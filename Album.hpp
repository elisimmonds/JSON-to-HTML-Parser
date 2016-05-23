// Eli Simmonds
// Project 3
// Album.hpp

#ifndef ALBUM_H
#define ALBUM_H

//#include "Tracks.hpp"
//#include "Artist.hpp"
#include "AlbumImage.hpp"
#include "JSONDataObject.hpp"

#include <string>

class Tracks;
class Artist;

extern int albumRefCount;

class Album: public JSONDataObject {
public:
	Album();
	~Album();

	std::string title();
	std::string genres();
	unsigned albumID();
	unsigned artistID();
	unsigned numImages();
	unsigned numTracks();
	std::string year();

	void setTracks(Tracks *tracks);
	void setArtist(Artist *artist);
	void setImage(AlbumImage *image);
	Artist *artist() { return _artist; }
	Tracks *tracks()  { return _tracks; }

	AlbumImage *&primaryImage() { return _primaryAlbumImage;   }
	AlbumImage *&secondaryImage()  { return _secondaryAlbumImage; }

	void print();
	std::string htmlString();
private:
	std::string _title, _year, _genres;
	unsigned _numTracks, _artistID, _numImages, _albumID;
	bool cachedTitle, cachedYear, cachedGenres, cachedNumTracks,
		cachedArtistID, cachedNumImages, cachedAlbumID;
	Tracks *_tracks;
	Artist *_artist;
	AlbumImage *_primaryAlbumImage, *_secondaryAlbumImage;
};

#endif
