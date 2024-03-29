// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix<double> random;
	random.print();
	Matrix<int> test1(2, 2);
	test1.setAt(1, 1, 5);
	test1.setAt(1, 2, 3);
	test1.setAt(2, 1, 4);
	test1.setAt(2, 2, 1);
	test1.print();
	test1.transpose();
	test1.print();
	Matrix<int> test2(2, 3);
	test2.setAt(1, 1, 11);
	test2.setAt(1, 2, 12);
	test2.setAt(1, 3, 13);
	test2.setAt(2, 1, 21);
	test2.setAt(2, 2, 22);
	test2.setAt(2, 3, 23);
	test2.print();
	test2.transpose();
	test2.print();

    return 0;
}

