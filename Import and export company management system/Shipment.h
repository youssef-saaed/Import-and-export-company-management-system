#pragma once

#include "Vehicle.h"
#include "Order.h"
#include <string>

class Shipment
{
private:
	Vehicle* vehicles;
	Vehicle* availableVehicles;
	Order* waitingOrders;
public:
	Shipment(Vehicle*, Vehicle*, Order*);
	Shipment();
	~Shipment();
	bool setVehicles(Vehicle*);
	Vehicle* getVehicles() const;
	bool setAvailableVehicles(Vehicle*);
	Vehicle* getAvailableVehicles() const;
	bool setWaitingOrders(Order*);
	Order* getWaitingOrders() const;
	bool addVehicle(const Vehicle&);
	bool removeVehicle(const Vehicle&);
	bool changeVehicleState(const Vehicle&, std::string);
	bool addOrder(const Order&);
	bool removeOrder(const Order&);
	bool shipOrder(const Order&);
};

