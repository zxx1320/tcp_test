#include "threadipportscan.h"
#include <QDebug>
#include <QTcpSocket>

ThreadIpPortScan::ThreadIpPortScan()
{

}

ThreadIpPortScan::~ThreadIpPortScan()
{
    this->search_stop();
    this->wait();
    this->deleteLater();
}

void ThreadIpPortScan::run()
{
    //线程任务
    while (!m_b_stop)
    {
        if(!m_b_paused)
        {
            qDebug() << QThread::currentThreadId() << endl;
            m_i_onlinenum = 0;
            m_qstringlist_onlineip.clear();
            int l_int_scan_progress = 0;
            QTcpSocket t_socket(0);
            t_socket.abort();
            QString t_ip("192.168.0.0");
            for(int x = 1; x < 4; x++)
            {
                for(int y = 1; y < 255; y++)
                {
                    t_ip.replace(8,1,QString::number(x));
                    t_ip.replace(10,t_ip.size()-10,QString::number(y));
                    qDebug()<< "IP:" << t_ip << endl;
                    t_socket.abort();
                    t_socket.connectToHost(t_ip,502);
                    if(t_socket.waitForConnected(100))
                    {
                        m_i_onlinenum ++;
                        m_qstringlist_onlineip.append(t_ip);
                        //qDebug()<<"connect over";
                    }
                    else
                    {
                        //qDebug()<<tmpport<<"not open"<<endl;
                    }
                    //发送进度
                    l_int_scan_progress++;
                    emit(signal_scan_progress(l_int_scan_progress));
                    if(true == m_b_stop)
                        break;
                }
            }

            //扫描完成，发送信号
            search_done();
            qDebug() << QThread::currentThreadId() << endl;
            emit(signal_online_ip(m_qstringlist_onlineip));

        }
        sleep(1);
    }

}

void ThreadIpPortScan::search_begin()
{
    m_b_paused = false;
}

void ThreadIpPortScan::search_done()
{
    m_b_paused = true;
}

void ThreadIpPortScan::search_stop()
{
    m_b_stop = true;
}
