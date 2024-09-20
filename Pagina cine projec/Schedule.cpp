#include "Schedule.h"

Movie scheduleMovie;
Theater theather;

Schedule::Schedule() {
	startTime = "00:00";
	endTime = "00:00";
	date = "01-01-1970";
}

Schedule::Schedule(const string& startTime, const string& endTime, const string& date) {
	this->startTime = startTime;
	this->endTime = endTime;
	this->date = date;
}


void Schedule::setStartTime(const string& startTime) {
	this->startTime = startTime;
}

void Schedule::setEndTime(const string& endTime) {
	this->endTime = endTime;
}

void Schedule::setDate(const string& date) {
	this->date = date;
}


string Schedule::getStartTime() const {
	return startTime;
}

string Schedule::getEndTime() const {
	return endTime;
}

string Schedule::getDate() const {
	return date;
}



void Schedule::saveDatesInformation(string*& schedules)
{
	int index = 0;
	schedules = new string[theather.getRooms()];
	
	while (index < theather.getRooms()) {

		cout << BLUE "\nDigite la fecha de la pelicula que desea agregar en la sala " << index + 1 << ": " RESET;
		cin >> date;
		setDate(date);

		cout << CYAN "\nDigite la hora de inicio de la pelicula en la sala " << index + 1 << ": " RESET;
		cin >> startTime;
		setStartTime(startTime);

		cout << TURQUOISE "\nDigite la fecha de la pelicula que desea agregar en la sala " << index + 1 << ": " RESET;
		cin >> endTime;
		setEndTime(endTime);

		schedules[index] = date + TURQUOISE "\nHora de inicio: " RESET + startTime + TURQUOISE "\nHora de salida: " RESET + endTime;

		index++;
	}
	cout << GREEN "\HORARIO AGREGADO EXITOSAMENTE\n" RESET;
	system("pause");
	system("cls");
}

void Schedule::showDatesInformation(string*& schedules)
{
	for (int i = 0; i < theather.getRooms(); i++) {
		cout << TURQUOISE "Fecha: " RESET << schedules[i] << endl;
	}
}
