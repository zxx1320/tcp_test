#include "demowindow.h"
#include "ui_demowindow.h"
#include <QDebug>
#include <QCloseEvent>

DemoWindow::DemoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DemoWindow)
{
    ui->setupUi(this);

    connect(&threadipportscan,&ThreadIpPortScan::signal_scan_progress,this,&DemoWindow::slot_scan_progress);
    threadipportscan.start();
    qDebug() << QThread::currentThreadId() << endl;
}

DemoWindow::~DemoWindow()
{
    delete ui;
    threadipportscan.search_stop();
    threadipportscan.wait();
    threadipportscan.deleteLater();
}

void DemoWindow::slot_scan_progress(int value)
{
    ui->progressBar->setValue(value);
}


void DemoWindow::on_pushButton_clicked()
{
    ui->progressBar->setValue(0);
    threadipportscan.search_begin();
}

#if 1
void DemoWindow::closeEvent(QCloseEvent *event)
{
    if(threadipportscan.isRunning())
    {
        threadipportscan.search_stop();
        threadipportscan.wait();
    }

    event->accept();
}
#endif
