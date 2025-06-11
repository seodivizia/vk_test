#include "HttpRequestsCounter.h"
#include <string>
#include <sstream>


HttpRequestsCounter::HttpRequestsCounter(const std::string &name): Metrika(name)
{
}

Metrika *HttpRequestsCounter::compute()
{
	//вычисляем метрику http requests count
	count = 11;
	return this;
}

std::string HttpRequestsCounter::to_string() {

	std::ostringstream os;
	
	os << get_name() + " \"" << count << + "\"";

	return   os.str();
}