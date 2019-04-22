#pragma once

#ifndef _PARAM_H
#define _PARAM_H


//版本号
#define VER_NUM_001   20190421
#define VER_NUM_002  
#define VER_CUR_NUM   VER_NUM_001

//自定义文件目录
#define  APP_CONFIG_FILE  _T("\\App.ini")

//自定义消息
#define WM_SWITCH_VIEW						WM_USER+110
#define WM_SIZE_CHANGE                      WM_USER+111

//软件参数
typedef struct _tParam {

	int  m_VerNum; //版本号

	_tParam();

}PARAM,*PPARAM;


#define eTCP  0
#define eUDP  1
#define eSerial 2
//设备配置
typedef struct _tDeviParam 
{
	
	byte nType;

	_tDeviParam();

}DeviParam,*PDEVIPARAM;

#endif