#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾����" << endl;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}

