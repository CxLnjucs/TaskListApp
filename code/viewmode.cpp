#include"viewmode.h"

ViewMode viewmode;

ViewMode::ViewMode():vt(VIEW_PRIORITY){}

void ViewMode::change_vt(ViewType _vt) {
	vt = _vt;
}

void ViewMode::show() {
	switch (vt)
	{
	case VIEW_CALENDAR:
		std::cout << "VIEW_CALENDAR: TODO" << std::endl;
		//TODO
		break;

	case VIEW_PRIORITY:
		std::sort(task_list.begin(), task_list.end(), [](Task* a, Task* b) {
			return a->get_priority() > b->get_priority();
			});
		std::cout << "VIEW_PRIORITY:" << std::endl;
		for (int i = 0; i < task_list.size(); i++) {
			std::cout << task_list[i]->get_name() << "    " << "priority: ";
			switch (task_list[i]->get_priority())
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
		}
		break;

	case VIEW_DDL:
		std::sort(task_list.begin(), task_list.end(), [](Task* a, Task* b) {
			return a->get_ddl().earlier_than(b->get_ddl());
			});
		std::cout << "VIEW_DDL:" << std::endl;
		for (int i = 0; i < task_list.size(); i++) {
			std::cout << task_list[i]->get_name() << "    " 
				<< "ddl: " << task_list[i]->get_ddl().get_string_of_date() << std::endl;
		}
		break;

	case VIEW_REMINDER:
		// TODO
		// 考虑没有设置提醒时间的情况
		break;

	case VIEW_CATEGORY:
		std::cout << "VIEW_CATEGORY:" << std::endl;
		category.show();
		break;

	default:
		assert(0);
		break;
	}
}