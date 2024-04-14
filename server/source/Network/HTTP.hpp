#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <map>
#include "INetwork.hpp"

#define ERROR_CODE -1

using tcp = boost::asio::ip::tcp;

namespace todo {
	struct HTTPMessage {
		std::string body;
		std::string method;

		HTTPMessage& operator=(const boost::beast::http::request<boost::beast::http::string_body> &r) {
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
			HTTPMessage read(tcp::socket&) const;

			void addAnswer(const short&, const std::string&, std::function<HTTPMessage()>);
			bool removeAnswer(const short&, const std::string&);
			void answerClient(const HTTPMessage&, tcp::socket&) const;

		private:
			void session(tcp::socket) const;
			short getCodeFromBody(const std::string&) const;

			boost::asio::io_context mContext;
			std::map<std::pair<short, std::string>, std::function<HTTPMessage()>> mAnswers;
	};
};
