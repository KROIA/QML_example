import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "Simple QML Table"

    ListView {
        anchors.fill: parent
        model: ListModel {
            id: tableModel
            ListElement { name: "Alice"; age: 30 }
            ListElement { name: "Bob"; age: 25 }
            ListElement { name: "Carol"; age: 35 }
        }
        delegate: Rectangle {
            width: parent.width
            height: 40
            border.color: "black"
            color: index % 2 === 0 ? "lightgray" : "white"

            Row {
                anchors.fill: parent
                anchors.margins: 10

                Text {
                    text: model.name
                    width: 200
                    anchors.left: parent.left
                }

                Text {
                    text: model.age
                    width: 100
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 210
                }
            }
        }
    }
}
