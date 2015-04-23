#ifndef MOON_H
#define MOON_H

#include <QObject>

class Moon : public QObject
{
	Q_OBJECT
public:
	Moon(uint id, QObject* parent = 0);
	virtual ~Moon();

	virtual inline uint id() { return _id; }

	virtual QString name();
	virtual void setName(const QString& value);

	virtual uint revolution();
	virtual void setRevolution(uint value);

	virtual QColor color();
	virtual void setColor(const QColor& value);

protected:
	uint _id;
};

#endif // MOON_H
