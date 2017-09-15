#ifndef CUSTOMCAMERA_H
#define CUSTOMCAMERA_H

#include <QObject>
#include <QCamera>
#include <QCameraInfo>
class CustomCamera : public QObject
{
    Q_OBJECT
public:
    explicit CustomCamera(QObject *parent = nullptr);
    void autoselect_camera();
signals:

public slots:

private:
   QCamera m_front_camera;
   QCamera m_back_camera;
};

#endif // CUSTOMCAMERA_H
