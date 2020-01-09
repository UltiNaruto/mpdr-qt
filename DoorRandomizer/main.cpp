#include "randomizergui.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator app_translator,qt_translator;

    QString qt_translations_path = QCoreApplication::applicationDirPath().append("/translations/");
    QString locale = QLocale::system().name();
    locale.truncate(locale.lastIndexOf("_"));

    if(qt_translator.load(qt_translations_path + QString("qt_%1.qm").arg(locale)))
        a.installTranslator(&qt_translator);
    if(app_translator.load(QString("LanguagePacks/mpdr_%1.qm").arg(locale))) {
        a.installTranslator(&app_translator);
    }

    RandomizerGUI w;
    w.show();
    return a.exec();
}
