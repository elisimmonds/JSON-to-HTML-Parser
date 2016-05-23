// Eli Simmonds
// Project 3
// JSONDataObject.cpp

#include "JSONDataObject.hpp"

JSONDataObject::JSONDataObject() {
	_listOfDataItems = new std::vector<JSONDataItem *>; // use pointer or physical vector?
}

JSONDataObject::~JSONDataObject() {
	for (auto it = _listOfDataItems->begin(); it != _listOfDataItems->end(); it++) {
		delete (*it);
	}
//	std::cout << "JSONDataObject: Destructor called" << std::endl;
	delete _listOfDataItems;
}

void JSONDataObject::parseFromJSONstream(std::fstream &stream) {
	char c;
	if (!(stream >> c) || c != '{')
		exit(1);
	
	do {
		JSONDataItem *a = new JSONDataItem();
		a->parseJSONItem(stream);
		_listOfDataItems->push_back(a);
		stream >> c;
	} while (c != '}');
}

void JSONDataObject::print() {
	if (_listOfDataItems->empty())
		std::cout << "Vector is empty" << std::endl;

	std::cout << "JSONDataObject: print()" << std::endl;
	for(auto it = _listOfDataItems->begin(); it!=_listOfDataItems->end(); it++){
		(*it)->print();	
	}
}

std::string JSONDataObject::valueForStringAttribute(std::string s) {
	for(auto it = _listOfDataItems->begin(); it!=_listOfDataItems->end(); it++){
		if ((*it)->attribute() == s && !(*it)->isNumber())
			return (*it)->stringValue();
	}
	return "unknown";
	
}

int JSONDataObject::valueForIntegerAttribute(std::string s) {
	for(auto it = _listOfDataItems->begin(); it!=_listOfDataItems->end(); it++){
		if ((*it)->attribute() == s && (*it)->isNumber())
			return (*it)->integerValue();
	}
	return 0;
}
