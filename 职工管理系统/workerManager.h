#pragma once
#include<iostream>
#include"worker.h"
using namespace ::std;

//定义worker的单链表
typedef struct LNode
{
	worker* data;
	struct LNode* next;//指向下一个职工的指针。
}*LinkList, LNode;

//创建管理类：与用户沟通的菜单接口，职工的增删改查、文件的读写交互
class workerManager
{
public:
	workerManager();

	//显示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//添加职工
	void AddWorkers();
	//显示职工
	void ShowWorkers();
	//删除职工
	void deleteworker();
	//修改职工
	void changeworker();
	//查找并输出职工信息
	void getworker();
	//排序员工
	void sortworker();
	//清空数据
	void distory();

	~workerManager();
private:
	int num;
	LinkList head;//指向职工的头指针
	LinkList tail;//指向职工的尾指针
	//保存文件
	void save();
	//读取文件并存入单链表
	void readfile();
	bool fileisempty;//判断文件是否为空
	//根据编号查找职工并返回对应node
	LNode* getidNode(int id);
	//根据姓名查找职工并返回对应node
	LNode* getnameNode(string);
	//交换函数
	void swap(LNode* p1, LNode* p2);

};