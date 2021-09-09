import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import Qt.example.calculatorpresenter 1.0
import Qt.example.calculatorview 1.0

ApplicationWindow {
    id: window
    visible: true
    title: qsTr("Calculator")
    color: "lightblue"

    // I could only get the top-level window to automatically calculate
    // its size if I did this.
    width: calculator_view.implicitWidth + 2 * calculator_view.anchors.margins
    height: calculator_view.implicitHeight + 2 * calculator_view.anchors.margins

    // Instantiate OUR model
    CalculatorPresenter {
        id: calculator_presenter
    }

    // Instantiate OUR view that will use the CalculatorPresenter model
    CalculatorView {
        id: calculator_view
        anchors.fill: parent
        anchors.margins: 10
        implicitWidth: maincolumn_layout.implicitWidth + 2 * maincolumn_layout.anchors.margins
        implicitHeight: maincolumn_layout.implicitHeight + 2 * maincolumn_layout.anchors.margins
        model: calculator_presenter

        // Basic calculator layout: result along top with a grid of buttons below.
        // We use this instead of a GridLayout.
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
                Layout.fillWidth: true

                Button {
                    text: ""
                    Layout.fillWidth: true
                }

                Button {
                    text: ""
                    Layout.fillWidth: true
                }

                Button {
                    text: ""
                    Layout.fillWidth: true
                }

                Button {
                    text: "/"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("/")
                }
            }

            RowLayout {
                spacing: 10
                Layout.fillWidth: true

                Button {
                    text: "7"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("7")
                }

                Button {
                    text: "8"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("8")
                }

                Button {
                    text: "9"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("9")
                }

                Button {
                    text: "*"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("*")
                }
            }

            RowLayout {
                spacing: 10
                Layout.fillWidth: true

                Button {
                    text: "4"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("4")
                }

                Button {
                    text: "5"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("5")
                }

                Button {
                    text: "6"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("6")
                }

                Button {
                    text: "-"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("-")
                }
            }

            RowLayout {
                spacing: 10
                Layout.fillWidth: true

                Button {
                    text: "1"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("1")
                }

                Button {
                    text: "2"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("2")
                }

                Button {
                    text: "3"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("3")
                }

                Button {
                    text: "+"
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("+")
                }
            }

            RowLayout {
                spacing: 10
                Layout.fillWidth: true

                Button {
                    text: ""
                    Layout.fillWidth: true
                }

                Button {
                    text: "0"
                    Layout.fillWidth: true

                    onClicked: calculator_view.pressKey("0")
                }

                Button {
                    text: ""
                    Layout.fillWidth: true
                }

                Button {
                    text: "="
                    Layout.fillWidth: true

                    onClicked: calculator_view.press("=")
                }
            }
        }
    }
}


