#include "dbtoaccess.h"

DBtoaccess::DBtoaccess(QObject *parent) : QObject(parent)
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
    QSqlQuery query("CREATE TABLE token (id INTEGER PRIMARY KEY, key TEXT)");
    QSqlQuery query2("CREATE TABLE login (id INTEGER PRIMARY KEY, pseudo TEXT, pass TEXT");
    return ("");
}

QString DBtoaccess::DBstockuser(const QString &user, const QString &token)
{
    // appel d'une metode pour verifier que l'api dise ok et retourne un token
    return ("");
}

QString DBtoaccess::DBtogetusr()
{
    QSqlQuery query;
    query.exec("INSERT INTO login(pseudo) VALUES('pseudo2')");
    if (!query.exec("SELECT pseudo FROM login"))
            qWarning() << "requette non effectué" << query.lastError();
    return(query.value(0).toString());
}
