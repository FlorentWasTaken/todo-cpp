#include "HTTP.hpp"

todo::HTTP::HTTP(const short &port)
{
    tcp::acceptor acceptor(mContext, tcp::endpoint(tcp::v4(), port));

    while (getRunning())
    {
        tcp::socket socket(mContext);

        acceptor.accept(socket);
        std::cout << "-----------" << std::endl; // duplicated requests ??
        if (socket.is_open()) {
            std::thread([&, socket = std::move(socket)]() mutable {
                session(std::move(socket));
            }).detach();
        }
        else {
            std::cerr << "Error: Failed to open socket." << std::endl;
        }
    }
}

void todo::HTTP::session(tcp::socket socket)
{
    try
    {
        if (!socket.is_open()) {
            std::cerr << "Error: Socket is not open." << std::endl;
            return;
        }
        boost::beast::flat_buffer buffer;

        boost::beast::http::request<boost::beast::http::string_body> request;
        boost::beast::http::read(socket, buffer, request);

        std::string client_data = request.body();

        boost::beast::http::response<boost::beast::http::string_body> response;
        response.version(request.version());
        response.result(boost::beast::http::status::ok);
        response.set(boost::beast::http::field::server, "Boost server");
        response.set(boost::beast::http::field::content_type, "text/plain");
        response.keep_alive(request.keep_alive());
        response.body() = "Received data from client: " + client_data;
        response.prepare_payload();

        boost::beast::http::write(socket, response);

        socket.shutdown(tcp::socket::shutdown_send);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}