#include "stdafx.h"
#include "data.h"
#include <iostream>
#include "nlohmann\json.hpp"


using namespace std;
using json = nlohmann::json;

Data::Data() {}

Data::~Data() {}

int Data::Search(string id) {
	for (int i = 0; i < storesCount; i++) {
		if (stores[i].GetId() == id) return i;
	}
	return -1;
}

json Data::AddStore(json j) {
	json status;
	if (j.count("name") == 1 && j.count("id") == 1 && j.count("address") == 1) {
		Store* storesCopy = stores;
		storesCount++;
		stores = new Store[storesCount];

		for (int i = 0; i < storesCount - 1; i++)
			stores[i] = storesCopy[i];

		stores[storesCount - 1] = *(new Store(j));

		
		status["status"] = "DONE";
	} else {
		status["status"] = "invalid json string";
	}
	return status;
}

json Data::DeleteStore(json j) {
	json status;
	if (j.count("id") == 1) {
		int pos = Search(j["id"].get<string>());
		
		if (pos != -1) {
			storesCount--;
			for (int i = pos; i < storesCount; i++)
				stores[i] = stores[i + 1];
			status["status"] = "DONE";
		}
		else
			status["status"] = "FAIL";
	}
	else {
		status["status"] = "invalid json string";
	}
	return status;
}

void Data::ShowStore(json j) {
	if (j.count("id") == 1) {
		int pos = Search(j["id"].get<string>());
		if (pos != -1) {
			stores[pos].ShowStore();
		}
	}
	
}

json Data::AddEmployee(json j) {
	json status;
	if (j.count("ide") == 1 && j.count("id") == 1 && j.count("name") == 1 && j.count("position") == 1 && j.count("salary") == 1) {
		int pos = Search(j["id"].get<string>());
		if (pos != -1) {
			stores[pos].AddEmployees(j);
			status["status"] = "DONE";
		}
		else
			status["status"] = "FAIL";
	}
	else {
		status["status"] = "invalid json string";
	}
	return status;
}

json Data::AddProduct(json j) {
	json status;
	if (j.count("idp") == 1 && j.count("id") == 1 && j.count("name") == 1 && j.count("price") == 1 && j.count("count") == 1) {
		int pos = Search(j["id"].get<string>());
		if (pos != -1) {
			stores[pos].AddProduct(j);
			status["status"] = "DONE";
		}
		else
			status["status"] = "FAIL";
	}
	else {
		status["status"] = "invalid json string";
	}
	return status;
}

json Data::DeleteEmployee(json j) {
	json status;
	if (j.count("ide") == 1 && j.count("id") == 1) {
		int pos = Search(j["id"].get<string>());
		if (pos != -1) {
			stores[pos].DeleteEmployee(j["ide"].get<string>());
			status["status"] = "DONE";
		}
		else
			status["status"] = "FAIL";
	}
	else {
		status["status"] = "invalid json string";
	}
	return status;
}

json Data::DeleteProduct(json j) {
	json status;
	if (j.count("idp") == 1 && j.count("id") == 1) {
		int pos = Search(j["id"].get<string>());
		if (pos != -1) {
			stores[pos].DeleteProduct(j["idp"].get<string>());
			status["status"] = "DONE";
		}
		else
			status["status"] = "FAIL";
	}
	else {
		status["status"] = "invalid json string";
	}
	return status;
}
