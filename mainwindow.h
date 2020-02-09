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
