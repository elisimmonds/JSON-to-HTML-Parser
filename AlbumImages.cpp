// Eli Simmonds
// Project 3
// AlbumImages.cpp


#include "AlbumImages.hpp"


AlbumImages::AlbumImages() {

}

AlbumImages::~AlbumImages() {
// uses base class destructor
}

int AlbumImages::numImages() {
// returns the size of the vector
	return listOfAlbumImages()->size();
}

void AlbumImages::addImage(AlbumImage *image) {
// adds an image ptr to the vector
	listOfAlbumImages()->push_back(image);
}

AlbumImage *AlbumImages::findAlbumImage(int aID) {
// returns the image ptr based on an album id
	for (int i = 0; i < numImages(); i++) {
		if (listOfAlbumImages()->at(i)->albumID() == aID) {
			return listOfAlbumImages()->at(i);
		}
	}
	return nullptr;
}

void AlbumImages::loadImagesFromFile(std::string fileName) {
	std::fstream albumImages;
	albumImages.open(fileName);
	if (!albumImages.is_open())
		exit (23);
	parseJSONArray(albumImages);
	albumImages.close();
	
}

std::string AlbumImages::htmlString() {
// creates master list of album images
	std::string html;
	for (int i = 0; i < numImages(); i++) {
		html += listOfAlbumImages()->at(i)->htmlString();
	}
	return html;
}

void AlbumImages::runAsserts() {

}
