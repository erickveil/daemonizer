#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include "staticlogger.h"

class Worker : public QObject
{
    Q_OBJECT

    int _count = 0;
    QTimer *_mainLoop = nullptr;

public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

    void start();

signals:

public slots:
    void tick();
};

#endif // WORKER_H
