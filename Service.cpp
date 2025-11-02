#include "Service.h"
#include "pqxx/pqxx"
#include "iostream"

using namespace Services;
using namespace std;

Service::Service() {}

std::string Service::trim(const std::string& str) const {
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
	return trimmed;
}