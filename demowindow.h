#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DemoWindow; }
QT_END_NAMESPACE

class DemoWindow : public QMainWindow
{
    Q_OBJECT

public:
    DemoWindow(QWidget *parent = nullptr);
    ~DemoWindow();

private:
    Ui::DemoWindow *ui;
};
#endif // DEMOWINDOW_H
