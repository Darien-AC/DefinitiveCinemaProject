#include "Sale.h"

Sale::Sale() : reservationNumber(0), movieName(""), schedule(""), roomNumber(""), seats(nullptr),
numSeats(0), customerID(""), cardNumber(""), totalPrice(0.0) {}

Sale::Sale(const Movie& movie, const Theater& theater, const Schedule& schedule, int reservationNum,
    const string& movieName, const string& scheduleTime, const string& roomNum,
    string* seatsArray, int seatCount, const string& customerId,
    const string& cardNum, double price)
    : movieSale(movie), theaterSale(theater), scheduleSale(schedule), reservationNumber(reservationNum),
    movieName(movieName), schedule(scheduleTime), roomNumber(roomNum), numSeats(seatCount),
    customerID(customerId), cardNumber(cardNum), totalPrice(price)
{
    seats = new string[seatCount];
    for (int i = 0; i < seatCount; ++i) {
        seats[i] = seatsArray[i];
    }
}


void Sale::setMovieSale(const Movie& movie) { 
    movieSale = movie; 
}

void Sale::setTheaterSale(const Theater& theater) { 
    theaterSale = theater; 
}

void Sale::setScheduleSale(const Schedule& schedule) { 
    scheduleSale = schedule; 
}

void Sale::setReservationNumber(int number) { 
    reservationNumber = number; 
}

void Sale::setMovieName(const string& name) {
    movieName = name; 
}

void Sale::setSchedule(const string& scheduleTime) { 
    schedule = scheduleTime; 
}

void Sale::setRoomNumber(const string& roomNum) {
    roomNumber = roomNum; 
}

void Sale::setSeats(string* seatsArray, int seatCount) {
    if (seats != nullptr) {
        delete[] seats;
    }
    numSeats = seatCount;
    seats = new string[seatCount];
    for (int i = 0; i < seatCount; ++i) {
        seats[i] = seatsArray[i];
    }
}

void Sale::setCustomerID(const string& id) { 
    customerID = id; 
}

void Sale::setCardNumber(const string& cardNum) { 
    cardNumber = cardNum; 
}

void Sale::setTotalPrice(double price) { 
    totalPrice = price; 
}

Movie Sale::getMovieSale() const {
    return movieSale; 
}

Theater Sale::getTheaterSale() const { 
    return theaterSale; 
}

Schedule Sale::getScheduleSale() const { 
    return scheduleSale; 
}

int Sale::getReservationNumber() const { 
    return reservationNumber; 
}

string Sale::getMovieName() const { 
    return movieName; 
}

string Sale::getSchedule() const { 
    return schedule; 
}

string Sale::getRoomNumber() const {
    return roomNumber; 
}

string* Sale::getSeats() const {
    return seats; 
}

int Sale::getNumSeats() const {
    return numSeats; 
}

string Sale::getCustomerID() const {
    return customerID; 
}

string Sale::getCardNumber() const {
    return cardNumber; 
}

double Sale::getTotalPrice() const { 
    return totalPrice; 
}


void Sale::processPayment(Reservation reservation) {
    int inputReservationNumber;
    cout << GREEN "Ingrese el número de reserva: " RESET;
    cin >> inputReservationNumber;

    if (reservation.getReservationNumber() == inputReservationNumber) {
        cout << GREEN "Ingrese su número de identificación: " RESET;
        cin >> customerID;
        cout << GREEN "Ingrese el número de tarjeta: " RESET;
        cin >> cardNumber;

        reservationNumber = reservation.getReservationNumber();
        setReservationNumber(reservationNumber);
        movieName = reservation.getMovieName();
        setMovieName(movieName);
        schedule = reservation.getSchedule();
        setSchedule(schedule);
        roomNumber = reservation.getRoomNumber();
        setRoomNumber(roomNumber);
        numSeats = reservation.getNumSeats();
        

        delete[] seats;
        seats = new string[numSeats];
        for (int i = 0; i < numSeats; ++i) {
            seats[i] = reservation.getSeat(i);
        }

        // Calcular el precio total
        double pricePerSeat = theaterSale.getPrice();
        totalPrice = numSeats * pricePerSeat;
        setTotalPrice(totalPrice);

        printInvoice();
    }
    else {
        cout << RED "Número de reserva no encontrado. Por favor, verifique e intente nuevamente.\n" RESET;
    }
}

void Sale::printInvoice() {
    cout << YELLOW "\n--------- FACTURA ---------\n" RESET;
    cout << GREEN "Número de reserva: " << getReservationNumber() << RESET << endl;
    cout << "Película: " << getMovieName() << endl;
    cout << "Sala: " << getRoomNumber() << endl;
    cout << "Horario: " << getSchedule() << endl;
    cout << "Asientos seleccionados: ";
    for (int i = 0; i < numSeats; ++i) {
        cout << seats[i] << " ";
    }
    cout << endl;
    cout << "ID del cliente: " << customerID << endl;
    cout << "Número de tarjeta: **** **** **** " << cardNumber.substr(cardNumber.size() - 4) << endl;
    cout << YELLOW "Precio total: $" << getTotalPrice() << RESET << endl;
    cout << YELLOW "---------------------------\n" RESET;

    delete[] seats;
}
