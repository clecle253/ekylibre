#include "incident.h"

incident::incident(QObject *parent) : QObject(parent)
{
    m_latitude = 0;
    m_longitude = 0;
    m_name = "";
    m_date = m_date;
    m_field = "";
    m_note = "";
    m_icon_index = 0;
    m_picture = m_picture;
    m_sound = "";
    QSqlQuery query;
    query.exec("SELECT id FROM incidents");
    while (query.next())
    {
        if (m_new_key <= query.value(query.record().indexOf("id")).toInt())
            m_new_key = query.value(query.record().indexOf("id")).toInt();
    }
    m_new_key += 1;
}

bool incident::check_database()
{
    QSqlQuery query("CREATE TABLE incidents (id INTEGER PRIMARY KEY, "
                    "latitude REAL, lognitude REAL, name TEXT, date TEXT"
                    "field TEXT, note TEXT, icon_index INT, picture BLOB"
                    "audio_note BLOB)");
    if (query.isValid())
        return(true);
    return(false);
}

void incident::set_latitude(const float &latitude){m_latitude = latitude;}
void incident::set_longitude(const float &longitude){m_longitude = longitude;}
void incident::set_name(const QString &name){m_name = name;}
void incident::set_date(){m_date = QDateTime::currentDateTime();}
void incident::set_field(const QString &field){m_field = field;}
void incident::set_note(const QString &note){m_note = note;}
void incident::set_icon_index(const int &icon_index){m_icon_index = icon_index;}
void incident::set_picture(const QString &image){m_picture = image;}
void incident::set_sound(const QString &sound){m_sound = sound;}
QString incident::get_the_file_name(const bool &is_a_picture)
{
    QString name;
    if (is_a_picture == true)
        name += "picture-";
    else
        name += "sound-";
    name += (m_new_key + '0');
    return (name);
}

bool incident::store_data()
{
    QSqlQuery query;
    query.prepare("INSERT INTO incidents(latitude, longitude, name, date, field, note, icon_index, picture, audio_note)"
                  "VALUES (:latitude, :longitude, :name, :date, :field, :note, :icon_index, :picture, :audio_note)");
    query.bindValue(":latitude", m_latitude);
    query.bindValue(":longitude", m_longitude);
    query.bindValue(":name", m_name);
    query.bindValue(":date", m_date.toString(Qt::ISODate));
    query.bindValue(":field", m_field);
    query.bindValue(":note", m_note);
    query.bindValue(":icon_index", m_icon_index);
    query.bindValue(":picture", m_picture);
    query.bindValue(":sound", m_sound);
    query.exec();
    if (query.isValid())
        return (true);
    return(false);
}
