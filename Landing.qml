import QtQuick 2.4

Item
{
	Item
	{
		width: 300
		height: 200
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter

		Rectangle
		{
			height: 100
			color: "#1fc91f"
			anchors.right: parent.right
			anchors.left: parent.left
			anchors.top: parent.top

			MouseArea
			{
				id: newCalendar
				hoverEnabled: true
				anchors.fill: parent
				onEntered: parent.color = "#15f212"
				onExited: parent.color = "#1fc91f"
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
			height: 100
			color: "#1fc91f"
			anchors.bottom: parent.bottom
			anchors.right: parent.right
			anchors.left: parent.left

			MouseArea
			{
				id: openCalendar
				hoverEnabled: true
				anchors.fill: parent
				onEntered: parent.color = "#15f212"
				onExited: parent.color = "#1fc91f"
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
