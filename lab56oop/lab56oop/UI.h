#pragma once
#include "Controller.h"


class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printPlayListMenu();

	void addMovieToRepo();
	void displayAllMoviesRepo();
	void displayMoviesByGenre(const std::string& genre);
	void addMovieToPlaylist();
	void addAllMoviesByGenreToPlaylist();
	void displayAllPlayList();

	
	void delMovie();

	//void deleteMovieRepo();
};

