// Eli Simmonds
// Project 3
// ArtistImages.cpp

#include "ArtistImages.hpp"

ArtistImages::ArtistImages() {

}

ArtistImages::~ArtistImages() {
// use base class destructor
}

int ArtistImages::numImages() {
// returns size of the vector
	return listOfArtistImages()->size();
}

void ArtistImages::addImage(ArtistImage *image) {
// adds an image ptr to the vector
	listOfArtistImages()->push_back(image);
}

ArtistImage *ArtistImages::findArtistImage(int aID) {
// finds an image by iterating through the vector
// and returns it
	ArtistImage *image;
	for (int i = 0; i < numImages(); i++) {
		if (listOfArtistImages()->at(i)->artistID() == aID) {
			image = listOfArtistImages()->at(i);
			return image; }
	}
	return image;
}

void ArtistImages::loadImagesFromFile(std::string fileName) {
	std::fstream artistImages;
	artistImages.open(fileName);
	if (!artistImages.is_open()) {
		exit(22); }
	parseJSONArray(artistImages);
	artistImages.close();
}

void ArtistImages::runAsserts() {

}
