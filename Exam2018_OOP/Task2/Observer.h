#pragma once
#include <iostream>
#include <string>
class Observer {
public:
	virtual void update(std::string city_name, double temperature)  = 0;
};