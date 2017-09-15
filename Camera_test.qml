import QtQuick 2.0
import QtMultimedia 5.9

Item {
    Camera
    {
        id:camera
        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
        flash.mode: Camera.FlashRedEyeReduction

        exposure{
            exposureCompensation:  -1.0
            exposureMode: Camera.ExposureAuto
        }

        focus {
            focusMode: Camera.FocusContinuous
            focusPointMode: Camera.FocusPointCenter
        }
    }


    Rectangle{
        id: cam_conteneur
        anchors.top: parent.top
        height: parent.height //- 50
        width: parent.width
        color :"black"

        VideoOutput{
            anchors.fill: parent
            source: camera
            autoOrientation: true
        }
    }
    Rectangle{
        anchors.top: cam_conteneur.bottom
        width: parent.width
        height: parent.height - cam_conteneur.height
        MouseArea{
            anchors.fill: parent
            onClicked: camera.imageCapture.capture();
            onPressed: color = "red"
            onReleased: color = "white"
        }
    }
}
