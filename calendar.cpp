#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>

#include "calendar.h"

static QDir Directory("./save/");

Calendar::Calendar(const QString& name, QObject* parent)
	: QObject(parent)
{
	ensureSaveDirectory();
	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(Directory.absolutePath() + QDir::separator() + name + ".db");
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
		if(!q.exec("CREATE TABLE 'Event' ('id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 'Month' INTEGER NOT NULL, 'Day' INTEGER NOT NULL, 'Year' INTEGER NOT NULL CHECK(Year > 0), 'Name' TEXT NOT NULL UNIQUE, 'Description' TEXT, FOREIGN KEY('Month') REFERENCES 'Month')"))
			qFatal("SQL Error : %s", q.lastError().databaseText().toStdString().c_str());
		db.commit();
	}
}

Calendar::~Calendar()
{
	close();
}

Month* Calendar::newMonth(const QString& name, uint length)
{
	QSqlQuery q;
	q.prepare("INSERT INTO 'Month' (Name, Length) values (?, ?)");
	q.addBindValue(name);
	q.addBindValue(length);
	if(!q.exec())
	{
		qDebug() << q.lastError().text();
		return nullptr;
	}

	q.exec("SELECT MAX(id) as id FROM 'Month' LIMIT 1");
	q.next();
	return new Month(q.value(0).toUInt(), this);
}

QStringList Calendar::list()
{
	ensureSaveDirectory();

	QStringList ret, entries = Directory.entryList();
	for(QString entry : entries)
		if(entry.endsWith(".db"))
			ret.append(entry.split('.').first());

	return ret;
}

void Calendar::ensureSaveDirectory()
{
	if(!Directory.exists())
		QDir().mkdir(Directory.absolutePath());
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
