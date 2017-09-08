#include "connection.h"

connection::connection(QObject *parent) : QObject(parent)
{
    m_login = "";
    m_pasword = "";
}

QString connection::get_usrname(){return(m_login);}

void connection::set_user(const QString &login)
{
    m_login = login;
    qWarning() << "le login recuperer est :" << m_login;
}

void connection::set_pass(const QString &pasword)
{
    m_pasword = pasword;
    qWarning() << "le password est :" << m_pasword;
}


