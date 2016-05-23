// Eli Simmonds
// Project 3
// Artists.cpp

#include "Artists.hpp"
#include "Albums.hpp"
#include "Album.hpp"
#include "ArtistImages.hpp"

Artists::Artists() {

}

Artists::~Artists() {
// use the base class destructor
}

int Artists::numArtists() {
// returns number of objects
	return _listOfDataObjects->size();
}

void Artists::addArtist(Artist *artist) {
// adds an object ptr to vector
	_listOfDataObjects->push_back(artist);	
}

Artist *Artists::artistWithID(unsigned int aID) {
// finds an artist given an ID and returns it
	Artist *artist;
	for( unsigned int i = 0; i < listOfArtists()->size(); i++){
		if( listOfArtists()->at(i)->artistID() == aID) {
			artist = listOfArtists()->at(i);
			return artist;
		}
	}
	return artist;
}

void Artists::loadArtistsFromFile(std::string fileName) {
	std::fstream artStream;
	artStream.open(fileName);
	if (!artStream.is_open()) { 
		exit(7); }
	parseJSONArray(artStream);
	artStream.close();
}

std::string Artists::htmlString() {
// creates master html file
	std::string html;
	for (int i = 0; i < numArtists(); i++) {
		html += listOfArtists()->at(i)->htmlString();
	}
	return html;
}

void Artists::setAlbumsForArtists(Albums *albums) {
// sets albums for every single artust ysubg the
// albumsForArtist function.
	for (int i = 0; i < numArtists(); i++) {
		auto artist = listOfArtists()->at(i);
		auto albumsForArtist = albums->albumsForArtist(artist->artistID());
		artist->setAlbums(albumsForArtist);
	}
}

void Artists::setImagesForArtists(ArtistImages *images) {
// sets an image for each artist and finds out if it is a 
// secondary or primary image.
	ArtistImage *img;
	Artist *artist;
	for (int i = 0; i < images->numImages(); i++) {
		artist = artistWithID(images->listOfArtistImages()->at(i)->artistID());
		img = images->listOfArtistImages()->at(i);
		if (img->type() == "primary")
			artist->primaryImage() = img;
		else if (img->type() == "secondary")
			artist->secondaryImage() = img;
	}
}

void Artists::runAsserts() {
// just for testing
}
