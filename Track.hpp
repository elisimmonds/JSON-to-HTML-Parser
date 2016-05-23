// Eli Simmonds
// Project 3
// Track.hpp

#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <cstring>

#include "JSONDataObject.hpp"

extern int trackRefCount;

class Track: public JSONDataObject {
public:
	Track();
	~Track();

	std::string title();
	std::string artist_name();
	std::string album_name();
	int album_ID();
	std::string duration();
	std::string position();

	void print();
	std::string htmlString();

private:
	std::string _title, _artistName, _albumName, _duration, _position;
	int _albumID;
	bool cachedTitle, cachedArtistName, cachedAlbumName, cachedDuration,
		cachedAlbumID, cachedPosition;


};

#endif
