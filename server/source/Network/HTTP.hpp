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

			void write(tcp::socket&, const std::string&) const;
			boost::beast::http::request<boost::beast::http::string_body> read(tcp::socket&) const;

		private:
			void session(tcp::socket) const;

			boost::asio::io_context mContext;
	};
};
