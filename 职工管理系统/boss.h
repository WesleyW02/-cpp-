#pragma once
#pragma once
#include"worker.h"
using namespace std;

class Boss :public worker
{
public:
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
	Boss(int id, string name, int did);
};
