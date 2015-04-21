#include <QCoreApplication>
#include <QSqlDatabase>

#include "calendar.h"

Calendar::Calendar(const QString& name, QObject* parent)
	: QObject(parent)
{
	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(Directory + name);
	db.open();
}

Calendar::~Calendar()
{
	close();
}

void Calendar::close()
{
	auto db = QSqlDatabase::database();
	if(db.isValid())
	{
		db.close();
		QSqlDatabase::removeDatabase(db.connectionName());
	}
}
