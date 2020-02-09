#include "accountmanager.h"

AccountManager::AccountManager(QObject *parent) : QObject(parent) {
    nam = new QNetworkAccessManager();
    connect(nam, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyReceived(QNetworkReply *)));

    accessToken = settings.value("auth/accessToken").toString();
}

AccountManager::~AccountManager() {
    delete nam;
}

void AccountManager::syncSettings() {
    if (accessToken.isEmpty()) settings.remove("auth/accessToken");
    else settings.setValue("auth/accessToken", accessToken);
}

void AccountManager::refresh() {
    if (accessToken.isEmpty()) return;
    QNetworkRequest req (QUrl("https://authserver.mojang.com/refresh"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    nam->post(req, QString("{\"accessToken\":\"%1\",\"clientToken\":\"%2\",\"requestUser\":true}")
              .arg(accessToken).arg(settings.value("auth/clientToken").toString()).toUtf8());
}

void AccountManager::login(QString &username, QString &password) {
    logout(); // Logout for the time being, until I add support for multiple accounts at once

    QNetworkRequest req (QUrl("https://authserver.mojang.com/authenticate"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    nam->post(req, QString("{\"agent\":{\"name\":\"minecraft\",\"version\":1},\"username\":\"%1\",\"password\":\"%2\",\"clientToken\":\"%3\",\"requestUser\":true}")
              .arg(username).arg(password).arg(settings.value("auth/clientToken").toString()).toUtf8());
}

void AccountManager::logout() {
    if (loggedIn) {
        QNetworkRequest req (QUrl("https://authserver.mojang.com/invalidate"));
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        nam->post(req, QString("{\"accessToken\":\"%1\",\"clientToken\":\"%2\"}")
                  .arg(accessToken).arg(settings.value("auth/clientToken").toString()).toUtf8());

        loggedIn = false;
        playername = "";
        accessToken = "";
        uuid = "";
        properties = "";
        syncSettings();
    }
    emit loggedOut();
}

void AccountManager::replyReceived(QNetworkReply *reply) {
    QString endpoint = reply->url().path();
    if (endpoint == "/authenticate" || endpoint == "/refresh") {
        QByteArray content = reply->readAll();
        if (content.isEmpty()) return;
        QJsonObject json = QJsonDocument::fromJson(content).object();

        if (json.contains("error")) {
            emit loginFailed(json["error"].toString(), json["errorMessage"].toString());
        } else {
            QJsonObject profile = json["selectedProfile"].toObject();
            QJsonObject user = json["user"].toObject();
            playername = profile["name"].toString();
            uuid = profile["id"].toString();
            accessToken = json["accessToken"].toString();
            properties = user["properties"].toString();

            syncSettings();
            loggedIn = true;
            emit loginSucceeded();
        }
    }
}

bool AccountManager::isLoggedIn() {
    return loggedIn;
}

QString AccountManager::getPlayername() {
    return playername;
}

QString AccountManager::getAccessToken() {
    return accessToken;
}

QString AccountManager::getUuid() {
    return uuid;
}

QString AccountManager::getProperties() {
    return properties;
}
