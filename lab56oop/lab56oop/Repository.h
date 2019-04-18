#pragma once
#include "Song.h"
#include "DynamicVector.h"
#include <vector>

class Repository
{
private:
	std::vector<Movie> movies;

public:
	/*
		Default constructor.
	*/
	Repository() {}

	/*
		Adds a movie to the repository.
		Input: m - movie.
		Output: the movie is added to the repository.
	*/
	void addMovie(const Movie& m);

	void deleteMovie(Movie& m);
	
	void updateMovie(const Movie& m1, const Movie& m2);


	/*
		Finds a movie, by genre and title.
		Input: genre, title - string
		Output: the movie that was found, or an "empty" movie, if nothing was found.
	*/
	Movie findByGenreAndTitle(const std::string& genre, const std::string& title);

	std::vector<Movie> getMovies() { return movies; }

	Movie getByTitle(std::string& title);
};