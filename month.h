#ifndef MONTH_H
#define MONTH_H

#include <QObject>

class Month : public QObject
{
	Q_OBJECT
	Q_PROPERTY(uint id READ id)
	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(uint length READ length WRITE setLength)
public:
	Month(uint id, QObject* parent = 0);
	virtual ~Month();

	virtual inline uint id() { return _id; }

	virtual QString name();
	virtual void setName(const QString& value);

	virtual uint length();
	virtual void setLength(uint value);

protected:
	uint _id;
};

#endif // MONTH_H
