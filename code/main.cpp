#include<iostream>
#include<vector>

#include"userinterface.h"

using namespace std;

int main() {
	UserInterface ui;
	// ����task1
	ui.new_task("task1", "����ʵ��", 2024, 10, 1, 23, 59, PRI_MIDDLE);
	ui.add_timeline_node2task("task1", 2024, 9, 30, 20, 0, "���ʵ�鷽��");

	// ����task2 
	ui.new_task("task2", "ϴ�·�", 2024, 9, 30, 18, 0, PRI_LOW);
	ui.add_tag2task("task2", "��ͨ");
	ui.add_tag2task("task2", "����");
	ui.finish_task("task2");

	// ����task3
	ui.new_task("task3", "���Ͼ���վ�˳�", 2024, 10, 2, 15, 0, PRI_HIGH);
	ui.add_tag2task("task3", "����");
	ui.add_reminder2task("task3", 2024, 10, 2, 13, 0);
	
	// չʾ�������
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task1");
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task2");
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task3");
	cout << endl << "############################" << endl << endl;

	// չʾ�б���ͼ������
	ui.tasks_show_by_category();
	cout << endl << "############################" << endl << endl;
	ui.tasks_show_by_ddl();
	cout << endl << "############################" << endl << endl;
	ui.tasks_show_by_priority();
	cout << endl << "############################" << endl << endl;

	// 展示统计功能
	ui.show_completion_rate();
	
	return 0;
}