#pragma once
#include "define.h"
#include "Movie.h"

class Theater
{
private:
	string roomNumber;
	int rooms;
	int totalSeats;
	char seats[ROWS][COLUMNS];
	int price;
	int totalTickets;
	int billNumber;

public:
	Theater();
	Theater(string _roomNumber, int _totalPrice, int _billNumber, int _rooms);

	void setRoomNumber(const string& _roomNumber);
	void setRooms(int _rooms);
	void setTotalSeats(int _totalSeats);
	void setPrice(int _price);
	void setTotalTickets(int _totalTickets);
	void setBillNumber(int _billNumber);

	string getRoomNumber() const;
	int getTotalSeats() const;
	int getRooms() const;
	int getPrice() const;
	int getTotalTickets() const;
	int getBillNumber() const;

	void showLetterOfSeats(int seatsNumber[COLUMNS]);
	void saveRoomInformation(string* &rooms);
	void showRoomInformation(string*& rooms);
	void showTheaterSeats();
	void theaterSeats();
};