#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>

#include "calendar.h"

static QString Directory = "./save/";

Calendar::Calendar(const QString& name, QObject* parent)
	: QObject(parent)
{
	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(QDir().absolutePath() + Directory + name + ".db");
	db.open();

	if(db.tables().empty())
	{
		QSqlQuery q;
		if(!q.exec("CREATE TABLE 'Moon' ('id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 'Name' TEXT NOT NULL UNIQUE, 'Revolution' INTEGER NOT NULL, 'Color' INTEGER NOT NULL)"))
			qFatal("SQL Error : %s", q.lastError().databaseText().toStdString().c_str());
		if(!q.exec("CREATE TABLE 'Month' ('id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 'Name' TEXT NOT NULL UNIQUE, 'Length' INTEGER NOT NULL)"))
			qFatal("SQL Error : %s", q.lastError().databaseText().toStdString().c_str());
		if(!q.exec("CREATE TABLE 'Day' ('id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 'Name' TEXT NOT NULL UNIQUE)"))
			qFatal("SQL Error : %s", q.lastError().databaseText().toStdString().c_str());
		if(!q.exec("CREATE TABLE 'Event' ('id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 'Month' INTEGER NOT NULL, 'Day' INTEGER NOT NULL, 'Year' INTEGER NOT NULL CHECK(Year > 0), 'Name' TEXT NOT NULL UNIQUE, 'Description' TEXT, FOREIGN KEY('Month') REFERENCES 'Month', FOREIGN KEY('Day') REFERENCES 'Day')"))
			qFatal("SQL Error : %s", q.lastError().databaseText().toStdString().c_str());
		db.commit();
	}
}

Calendar::~Calendar()
{
	close();
}

QStringList Calendar::list()
{
	QDir path(Directory);
	if(!path.exists())
		QDir().mkdir(Directory);

	QStringList ret, entries = path.entryList();
	for(QString entry : entries)
		if(entry.endsWith(".db"))
			ret.append(entry.split('.').first());

	return ret;
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
