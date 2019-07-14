#pragma once
#include "Observer.h"

class NewspaperObserver : public NewspaperObserver{
	std::string newspaper;
	std::string city_name;
	double current_temperature;
public:
	NewspaperObserver();
	NewspaperObserver(std::string newspaper, std::string city_name, double current_temperature);
	NewspaperObserver(const NewspaperObserver& other);
	~NewspaperObserver();
	NewspaperObserver& operator= (const NewspaperObserver& other);

	std::string getNewspaper() const;
	std::string getCityName() const;
	double getCurrentTemperature() const;

	void setNewspaper(std::string new_newspaper);
	void setCityName(std::string new_cityName);
	void setCurrent_Temperature(double new_temperature);
	virtual void update(std::string city_name, double new_temperature)  override;
	void printMeMeteo() const;
};