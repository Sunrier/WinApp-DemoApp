/*************************************************************************************************
	FileName : define.h
    FileFunc : 实现应用定义头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-08-05 11:13:15
    Descp    : 定义应用定义头文件
    History  : None
	Other    : None
*************************************************************************************************/
#ifndef __DEFINE_H__
#define __DEFINE_H__

#ifdef __cplusplus
extern "C" {  
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
//#include <direct.h>
#include <time.h>
#include <windows.h>

#include "Tool.h"
#include "global.h"
#include "apputils.h"
#include "wcomm.h"
#include "comm.h"
#include "app.h"
#include "trans.h"
#include "demoapp.h"
#include "baseapp.h"
#include "ftpapp.h"
#include "emailapp.h"


#pragma comment(linker, "/subsystem:console")
#pragma comment(lib,"Tool.lib")
#pragma comment(lib,"AppUtils.lib")
#pragma comment(lib,"WComm.lib")
#pragma comment(lib,"Comm.lib")


#ifdef __DEFINE_H__
#define _EXTERN
#else
#define _EXTERN   extern
#endif

_EXTERN App_Prm g_mApp;
_EXTERN Comm_Prm g_mTermCfg;
_EXTERN Trans_Prm g_mCurrTrans;

#ifdef __cplusplus   
}  

#endif

#endif







