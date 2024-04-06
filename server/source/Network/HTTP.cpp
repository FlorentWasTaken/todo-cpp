#include "HTTP.hpp"

todo::HTTP::HTTP(const short &port)
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
        boost::beast::http::request<boost::beast::http::string_body> r = read(socket);

        //write(socket, "Received data from client: " + r.body());
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
 * @return void
**/
void todo::HTTP::write(tcp::socket &socket, const std::string &body) const
{
    if (!socket.is_open())
        throw std::exception("HTTP write error : Socket isn't opened");
    boost::beast::http::response<boost::beast::http::string_body> response;

    //response.version(request.version());
    response.result(boost::beast::http::status::ok);
    response.set(boost::beast::http::field::server, "HTTP server");
    response.set(boost::beast::http::field::content_type, "text/plain");
    //response.keep_alive(request.keep_alive());
    response.body() = body;
    response.prepare_payload();

    boost::beast::http::write(socket, response);
}

/**
 * Read content on a socket.
 * @param tcp::socket & | socket to read
 * @return boost::beast::http::request<boost::beast::http::string_body>
**/
boost::beast::http::request<boost::beast::http::string_body> todo::HTTP::read(tcp::socket &socket) const
{
    if (!socket.is_open())
        throw std::exception("HTTP read error : Socket isn't opened");
    boost::beast::flat_buffer buffer;
    boost::beast::http::request<boost::beast::http::string_body> request;

    boost::beast::http::read(socket, buffer, request);
    return request;
}