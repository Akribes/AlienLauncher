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

#include "mainwindow.h"

#include <QApplication>
#include <QUuid>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    QApplication::setOrganizationName("AlienLauncher");
    QApplication::setOrganizationDomain("");
    QApplication::setApplicationName("AlienLauncher");

    // Cliend id sent to auth servers must be identical for each request, so use a random UUID (like the official launcher)
    QSettings s;
    if (!s.contains("auth/clientToken")) {
        s.setValue("auth/clientToken", QUuid::createUuid().toString(QUuid::Id128));
    }

    MainWindow w;
    w.show();
    return a.exec();
}
