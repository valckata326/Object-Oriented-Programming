#include "pch.h"
#include <iostream>
#include "Set.h"

int main()
{
	Set<char> set;
	set.insert('1');
	set.insert('2');
	set.insert('3');
	set.insert('4');
	set.insert('5');
	set.insert('6');
	set.insert('7');


	Set<char> set1;
	set1.insert('a');
	set1.insert('b');
	set1.insert('1');
	set1.insert('d');
	set1.insert('e');
	set1.insert('3');
	set1.insert('g');

	Set<char> set2;
	set2 = set.intersection(set1);
	set2.print();

	Set<char> set3;
	set3 = set.union1(set1);
	set3.print();


	system("pause");
}

