#include "stdafx.h"
#include "product.h"
#include <iostream>;


Product::Product(json j){
	name = j["name"].get<string>();
	price = j["price"].get<int>();
	count = j["count"].get<int>();
	id = j["idp"].get<string>();
}
void Product::ShowProducts() {
	cout << " name:" << name <<  
			" price:" << price << 
			" count:" << count << 
			" id:" << id << endl;
}

string Product::GetId() { return id; }

int Product::GetCount() { return count; }

string Product::GetName() { return name; }

int Product::GetPrice() { return price; }

Product::Product(){}

Product::~Product(){}
