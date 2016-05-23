// Eli Simmonds
// Project 3
// JSONDataItem.hpp

#ifndef JSONDATAITEM_H
#define JSONDATAITEM_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>

class JSONDataItem {
public:
	JSONDataItem();
	void parseJSONItem(std::fstream &stream);
	std::string attribute();
	int integerValue();
	std::string stringValue();
	bool isNumber();
	void print();  // purely for debugging -- any format you want

private:
	std::string _attribute, _svalue;
	int _ivalue;
	bool _hasReadAnItem, _isNumber;

	std::string readQuotedString(std::fstream &stream);
};

#endif
