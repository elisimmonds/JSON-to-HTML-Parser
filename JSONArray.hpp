// Eli Simmonds
// Project 3
// JSONArray.hpp

#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONDataObject.hpp"

#include <vector>
#include <stdlib.h>
#include <cstring>
#include <fstream>


class JSONArray {
public:
	JSONArray();
	~JSONArray();
	std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
	virtual JSONDataObject *jsonObjectNode() = 0;
	int numJSONObjects();
	void parseJSONArray(std::fstream &stream);
	virtual void print();

protected:
	std::vector<JSONDataObject *> *_listOfDataObjects;
};

#endif
