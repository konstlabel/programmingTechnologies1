#include "Repository.h"

using namespace Repositories;

Repository::Repository(pqxx::connection* conn) {

	if (conn == nullptr) {
		throw std::invalid_argument("Connection pointer is null");
	}

	this->conn = conn;
}

Repository::Repository(const Repository& other) {
	
	this->conn = other.conn;
}

