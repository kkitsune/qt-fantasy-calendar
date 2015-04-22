#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "month.h"

Month::Month(uint id, QObject* parent)
	: QObject(parent)
{
	if(!QSqlDatabase::database().isValid())
		qFatal("No valid database opened");

	_id = id;
}

Month::~Month()
{
}

QString Month::name()
{
	QSqlQuery q;
	q.prepare("SELECT Name from 'Month' where id = ?");
	q.addBindValue(_id);
	if(q.next())
		return q.value(0).toString();
	else
		return QString();
}

void Month::setName(const QString& value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Month' set Name = ? where id = ?");
	q.addBindValue(value);
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Month #%i Update failed", _id);
}

uint Month::length()
{
	QSqlQuery q;
	q.prepare("SELECT Length from 'Month' where id = ?");
	q.addBindValue(_id);
	if(q.next())
		return q.value(0).toUInt();
	else
		return 0;
}

void Month::setLength(uint value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Month' set Length = ? where id = ?");
	q.addBindValue(value);
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Month #%i Update failed", _id);
}

