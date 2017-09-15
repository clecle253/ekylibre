#include "customcamera.h"

CustomCamera::CustomCamera(QObject *parent) : QObject(parent)
{

}

void CustomCamera::autoselect_camera()
{
   qWarning() << QCameraInfo::availableCameras().count();

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras)
        qDebug() << cameraInfo.deviceName();
}
