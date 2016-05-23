// Eli Simmonds
// Project 3
// JSONDataItem.cpp

#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem() {
	_hasReadAnItem = _isNumber = false;
	_attribute = _svalue = "";
	_ivalue = 0;
}

void JSONDataItem::parseJSONItem(std::fstream &stream) {
	char c;
	if (!(stream >> c) || c != '"')
		exit(1);

	_attribute = readQuotedString(stream);

	if (!(stream >> c || c != ':'))
		exit(2);

	stream >> c;
	if (isdigit(c)) {
		_isNumber = true;
		stream.unget();
		stream >> _ivalue; }
	else {
		_svalue = readQuotedString(stream); }
}

std::string JSONDataItem::attribute() {
	return _attribute;
}

std::string JSONDataItem::readQuotedString(std::fstream &stream) {
	char c;
	std::string temp;

	stream.get(c);
	while ( c != '"' ) {
		if ( c == '\\' ) {
			//temp += c;
			stream.get(c);
		}
		temp += c;
		stream.get(c);
	}
	return temp;

}

int JSONDataItem::integerValue() {
	return _ivalue;
}

std::string JSONDataItem::stringValue() {
	return _svalue;
}

bool JSONDataItem::isNumber() {
	return _isNumber; 
}

void JSONDataItem::print() {
	std::cout << "JSONDataItem: print() " << std::endl;
	std::cout << attribute() << " : ";
	if (isNumber())
		std::cout << integerValue() << std::endl;
	else
		std::cout << stringValue() << std::endl;
}
