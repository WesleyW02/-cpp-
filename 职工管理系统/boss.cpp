#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司事物" << endl;
}
//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}

