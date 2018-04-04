#pragma once
#include <string>
#include "nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;


using namespace std;
class Product {
private:
	string name;
	int price;
	int count;
	string id;
public:
	Product(json);

	string GetId();

	string GetName();

	int GetPrice();

	int GetCount();

	Product();

	~Product();

	void ShowProducts();
	
	
};

