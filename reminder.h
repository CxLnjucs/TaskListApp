#pragma once

#include"date.h"

class Reminder {
	
	Date remind_date;

public:
	Reminder(const Date& _date);
	Date get_remind_date();
};