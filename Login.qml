import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    anchors.fill: parent
    TextField {
        text: qsTr("Login")
    }
    TextField {
        Layout.alignment: Qt.AlignCenter
        text: qsTr("Password")
    }
}

