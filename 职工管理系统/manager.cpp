#include"Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，给普通员工下发任务" << endl;
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}

