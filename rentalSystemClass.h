#ifndef RENTALSYSTEMCLASS_H
#define RENTALSYSTEMCLASS_H
#include "branchClass.h"
#include "strategyClass.h"

using namespace std;

class RentalSystem {
    vector<Branch*> allBranch;
    strategyFactory* factory;
    public:

    void addBranch(Branch* branch) {
        allBranch.push_back(branch);
    }

    bool allocatePrice(string branchName, VehicleType type, int price) {
        bool branchExist = false;
        for(int i = 0 ; i < allBranch.size(); i++) {
            if(allBranch[i]->getBranchName() == branchName) {
                branchExist = true;
                allBranch[i]->addCarRent(type, price);
            }
        }

        return branchExist;
    }

    void addVehicle(string vehicleId, VehicleType type, string branchName) {
        for(int i = 0 ; i < allBranch.size(); i++) {
            if(allBranch[i]->getBranchName() == branchName) {
                allBranch[i]->addVehicle(vehicleId, type);
            }
        }
    }

    bool bookVehicle(VehicleType type, int startTime, int endTime) {
        return factory->getObject("default")->doAlgorithm(allBranch, startTime, endTime, type);
    }
};

#endif