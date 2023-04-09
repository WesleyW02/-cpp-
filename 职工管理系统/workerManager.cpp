#include"workerManager.h"
#include<fstream>
#include"boss.h"
#include"employee.h"
#include"manager.h";
#include"worker.h"
#define FILENAME "empFile.txt"
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//第一次使用，文件未创建,文件不存在。
	if (!ifs.is_open())
	{
		//cout<<"文件不存在"<<endl;//测试用例
		num = 0;
		head = NULL;
		tail = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	//文件存在，但是没有数据
	char ch;
	ifs >> ch;
	if (ifs.eof())//文件为空
	{
		//cout<<"文件为空!"<<endl;//测试用例
		num = 0;
		head = NULL;
		tail = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	//文件存在，并且保存职工所有数据,逐行读取数据并存入单链表
	readfile();
}

workerManager::~workerManager()
{
	while (head != NULL)
	{
		LNode* p = head;
		head = head->next;
		delete p;
	}
	head = NULL;
	tail = NULL;
}

//显示菜单
void workerManager:: showMenu()
{
	cout << "************************" << endl;
	cout << "**欢迎进入职工管理系统**" << endl;
	cout << "*****0.退出管理系统*****" << endl;
	cout << "*****1.增加职工信息*****" << endl;
	cout << "*****2.显示职工信息*****" << endl;
	cout << "*****3.删除离职员工*****" << endl;
	cout << "*****4.修改职工信息*****" << endl;
	cout << "*****5.查找职工信息*****" << endl;
	cout << "*****6.按照编号排序*****" << endl;
	cout << "*****7.清空所有文档*****" << endl;
	cout << "************************" << endl;
}
//退出系统
void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void workerManager:: AddWorkers() 
{
	cout << "请输入需要增加的职工数" << endl;
	int addnum=0;
	cin >> addnum;
	if (addnum > 0)
	{
		for (int i = 0; i < addnum; i++)
		{
			cout << "请输入第" << i + 1 << "个职工信息" << endl;
			cout << "请输入职工编号" << endl;
			int id=0;
			cin >> id;
			cout << "请输入职工姓名" << endl;
			string name;
			cin >> name;
			cout << "请输入职工岗位" << endl;
			cout << "1:老板，2：经理，3：普通员工" << endl;
			int did;
			cin >>did;
			LNode* newnode = new LNode;
			switch (did)
			{
			case 1:
				newnode->data = new Boss(id, name, did);
				break;
			case 2:
				newnode->data = new Manager(id, name, did);
				break;
			case 3:
				newnode->data = new Employee(id, name, did);
				break;
			default:
				cout << "输入信息有误，请重新输入" << endl;
				i--;
				break;
			}
			if (did == 1 || did == 2 || did == 3)
			{
				if (head == NULL)//当前没有职工
				{
					head = newnode;
					tail = newnode;
					tail->next=NULL;
				}
				else
				{
					tail->next = newnode;
					tail = newnode;//尾插法插入单链表
					tail->next = NULL;
				}
				num++;
			}
		}
		save();
	}
	else
	{
		cout << "输入数量有误" << endl;
	}
	system("cls");
	return;
}

//显示职工
void workerManager::ShowWorkers()
{
	if (head == NULL)
	{
		cout << "目前没有员工" << endl;
		system("pause");
		system("cls");
		return;
	}
	LNode* p=head;
	while (NULL!= p)
	{
		p->data->showInfo();//显示p的信息
		p = p->next;
	}
	system("pause");
	system("cls");
	return;
}

//写入文件
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	LNode* p = head;
	while (p != NULL)
	{
		ofs << p->data->m_id << "\t" << p->data->m_name
			<< "\t" << p->data->m_deptid << endl;
		p = p->next;
	}
	ofs.close();
}

//读取文件并存入单链表
void workerManager:: readfile()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//读取失败和为空已经判断过了，这里不用管。
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		LNode* newnode = new LNode;
		switch (did)
		{
		case 1:
			newnode->data = new Boss(id, name, did);
			break;
		case 2:
			newnode->data = new Manager(id, name, did);
			break;
		case 3:
			newnode->data = new Employee(id, name, did);
			break;
		}
		if (head == NULL)//当前没有职工
		{
			head = newnode;
			tail = newnode;
			tail->next = NULL;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;//尾插法插入单链表
			tail->next = NULL;
		}
		num++;
	}
	ifs.close();
}

//根据编号查找员工，并返回对应node
LNode* workerManager:: getidNode(int id)
{
	LNode* p = head;
	LNode* q = NULL;
	while (p != NULL && p->data->m_id != id)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到编号为" << id << "的职工" << endl;
		return NULL;
	}
	return q;
}

//删除职工
void workerManager::deleteworker()
{
	cout << "请输入需要删除职工的ID" << endl;
	int id;
	cin >> id;
	LNode* q = getidNode(id);//q为待删除结点前驱
	if (q != NULL)
	{
		LNode* p = q->next;
		if (q == head && p == NULL)//此时有唯一结点
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else//p为q后继，删除p
		{
			q->next = p->next;
			delete p;
			cout << "删除成功" << endl;
		}
	}
	else//q=NULL,单独判断恰好需要删除第一个结点时
	{
		if (head->data->m_id == id)//需要删除第一个结点
		{
			q = head;
			head = head->next;
			delete q;
			q = NULL;
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败" << endl;
		}
	}

	//将结果写回文件
	save();
	system("pause");
	system("cls");
}

//修改职工
void workerManager::changeworker()
{
	cout << "请输入需要修改职工的ID" << endl;
	int id;
	cin >> id;
	int did;
	string name;
	LNode* q = getidNode(id);//q为待修改结点前驱
	if (q != NULL)
	{
		LNode* p = q->next;
		if (q == head && p == NULL)//此时有唯一结点
		{
			cout << "请重新输入信息" << endl;
			cout << "请输入职工编号" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "请输入职工姓名" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "请输入职工岗位" << endl;
			cout << "1:老板，2：经理，3：普通员工" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "修改成功" << endl;
		}
		else//p为q后继，修改p
		{
			q = q->next;
			cout << "请重新输入信息" << endl;
			cout << "请输入职工编号" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "请输入职工姓名" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "请输入职工岗位" << endl;
			cout << "1:老板，2：经理，3：普通员工" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "修改成功" << endl;
		}
	}
	else//q=NULL,单独判断恰好需要删除第一个结点时
	{
		q = head;
		if (head->data->m_id == id)//需要修改第一个结点
		{
			cout << "请重新输入信息" << endl;
			cout << "请输入职工编号" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "请输入职工姓名" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "请输入职工岗位" << endl;
			cout << "1:老板，2：经理，3：普通员工" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败" << endl;
		}
	}

	//将结果写回文件
	save();
	system("pause");
	system("cls");
}

//根据姓名查找职工并返回对应node
LNode* workerManager:: getnameNode(string name)
{
	LNode* p = head;
	LNode* q = NULL;
	while (p != NULL && p->data->m_name != name)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到姓名为" << name << "的职工" << endl;
		return NULL;
	}
	return q;
}

//查找并输出职工信息
void workerManager:: getworker()
{
	cout << "请输入查询方式" << endl;
	cout << "1.按编号查询，2.按姓名查询" << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (1 == choice)
		{
			cout << "请输入id" << endl;
			int id;
			cin >> id;
			LNode*q = getidNode(id);
			if (q != NULL)
			{
				LNode* p = q->next;
				if (q == head && p == NULL)//此时有唯一结点
				{
					q->data->showInfo();
				}
				else//p为q后继，删除p
				{
					p->data->showInfo();
				}
			}
			else//q=NULL,单独判断恰好需要删除第一个结点时
			{
				if (head->data->m_id == id)//需要删除第一个结点
				{
					head->data->showInfo();
				}
			}
			goto FLAG;
		}
		else if (2 == choice)
		{
			cout << "请输入姓名" << endl;
			string name;
			cin >> name;
			LNode* q = getnameNode(name);
			if (q != NULL)
			{
				LNode* p = q->next;
				if (q == head && p == NULL)//此时有唯一结点
				{
					q->data->showInfo();
				}
				else//p为q后继，删除p
				{
					p->data->showInfo();
				}
			}
			else//q=NULL,单独判断恰好需要删除第一个结点时
			{
				if (head->data->m_name == name)//需要删除第一个结点
				{
					head->data->showInfo();
				}
			}
			goto FLAG;
		}
		else
		{
			cout << "请输入有效的输入" << endl;
		}
	}
FLAG:
	system("pause");
	system("cls");
	return;
}

//交换函数
void workerManager::swap(LNode* p1, LNode* p2)
{
	worker* temp;
	temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}

//排序职工
void workerManager::sortworker()
{
	cout << "请输入排序方式" << endl;
	cout << "1.按编号升序，2.按编号降序" << endl;
	int choice = 0;
	cin >>choice;
	if (choice == 1)
	{
		LNode* min;//记录id最小的node
		min = head;
		LNode* p = head;
		LNode* q = head;
		while (p != NULL)
		{
			while (q != NULL)
			{
				if (q->data->m_id < min->data->m_id)
				{
					min = q;
				}
				q = q->next;
			}
			swap(min, p);
			//cout << min->data->m_id << " " << p->data->m_id << endl;
			p = p->next;
			min = p;
			q = p;
		}
	}
	else if(choice ==2)
	{
		LNode* max;//记录id最大的node
		max = head;
		LNode* p = head;
		LNode* q = head;
		while (p != NULL)
		{
			while (q != NULL)
			{
				if (q->data->m_id > max->data->m_id)
				{
					max = q;
				}
				q = q->next;
			}
			swap(max, p);
			//cout << min->data->m_id << " " << p->data->m_id << endl;
			p = p->next;
			max = p;
			q = p;
		}
	}
	else
	{
		cout << "排序规则错误" << endl;
	}
	//存入文件
	save();
	system("pause");
	system("cls");
}

void workerManager::distory()
{
	cout << "确定要清空文件吗？" << endl;
	cout << "1.确定" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		LNode* p = head;
		LNode* q = head;
		while (p != NULL)
		{
			p = p->next;
			delete q;
			q = p;
		}
		head = NULL;
		tail = NULL;
	}
	else
	{
		cout << "取消清空" << endl;
	}
	save();
	system("pause");
	system("cls");
}