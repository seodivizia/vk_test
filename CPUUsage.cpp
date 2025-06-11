#include "CPUUsage.h"
#include <sstream>


CPUUsage::CPUUsage(const std::string &name): Metrika(name)
{
}

Metrika *CPUUsage::compute() {
	//��������� ������� usage
	//�������� ��� �����
	usage = 1.5;
	return this;
}

std::string CPUUsage::to_string() {

	std::ostringstream os;

	os << get_name() + " \"" << usage << +"\"";

	return   os.str();
	
}