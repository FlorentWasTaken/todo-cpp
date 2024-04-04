#pragma once
#include "IList.hpp"

namespace todo {
	class List : public AList {
		public:
			List() = default;
			List(const std::string&, const unsigned short&);
			~List() = default;
	};
};