#pragma once
#include "define.h"
#include "Movie.h"
#include "Schedule.h"
#include "Theater.h"

class Reservation
{
private:
	Movie movieReserve;
	Theater theaterReserve;
	Schedule scheduleReserve;
	int reservationNumber;
	string movieName;
	string schedule;
	string roomNumber;
	string* seats;
	int numSeats;

	string* reservations;
	int reservationCount;
	int maxReservations;

public:
	Reservation();
	Reservation(int number, const string& name, const string& sch, const string& room, const string* selectedSeats, int count);

	void setReservationNumber(int number);
	void setMovieName(const string& name);
	void setSchedule(const string& sch);
	void setRoomNumber(const string& room);
	void setSeats(const string* selectedSeats, int count);
	void setReservations(string* newReservations);
	void setReservationCount(int newCount);
	void setMaxReservations(int newMax);

	int getReservationNumber() const;
	string getMovieName() const;
	string getSchedule() const;
	string getRoomNumber() const;
	int getNumSeats() const;
	string getSeat(int index) const;
	string* getReservations();
	int getReservationCount();
	int getMaxReservations();


	string askForMovieName();
	bool movieExistInRooms(string movieName, string*& rooms, int numRooms);
	int askForRoomNumber(int numRooms);
	bool isValidRoomNumber(int roomNumber, string movieName, string*& rooms, int numRooms);
	int generateReservationNumber();
	string createReservationDetails(string movieName, int roomNumber, string schedule, int reservationNumber);
	void addReservationToDynamicArray(string*& reservations, int& reservationCount, int& maxReservations, string reservationDetails);
	void showReservations();

	void showAllInformation(string*& schedules, string*& rooms);
	void saveReservationInformation(string*& schedules, string*& rooms);
};

