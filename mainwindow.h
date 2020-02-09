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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "accountmanager.h"
#include <QLabel>
#include <QMainWindow>
#include <QSettings>
#include <QtNetwork>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QSettings settings;

        QLabel accountStatusLabel;

        AccountManager accountManager;

    private slots:
        void clearCredentialInputs();
        void onLoginFailed(QString error, QString detailed);
        void onLoginSucceeded();
        void onLogout();

        // Instances
        void on_applyButton_clicked();
        void on_launchButton_clicked();

        // Account
        void on_loginButton_clicked();

        // About
        void on_aboutQtButton_clicked();
};
#endif // MAINWINDOW_H
