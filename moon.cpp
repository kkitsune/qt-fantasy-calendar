#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QColor>

#include "moon.h"

Moon::Moon(uint id, QObject* parent)
	: QObject(parent)
{
	_id = id;
}

Moon::~Moon()
{
}

QString Moon::name()
{
	QSqlQuery q;
	q.prepare("SELECT Name from 'Moon' where id = ?");
	q.addBindValue(_id);
	q.exec();
	if(q.next())
		return q.value(0).toString();
	else
		return QString();
}

void Moon::setName(const QString& value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Moon' set Name = ? where id = ?");
	q.addBindValue(value);
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Moon #%i Update failed", _id);
}

uint Moon::revolution()
{
	QSqlQuery q;
	q.prepare("SELECT Revolution from 'Moon' where id = ?");
	q.addBindValue(_id);
	q.exec();
	if(q.next())
		return q.value(0).toUInt();
	else
		return 0;
}

void Moon::setRevolution(uint value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Moon' set Revolution = ? where id = ?");
	q.addBindValue(value);
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Moon #%i Update failed", _id);
}

QColor Moon::color()
{
	QSqlQuery q;
	q.prepare("SELECT Color from 'Moon' where id = ?");
	q.addBindValue(_id);
	q.exec();
	if(q.next())
		return QColor::fromRgb(q.value(0).toUInt());
	else
		return QColor();
}

void Moon::setColor(const QColor& value)
{
	QSqlQuery q;
	q.prepare("UPDATE 'Moon' set Color = ? where id = ?");
	q.addBindValue(value.rgb());
	q.addBindValue(_id);
	if(!q.exec())
		qFatal("Moon #%i Update failed", _id);
}
