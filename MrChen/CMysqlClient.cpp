#include "stdafx.h"
#include "CMysqlClient.h"


CMysqlClient::CMysqlClient()
{
	//��ʼ��MySQL ��
	/*if (mysql_library_init(sizeof(server_args) / sizeof(char *),
		server_args, server_groups))
	{
		printf("��ʼ��MySQL��ʧ��");
		return 0;
	}
*/
//	mysql_init(&m_sql);

}


CMysqlClient::~CMysqlClient()
{
	// �ͷ�MySQL��
	//mysql_library_end();
}

bool CMysqlClient::Login(const char * username, const char * passwd, const char * url)
{
	return false;
}

//const char * CMysqlClient::Query(const char * szsql)
//{
//	if (mysql_real_query(&m_sql, szsql, strlen(szsql)))
//	{
//		printf("ִ�в�ѯ����ʧ�ܡ�����ԭ��: %s\n", mysql_error(&m_sql));
//		return "NULL";
//	}
//
//	//printf("--------------------------------------------------\n");
//	//printf("��ѯ��artist���еļ�¼��\n");
//
//	MYSQL_RES* result = mysql_use_result(&m_sql);
//
//	MYSQL_ROW row;
//	unsigned int nFields;
//	unsigned int i;
//
//	nFields = mysql_num_fields(result);
//	while ((row = mysql_fetch_row(result)))
//	{
//		unsigned long *lengths;
//		lengths = mysql_fetch_lengths(result);
//		for (i = 0; i < nFields; i++)
//		{
//			char buf[MAX_PATH] = { 0 };
//			//sprintf(buf,"[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
//			return buf;
//		}
//	}
//	return "NULL";
//}
