// shop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "employee.h"
#include "data.h"
#include <iostream>
#include "nlohmann\json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;


inline constexpr std::uint32_t StrRead(const char* str, std::uint32_t hash = 2166136261UL) {
	return *str ? StrRead(str + 1, (hash ^ *str) * 16777619ULL) : hash;
}
int main()
{
	Data* BD = new Data();
	string action;
	json j;

	cout << "You can use 'help' to see all commands\n";
	while (action != "exit") {
		cout << "/";
		cin >> action;
		switch (StrRead(action.c_str())) {

			case StrRead("addStore"): 
				cout << "name && address && id\n ";
				cin >> j;
				cout << BD->AddStore(j) << endl ;
				break; 

			case StrRead("deleteStore"):
				cout << "store id\n";
				cin >> j;
				cout << BD->DeleteStore(j) << endl;
				break; 

			case StrRead("showStore"):
				cout << "store id\n";
				cin >> j;
				BD->ShowStore(j);
				break;

			case StrRead("addEmployee"): 
				cout << "store  id && employer ide && name && position && salary \n";
				cin >> j;
				cout << BD->AddEmployee(j) << endl;
				break; 

			case StrRead("addProduct"):
				cout << "store id && product idp && name && price && count\n";
				cin >> j;
				cout << BD->AddProduct(j) << endl;
				break; 

			case StrRead("deleteProduct"): 
				cout << "store id && product idp\n";
				cin >> j;
				cout << BD->DeleteProduct(j) << endl;
				break; 

			case StrRead("deleteEmployee"):
				cout << "store id && employee ide\n";
				cin >> j;
				cout << BD->DeleteEmployee(j) << endl;
				break; 

			case StrRead("help"):
				cout << "	addStore\n";
				cout << "	deleteStore\n";
				cout << "	showStore\n";
				cout << "	addEmployee\n";
				cout << "	deleteEmployee\n";
				cout << "	addProduct\n";
				cout << "	deleteProduct\n";
				cout << "	exit\n";
				break;

			case StrRead("exit"): 
				BD->~Data();
				return 0;
				break; 

			default: cout << "error 404, command not found!" << endl; break; 
		};

	}
	
}

