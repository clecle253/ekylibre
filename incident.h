#ifndef INCIDENT_H
#define INCIDENT_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QString>
#include <QDateTime>
#include <QImage>
#include <QDebug>

class incident : public QObject
{
    Q_OBJECT
public:
    explicit incident(QObject *parent = nullptr);
    bool check_database();
    void set_latitude(const float &latitude);
    void set_longitude(const float &longitude);
    void set_name(const QString &name);
    void set_date();
    bool store_data();
    void set_field(const QString &field);
    void set_note(const QString &note);
    void set_icon_index(const int &icon_index);
    void set_picture(const QString &image);
    void set_sound(const QString &sound);
    QString get_the_file_name(const bool &is_a_picture);
signals:

public slots:

private:
    float m_latitude;
    float m_longitude;
    QString m_name;
    QDateTime m_date;
    QString m_field;
    QString m_note;
    int m_icon_index;
    QString m_picture;
    QString m_sound;
    int m_new_key;
};

#endif // INCIDENT_H
