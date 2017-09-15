#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QtNetwork>

class connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString usrname READ get_usrname  WRITE set_user)
    Q_PROPERTY(QString password WRITE set_pass NOTIFY passchange)

public:
    explicit connection(QObject *parent = nullptr);
    QString get_usrname();
    void set_user(const QString &login);
    void set_pass(const QString &pasword);
    void connect_to_base();
    void com_token_request();
    bool is_valid_old();
    void DB_login_destroy();
    void DB_login_insert();
signals:

public slots:

private:
     QString m_login;
     QString m_pasword;
};

#endif // CONNECTION_H
