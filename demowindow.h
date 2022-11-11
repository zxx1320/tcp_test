#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include "threadipportscan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DemoWindow; }
QT_END_NAMESPACE

class DemoWindow : public QMainWindow
{
    Q_OBJECT

public:
    DemoWindow(QWidget *parent = nullptr);
    ~DemoWindow();

public slots:
    void slot_scan_progress(int);
    void slot_scan_online_ip(QStringList);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DemoWindow *ui;
    ThreadIpPortScan threadipportscan;
};
#endif // DEMOWINDOW_H
