#include <QCoreApplication>

#include <functional>

#include "daemonizer.h"
#include "staticlogger.h"
#include "worker.h"


int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    // Must be declared before the Daemonizer::init for QTimer to work.
    QCoreApplication a(argc, argv);

    LOG_INFO("Starting daemontet - v 0.19");
    LOG_WARN("Warn test");

    auto hupCb = [&] () {
        LOG_INFO("Alternate SIGHUP handler called.");
    };

    Daemonizer *daemon = Daemonizer::Instance();
    daemon->SigHupCallback = hupCb;
    daemon->init();

    // main loop

    Worker worker;
    worker.start();

    return a.exec();
    LOG_INFO("Post exec");

}
