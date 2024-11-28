#include"userinterface.h"

int UserInterface::search_in_task_list(std::string _name) {
	for (int i = 0; i < task_list.size(); i++) {
		if (task_list[i]->get_name() == _name) {
			return i;
		}
	}
	assert(0);
}

// 任务管理模块
void UserInterface::new_task(std::string _name, std::string _description, 
	int _year, int _month, int _day, int _hour, int _min, Priority _priority) {
	Task* task = new Task(_name, _description, _year, _month, _day, _hour, _min, _priority);
	task_list.push_back(task);
	category.add_task2cat("未分类", task);
}

void UserInterface::delete_task(std::string _name) {
	int task_list_i = search_in_task_list(_name);
	Task* task_to_delete = task_list[task_list_i];
	task_list.erase(task_list.begin() + task_list_i);
	category.delete_task_in_category(_name);
	delete task_to_delete;
}

void UserInterface::finish_task(std::string _name) {
	int task_list_i = search_in_task_list(_name);
	task_list[task_list_i]->mark_completed();
}

void UserInterface::add_tag2task(std::string _task_name, std::string _tag_name) {
	int task_list_i = search_in_task_list(_task_name);
	Tag tag(_tag_name);
	task_list[task_list_i]->add_tag(tag);
}
void UserInterface::add_timeline_node2task(std::string _name, int _year, int _month, int _day, int _hour, int _min, std::string desc) {
	int task_list_i = search_in_task_list(_name);
	Date date(_year, _month, _day, _hour, _min);
	task_list[task_list_i]->add_timeline_node(date, desc);
}

void UserInterface::add_reminder2task(std::string _name, int _year, int _month, int _day, int _hour, int _min) {
	int task_list_i = search_in_task_list(_name);
	Date remind_date(_year, _month, _day, _hour, _min);
	task_list[task_list_i]->set_reminder(remind_date);
}

void UserInterface::show_all_details_of_task(std::string _name) {
	int task_list_i = search_in_task_list(_name);
	std::cout << "name: " << task_list[task_list_i]->get_name() << std::endl;
	std::cout << "description: " << task_list[task_list_i]->get_description() << std::endl;
	std::cout << "due_date: " << task_list[task_list_i]->get_ddl().get_string_of_date() << std::endl;
	std::cout << "priority: ";
	switch (task_list[task_list_i]->get_priority())
	{
	case 0:
		std::cout << "LOW";
		break;
	case 1:
		std::cout << "MIDDLE";
		break;
	case 2:
		std::cout << "HIGH";
		break;
	default:
		assert(0);
		break;
	}
	std::cout << std::endl;

	std::cout << "completed: ";
	switch (task_list[task_list_i]->if_completed()) {
	case true:
		std::cout << "YES";
		break;
	case false:
		std::cout << "NO";
		break;
	}
	std::cout << std::endl;

	std::cout << "tags: ";
	std::vector<Tag> tags = task_list[task_list_i]->get_tags();
	for (int i = 0; i < tags.size(); i++) {
		std::cout << tags[i].get_name() << " ";
	}
	std::cout << std::endl;
	
	std::cout << "timeline:" << std::endl;
	task_list[task_list_i]->get_timeline().show();

	std::cout << "remind me at: ";
	Reminder* reminder = task_list[task_list_i]->get_reminder();
	if (reminder == nullptr) {
		std::cout << "NO REMINDER";
	}
	else {
		std::cout << reminder->get_remind_date().get_string_of_date();
	}
	std::cout << std::endl;
}


// 类别模块
void UserInterface::new_category(std::string cat_name) {
	category.new_category(cat_name);
}

void UserInterface::delete_category(std::string cat_name) {
	// TODO
}
void UserInterface::move_task_cat2other(std::string task_name, std::string cat_name_ori, std::string cat_name_des) {
	// TODO
}


// 视图模块
void UserInterface::tasks_show_by_calendar() {
	viewmode.change_vt(VIEW_CALENDAR);
	viewmode.show();
}

void UserInterface::tasks_show_by_priority() {
	viewmode.change_vt(VIEW_PRIORITY);
	viewmode.show();
}

void UserInterface::tasks_show_by_category() {
	viewmode.change_vt(VIEW_CATEGORY);
	viewmode.show();
}

void UserInterface::tasks_show_by_ddl() {
	viewmode.change_vt(VIEW_DDL);
	viewmode.show();
}

void UserInterface::tasks_show_by_reminder() {
	viewmode.change_vt(VIEW_REMINDER);
	viewmode.show();
}


// 统计模块
void UserInterface::show_completion_rate() {
	float rate = statistics.calculate_completion_rate();
	std::cout << "任务完成率为：" << 100 * rate << "%." << std::endl;
}
