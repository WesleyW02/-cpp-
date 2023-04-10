#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker//职工抽象类
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	string m_name;
	int m_id;
	int m_deptid;//职工所在部门名称编号
};