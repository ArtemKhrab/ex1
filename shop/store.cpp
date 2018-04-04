#include "stdafx.h"
#include"data.h"
#include "store.h"
#include "employee.h"
#include "nlohmann\json.hpp"

using json = nlohmann::json;
using namespace std;

Store::Store(json j) {
	name = j["name"].get<string>();
	address = j["address"].get<string>();
	id = j["id"].get<string>();
	employees = new Employee[1];
	products = new Product[1];

}

Store::Store() {};

void Store::AddEmployees(json j) {
	Employee* employeesCopy = employees;
	employeesCount++;
	employees = new Employee[employeesCount];

	for (int i = 0; i < employeesCount-1; i++)
		employees[i] = employeesCopy[i];

	*(employees + employeesCount - 1) = 
		*(new Employee(j));
}

void Store::AddProduct(json j) {
	Product* productsCopy = products;
	productsCount++;
	products = new Product[productsCount];

	for (int i = 0; i < productsCount - 1; i++)
		products[i] = productsCopy[i];

	*(products + productsCount - 1) = 
		*(new Product(j));


}
void Store::DeleteProduct(string id) {
	int position = -1;

	for (int i = 0; i < productsCount; i++)

		if (products[i].GetId() == id) {
			position = i;
			break;
		}

	if (position != -1) {
		productsCount--;
		for (int i = position; i < productsCount; i++)
			products[i] = products[i + 1];
	}
}

void Store::DeleteEmployee(string id) {
	int position = -1;
	for (int i = 0; i < employeesCount; i++)
		if (employees[i].GetId() == id) {
			position = i;
			break;
		}

	if (position != -1) {
		employeesCount--;
		for (int i = position; i < employeesCount; i++)
			employees[i] = employees[i + 1];
	}
}

void Store::ShowProducts() {
	for (int i = 0; i < productsCount; i++)
		products[i].ShowProducts();
}

void Store::ShowEmployees() {
	for (int i = 0; i < employeesCount; i++)
		employees[i].ShowEmployees();
}

void Store::ShowStore() {
	cout << " name: " << name << endl;
	cout << " address: " << address << endl;
	cout << " id: " << id << endl;
	cout << " employees: " << endl;
	ShowEmployees();
	cout <<  "products: " << endl;
	ShowProducts();
}
string Store::GetName() { return name; }

string Store::GetAddress() { return address; }

string Store::GetId() { return id; }

int Store::GetProductsCount() { return productsCount; }

int Store::GetEmployeesCount() { return employeesCount; }

Product* Store::GetProduct() { return products; }

Employee* Store::GetEmployee() { return employees; }

Store::~Store(){
	delete[] employees;
	delete[] products;
}
