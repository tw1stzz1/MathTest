#include "Lib.h"


Task::Task() {
	num_1 = rand() % 10;
	num_2 = rand() % 10;
	operation = static_cast <Operation> (rand() % 4);
	switch (operation) {
	case Add:
		answer = num_1 + num_2;
		break;
	case Subtract:
		answer = num_1 - num_2;
		break;
	case Multiplication:
		answer = num_1 * num_2;
		break;
	case Division:
		answer = num_1 / num_2;
		break;
	}
}

Task::Task(int min, int max, char operation_num) {
	num_1 = rand() % (max - min + 1) + min;
	num_2 = rand() % (max - min + 1) + min;
	if (operation_num == '\0') {
		operation = static_cast <Operation> (rand() % 4);
	}
	else {
		operation = static_cast <Operation> (operation_num);
	}
	switch (operation) {
	case Add:
		answer = num_1 + num_2;
		break;
	case Subtract:
		answer = num_1 - num_2;
		break;
	case Multiplication:
		answer = num_1 * num_2;
		break;
	case Division:
		answer = num_1 / num_2;
		break;
	}
}