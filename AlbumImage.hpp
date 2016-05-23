// Eli Simmonds
// Project 3
// AlbumImage.hpp

#ifndef ALBUMIMG_H
#define ALBUMIMG_H

#include "JSONDataObject.hpp"

#include <string>
#include <iostream>

extern int albImageRefCount;

class AlbumImage: public JSONDataObject {
public:
	AlbumImage();
	~AlbumImage();
	
	int height();
	int width();
	int albumID();
	std::string type();
	std::string uri();
	
	std::string htmlString();

	void print();

private:
	int _height, _width, _albumID;
	std::string _type, _uri;
	bool cachedHeight, cachedWidth, cachedAlbumID,
		cachedType, cachedURI;
};

#endif
