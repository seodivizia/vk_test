#pragma once
#include <vector>
#include <string>
#include "Metrika.h"
#include <fstream>






class Logger
{
	std::vector<Metrika *> v;
	std::string s;
	std::string filepath;
	std::fstream fs;

public:

	Logger(const std::string &filename): filepath(filename)
	{
		
	}
	void add(Metrika *m)
	{
		
		v.push_back(m);
	}	

	void log();

private:

	std::string get_log_str();

	void write(const std::string &data);	

	std::string get_timestamp_str();
	
};

