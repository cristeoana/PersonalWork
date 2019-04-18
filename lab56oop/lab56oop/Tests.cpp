#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "PlayList.h"
#include "Controller.h"
#include "Tests.h"

void Tests::testMovie()
{
	Movie s{ "Comedy", "God for a day", 2003, 200000, "https://www.youtube.com/watch?v=V9IhMHPInVk" };
	assert(s.getGenre() == "Comedy");
	assert(s.getTitle() == "God for a day");
	assert(s.getSource() == "https://www.youtube.com/watch?v=V9IhMHPInVk");
	assert(s.getYear() == 2003);
	assert(s.getLikes() == 200000);
}

void Tests::testDynamicVector()
{
	DynamicVector<int> v1;
	v1.AddTrailer(10);
	v1.AddTrailer(20);
	assert(v1.GetSize() == 2);
	assert(v1[1] == 20);
	v1.AddTrailer(30);
	assert(v1.GetSize() == 3);

	DynamicVector<int> v2 = v1;
	assert(v2.GetSize() == 3);

	DynamicVector<int> v3;
	v3 = v1;
	assert(v3[0] == 10);

}

void Tests::testRepository()
{
	Repository repo{};
	Movie s{ "Comedy", "God for a day", 2003, 200000, "https://www.youtube.com/watch?v=V9IhMHPInVk" };
	repo.addMovie(s);
	Movie res = repo.findByGenreAndTitle("Comedy", "God for a day");
	assert(res.getTitle() == s.getTitle() && res.getGenre() == s.getGenre());
	res = repo.findByGenreAndTitle("Comedy", "");
	assert(res.getGenre() == "");

	std::vector<Movie> movies = repo.getMovies();
	assert(movies.size() == 1);
}

void Tests::testPlaylist()
{
	PlayList playList{};
	Movie s1{ "Comedy", "God for a day", 2003, 200000, "https://www.youtube.com/watch?v=V9IhMHPInVk" };
	Movie s2{ "Fantasy", "Harry Potter and the Deathly Hallows", 2010, 8000000, "https://www.youtube.com/watch?v=_EC2tmFVNNE" };
	playList.add(s1);
	playList.add(s2);

	assert(playList.isEmpty() == false);

}

void Tests::testController()
{
	Repository repo{};
	Controller ctrl{ repo };
	ctrl.addMovieToRepository("Comedy", "The Mask", 1994, 1000000, "https://www.youtube.com/watch?v=hOqVRwGVUkA");
	ctrl.addMovieToRepository("Fantasy", "Harry Potter and the Deathly Hallows", 2010, 8000000, "https://www.youtube.com/watch?v=_EC2tmFVNNE");
	Movie m{ "Comedy", "God for a day", 2003, 200000, "https://www.youtube.com/watch?v=V9IhMHPInVk" };
	ctrl.addMovieToPlaylist(m);
	ctrl.addAllMoviesByGenreToPlaylist("Comedy");

	assert(ctrl.getRepo().getMovies().size() == 2);
	
	PlayList list = ctrl.getPlaylist();
	assert(list.isEmpty() == false);
	assert(list.getCurrentMovie().getGenre() == "Comedy");

	ctrl.startPlaylist();
	ctrl.nextMoviePlaylist();	
}

void Tests::testAll()
{
	testMovie();
	testDynamicVector();
	testRepository();
	testPlaylist();
	testController();
}
