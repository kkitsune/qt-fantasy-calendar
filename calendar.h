#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>

class Calendar : public QObject
{
	Q_OBJECT
public:
	Calendar(const QString& name, QObject* parent = 0);
	virtual ~Calendar();

	static QStringList list();

public slots:
	virtual void close();
};

#endif // CALENDAR_H
