// Eli Simmonds
// Project 3
// Artists.hpp

#ifndef ARTISTS_H
#define ARTISTS_H

#include "Artist.hpp"
#include "JSONArray.hpp"

#include <string>
#include <vector>
#include <iostream>

class Albums;
class Album;
class ArtistImages;

class Artists: public JSONArray {
public:
	Artists();
	~Artists();

	int numArtists();
	void addArtist(Artist *artist);
	Artist *artistWithID(unsigned int aID);
	void loadArtistsFromFile(std::string fileName);
	std::string htmlString();
	JSONDataObject *jsonObjectNode() { return new Artist();  }
	void setAlbumsForArtists(Albums *albums); // also sets albums _artist variable
	void setImagesForArtists(ArtistImages *images);
	std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
	void runAsserts();  // used for checking the integrity of this class.

};

#endif
