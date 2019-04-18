#include "PlayList.h"


PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::add(const Movie& movie)
{
	this->movies.push_back(movie);
}

Movie PlayList::getCurrentMovie()
{
	if (this->current == this->movies.size())
		this->current = 0;
	return this->movies[this->current];
}

void PlayList::play()
{
	if (this->movies.size() == 0)
		return;
	this->current = 0;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

void PlayList::next()
{
	if (this->movies.size() == 0)
		return;
	this->current++;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

bool PlayList::isEmpty()
{
	return this->movies.size() == 0;
}

Movie PlayList::findByGenreAndTitle(const std::string& genre, const std::string& title)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		Movie m = movies[i];
		if (m.getGenre() == genre && m.getTitle() == title)
			return m;
	}

	return Movie{};
}