#pragma once
#include "DynamicVector.h"
#include "Song.h"
#include <vector>

class PlayList
{
private:
	std::vector<Movie> movies;
	int current;

public:
	PlayList();

	// Adds a movie to the playlist.
	void add(const Movie& movie);

	// Returns the movie that is currently playing.
	Movie getCurrentMovie();

	// Starts the playlist - plays the first movie.
	void play();

	// Plays the next movie in the playlist.
	void next();

	std::vector<Movie>& getMovies() { return movies; }

	// Checks if the playlist is empty.
	bool isEmpty();

	Movie findByGenreAndTitle(const std::string& genre, const std::string& title);

	
};

