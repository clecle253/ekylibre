import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    StackView{
        id: stack_view
        focus: true
        initialItem: Qt.resolvedUrl("Login.qml")
        anchors.fill: parent
        Keys.onReleased: if (event.key === Qt.Key_Back && stack_view.depth > 1){
                             StackView.pop();
                             event.accepted = true;
                         }
    }
}
