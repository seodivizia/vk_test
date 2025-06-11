#pragma once
#include "Metrika.h"
#include <string>

class HttpRequestsCounter: public Metrika
{

	int count = 0;

public: 

	HttpRequestsCounter(const std::string &name);

	virtual Metrika *compute();

	virtual std::string to_string();	
};

