#pragma once
#include "Shipment.h"

Shipment::Shipment(Vehicle* vehicles, Vehicle* availableVehicles, Order* waitingOrders)
{
	setVehicles(vehicles);
	setAvailableVehicles(availableVehicles);
	setWaitingOrders(waitingOrders);
}

Shipment::~Shipment()
{
	delete vehicles;
	delete availableVehicles;
	delete waitingOrders;
}

bool Shipment::setVehicles(Vehicle* vehicles)
{
	if (vehicles) {
		this->vehicles = vehicles;
		return true;
	}
	return false;
}

Vehicle* Shipment::getVehicles() const
{
	return vehicles;
}

bool Shipment::setAvailableVehicles(Vehicle* availableVehicles)
{
	if (availableVehicles) {
		this->availableVehicles = availableVehicles;
		return true;
	}
	return false;
}

Vehicle* Shipment::getAvailableVehicles() const
{
	return availableVehicles;
}

bool Shipment::setWaitingOrders(Order* waitingOrders)
{
	if (waitingOrders) {
		this->waitingOrders = waitingOrders;
		return true;
	}
	return false;
}

Order* Shipment::getWaitingOrders() const
{
	return waitingOrders;
}
