#pragma once

#ifndef _PARAM_H
#define _PARAM_H


//�汾��
#define VER_NUM_001   20190421
#define VER_NUM_002  
#define VER_CUR_NUM   VER_NUM_001

//�Զ����ļ�Ŀ¼
#define  APP_CONFIG_FILE  _T("\\App.ini")

//�Զ�����Ϣ
#define WM_SWITCH_VIEW						WM_USER+110
#define WM_SIZE_CHANGE                      WM_USER+111

//�������
typedef struct _tParam {

	int  m_VerNum; //�汾��

	_tParam();

}PARAM,*PPARAM;


#define eTCP  0
#define eUDP  1
#define eSerial 2
//�豸����
typedef struct _tDeviParam 
{
	
	byte nType;

	_tDeviParam();

}DeviParam,*PDEVIPARAM;

#endif