#include "Vehicle.h"

Vehicle::Vehicle(const VehicleType& type, const std::string& vehicleDetails, const double& maxMass, const double& maxVolume, const double& availableMass, const double& availableVolume, Order* orders)
{
	setType(type);
	setVehicleDetails(vehicleDetails);
	setMaxMass(maxMass);
	setMaxVolume(maxVolume);
	setAvailableMass(availableMass);
	setAvailableVolume(availableVolume);
	setOrders(orders);
}

Vehicle::~Vehicle()
{
	delete orders;
}

bool Vehicle::setType(const VehicleType& type)
{
	if (type >= 0 && type <= 2) {
		this->type = type;
		return true;
	}
	return false;
}

VehicleType Vehicle::getType() const
{
	return type;
}

bool Vehicle::setVehicleDetails(const std::string& vehicleDetails)
{
	if (vehicleDetails != "") {
		this->vehicleDetails = vehicleDetails;
		return true;
	}
	return false;
}

std::string Vehicle::getVehicleDetails() const
{
	return vehicleDetails;
}

bool Vehicle::setMaxMass(const double& maxMass)
{
	if (maxMass > 0.) {
		this->maxMass = maxMass;
		return true;
	}
	return false;
}

double Vehicle::getMaxMass() const
{
	return maxMass;
}

bool Vehicle::setMaxVolume(const double& maxVolume)
{	
	if (maxVolume > 0.) {
		this->maxVolume = maxVolume;
		return true;
	}
	return false;
}

double Vehicle::getMaxVolume() const
{
	return maxVolume;
}

bool Vehicle::setAvailableMass(const double& availableMass)
{
	if (availableMass > 0.) {
		this->availableMass = availableMass;
		return true;
	}
	return false;
}

double Vehicle::getAvailableMass() const
{
	return availableMass;
}

bool Vehicle::setAvailableVolume(const double& availableVolume)
{
	if (availableVolume > 0.) {
		this->availableVolume = availableVolume;
		return true;
	}
	return false;
}

double Vehicle::getAvailableVolume() const
{
	return availableVolume;
}

bool Vehicle::setOrders(Order* orders)
{
	if (orders) {
		this->orders = orders;
		return true;
	}
	return false;
}

Order* Vehicle::getOrder() const
{
	return orders;
}
