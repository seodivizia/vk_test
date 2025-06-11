// Example program
#include "Metrika.h"
#include "Logger.h"
#include "CPUUsage.h"
#include "HttpRequestsCounter.h"
#include <thread>

//For example we create global object of type Logger
// passing as an argument string, that denotes path to log-file
Logger logger("log.txt");

//Test function< that called NOT in the main thread
void func() {
	logger.log();
}

int main()
{
	//Creation necessary metriks
	//Argument is name of metrik
	CPUUsage *cpuUsage = new CPUUsage("CPU");
	HttpRequestsCounter *httpRequestsCouunter = new HttpRequestsCounter("HTTP requests RPS");	
	
	 //add metriks inside the logger
	logger.add(cpuUsage);
	logger.add(httpRequestsCouunter);

	//invoke log to write to the file
	logger.log();

	//for example we create new thread, and write log in it
	std::thread t(func);
	t.join();	 

	delete cpuUsage;
	delete httpRequestsCouunter;
}