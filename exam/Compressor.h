#pragma once
#include<iostream>
class Compressor
{
private:
	bool isWork;
public:
	Compressor()
	{
		this->isWork = true;
	}
	void compression() {
		std::cout << "hladogen is compressed\n";
	}
	void pressure() {
		std::cout << "hladogen is pressure\n";
	}
};

