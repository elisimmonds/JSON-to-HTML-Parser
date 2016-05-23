// Eli Simmonds
// Project 3
// README.txt

This project is working through main_JSON.cpp My main function has the functionality built in for 
creating the HTML. All other functions are from the classes.

Since I delete pointers and have all warnings turned on in my makefile
there are compilation warnings. Otherwise it works fine.

Due to the images being different sizes as your sample ones my layout is different
on the individual albums. It has all the same info. 

Tracks::setTracksForAlbum() erases the track instance from the main vector
Individual HTML files have the title at the top. 

Testing
It is tested by creating one of each type of object calling the readFromFile function

I wasn't sure if you wanted us to print or not so I commented out the print
The line that prints is ar->print() in the main file.
It is line 56

the directory with all my HTML is html_albums
the my main file is artists.html
you run this project by typing make
you delete all the nonsense by typing make clean
