#ifndef BRANCHCLASS_H
#define BRANCHCLASS_H
#include<unordered_map>
#include<vector>
#include "vehicleClass.h"
using namespace std;

class Branch {
    string id;
    string branchName;
    vector<Vehicle*> allVehicle;
    unordered_map<VehicleType, double> carRentPrice;

    public:
    
    Branch(string branchName) {
        this->branchName = branchName;
    }

    void addCarRent (VehicleType type, int price){
        carRentPrice[type] = price;
    }

    void addVehicle(string vehicleId, VehicleType type) { 
        Vehicle* vehicle= new Vehicle(type, vehicleId, this->branchName, Status::available);
        allVehicle.push_back(vehicle);
    }

    vector<Vehicle*> getAllVehicle() {
        return allVehicle;
    }

    unordered_map<VehicleType, double> getCarRentPrice() {
        return carRentPrice;
    }

    string getBranchName() {
        return branchName;
    }
};

#endif