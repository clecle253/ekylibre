#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "connection.h"
#include "dbtoaccess.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<DBtoaccess>("Ekylibre.db", 1,0, "DBaccess");
    qmlRegisterType<connection>("Ekylibre.connection" ,1 ,0 ,"Connection");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    DBtoaccess tst;
    qDebug() << tst.DBtogetusr();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
