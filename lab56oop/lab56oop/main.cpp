#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>
#include "Tests.h"

using namespace std;

int main()
{
	system("color f4");
	//Tests::testAll();
	{
		Repository repo{};
		Movie m1{ "Comedy", "The Mask", 1994, 1000000, "https://www.youtube.com/watch?v=hOqVRwGVUkA" };
		Movie m2{ "Comedy", "God for a day", 2003, 200000, "https://www.youtube.com/watch?v=fe-luzrqWSk" };
		Movie m3{ "Comedy", "Scary movie", 2013, 100000, "https://www.youtube.com/watch?v=fbfRP5vM7xU" };
		Movie m4{ "Fantasy", "Harry Potter and the Philosopher's Stone", 2001, 300000000, "https://www.youtube.com/watch?v=PbdM1db3JbY" };
		Movie m5{ "Fantasy", "Harry Potter and the Chamber of Secrets", 2002, 4000000, "https://www.youtube.com/watch?v=uU-ET1FAv3Y" };
		Movie m6{ "Fantasy", "Harry Potter and the Prisoner of Azkaban", 2004, 5000000, "https://www.youtube.com/watch?v=lAxgztbYDbs" };
		Movie m7{ "Fantasy", "Harry Potter and the Goblet of Fire", 2005, 2000000, "https://www.youtube.com/watch?v=PFWAOnvMd1Q" };
		Movie m8{ "Fantasy", "Harry Potter and the Order of the Phoenix",2007,900000, "https://www.youtube.com/watch?v=y6ZW7KXaXYk" };
		Movie m9{ "Fantasy", "Harry Potter and the Half-Blood Prince",2009 , 5000000, "https://www.youtube.com/watch?v=JYLdTuL9Wjw" };
		Movie m10{ "Fantasy", "Harry Potter and the Deathly Hallows",2010 , 8000000, "https://www.youtube.com/watch?v=_EC2tmFVNNE" };
		repo.addMovie(m1);
		repo.addMovie(m2);
		repo.addMovie(m3);
		repo.addMovie(m4);
		repo.addMovie(m5);
		repo.addMovie(m6);
		repo.addMovie(m7);
		repo.addMovie(m8);
		repo.addMovie(m9);
		repo.addMovie(m10);


		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.run();
		//repo.getMovies().deletee();
		//repo.~Repository();
		//ctrl.~Controller();
		//ui.~UI();
	}

	//_CrtDumpMemoryLeaks();
	return 0;
}