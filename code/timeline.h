#pragma once

#include<string>
#include<vector>
#include<cassert>

#include"date.h"


class Timeline {
	std::vector<Date> date_list;
	std::vector<std::string> desc_list;
public:
	Timeline(const Date& _date);
	void add_timeline_node(Date date, std::string desc);
	void show();
};