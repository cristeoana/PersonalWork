#pragma once
#include <iostream>


class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string source;		// youtube Link

public:
	// default constructor for a song
	Movie();

	// constructor with parameters
	Movie(const std::string& genre, const std::string& title, const int year, const int likes, const std::string& source);
	
	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	std::string getSource() const { return source; }
	int getYear() const { return year; }
	int getLikes() const { return likes; }

	// Plays the current song: the page corresponding to the source link is opened in a browser.
	void play();
	bool operator==(Movie m);
};

