#pragma once
#pragma once
#include"worker.h"
using namespace std;

class Boss :public worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
	Boss(int id, string name, int did);
};
