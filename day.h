#ifndef DAY_H
#define DAY_H

#include <QObject>

class Day : public QObject
{
	Q_OBJECT
public:
	Day(uint id, QObject *parent = 0);
	virtual ~Day();

	virtual inline uint id() { return _id; }

	virtual QString name();
	virtual void setName(const QString& value);

protected:
	uint _id;
};

#endif // DAY_H
