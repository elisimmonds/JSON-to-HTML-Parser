// Eli Simmonds
// Project 3
// main_JSON.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <ostream>

#include "JSONDataObject.hpp"
#include "JSONDataItem.hpp"
#include "JSONArray.hpp"
#include "Tracks.hpp"
#include "Artists.hpp"
#include "Albums.hpp"
#include "ArtistImages.hpp"
#include "AlbumImages.hpp"

int main() {
	// load the tracks
	Tracks *tr = new Tracks();
	std::string fileName = "JSON_files/tracks.json";
	tr->loadTracksFromFile(fileName);

	// load the artists
	Artists *ar = new Artists();
	std::string artFile = "JSON_files/artists.json";
	ar->loadArtistsFromFile(artFile);
	
	// load the albums
	Albums *al = new Albums();
	std::string albFile = "JSON_files/albums.json";
	al->loadAlbumsFromFile(albFile);

	al->setTracksForAlbums(tr); // set the tracks for each album
	ar->setAlbumsForArtists(al); // set the albums for each artist
	al->setAlbumsArtist(ar); // set the artist for each album

	// load artist images
	ArtistImages *ai = new ArtistImages();
	std::string artImFile = "JSON_files/artistImages.json";
	ai->loadImagesFromFile(artImFile);

	// load album images
	AlbumImages *ali = new AlbumImages();
	std::string albImFile = "JSON_files/albumImages.json";
	ali->loadImagesFromFile(albImFile);
	al->setImagesForAlbums(ali);  // use all album images to set the images for each album
	ar->setImagesForArtists(ai);  // set the images for each artist


//	ar->print();


	std::fstream artistFile ("HTML_templates/artist_template.html"); // open the track file
        std::stringstream artBuffer; // create a stream to get the file data
        artBuffer << artistFile.rdbuf(); // read the data from the file into the stream  
        std::string artist_data = artBuffer.str();  // taking data from the stream and making it a string
        std::string artist_html = ar->htmlString();


	// this creates the artists main page.
        int art_idx = artist_data.find("<\% artist_details \%>");  // find the chars track to replace
        int title_idx = artist_data.find("<\% artist_name \%>");  // find the chars track to replace
        std::string artistOutput = artist_data.replace(art_idx, 20, artist_html); // 
	std::string artString = "Artists";	// title for the page
        artistOutput = artist_data.replace(title_idx, 17, artString); // replace the tempalte info
        std::ofstream artistHTML;	// create ofstream
        artistHTML.open("artists.html");	// open the ofstream with this name
        if (!artistHTML.is_open())		// check if open.
        	std::cout << "error opening artist.html" << std::endl;
        artistHTML << artistOutput;		// slap the html in there
	artistHTML.close();			// close stream
	
	// This section creates the individual album HTML pages.
	std::fstream albumFile ("HTML_templates/album_template.html"); // use the template
	std::stringstream albBuffer;	// create a string stream to find the string
	std::ofstream albumHTML;	// create ofstream to open a file for html
	albBuffer << albumFile.rdbuf();	// read in the template
	std::string album_data = albBuffer.str();	// set the data to a string
        title_idx = album_data.find("<\% album_name \%>");  // find the chars to replace
	int alb_idx = album_data.find("<\% album_details \%>"); // fimd title to replace
	for (int i = 0; i < al->numAlbums(); i++) {
		std::string albumTitle = al->listOfAlbums()->at(i)->title();	// set current title
		std::string album_html = al->listOfAlbums()->at(i)->htmlString();	// set current html
		std::string albumOutput = album_data.replace(alb_idx, 20, album_html);	//replace with html
        	albumOutput = album_data.replace(title_idx, 16, albumTitle); // replace with title
		std::string fileName = "./html_albums/";	// specify where to drop the file.
		fileName += std::to_string(al->listOfAlbums()->at(i)->albumID());	// concatinate with title
		fileName += ".html";							// add extrension
		albumHTML.open(fileName);		// open the new filename
		albumHTML << albumOutput;		// slap the html in there
		albumHTML.close();			// close the stream
		album_data = albBuffer.str();		// reset the album data.
	}


/* for testing purposes only. Tests the destuctors functionality
	std::cout << "trackCount: " << trackRefCount << std::endl;
	std::cout << "albumCount: " << albumRefCount << std::endl;
	std::cout << "artistCount: " << artRefCount << std::endl;
	std::cout << "artistImageCount: " << artImageRefCount << std::endl;
	std::cout << "albumImageCount: " << albImageRefCount << std::endl;

	std::cout << "Deleting artists" << std::endl;
	delete ar;

	std::cout << "trackCount: " << trackRefCount << std::endl;
	std::cout << "albumCount: " << albumRefCount << std::endl;
	std::cout << "artistCount: " << artRefCount << std::endl;
	std::cout << "artistImageCount: " << artImageRefCount << std::endl;
	std::cout << "albumImageCount: " << albImageRefCount << std::endl;
*/

	return 0;
};
