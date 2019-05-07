#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = nullptr);
    ~LogInDialog();

private:
    void onLogInSuccess(bool flag);
    void onButtonBoxAcceptedClicked();

    Ui::LogInDialog *ui;
    QString m_serverIp;
    int m_serverPort;
};

#endif // LOGINDIALOG_H
