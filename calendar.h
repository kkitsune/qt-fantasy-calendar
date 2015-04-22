#ifndef CALENDAR_H
#define CALENDAR_H

#include "month.h"

class Calendar : public QObject
{
	Q_OBJECT
public:
	Calendar(const QString& name, QObject* parent = 0);
	virtual ~Calendar();

	virtual Month* newMonth(const QString& name, uint length);

	static QStringList list();
	static void ensureSaveDirectory();

public slots:
	virtual void close();
};

#endif // CALENDAR_H
