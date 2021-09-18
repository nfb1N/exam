#pragma once
#include "OutBlock.h"
#include "Room.h"
#include "Compressor.h"
#include "Sensor.h"
class InBlock :
    public OutBlock
{
private:
    Room myRoom;
    Sensor sensor;
    Compressor compressor;
public:
    InBlock(Room& room, unsigned int tmp) : OutBlock() {
        this->myRoom = room;
        this->sensor.setTemperature(tmp);
    }
    virtual void ventilate() override{
        bool isOpen= false;
        while (sensor.compare(myRoom.getTemperature()) != 0) {
            isOpen= true;
            if (sensor.compare(myRoom.getTemperature()) == 1) {
                compressor.pressure();
                decreseTmpOfRoom();
                std::cout << "cold\n";
            }
            if (sensor.compare(myRoom.getTemperature()) == -1) {
                compressor.pressure();
                increseTmpOfRoom();
                std::cout << "warm\n";
            }
        }
            if(!isOpen)std::cout << "not changed\n";
            std::cout << "stoped\n";
    }
    void increseTmpOfRoom(){
        unsigned int tmp = this->myRoom.getTemperature();
        this->myRoom.setTemperature(++tmp);
    }

    void decreseTmpOfRoom() {
        unsigned int tmp = this->myRoom.getTemperature();
        this->myRoom.setTemperature(--tmp);
    }
};

