#pragma once
#include"worker.h"
using namespace std;

class Manager :public worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
	Manager(int id, string name, int did);
};
