#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker//ְ��������
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
	string m_name;
	int m_id;
	int m_deptid;//ְ�����ڲ������Ʊ��
};