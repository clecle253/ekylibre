import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Ekylibre.connection 1.0
import Ekylibre.db 1.0

Item {
    Connection{id:connection}
    DBaccess{id:dbaccess}
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
            placeholderText: "Login"
            anchors.horizontalCenter: layout.horizontalCenter
            onTextChanged: connection.usrname = text
        }
        TextField {
            placeholderText: "Password"
            echoMode: TextInput.Password
            //echoMode: TextInput.PasswordEchoOnEdit
            anchors.horizontalCenter: layout.horizontalCenter
            onTextChanged: {connection.password = text}
        }
        Rectangle{
            height: bouton_connexion.height
            width: bouton_connexion.width + bouton_inscription.width + 10
            anchors.horizontalCenter: layout.horizontalCenter
            Button{
                id: bouton_connexion
                text: "Connexion"
                onPressed: dbaccess.dbstup
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

