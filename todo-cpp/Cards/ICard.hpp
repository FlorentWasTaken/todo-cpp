#pragma once
#include <iostream>
#include <list>
#include "../Tools/tool-string.hpp"
#include "../Labels/Label.hpp"

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
			virtual void setStartDate(const unsigned int&) = 0;
			virtual unsigned int getDueDate() const = 0;
			virtual void setDueDate(const unsigned int&) = 0;

			virtual void addLabel(std::shared_ptr<ILabel>&) = 0;
			virtual void removeLabel(std::shared_ptr<ILabel>&) = 0;

			virtual std::string getUUID() const = 0;

	};

	class ACard : public ICard {
		public:
			ACard();
			virtual ~ACard() = default;


			std::string getTitle() const;
			void setTitle(const std::string&);

			std::string getDescription() const;
			void setDescription(const std::string&);

			unsigned int getStartDate() const;
			void setStartDate(const unsigned int&);

			unsigned int getDueDate() const;
			void setDueDate(const unsigned int&);

			void addLabel(std::shared_ptr<ILabel>&);
			void removeLabel(std::shared_ptr<ILabel>&);

			std::string getUUID() const;

		private:
			std::string mTitle = "";
			std::string mDescription = "";
			unsigned int mStartDate = 0;
			unsigned int mDueDate = 0;
			std::list<std::shared_ptr<ILabel>> mLabels;
			std::string mUUID = "";
	};
};