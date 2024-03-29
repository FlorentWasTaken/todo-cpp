#pragma once
#include <iostream>
#include "../Tools/tool-string.hpp"

namespace todo {
	struct LabelColor {
		uint8_t red = 0;
		uint8_t green = 0;
		uint8_t blue = 0;
	};

	// The labels are used in the same way as on Trello or GitHub issues.
	class ILabel {
		public:
			ILabel() = default;
			virtual ~ILabel() = default;


			virtual std::string getTitle() const = 0;
			virtual void setTitle(const std::string&) = 0;

			virtual LabelColor getColor() const = 0;
			virtual void setColor(const LabelColor&) = 0;

			virtual unsigned short getPriority() const = 0;
			virtual void setPriority(const unsigned short&) = 0;

			virtual std::string getUUID() const = 0;
			virtual unsigned int getDBiD() const = 0;
			virtual void setDBiD(const unsigned int&) = 0;
	};

	class ALabel : public ILabel {
		public:
			ALabel();
			virtual ~ALabel() = default;


			std::string getTitle() const;
			void setTitle(const std::string&);

			LabelColor getColor() const;
			void setColor(const LabelColor&);

			unsigned short getPriority() const;
			void setPriority(const unsigned short&);

			std::string getUUID() const;
			unsigned int getDBiD() const;
			void setDBiD(const unsigned int&);

		private:
			std::string mTitle = "";
			LabelColor mColor;
			unsigned short mPriority = 0;
			std::string mUUID = "";
			unsigned int mDBiD = 0;
	};
};