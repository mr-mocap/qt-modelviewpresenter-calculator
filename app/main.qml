import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import Qt.example.calculatorpresenter 1.0
import Qt.example.calculatorview 1.0

Window {
    id: window
    visible: true
    title: qsTr("Calculator")
    color: "lightblue"
    width: calculator_view.implicitWidth + 2 * calculator_view.anchors.margins
    height: calculator_view.implicitHeight + 2 * calculator_view.anchors.margins

    CalculatorPresenter {
        id: calculator_presenter
    }

    CalculatorView {
        id: calculator_view
        anchors.fill: parent
        anchors.margins: 10
        implicitWidth: maincolumn_layout.implicitWidth + 2 * maincolumn_layout.anchors.margins
        implicitHeight: maincolumn_layout.implicitHeight + 2 * maincolumn_layout.anchors.margins
        model: calculator_presenter

        ColumnLayout {
            id: maincolumn_layout
            anchors.fill: parent
            anchors.margins: 10
            implicitWidth: toprowbuttons_layout.implicitWidth
            implicitHeight: toprowbuttons_layout.implicitHeight
            spacing: 10

            RowLayout {
                id: result_layout
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                Label {
                    id: currentresult_label
                    text: calculator_view.result
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 14
                    Layout.fillWidth: true
                    color: "black"

                    background: Rectangle {
                        anchors.fill: currentresult_label
                    }
                }
            }

            RowLayout {
                id: toprowbuttons_layout
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                Button {
                    text: ""
                    padding: 0
                }

                Button {
                    text: ""
                    padding: 0
                }

                Button {
                    text: ""
                    padding: 0
                }

                Button {
                    text: "/"
                    padding: 0

                    onClicked: calculator_view.press("/")
                }
            }

            RowLayout {
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                Button {
                    text: "7"
                    padding: 0

                    onClicked: calculator_view.press("7")
                }

                Button {
                    text: "8"
                    padding: 0

                    onClicked: calculator_view.press("8")
                }

                Button {
                    text: "9"
                    padding: 0

                    onClicked: calculator_view.press("9")
                }

                Button {
                    text: "*"
                    padding: 0

                    onClicked: calculator_view.press("*")
                }
            }

            RowLayout {
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                Button {
                    text: "4"

                    onClicked: calculator_view.press("4")
                }

                Button {
                    text: "5"

                    onClicked: calculator_view.press("5")
                }

                Button {
                    text: "6"

                    onClicked: calculator_view.press("6")
                }

                Button {
                    text: "-"

                    onClicked: calculator_view.press("-")
                }
            }

            RowLayout {
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                Button {
                    text: "1"

                    onClicked: calculator_view.press("1")
                }

                Button {
                    text: "2"

                    onClicked: calculator_view.press("2")
                }

                Button {
                    text: "3"

                    onClicked: calculator_view.press("3")
                }

                Button {
                    text: "+"

                    onClicked: calculator_view.press("+")
                }
            }

            RowLayout {
                spacing: 10
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true
                Layout.fillHeight: true

                Button {
                    text: ""
                }

                Button {
                    text: "0"

                    onClicked: calculator_view.pressKey("0")
                }

                Button {
                    text: ""
                }

                Button {
                    text: "="

                    onClicked: calculator_view.press("=")
                }
            }
        }
    }
}


