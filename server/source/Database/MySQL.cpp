#include "MySQL.hpp"

todo::MySQL::MySQL(const std::string & host, const std::string &user, const std::string &password, const std::string &database, const int &port)
{
	connect(host, user, password, database, port);
}

todo::MySQL::~MySQL()
{
	close();
}

void todo::MySQL::connect(const std::string &host, const std::string &user, const std::string &password, const std::string &database, const int &port)
{
	if (host == "")
		throw std::invalid_argument("host is empty");
	else if (user == "")
		throw std::invalid_argument("user is empty");
	else if (database == "")
		throw std::invalid_argument("database is empty");
	mDb = mysql_init(NULL);

	if (mDb == NULL)
		throw std::exception("An error occurred during the initialization of MySQL");

	if (mysql_real_connect(mDb, host.c_str(), user.c_str(), password.c_str(), database.c_str(), port, NULL, 0) == NULL) {
		close();
		throw std::exception("An error occurred during the connection of MySQL");
	}
}

void todo::MySQL::close()
{
	if (mDb == nullptr)
		throw std::exception("Can't close MySQL database, it's not connected");
	mysql_close(mDb);
}