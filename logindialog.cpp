#include "logindialog.h"
#include "ui_logindialog.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(logInDialog, "Client.LogInDialog")

LogInDialog::LogInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogInDialog)
    , m_serverIp(QString())
    , m_serverPort(0)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this,
            &LogInDialog::onButtonBoxAcceptedClicked);
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::onLogInSuccess(bool flag)
{
    qCWarning(logInDialog) << flag;
    if (flag) {
        qCWarning(logInDialog) << "LogInDialog::logInSuccess";
        this->accept();
    }
}

void LogInDialog::onButtonBoxAcceptedClicked()
{
    m_serverIp = ui->ipLineEdit->text();
    m_serverPort = ui->portLineEdit->text().toInt();

    this->accept();
}
