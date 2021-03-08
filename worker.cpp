#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    _mainLoop = new QTimer();
    _mainLoop->setInterval(2000);
    _mainLoop->setSingleShot(false);

    connect(_mainLoop,
            SIGNAL(timeout()),
            this,
            SLOT(tick()));
}

Worker::~Worker()
{
    if (_mainLoop != nullptr) {
        delete _mainLoop;
        _mainLoop = nullptr;
    }
}

void Worker::start()
{
    _mainLoop->start();
}

void Worker::tick()
{
    LOG_INFO("Count: " + QString::number(_count++));
}
