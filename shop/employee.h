#pragma once
#include <string>
#include "nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;



class Employee
{
private:
	string position;
	string name;
	int salary;
	string id;

public:
	Employee(json);

	void ShowEmployees();

	string GetId();

	string GetPosition();

	string GetName();

	int GetSalary();

	Employee();

	~Employee();
};

