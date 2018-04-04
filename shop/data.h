#pragma once
#include "store.h"
#include "nlohmann\json.hpp"

using json = nlohmann::json;

class Data {
private:

	int Search(string);

public:

	int storesCount;

	Store* stores;

	json AddStore(json);

	json DeleteStore(json);

	json AddEmployee(json);

	json AddProduct(json);

	json DeleteEmployee(json);

	json DeleteProduct(json);

	void ShowStore(json);

	Data();

	~Data();
};



