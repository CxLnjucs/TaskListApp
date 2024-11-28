#pragma once

#include<vector>
#include<string>
#include<cassert>

#include"task.h"

class Category {
	std::vector<std::string> cat_name_list;
	std::vector<std::vector<Task*>> cat_task_list;
public:
	Category();
	int search_in_cat_name_list(std::string cat_name);
	void new_category(std::string cat_name);
	void add_task2cat(std::string cat_name, Task* task);
	void show();
	void search_task_in_category(std::string task_name, int* _i, int* _j);
	void delete_task_in_category(std::string task_name);
};

extern Category category;