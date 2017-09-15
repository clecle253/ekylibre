#include "connection.h"
#include "dbtoaccess.h"

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

bool connection::is_valid_old()
{
    QSqlQuery query;
    query.prepare("SELECT *FROM login");
    query.exec();
    if (!query.isValid())
        return(false);
    m_login = query.value(query.record().indexOf("pseudo")).toString();
    m_pasword = query.value(query.record().indexOf("pass")).toString();
    if (m_login.isEmpty() || m_pasword.isEmpty())
        return(false);
    return(true);
}

void connection::DB_login_destroy()
{
    QSqlQuery query;

    query.prepare("DROP TABLE login");
    query.exec();
}

void connection::DB_login_insert()
{
    QSqlQuery query;

    query.prepare("CREATE TABLE login(id INTERGER PRIMARY KEY, pseudo TEXT, pass TEXT)");
    query.exec();
    query.clear();
    query.prepare("INSERT INTO login(pseudo, pass) VALUES(:pseudo, :pass)");
    query.bindValue(":pseudo", m_login);
    query.bindValue(":pass", m_pasword);
    query.exec();

}

void connection::com_token_request()
{
    /*QNetworkAccessManager networkManager;
    QUrl url ("http://api.ekylibre.com/V2/connexion request");
    QNetworkRequest::User request;
    request.setUrl(url);
    request.HightPriority();
    QNetworkReply* curentReply = networkManager.get(request);*/

}


