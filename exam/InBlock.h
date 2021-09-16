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
        if (sensor.compare(myRoom.getTemperature()) == 0) {
            std::cout << "not changed";
        }
        if (sensor.compare(myRoom.getTemperature()) == 1) {
            compressor.pressure();
            decreseTmpOfRoom();
        std::cout << "cold";
        }
        if (sensor.compare(myRoom.getTemperature()) == -1) {
            compressor.pressure();
            increseTmpOfRoom();
        std::cout << "warm";
        }
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

