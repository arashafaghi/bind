
#include <iostream>
#include "shape.h"
#include <functional>  
#include <memory>

template<typename T>
void logger(T s)
{
	std::cout <<"log : "<< s << '\n';
}

int main()
{
	
	point a(12, 13);
	point b(5, 6);

	/*
		Part 1	Pure virtual functions AKA interfaces 
	*/
	shape* bold = new line(point(1, 1), point(3, 5));
	bold->drawMe();
	//std::cout << bold->lengh() << std::endl;   

	line aline; //local
	auto aline_ptr = new line(a, b); //auto creates a pointer 
	logger<float>(aline.lengh(a, b));
	logger<float>(aline_ptr->lengh(a, b));
	
	
	/*
		Part 2 std::bind
	*/
	using namespace std::placeholders;
	
	//bining a function
	auto temp = std::bind(&logger<int>, _1);
	temp(5);

	//binding a member function 
	line bindedLine;
	auto fun = std::bind(&line::lengh,&bindedLine,_1,_2);
	std::cout << fun(a,b) << std::endl;

	auto fun2 = std::bind(fun, a, _1);
	std::cout << fun2(b) << std::endl;
	
	//binding a member function without object instance 
	auto pointFun = std::bind(&point::multiply, _1);
	logger<int>(pointFun(b));
	

	//question : why can we skip passing instance of point object to multiply in std::bind?

	auto fp = std::bind(&line::getFirstPoint, _1);
	point dummy(fp(bindedLine));
	std::cout << pointFun(dummy) << std::endl;
	

	//hit any key
	delete bold, aline_ptr;
	std::cin.get();
}

//Next will be lambda and difference between lambda functions and std::bind functions. 
