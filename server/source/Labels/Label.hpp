#pragma once
#include "ILabel.hpp"

namespace todo {
	class Label : public ALabel {
		public:
			Label();
			Label(const std::string&, const unsigned short&, const LabelColor&);
			~Label();
	};
};