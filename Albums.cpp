// Eli Simmonds
// Project 3
// Albums.cpp

#include "Albums.hpp"
#include "AlbumImages.hpp"
#include "Artists.hpp"
//#include "Tracks.hpp"
//#include "Track.hpp"

Albums::Albums() {

}

Albums::~Albums() {
// use baseclass destructor
}

int Albums::numAlbums() {
// returns number of elements in the object
	return _listOfDataObjects->size();
}

void Albums::addAlbum(Album *album) {
// adds and album ptr to the vector
	listOfAlbums()->push_back(album);
}

Album *Albums::albumWithID(unsigned int aID) {
// finds an album given an album id
// by iterating through the vector
	for ( unsigned int i = 0; i < listOfAlbums()->size(); i++) {
		if ( listOfAlbums()->at(i)->albumID() == aID)
			return listOfAlbums()->at(i);
	}
}

void Albums::setTracksForAlbums(Tracks *tracks) {
// sets the tracks for every album by using
// the tracksWithAlbumID function and album
// setTracks function
	for (int i = 0; i < numAlbums(); i++) {
                auto album = listOfAlbums()->at(i);
                auto tracksForAlbum = tracks->tracksWithAlbumID(album->albumID());
		album->setTracks(tracksForAlbum);
	}

}

Albums *Albums::albumsForArtist(unsigned int aID) {
// finds the albums for each artist by being
// passed an artist ID
	Albums *artAlbums = new Albums();
	for (int i = 0; i < numAlbums(); i++) {
		if (listOfAlbums()->at(i)->artistID() == aID) {
			artAlbums->addAlbum(listOfAlbums()->at(i));			
		}
	}
	return artAlbums;
}

void Albums::setAlbumsArtist(Artists *artists) {
// sets the _artist variable for each album
	int artID = 0;
	for (int i = 0; i < numAlbums(); i++) {
		artID = listOfAlbums()->at(i)->artistID();
		listOfAlbums()->at(i)->setArtist(artists->artistWithID(artID));
	}
}


void Albums::setImagesForAlbums(AlbumImages *images) {
// sets the images for each album
	Album *alb;
	for (int i = 0; i < images->numImages(); i++) { 
		alb = albumWithID(images->listOfAlbumImages()->at(i)->albumID());
		alb->setImage(images->listOfAlbumImages()->at(i));
	}
}

void Albums::loadAlbumsFromFile(std::string fileName) {
	std::fstream albumStream;
	albumStream.open(fileName);
	if (!albumStream.is_open())
		exit(16);
	parseJSONArray(albumStream);
	albumStream.close();
}

std::string Albums::htmlString() {
// creates the string of albums for each artist
// that will go on the master webpage
	std::string html;
	for (int i = 0; i < numAlbums(); i++) {
		html += listOfAlbums()->at(i)->htmlString();
	}
	return html;
}

void Albums::runAsserts() {
// just for testing
}

