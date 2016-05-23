// Eli Simmonds
// Project 3
// ArtistImages.hpp

#ifndef ARTISTIMGS_H
#define ARTISTIMGS_H

#include "JSONDataObject.hpp"
#include "JSONArray.hpp"
#include "ArtistImage.hpp"

#include <string>
#include <vector>
#include <iostream>

class ArtistImages: public JSONArray {
public:
	ArtistImages();
	~ArtistImages();
	
	int numImages();
	void addImage(ArtistImage *image);
	ArtistImage *findArtistImage(int aID);
	void loadImagesFromFile(std::string fileName);
	std::string htmlString();
	JSONDataObject *jsonObjectNode() { return new ArtistImage(); }
	//set images for artist?
	std::vector<ArtistImage *> *listOfArtistImages() { return (std::vector<ArtistImage *> *) _listOfDataObjects; }
	void runAsserts();  // used for checking integrity of the class

};

#endif
