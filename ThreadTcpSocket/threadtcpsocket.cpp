#include "threadtcpsocket.h"

/***********************************************************
* Copyright(c) 2022 xianyang.zhang All rights reserved
* @file: threadtcpsocket.cpp
* @Function name: ThreadTcpSocket(QObject *parent) : QObject(parent)
* @Brief: 构造函数，用于常见线程以及连接信号和槽
* @author: xianyang.zhang
* @Return:
* @Others:
*
* @Date: 2022/11/09
************************************************************/
ThreadTcpSocket::ThreadTcpSocket(QObject *parent) : QObject(parent)
{
    tcpsocket = new QTcpSocket();
    thread_tcpsocket = new QThread();

    //将类对象和成员放至线程中运行，此时槽函数运行的为线程函数
    this->moveToThread(thread_tcpsocket);
    tcpsocket->moveToThread(thread_tcpsocket);

    thread_tcpsocket->start();

}

/***********************************************************
* Copyright(c) 2022 xianyang.zhang All rights reserved
* @file: threadtcpsocket.cpp
* @Function name: ~ThreadTcpSocket()
* @Brief: 析构函数，用于释放内存
* @author:xianyang.zhang
* @Return:
* @Others:
*
* @Date: 2022/11/09
************************************************************/
ThreadTcpSocket::~ThreadTcpSocket()
{
    tcpsocket->close();
    tcpsocket->deleteLater();

    thread_tcpsocket->quit();
    thread_tcpsocket->wait();
    thread_tcpsocket->deleteLater();

}

/***********************************************************
* Copyright(c) 2022 xianyang.zhang All rights reserved
* @file: threadtcpsocket.cpp
* @Function name: slot_tcpsocket_init(bool enable, qint32 port, QString ip_addr)
* @Brief:
* @author: xianyang.zhang
* @Return:
* @Others:
*
* @Date: 2022/11/09
************************************************************/
void ThreadTcpSocket::slot_tcpsocket_init(bool enable, qint32 port, QString ip_addr)
{
    if(true == enable)
    {
        //断开之前的套接字
        tcpsocket->abort();

        tcpsocket->connectToHost(ip_addr,port);
    }

}

