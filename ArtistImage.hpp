// Eli Simmonds
// Project 3
// ArtistImage.hpp

#ifndef ARTISTIMG_H
#define ARTISTIMG_H

#include <string>
#include <iostream>

#include "JSONDataObject.hpp"

extern int artImageRefCount;

class ArtistImage: public JSONDataObject {
public:
	ArtistImage();
	~ArtistImage();
	
	int height();
	int width();
	int artistID();

	std::string uri();
	std::string type();

	void print();
	std::string htmlString();
private:
	int _height, _width, _artistID;
	std::string _uri, _type;

	bool cachedHeight, cachedWidth, cachedArtistID, cachedURI, cachedType;
};

#endif
