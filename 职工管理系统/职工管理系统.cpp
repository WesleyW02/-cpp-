#include"workerManager.h"
int main()
{
	//实例化管理者对象
	workerManager manager;
	//展示菜单成员函数
	int choice = 0;
	while (true)
	{
		manager.showMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			manager.exitSystem();
			break;
		case 1://添加职工
			manager.AddWorkers();
			break;
		case 2://显示职工
			manager.ShowWorkers();
			break;
		case 3://删除职工
			manager.deleteworker();
			break;
		case 4://修改职工
			manager.changeworker();
			break;
		case 5://查找职工
			manager.getworker();
			break;
		case 6://排序职工
			manager.sortworker();
			break;
		case 7://清空文件
			manager.distory();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
}