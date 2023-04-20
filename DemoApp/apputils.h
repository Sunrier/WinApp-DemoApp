/*************************************************************************************************
	FileName : apputils.h
	FileFunc : 实现应用实用函数接口头文件
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2015-12-25 19:13:15
	Descp    : 实现应用实用函数接口
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __APPUTILS_H__
#define __APPUTILS_H__

#ifdef __cplusplus
extern "C" {  
#endif


/*设备事件*/
typedef enum
{
	DEV_CARD = 1,
	
}enumDeviceEvent;


typedef enum
{
	MENUOPT_1LINE2MENU    		= 0x0001,   /*一行两个菜单,否则一行一个菜单*/
	MENUOPT_NOI_NVERT_TITLE  	= 0x0002,   /*标题不反显*/
	MENUOPT_AUTOCHECKLEN  		= 0x0004,   /*检查菜单长度,若第二列的超过长度,在下一行显示,否则一行一个菜单*/
	MENUOPT_INORDER       		= 0x0008,   /*翻屏后菜单顺序排列,否则从1开始*/
	MENUOPT_UP_DOWN_ARROW 		= 0x0010,   /*是否显示翻页箭头*/
	MENUOPT_EXEC_FUNC     		= 0x0020,   /*是否执行立刻函数*/
	MENUOPT_RETURN        		= 0x0040,   /*选中菜单执行完函数以后直接退出菜单,否则退回到当前菜单界面*/
	MENUOPT_ENTER_RETURN  		= 0x0080,   /*按确定键退出菜单*/
}AppUtils_MenuOption;



typedef struct
{
	//unsigned char ( *EnableFunc )( void );	/* =1:显示, =0:不显示*/
	unsigned char ucReturnIndex;            	/*选中了以后返回值*/
	unsigned char *pucMenuTitle;          		/*菜单名称*/
	unsigned char (*Func)(void *Parameter); 	/*选中后执行函数*/
	void *Parameter;                			/*传入参数*/
}AppUtils_MenuItem;

/***********************************************************************************************
	FuncName : AppUtils_Restart
	FuncFunc : 重启应用
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Restart( void );

/***********************************************************************************************
	FuncName : AppUtils_Cls
	FuncFunc : 清屏
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Cls( void );

/***********************************************************************************************
	FuncName : AppUtils_ClearLine
	FuncFunc : 清除当前屏幕信息
	Input	 : unsigned char — ucLineNo	从第几行开始清屏
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ClearLine(unsigned char ucLineNo);

/***********************************************************************************************
	FuncName : AppUtils_ClearLines
	FuncFunc : 清除当前屏幕信息
	Input	 : unsigned char	— ucLineNo		从第几行开始清屏
			   unsigned char	— ucEndLineNo	从第几行结束清屏
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ClearLines(unsigned char ucLineNo,unsigned char ucEndLineNo);

/***********************************************************************************************
	FuncName : AppUtils_UserClear
	FuncFunc : 清屏
	Input	 : unsigned char	— ucLineNo	从第几行开始清屏
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_UserClear(unsigned char ucLineNo);

/***********************************************************************************************
	FuncName : AppUtils_CStrlcpy
	FuncFunc : 中文智能截断函数
	Input	 : const unsigned char *	— pucSrc	源串
               int 						— iLen		截取的长度,只拷贝最多iLen-1个字节并最后附加0x00
	Output	 : unsigned char *			— pucDest  目标串,返回已拷贝的字符数, 不包含NULL 
	Return	 : int						— 返回已拷贝的字符数
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : pucDest 与 pucSrc指针不得重叠
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_CStrlcpy(unsigned char *pucDest,const unsigned char *pucSrc,int iLen);

/***********************************************************************************************
	FuncName : AppUtils_DisplayChar
	FuncFunc : 显示一个字符提示信息
	Input	 : unsigned char 	— ucChar	输入的一个字符提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayChar(unsigned char ucChar,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayInfo
	FuncFunc : 显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayInfo(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayCenter
	FuncFunc : 居中显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
               BOOL			 	— bInvertFlag	是否反显 TRUE-是 FALSE-否
	Output	 : None
	Return	 : unsigned char	— 返回下一次显示的行
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayCenter(unsigned char *pucInputData,unsigned char ucStartLine,BOOL bInvertFlag);

/***********************************************************************************************
	FuncName : AppUtils_DisplayTitle
	FuncFunc : 居中显示标题
	Input	 : unsigned char *	— pucInputData	输入的提示信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayTitle(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DisplayLeft
	FuncFunc : 靠左显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— unsigned char	— 返回下一次显示的行
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayLeft(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayRight
	FuncFunc : 靠右显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayRight(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DispEnglish
	FuncFunc : 显示英文信息到目标位置
	Input	 : unsigned char *	— pucInputData		输入的显示的英文信息
               unsigned int 	— uiStartX			起始坐标X-纵坐标
               unsigned int 	— uiStartY			起始坐标Y-横坐标
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_DispEnglish(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY);

/***********************************************************************************************
	FuncName : AppUtils_DispChinese
	FuncFunc : 显示中文信息到目标位置
	Input	 : unsigned char *	— pucInputData		输入的显示的中文信息
               unsigned int 	— uiStartX			起始坐标X-纵坐标
               unsigned int 	— uiStartY			起始坐标Y-横坐标
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_DispChinese(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY);

/***********************************************************************************************
	FuncName : AppUtils_DispStrByColor
	FuncFunc : 显示信息到目标位置
	Input	 : unsigned char *	— pucInputData		输入的显示信息
               unsigned int 	— uiStartX			起始坐标X-纵坐标
               unsigned int 	— uiStartY			起始坐标Y-横坐标
               unsigned int 	— uiFontSize		字体大小
               unsigned long 	— ulRGBFontColor	字体颜色
               unsigned long 	— ulRGBBGColor		背景色
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DispStrByColor(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY,unsigned int uiFontSize,unsigned long ulRGBFontColor,unsigned long ulRGBBGColor);

/***********************************************************************************************
	FuncName : AppUtils_DisplayText
	FuncFunc : 显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
			   unsigned char 	— ucStartLine	起始行
			   unsigned	char	— ucDispMode	显示方式:0-左对齐 1-右对齐 2-居中
               unsigned	char	— ucInvertFlag	是否反显 TRUE-是 FALSE-否
               unsigned	char	— ucInvertColor反显颜色:低四位控制前景色:高亮|红|绿|蓝,高四位来控制背景色:高亮|红|绿|蓝
               unsigned char 	— ucCRFlag		是否自动换行 0-否 1-是
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayText(unsigned char *pucInputData,unsigned char ucStartLine,unsigned char ucDispMode,unsigned char ucInvertFlag,unsigned char ucInvertColor,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : AppUtils_FlushKbd
	FuncFunc : 清除按键缓冲区信息
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_FlushKbd( void );

/***********************************************************************************************
	FuncName : AppUtils_FlushCard
	FuncFunc : 清除卡槽缓冲区信息
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_FlushCard( void );

/***********************************************************************************************
	FuncName : AppUtils_SetTimeOut
	FuncFunc : 设置超时时间
	Input	 : unsigned long	— uiTimeout	输入设置的超时时间(S)
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-23 10:01:12
	Descp    : 秒
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_SetTimeOut(unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetTimeOut
	FuncFunc : 获取超时时间
	Input	 : None
	Output	 : unsigned int	*	— puiTimeout	输出设置的超时时间(S)
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-23 10:01:12
	Descp    : 秒
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTimeOut(unsigned int *puiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_WaitKey
	FuncFunc : 等待按键
	Input	 : unsigned long	— ulTimeout		输入超时时间(秒)
	Output	 : None
	Return	 : unsigned char *	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WaitKey(unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_WaitKeyMill
	FuncFunc : 等待按键
	Input	 : unsigned long	— ulTimeout	输入超时时间(毫秒)
	Output	 : None
	Return	 : unsigned char *	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WaitKeyMill(unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_Delay
	FuncFunc : 等待超时
	Input	 : unsigned long	— ulMSec	输入超时时间(毫秒)
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Delay(unsigned long ulMSec);

/***********************************************************************************************
	FuncName : AppUtils_MillSec
	FuncFunc : 获取当前的毫秒数
	Input	 : None
	Output	 : None
	Return	 : unsigned long	— ulMillSec	输出经过的毫秒数
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned long AppUtils_MillSec( void );

/***********************************************************************************************
	FuncName : AppUtils_Printf
	FuncFunc : 显示显示信息
	Input	 : char *			— pFmt			格式化字符串
	Output	 : None
 	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Printf(char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_Warning
	FuncFunc : 显示提示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
	Output	 : None
	Return	 : unsigned char *	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : 默认5秒
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Warning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_WarningEx
	FuncFunc : 显示提示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
		       unsigned long	— ulTimeout	输入超时时间(秒)
	Output	 : None
	Return	 : unsigned char *	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WarningEx(unsigned char *pucInputData,unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_FormatWarning
	FuncFunc : 显示提示信息
	Input	 : char *			— pFmt			格式化字符串
	Output	 : None
	Return	 : unsigned char 	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatWarning(char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_FormatWarningEx
	FuncFunc : 显示提示信息
	Input	 : unsigned char    — ucTimerFlag	    输入是否支持超时 0-不支持 1-支持
			   unsigned long	— ulInputSeconds	输入设置的超时时间(S)
	           char *			— pFmt				格式化字符串
	Output	 : None
	Return	 : unsigned char 	— ucKey			输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : 不支持超时
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatWarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_FormatDisp
	FuncFunc : 显示显示信息
	Input	 : char *			— pFmt			格式化字符串
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : 自动换行
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatDisp(char *pFmt,...);

/***********************************************************************************************
	FuncName 	: AppUtils_DisplayAscData
	FuncFunc 	: 显示报文日志到屏幕
    Input	 	: unsigned char *	—	pucInputTitle 	显示日志标题
    			  unsigned char *	—	pucInputData	显示输入数据
	Output	 	: None
	Return	 	: unsigned char		— 成功,返回APPUTILS_SUCCESS
									— 失败,返回APPUTILS_FAILURE
	Author		: Sunrier
	Date     	: 2013-12-24 19:13:21
	Descp    	: None
	History  	: None
	Other    	: None
*************************************************************************************************/
unsigned char AppUtils_DisplayAscData(unsigned char *pucInputTitle,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DisplayHexData
	FuncFunc : 16进制方式显示数据到界面
	Input	 : unsigned char *	— pucInputTitle	输入的标题
			   unsigned char *	— pucInputData		输入的数据
			   unsigned int		— uiInputDataLen	输入的数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayHexData(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_SetStatus
	FuncFunc : 设置某个状态位
	Input	 : unsigned char *	— pucStatusSetted 	输入数据
		       unsigned char 	— ucStatusFlag 	输入某个位的状态值
	Output	 : unsigned char *	— pucStatusSetted 	输出数据
	Return	 : unsigned char	— 成功返回TOOL_OK(0x00)
								— 失败返回TOOL_FAIL(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_SetStatus(unsigned char *pucStatusSetted,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_ResetStatus
	FuncFunc : 复位某个状态位
	Input	 : unsigned char *	— pucStatusSetted 	输入数据
		       unsigned char 	— ucStatusFlag 	输入某个位的状态值
	Output	 : unsigned char *	— pucStatusSetted 	输出数据
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ResetStatus(unsigned char *pucStatusSetted,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_ResetUsStatus
	FuncFunc : 复位某个状态位
	Input	 : unsigned short *	— pusStatusSetted 	输入数据
		       unsigned short 	— usStatusFlag 	输入某个位的状态值
	Output	 : unsigned short *	— pusStatusSetted 	输出数据
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : 如2012
	History  : 短整型数据
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ResetUsStatus(unsigned short *pusStatusSetted,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_CheckStatus
	FuncFunc : 检测某个状态位的值是否相同
	Input	 : unsigned char	— ucStatusChecked 		输入数据
		       unsigned char 	— ucStatusFlag 		输入某个位的状态值
	Output	 : None
	Return	 : unsigned char	— 相同返回APPUTILS_SUCCESS(0x00)
								— 不相同返回APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckStatus(unsigned char ucStatusChecked,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_CheckUshortStatus
	FuncFunc : 检测某个状态位的值是否相同
	Input	 : unsigned short	— usStatusChecked 	输入数据
		       unsigned short 	— usStatusFlag 	输入某个位的状态值
	Output	 : None
	Return	 : unsigned char	— 相同返回APPUTILS_SUCCESS(0x00)
								— 不相同返回APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : 如2012
	History  : 短整型
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckUshortStatus(unsigned short usStatusChecked,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_IsNullData
	FuncFunc : 判断输入数据是否为空
	Input	 : unsigned char *	— pucInputData		输入数据
			   unsigned int *	— uiInputDataLen	输入数据的长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS 	表示为空
								— 失败,返回APPUTILS_FAILURE	表示不为空
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsNullData(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetSysDateTime
	FuncFunc : 获取系统当前日期时间
	Input	 : None
	Output	 : unsigned int *	— pucOutputData	输出的系统日期
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetSysDateTime(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetTerminalType
	FuncFunc : 获取终端类型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回对应机型,详细见enumTerminalType类型
								— 失败,返回0x00
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTerminalType( void );

/***********************************************************************************************
	FuncName : AppUtils_GetTermModuleName
	FuncFunc : 获取终端模块名称
	Input	 : None
	Output	 : unsigned char *	— pucOutputData	终端模块名称
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTermModuleName(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetTermLicense
	FuncFunc : 获取终端入网认证编号
	Input	 : None
	Output	 : unsigned char *	— pucOutputData	终端入网认证编号
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTermLicense(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetSerialNo
	FuncFunc : 获取终端序列号
	Input	 : None
	Output	 : unsigned char *	— pucOutputSerialNo	终端序列号
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetSerialNo(unsigned char *pucOutputSerialNo);

/***********************************************************************************************
	FuncName : AppUtils_GetTusn
	FuncFunc : 获取终端厂商序列号
	Input	 : None
	Output	 : unsigned char *	— pucOutputTusn		终端厂商序列号
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : 厂商唯一标识
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTusn(unsigned char *pucOutputTusn);

/***********************************************************************************************
	FuncName : AppUtils_GetRows
	FuncFunc : 获取该机型最大行数
	Input	 : None
	Output	 : None
	Return	 : unsigned char	—返回行数
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRows( void );

/***********************************************************************************************
	FuncName : AppUtils_GetColumns
	FuncFunc : 获取该机型最大列数
	Input	 : None
	Output	 : None
	Return	 : unsigned char	—返回列数
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetColumns( void );

/***********************************************************************************************
	FuncName : AppUtils_IsBigScreen
	FuncFunc : 是否是大屏幕机型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsBigScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsTouchScreen
	FuncFunc : 是否是触摸屏幕机型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsTouchScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsRotatedScreen
	FuncFunc : 是否是宽屏机型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsRotatedScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsColorScreen
	FuncFunc : 是否是彩屏机型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsColorScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsAlphaScreen
	FuncFunc : 是否是支持ALPHA键的机型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsAlphaScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInPinpad
	FuncFunc : 是否只支持内置密码键盘
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInPinpad( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInCtls
	FuncFunc : 是否只支持内置CTLS
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInCtls( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInSignature
	FuncFunc : 是否只支持内置签名板
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInSignature( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInBarCode
	FuncFunc : 是否只支持内置扫码枪
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInBarCode( void );

/***********************************************************************************************
	FuncName : AppUtils_IsMobileDevice
	FuncFunc : 是否是移动设备
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsMobileDevice( void );

/***********************************************************************************************
	FuncName : AppUtils_IsBatteryTerminal
	FuncFunc : 是否是节能终端
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 是,返回APPUTILS_SUCCESS
								— 否,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsBatteryTerminal( void );

/***********************************************************************************************
	FuncName : AppUtils_YesOrNo
	FuncFunc : 提示是否修改相关信息
	Input	 : unsigned char  * — pucMsg1,输入显示的信息1
	           unsigned char  * — pucMsg2,输入显示的信息2
	           unsigned char   —  ucInputDispFlag,输入信息是否显示标志:0-不显示 1-显示
	           unsigned char  *	— puiOutputData,输入的原数据的值
	Output	 : unsigned char  *	— puiOutputData,输出修改后的数据值
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_YesOrNo(unsigned char *pucMsg1,unsigned char *pucMsg2,unsigned char ucInputDispFlag,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : AppUtils_YesNoConfirm
	FuncFunc : 提示是否确认相关信息
	Input	 : unsigned char  * — pucTitle,输入的提示标题
			   unsigned char  * — pucMsg1,输入显示的信息1
	           unsigned char  * — pucMsg2,输入显示的信息2
	           unsigned char  *	— pucPromptMsg,输入的提示信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_YesNoConfirm(unsigned char *pucTitle,unsigned char *pucMsg1,unsigned char *pucMsg2,unsigned char *pucPromptMsg);

/***********************************************************************************************
	FuncName : AppUtils_GetText
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucMaskChr		输入的信息是否屏蔽 0-不屏蔽 非0-屏蔽
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
								— 超时,返回APPUTILS_TIMEOUT
								— 用户取消,返回APPUTILS_ESC(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示字符组成
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetText(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucMaskChr,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetTextEx
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucMaskChr		输入的信息是否屏蔽 0-不屏蔽 非0-屏蔽
			   unsigned int		— uiTimeout		输入的超时时间(S)
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : int				— 成功,输入数据的长度
					 			— 失败,-1超时
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示字符组成
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_GetTextEx(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucMaskChr,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetNum
	FuncFunc : 输入一个信息,只由数字字符组成
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
								— 超时,返回APPUTILS_TIMEOUT
								— 用户取消,返回APPUTILS_ESC(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : 输入一个数据信息,只由数字字符组成
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetNum(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetPassWord
	FuncFunc : 输入一个密码信息,输入的信息屏蔽
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucDispMode		输入的对齐方式:0x00-靠左对齐显示(默认方式) 0x01-靠右对齐显示
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回APPUTILS_FAILURE
								— 超时,返回APPUTILS_TIMEOUT
								— 用户取消,返回APPUTILS_ESC(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetPassWord(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode);

/***********************************************************************************************
	FuncName : AppUtils_GetPassWordEx
	FuncFunc : 输入一个密码信息,输入的信息屏蔽
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucDispMode		输入的对齐方式:0x00-靠左对齐显示(默认方式) 0x01-靠右对齐显示
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
					 			— 超时,返回APPUTILS_TIMEOUT
								— 用户取消,返回APPUTILS_ESC(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetPassWordEx(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode);

/***********************************************************************************************
	FuncName : AppUtils_GetAmout
	FuncFunc : 输入金额信息,只由数字字符组成
	Input	 : unsigned char 	— ucStartLine			输入的起始行数
	           unsigned char *	— pucMsgPrompt			输入显示的标题
	           unsigned char 	— ucNegativeFlag		输入金额正负标志
	           unsigned char *	— pucCurrencyName		输入的货币名称
			   unsigned char	— ucZeroAmtAllowFlag	输入的是否可以金额为0标志 TRUE-可以为全0 其它-不可以
	Output	 : unsigned char *	— pucOutputData		输出输入的金额信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : 输入一个金额信息,只由数字字符组成
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetAmout(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char ucNegativeFlag,unsigned char *pucCurrencyName,unsigned char ucZeroAmtAllowFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetIpAddress
	FuncFunc : 输入IP地址信息
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
	           unsigned char *	— pucMsgPrompt		输入显示的标题
	           unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputIP		输出IP地址
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : 输入IP地址风格的字符串，可以用#号键代替输入'.',可以接受的字符串为16字节(含NULL),
	           在第二行显示Msg中的提示信息，第三行显示和输入IP地址
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetIpAddress(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned int uiTimeout,unsigned char *pucOutputIP);

/***********************************************************************************************
	FuncName : AppUtils_GetBcd
	FuncFunc : 输入一个BCD码格式的信息
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
			   unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个BCD码格式的信息,由'0'到'9'或者'A'到'F'字符组成
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetBcd(unsigned char ucStartLine,unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetCn
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示中文字符组成
	Input	 : unsigned char 	— ucStartLine		输入的起始行数
			   unsigned char *	— pucMsgPrompt		输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示中文字符组成
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetCn(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_IsExistFile
	FuncFunc : 检查文件是否存在
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
			   unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char    — ucNullFlag  			检查的文件内容是否可以为空 0-不可以为空 1或非0-可以为空  
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsExistFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : AppUtils_CreateFile
	FuncFunc : 创建文件
	Input	 : unsigned char *	— pucInputFilePathName	输入创建的文件路径
		       unsigned char *	— pucInputFileName		输入创建的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS(0x00)
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 检查文件是否存在,如果不存在就创建文件
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CreateFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : AppUtils_RemoveDir
	FuncFunc : 删除指定文件
	Input	 : unsigned char *	— pucInputDelFilePath	输入删除的文件目录路径
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_RemoveDir(unsigned char *pucInputDelFilePath);

/***********************************************************************************************
	FuncName : AppUtils_RemoveFile
	FuncFunc : 删除指定文件
	Input	 : unsigned char *	— pucInputDelFilePath	输入删除的文件目录路径
			   unsigned char *	— pucInputDelFileName	输入删除的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_RemoveFile(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : AppUtils_AppendInfoToFile
	FuncFunc : 将信息以字符串或十六进制格式保存到文件
	Input	 : unsigned char	— ucInputSystemFlag	输入的系统格式:0-Windows换行符(0x0D 0x0A)	其它-Linux/Unix,换行符(0x0A)
	           unsigned char	— ucInputFileModeFlag	输入的保存文件模式:0-追加	其它-覆盖
			   unsigned char *	— pucInputFilePathName	输入保存的文件路径
			   unsigned char *	— pucInputFileName		输入保存的文件名
			   unsigned char    — ucFileFlag			输入保存文件附加标志
			   											0x00-无附加信息
			   											ucFileFlag&0x01-保存的文件名加入日期后缀
			   											ucFileFlag&0x02-保存的文件信息加入日期时间信息
			   											ucFileFlag&0x04-保存的文件信息加入输入的数据长度
			   unsigned char    — ucCRFlag				输入格式换行标志
			                                            ucCRFlag 0x00-不换行 
										    	        ucCRFlag&0x01-写文件信息之前先换行 
										    	        ucCRFlag&0x02-存在标题时换行 
										    		    ucCRFlag&0x04-写文件信息完换行
										    		    ucCRFlag&0x08-保存文件末尾追加分割线
		       unsigned char *	— pucTitle				输入标题信息
			   unsigned char *	— pucInputData			输入数据
		       unsigned int		— uiInputDataLen		输入数据长度
		       unsigned char	— ucFormatFlag  		存储数据的格式 0-ASC 1-HEX 2-HEX和ASC 3-只显示可显示字符 其它值-ASC
		       unsigned int		— uiLineMaxNum			输入每行显示最大个数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : 如:ucCRFlag=0x06-写文件信息之前先换行和写文件信息完都换行,一行最大长度4096
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendInfoToFile(unsigned char ucInputSystemFlag,unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,
						unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : AppUtils_GetNumberOfRecords
	FuncFunc : 获取文件记录数
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入文件记录的大小
	Output	 : unsigned long *	— pulRecordNumber		输出文件记录数
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetNumberOfRecords(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName : AppUtils_GetRecordByIndex
	FuncFunc : 根据相关交易记录索引获取记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入的文件名
			   unsigned int		— uiRecordLength		输入记录大小
			   unsigned int		— uiRecordIndex		输入记录索引
	Output	 : unsigned char *	— pucRecord			输出交易记录
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucRecord,unsigned int uiRecordLength,unsigned int uiRecordIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetTransRecByIdx
	FuncFunc : 根据索引获取交易记录
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入记录大小
			   unsigned int		— uiRecordIndex		输入记录索引
	Output	 : void *			— pRecord				输出交易记录
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTransRecByIdx(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,void *pRecord,unsigned int uiRecordIndex);

/***********************************************************************************************
	FuncName : AppUtils_UpdateRecordByIndex
	FuncFunc : 更新指定索引的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char *	— pucInputData			输入更新的某条索引记录信息
		       unsigned long    — ulSize  				输入保存的数据信息大小
		       unsigned long   	— ulIndex  				输入更新的文件记录索引号
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetRecord
	FuncFunc : 搜索指定的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入保存的数据信息大小
		       DBInfor *    	— pDBInfor  			输入搜索的文件记录信息       
	Output	 : unsigned char *	— pucOutputData			输出获取的某条索引记录信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : 根据相关交易记录信息获取整个记录信息
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_AppendFileRecord
	FuncFunc : 追加文件记录
	Input	 : unsigned char	— ucInputFileModeFlag	输入的保存文件模式			0-追加	其它-覆盖
	           unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char *	— pucInputData			输入保存的数据信息
		       unsigned long    — ulSize  				输入保存的数据信息大小
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendFileRecord(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize);

/***********************************************************************************************
	FuncName : AppUtils_AppendRecord
	FuncFunc : 追加记录
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char *	— pucInputData			输入保存的数据信息
		       unsigned long    — ulSize  				输入保存的数据信息大小
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize);

/***********************************************************************************************
	FuncName : AppUtils_UpdateRecord
	FuncFunc : 更新指定的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入保存的数据信息大小
		       DBInfor *    	— pDBInfor  			输入搜索的文件记录信息
		       unsigned char *	— pucInputData			输入更新的某条索引记录信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : 只更新指定文件记录信息,不存在指定文件信息也不追加
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DeleteRecordByIndex
	FuncFunc : 删除指定索引的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
	           unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入保存的数据信息大小
		       unsigned long   	— ulIndex  			输入删除的文件记录索引号
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DeleteRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetClock
	FuncFunc : 获取日期时间
	Input	 : None
	Output	 : unsigned char *	— pucClockData	输出的日期时间信息YYYYMMDDHHMMSS
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : 日期时间的字符串 YYYYMMDDHHMMSS
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetClock(unsigned char *pucClockData);

/***********************************************************************************************
	FuncName : AppUtils_Asc2Bcd
	FuncFunc : Asc码转换成Bcd码
	Input	 : unsigned char *	— pucAscBuf	输入的ASCII码
			   unsigned int		— iAscLength	输入的ASCII码长度
	Output	 : unsigned char *	— pucBcdBuf	输出的BCD码
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Asc2Bcd(unsigned char *pucAscBuf,unsigned char *pucBcdBuf,unsigned int uiAscLength);

/***********************************************************************************************
	FuncName : AppUtils_Bcd2Asc
	FuncFunc : Bcd码转换成Asc码
	Input	 : unsigned char *	— pucBcdBuf	输入的BCD码
			   unsigned int		— uiAscLength	输出的ASCII码长度
	Output	 : unsigned char *	— pucAscBuf	输出的ASCII码
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Bcd2Asc(unsigned char *pucBcdBuf, unsigned char *pucAscBuf,unsigned int uiAscLength);

/***********************************************************************************************
	FuncName : AppUtils_DeleteTrail
	FuncFunc : 去除某个字符串尾部所有字符
	Input	 : unsigned char 	— ucDeleteLetter	去除的字符
			   unsigned char *	— pucString		输入的字符串
	Output	 : unsigned char *	— pucString		输出的字符
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DeleteTrail(unsigned char ucDeleteLetter,unsigned char *pucString);

/***********************************************************************************************
	FuncName : AppUtils_AmountCmp
	FuncFunc : 比较两个字符串金额
	Input	 : unsigned char *	— pucAmount1	输入字符串金额1
			   unsigned char *	— pucAmount2	输入字符串金额2
	Output	 : None
	Return	 : int				— 0:pucAmount1==pucAmount2
								— >0:pucAmount1>pucAmount2
								— <0:pucAmount1<pucAmount2
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_AmountCmp(unsigned char *pucAmount1,unsigned char *pucAmount2);

/***********************************************************************************************
	FuncName : AppUtils_AddAmountPoint
	FuncFunc : 将字符串金额末尾添加小数点
	Input	 : unsigned char *	— pucInputData		输入字符串金额
	           unsigned char 	— ucTrimZeroFlag	输入末尾0是否去掉标志:0-不去掉 1-去掉
	Output	 : unsigned char *	— pucOutputData	输出带有小数点的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : 例:pucInputData=2000068,ucTrimZeroFlag=0,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=0,pucOutputData=200006.80
	              pucInputData=2000068,ucTrimZeroFlag=1,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=1,pucOutputData=200006.8
*************************************************************************************************/
unsigned char AppUtils_AddAmountPoint(unsigned char *pucInputData,unsigned char ucTrimZeroFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_TrimAmountPoint
	FuncFunc : 去掉字符串金额小数点
	Input	 : unsigned char *	— pucInputData		输入带有小数点的字符串金额
	Output	 : unsigned char *	— pucOutputData	输出的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : 例:pucInputData=20000.68,pucOutputData=2000068;pucInputData=200006.8,pucOutputData=20000680
*************************************************************************************************/
unsigned char AppUtils_TrimAmountPoint(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_AmountAdd
	FuncFunc : 两个字符串字符金额相加
	Input	 : unsigned char *	— pucAdd1		输入字符串金额1
			   unsigned char *	— pucAdd2		输入字符串金额2
			   unsigned char 	— ucMaxLen		输入字符串金额最大长度(当ucMaxLen=0时,默认ucMaxLen;其它为0<ucMaxLen<=50)
	Output	 : unsigned char *	— pucResult	输出的相加后的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 + pucSub2
	History  : None
	Other    : 例:100+203=303
*************************************************************************************************/
unsigned char AppUtils_AmountAdd(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountAddEx
	FuncFunc : 两个字符串字符金额相加
	Input	 : unsigned char *	— pucAdd1		输入字符串金额1
			   unsigned char *	— pucAdd2		输入字符串金额2
			   unsigned char 	— ucMaxLen		输入字符串金额最大长度(当ucMaxLen=0时,默认ucMaxLen;其它为0<ucMaxLen<=50)
	Output	 : unsigned char *	— pucResult	输出的相加后的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 + pucSub2
	History  : None
	Other    : 例:1.00+2.03=3.03
*************************************************************************************************/
unsigned char AppUtils_AmountAddEx(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountSub
	FuncFunc : 两个字符串字符金额相减
	Input	 : unsigned char *	— pucSub1		输入字符串金额1
			   unsigned char *	— pucSub2		输入字符串金额2
	Output	 : unsigned char *	— pucResult	输出的相减后的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 - pucSub2
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountSub(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountSubEx
	FuncFunc : 两个字符串字符金额相减
	Input	 : unsigned char *	— pucSub1		输入字符串金额1
			   unsigned char *	— pucSub2		输入字符串金额2
	Output	 : unsigned char *	— pucResult	输出的相减后的字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 - pucSub2
	History  : None
	Other    : 例:3.00+2.03=0.97
*************************************************************************************************/
unsigned char AppUtils_AmountSubEx(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountAscToString
	FuncFunc : 把一个字符串转换为字符串金额
	Input	 : unsigned char *	— pucInputAmount	输入的字符串金额(ASC格式,最大长度12位)
			   unsigned char *	— pucCurrencyName	输入货币名称
			   unsigned char 	— ucNegativeFlag	输入的金额正负标志 '-'或'D'表示负数;其它标志为正数
	Output	 : unsigned char *	— pucOutputAmount	输出字符串金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : 如输入000000012030,为正标志返回120.30
    		   如输入000000012030,为负标志返回-120.30
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountAscToString(unsigned char *pucInputAmount,unsigned char *pucCurrencyName,unsigned char ucNegativeFlag,unsigned char *pucOutputAmount);

/***********************************************************************************************
	FuncName : AppUtils_AmountAscToLong
	FuncFunc : 把一个字符串金额转换为整数金额
	Input	 : unsigned char *	— pucInputAmount	输入的字符串金额(ASC格式,最大长度12位)
	Output	 : unsigned long *	— pulOutputAmount	输出整数金额
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : 如输入000000012030,为正标志返回120.30
    		   如输入000000012030,为负标志返回-120.30
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountAscToLong(unsigned char *pucInputAmount,unsigned long *pulOutputAmount);

/***********************************************************************************************
	FuncName : AppUtils_Beep
	FuncFunc : 响铃
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Beep( void );

/***********************************************************************************************
	FuncName : AppUtils_NormalBeep
	FuncFunc : 正常响铃
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_NormalBeep( void );

/***********************************************************************************************
	FuncName : AppUtils_ErrorBeep
	FuncFunc : 报错提示响铃
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ErrorBeep( void );

/***********************************************************************************************
	FuncName : AppUtils_ErrorSound
	FuncFunc : 错误报警
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ErrorSound( void );

/***********************************************************************************************
	FuncName : AppUtils_BeepEx
	FuncFunc : 发声
	Input	 : unsigned	int 	— uiFreq,输入发声频率
			   unsigned	long 	— ulMillSec,输入发声时间间隔(MS)
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 毫秒
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_BeepEx(unsigned int uiFreq,unsigned long ulMillSec);

/***********************************************************************************************
	FuncName : AppUtils_Window
	FuncFunc : 重新画框
	Input	 : unsigned int 	— uiStartX			起始坐标X-纵坐标
               unsigned int 	— uiStartY			起始坐标Y-横坐标
               unsigned int 	— uiEndX			结束坐标X-纵坐标
               unsigned int 	— uiEndY			结束坐标Y-横坐标
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Window(unsigned int uiStartX,unsigned int uiStartY,unsigned int uiEndX,unsigned int uiEndY);

/***********************************************************************************************
	FuncName : AppUtils_SetFontSize
	FuncFunc : 设置字体大小
	Input	 : unsigned int 	— uiFontSize	字体大小
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_SetFontSize(unsigned int uiFontSize);

/***********************************************************************************************
	FuncName : AppUtils_SetFontFile
	FuncFunc : 设置字体文件
	Input	 : const unsigned char *	— pucFontFileName	字体文件名
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_SetFontFile(const unsigned char *pucFontFileName);

/***********************************************************************************************
	FuncName : AppUtils_GetFileString
	FuncFunc : 获取配置文件中字符串的值
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
			   unsigned char *	— pucInputFileName		输入文件名
			   unsigned char *	— pucInputSectionName	输入的节名
			   unsigned char *	— pucInputKeyName		输入键名
	Output	 : unsigned char *	— pucOutputKeyValue	输出的键值
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetFileString(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : AppUtils_UpdateDateTime
	FuncFunc : 获取配置文件中字符串的值
	Input	 : unsigned char *	— pNewDate		输入的日期YYYYMMDD
			   unsigned char *	— pNewTime		输入的时间HHMMSS
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateDateTime(char *pNewDate, char *pNewTime);

/***********************************************************************************************
	FuncName : AppUtils_CheckDateFormatValid
	FuncFunc : 检查日期格式是否合法(仅仅检查月日)
	Input	 : unsigned char *	— pucInputDate 输入日期(格式:MMDD)
	Output	 : None
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
								— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-21 19:00:55
	Descp    : MMDD如0213
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckDateFormatValid(unsigned char *pucInputDate);

/***********************************************************************************************
	FuncName : AppUtils_ConvertTransDateTime
	FuncFunc : 把交易日期时间转换为字符串格式(YYYYMMDD HH:MM:SS)
	Input	 : unsigned char *	— pucInputDate		输入日期 YYYYMMDD(BCD)
	           unsigned char *	— pucInputTime		输入时间 HHMMSS(BCD)
	Output	 : unsigned char *	— pucOutputData	输出的字符串日期时间信息
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : YYYYMMDD HH:MM:SS
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ConvertTransDateTime(unsigned char *pucInputDate,unsigned char *pucInputTime,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_ConvertPanByMask
	FuncFunc : 根据设置屏蔽卡号
	Input	 : unsigned char *	— pucInputPAN		输入卡号
	           unsigned char	— ucPanLen			输入卡号长度
	Output	 : unsigned char *	— pucOutputData	输出屏蔽后的卡号
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ConvertPanByMask(unsigned char *pucInputPAN,unsigned char ucPanLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_CheckEvent
	FuncFunc : 检查当前事件是否支持
	Input	 : enumDeviceEvent 	— eEvent	输入检查的当前事件
	Output	 : None
	Return	 : unsigned char	— 支持,返回APPUTILS_SUCCESS
					 			— 不支持,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
    Date     : 2015-07-28 19:00:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckEvent(enumDeviceEvent eEvent);

/***********************************************************************************************
	FuncName : AppUtils_ReadTrackEvent
	FuncFunc : 获取磁道事件信息
	Input	 : unsigned int 	— uiMaxLen					输入磁道信息最大长度
	Output	 : unsigned char *	— pucOutputData			输出磁道信息
			   unsigned int *	— puiOutputDataLen			输出磁道信息长度
	Return	 : unsigned char	— 成功,返回APPUTILS_SUCCESS
					 			— 失败,返回非APPUTILS_SUCCESS
	Author	 : Sunrier
    Date     : 2015-07-28 19:00:55
    Descp    : 磁道信息:磁道1+磁道2+磁道3
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ReadTrackEvent(unsigned int uiMaxLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_DisplayMenu
	FuncFunc : 显示菜单
	Input	 : unsigned char 				— ucStartLine			显示的起始行
			   unsigned char *				— pucMenuTitle			菜单标题
			   unsigned char 				— ucMenuOption			菜单设置状态
			   unsigned char 				— ucMenuItemMaxCnt		用户菜单选项个数
			   AppUtils_MenuItem * 			— UserMenuItem			用户菜单选项
			   unsigned int 				— uiMenuTimeout			超时时间
			   unsigned char (*)(void) * 	— CallFunc				菜单执行完后的回调处理
	Output	 : None
	Return	 : unsigned char				— 成功,返回按键值
											— 失败,返回超时(0x03)或取消(0x02)
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayMenu(unsigned char ucStartLine,unsigned char *pucMenuTitle,unsigned char ucMenuOption,unsigned char ucMenuItemMaxCnt,AppUtils_MenuItem UserMenuItem[],unsigned int uiMenuTimeout,unsigned char (*CallFunc)(void));

/***********************************************************************************************
	FuncName : AppUtils_VerifyManage
	FuncFunc : 权限管理
	Input	 : unsigned char *	— pucInputData		认证数据
			   unsigned char *	— uiInputDataLen	认证数据长度
			   unsigned char 	— ucVerifyLevel	认证等级:0x00-高级 	 0x01-一级   0x02-二级 
			   												 0x03-三级 	 0x04-四级   0x05-五级
			   												 0x06-认证级 0x07-权限级 0x08-开放
	Output	 : None
	Return	 : unsigned	char 	— 成功,返回APPUTILS_SUCCESS(0x00)
								— 失败,返回APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_VerifyManage(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucVerifyLevel);

/***********************************************************************************************
	FuncName : AppUtils_GetRevisionInfo
	FuncFunc : 获取库版本修订信息
	Input	 : unsigned int *	— puiOutputDataLen	输入修订信息的最大存储长度
	Output	 : unsigned char *	— pucOutputData	输出修订信息
	           unsigned int *	— puiOutputDataLen	输出修订信息的长度
	Return	 : unsigned	char 	— 成功,返回APPUTILS_SUCCESS(0x00)
								— 失败,返回APPUTILS_FAILURE(0x01)
								— 失败,返回APPUTILS_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRevisionInfo(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetLibVersion
	FuncFunc : 获取库版本
	Input	 : unsigned int *	— puiOutputDataLen	输入库版本的最大存储长度
	Output	 : unsigned char *	— pucOutputData	输出当前库版本
	           unsigned int *	— puiOutputDataLen	输出库版本的最大存储长度
	Return	 : unsigned	char 	— 成功,返回APPUTILS_SUCCESS(0x00)
								— 失败,返回APPUTILS_FAILURE(0x01)
								— 失败,返回APPUTILS_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetLibVersion(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

#ifdef __cplusplus   
}  

#endif

#endif





