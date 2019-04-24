/******************************************************************************/
/** ģ�����ƣ�ModbusͨѶ                                                     **/
/** �ļ����ƣ�mbconfig.h                                                     **/
/** ��    ����V1.0.0                                                         **/
/** ��    �飺��������ModbusЭ��ջʹ�õ���ض���                             **/
/**--------------------------------------------------------------------------**/



#ifndef _MB_CONFIG_H
#define _MB_CONFIG_H

/*�����Ƿ�ʹ��RTU��վ���ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_RTU_MASTER_ENABLED		(0)

/*�����Ƿ�ʹ��RTU��վ���ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_RTU_SLAVE_ENABLED		(0)

/*�����Ƿ�ʹ��ASCII��վ���ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_ACSII_MASTER_ENABLED		(0)

/*�����Ƿ�ʹ��ASCII��վ���ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_ASCII_SLAVE_ENABLED		(0)

/*�����Ƿ�ʹ��TCP���������ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_TCP_SERVER_ENABLED		(0)

/*�����Ƿ�ʹ��TCP�ͻ��˹��ܣ�0Ϊ���ã�1Ϊʹ��*/
#define MB_TCP_CLIENT_ENABLED		(0)

#if MB_RTU_MASTER_ENABLED > (0)
#include "mbrtumaster.h"
#endif

#if MB_RTU_SLAVE_ENABLED > (0)
#include "mbrtuslave.h"
#endif

#if MB_TCP_CLIENT_ENABLED > (0)
#include "mbtcpclient.h"
#endif

#if MB_TCP_SERVER_ENABLED > (0)
#include "mbtcpserver.h"
#endif

#include "mbcommon.h"

#endif
/*********** (C) COPYRIGHT 1999-2016 Moonan Technology *********END OF FILE****/