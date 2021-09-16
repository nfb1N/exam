#pragma once
class Sensor
{
private:
	bool isWork;
	unsigned int inTemperature;
public:
	Sensor()
	{
		this->inTemperature = 0;
		this->isWork = true;
	}
	Sensor(unsigned int tmp)
	{
		this->inTemperature = tmp;
		this->isWork = true;
	}
	short compare(unsigned int outTmp) {
		if (this->inTemperature < outTmp)return 1;
		if (this->inTemperature == outTmp)return 0;
		if (this->inTemperature > outTmp)return -1;
	}
	unsigned int getTemperature() {
		return this->inTemperature;
	}
	void setTemperature(unsigned int tmp) {
		this->inTemperature = tmp;
	}
};

