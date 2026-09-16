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
	MathTest(int questons_amount);
	MathTest(int questons_amount, int min, int max);
	MathTest(int questons_amount, int min, int max, int operation_num);

	Task* tasks() const noexcept;
	int questions_count();
	int* get_user_answers() const noexcept;
	int correct_answers_count();

	void tasks(Task*);
	void questions_count(int);
	void user_answers(int*);
	void correct_answers_count(int);

	void run();
	int get_questions_amount();
	void create_tasks();
	void check_user_answer();
	void show_stat();
};

int* MathTest::get_user_answers() const noexcept {
	return  _user_answers;
}

MathTest::MathTest() {

}

void MathTest::run() {

}
