#include <iostream>
#include "tasks.h"
#include <cstring>
using namespace std;

int main() {
	int menuSelect;

	while (1) {
		std::cout << "Select 1-14 for functions.\nSelect 0 for exit\n";
		std::cin >> menuSelect;

		switch (menuSelect) {
		case 0:;break;
		case 1: task_one(); break;
		case 2:task_two();break;
		case 3:task_three();break;
		case 4:task_four();break;
		case 5:task_five(1);break;
		case 6:task_six();break;
		case 7:task_seven();break;
		case 8:task_eight();break;
		case 9:task_nine();break;
		case 10:task_ten();break;
		case 11:task_eleven();break;
		case 12:task_twelve();break;
		//I am superstitious and haven't done number 13 :) 
		case 14:task_fourteen();break;
		default:std::cout << "Invalid argument!\n";break;

		}
		if (menuSelect == 0) {
			break;
		}

	}
	return 0;
}
