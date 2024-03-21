#pragma once
#include "ICard.hpp"

namespace todo {
	class Card : public ACard {
		public:
			Card();
			Card(const std::string&, const std::string&);
			~Card();
	};
};