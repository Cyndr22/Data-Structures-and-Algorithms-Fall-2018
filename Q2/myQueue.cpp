/*
 * Connor Steed (crs268)
 * Assignment1: Question 2
 * "myQueue.cpp" file
 * 09/18/2018
 */

#include "myQueue.h"
#include <iostream>

using namespace std;

myQueue::myQueue()
{

	//initialize the value of the rear and front indicator based on your implementation.
	front = -1;
	rear = -1;
	for (int i = 0; i < MAX; i++) {
		holder[i] = -1;
	}
}


bool myQueue::push(int x)
{
	//Check if the queue is full or not.
	//If so, insert an item into the back of the myQueue.
	//Update the value of the front indicator
	//Otherwise, print a meaningful error message
	if (isEmpty()) {
		front = -1;
		rear = -1;
	}
	if (!isFull())
	{
		
		if (rear == MAX - 1) {
			if (isEmpty()) {
				front = 0;
			}
			rear = 0;
			holder[rear] = x;
			return true;
		}
		else {
			if (isEmpty()) {
				front = 0;
			}
			rear++;
			holder[rear] = x;
			return true;
		}
		
		
	}
	else
	{
		//print a meaningfull message
		cout << "The queue is full and cannot add any more elements..." << endl;
		return false;
	}
}

int myQueue::pop()
{
	//Remove the front item from the myQueue
	//Update the value of the rear indicator
	int val = holder[front];
	holder[front] = -1;
	if (front == MAX - 1) {
		front = 0;
		return val;
	}
	else {
		front++;
		return val;
	}
}

bool myQueue::isFull()
{
	//Check if the myQueue still has empty space at its rear or the front.
	bool val = false;
	//Checks for if the element after 'rear' in the list is 'front'
	if ((rear == MAX - 1 && front == 0) || front == rear + 1) {
		val = true;
	}
	return val;
}

bool myQueue::isEmpty()
{
	//Check if the myQueue is empty based on the value of the front and rear indicator.
	bool val = false;
	//Checks for if front and rear are the same index and that location is empty
	if (front == -1) {
		val = true;
	}
	return val;
}


void myQueue::print()
{
	//print all items of the myQueue.
	int count = front;
	if (count == -1 || holder[count] != -1) {
		cout << "The queue is empty...";
		return;
	}
	else {
		while (count != rear && holder[count] != -1) {
			cout << "" << holder[count] << " ";
			if (count == (MAX - 1)) {
				count = 0;
			}
			else {
				count++;
			}
		}
		if (count == -1 || holder[count] == -1) {
			cout << "The queue is empty...";
			return;
		}
		else {
			cout << "" << holder[count] << endl;
		}
	}
}
