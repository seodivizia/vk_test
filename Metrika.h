#pragma once
#include <string>

class Metrika
{
	std::string name;
public:
	Metrika(const std::string &name) : name(name) {};
	std::string get_name() { return name; }
	virtual std::string to_string() = 0;
	virtual Metrika *compute() = 0;
	

};

