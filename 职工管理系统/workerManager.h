#pragma once
#include<iostream>
#include"worker.h"
using namespace ::std;

//����worker�ĵ�����
typedef struct LNode
{
	worker* data;
	struct LNode* next;//ָ����һ��ְ����ָ�롣
}*LinkList, LNode;

//���������ࣺ���û���ͨ�Ĳ˵��ӿڣ�ְ������ɾ�Ĳ顢�ļ��Ķ�д����
class workerManager
{
public:
	workerManager();

	//��ʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//���ְ��
	void AddWorkers();
	//��ʾְ��
	void ShowWorkers();
	//ɾ��ְ��
	void deleteworker();
	//�޸�ְ��
	void changeworker();
	//���Ҳ����ְ����Ϣ
	void getworker();
	//����Ա��
	void sortworker();
	//�������
	void distory();

	~workerManager();
private:
	int num;
	LinkList head;//ָ��ְ����ͷָ��
	LinkList tail;//ָ��ְ����βָ��
	//�����ļ�
	void save();
	//��ȡ�ļ������뵥����
	void readfile();
	bool fileisempty;//�ж��ļ��Ƿ�Ϊ��
	//���ݱ�Ų���ְ�������ض�Ӧnode
	LNode* getidNode(int id);
	//������������ְ�������ض�Ӧnode
	LNode* getnameNode(string);
	//��������
	void swap(LNode* p1, LNode* p2);

};