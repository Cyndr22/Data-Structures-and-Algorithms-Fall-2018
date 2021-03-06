/*
 * Connor Steed (crs268)
 * Assignment1: Question 2
 * "main.cpp" file
 * 09/18/2018
 */

#include "myQueue.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char choice;

	cout << "***************************************************************** " << endl;
	cout << "****** Testing the implemeted queue data structure ************** " << endl;
	cout << "***************************************************************** " << endl;

	//Create your queue
	myQueue queue;

	do
	{
		cout << "Choose your task from the following options:" << endl;
		cout << "1: Push items?" << endl;
		cout << "2: Pop items?" << endl;
		cout << "3: Print items?" << endl;
		cout << "4: exit?" << endl;
		cin >> choice;
		//check if the choice has a valid value.
		if (choice == '1')
		{
			char toCheck;
			bool flag = true;
			int inputItem;
			cout << "Enter input items, C to cancel" << endl;

			while (flag)
			{
				cin >> toCheck;
				if (toCheck == 'c')
					flag = false;

				if (flag)
				{
					inputItem = toCheck - '0';
					//push the inputItem into queue.
					//Print an error message if the queue is full.
					//Set the value of the flag to false if it is already full.
					if (!queue.isFull()) {
						queue.push(inputItem);
					}
					else {
						cout << "The queue is already full, cannot push any more elements..." << endl;
						flag = false;
					}
				}
			}
			cout << "Back to the main menu!" << endl;
		}

		else if (choice == '2')
		{
			char toCheck;
			bool flag = true;
			int count = 0;
			cout << "Enter the number of items you want to pop-out, C to cancel" << endl;
			cin >> toCheck;
			if (toCheck == 'c')
				flag = false;
			count = toCheck - '0';
			while (flag)
			{
				//Check if the queue is already empty or not
				//If true, pop from the front, update the count value and print the poped item for the
				//user.
				//Otherwise, print a meaningfull error message and set the flag value to false.
				while (count > 0) {
					bool flag2 = true;
					if (!queue.isEmpty()) {
						int temp = queue.pop();
						if (temp != -1) {
							cout << "Popped Element: " << temp << endl;
						}
						count--;
					}
					else {
						cout << "The queue is already empty, cannot pop any more elements" << endl;
						count = 0;
						flag = false;
					}
				}
				flag = false;
			}
			cout << "Back to the main menu!" << endl;
		}

		else if (choice == '3')
		{
			//Print all items of the queue.
			cout << "Queue: ";
			queue.print();
			cout << endl;
		}

		else if (choice == '4')
		{
			cout << "***************************************************************** " << endl;
			cout << "***************************************************************** " << endl;
			cout << "***************************************************************** " << endl;
			return 0;
		}
		else
		{
			cout << "INVALID CHOICE " << endl;
		}
	} while (true);
}
