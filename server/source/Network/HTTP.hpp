#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include "INetwork.hpp"

using tcp = boost::asio::ip::tcp;

namespace todo {
	class HTTP : public ANetwork {
		public:
			HTTP() = default;
			HTTP(const short&);
			~HTTP() = default;

		private:
			void session(tcp::socket);

			boost::asio::io_context mContext;
	};
};
