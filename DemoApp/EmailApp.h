/*************************************************************************************************
	FileName : EmailApp.h
    FileFunc : 实现Email项目应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : 实现Email项目应用入口函数头文件
    History  : None
*************************************************************************************************/

#ifndef __EMAILAPP_H__
#define __EMAILAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	EMAILAPP_NAME				"Email测试"
#define 	EMAILAPP_FUNCTION			EMAILAPP_NAME "模拟应用软件"
#define 	EMAILAPP_VERSION			"00.00.01"
#define 	EMAILAPP_AUTHOR				APP_AUTHOR
#define 	EMAILAPP_CONTACT			APP_CONTACT
#define 	EMAILAPP_DATE				"2015-09-28 10:26:10"
#define 	EMAILAPP_DESCPTION			"Email项目应用软件"


/***********************************************************************************************
	FuncName : EmailApp_Menu
    FuncFunc : Email项目应用菜单
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2015-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif












