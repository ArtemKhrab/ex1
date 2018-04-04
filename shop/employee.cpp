#include "stdafx.h"
#include "employee.h"
#include <iostream>


Employee::Employee(json j)
{
	position = j["position"].get<string>();	
	name = j["name"].get<string>();
	salary = j["salary"].get<int>();
	id = j["ide"].get<string>();
}
Employee::Employee() {}

void Employee::ShowEmployees()
{
	cout << " position:" << position <<
			" name:" << name <<
			" salary:" << salary <<
			" id:" << id << endl;
}

string Employee::GetId() { return id;}

string Employee::GetName() { return name; }

string Employee::GetPosition() { return position; }

int Employee::GetSalary() { return salary; }

Employee::~Employee() {}
