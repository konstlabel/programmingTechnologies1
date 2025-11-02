#pragma once

#include <iostream>
#include <pqxx/pqxx>

namespace Services {
	class Service {
	protected:
	public:
		Service();

		virtual ~Service() = default;

		std::string trim(const std::string& str) const;
	};
}