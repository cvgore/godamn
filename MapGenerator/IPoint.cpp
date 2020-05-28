#include "IPoint.h"
#include <iostream>


IPoint::IPoint() // :: = należy do klasy IPoint
{
	this->x = 0;
	this->y = 0;
}

IPoint::IPoint(int x, int y) : x(x), y(y)	// lista inicjalizacyjna - minimalnie zwieksza predkosc
											//	dzialania, jedyna mozliwosc inicjalizacji stalych
{
	this->x = x;	// deklaracja wskaznika do obiektu typu IPoint i elementu x
	this->y = y;	// deklaracja wskaznika do obiektu typu IPoint i elementu y
}

IPoint::IPoint(const IPoint& other)
{
	this->x = other.x;
	this->y = other.y;
}

IPoint::~IPoint()
{
}

int IPoint::getX() const
{
	return x;
}

int IPoint::getY() const
{
	return y;
}

void IPoint::setx(int nowyX)
{
	this->x = nowyX;
}

void IPoint::sety(int nowyY)
{
	this->y = nowyY;
}

void IPoint::MoveTo(int x, int y)
{
	this->setx(x);
	this->sety(y);
}

void IPoint::MoveTo(const IPoint& other)
{
	this->setx(other.getX());
	this->sety(other.getY());
}


void IPoint::MoveByDistance(int x, int y)
{
	this->x += x;
	this->y += y;
}


void IPoint::Display()const
{
	std::cout << this->x << " " << this->y << std::endl;
}
