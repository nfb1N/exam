#pragma once
#include<iostream>
class OutBlock
{
protected:
	bool isWork;
public:
	OutBlock()
	{
		this->isWork = true;
	}
	virtual void ventilate() {
		std::cout << "block is ventilated";
	}
};

