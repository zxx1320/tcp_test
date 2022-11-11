#ifndef THREADIPPORTSCAN_H
#define THREADIPPORTSCAN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QThread>
#include <QStringList>

class ThreadIpPortScan : public QThread
{
    Q_OBJECT
public:
    ThreadIpPortScan();
    ~ThreadIpPortScan();

private:
    bool m_b_paused = true;
    bool m_b_stop = false;
    int  m_i_onlinenum = 0;
    QStringList m_qstringlist_onlineip;

protected:
    void run() Q_DECL_OVERRIDE;  //函数重载，此时运行的函数为线程函数,Q_DECL_OVERRIDE一致的；

public:
    void search_begin(void);    //开始搜寻
    void search_done(void);     //完成搜寻
    void search_stop(void);     //停止搜寻

signals:
    // 进度的信号，其中包括当前查找的在线系统数量
    void signal_scan_progress(int);
    // 完成时的信号，需要将所以的IP地址通过Qlist回传至主线程显示；
    void signal_online_ip(QStringList);

};

#endif // THREADIPPORTSCAN_H
