#include<iostream>
#include<vector>

#include"userinterface.h"

using namespace std;

int main() {
	UserInterface ui;
	// 构建task1
	ui.new_task("task1", "物理实验", 2024, 10, 1, 23, 59, PRI_MIDDLE);
	ui.add_timeline_node2task("task1", 2024, 9, 30, 20, 0, "设计实验方案");

	// 构建task2 
	ui.new_task("task2", "洗衣服", 2024, 9, 30, 18, 0, PRI_LOW);
	ui.add_tag2task("task2", "普通");
	ui.add_tag2task("task2", "生活");
	ui.finish_task("task2");

	// 构建task3
	ui.new_task("task3", "到南京南站乘车", 2024, 10, 2, 15, 0, PRI_HIGH);
	ui.add_tag2task("task3", "出行");
	ui.add_reminder2task("task3", 2024, 10, 2, 13, 0);
	
	// 展示构建结果
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task1");
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task2");
	cout << endl << "############################" << endl << endl;
	ui.show_all_details_of_task("task3");
	cout << endl << "############################" << endl << endl;

	// 展示列表视图排序结果
	ui.tasks_show_by_category();
	cout << endl << "############################" << endl << endl;
	ui.tasks_show_by_ddl();
	cout << endl << "############################" << endl << endl;
	ui.tasks_show_by_priority();
	cout << endl << "############################" << endl << endl;

	return 0;
}