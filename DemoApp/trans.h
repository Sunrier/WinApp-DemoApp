/*************************************************************************************************
	FileName : trans.h
    FileFunc : 实现项目应用测试接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2015-12-23 11:13:15
    Descp    : 实现项目应用测试接口函数
    History  : None
*************************************************************************************************/

#ifndef __TRANS_H__
#define __TRANS_H__

#ifdef __cplusplus
extern "C" {  
#endif


/***********************************************************************************************
	FuncName : Trans_InitConfig
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
unsigned char Trans_InitConfig( void );

/***********************************************************************************************
	FuncName : Trans_GetCfgInfor
    FuncFunc : 获取测试项目配置信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2015-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_GetCfgInfor( void );

/***********************************************************************************************
	FuncName : Trans_DisplayTransName
	FuncFunc : 显示交易类型
	Input	 : unsigned char	— ucTransType			交易类型
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-08-05 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_DisplayTransName(unsigned char ucTransType);

/***********************************************************************************************
	FuncName : Trans_EchoTesting
	FuncFunc : 回响测试交易
	Input	 : void *	— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_EchoTesting(void *pDummy);

/***********************************************************************************************
	FuncName : Trans_Help
    FuncFunc : 软件帮助菜单
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2015-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Help(void *pDummy);

/***********************************************************************************************
	FuncName : Trans_Menu
    FuncFunc : 测试应用菜单
	Input	 : void *	— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
											BANK_ABORT
											BANK_TIMEOUT
    Author	 : Sunrier
    Date     : 2015-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif








