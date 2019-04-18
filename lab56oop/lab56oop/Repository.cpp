#include "Repository.h"
#include <string>

using namespace std;

void Repository::addMovie(const Movie& m)
{
	this->movies.push_back(m);
}

void Repository::deleteMovie(Movie& m)
{
	for (std::vector<Movie>::iterator it = movies.begin(); it != movies.end(); ++it)
	{
		if (m.getTitle() == (*it).getTitle())
		{
			movies.erase(it);
			return;
		}

	}
}

void Repository::updateMovie(const Movie& m1, const Movie& m2)
{
	for (std::vector<Movie>::iterator it = movies.begin(); it != movies.end(); ++it)
	{
		if (m1.getTitle() == (*it).getTitle())
		{
			movies.erase(it);
			movies.insert(it, m2);
		}

	}
}



Movie Repository::findByGenreAndTitle(const std::string& genre, const std::string& title)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		Movie m = movies[i];
		if (m.getGenre() == genre && m.getTitle() == title)
			return m;
	}

	return Movie{};
}

Movie Repository::getByTitle(std::string& title)
{
	for (std::vector<Movie>::iterator it = movies.begin(); it != movies.end(); ++it)
		{
			//find partial string
			if ((*it).getTitle() == title)
			{
				return *it;
			}
		}
	return Movie{};
}