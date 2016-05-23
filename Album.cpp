// Eli Simmonds
// Project 3
// Album.cpp

#include "Album.hpp"
#include "Artist.hpp"
#include "Tracks.hpp"

int albumRefCount = 0;

Album::Album() {
// album constructor
// initializes all private variables
	albumRefCount++;
	_title = _year = _genres = " ";
	_numTracks = _artistID = _numImages = _albumID = 0;
	cachedTitle = cachedYear = cachedGenres = cachedNumTracks =
		cachedArtistID = cachedNumImages = cachedAlbumID = false;

	_tracks = new Tracks();
	_primaryAlbumImage = new AlbumImage();
	_secondaryAlbumImage = new AlbumImage();
}

Album::~Album() {
// destructor for the album class
// deletes the images and all tracks associated with
// the album instance
//	std::cout << "Album: Destructor called on " << title() << std::endl;
	albumRefCount--;
	delete _tracks;
	delete _primaryAlbumImage;
	delete _secondaryAlbumImage;	
}

std::string Album::title() {
	if (cachedTitle)
		return _title;
	cachedTitle = true;
	return _title = valueForStringAttribute("title");
}

std::string Album::genres() {
	if (cachedGenres)
		return _genres;
	cachedGenres = true;
	return _genres = valueForStringAttribute("genres");
}

std::string Album::year() {
	if (cachedYear)
		return _year;
	cachedYear = true;
	return _year = valueForStringAttribute("year");
}

unsigned Album::albumID() {
	if (cachedAlbumID)
		return _albumID;
	cachedAlbumID = true;
	return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::artistID() {
	if (cachedArtistID)
		return _artistID;
	cachedArtistID = true;
	return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned Album::numImages() {
	if (cachedNumImages)
		return _numImages;
	cachedNumImages = true;
	return _numImages = valueForIntegerAttribute("num_images");
}

unsigned Album::numTracks() {
	if (cachedNumTracks)
		return _numTracks;
	cachedNumTracks = true;
	return _numTracks = valueForIntegerAttribute("num_tracks");
}

void Album::setImage(AlbumImage *image) {
// sets the image for the album class
// decides whether the image is going to be the
// primary or secondary image for the class
	if (image->type() == "primary")
		_primaryAlbumImage = image;
	else if (image->type() == "secondary")
		_secondaryAlbumImage = image;
	else
		std::cout << "Album::setImage: no images for album: " << title() << std::endl;
}

void Album::setTracks(Tracks *tracks) {
// sets the tracks for the album instance
	_tracks = tracks;
}

void Album::setArtist(Artist *artist) {
// sets the artist that created the albums
	_artist = artist;
}

void Album::print() {
// prints out all info in the album class
// as well as all the tracks in the album
// and the primary/secondary image if they
// are set.
	std::cout << "NumTracks: " << numTracks() << "\n"
		<< "Title: " << title() << "\n"
		<< "Year: " << year() << "\n"
		<< "Genres: " << genres() << "\n"
		<< "Artist ID: " << artistID() << "\n"
		<< "Num Images: " << numImages() << "\n"
		<< "Album ID: " << albumID() << std::endl;
	std::cout << std::endl;
	if (_primaryAlbumImage->height() != 0) {
		_primaryAlbumImage->print(); }
	if (_secondaryAlbumImage->height() != 0) {
		_secondaryAlbumImage->print(); }

	std::cout << std::endl;
	_tracks->print();
}

std::string Album::htmlString() {
// creates the html string for an album instance
// includes one image, the primary image having
// the first call. Also includes the HTML for the
// tracks that this album includes
	std::string html;
	html += "<li><p><strong>";
	html += title();
	html += "</strong></p>";
	if (_primaryAlbumImage->height() != 0)
		html += _primaryAlbumImage->htmlString();
	else if (_secondaryAlbumImage->height() != 0)
		html += _secondaryAlbumImage->htmlString();
	html += "<table class=";
	html += '"';
	html += "albumInfo";
	html += '"';
	html += "><tr><td class=";
	html += '"';
	html += "aTitle";
	html += '"';
	html += " colspan=2>";
	html += title();
	html += "</td></tr><tr><td class=";
	html += '"';
	html += "tdNarrow";
	html += '"';
	html += ">Artist:</td><td class=";
	html += '"';
	html += "value";
	html += '"';
	html += ">";
	html += _artist->artistName();
	html += "</td></tr><tr><td class=";
	html += '"';
	html += "tdNarrow";
	html += '"';
	html += ">Genres:</td><td class=";
	html += '"';
	html += "value";
	html += '"';
	html += ">";
	html += genres();
	html += "</td></tr><tr><td>Year:</td><td class=";
	html += '"';
	html += "value";
	html += '"';
	html += ">";
	html += year();
	html += "</td></tr></table>";
	html += "<div class=";
	html += '"';
	html += "clear";
	html += '"';
	html += ">&nbsp;</div><h2>Tracklist</h2>";
	html += "<table class=";
	html += '"';
	html += "tracks";
	html += '"';
	html += '>';
	html += _tracks->htmlString();
	html += "</table></li>";

	return html;
}





