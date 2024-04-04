#pragma once
#include "IDatabase.hpp"
#include <mysql.h>

namespace todo {
	class MySQL : public IDatabase {
		public:
			MySQL() = default;
			MySQL(const std::string&, const std::string&, const std::string&, const std::string&, const int&);
			~MySQL();

			void connect(const std::string&, const std::string&, const std::string&, const std::string&, const int&);
			void close();

		private:
			MYSQL *mDb = nullptr;
	};
};
