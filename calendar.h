#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>

class Calendar : public QObject
{
	Q_OBJECT
public:
	Calendar(QObject* parent = 0);
	virtual ~Calendar();
};

#endif // CALENDAR_H
