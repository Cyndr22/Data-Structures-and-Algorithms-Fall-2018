/*
 * Connor Steed (crs268)
 * Assignment1: Question 1
 * "myStack.h" file
 * 09/18/2018
 */

#ifndef STACK_H
#define STACK_H
#define MAX 1000

#include <iostream>

template <class T>
class myStack
{
private:
	int top; //An indicator that contains the current size of the stack
	T data[MAX];    //Maximum size of the stack
public:
	myStack();
	~myStack();
	void push(T x);
	T pop();
	bool isEmpty() const;
	bool isFull() const;
};

template <class T>
myStack<T>::myStack() {
	//initialize the value of the top.
	top = -1;
	for (int i = 0; i < MAX; i++) {
		data[i] = -1;
	}
}

template <class T>
void myStack<T>::push(T x)
{
	if (isFull())
	{
		//Todo:
		//print a meaningful error message
		std::cout << "The stack is full, cannot push any more elements." << std::endl;
	}
	else
	{
		//Push the item x to myStack.
		//Update the value of the top.
		top++;
		data[top] = x;
	}
}

template <class T>
T myStack<T>::pop()
{
	//Pop the top element of the stack (e.g. x).
	//update the value of the top.
	//return x.
	T x = data[top];
	data[top] = -1;
	top--;
	return x;
}

template <class T>
bool myStack<T>::isEmpty() const {
	//if empty, return true; otherwise, return false
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool myStack<T>::isFull() const {
	//if full, return true; otherwise, return false
	if (top >= MAX - 1) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
myStack<T>::~myStack() {

}

#endif  STACK_H
