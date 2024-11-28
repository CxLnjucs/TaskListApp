#pragma once

#include<iostream>
#include<cassert>
#include<algorithm>

#include"task.h"
#include"category.h"

enum ViewType{
	VIEW_CALENDAR,
	VIEW_PRIORITY,
	VIEW_DDL,
	VIEW_REMINDER,
	VIEW_CATEGORY
};

class ViewMode {
	ViewType vt;
public:                     
	ViewMode();
	void change_vt(ViewType _vt);
	void show();
};

extern ViewMode viewmode;