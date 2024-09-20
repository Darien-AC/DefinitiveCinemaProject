#pragma once
#ifndef MOVIE_H
#include "define.h"

class Movie
{
private:
	string name;
	string description;
	string country;
	string year;
	string duration;

public:
	Movie();
	Movie(string _name, string _description, string _country, string _year, string _duration);

	void setName(const string& _name);
	void setDescription(const string& _description);
	void setCountry(const string& _country);
	void setYear(const string& _year);
	void setDuration(const string& _duration);

	string getName() const;
	string getDescription() const;
	string getCountry() const;
	string getYear() const;
	string getDuration() const;

	void getMovieInformation();
	void saveMovies();
	string getMovieName(int index);
	void displayMovies();
	string displayInformation();

};

extern Movie* movieList;
extern int movieCount;

#endif