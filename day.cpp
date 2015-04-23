#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "day.h"

Day::Day(uint id, QObject* parent)
	: QObject(parent)
{
	_id = id;
}

Day::~Day()
{
}

QString Day::name()
{
	QSqlQuery q;
	q.prepare("SELECT Name from 'Day' where id = ?");
	q.addBindValue(_id);
	q.exec();
	if(q.next())
		return q.value(0).toString();
	else
		return QString();
}

void Day::setName(const QString& value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Day' set Name = ? where id = ?");
	q.addBindValue(value);
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Day #%i Update failed", _id);
}
