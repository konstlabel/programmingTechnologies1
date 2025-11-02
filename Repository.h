#pragma once
#include <iostream>
#include <pqxx/pqxx>

namespace Repositories {
	class Repository {
	protected:
		const pqxx::connection* conn;
	public:
		Repository(pqxx::connection* conn);

		explicit Repository(const Repository& other);

		virtual ~Repository() = default;
	};
}
