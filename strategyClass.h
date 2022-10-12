#ifndef STRATEGYCLASS_H
#define STRATEGYCLASS_H
#include <limits.h>
#include<vector>
#include "branchClass.h"
using namespace std;

class Strategy {
    public:

    virtual bool doAlgorithm ( vector<Branch*>& allBranch, int startTime, int endTime, VehicleType type) = 0;
};


class minPriceStrategy : public Strategy {
    public:
    bool doAlgorithm ( vector<Branch*>& allBranch, int startTime, int endTime, VehicleType type) {
        int minPrice = INT_MAX;
        int pos;
        bool found = false;
        Vehicle* vehicleFound;
        
        for(int i = 0 ; i < allBranch.size(); i++) {
            auto vehicles = allBranch[i]->getAllVehicle();
            int price = allBranch[i]->getCarRentPrice()[type];
            for(auto vehicle :  vehicles) {
                if(vehicle->getEndTime() <= startTime && price < minPrice) {
                    minPrice = price;
                    pos = i;
                    vehicleFound = vehicle;
                }
            }
        }

        if(minPrice ==INT_MAX)
            return false;

        vehicleFound->setEndTime(endTime);
        cout<<vehicleFound->getVehicleId();
        return true;
    }
};

class strategyFactory {
    public:

    Strategy* getObject(string s) {
        if(s == "default") {
            Strategy* obj = new minPriceStrategy();
            return obj;
        }
    }
};

#endif
