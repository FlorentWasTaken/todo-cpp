#include "MySQL.hpp"

todo::MySQL::MySQL(const std::string &host, const std::string &user, const std::string &password, const std::string &database, const int &port)
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

	if (mysql_real_connect(mDb, host.c_str(), user.c_str(), password.c_str(), database.c_str(), port, NULL, 0) == NULL) { // TODO : connect without database
		close();
        throw std::exception((std::string("An error occurred during the connection of MySQL : ") + mysql_error(mDb)).c_str());
	}
    std::cout << "MySQL : successfully connected to " << database << std::endl;
}

void todo::MySQL::close()
{
	if (mDb == nullptr)
		throw std::exception("Can't close MySQL database, it's not connected");
	mysql_close(mDb);
}

MYSQL_RES* todo::MySQL::query(const std::string &query) const
{
    if (mDb == nullptr)
        throw std::runtime_error("Can't create query : MySQL database not initialized");
    else if (mysql_query(mDb, query.c_str()) != 0)
        throw std::runtime_error("MySQL query error : " + std::string(mysql_error(mDb)));

    MYSQL_RES* result = mysql_store_result(mDb);

    if (result == nullptr)
        throw std::runtime_error("MySQL result error : " + std::string(mysql_error(mDb)));

    /*MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != nullptr) {
        unsigned int num_fields = mysql_num_fields(result);
        for (unsigned int i = 0; i < num_fields; ++i) {
            if (row[i] != nullptr) {
                std::cout << row[i] << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }*/
    mysql_free_result(result);
}


//MYSQL_RES* todo::MySQL::query(const std::string& query, ...) const {
    /*if (mDb == nullptr)
        throw std::runtime_error("Can't create query : MySQL database not initialized");

    MYSQL_STMT* stmt = mysql_stmt_init(mDb);
    if (stmt == nullptr) {
        std::cerr << "MySQL prep query error : " << mysql_error(mDb) << std::endl;
        return nullptr;
    }

    if (mysql_stmt_prepare(stmt, query.c_str(), query.size()) != 0) {
        std::cerr << "MySQL prep query error : " << mysql_error(mDb) << std::endl;
        mysql_stmt_close(stmt);
        return nullptr;
    }

    va_list args;
    va_start(args, query.c_str());
    int argIndex = 0;

    std::vector<MYSQL_BIND> bindParams;
    bindParams.reserve(countChar(query, '?'));

    for (size_t i = 0; i < query.size(); ++i) {
        if (query[i] == '?') {
            const char* param = va_arg(args, const char*);
            if (param == nullptr) {
                std::cerr << "MySQL not enough args" << std::endl;
                va_end(args);
                mysql_stmt_close(stmt);
                return nullptr;
            }

            MYSQL_BIND bindParam;
            memset(&bindParam, 0, sizeof(MYSQL_BIND));

            bindParam.buffer_type = MYSQL_TYPE_STRING;
            bindParam.buffer = (void*)param;
            bindParam.buffer_length = strlen(param);

            bindParams.push_back(bindParam);

            argIndex++;
        }
    }
    va_end(args);

    if (!bindParams.empty()) {
        if (mysql_stmt_bind_param(stmt, bindParams.data()) != 0) {
            std::cerr << "MySQL param error : " << mysql_stmt_error(stmt) << std::endl;
            mysql_stmt_close(stmt);
            return nullptr;
        }
    }

    if (mysql_stmt_execute(stmt) != 0) {
        std::cerr << "MySQL exe error : " << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return nullptr;
    }

    if (mysql_stmt_store_result(stmt) != 0) {
        std::cerr << "MySQL store error : " << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return nullptr;
    }*/

    //return mysql_stmt_result_metadata(stmt);
//}

void todo::MySQL::createDatabase(const std::string &database)
{

}

bool todo::MySQL::doesDbExists(const std::string &database) const
{
	std::string _query = "SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = '?'";
	//MYSQL_RES* res = query(_query, database); //TODO : replace by prep query

	/*if (mysql_query(mDb, checkQuery.c_str()) != 0) {
		std::cerr << "MySQL database error : " << mysql_error(conn) << std::endl;
		mysql_close(mDb);
		return false;
	}*/

	return true;
}