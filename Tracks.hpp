// Eli Simmonds
// Project 3
// Tracks.hpp

#ifndef TRACKS_H
#define TRACKS_H

#include "JSONArray.hpp"
#include "JSONDataObject.hpp"
#include "Track.hpp"


class Tracks: public JSONArray {
public:
	Tracks();
	~Tracks();
	
	int numTracks();
	void addTrack(Track *track);
	Tracks *tracksWithAlbumID(int aID);
	void loadTracksFromFile(std::string fileName);
	std::string htmlString();
	JSONDataObject *jsonObjectNode() { return new Track(); }
	std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
	void runAsserts(); // used for checking the integrity of this class.

};

#endif
