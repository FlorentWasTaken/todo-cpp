#pragma once
#include <iostream>

namespace todo {
	class INetwork {
		public:
			INetwork() = default;
			virtual ~INetwork() = default;

			virtual void setRunning(const bool&) = 0;
			virtual bool getRunning() const = 0;
	};

	class ANetwork : public INetwork {
		public:
			ANetwork() = default;
			virtual ~ANetwork() = default;

			void setRunning(const bool&);
			bool getRunning() const;

		private:
			bool mRunning = true;
	};
};