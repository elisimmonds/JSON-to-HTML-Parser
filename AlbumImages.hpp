// Eli Simmonds
// Project 3
// AlbumImages.hpp

#ifndef ALBUMIMAGES_H
#define ALBUMIMAGES_H

#include "JSONDataObject.hpp"
#include "JSONArray.hpp"
#include "AlbumImage.hpp"

#include <string>
#include <vector>
#include <iostream>


class AlbumImages: public JSONArray {
public:
	AlbumImages();
	~AlbumImages();

	int numImages();
	void addImage(AlbumImage *image);
	AlbumImage *findAlbumImage(int aID);
	void loadImagesFromFile(std::string fileName);
	std::string htmlString();
	JSONDataObject *jsonObjectNode() { return new AlbumImage(); }

	std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }
	void runAsserts();

};

#endif
