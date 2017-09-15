#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "connection.h"
#include "dbtoaccess.h"
#include "incident.h"
//#include "ekylib.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<DBtoaccess>("Ekylibre.db", 1,0, "DBaccess");
    qmlRegisterType<connection>("Ekylibre.connection" ,1 ,0 ,"Connection");

    DBtoaccess init;
    init.init_drivers();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    connection tst;

    tst.com_token_request();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
