#include "UI.h"
#include "PlayList.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage movie repository."<<endl;
	cout << "2 - Manage playlist." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Remove a movie" << endl;
	cout << "\t 4 - Update a movie" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printPlayListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Add movies by genre." << endl;
	cout << "\t 3 - Display movies from playlist." << endl;
	cout << "\t 4 - Display movies by genre." << endl;
	cout << "\t 5 - Delete a movie from playlist." << endl;
	cout << "\t 6 - Play." << endl;
	cout << "\t 7 - Next." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addMovieToRepo()
{
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	
	cout << "Enter the year: " << endl;
	int year;
	cin >> year;
	cin.ignore();
	cout << "Enter the number of likes";
	int likes;
	cin >> likes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);
	
	this->ctrl.addMovieToRepository(genre, title, year, likes, link);
}

void UI::displayAllMoviesRepo()
{
	vector<Movie> movies = this->ctrl.getRepo().getMovies();
	if (movies.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (int i = 0; i < movies.size(); i++)
	{
		Movie m = movies[i];		
		cout << m.getGenre() << " - " << m.getTitle() << "; " << m.getYear() << ";" << m.getLikes() << endl;
	}
}

void UI::displayAllPlayList()
{
	vector<Movie> movies = this->ctrl.getPlaylist().getMovies();
	if (movies.size() == 0)
	{
		cout << "There are no movies in the playlist." << endl;
		//return;
	}
	else
		for (int i = 0; i < movies.size(); i++)
		{
			Movie m = movies[i];		
			cout << m.getGenre() << " - " << m.getTitle() << "; " << m.getYear() << ";" << m.getLikes() << endl;
		}
}


void UI::displayMoviesByGenre(const std::string& genre)
{
	vector<Movie> movies = this->ctrl.getRepo().getMovies();
	if (movies.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}
	int c = 0;
	for (int i = 0; i < movies.size(); i++)
	{
		Movie m = movies[i];
		string g = m.getGenre();
		
		if (g == genre)
		{
			cout << m.getGenre() << " - " << m.getTitle() << "; " << m.getYear() << ";" << m.getLikes() << endl;
			c++;

		}		
	}
	if (c == 0)
	{
		this->displayAllMoviesRepo();
	}
	for (int i = 0; i < movies.size(); i++)
	{
		Movie m = movies[i];
		//m.play();
		
		//PlayList playlist;
		
		string g = m.getGenre();
		if (g == genre)
		{
			cout << m.getGenre() << " - " << m.getTitle() << "; " << m.getYear() << ";" << m.getLikes() << endl;
			movies[i].play();
			string answer;
			cout << "Do you like the trailer and do you want add it in the playlist? ";
			getline(cin, answer);
			if (answer == "yes")
			{
				if(this->ctrl.getPlaylist().findByGenreAndTitle(m.getGenre(), m.getTitle()).getGenre()=="")
					this->ctrl.addMovieToPlaylist(m);
				//this->addMovieToPlaylist();
			}

		
		}
		
	}
}


void UI::addMovieToPlaylist()
{
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	
	// search for the song in the repository
	Movie m = this->ctrl.getRepo().findByGenreAndTitle(genre, title);
	if (m.getGenre() == "" && m.getTitle() == "")
	{
		cout << "There are no movies with the given data in the repository. Nothing will be added to the playlist." << endl;
		return;
	}

	this->ctrl.addMovieToPlaylist(m);
}



void UI::addAllMoviesByGenreToPlaylist()
{
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);

	this->ctrl.addAllMoviesByGenreToPlaylist(genre);
}

void UI::delMovie()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	Movie m = this->ctrl.getPlaylist().findByGenreAndTitle(genre, title);
	if (m.getTitle().compare("") == 0)
		cout << "Movie not found";
	else
	{
		for (std::vector<Movie>::iterator it = this->ctrl.getPlaylist().getMovies().begin(); it != this->ctrl.getPlaylist().getMovies().end(); ++it)
		{
			if (m.getTitle() == (*it).getTitle())
				this->ctrl.getPlaylist().getMovies().erase(it);

		}
	}
}



void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{0};
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				Movie m;
				string genre;
				string title; string title2;
				//string genre;
				int year; int likes;
				string link;

				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					this->displayAllMoviesRepo();
					break;
				
				case 3:
					cout << "Give the title: ";
					getline(cin, title);
					m = this->ctrl.getRepo().getByTitle(title);
					this->ctrl.getRepo().deleteMovie(m);
					break;
				case 4:
					Movie m1;
					cout << "Give the title: ";
					getline(cin, title);
					m = this->ctrl.getRepo().getByTitle(title);

					cout << "Enter the genre: ";
					getline(cin, genre);
					cout << "Enter the title2: ";
					getline(cin, title2);

					cout << "Enter the year: " << endl;
					cin >> year;
					cin.ignore();
					cout << "Enter the number of likes";
					cin >> likes;
					cin.ignore();
					cout << "Youtube link: ";
					getline(cin, link);
					
					this->ctrl.addMovieToRepository(genre, title2, year, likes, link);
					m1 = this->ctrl.getRepo().getByTitle(title2);

					this->ctrl.getRepo().updateMovie(m, m1);

					break;

				}
			}			
		}

		// playlist management
		if (command == 2)
		{
			while (true)
			{
				UI::printPlayListMenu();
				int commandPlaylist{0};
				cout << "Input the command: ";
				cin >> commandPlaylist;
				cin.ignore();
				string genre;
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist)
				{
				case 1:
					this->addMovieToPlaylist();
					break;
				case 2:
					this->addAllMoviesByGenreToPlaylist();
					break;
				case 3:
					this->displayAllPlayList();
					break;
				case 4:
					cout << "Enter the movie genre: ";
					getline(cin, genre);
					this->displayMoviesByGenre(genre);
					break;
				case 5:
					this->delMovie();
					this->displayAllPlayList();
					break;

				case 6:
				{
					if (this->ctrl.getPlaylist().isEmpty())
					{
						cout << "Nothing to play, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.startPlaylist();
					Movie m = this->ctrl.getPlaylist().getCurrentMovie();
					cout << "Now playing: " << m.getGenre() << " - " << m.getTitle() << endl;
					break;
				}
				case 7:
				{
					if (this->ctrl.getPlaylist().isEmpty())
					{
						cout << "Nothing to play, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.nextMoviePlaylist();
					Movie m = this->ctrl.getPlaylist().getCurrentMovie();
					cout << "Now playing: " << m.getGenre() << " - " << m.getTitle() << endl;
					break;
				}
				}
			}
		}
	}
}