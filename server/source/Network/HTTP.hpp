#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <map>
#include "INetwork.hpp"

using tcp = boost::asio::ip::tcp;

namespace todo {
	struct HTTPresponse {
		std::string body;
		std::string method;

		HTTPresponse& operator=(const boost::beast::http::request<boost::beast::http::string_body> &r) {
			body = r.body();
			method = r.method_string();
			return *this;
		};
	};

	class HTTP : public ANetwork {
		public:
			HTTP() = default;
			HTTP(const short&);
			~HTTP() = default;

			void write(tcp::socket&, const std::string&, const boost::beast::http::status&) const;
			HTTPresponse read(tcp::socket&) const;

			void addAnswer(const short&, const std::string&, std::function<void()>);
			bool removeAnswer(const short&, const std::string&);

		private:
			void session(tcp::socket) const;

			boost::asio::io_context mContext;
			std::map<std::pair<short, std::string>, std::function<void()>> mAnswers;
	};
};
