// Eli Simmonds
// Project 3
// JSONArray.cpp

#include "JSONArray.hpp"

JSONArray::JSONArray() {
	_listOfDataObjects = new std::vector<JSONDataObject *>;
}

JSONArray::~JSONArray() {
	for (auto it = _listOfDataObjects->begin(); it != _listOfDataObjects->end(); it++) {
		delete (*it);
	}
	delete _listOfDataObjects;
}

int JSONArray::numJSONObjects() {
	return _listOfDataObjects->size();
}

void JSONArray::parseJSONArray(std::fstream &stream) { // kooshesh's code
//	char cc[2], prev = ' ';
	char cc[2] = " ";
	cc[1] = '\0';
	if( ! (stream >> cc[0]) || cc[0] != '[' )  // we expect this to be a open-bracket character.i}
		exit(10);
	do {
		JSONDataObject *dItem = jsonObjectNode();
		dItem->parseFromJSONstream(stream);
		_listOfDataObjects->push_back(dItem);
		if( ! (stream >> cc[0]) ) 
			exit(9);
		if( cc[0] != ']' && cc[0] != ',' )  
			exit(11);
	} while( cc[0] != ']' );
}

void JSONArray::print() {
	for (auto it = _listOfDataObjects->begin(); it != _listOfDataObjects->end(); it++) {
		(*it)->print(); 
	} 
}
