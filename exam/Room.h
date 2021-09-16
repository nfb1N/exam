#pragma once
class Room
{
private:
	unsigned int myTemperature;
public:
	Room()
	{
		this->myTemperature = 0;
	}
	Room(unsigned int tmp)
	{
		this->myTemperature = tmp;
	}
	unsigned int getTemperature() {
		return this->myTemperature;
	}
	void setTemperature(unsigned int tmp) {
		this->myTemperature = tmp;
	}
};

