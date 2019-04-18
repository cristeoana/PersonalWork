#include "Song.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie(): title(""), genre(""), year(), likes(), source("") {}

Movie::Movie(const std::string& genre, const std::string& title, const int year, const int likes, const std::string& source)
{
	this->genre = genre;
	this->title = title;
	this->year = year;
	this->likes = likes;
	this->source = source;
}

void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool Movie::operator==(Movie m)
{
	return this->genre == m.getGenre() && this->likes == m.getLikes() && this->title == m.getTitle() && this->year == m.getYear();
}
