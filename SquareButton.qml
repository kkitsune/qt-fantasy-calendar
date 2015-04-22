import QtQuick 2.4

Rectangle
{
	signal buttonClicked()
	property string text: qsTr("Button")

	id: button
	width: 250
	height: 100
	color: "#1fc91f"

	state: "Normal"
	states:
	[
		State
		{
			name: "Normal"
			when: !buttonrMouse.containsMouse
			PropertyChanges
			{
				target: button
				color: "#1fc91f"
			}
		},
		State
		{
			name: "Hover"
			when: buttonrMouse.containsMouse
			PropertyChanges
			{
				target: button
				color: "#15f212"
			}
		}
	]

	transitions: [
		Transition {
			to: "*"
			ColorAnimation {
				property: "color"
				duration: 200
			}
		}
	]

	MouseArea
	{
		id: buttonrMouse
		hoverEnabled: true
		anchors.fill: parent
		onClicked: buttonClicked()
	}

	Text
	{
		text: button.text
		verticalAlignment: Text.AlignVCenter
		horizontalAlignment: Text.AlignHCenter
		anchors.fill: parent
		font.pixelSize: 30
	}
}

