// Eli Simmonds
// Project 3
// Albums.hpp

#ifndef ALBUMS_H
#define ALBUMS_H

#include <string>
#include <vector>
#include <stdlib.h>

#include "Album.hpp"
#include "JSONDataObject.hpp"
#include "JSONArray.hpp"

#include "Tracks.hpp"
//class Tracks;

class AlbumImages;
class Artists;

class Albums: public JSONArray {
public:
	Albums();
	~Albums();

	int numAlbums();
	void addAlbum(Album *album);
	Album *albumWithID(unsigned int aID);
	void setTracksForAlbums(Tracks *tracks);
	void setAlbumsArtist(Artists *artists);
	void setImagesForAlbums(AlbumImages *images);
	Albums *albumsForArtist(unsigned int aID);
	void loadAlbumsFromFile(std::string fileName);
	std::string htmlString();
	JSONDataObject *jsonObjectNode() { return new Album(); }
	std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }
	void runAsserts();

};

#endif
