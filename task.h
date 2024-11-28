#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<cassert>

#include"date.h"
#include"tag.h"
#include"timeline.h"
#include"reminder.h"

enum Priority {
	PRI_LOW,
	PRI_MIDDLE,
	PRI_HIGH
};

class Task {
	std::string name;
	std::string description;
	Date due_date;
	Priority priority;
	bool completed;
	std::vector<Tag> tags;
	Timeline timeline;
	Reminder* reminder = nullptr;

public:
	Task(std::string _name, std::string _description, int _year, int _month, int _day, int _hour, int _min, Priority _priority);
	~Task();
	void set_reminder(const Date& remind_date);
	void add_tag(Tag _tag);
	void add_timeline_node(Date date, std::string desc);
	bool if_completed();
	void mark_completed();
	std::string get_name();
	std::string get_description();
	Date get_ddl();
	int get_priority();
	std::vector<Tag> get_tags();
	Timeline get_timeline();
	Reminder* get_reminder();
};

extern std::vector<Task*> task_list;