#include "dbtoaccess.h"

DBtoaccess::DBtoaccess(QObject *parent) : QObject(parent)
{

}

bool DBtoaccess::init_drivers()
{
    if (QSqlDatabase::isDriverAvailable(DRIVER))
    {
        m_db = QSqlDatabase::addDatabase(DRIVER);
        m_db.setDatabaseName(DBNAME);
        if(!m_db.open())
            qWarning() << "ERROR" << m_db.lastError();
        else
            qWarning() << "database op";
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver" << DRIVER << "available";

}

QString DBtoaccess::DB_setup_tables()
{
    QSqlQuery query2("CREATE TABLE login (id INTEGER PRIMARY KEY, pseudo TEXT, pass TEXT");
    return ("");
}
