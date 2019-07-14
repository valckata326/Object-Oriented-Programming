#include "pch.h"
#include "MeteoStation.h"


void MeteoStation::setCity(std::string new_city)
{
	this->city = new_city;
}

MeteoStation::MeteoStation()
{
	setCity("Unknown");
	setTemperature(0);
}

MeteoStation::MeteoStation(std::string new_city, double temperature)
{
	setCity(new_city);
	setTemperature(temperature);
}

MeteoStation::MeteoStation(const MeteoStation & other)
{
	*this = other;
}

MeteoStation::~MeteoStation()
{
}

MeteoStation & MeteoStation::operator=(const MeteoStation & other)
{
	if (this != &other)
	{
		setCity(other.getCity());
		setTemperature(other.getTemperature());
	}
	return *this;
}

std::string MeteoStation::getCity() const
{
	return this->city;
}

double MeteoStation::getTemperature() const
{
	return this->temperature;
}

void MeteoStation::setTemperature(double new_temperature)
{
	this->temperature = new_temperature;
}
