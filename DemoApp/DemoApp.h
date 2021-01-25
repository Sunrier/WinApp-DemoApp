/*************************************************************************************************
	FileName : demoapp.h
    FileFunc : 实现demo应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-08-05 18:13:15
    Descp    : 实现demo应用入口函数头文件
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __DEMOAPP_H__
#define __DEMOAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


/*DEMO应用相关信息*/
#define		DEMOAPP_APPNAME   			"DEMOAPP"					/*应用名*/
#define		DEMOAPP_APPCOMMSECNAME		"COMM"						/*应用通讯参数节名*/
#define 	DEMOAPP_DEFAULTCONFIGPATH	".\\CONFIG\\"				/*配置文件默认路径*/
#define 	DEMOAPP_CONFIGFILENAME		DEMOAPP_APPNAME ".ini"		/*应用配置文件名*/


#define 	DEMOAPP_NAME				GLOBAL_APPNAME
#define 	DEMOAPP_FUNCTION			GLOBAL_APPNAME "应用软件"
#define 	DEMOAPP_VERSION				"00.00.01"
#define 	DEMOAPP_AUTHOR				"Sunrier"
#define 	DEMOAPP_CONTACT				"Sunrier@163.com"
#define 	DEMOAPP_DATE				"2013-08-15 18:26:10"
#define 	DEMOAPP_DESCPTION			"Demo项目应用软件"


/***********************************************************************************************
	FuncName : DemoApp_InitTranCfg
    FuncFunc : 初始化配置文件信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 18:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_InitTranCfg( void );

/***********************************************************************************************
	FuncName : DemoApp_Init
    FuncFunc : Demo应用初始化
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 18:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Init(void *pDummy);

/***********************************************************************************************
	FuncName : DemoApp_Menu
    FuncFunc : Demo项目应用菜单
	Input	 : void *	— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2013-08-05 18:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif









