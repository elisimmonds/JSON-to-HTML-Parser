// Eli Simmonds
// Project 3
// JSONDataObject.hpp

#ifndef JSONDATAOBJECT_H
#define JSONDATAOBJECT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>

#include "JSONDataItem.hpp"

class JSONDataObject {
public:
	JSONDataObject();
	virtual ~JSONDataObject();
	std::vector<JSONDataItem *> *listOfDataItems() const { return _listOfDataItems; }
	void parseFromJSONstream(std::fstream &stream);
	virtual void print();
	std::string valueForStringAttribute(std::string s);
	int valueForIntegerAttribute(std::string s);

private:
	std::vector<JSONDataItem *> *_listOfDataItems;
};

#endif
