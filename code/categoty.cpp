#include<iostream>

#include"category.h"
#include"task.h"

Category category;

Category::Category(){
	new_category("未分类");
}

int Category::search_in_cat_name_list(std::string cat_name) {
	for (int i = 0; i < cat_name_list.size(); i++) {
		if (cat_name_list[i] == cat_name) {
			return i;
		}
	}
	assert(0);
}

void Category::new_category(std::string cat_name) {
	cat_name_list.push_back(cat_name);
	std::vector<Task*> tasks;
	cat_task_list.push_back(tasks);
}

void Category::add_task2cat(std::string cat_name, Task* task) {
	for (int i = 0; i < cat_name_list.size(); i++) {
		if (cat_name_list[i] == cat_name) {
			cat_task_list[i].push_back(task);
			break;
		}
	}
}

void Category::show() {
	for (int i = 0; i < cat_name_list.size(); i++) {
		std::cout << cat_name_list[i] << ":" << std::endl;
		for (int j = 0; j < cat_task_list[i].size(); j++) {
			std::cout << "\t" << cat_task_list[i][j]->get_name() <<std::endl;
		}
	}
}

void Category::search_task_in_category(std::string task_name, int* _i, int* _j) {
	for (int i = 0; i < cat_task_list.size(); i++) {
		for (int j = 0; j < cat_task_list[i].size(); j++) {
			if (cat_task_list[i][j]->get_name() == task_name) {
				*_i = i;
				*_j = j;
				return;
			}
		}
	}
}

void Category::delete_task_in_category(std::string task_name) {
	int i = -1, j = -1;
	search_task_in_category(task_name, &i, &j);
	assert(i != -1 && j != -1);
	cat_task_list[i].erase(cat_task_list[i].begin() + j);
}