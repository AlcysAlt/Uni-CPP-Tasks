#include <iostream>
#include <string>
using namespace std;
class City
{
private:
	string name;
	float coordinates;

public:
	void airports();
	void weather();

};

class Airport
{
private:
	float airportCode;
	int noOfTerminals;

public:
	void landFlights();
	void departFlights();
	int runwaysAvailable();
	float windSpeed();
	void windDirection();
};

class Airline
{
private:
	string name;
	int flights;
	int planes;
	int pilots;

public:
	void addNewFlight();
	void removeFlight();
	void buyPlane();
	void sellPlane();
};

class Plane
{
private:
	float planeNo;
	string model;
	float capacity;
	float flightRange;

public:
	void refuel();
	void takeoff();
	void land();

};

class Pilot
{
private:
	string name;
	float flightHours;
	string experience;

public:
	void flyPlane();
};

class Seat
{
private:
	float seatNumber;
	string flightClass;
	float cost;

public:
	bool isOccupied();
};

class Flight
{
private:
	float flightNumber;
	string destinations;

public:
	void assignPilot();
	void assignPlane();
	void assignPassanger();
	void assignDestination();
	float arrivalTime();
	float departureTime();
};

class Passenger
{
private:
	string name;
	string passportNumber;
	string ticket;

public:
	void travel();
	void bookFlight();

};


int main()
{
	
	std::cout << "Hello World!\n";
}

