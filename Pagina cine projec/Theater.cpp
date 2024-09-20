#include "Theater.h"

Movie movie;

Theater::Theater()
{
	roomNumber = "";
	rooms = 2;
	totalSeats = ROWS * COLUMNS;
	price = 3200;
	totalTickets = 0;
	billNumber = 0;

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			seats[i][j] = 'O';
		}
	}
}

Theater::Theater(string _roomNumber, int _totalPrice, int _billNumber, int _rooms)
{
	roomNumber = _roomNumber;
	rooms = _rooms;
	totalSeats = ROWS * COLUMNS;
	price = _totalPrice;
	totalTickets = 0;
	billNumber = _billNumber;
}

void Theater::setRoomNumber(const string& _roomNumber) {
	roomNumber = _roomNumber;
}

void Theater::setRooms(int _rooms) {
	rooms = _rooms;
}

void Theater::setTotalSeats(int _totalSeats) {
	totalSeats = _totalSeats;
}

void Theater::setPrice(int _price) {
	price = _price;
}

void Theater::setTotalTickets(int _totalTickets) {
	totalTickets = _totalTickets;
}

void Theater::setBillNumber(int _billNumber) {
	billNumber = _billNumber;
}


string Theater::getRoomNumber() const {
	return roomNumber;
}

int Theater::getTotalSeats() const {
	return totalSeats;
}

int Theater::getRooms() const {
	return rooms;
}

int Theater::getPrice() const {
	return price;
}

int Theater::getTotalTickets() const {
	return totalTickets;
}

int Theater::getBillNumber() const {
	return billNumber;
}



void Theater::saveRoomInformation(string*& rooms)
{
	string movieName;
	int index = 0;

	rooms = new string[getRooms()];

	cin.ignore();

	while (index < getRooms()) {
		cout << GREEN "\nDigite el nombre de la pelicula que desea agregar en la sala " << index + 1 << ": " RESET;
		getline(cin, movieName);

		bool found = false;
		for (int i = 0; i < movieCount; i++) {
			if (movieName == movieList[i].getName()) {
				found = true;
			}
		}

		if (found) {
			rooms[index] = movieName;
			index++;
		}
		else {
			cout << RED "No se encontró dicha película. Intente de nuevo.\n" RESET;
			system("pause");
			system("cls");
		}
	}

	cout << GREEN "\SALAS ASIGNADAS EXITOSAMENTE\n" RESET;
	system("pause");
	system("cls");
}


void Theater::showRoomInformation(string*& rooms)
{
	for (int i = 0; i < getRooms(); i++) {
		cout << GREEN <<rooms[i] << RESET << endl;
	}
}



void Theater::showTheaterSeats()
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (seats[i][j] == 'O') {
				cout << GREEN << seats[i][j] << RESET << ' ';
				}
			else if (seats[i][j] == 'X') {
					cout << RED << seats[i][j] << RESET << ' ';
					}
			else {
				cout << seats[i][j] << ' ';
			}
		}
		cout << endl;
	}
}

void Theater::theaterSeats()
{
	int totalSeats;
	string* selectedSeats = nullptr;
	bool seatTaken = false;

	cout << "Asientos del teatro:\n";
	showTheaterSeats();

	cout << "\n¿Cuántos asientos desea comprar? ";
	cin >> totalSeats;

	selectedSeats = new string[totalSeats];

	for (int i = 0; i < totalSeats; ++i) {
		string seatSelection;

		do {
			seatTaken = false;

			cout << "Seleccione el asiento (ejemplo: A3, B2, etc.): ";
			cin >> seatSelection;

			char row = seatSelection[0];
			int column = stoi(seatSelection.substr(1)) - 1;

			int rowIndex = row - 'A';

			if (seats[rowIndex][column] == 'X') {
				cout << "El asiento " << seatSelection << " ya está ocupado. Elija otro asiento.\n";
				seatTaken = true;
			}
			else {
				selectedSeats[i] = seatSelection;
				seats[rowIndex][column] = 'X';
			}
		} while (seatTaken);
	}

	cout << "\nAsientos seleccionados: ";
	for (int i = 0; i < totalSeats; ++i) {
		cout << selectedSeats[i] << " ";
	}
	cout << endl;

	delete[] selectedSeats;

	cout << "\nAsientos del teatro después de la selección:\n";
	showTheaterSeats();
}

