import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    Rectangle {
        id : login
        width: parent.width / 3
        height: parent.height / 12
        anchors.top: parent.height / 12 * 3
        Text {
            text: "Login"
            anchors.centerIn: parent
        }
    }
}
