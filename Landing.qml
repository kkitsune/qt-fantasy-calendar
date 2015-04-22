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

		SquareButton
		{
			anchors.right: parent.right
			anchors.left: parent.left
			anchors.top: parent.top
			text: qsTr("New Calendar")
			onButtonClicked: newClicked()
		}

		SquareButton
		{
			anchors.bottom: parent.bottom
			anchors.right: parent.right
			anchors.left: parent.left
			text: qsTr("Open Calendar")
			onButtonClicked: openClicked()
		}
	}
}
