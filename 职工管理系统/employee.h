#pragma once
#include"worker.h"
using namespace std;

class Employee :public worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
	Employee(int id, string name, int did);
};
