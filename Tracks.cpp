// ELi Simmonds
// Project 3
// Tracks.cpp

#include "Tracks.hpp"

Tracks::Tracks() {

}

Tracks::~Tracks() {
// use base class destructor
}

int Tracks::numTracks() {
// return number of objects in Tracks object
	return listOfTracks()->size();
}

void Tracks::addTrack(Track *track) {
// adds a track ptr to the vector
	_listOfDataObjects->push_back(track);
}

Tracks *Tracks::tracksWithAlbumID(int aID) {
// gets each track from an album and then erases it from the vector
// since it will be added to a new Tracks instance
	Tracks *albTracks = new Tracks();
	for (int i = 0; i < numTracks(); i++) {
		if (listOfTracks()->at(i)->album_ID() == aID) {
			albTracks->addTrack(listOfTracks()->at(i));
			listOfTracks()->erase(listOfTracks()->begin() + i);
			i--;
		}
	}
	return albTracks;
}

void Tracks::loadTracksFromFile(std::string fileName) {
	std::fstream track_input;
	track_input.open(fileName);
	if (!track_input.is_open()) {
		exit(5); }
	parseJSONArray(track_input);
	track_input.close();
}

std::string Tracks::htmlString() {
// creates master HTML of tracks for an album
	std::string html;
	for (int i = 0; i < numTracks(); i++) {
		html += listOfTracks()->at(i)->htmlString();
	}
	return html;	
}

void Tracks::runAsserts() {
// testing purposes only
}
