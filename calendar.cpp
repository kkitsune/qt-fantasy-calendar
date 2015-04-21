#include <QSqlDatabase>
#include <QDir>

#include "calendar.h"

static QString Directory = "./save/";

Calendar::Calendar(const QString& name, QObject* parent)
	: QObject(parent)
{
	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(QDir().absolutePath() + Directory + name + ".db");
	db.open();
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
