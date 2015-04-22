import QtQuick 2.4
import QtQuick.Controls 1.3

Item
{
	width: 800
	height: 600

	signal cancelClicked()

	SquareButton
	{
		id: btnCancel
		height: 60
		anchors.left: parent.left
		anchors.top: parent.top
		text: qsTr("<< Cancel")
		onButtonClicked:
		{
			cancelClicked();
			stack.clear();
			stack.push(stack.initialItem);
		}
	}

	Rectangle
	{
		height: 60
		color: "#1fc91f"
		anchors.left: btnCancel.right
		anchors.right: parent.right
		anchors.top: parent.top

		Text
		{
			text: qsTr("Create a new Calendar")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
			anchors.fill: parent
			font.pixelSize: 30
		}
	}

	StackView
	{
		anchors.top: btnCancel.bottom
		anchors.right: parent.right
		anchors.left: parent.left
		anchors.bottom: parent.bottom

		id: stack
		initialItem: nameCal

		Item
		{
			id: nameCal
			onVisibleChanged:
			{
				if(visible)
				{
					name.selectAll();
					name.forceActiveFocus();
				}
			}

			Rectangle
			{
				id: form
				width: 450
				height: 35
				color: "#1fc91f"
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.verticalCenter: parent.verticalCenter

				TextEdit
				{
					id: name
					text: qsTr("Enter Name Here")
					anchors.fill: parent
					horizontalAlignment: Text.AlignHCenter
					cursorVisible: true
					font.pixelSize: 25
				}
			}

			SquareButton
			{
				height: 50
				text: "Next"
				anchors.top: form.bottom
				anchors.right: form.right
				anchors.left: form.left
				onButtonClicked: { console.log("Next Clicked"); }
			}
		}
	}
}
