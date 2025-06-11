// Example program
#include "Metrika.h"
#include "Logger.h"
#include "CPUUsage.h"
#include "HttpRequestsCounter.h"
#include <thread>

//��� ������� ������� ���������� ������ ���� Logger
// ��������� � �������� ��������� ������, ������������ ���� � ���-�����
Logger logger("log.txt");

//�������� �������,������� ���������� �� �� main-������
void func() {
	logger.log();
}

int main()
{
	//�������� ����������� ������
	//�������� ���������� ��� �������
	CPUUsage *cpuUsage = new CPUUsage("CPU");
	HttpRequestsCounter *httpRequestsCouunter = new HttpRequestsCounter("HTTP requests RPS");	
	
	 //��������� ������� ������ logger
	logger.add(cpuUsage);
	logger.add(httpRequestsCouunter);

	//��������� ������� �������� ���
	logger.log();

	//��� ������� ������� ����� �����, � ���������� ������ ���
	std::thread t(func);
	t.join();	 	 
}