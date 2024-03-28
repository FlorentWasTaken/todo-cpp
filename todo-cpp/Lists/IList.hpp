#pragma once
#include <iostream>
#include <list>
#include "../Tools/tool-string.hpp"
#include "../Cards/Card.hpp"

namespace todo {
	class IList {
		public:
			IList() = default;
			virtual ~IList() = default;


			virtual std::string getTitle() const = 0;
			virtual void setTitle(const std::string&) = 0;

			virtual unsigned short getPriority() const = 0;
			virtual void setPriority(const unsigned short&) = 0;

			virtual void addCard(std::shared_ptr<ICard>&) = 0;
			virtual void removeCard(std::shared_ptr<ICard>&) = 0;

			virtual std::string getUUID() const = 0;
			virtual unsigned int getDBiD() const = 0;
			virtual void setDBiD(const unsigned int&) = 0;
	};

	class AList : public IList {
		public:
			AList();
			virtual ~AList() = default;


			std::string getTitle() const;
			void setTitle(const std::string&);

			unsigned short getPriority() const;
			void setPriority(const unsigned short&);

			void addCard(std::shared_ptr<ICard>&);
			void removeCard(std::shared_ptr<ICard>&);

			std::string getUUID() const;
			unsigned int getDBiD() const;
			void setDBiD(const unsigned int&);

		private:
			std::string mTitle = "";
			unsigned short mPriority = 0;
			std::list<std::shared_ptr<ICard>> mCards;
			std::string mUUID = "";
			unsigned int mDBiD = 0;
	};
}