#ifndef CALENDAR_H
#define CALENDAR_H

#include "month.h"
#include "moon.h"
#include "day.h"

class Calendar : public QObject
{
	Q_OBJECT
public:
	Calendar(const QString& name, QObject* parent = 0);
	virtual ~Calendar();

	Q_INVOKABLE virtual Month* newMonth(const QString& name, uint length);
	Q_INVOKABLE virtual Moon* newMoon(const QString& name, uint revolution, const QColor& color);
	Q_INVOKABLE virtual Day* newDay(const QString& name);

	static QStringList list();
	static void ensureSaveDirectory();

public slots:
	virtual void close();
};

#endif // CALENDAR_H
