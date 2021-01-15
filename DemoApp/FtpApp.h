/*************************************************************************************************
	FileName : FtpApp.h
    FileFunc : 实现FTP项目应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2015-12-23 11:13:15
    Descp    : 实现FTP项目应用入口函数头文件
    History  : None
*************************************************************************************************/

#ifndef __FTPAPP_H__
#define __FTPAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	FTPAPP_NAME					"FTP测试"
#define 	FTPAPP_FUNCTION				FTPAPP_NAME "模拟应用软件"
#define 	FTPAPP_VERSION				"00.00.01"
#define 	FTPAPP_AUTHOR				APP_AUTHOR
#define 	FTPAPP_CONTACT				APP_CONTACT
#define 	FTPAPP_DATE					"2015-09-28 10:26:10"
#define 	FTPAPP_DESCPTION			"FTP项目应用软件"


/***********************************************************************************************
	FuncName : FtpApp_Menu
    FuncFunc : FTP项目应用菜单
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
unsigned char FtpApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif











