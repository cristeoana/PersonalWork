#pragma once
#include "Repository.h"
#include "PlayList.h"

class Controller
{
private:
	Repository repo;
	PlayList playList;

public:
	Controller(const Repository& r) : repo(r) {}

	Repository getRepo()  { return repo; }
	PlayList& getPlaylist() { return playList; }

	// Adds a movie with the given data to the song repository.
	void addMovieToRepository(const std::string& genre, const std::string& title, int year, int likes, const std::string& source);
    
	/*
		Adds a given movie to the current playlist.
		Input: movie - Movie, the movie must belong to the repository.
		Output: the movie is added to the playlist.
	*/
	void addMovieToPlaylist(const Movie& movie);

	// Adds all the movies from the repository, that have the given genre, to the current playlist.
	void addAllMoviesByGenreToPlaylist(const std::string& genre);

	void startPlaylist();
	void nextMoviePlaylist();
	
};

