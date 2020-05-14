#pragma once

class IPoint
{
private:
	int x, y;

public:
	
	IPoint();							
	IPoint(int x, int y);
	IPoint(const IPoint& other);		

	~IPoint();

	// selektory - getter
	int getX() const;
	int getY() const;
	void Display()const;

	// setter
	void setx(int nowyX);
	void sety(int nowyY);
	void MoveTo(int x, int y);
	void MoveTo(const IPoint& other);
	void MoveByDistance(int x, int y);


};