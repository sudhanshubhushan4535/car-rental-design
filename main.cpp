#include "rentalSystemClass.h"
int main() {
    RentalSystem* rentalSystem = new RentalSystem();
    Branch* b1 = new Branch("indiranagar");
    Branch* b2 = new Branch("bellandur");
    rentalSystem->addBranch(b1);
    rentalSystem->addBranch(b2);

    rentalSystem->allocatePrice("indiranagar",VehicleType::sydan, 200);
    rentalSystem->allocatePrice("indiranagar",VehicleType::suv, 200);
    rentalSystem->allocatePrice("indiranagar",VehicleType::hachBack, 300);
    rentalSystem->allocatePrice("bellandur",VehicleType::sydan, 150);
    rentalSystem->allocatePrice("bellandur",VehicleType::suv, 250);
    rentalSystem->allocatePrice("bellandur",VehicleType::hachBack, 350);
    
    rentalSystem->addVehicle("abc", VehicleType::sydan, "indiranagar");
    rentalSystem->addVehicle("def", VehicleType::sydan, "bellandur");

    rentalSystem->bookVehicle(VehicleType::sydan, 0, 2);
    rentalSystem->bookVehicle(VehicleType::sydan, 0, 2);
}