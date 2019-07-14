#include "pch.h"
#include "NewspaperObserver.h"

NewspaperObserver::NewspaperObserver()
{
	setNewspaper("Unknown");
	setCityName("Unknown");
	setCurrent_Temperature(0);
}

NewspaperObserver::NewspaperObserver(std::string newspaper, std::string city_name, double current_temperature)
{
	setNewspaper(newspaper);
	setCityName(city_name);
	setCurrent_Temperature(current_temperature);
}

NewspaperObserver::NewspaperObserver(const NewspaperObserver & other)
{
	*this = other;
}

NewspaperObserver::~NewspaperObserver()
{
}

NewspaperObserver & NewspaperObserver::operator=(const NewspaperObserver & other)
{
	if (this != &other)
	{
		setNewspaper(other.getNewspaper());
		setCityName(other.getCityName());
		setCurrent_Temperature(other.getCurrentTemperature());
	}
	return *this;
}

std::string NewspaperObserver::getNewspaper() const
{
	return this->newspaper;
}

std::string NewspaperObserver::getCityName() const
{
	return this->city_name;
}

double NewspaperObserver::getCurrentTemperature() const
{
	return this->current_temperature;
}

void NewspaperObserver::setNewspaper(std::string new_newspaper)
{
	this->newspaper = new_newspaper;
}

void NewspaperObserver::setCityName(std::string new_cityName)
{
	this->city_name = new_cityName;
}

void NewspaperObserver::setCurrent_Temperature(double new_temperature)
{
	this->current_temperature = new_temperature;
}

void NewspaperObserver::update(std::string city_name,double temperature) 
{
	setCityName(city_name);
	setCurrent_Temperature(temperature);
	std::cout << "Update: " << getNewspaper() << ": " << "The temperature in " << getCityName() << " is " << getCurrentTemperature() << std::endl;
}

void NewspaperObserver::printMeMeteo() const
{
	std::cout << "Newspaper " << getNewspaper() << ": " << "The temperature in " << getCityName() << " is " << getCurrentTemperature() << std::endl;
}
