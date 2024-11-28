#pragma once

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<cassert>

#include"task.h"
#include"category.h"
#include"viewmode.h"
#include"statistics.h"

class UserInterface {
	int search_in_task_list(std::string _name);
public:
	// �������ģ��
	void new_task(std::string _name, std::string _description, int _year, int _month, int _day, int _hour, int _min, Priority _priority);
	void delete_task(std::string _name);
	void finish_task(std::string _name);
	void add_tag2task(std::string _task_name, std::string _tag_name);
	void add_timeline_node2task(std::string _name, int _year, int _month, int _day, int _hour, int _min, std::string desc);
	void add_reminder2task(std::string _name, int _year, int _month, int _day, int _hour, int _min);
	void show_all_details_of_task(std::string _name);
	// ���ģ��
	void new_category(std::string cat_name);
	void delete_category(std::string cat_name); // ɾ�����ͬʱɾ���������������
	void move_task_cat2other(std::string task_name, std::string cat_name_ori, std::string cat_name_des);
	// ��ͼģ��
	void tasks_show_by_calendar();
	void tasks_show_by_priority();
	void tasks_show_by_category();
	void tasks_show_by_ddl();
	void tasks_show_by_reminder();
	// ͳ��ģ��
	void show_completion_rate();
};