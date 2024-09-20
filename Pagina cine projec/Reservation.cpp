#include "Reservation.h"

Reservation::Reservation()
{
	reservationNumber = 0;
	movieName = "";
	schedule = "";
	roomNumber = "";
	numSeats = 0;

	maxReservations = 10;
	reservations = new string[maxReservations];
	reservationCount = 0;
}

Reservation::Reservation(int number, const string& name, const string& sch, const string& room, const string* selectedSeats, int count)
	: reservationNumber(number), movieName(name), schedule(sch), roomNumber(room), numSeats(count) {
	seats = new string[numSeats];
	for (int i = 0; i < numSeats; ++i) {
		seats[i] = selectedSeats[i];
	}

	delete[] reservations;
}

void Reservation::setReservationNumber(int number) {
	reservationNumber = number;
}

void Reservation::setMovieName(const string& name) {
	movieName = name;
}

void Reservation::setSchedule(const string& sch) {
	schedule = sch;
}

void Reservation::setRoomNumber(const string& room) {
	roomNumber = room;
}

void Reservation::setSeats(const string* selectedSeats, int count) {
	if (seats != nullptr) {
		delete[] seats;
	}
	numSeats = count;
	seats = new string[numSeats];
	for (int i = 0; i < numSeats; ++i) {
		seats[i] = selectedSeats[i];
	}
}

void Reservation::setReservations(string* newReservations) {
	delete[] reservations;
	reservations = newReservations;
}

void Reservation::setReservationCount(int newCount) {
	reservationCount = newCount;
}

void Reservation::setMaxReservations(int newMax) {
	maxReservations = newMax;
}

int Reservation::getReservationNumber() const {
	return reservationNumber;
}

string Reservation::getMovieName() const {
	return movieName;
}

string Reservation::getSchedule() const {
	return schedule;
}

string Reservation::getRoomNumber() const {
	return roomNumber;
}

int Reservation::getNumSeats() const {
	return numSeats;
}

string Reservation::getSeat(int index) const {
	if (index >= 0 && index < numSeats) {
		return seats[index];
	}
	return "";
}

string* Reservation::getReservations()
{
	return reservations;
}

int Reservation::getReservationCount()
{
	return reservationCount;
}

int Reservation::getMaxReservations()
{
	return maxReservations;
}



string Reservation::askForMovieName()
{
	cin.ignore();
	string movieName;
	cout << GREEN "Digite el nombre de la película para la reserva: " RESET;
	getline(cin, movieName);
	return movieName;
}

bool Reservation::movieExistInRooms(string movieName, string*& rooms, int numRooms)
{
	for (int i = 0; i < numRooms; ++i) {
		if (movieName == rooms[i]) {
			return true;
		}
	}
	return false;
}

int Reservation::askForRoomNumber(int numRooms)
{
	int roomNumber;
	cout << CYAN "Digite el número de la sala donde desea hacer la reserva (1-" << numRooms << "): " RESET;
	cin >> roomNumber;
	return roomNumber;
}

bool Reservation::isValidRoomNumber(int roomNumber, string movieName, string*& rooms, int numRooms)
{
	if (roomNumber > 0 && roomNumber <= numRooms) {
		if (movieName == rooms[roomNumber - 1]) {
			return true;
		}
	}
	return false;
}

int Reservation::generateReservationNumber()
{
	int reservationNumberr = 0;
	srand(static_cast<unsigned int>(time(0)));
	reservationNumberr = rand() % 9000 + 1000;
	setReservationNumber(reservationNumberr);
	return reservationNumberr;
}

string Reservation::createReservationDetails(string movieName, int roomNumber, string schedule, int reservationNumber)
{
	return "Película: " + movieName + "\nSala: " + to_string(roomNumber) + "\nHorario: " + schedule + "\nNúmero de reserva: " + to_string(reservationNumber);
}

void Reservation::addReservationToDynamicArray(string*& reservations, int& reservationCount, int& maxReservations, string reservationDetails)
{
	if (reservationCount < maxReservations) {
		reservations[reservationCount] = reservationDetails;
		reservationCount++;
		setReservationCount(reservationCount);
	}
	else {
		maxReservations *= 2;
		string* temp = new string[maxReservations];
		for (int i = 0; i < reservationCount; ++i) {
			temp[i] = reservations[i];
		}
		delete[] reservations;
		reservations = temp;
		reservations[reservationCount] = reservationDetails;
		reservationCount++;
		setReservationCount(reservationCount);
	}
}

void Reservation::showReservations()
{
	cout << GREEN "Reservas registradas:\n" RESET;
	for (int i = 0; i < reservationCount; ++i) {
		cout << reservations[i] << endl;
	}
}

void Reservation::showAllInformation(string*& schedules, string*& rooms)
{
	for (int i = 0; i < theaterReserve.getRooms(); ++i) {
		cout << GREEN "SALA " << i + 1 << RESET << endl;
		cout << CYAN "Pelicula: " << RESET << rooms[i] << endl;
		cout << BLUE "Horario: " << RESET << schedules[i] << endl;
		cout << BLUE "--------------------------------------------------" << RESET << endl;
	}
}

void Reservation::saveReservationInformation(string*& schedules, string*& rooms)
{
	string movieName = askForMovieName();
	int numRooms = theaterReserve.getRooms();

	if (!movieExistInRooms(movieName, rooms, numRooms)) {
		cout << RED "La película " << movieName << " no se encuentra en ninguna sala.\n" RESET;
		return;
	}

	int roomNumber = askForRoomNumber(numRooms);

	if (!isValidRoomNumber(roomNumber, movieName, rooms, numRooms)) {
		cout << RED "La película " << movieName << " no está disponible en la sala " << roomNumber << ".\n" RESET;
		return;
	}

	int reservationNumber = generateReservationNumber();
	setReservationNumber(reservationNumber);

	cout << GREEN "Reserva exitosa para la película " << movieName << " en la sala " << roomNumber << ".\n" RESET;
	cout << BLUE "Horario: " << RESET << schedules[roomNumber - 1] << endl;
	cout << PINK "Número de reserva: " << reservationNumber << RESET << endl;

	string reservationDetails = createReservationDetails(movieName, roomNumber, schedules[roomNumber - 1], reservationNumber);
	cout << YELLOW "\nDetalles de la reserva:\n" RESET << reservationDetails << endl;

	addReservationToDynamicArray(this->reservations, this->reservationCount, this->maxReservations, reservationDetails);

	theaterReserve.theaterSeats();
}


