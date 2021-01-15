/*************************************************************************************************
	FileName : app.h
    FileFunc : 实现应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : 实现应用入口函数头文件
    History  : None
*************************************************************************************************/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
extern "C" {  
#endif


/***********************************************************************************************
	FuncName : App_GetConfigPrm
    FuncFunc : 获取默认配置参数
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_GetConfigPrm( void );

/***********************************************************************************************
	FuncName : App_InitCfg
    FuncFunc : 初始化配置文件信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_InitCfg( void );

/***********************************************************************************************
	FuncName : App_SetCommCfg
    FuncFunc : 设置项目默认通讯配置信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_SetCommCfg( void );

/***********************************************************************************************
	FuncName : App_GetCommCfg
    FuncFunc : 获取项目通讯配置信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_GetCommCfg( void );

/***********************************************************************************************
	FuncName : App_Init
    FuncFunc : 初始化信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_Init( void );

/***********************************************************************************************
	FuncName : App_Help
    FuncFunc : 软件帮助菜单
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_Help( void );

/***********************************************************************************************
	FuncName : App_DrawInterface
    FuncFunc : 画软件应用界面
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_DrawInterface( void );

/***********************************************************************************************
	FuncName : App_SelectOption
    FuncFunc : 应用菜单
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_SelectOption( void );

/***********************************************************************************************
	FuncName : App_PrintWidthHexAsc
	FuncFunc : 将数据信息保存到LOG日志文件
	Input	 : unsigned char *	— pucInputTitle	输入的标题
			   unsigned char *	— pucInputData		输入的数据
			   unsigned int		— uiInputDataLen	输入的数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
	Author	 : Sunrier
	Date     : 2014-12-24 12:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_PrintWidthHexAsc(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

#ifdef __cplusplus   
}  

#endif

#endif







