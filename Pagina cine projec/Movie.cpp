#include "Movie.h"

Movie* movieList = nullptr;
int movieCount = 0;

Movie::Movie()
{
	name = "";
	description = "";
	country = "";
	year = "";
}

Movie::Movie(string _name, string _description, string _country, string _year, string _duration)
{
	name = _name;
	description = _description;
	country = _country;
	year = _year;
	duration = _duration;
}



void Movie::setName(const string& _name) {
	name = _name;
}

void Movie::setDescription(const string& _description) {
	description = _description;
}

void Movie::setCountry(const string& _country) {
	country = _country;
}

void Movie::setYear(const string& _year)
{
	year = _year;
}

void Movie::setDuration(const string& _duration)
{
	duration = _duration;
}



string Movie::getName() const
{
	return name;
}

string Movie::getDescription() const
{
	return description;
}

string Movie::getCountry() const
{
	return country;
}

string Movie::getYear() const
{
	return year;
}

string Movie::getDuration() const
{
	return duration;
}



void Movie::getMovieInformation()
{
	string information;

	cin.ignore();
	cout << TURQUOISE "Digite el nombre de la pelicula: " RESET;
	getline(cin, information);
	setName(information);

	cout << TURQUOISE "\nDigite el anyo de la pelicula: " RESET;
	cin >> information;
	setYear(information);

	cout << TURQUOISE "\nDigite el pais de la pelicula: " RESET;
	cin >> information;
	setCountry(information);

	cout << TURQUOISE "\nDigite la duracion de la pelicula: " RESET;
	cin >> information;
	cin.ignore();
	setDuration(information);

	cout << TURQUOISE "\nDigite la sinopsis de la pelicula: " RESET;
	getline(cin, information);
	system("cls");
	setDescription(information);
}

void Movie::saveMovies()
{
	Movie* newMovieList = new Movie[movieCount + 1];

	for (int i = 0; i < movieCount; ++i) {
		newMovieList[i] = movieList[i];
	}

	cout << "\nAgregue la informacion de la nueva pelicula:\n\n";
	newMovieList[movieCount].getMovieInformation();

	delete[] movieList;

	movieList = newMovieList;

	movieCount++;

	cout << GREEN "\nPELICULA AGREGADA EXITOSAMENTE\n" RESET;
	system("pause");
	system("cls");
}

string Movie::getMovieName(int index)
{
	if (index >= 0 && index < movieCount) {
		return movieList[index].getName();
	}
}

void Movie::displayMovies()
{
	for (int i = 0; i < movieCount; ++i) {
		cout << movieList[i].displayInformation();
	}
}

string Movie::displayInformation()
{
	string totalInformation = "";

	totalInformation = GREEN "\n" + name + "\n\n" + CYAN + year + "\n" + PURPLE + country + YELLOW "\nDuracion: " + ORANGE + duration + TURQUOISE "\n\n" + "Sinopsis: \n" RESET + description + "\n\n" + BLUE "------------------------------------------------------------------------------------------------------------------------" + "\n\n\n" RESET;

	return totalInformation;
}
