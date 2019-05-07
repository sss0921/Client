#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(mainWindow, "Client.MainWindow")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
