// Eli Simmonds
// Project 3
// Artist.hpp

#ifndef ARTIST_H
#define ARTIST_H

#include "JSONDataObject.hpp"
#include "ArtistImage.hpp"

#include <string>

class Albums;

extern int artRefCount;

class Artist: public JSONDataObject {
public:
	Artist();
	~Artist();

	std::string profile();
	std::string artistName();
	std::string realName();
	std::string numImages();  // since it's a string in the JSON file
	unsigned artistID();

	void print();
	std::string htmlString();

	void setAlbums(Albums *albums) { _albums = albums; }
	Albums *albums() { return _albums; }
	ArtistImage *&primaryImage()       { return _primaryImage;   }
	ArtistImage *&secondaryImage()     { return _secondaryImage; }

private:
	std::string _name, _realName, _profile, _numImages;
	unsigned _artistID;
	bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

	// the following 3 variables are new to this project.
	ArtistImage *_primaryImage, *_secondaryImage;
	Albums *_albums;
};

#endif
