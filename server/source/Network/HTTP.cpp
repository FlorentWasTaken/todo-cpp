#include "HTTP.hpp"

todo::HTTP::HTTP(const short &port = 8080)
{
    tcp::acceptor acceptor(mContext, tcp::endpoint(tcp::v4(), port));

    std::cout << "HTTP server is running..." << std::endl;
    while (getRunning())
    {
        tcp::socket socket(mContext);

        acceptor.accept(socket);
        if (!socket.is_open())
            continue;
        std::thread([&, socket = std::move(socket)]() mutable {
            session(std::move(socket));
        }).detach();
    }
    std::cout << "HTTP server closed" << std::endl;
}

/**
 * Manage clients calls.
 * @param tcp::socket | client socket
 * @return void
**/
void todo::HTTP::session(tcp::socket socket) const
{
    try
    {
        todo::HTTPresponse r = read(socket);

        socket.shutdown(tcp::socket::shutdown_send);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**
 * Write content on a socket.
 * @param tcp::socket & | socket to write on
 * @param const std::string & | response's body
 * @param const boost::beast::http::status & | response's status (e.g : 200 = ok)
 * @return void
**/
void todo::HTTP::write(tcp::socket &socket, const std::string &body, const boost::beast::http::status &status) const
{
    if (!socket.is_open())
        throw std::exception("HTTP write error : Socket isn't opened");
    boost::beast::http::response<boost::beast::http::string_body> response;

    response.result(status);
    response.set(boost::beast::http::field::server, "HTTP server");
    response.set(boost::beast::http::field::content_type, "text/plain");
    response.keep_alive(false);
    response.body() = body;
    response.prepare_payload();

    boost::beast::http::write(socket, response);
}

/**
 * Read content on a socket.
 * @param tcp::socket & | socket to read
 * @return todo::HTTPresponse
**/
todo::HTTPresponse todo::HTTP::read(tcp::socket &socket) const
{
    if (!socket.is_open())
        throw std::exception("HTTP read error : Socket isn't opened");
    boost::beast::flat_buffer buffer;
    todo::HTTPresponse r;
    boost::beast::http::request<boost::beast::http::string_body> request;

    boost::beast::http::read(socket, buffer, request);
    return r = request;
}

/**
 * Add an event when a message is received from client.
 * @param const short& code | code received (e.g : 200)
 * @param const std::string& method | method received (e.g : POST, GET, ...)
 * @param std::function<void()> func | the function to use when message is received
 * @return void
**/
void todo::HTTP::addAnswer(const short &code, const std::string &method, std::function<void()> func)
{
    mAnswers.emplace(std::make_pair(code, method), func);
}

/**
 * Remove an event for received message.
 * @param const short& code | code received (e.g : 200)
 * @param const std::string& method | method received (e.g : POST, GET, ...)
 * @return bool | true if removed, false otherwise
**/
bool todo::HTTP::removeAnswer(const short &code, const std::string &method)
{
    for (auto it = mAnswers.begin(); it != mAnswers.end();) {
        if (it->first.first == code && it->first.second == method) {
            it = mAnswers.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}