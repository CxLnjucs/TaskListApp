#include"task.h"

std::vector<Task*> task_list;

Task::Task(std::string _name, std::string _description, int _year, int _month, int _day, int _hour, int _min, Priority _priority) : 
	name(_name), description(_description), due_date(_year, _month, _day, _hour, _min), 
	priority(_priority), completed(false), timeline(due_date) {}

Task::~Task() {
	if (reminder) {
		delete reminder;
		reminder = nullptr;
	}
}

void Task::add_timeline_node(Date date, std::string desc) {
	timeline.add_timeline_node(date, desc);
}

void Task::set_reminder(const Date& remind_date){
	reminder = new Reminder(remind_date);
	assert(reminder != nullptr);
}

void Task::add_tag(Tag _tag) {
	tags.push_back(_tag);
}

bool Task::if_completed() {
	return completed;
}

void Task::mark_completed() {
	completed = true;
}

std::string Task::get_name() {
	return name;
}

std::string Task::get_description() {
	return description;
}

Date Task::get_ddl() {
	return due_date;
}
int Task::get_priority() {
	return priority;
}

std::vector<Tag> Task::get_tags() {
	return tags;
}
Timeline Task::get_timeline() {
	return timeline;
}

Reminder* Task::get_reminder() {
	return reminder;
}