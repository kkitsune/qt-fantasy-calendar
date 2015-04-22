import QtQuick 2.4

Item
{
	width: 800
	height: 600

	signal cancelClicked()

	SquareButton
	{
		anchors.left: parent.left
		anchors.top: parent.top
		text: qsTr("<< Cancel")
		onButtonClicked: cancelClicked()
	}
}

