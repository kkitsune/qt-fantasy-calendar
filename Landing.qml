import QtQuick 2.4

Item
{
	signal newClicked()
	signal openClicked()

	Item
	{
		width: 300
		height: 200
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter

		Rectangle
		{
			id: newCalendar
			height: 100
			color: "#1fc91f"
			anchors.right: parent.right
			anchors.left: parent.left
			anchors.top: parent.top

			state: "Normal"
			states:
			[
				State
				{
					name: "Normal"
					when: !newCalendarMouse.containsMouse
					PropertyChanges
					{
						target: newCalendar
						color: "#1fc91f"
					}
				},
				State
				{
					name: "Hover"
					when: newCalendarMouse.containsMouse
					PropertyChanges
					{
						target: newCalendar
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
				id: newCalendarMouse
				hoverEnabled: true
				anchors.fill: parent
				onClicked: newClicked()
			}

			Text
			{
				text: qsTr("New Calendar")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
				font.pixelSize: 30
			}
		}

		Rectangle
		{
			id: openCalendar
			height: 100
			color: "#1fc91f"
			anchors.bottom: parent.bottom
			anchors.right: parent.right
			anchors.left: parent.left

			state: "Normal"
			states:
			[
				State
				{
					name: "Normal"
					when: !openCalendarMouse.containsMouse
					PropertyChanges
					{
						target: openCalendar
						color: "#1fc91f"
					}
				},
				State
				{
					name: "Hover"
					when: openCalendarMouse.containsMouse
					PropertyChanges
					{
						target: openCalendar
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
				id: openCalendarMouse
				hoverEnabled: true
				anchors.fill: parent
				onClicked: openClicked()
			}

			Text
			{
				text: qsTr("Open Calendar")
				horizontalAlignment: Text.AlignHCenter
				font.pixelSize: 30
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
			}
		}
	}
}
