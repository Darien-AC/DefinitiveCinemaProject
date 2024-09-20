#pragma once
#include "Reservation.h" // Asegúrate de incluir el encabezado de Reservation

using namespace std;

class Sale {
private:
    Movie movieSale;
    Theater theaterSale;
    Schedule scheduleSale;
    int reservationNumber;
    string movieName;
    string schedule;
    string roomNumber;
    string* seats;
    int numSeats;
    string customerID;
    string cardNumber;
    double totalPrice;
public:
    Sale();
    Sale(const Movie& movie, const Theater& theater, const Schedule& schedule, int reservationNum, const string& movieName,
        const string& scheduleTime, const string& roomNum, string* seatsArray, int seatCount,
        const string& customerId, const string& cardNum, double price);

    void setMovieSale(const Movie& movie);
    void setTheaterSale(const Theater& theater);
    void setScheduleSale(const Schedule& schedule);
    void setReservationNumber(int number);
    void setMovieName(const string& name);
    void setSchedule(const string& scheduleTime);
    void setRoomNumber(const string& roomNum);
    void setSeats(string* seatsArray, int seatCount);
    void setCustomerID(const string& id);
    void setCardNumber(const string& cardNum);
    void setTotalPrice(double price);

    Movie getMovieSale() const;
    Theater getTheaterSale() const;
    Schedule getScheduleSale() const;
    int getReservationNumber() const;
    string getMovieName() const;
    string getSchedule() const;
    string getRoomNumber() const;
    string* getSeats() const;
    int getNumSeats() const;
    string getCustomerID() const;
    string getCardNumber() const;
    double getTotalPrice() const;

    void processPayment(Reservation reservation);
    void printInvoice();
};