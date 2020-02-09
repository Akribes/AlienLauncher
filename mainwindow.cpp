#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    accountStatusLabel.setText("Not logged in");
    this->ui->statusBar->addWidget(&accountStatusLabel);

    connect(&accountManager, SIGNAL(loginSucceeded()), this, SLOT(clearCredentialInputs()));
    connect(&accountManager, SIGNAL(loginFailed(QString, QString)), this, SLOT(onLoginFailed(QString, QString)));
    connect(&accountManager, SIGNAL(loginSucceeded()), this, SLOT(onLoginSucceeded()));
    connect(&accountManager, SIGNAL(loggedOut()), this, SLOT(onLogout()));

    accountManager.refresh();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Instances
void MainWindow::on_applyButton_clicked() {
    // TODO Save current instance
}

void MainWindow::on_launchButton_clicked() {
    // TODO Launch current instance
}

// Account
void MainWindow::on_loginButton_clicked() {
    QString username = this->ui->usernameLineEdit->text();
    QString password = this->ui->passwordLineEdit->text();
    if (username.isEmpty() || password.isEmpty()) return;

    this->ui->statusBar->showMessage("Logging in...", 0);
    accountManager.login(username, password);
}

// About
void MainWindow::on_aboutQtButton_clicked() {
    QMessageBox::aboutQt(this);
}

// Other things

void MainWindow::clearCredentialInputs() {
    this->ui->usernameLineEdit->clear();
    this->ui->passwordLineEdit->clear();
}

void MainWindow::onLoginFailed(QString error, QString detailed) {
    this->ui->statusBar->clearMessage();
    QMessageBox msgBox;
    msgBox.setWindowTitle(":(");
    msgBox.setText("Logging in failed.");
    msgBox.setDetailedText(QString("%1:\n\n%2").arg(error).arg(detailed));
    msgBox.exec();
}

void MainWindow::onLoginSucceeded() {
    this->ui->statusBar->clearMessage();
    accountStatusLabel.setText(QString("Logged in as %1").arg(accountManager.getPlayername()));
}

void MainWindow::onLogout() {
    accountStatusLabel.setText("Not logged in");
}