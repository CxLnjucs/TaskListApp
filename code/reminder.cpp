#include"reminder.h"

Reminder::Reminder(const Date& _date):remind_date(_date) {}

Date Reminder::get_remind_date() {
	return remind_date;
}