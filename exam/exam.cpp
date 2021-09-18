#include <iostream>
#include"InBlock.h"
int main()
{
	Room room(23);
	InBlock inBlock(room, 16);
	inBlock.ventilate();
}