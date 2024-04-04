#pragma once
#include <iostream>

namespace todo {
	class IDatabase {
		public:
			IDatabase() = default;
			virtual ~IDatabase() = default;

			virtual void connect(const std::string&, const std::string&, const std::string&, const std::string&, const int&) = 0;
			virtual void close() = 0;
	};
};