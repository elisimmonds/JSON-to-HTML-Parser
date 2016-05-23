// Eli Simmonds
// Project 3
// ArtistImage.cpp

#include "ArtistImage.hpp"

int artImageRefCount = 0;

ArtistImage::ArtistImage() {
// initializes all private variables
	artImageRefCount++;
	_height = _width = _artistID = 0;
	_uri = _type = " ";
	cachedHeight = cachedWidth = cachedArtistID
		 = cachedURI = cachedType = false;
}

ArtistImage::~ArtistImage() {
// decrements the counter to track memory allocation
	artImageRefCount--;

}

int ArtistImage::height() {
	if (cachedHeight)
		return _height;
	cachedHeight = true;
	return _height = valueForIntegerAttribute("height");
}

int ArtistImage::width() {
	if (cachedWidth)
		return _width;
	cachedWidth = true;
	return _width = valueForIntegerAttribute("width");
}

int ArtistImage::artistID() {
	if (cachedArtistID)
		return _artistID;
	cachedArtistID = true;
	return _artistID = valueForIntegerAttribute("artist_id");
}

std::string ArtistImage::uri() {
	if (cachedURI)
		return _uri;
	cachedURI = true;
	return _uri = valueForStringAttribute("uri");
}

std::string ArtistImage::type() {
	if (cachedType)
		return _type;
	cachedType = true;
	return _type = valueForStringAttribute("type");
}

void ArtistImage::print() {
// prints a single album image
	std::cout << "height: " << height() << "\n"
		<< "uri: " << uri() << "\n"
		<< "artist_id: " << artistID() << "\n"
		<< "width: " << width() << "\n"
		<< "type: " << type() << std::endl;
	std::cout << std::endl;
}

std::string ArtistImage::htmlString() {
// creates html for a single image
	std::string html;
	
	html += "<img class=";
	html += '"';
	html += "image";
	html += '"';
	html += " ";
	html += "width=";
	html += width();
	html += " ";
	html += "height=";
	html += height();
	html += " src=";
	html += '"';
	html += uri();
	html += '"';
	html += ">";

	return html;
}




