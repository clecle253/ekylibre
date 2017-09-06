import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    ColumnLayout{
        id: layout
        spacing: 2
        anchors.fill: parent
        Image{
            id: logo
            source: "img/logo_ekylibre.png"
            //fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: layout.horizontalCenter
        }

        TextField {
            text: qsTr("Login")
            anchors.horizontalCenter: layout.horizontalCenter
        }
        TextField {
            text: qsTr("Password")
            anchors.horizontalCenter: layout.horizontalCenter
        }
        Rectangle{
            height: bouton_connexion.height
            width: bouton_connexion.width + bouton_inscription.width + 10
            anchors.horizontalCenter: layout.horizontalCenter
            Button{
                id: bouton_connexion
                text: "Connexion"
            }
            Button{
                id: bouton_inscription
                text: "Inscription"
                anchors.top: bouton_connexion.top
                anchors.left: bouton_connexion.right
                anchors.leftMargin: 10
            }
        }
    }
}

