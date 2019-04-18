# PersonalWork

# lab56oop
So many movies, so little time… To make sure you do not miss any good movies, you absolutely need a
software application to help you manage your films and create watch lists. The application can be used
in two modes: administrator and user. When the application is started, it will offer the option to choose
the mode.
Administrator mode: The application will have a database, which holds all the movies. You must be
able to update the database, meaning: add a new movie, delete a movie and update the information of
a movie. Each Movie has a title, a genre, a year of release, a number of likes and a trailer. The trailer is
memorised as a link towards an online resource. The administrators will also have the option to see all
the movies in the database.
User mode: A user can create a watch list with the movies that he wants to watch. The application will
allow the user to:
a. See the movies in the database having a given genre (if the genre is empty, see all the
movies), one by one. When the user chooses this option, the data of the first movie (title,
genre, year of release, number of likes) is displayed and the trailer is played in the browser.
b. If the user likes the trailer, he/she can choose to add the movie to his/her watch list.
c. If the trailer is not satisfactory, the user can choose not to add the movie to the watch list
and to continue to the next. In this case, the information corresponding to the next movie is
shown and the user is again offered the possibility to add it to the watch list. This can
continue as long as the user wants, as when arriving to the end of the list of movies with the
given genre, if the user chooses next, the application will again show the first movie.
d. Delete a movie from the watch list, after the user watched the movie. When deleting a
movie from the watch list, the user can also rate the movie (with a like), and in this case, the
likes of the movie in the repository will be increased.
e. See the watch list.

# lab1db
Create a C# Windows Forms application that uses ADO.NET to interact with the database you developed in the 1st semester. The application must contain a form allowing the user to manipulate data in 2 tables that are in a 1:n relationship (parent table and child table). The application must provide the following functionalities:
-display all the records in the parent table;
-when selecting a record in the parent table:
---display all the corresponding records in the child table;
---add new child records in the child table;
---remove / update child records in the child table.
You must use the DataSet and SqlDataAdapter classes. You are free to use any controls on the form.

Transform your first lab to dynamically create the master-detail windows form. The form caption, stored procedures / queries used to access and manipulate data will be set in a configuration file.
You must prepare at least two different scenarios handling data from two different 1:n relationships.
The form should be generic enough such that switching between scenarios (i.e., updating the application to handle data from another 1:n relationship) comes down to updating the configuration file.
How you define and interpret the configuration file is entirely up to you.
