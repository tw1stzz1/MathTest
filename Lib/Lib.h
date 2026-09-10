#pragma once
#include <random>
#include <ctime>
#include <iostream>

enum Operation {
	Add = 0,
	Subtract,
	Multiplication,
	Division
};

struct Task {
	int num_1;
	int num_2;
	int answer;
	Operation operation;

	Task();
	Task(int, int, int, char);
};

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

class MathTest;