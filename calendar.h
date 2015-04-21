#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>

class Calendar : public QObject
{
	Q_OBJECT

	static const QString Directory = QString("./Save/");
public:
	Calendar(const QString& name, QObject* parent = 0);
	virtual ~Calendar();

public slots:
	virtual void close();
};

#endif // CALENDAR_H
