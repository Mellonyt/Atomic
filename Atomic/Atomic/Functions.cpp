#include <random>
#include "./Functions.h"
#include "./Item.h"

int atomic::random(const int& min, const int& max) {
	std::random_device device;
	std::mt19937 mt(device());
	std::uniform_int_distribution<int> db(min, max);
	return db(mt);
}

std::string atomic::getDemandString(const atomic::Demand& demand) {
	switch (demand) {
	case atomic::Demand::NotAssigned:
		return "Not Assigned";
	case atomic::Demand::Terrible:
		return "Terrible";
	case atomic::Demand::Low:
		return "Low";
	case atomic::Demand::Normal:
		return "Normal";
	case atomic::Demand::High:
		return "High";
	case atomic::Demand::Amazing:
		return "Amazing";
	default:
		return "Unknown";
	}
}

std::vector<std::string> atomic::split(const std::string& str, const char& separator) {
	std::vector<std::string> split_items = {};
	std::string stringHolder = "";
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == separator) {
			split_items.push_back(stringHolder);
			stringHolder.clear();
			continue;
		}
		stringHolder += str[i];
	}
	if (!stringHolder.empty())
		split_items.push_back(stringHolder);
	return split_items;
}

bool atomic::isStatusSuccess(const int& status_code) {
	switch (status_code) {
	case 200:
	case 201:
	case 202:
	case 203:
	case 204:
	case 205:
	case 206:
	case 208:
	case 207:
	case 226:
		return true;
	default:
		return false;
	}
}

std::string atomic::lower(const std::string& str) {
	std::string newString = "";
	for (auto c = str.begin(); c != str.end(); ++c) {
		newString += tolower(*c);
	}
	return newString;
}

std::string atomic::upper(const std::string& str) {
	std::string newString = "";
	for (auto c = str.begin(); c != str.end(); ++c) {
		newString += toupper(*c);
	}
	return newString;
}