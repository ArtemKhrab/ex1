#pragma once
#include "employee.h"
#include "product.h"
#include <iostream>
#include "nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;

using namespace std;

class Store
{
private:
	string name;
	string address;
	int employeesCount = 0;
	int productsCount = 0;
	Product* products;
	Employee* employees;
	string id;

public:

	Store(json);

	Store();

	void AddProduct(json);

	void AddEmployees(json);

	void DeleteProduct(string);

	void DeleteEmployee(string);

	void ShowProducts();

	void ShowEmployees();

	void ShowStore();

	string GetName();

	string GetAddress();

	string GetId();

	int GetEmployeesCount();

	int GetProductsCount();

	Product* GetProduct();

	Employee* GetEmployee();

	~Store();
};

