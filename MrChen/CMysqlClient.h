#ifndef CMysqlClient_H
#define CMysqlClient_H

#pragma once

#include "mysql.h"
class CMysqlClient
{
public:
	CMysqlClient();
	~CMysqlClient();
	bool Login(const char * username, const char * passwd, const char * url = "127.0.0.1");


	/*const char * Query(const char * szsql);*/
private:
	MYSQL m_sql;

};


#endif