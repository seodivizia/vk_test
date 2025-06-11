#pragma once
#include "Metrika.h"
#include <string>
class CPUUsage : public Metrika
{	
	double usage = 0;
public:

	CPUUsage(const std::string &name);
	virtual Metrika *compute();
	virtual std::string to_string();

	
};

