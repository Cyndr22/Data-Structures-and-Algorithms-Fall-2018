/*
 * Connor Steed (crs268)
 * Assignment1: Question 1
 * "main.cpp" file
 * 09/18/2018
 */

#include "myStack.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <climits>

using namespace std;

int main()
{
	cout << "***************************************************************** " << endl;
	cout << "*************** postfix mini calculator ************************* " << endl;
	cout << "***************************************************************** " << endl;


	//Todo: Create your stack

	myStack<int> stack;

	char inputItem; //User input
	bool flag = true;

	while (true)
	{
		cout << "Enter your input items. Then enter 'c' at the end of your input line!" << endl;
		cout << "Enter 'H' to halt the program at any time!" << endl;

		while (flag)
		{
			cin >> inputItem;
			if (inputItem == 'H')
			{
				cout << "***************************************************************** " << endl;
				cout << "***************************************************************** " << endl;
				cout << "***************************************************************** " << endl;
				return 0;
			}

			else if (inputItem == 'c')
			{
				//Todo:
				//1) Check if the input line is in the correct format.
				//2) If true, compute the results based on the algorithm and print for the user.
				//3) Otherwise, print a meaningful error message and pop all items of the stack.
				int count = 0;
				int result;
				while (!stack.isEmpty()) {
					if (count >= 1) {
						cout << stack.pop() << " ";
					}
					else {
						result = stack.pop();
					}
					count++;
				}
				if (count > 1) {
					cout << endl;
					cout << "Your input was formatted incorrectly, and the contacts of the stack were prited above." << endl;
					cout << "Please make your input in postfix formatting, and insert each item one at a time" << endl;
				}
				else if (count == 0) {
					cout << "The stack was empty" << endl;
				}
				else {
					cout << "The result of the calculation is: " << result << endl;
				}
				flag = false;
			}

			else if (isspace(inputItem)) //skip space characters
			{
				continue;
			}

			else if ((inputItem == '+') || (inputItem == '/')
				|| (inputItem == '-') || (inputItem == '*'))
			{
				//Todo:
				//Follow the steps mentioned in the algorithm for operators.
				int num1 = stack.pop();
				int num2 = stack.pop();
				int temp;
				switch (inputItem) {
				case('+'):
					temp = num2 + num1;
					stack.push(temp);
					break;
				case('-'):
					temp = num2 - num1;
					stack.push(temp);
					break;
				case('/'):
					temp = num2 / num1;
					stack.push(temp);
					break;
				case('*'):
					temp = num2 * num1;
					stack.push(temp);
					break;
				default:
					break;
				}
			}

			else
			{

				int num = inputItem - '0';
				if ((num >= 0) && (num <= 9))
				{
					//Todo:
					//Follow the steps mentioned in the algorithm for integer values.
					stack.push(num);
				}
				else
				{
					cout << "Invalid input line!!!" << endl;
					flag = false;
					//Todo:
					//Pop all input items
					while ((getchar() != '\n')); //flush the buffer
				}
			}
		}

		flag = true;
	}
	return 0;
}