#ifndef DBACCESS_H
#define DBACCESS_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QString>
#include <QDebug>

const QString DRIVER("QSQLITE");
const QString DBNAME("test007");

class DBtoaccess : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dbstup READ DB_setup_tables)
public:
    explicit DBtoaccess(QObject *parent = nullptr);
    QString DB_setup_tables();
    QString DBstockuser(const QString &user, const QString &token);
    QString DBtogetusr();
private:
    QSqlDatabase m_db;
};

#endif // DBACCESS_H
