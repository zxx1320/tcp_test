#ifndef THREADTCPSOCKET_H
#define THREADTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class ThreadTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit ThreadTcpSocket(QObject *parent = nullptr);
    ~ThreadTcpSocket();

signals:

public slots:
    void slot_tcpsocket_init(bool, qint32, QString);

private:
    QTcpSocket* tcpsocket;
    QThread* thread_tcpsocket;

};

#endif // THREADTCPSOCKET_H
