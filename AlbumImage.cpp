// Eli Simmonds
// Project 3
// AlbumImage.cpp

#include "AlbumImage.hpp"

int albImageRefCount = 0;

AlbumImage::AlbumImage() {
// initializes all private variables
	albImageRefCount++;
	_height = _width = _albumID = 0;
	_type = _uri = " ";
	cachedHeight = cachedWidth = cachedAlbumID
		= cachedType = cachedURI = false;
}

AlbumImage::~AlbumImage() {
// decrements the counter that tracks memory allocation
	albImageRefCount--;
}

int AlbumImage::height() {
	if (cachedHeight)
		return _height;
	cachedHeight = true;
	return _height = valueForIntegerAttribute("height");
}

int AlbumImage::width() {
	if (cachedWidth)
		return _width;
	cachedWidth = true;
	return _width = valueForIntegerAttribute("width");
}

int AlbumImage::albumID() {
	if (cachedAlbumID)
		return _albumID;
	cachedAlbumID = true;
	return _albumID = valueForIntegerAttribute("album_id");
}

std::string AlbumImage::type() {
	if (cachedType)
		return _type;
	cachedType = true;
	return _type = valueForStringAttribute("type");
}

std::string AlbumImage::uri() {
	if (cachedURI)
		return _uri;
	cachedURI = true;
	return _uri = valueForStringAttribute("uri");
}

void AlbumImage::print() {
// prints all variables of the image
	std::cout << "height: " << height() << '\n'
		<< "type: " << type() << '\n'
		<< "uri: " << uri() << '\n'
		<< "width: " << width() << '\n'
		<< "album_id: " << albumID() << '\n'
		<< std::endl;
}

std::string AlbumImage::htmlString() {
// creates a string for a single image
	std::string html;

	html += "<img class=";
	html += '"';
	html += "image";
	html += '"';
	html += " width=";
	html += width();
	html += " height=";
	html += height();
	html += " src=";
	html += '"';
	html += uri();
	html += '"';
	html += ">";

	return html;
}
