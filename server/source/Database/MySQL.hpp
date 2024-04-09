#pragma once
#include "IDatabase.hpp"
#include "../Tools/tool-string.hpp"
#include <mysql.h>
#include <cstdarg>

namespace todo {
	class MySQL : public IDatabase<MYSQL_RES*> {
		public:
			MySQL() = default;
			MySQL(const std::string&, const std::string&, const std::string&, const std::string&, const int&);
			~MySQL();

			void connect(const std::string&, const std::string&, const std::string&, const std::string&, const int&);
			void close();
			MYSQL_RES* query(const std::string&) const;
			//MYSQL_RES* preparedQuery(const std::string&, ...) const;

		private:
			void createDatabase(const std::string&);
			bool doesDbExists(const std::string&) const;

			MYSQL *mDb = nullptr;
	};
};
