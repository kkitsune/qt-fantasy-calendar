import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Window
{
	visible: true
	title: "Fantasy Calendar"
	width: 800
	height: 600

	StackView
	{
		anchors.fill: parent
		initialItem: landing

		Landing
		{
			id: landing
			anchors.fill: parent
			onNewClicked: console.log("New Clicked");
			onOpenClicked: console.log("Open Clicked");
		}
	}
}
