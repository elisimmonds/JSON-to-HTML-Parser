// Eli Simmonds
// Project 3
// Artist.cpp

#include "Artist.hpp"
#include "Albums.hpp"

int artRefCount = 0;

Artist::Artist() {
	artRefCount++;
	_name = _realName = _profile = _numImages = "";
	_artistID = 0;
	cachedName = cachedRealName = cachedProfile = cachedNumImages = cachedArtistID = false;

	_primaryImage = new ArtistImage();
	_secondaryImage = new ArtistImage();
	_albums = new Albums();
}

Artist::~Artist() {
// starts a waterfall for the destructors
// artist instance is deleted as well as each album that it owns
	artRefCount--;
	delete _albums;
	delete _primaryImage;
	delete _secondaryImage;
}

std::string Artist::profile()    
{
	if( cachedProfile )
		return _profile;
	cachedProfile = true;
	return _profile = valueForStringAttribute("profile");
}

std::string Artist::artistName() {
	if ( cachedName )
		return _name;
	cachedName = true;
	return _name = valueForStringAttribute("artist_name");
}

std::string Artist::realName() {
	if ( cachedRealName )
		return _realName;
	cachedRealName = true;
	return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages() {
	if ( cachedNumImages )
		return _numImages;
	cachedNumImages = true;
	return _numImages = valueForStringAttribute("num_images");
}

unsigned Artist::artistID() {
	if (cachedArtistID)
		return _artistID;
	cachedArtistID = true;
	return _artistID = valueForIntegerAttribute("artist_id");
}

void Artist::print() {
// prints an instance of album and it's albums
	std::cout << "Profile: " << profile() << "\n"
		<< "Artist Name: " << artistName() << "\n"
		<< "Real Name: " << realName() << "\n"
		<< "Num Images: " << numImages() << "\n"
		<< "Artist ID: " << artistID() << "\n"
		<< std::endl;
	std::cout << std::endl;	
	if (_primaryImage->height() != 0) {
		std::cout << "printing primary image" << std::endl;
		_primaryImage->print(); }
	if (_secondaryImage->height() != 0) {
		std::cout << "printing secondary image" << std::endl;
		_secondaryImage->print();}
	_albums->print();
}

std::string Artist::htmlString() {
// creates the html for artist
// calls the html strings for albums and artist images
	bool firstImage = false;
	std::string html;
	html += "<h2>";
	html += artistName();
	html += "</h2>";
	if (_primaryImage->height() != 0) {
		html += _primaryImage->htmlString();
		firstImage = true; }
	if (!firstImage && _secondaryImage->height() != 0)
		html += _secondaryImage->htmlString();
	html += "<table class=";
	html += '"';
	html += "artistInfo";
	html += '"';
	html += "><tr><tr><td class=";
	html += '"';
	html += "tagName";
	html += '"';
	html += ">Number of Images: </td><td class=";
	html += '"';
	html += "value";
	html += '"';
	html += ">";
	html += numImages();
	html += "</td></tr><tr><td>Profile:</td><td class=";
	html += '"';
	html += "value";
	html += '"';
	html += ">";
	html += profile();
	html += "</td></tr></table>";
	html += "<div class=";
	html += '"';
	html += "clear";
	html += '"';
	html += ">&nbsp;</div><h2>Albums</h2><ol>";
	html += _albums->htmlString();
	html += "</ol>";

	return html;
}


