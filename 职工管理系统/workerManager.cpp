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
	//��һ��ʹ�ã��ļ�δ����,�ļ������ڡ�
	if (!ifs.is_open())
	{
		//cout<<"�ļ�������"<<endl;//��������
		num = 0;
		head = NULL;
		tail = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ�����û������
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		//cout<<"�ļ�Ϊ��!"<<endl;//��������
		num = 0;
		head = NULL;
		tail = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	//�ļ����ڣ����ұ���ְ����������,���ж�ȡ���ݲ����뵥����
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

//��ʾ�˵�
void workerManager:: showMenu()
{
	cout << "************************" << endl;
	cout << "**��ӭ����ְ������ϵͳ**" << endl;
	cout << "*****0.�˳�����ϵͳ*****" << endl;
	cout << "*****1.����ְ����Ϣ*****" << endl;
	cout << "*****2.��ʾְ����Ϣ*****" << endl;
	cout << "*****3.ɾ����ְԱ��*****" << endl;
	cout << "*****4.�޸�ְ����Ϣ*****" << endl;
	cout << "*****5.����ְ����Ϣ*****" << endl;
	cout << "*****6.���ձ������*****" << endl;
	cout << "*****7.��������ĵ�*****" << endl;
	cout << "************************" << endl;
}
//�˳�ϵͳ
void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void workerManager:: AddWorkers() 
{
	cout << "��������Ҫ���ӵ�ְ����" << endl;
	int addnum=0;
	cin >> addnum;
	if (addnum > 0)
	{
		for (int i = 0; i < addnum; i++)
		{
			cout << "�������" << i + 1 << "��ְ����Ϣ" << endl;
			cout << "������ְ�����" << endl;
			int id=0;
			cin >> id;
			cout << "������ְ������" << endl;
			string name;
			cin >> name;
			cout << "������ְ����λ" << endl;
			cout << "1:�ϰ壬2������3����ͨԱ��" << endl;
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
				cout << "������Ϣ��������������" << endl;
				i--;
				break;
			}
			if (did == 1 || did == 2 || did == 3)
			{
				if (head == NULL)//��ǰû��ְ��
				{
					head = newnode;
					tail = newnode;
					tail->next=NULL;
				}
				else
				{
					tail->next = newnode;
					tail = newnode;//β�巨���뵥����
					tail->next = NULL;
				}
				num++;
			}
		}
		save();
	}
	else
	{
		cout << "������������" << endl;
	}
	system("cls");
	return;
}

//��ʾְ��
void workerManager::ShowWorkers()
{
	if (head == NULL)
	{
		cout << "Ŀǰû��Ա��" << endl;
		system("pause");
		system("cls");
		return;
	}
	LNode* p=head;
	while (NULL!= p)
	{
		p->data->showInfo();//��ʾp����Ϣ
		p = p->next;
	}
	system("pause");
	system("cls");
	return;
}

//д���ļ�
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

//��ȡ�ļ������뵥����
void workerManager:: readfile()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//��ȡʧ�ܺ�Ϊ���Ѿ��жϹ��ˣ����ﲻ�ùܡ�
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
		if (head == NULL)//��ǰû��ְ��
		{
			head = newnode;
			tail = newnode;
			tail->next = NULL;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;//β�巨���뵥����
			tail->next = NULL;
		}
		num++;
	}
	ifs.close();
}

//���ݱ�Ų���Ա���������ض�Ӧnode
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
		cout << "δ�ҵ����Ϊ" << id << "��ְ��" << endl;
		return NULL;
	}
	return q;
}

//ɾ��ְ��
void workerManager::deleteworker()
{
	cout << "��������Ҫɾ��ְ����ID" << endl;
	int id;
	cin >> id;
	LNode* q = getidNode(id);//qΪ��ɾ�����ǰ��
	if (q != NULL)
	{
		LNode* p = q->next;
		if (q == head && p == NULL)//��ʱ��Ψһ���
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else//pΪq��̣�ɾ��p
		{
			q->next = p->next;
			delete p;
			cout << "ɾ���ɹ�" << endl;
		}
	}
	else//q=NULL,�����ж�ǡ����Ҫɾ����һ�����ʱ
	{
		if (head->data->m_id == id)//��Ҫɾ����һ�����
		{
			q = head;
			head = head->next;
			delete q;
			q = NULL;
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��" << endl;
		}
	}

	//�����д���ļ�
	save();
	system("pause");
	system("cls");
}

//�޸�ְ��
void workerManager::changeworker()
{
	cout << "��������Ҫ�޸�ְ����ID" << endl;
	int id;
	cin >> id;
	int did;
	string name;
	LNode* q = getidNode(id);//qΪ���޸Ľ��ǰ��
	if (q != NULL)
	{
		LNode* p = q->next;
		if (q == head && p == NULL)//��ʱ��Ψһ���
		{
			cout << "������������Ϣ" << endl;
			cout << "������ְ�����" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "������ְ������" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "������ְ����λ" << endl;
			cout << "1:�ϰ壬2������3����ͨԱ��" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "�޸ĳɹ�" << endl;
		}
		else//pΪq��̣��޸�p
		{
			q = q->next;
			cout << "������������Ϣ" << endl;
			cout << "������ְ�����" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "������ְ������" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "������ְ����λ" << endl;
			cout << "1:�ϰ壬2������3����ͨԱ��" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "�޸ĳɹ�" << endl;
		}
	}
	else//q=NULL,�����ж�ǡ����Ҫɾ����һ�����ʱ
	{
		q = head;
		if (head->data->m_id == id)//��Ҫ�޸ĵ�һ�����
		{
			cout << "������������Ϣ" << endl;
			cout << "������ְ�����" << endl;
			cin >> id;
			q->data->m_id = id;
			cout << "������ְ������" << endl;
			cin >> name;
			q->data->m_name = name;
			cout << "������ְ����λ" << endl;
			cout << "1:�ϰ壬2������3����ͨԱ��" << endl;
			cin >> did;
			if (did == 1 || did == 2 || did == 3)
			{
				q->data->m_deptid = did;
			}
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ��" << endl;
		}
	}

	//�����д���ļ�
	save();
	system("pause");
	system("cls");
}

//������������ְ�������ض�Ӧnode
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
		cout << "δ�ҵ�����Ϊ" << name << "��ְ��" << endl;
		return NULL;
	}
	return q;
}

//���Ҳ����ְ����Ϣ
void workerManager:: getworker()
{
	cout << "�������ѯ��ʽ" << endl;
	cout << "1.����Ų�ѯ��2.��������ѯ" << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (1 == choice)
		{
			cout << "������id" << endl;
			int id;
			cin >> id;
			LNode*q = getidNode(id);
			if (q != NULL)
			{
				LNode* p = q->next;
				if (q == head && p == NULL)//��ʱ��Ψһ���
				{
					q->data->showInfo();
				}
				else//pΪq��̣�ɾ��p
				{
					p->data->showInfo();
				}
			}
			else//q=NULL,�����ж�ǡ����Ҫɾ����һ�����ʱ
			{
				if (head->data->m_id == id)//��Ҫɾ����һ�����
				{
					head->data->showInfo();
				}
			}
			goto FLAG;
		}
		else if (2 == choice)
		{
			cout << "����������" << endl;
			string name;
			cin >> name;
			LNode* q = getnameNode(name);
			if (q != NULL)
			{
				LNode* p = q->next;
				if (q == head && p == NULL)//��ʱ��Ψһ���
				{
					q->data->showInfo();
				}
				else//pΪq��̣�ɾ��p
				{
					p->data->showInfo();
				}
			}
			else//q=NULL,�����ж�ǡ����Ҫɾ����һ�����ʱ
			{
				if (head->data->m_name == name)//��Ҫɾ����һ�����
				{
					head->data->showInfo();
				}
			}
			goto FLAG;
		}
		else
		{
			cout << "��������Ч������" << endl;
		}
	}
FLAG:
	system("pause");
	system("cls");
	return;
}

//��������
void workerManager::swap(LNode* p1, LNode* p2)
{
	worker* temp;
	temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}

//����ְ��
void workerManager::sortworker()
{
	cout << "����������ʽ" << endl;
	cout << "1.���������2.����Ž���" << endl;
	int choice = 0;
	cin >>choice;
	if (choice == 1)
	{
		LNode* min;//��¼id��С��node
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
		LNode* max;//��¼id����node
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
		cout << "����������" << endl;
	}
	//�����ļ�
	save();
	system("pause");
	system("cls");
}

void workerManager::distory()
{
	cout << "ȷ��Ҫ����ļ���" << endl;
	cout << "1.ȷ��" << endl;
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
		cout << "ȡ�����" << endl;
	}
	save();
	system("pause");
	system("cls");
}