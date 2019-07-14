#pragma once
#include <iostream>
class MeteoStation {
	std::string city;
	double temperature;
	void setCity(std::string new_city) ;
public:
	MeteoStation();
	MeteoStation(std::string new_city, double temperature);
	MeteoStation(const MeteoStation& other);
	~MeteoStation();
	MeteoStation& operator=(const MeteoStation& other);


	std::string getCity() const;
	double getTemperature() const;

	
	void setTemperature(double new_temperature);


};
