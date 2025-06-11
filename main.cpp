// Example program
#include "Metrika.h"
#include "Logger.h"
#include "CPUUsage.h"
#include "HttpRequestsCounter.h"
#include <thread>

//Для примера создаем глобальный объект типа Logger
// передавая в качестве аргумента строку, обозначающую путь к лог-файлу
Logger logger("log.txt");

//Тестовая функция,которая вызывается из не main-потока
void func() {
	logger.log();
}

int main()
{
	//создание необходимых метрик
	//аргумент обозначает имя метрики
	CPUUsage *cpuUsage = new CPUUsage("CPU");
	HttpRequestsCounter *httpRequestsCouunter = new HttpRequestsCounter("HTTP requests RPS");	
	
	 //добавляем метрики внутрь logger
	logger.add(cpuUsage);
	logger.add(httpRequestsCouunter);

	//имитируем событие записать лог
	logger.log();

	//для примера создаем новый поток, и записываем оттуда лог
	std::thread t(func);
	t.join();	 	 
}