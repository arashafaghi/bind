#include <iostream>;
#include <math.h>;
class shape
{
public:
	virtual void drawMe() =0;
	//pure virtual 
	
};

class point :public shape
{
private:
	int x;
	int y;
public:
	point() :x(1), y(1) {}
	point(int a, int b) : x(a), y(b) {}
	void drawMe() override { std::cout << ". i am a Point" << std::endl; }
	int getX() { return x; }
	int getY() { return y; }
	int multiply() { return x * y; } 
};

class line : public shape
{
private:

public:
	point a, b;
	line( const point& first,const point& second) :a(first), b(second) {}
	line() :a(2, 2), b(10, 10) {}
	void drawMe() override { std::cout << "__ i am a Line" << std::endl; }

/*	float lengh() //overloading
	{
		return lengh(this->a, this->b);
	} */
	float lengh(point a, point b)
	{
		int d = pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2);
		return sqrt(d);
	}
	point getFirstPoint() { return a; }
	point getSecondPoint() { return b; }
};

class circle : public shape
{
private:
	point cent;
	line radius;
public:
	void drawMe()override { std::cout << "O i am a Circle" << std::endl; };
};