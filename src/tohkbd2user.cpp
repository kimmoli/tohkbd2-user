/*
 * (C) 2014 Kimmo Lindholm <kimmo.lindholm@gmail.com> Kimmoli
 *
 * Main, Daemon functions
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "userdaemon.h"
#include "adaptor.h"
#include <QtCore/QCoreApplication>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    setlinebuf(stdout);
    setlinebuf(stderr);

    printf("tohkbd2-user: starting daemon version %s\n", APPVERSION);

    printf("tohkbd2-user: Locale is %s\n", qPrintable(QLocale::system().name()));

    QTranslator translator;
    translator.load("translations_" + QLocale::system().name(), "/usr/share/harbour-tohkbd2-user/i18n");
    app.installTranslator(&translator);


    UserDaemon rw;
    new Tohkbd2userAdaptor(&rw);

    rw.registerDBus();

    return app.exec();
}
