#include "Logger.h"
#include "Metrika.h"
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <future>
#include <iostream>
#include <iomanip>

void Logger::log() {

	//получаем log-строку
	auto logstr = get_log_str();

	//вызываем запись в log-файл в отдельном потоке( асинхронный вызов)
	auto  fut = std::async(std::launch::async, &Logger::write, this, logstr);

	fut.get();
}

//непостредственная запись в log-файл
void Logger::write(const std::string &data) {

	std::cout << data << std::endl;

	fs.open(filepath, std::ios::app);

	fs << data << std::endl;

	fs.close();
}

//вычисляем таймштамп
std::string Logger::get_timestamp_str()
{
	using namespace std;

	auto currentTime = chrono::system_clock::now();
	auto currentTimeT = chrono::system_clock::to_time_t(currentTime);
	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(currentTime.time_since_epoch() % chrono::seconds(1));

	//get milliseconds
	auto milliCount = milliseconds.count();

	auto t = *localtime(&currentTimeT);

	//get year
	auto year = t.tm_year + 1900;

	//get month
	auto month = t.tm_mon + 1;

	//get day
	auto day = t.tm_mday;

	//get hour
	auto hour = t.tm_hour;

	//get minutes
	auto min = t.tm_min;

	//get seconds
	auto sec = t.tm_sec;

	stringstream ss;

	ss << year << "-" << std::setfill('0') << setw(2) << month << "-" << setw(2) << day << " " << hour << ":" << min << ":" << sec << "." << milliCount;

	return ss.str();

}


//получаем форматированную строку , которая будет записана в log-файл
std::string Logger::get_log_str() {

	std::string s;

	s += get_timestamp_str();

	s += " ";

	for (Metrika *item : v) {

		s += item->compute()->to_string();

		s += " ";
	}

	return s;

}