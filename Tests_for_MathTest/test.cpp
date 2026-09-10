#include "pch.h"
#include "Lib.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TestTask, TaskInitialization) {
	Task t1;
	int answer;
	EXPECT_TRUE(t1.num_1 >= 0);
	EXPECT_TRUE(t1.num_1 < RAND_MAX);
	EXPECT_TRUE(t1.num_2 >= 0);
	EXPECT_TRUE(t1.num_2 < RAND_MAX);
	EXPECT_TRUE(t1.operation == Operation::Add || t1.operation == Operation::Subtract || t1.operation == Operation::Multiplication || t1.operation == Operation::Division);
	switch (t1.operation) {
	case Add:
		answer = t1.num_1 + t1.num_2;
		break;
	case Subtract:
		answer = t1.num_1 - t1.num_2;
		break;
	case Multiplication:
		answer = t1.num_1 * t1.num_2;
		break;
	case Division:
		answer = t1.num_1 / t1.num_2;
		break;
	}
	EXPECT_EQ(t1.answer, answer);
}