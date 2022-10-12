#ifndef VEHICLECLASS_H
#define VEHICLECLASS_H
#include<iostream>
#include "enumClass.h"
using namespace std;
class Vehicle {
    string vehicleId;
    string branchName;
    VehicleType type;
    Status status;
    int endTime;

    public:
    Vehicle(VehicleType type, string vehicleId, string branchName, Status status) {
        this->type = type;
        this->vehicleId = vehicleId;
        this->branchName = branchName;
        this->status = status;
        this->endTime = 0;
    }

    Status getStatus() {
        return this->status;
    }

    void setStatus(Status status) {
        this->status = status;
    }

    int getEndTime() {
        return endTime;
    }

    void setEndTime(int time) {
        this->endTime = time;
    }

    string getVehicleId() {
        return vehicleId; 
    }
};

#endif