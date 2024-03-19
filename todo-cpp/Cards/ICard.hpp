#pragma once
#include <iostream>
#include "../Tools/tool-string.hpp"

namespace todo {
	class ICard {
		public:
			ICard() = default;
			virtual ~ICard() = default;


			virtual std::string getTitle() const = 0;
			virtual void setTitle(const std::string&) = 0;

			virtual std::string getDescription() const = 0;
			virtual void setDescription(const std::string&) = 0;

			virtual unsigned int getStartDate() const = 0;
			virtual unsigned int getDueDate() const = 0;
	};

	class ACard : public ICard {
		public:
			ACard() = default;
			virtual ~ACard() = default;


			std::string getTitle() const;
			void setTitle(const std::string&);

			std::string getDescription() const;
			void setDescription(const std::string&);

			unsigned int getStartDate() const;
			unsigned int getDueDate() const;

		private:
			std::string mTitle = "";
			std::string mDescription = "";
			unsigned int mStartDate = 0;
			unsigned int mDueDate = 0;
	};
};