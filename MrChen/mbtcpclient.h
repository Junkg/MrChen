/******************************************************************************/
/** ģ�����ƣ�ModbusͨѶ                                                     **/
/** �ļ����ƣ�mbtcpclient.c                                                  **/
/** ��    ����V1.0.0                                                         **/
/** ��    �飺��������Modbus TCP�ͻ��˵�������Լ�����                       **/
/**           1��Modbus TCP�ͻ����û�Ӧ�õĽӿڲ�                            **/
/**           2��ʵ�ַ�����������������ɲ����䴫��Ӧ�ò�                    **/
/**--------------------------------------------------------------------------**/
/** �޸ļ�¼��                                                               **/
/**     �汾      ����              ����              ˵��                   **/
/**     V1.0.0  2016-04-17          ���Ҿ�            �����ļ�               **/
/**                                                                          **/
/******************************************************************************/

#ifndef __mbtcpclient_h
#define __mbtcpclient_h

#include "mbtcp.h"
#include "mbcommon.h"

/*���ɷ��ʷ�����������*/
uint16_t CreateAccessServerCommand(ObjAccessInfo objInfo,void *dataList,uint8_t *commandBytes);

/*�����յ��ķ�������Ӧ��Ϣ*/
void ParsingServerRespondMessage(uint8_t *recievedMessage);

#endif
/*********** (C) COPYRIGHT 1999-2016 Moonan Technology *********END OF FILE****/