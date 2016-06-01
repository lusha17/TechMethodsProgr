// LR2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstring> 
using namespace std; 

void doxygen(ifstream& file)
{ 
	string str;
 	bool flag = 0; 
 	while(getline(file, str))
	{ 
 	if (str.find("/**") != string::npos) 
		flag = 1; 
	str+='\n'; 
	if (str.find("\\func") != string::npos && flag) 
	{ 
		int i  = str.find("func") + strlen("func"); 
		if (str[i] == ' ') while (str[i] == ' ') 
			i++; 
		while (str.find("*/") != i && str[i] != '\n')
		{ 
			cout << str[i]; 
			i++; 
 		} 
		cout << endl; 
 		flag = 0;	 
 	} 	 
 	}  
 } 
 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
	char  name[255]; 
 	cin >> name; 
	ifstream file(name); 
	doxygen(file); 
 	file.close(); 
	system("pause");
	return 0; 
} 

