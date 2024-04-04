#pragma once
#include <iostream>

namespace todo {
	template<typename T>
	class IDatabase {
		public:
			IDatabase() = default;
			virtual ~IDatabase() = default;

			virtual void connect(const std::string&, const std::string&, const std::string&, const std::string&, const int&) = 0;
			virtual void close() = 0;
			virtual T query(const std::string&, ...) const = 0;
	};
};