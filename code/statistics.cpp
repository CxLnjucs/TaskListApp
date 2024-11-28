#include<vector>

#include"statistics.h"
#include"task.h"

Statistics statistics;

float Statistics::calculate_completion_rate() {
	float completed_num = 0;
	float uncompleted_num = 0;
	for (int i = 0; i < task_list.size(); i++) {
		if (task_list[i]->if_completed())completed_num++;
		else uncompleted_num++;
	}
	return completed_num / (completed_num + uncompleted_num);
}