#pragma once

#include "Order.h"
#include <string>

enum VehicleType { MOTORCYCLE, CAR, TRUCK };

class Vehicle
{
private:
	VehicleType type;
	std::string vehicleDetails;
	double maxMass, maxVolume, availableMass, availableVolume;
	Order* orders;
public:
	Vehicle(const VehicleType&, const std::string&, const double&, const double&, const double&, const double&, Order*);
	Vehicle();
	~Vehicle();
	bool setType(const VehicleType&);
	VehicleType getType() const;
	bool setVehicleDetails(const std::string&);
	std::string getVehicleDetails() const;
	bool setMaxMass(const double&);
	double getMaxMass() const;
	bool setMaxVolume(const double&);
	double getMaxVolume() const;
	bool setAvailableMass(const double&);
	double getAvailableMass() const;
	bool setAvailableVolume(const double&);
	double getAvailableVolume() const;
	bool setOrders(Order*);
	Order* getOrder() const;
	bool addOrder(Order);
	bool removeOrder(Order);
	bool isFull() const;
	bool emptyIt();
	bool shipOrders();
};

