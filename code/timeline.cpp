#include<iostream>

#include"timeline.h"


Timeline::Timeline(const Date& _date) {
	date_list.push_back(_date);
	desc_list.push_back("任务截止");
}

void Timeline::add_timeline_node(Date date, std::string desc) {
	assert(date_list.size() > 0);
	int i = date_list.size() - 1;
	while (i >= 0 && date.earlier_than(date_list[i])) {
		i--;
	}
	date_list.insert(date_list.begin() + (i + 1), date);
	desc_list.insert(desc_list.begin() + (i + 1), desc);
}

void Timeline::show() {
	for (int i = 0; i < date_list.size(); i++) {
		std::cout << date_list[i].get_string_of_date() << " : " << desc_list[i] << std::endl;
	}
}