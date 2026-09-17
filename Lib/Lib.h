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
	Task(int min, int max, char operation_num = '\0');
};


class MathTest {
	Task* _tasks;
	int _questions_count;
	int* _user_answers;
	int _correct_answers_count;
public:
	MathTest(int questons_count);
	MathTest(int questons_count, int min, int max);
	MathTest(int questons_count, int min, int max, int operation_num);

	Task* tasks() const noexcept;
	int questions_count();
	int* get_user_answers() const noexcept;
	int correct_answers_count();

	void correct_answers_count(int);

	void create_tasks(int min = 0, int max = 0, char operation_num = '\0');
	void run();
	void question_user();
	void check_user_answer(int, int);
	void show_stat();
	char grade_test();
};

int* MathTest::get_user_answers() const noexcept {
	return _user_answers;
}

int MathTest::questions_count() {
	return _questions_count;
}

int MathTest::correct_answers_count() {
	return _correct_answers_count;
}

MathTest::MathTest(int questons_count) {
	_questions_count = questons_count;
	create_tasks();
	run();
}
MathTest::MathTest(int questons_count, int min, int max) {
	_questions_count = questons_count;
	create_tasks(min, max);
	run();
}
MathTest::MathTest(int questons_count, int min, int max, int operation_num) {
	_questions_count = questons_count;
	create_tasks(min, max, operation_num);
	run();
}


void MathTest::run() {
	std::cout << "Now you will be subjected to test" << std::endl;
	question_user();


}

void MathTest::question_user() {
	_user_answers = new int[_questions_count];
	for (int i = 0; i < _questions_count; i++) {
		char oper;
		int user_answer;
		switch (_tasks[i].operation){
		case Add:
			oper = '+';
			break;
		case Subtract:
			oper = '-';
			break;
		case Multiplication:
			oper = '*';
			break;
		case Division:
			oper = '/';
			break;
		}
		std::cout << _tasks[i].num_1 << oper << _tasks[i].num_2 << '= ';
		std::cin >> user_answer;
		_user_answers[i] = user_answer;
		std::cout << std::endl;
		system("cls");
	}
}

void MathTest::create_tasks(int min, int max, char operation_num) {
	_tasks = new Task[_questions_count];
	if(min == 0 && max == 0) {
		for (int i = 0; i < _questions_count; i++) {
			Task t;
			_tasks[i] = t;
		}
	}
	else {
		for (int i = 0; i < _questions_count; i++) {
			Task t(min, max, operation_num);
			_tasks[i] = t;
		}
	}
}

void MathTest::check_user_answer(int user_answer, int answer) {
	if (user_answer == answer) _correct_answers_count++;
}