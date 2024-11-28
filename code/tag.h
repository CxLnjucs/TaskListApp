#pragma once

#include<string>

class Tag {
	std::string name;

public:
	Tag(std::string _name):name(_name) {}
	std::string get_name() {
		return name;
	}
};