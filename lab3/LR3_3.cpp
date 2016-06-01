// LR3_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <stdlib.h> 
using namespace std; 
 
 
/** 
  \class Class of stack 
*/ 
class stack { 
 private: 
 	stack* Next; 
 	string Data; 
 
 
 public: 
 	stack() : Next(nullptr), Data("") {}; 
 	void push(string data); 
 	void get(); 
 	string pop(); 
 	~stack() { if (Next != nullptr) delete Next; } 
 } Stack; 
 
 
 /// \func Adding element 
 void stack::push(string data) { 
 	if (Next == nullptr) 
	if (Data != "") { 
		Next = new stack(); 
 	} 
 	else { 
 		Data = data; 
 		return; 
 	} 
 	Next->push(Data); 
 	Data = data; 
 } 
 
 
 /// \func Getting element 
 void stack::get() { 
 	cout << Data << endl; 
 } 
 
 
 /// \func Deleting element 
 string stack::pop() { 
 	string temp = Data; 
 	if (Next != nullptr) { 
 		Data = Next->pop(); 
 	} 
	else { 
		Data = ""; 
 	} 

 
 	return temp; 
 } 
 
 
 /** 
   \func Main function of application 
 */ 
 int main() { 
 	size_t n;       ///Number of commands 
 	string line;    ///Command name 
 	cin >> n; 
 	for (size_t i = 0; i < n; i++) { 
 		cin >> line; 
 		if (line == "add") { 
 			cin >> line; 
 			Stack.push(line); 
		} 
		else if (line == "get") 
 			Stack.get(); 
		else if (line == "del") 
 			Stack.pop(); 
 		else 
 			return 1; 
 
 
	} 
 	system("pause"); 
 	return 0; 
 } 


