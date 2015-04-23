#ifndef MOON_H
#define MOON_H

#include <QObject>

class Moon : public QObject
{
	Q_OBJECT
	Q_PROPERTY(uint id READ id)
	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(uint revolution READ revolution WRITE setRevolution)
	Q_PROPERTY(QColor color READ color WRITE setColor)
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
