/*************************************************************************************************
	FileName : BaseApp.h
    FileFunc : 实现基础项目应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-06-28 18:26:10
    Descp    : 实现基础项目应用入口函数头文件
    History  : None
*************************************************************************************************/

#ifndef __BASEAPP_H__
#define __BASEAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	BASEAPP_NAME				"基础测试"
#define 	BASEAPP_FUNCTION			BASEAPP_NAME "模拟应用软件"
#define 	BASEAPP_VERSION				"00.00.01"
#define 	BASEAPP_AUTHOR				APP_AUTHOR
#define 	BASEAPP_CONTACT				APP_CONTACT
#define 	BASEAPP_DATE				"2013-06-28 18:26:10"
#define 	BASEAPP_DESCPTION			"基础项目应用软件"


/***********************************************************************************************
	FuncName : BaseApp_Menu
    FuncFunc : 基础项目应用菜单
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2013-06-28 18:26:10
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char BaseApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif












