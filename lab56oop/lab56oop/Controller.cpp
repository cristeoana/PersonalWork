#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

void Controller::addMovieToRepository(const std::string& genre, const std::string& title, int year, int likes, const std::string& source)
{
	Movie m{ genre, title, year, likes, source };
	this->repo.addMovie(m);
}

void Controller::addMovieToPlaylist(const Movie& movie)
{
	this->playList.add(movie);
}

void Controller::addAllMoviesByGenreToPlaylist(const std::string& genre)
{
	// get all the movies from the repository
	std::vector<Movie> movies = this->repo.getMovies();
	for (int i = 0; i < movies.size(); i++)
	{
		Movie s = movies[i];
		if (s.getGenre().compare(genre)==0)
			this->playList.add(s);
	}
	/*
	for (DynamicVector<Movie>::iterator it = songs.begin(); it != songs.end(); it++)
	{
		if (it->getArtist() == artist)
			this->playList.add(*it);
	}*/

	//int moviesByGenre = static_cast<int>(std::count_if(movies.begin(), movies.end(), [genre](Movie m) {return m.getGenre() == genre; }));
	/*DynamicVector<Movie> result, source = this->getRepo().getMovies();
	result.GetSize(moviesByGenre);
	auto it=std::copy_if(source, source.GetSize(), result, [genre](Movie s) {return s.getGenre() == genre; });
	for (auto it = result.begin(); it != result.end(); it++)
		this->playList.add(*it);*/
	return;
}

void Controller::startPlaylist()
{
	this->playList.play();
}

void Controller::nextMoviePlaylist()
{
	this->playList.next();
}

