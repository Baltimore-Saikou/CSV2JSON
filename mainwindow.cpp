#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "qvector.h"


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

void MainWindow::on_selectCsvButton_clicked()
{
    const QUrl fileUrl = QFileDialog::getOpenFileUrl(this, QStringLiteral("选择Json文件"), QDir::currentPath(), "Json files (*.json);;All files(*.*)");
    QString filePath = fileUrl.path();
    // 删除路径的第一个字符 "/"
    filePath.remove(0, 1);
    qDebug() << filePath;


    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "111";


        // todo 改项目名为JsonModify
    }
    else
    {
        qDebug() << "json文件打开失败";
    }
}
