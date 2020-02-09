/* Copyright 2020 Mart Koster
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
