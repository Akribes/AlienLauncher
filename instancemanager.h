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

#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H

#include "globals.h"
#include "instance.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class InstanceManager : public QObject {
    Q_OBJECT
	public:
		explicit InstanceManager(QObject *parent = nullptr);
		~InstanceManager();

		void downloadVersionManifest(); // https://launchermeta.mojang.com/mc/game/version_manifest.json

	private:
		QNetworkAccessManager *nam;
		QVector<Instance> instances;

	public slots:
		void replyReceived(QNetworkReply * reply);
};

#endif // INSTANCEMANAGER_H
