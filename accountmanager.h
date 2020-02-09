#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QObject>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class AccountManager : public QObject {
    Q_OBJECT

    public:
        explicit AccountManager(QObject *parent = nullptr);
        ~AccountManager();

        bool isLoggedIn();
        QString getPlayername();
        QString getAccessToken();
        QString getUuid();
        QString getProperties();

    signals:
        void loginSucceeded();
        void loginFailed(QString error, QString detailed);
        void loggedOut();

    public slots:
        void refresh();
        void login(QString &username, QString &password);
        void logout();
        void replyReceived(QNetworkReply *reply);

    private:
        void syncSettings();

        QSettings settings;
        QNetworkAccessManager *nam;

        bool loggedIn = false;
        QString playername;
        QString accessToken;
        QString uuid;
        QString properties;
};

#endif // ACCOUNTMANAGER_H
