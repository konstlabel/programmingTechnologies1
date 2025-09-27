#pragma once
#include "Admin.h"
#include "Vector.h"

using namespace Vectors;

namespace AdminRepositories {
	using namespace Admins;

	class AdminRepository {
		Vector<Admin> admins;

		public:
			AdminRepository();
			AdminRepository(int capacity, bool ownsObjects);
			AdminRepository(const AdminRepository& other);
			~AdminRepository();

			AdminRepository& operator =(const AdminRepository& other);
			bool operator ==(const AdminRepository& other) const;

			int getSize() const;
			int getCapacity() const;
			bool getOwnsObjects() const;

			void add(const Admin* admin);
			void add(const Admin& admin);
			void add(std::unique_ptr<Admin> admin);

			void deleteByIndex(int index);
			void deleteByAdmin(Admin* admin);

			Admin* findByIndex(int index);
			int findIndexByPointer(Admin* admin) const;
			int findIndexByAdmin(const Admin& admin) const;

			bool exists(const Admin& admin) const;
			bool isEmpty() const;

			void print() const;
	};
}