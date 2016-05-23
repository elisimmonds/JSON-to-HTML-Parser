// Eli Simmonds
// Project 3
// Track.cpp

#include "Track.hpp"

int trackRefCount = 0;

Track::Track() {
// initializes all private variables
	trackRefCount++;
	_title = _artistName = _albumName = _duration = _position = "";
	_albumID = 0;
	cachedTitle = cachedArtistName = cachedAlbumName = 
		cachedDuration = cachedAlbumID = cachedPosition = false;
}

Track::~Track() {
// doesn't do anything except decrement the counter I created
// to track memory allocation and deallocation
	trackRefCount--;	
}

std::string Track::title() {
	if (cachedTitle)
		return _title; 
	cachedTitle = true;
	return _title = valueForStringAttribute("title");
}
std::string Track::artist_name() {
	if (cachedArtistName)
		return _artistName; 
	cachedArtistName = true;
	return _artistName = valueForStringAttribute("artist_name");
}
std::string Track::album_name() {
	if (cachedAlbumName)
		return _albumName;
	cachedAlbumName = true;
	return _albumName = valueForStringAttribute("album_name"); 
}
std::string Track::duration() {
	if (cachedDuration)
		return _duration;
	cachedDuration = true;
	return _duration = valueForStringAttribute("duration");
}
int Track::album_ID() {
	if (cachedAlbumID)
		return _albumID;
	cachedAlbumID = true;
	return _albumID = valueForIntegerAttribute("album_id"); 
}
std::string Track::position() {
	if (cachedPosition)
		return _position;
	cachedPosition = true;
	return _position = valueForStringAttribute("position"); 
}
void Track::print() {
// prints all track variables.
	std::cout << "Title: " << title() << "\n"
		<< "Artist Name: " << artist_name() << "\n"
		<< "Album Name: " << album_name() << "\n"
		<< "Duration: " << duration() << "\n"
		<< "Album_ID: " << album_ID() << "\n"
		<< "Position: " << position() << std::endl;	
}

std::string Track::htmlString() {
// creates html for each track instance.
// only needs the trackname and duraction.
	std::string html;

	html += "<tr class=";
	html += '"';
	html += "tracks";
	html += '"';
	html += "><td class=";
	html += '"';
	html += "trackName";
	html += '"';
	html += ">";
	html += title();
	html += "</td><td>";
	html += duration();
	html += "</td></tr>";
	return html;
}
