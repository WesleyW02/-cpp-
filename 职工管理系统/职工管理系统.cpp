#include"workerManager.h"
int main()
{
	//ʵ���������߶���
	workerManager manager;
	//չʾ�˵���Ա����
	int choice = 0;
	while (true)
	{
		manager.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			manager.exitSystem();
			break;
		case 1://���ְ��
			manager.AddWorkers();
			break;
		case 2://��ʾְ��
			manager.ShowWorkers();
			break;
		case 3://ɾ��ְ��
			manager.deleteworker();
			break;
		case 4://�޸�ְ��
			manager.changeworker();
			break;
		case 5://����ְ��
			manager.getworker();
			break;
		case 6://����ְ��
			manager.sortworker();
			break;
		case 7://����ļ�
			manager.distory();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
}