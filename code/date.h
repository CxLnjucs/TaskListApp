#pragma once

#include<string>

typedef struct Date {
	int year;
	int month;
	int day;
	int hour;
	int min;

	Date(int _year, int _month, int _day, int _hour, int _min):
		year(_year), month(_month), day(_day), hour(_hour), min(_min) {}
	
	Date(const Date& other): year(other.year), month(other.month), day(other.day), hour(other.hour), min(other.min) {}

	bool earlier_than(const Date& date) const {
		if (year != date.year) return year < date.year;
		if (month != date.month) return month < date.month;
		if (day != date.day) return day < date.day;
		if (hour != date.hour) return hour < date.hour;
		return min < date.min;
	}

	std::string get_string_of_date() {
		std::string str_year = std::to_string(year);
		std::string str_month = std::to_string(month);
		std::string str_day = std::to_string(day);
		std::string str_hour = std::to_string(hour);
		std::string str_min = std::to_string(min);
		return str_year + "/" + str_month + "/" + str_day + " " + str_hour + ":" + str_min;
	}

}Date;