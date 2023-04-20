/*************************************************************************************************
	FileName : Tool.h
    FileFunc : 实现TOOL函数接口调用头文件
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2010-09-23 19:13:15
	Descp    : 实现工具集函数
    History  : None
    Other    : None
*************************************************************************************************/
#ifndef   __TOOL_H__   
#define   __TOOL_H__ 

#if 0 
#ifdef __cplusplus   
#define	EXPORT	extern "C"	__declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif
#else
#ifdef __cplusplus
extern "C" {
#endif

#define EXPORT
#endif

#if !defined(__32BIT__) && !defined(__64BIT__)  
#if defined(_LP64) || defined(__64BIT__) || defined(__LP64__) || defined(__x86_64__) || defined(_WIN64)
    //typedef int bool;
    typedef unsigned char uint8_t;
    typedef unsigned int uint16_t;
    typedef short int           INT16;
    typedef unsigned short int  UINT16;
    typedef int                 INT32;
	typedef unsigned int        uint32_t;
    typedef unsigned int        UINT32;
    typedef long                INT64;
    typedef unsigned long       UINT64;
   /*  64位统一定义为 __64BIT__ */
   #ifndef __64BIT__
      #define __64BIT__
   #endif
#else
    //typedef int bool;
    typedef unsigned char uint8_t;
    typedef unsigned int uint16_t;
    typedef short int           INT16;
    typedef unsigned short int  UINT16;
#ifdef _MSC_VER
#if _MSC_VER<=1200
	//typedef long                INT32;
	typedef unsigned long        uint32_t;
    //typedef unsigned long        UINT32;
//vc6使用的编译器是C90标准的，long long 型是在C99中新加入的。因此想要使用int 64 位的需要使用__int64变量即可
	typedef __int64            INT64;
    typedef unsigned __int64   UINT64;
#else
	typedef long                INT32;
	typedef unsigned long        uint32_t;
    typedef unsigned long        UINT32;
	typedef long long            INT64;
    typedef unsigned long long   UINT64;
#endif
#else
	typedef long                INT32;
	typedef unsigned long        uint32_t;
    typedef unsigned long        UINT32;
	typedef long long            INT64;
    typedef unsigned long long   UINT64;
#endif
    #ifndef __32BIT__
      #define __32BIT__
   #endif
#endif
#endif

#define TOOL_OFFSETOF(TYPE, MEMBER)   ((size_t) &((TYPE *)0)->MEMBER)

#define DB_KEY_SIZE			sizeof(DBKEY)
#define DB_MAX_RECD_LEN		20480
#define DB_MAX_LOG_LEN		2048


typedef enum
{
	LINE1 = 1,
	LINE2 ,
	LINE3 ,
	LINE4 ,
	LINE5 ,
	LINE6 ,
	LINE7 ,
	LINE8 ,
	LINE9 ,
}LineType;

/*用户按键*/
typedef enum
{
	bKEY0 = '0',
	bKEY1 = '1',
	bKEY2 = '2',
	bKEY3 = '3',
	bKEY4 = '4',
	bKEY5 = '5',
	bKEY6 = '6',
	bKEY7 = '7',
	bKEY8 = '8',
	bKEY9 = '9',
	bENTER = 0x0D,
	bBKSP = 0x08,
	bESC = 0x1B,
	bUP = 0x26,
	bDOWN = 0x28,
	bRIGHT = 0x27,
	bLEFT = 0x25,
	bKEYC = 0x26,
	bKEYD = 0x28,
	bALPHAKEY = 0x09,	/*TAB键*/
	bDEL = 0x53,
	bF1 = 0x70,
	bF2 = 0x70,
}UserKey;

/*日志级别-LOG_OFF>LOG_ERR>LOG_WARN>LOG_INFO>LOG_DEBUG>LOG_ALL*/
typedef enum _LOG_LEVEL
{
	LOG_OFF  	= 0x00,	/*关闭所有日志记录-最高级别*/
	LOG_ERROR	= 0x01,	/*描述应用程序运行中发生的错误信息*/
	LOG_WARN	= 0x02,	/*描述应用程序运行中发生的警告信息*/
	LOG_INFO 	= 0x04,	/*描述应用程序运行过程*/
	LOG_DEBUG 	= 0x08,	/*打开调试日志*/
	LOG_ALL 	= 0x10, /*打开所有日志记录*/
	LOG_MAX,
}LOG_LEVEL;

/*检查日志级别-LOG_CHECK_OFF>LOG_CHECK_ERROR>LOG_CHECK_WARN>LOG_CHECK_INFO>LOG_CHECK_DEBUG>LOG_CHECK_ALL*/
typedef enum _LOG_CHECK_LEVEL
{
	LOG_CHECK_OFF  	= 0x00,	/*关闭所有日志记录-最高级别*/
	LOG_CHECK_ERROR	= 0x01,	/*描述应用程序运行中发生的错误信息*/
	LOG_CHECK_WARN	= 0x02,	/*描述应用程序运行中发生的警告信息*/
	LOG_CHECK_INFO 	= 0x03,	/*描述应用程序运行过程*/
	LOG_CHECK_DEBUG = 0x04,	/*打开调试日志*/
	LOG_CHECK_ALL 	= 0x05, /*打开所有日志记录*/
	LOG_CHECK_MAX,
}LOG_CHECK_LEVEL;

/*主机数值字节顺序模式*/
typedef enum _ENDIAN
{
    ENDIAN_LITTLE	= 0x01,	/*小端模式(ENDIAN_LITTLE):windows小端模式*/
	ENDIAN_BIG		= 0x02, /*大端模式(ENDIAN_BIG)*/
}TOOL_ENDIAN;

/*数据类型*/
typedef enum
{
	TYPE_HEX = 1,
	TYPE_DEC,
	TYPE_BYTE,
	TYPE_WORD,
	TYPE_LONG,
	TYPE_STRING,
	TYPE_MAX,
}DATA_TYPE;

/*比较数据范围类型*/
typedef enum _COMPARE_RANGE_TYPE
{
	COMPARE_LMIN = 0x00,	/*<MIN*/
	COMPARE_LEMIN,			/*<=MIN*/
	COMPARE_GMAX,			/*>MAX*/
	COMPARE_GEMAX,			/*>=MAX*/
	COMPARE_GMIN_LMAX,		/*MIN<X<MAX*/
	COMPARE_GEMIN_LMAX,		/*MIN<=X<MAX*/
	COMPARE_GMIN_LEMAX,		/*MIN<X<=MAX*/
	COMPARE_GEMIN_LEMAX,	/*MIN<=X<=MAX*/
	COMPARE_MAX		
}COMPARE_TYPE;


/*CRC类型*/
typedef enum _CRC_MODE
{
 	CRC_MODE_CRC4_ITU = 0,
	CRC_MODE_CRC5_EPC,
	CRC_MODE_CRC5_ITU,
	CRC_MODE_CRC5_USB,
	CRC_MODE_CRC6_ITU,
	CRC_MODE_CRC7_MMC,
	CRC_MODE_CRC8,
	CRC_MODE_CRC8_ITU,
	CRC_MODE_CRC8_ROHC,
	CRC_MODE_CRC8_MAXIM,
	CRC_MODE_CRC16_IBM,
	CRC_MODE_CRC16_MAXIM,
	CRC_MODE_CRC16_USB,
	CRC_MODE_CRC16_MODBUS,
 	CRC_MODE_CRC16_CCITT,
 	CRC_MODE_CRC16_CCITT_FALSE,
 	CRC_MODE_CRC16_X25,
 	CRC_MODE_CRC16_XMODEM,
 	CRC_MODE_CRC16_DNP,
	CRC_MODE_CRC32,
	CRC_MODE_CRC32_MPEG2,
	CRC_MODE_CRC8_CUSTOM,
	CRC_MODE_CRC16_CUSTOM,
	CRC_MODE_CRC_CUSTOM,
	CRC_MODE_MAX,
}CRC_MODE;

typedef enum
{
	MONTH_1 = 1,
	MONTH_2 ,
	MONTH_3 ,
	MONTH_4 ,
	MONTH_5 ,
	MONTH_6 ,
	MONTH_7 ,
	MONTH_8 ,
	MONTH_9 ,
	MONTH_10 ,
	MONTH_11 ,
	MONTH_12 ,
	MONTH_MAX,
}MONTH_KEY;


typedef struct
{
	unsigned int uiStartOffset;
	unsigned int uiLength;
	unsigned char *pucSearchKey;
}DBInfor;

/*数据分割表*/
typedef struct
{
	unsigned int uiOffset;			/*数据起始位*/
    unsigned int uiFieldLen;		/*数据长度*/
} DataFieldTab;

typedef struct
{                                   
	unsigned long ulRecNum;		/* Number of records in the file    */
    unsigned long ulFixRecSize;	/* Size of a fixed record.          */
}DB_FILE;

typedef enum
{
  KEY_LONG = 0,
  KEY_STRING,
}DBKEYTYPE;

typedef struct __STDBKEY
{
	long	lOffset;			/*数据库要求索引结构最基本的成员变量*/
  	unsigned char ucKeyType; 	/*DBKEYTYPE*/
  	unsigned int uiLen;			/*数据长度*/
  	long	lKey;			  	/*long型索引*/
  	unsigned char aucKey[16];	/*String型索引*/
}DBKEY;

/*定义TLV*/
typedef struct _TLV
{
	int iTag;	/*tag*/
	int iLen;	/*iLen*/
	unsigned char *pucValue;	/*pucValue*/
}TLV;

/*TAG数据类型*/
typedef enum _TLV_TAGTYPE
{
  TAGTYPE_NUMERIC = 0,		/*Alpha numeric*/
  TAGTYPE_BINARY,			/*Binary*/
  TAGTYPE_BCDNUMBER,		/*BCD*/
  TAGTYPE_ALPHANUMERIC,		/*Alpha numeric or special character*/
}TLV_TAGTYPE;

/*TAG数据来源*/
typedef enum _TLV_TAGSOURCE
{
  TAGSOURCE_ICC = 0,		/*IC卡*/
  TAGSOURCE_ISSUER,			/*发卡行*/
  TAGSOURCE_TERMINAL,		/*终端*/
  TAGSOURCE_ISSUERTERMINAL,	/*发卡行或终端*/
}TLV_TAGSOURCE;

/*EMV TLV信息结构定义*/
typedef struct _TLVTAG_PRM
{
	int iTag;								/*标签整型值*/
	unsigned char aucTag[4+1];				/*标签字符串值*/
	int iTagLen;							/*标签的长度*/
	int iTagValueLen;						/*标签值的长度*/
	unsigned char ucTagValueLenVarFlag;		/*标签值的长度可变标志:0-不可变,固定 非0-可变*/
	int iTagValueMinLen;					/*标签值的最小长度*/
	TLV_TAGTYPE	   ucTagType;				/*标签类型:参考TLV_TAGTYPE*/
	TLV_TAGSOURCE  ucTagSource;				/*标签来源:参考TLV_TAGSOURCE*/
	unsigned char ucTemplateFlag;			/*是否模板标志:0-否 非0-是*/
	unsigned char aucTagEnName[64+1];		/*标签英文名*/
	unsigned char aucTagCnName[64+1];		/*标签中文名*/
	unsigned char aucTagShortName[12+1];	/*标签简称名*/
}TLVTAG_PRM;

/*权重系数比例信息*/
typedef struct
{
	int iIndex;
	double dWeight;
	long lPercent;
}WEIGHTFACTOR_PRM;

/*子集集合参数结构体*/
typedef struct
{
	unsigned char ucDataType;	
	unsigned char ucData;
	int iData;
	unsigned int uiData;
	long lData;
	unsigned long ulData;
	float fData;
	double dData;	
	unsigned char aucData[12];
	int iOrgIndex;				/*原索引号*/
}SUBSET_PRM;

/*搜索子集集合匹配参数结构体*/
typedef struct
{
	int iN;			/*当前总数n*/
    int iM;			/*当前选择数m*/
    long lSum;		/*当前选择数和sum*/
    int iCount;		/*当前组合数*/
    int **piSubSet;	/*当前组合:记录索引*/
}SUBSETMATCH_PRM;

/*搜索子集集合结果参数结构体*/
typedef struct
{
	double dMinData;				/*子集合最小的数据*/
	double dMaxData;				/*子集合最大的数据*/
	unsigned char ucSubSetFlag;		/*子集合存在标志:0-不存在 1-存在*/
	int iSetSubNum;					/*子集合当前数据个数*/
	int *piSubSet;					/*子集合数据*/
}SUBSETRESULT_PRM;

/*RSA公钥结构定义*/
typedef struct
{
	unsigned int  uiBits;    			/*模位数，bit单位*/
	unsigned char aucModulus[256];    	/*模*/
	unsigned char aucExponent[256];   	/*指数*/
}RSAPUBLICKEY_PRM;

/*RSA私钥结构定义*/
typedef struct
{
	unsigned int  uiBits;    				/*模位数，bit单位*/
	unsigned char aucModulus[256];         	/*模-N(模数)*/
	unsigned char aucPublicExponent[256];   /*公钥指数*/
	unsigned char aucExponent[256];         /*私钥指数-D(私钥)*/
	unsigned char aucPrime[2][256];         /*pq素数,素数因子*/
	unsigned char aucPrimeExponent[2][256]; /*CRT指数,素数与指数除法值Dp,Dq*/
	unsigned char aucCoefficient[256];      /*CRT系数,素数与素数除法值Qinv*/
}RSAPRIVATEKEY_PRM;

/*CRC类型定义*/
typedef struct
{
	unsigned char width;	/*数据宽度(即CRC比特数):CRC校验码的长度(二进制位数)*/
	uint32_t poly;			/*多项式简记式(生成项的简写):以16进制表示;如除数11011(poly值为0x1B)的二项式为G(X)=X4+X3+X+1,
	                  			例如:CRC-32即是0x04C11DB7,忽略了最高位的"1",即完整的生成项是0x104C11DB7,实际使用简记式0x04C11DB7*/
	uint32_t init;			/*初始值:这是算法开始时寄存器(crc)的初始化预置值,十六进制表示*/
	unsigned char refIn;	/*输入值是否反转:待测数据的每个字节是否按位反转(True或False)*/
	unsigned char refOut;	/*输出值是否反转:在计算后之后,异或输出之前:整个数据是否按位反转(True或False)*/
	uint32_t xorOut;		/*结果异或值:计算结果与此参数异或后得到最终的CRC值*/
}CRC_TYPE;

/***********************************************************************************************
	FuncName : Tool_SetTimer
	FuncFunc : 设置定时器计数器
	Input	 : unsigned long	— ulInputSeconds	输入设置的超时时间(S)
	Output	 : unsigned long *	— pulEndTimer		结束时间(S)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetTimer(unsigned long ulInputSeconds,unsigned long *pulEndTimer);

/***********************************************************************************************
	FuncName : Tool_CheckTimer
	FuncFunc : 检查定时器计数器是否有效
	Input	 : unsigned long 	— pulEndTimer		结束时间(S)
	Output	 : None
	Return	 : unsigned char	— 有效,返回TOOL_SUCCESS(0x00)
								— 超时或失效,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTimer(unsigned long pulEndTimer);

/***********************************************************************************************
	FuncName : Tool_TimerOpen
	FuncFunc : 打开定时器
	Input	 : unsigned long	— ulInputSeconds	输入设置的超时时间(S)
	Output	 : unsigned int *	— puiTimerID		返回定时器ID
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : 目前只支持5组定时器
	History  : None
	Other    : 配合Tool_TimerCheck和Tool_TimerClose使用
*************************************************************************************************/
EXPORT unsigned char Tool_TimerOpen(unsigned long ulInputSeconds,unsigned int *puiTimerID);

/***********************************************************************************************
	FuncName : Tool_TimerCheck
	FuncFunc : 检查定时器是否启动正常
	Input	 : unsigned int		— uiTimerID		输入定时器ID
	Output	 : unsigned long *	— pulLeftTime		成功返回剩余时间(S)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : 目前只支持5组定时器
	History  : None
	Other    : 配合Tool_TimerOpen和Tool_TimerClose使用
*************************************************************************************************/
EXPORT unsigned char Tool_TimerCheck(unsigned int uiTimerID,unsigned long *pulLeftTime);

/***********************************************************************************************
	FuncName : Tool_TimerClose
	FuncFunc : 关闭定时器
	Input	 : unsigned int		— uiTimerID		输入定时器ID
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : 目前只支持5组定时器
	History  : None
	Other    : 配合Tool_TimerOpen和Tool_TimerCheck使用
*************************************************************************************************/
EXPORT unsigned char Tool_TimerClose(unsigned int uiTimerID);

/***********************************************************************************************
	FuncName : Tool_SetTimeOut
	FuncFunc : 设置超时时间
	Input	 : unsigned long	— uiTimeout	输入设置的超时时间(S)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetTimeOut(unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : Tool_GetTimeOut
	FuncFunc : 获取超时时间
	Input	 : None
	Output	 : unsigned int *	— puiTimeout	输出设置的超时时间(S)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimeOut(unsigned int *puiTimeout);

/***********************************************************************************************
	FuncName : Tool_WaitKey
	FuncFunc : 获取按键值带超时功能
	Input	 : unsigned long	— ulInputSeconds	输入设置的超时时间(S)
	Output	 : unsigned char *	— pucOutputKey		输出获取的按键值	0x00-表示超时
	Return	 : unsigned char	— 有按键成功,返回TRUE
								— 无按键失败,返回FALSE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WaitKey(unsigned long ulInputSeconds,unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_WaitKeyMill
	FuncFunc : 获取按键值带超时功能
	Input	 : unsigned long	— ulInputMillSeconds	输入设置的超时时间(ms)
	Output	 : unsigned char *	— pucOutputKey			输出获取的按键值	0x00-表示超时
	Return	 : unsigned char	— 有按键成功,返回TRUE
								— 无按键失败,返回FALSE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 毫秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WaitKeyMill(unsigned long ulInputMillSeconds,unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_Delay
	FuncFunc : 延时函数
	Input	 : unsigned long	— ulInputMillSec	输入等待的时间(毫秒)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 以毫秒统计如需要等待1秒,则输入参数ulMSec=1000
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Delay(unsigned long ulInputMillSec);

/***********************************************************************************************
	FuncName : Tool_ClrKey
	FuncFunc : 清除按键缓冲
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ClrKey( void );

/***********************************************************************************************
	FuncName : Tool_CheckKey
	FuncFunc : 检测按键函数
	Input	 : None
	Output	 : unsigned char *	— pucOutputKey	输出按键键值
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckKey(unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_GetDateAndTime
	FuncFunc : 获取日期时间
	Input	 : unsigned char 	— ucFormatFlag		输出的日期时间格式标志
								   0:YYYYMMDDHHMMSS
								   1:YYYY-MM-DD HH:MM:SS
								   2:YYYYMMDDHHMMSSMS
								   3:YYYY-MM-DD HH:MM:SS.MS
								   4:S(数)
								   5:MS(毫秒数)
								   6:YYYYMMDDHHMMSS.MS
								   其它:YYYY-MM-DD HH:MM:SS
	Output	 : unsigned char *	— pucOutputData	输出的日期时间信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDateAndTime(unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCurrentDate
	FuncFunc : 获取当前日期信息
	Input	 : unsigned char   	— ucFormatFlag,日期格式
								   0x00-YYYYMMDD 0x01-YYYY(20YY) 0x02-YYMMDD
								   0x03-YYMM 0x04-YYDD 0x05-MMDD
								   0x06-YY 0x07-MM 0x08-DD
								   0x09-YYYY-MM-DD 0x0A-YYYY/MM/DD 0x10-HHMMSS
								   0x11-YYYYMMDDHHMMSS 0x12-YYMMDDHHMMSS 0x13-YYYY-MM-DD HH:MM:SS
								   0x14-YYYY/MM/DD HH:MM:SS 0x15-HH:MM:SS 0x16-YYYY-MM-DD HH:MM
								   0x17-YYYY/MM/DD HH:MM 0x18-HH:MM 0x19-HHMM
								   0x1A-HH 0x1B-MM 0x1C-SS
								   0x20-星期几 0x21-YYYY-MM-DD HH:MM:SS 星期几 0x22-YYYY/MM/DD HH:MM:SS 星期几
								   0x23-星期一:1 星期二:2 星期三:3 星期四:4 星期五:5 星期六:6  星期日:7
								   0x24-服务器中文时间格式如:2023/04/03 09:59:47(星期一)
								   0x25-服务器中文时间格式如:2023-04-03 09:59:47(星期一)
								   0x26-服务器中文时间格式如:2023年04月03日09时59分47秒(星期一)
								   0x27-服务器中文时间格式如:2023年04月03日09:59:47(星期一)
								   0x28-服务器英文时间格式如:Mon, 3 Apr 2023 09:59:47 +0800
								   其它-YYYYMMDD
	Output	 : unsigned char *	— pucOutputDate,输出日期信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : 年月日时分秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentDate(unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetCurrentMillSeconds
	FuncFunc : 获取到现在所经过的毫秒数
	Input	 : None
	Output	 : unsigned long *	— pulOutputMillSeconds	输出所经过的毫秒数(MS)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : 毫秒数
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentMillSeconds(unsigned long *pulOutputMillSeconds);

/***********************************************************************************************
	FuncName : Tool_GetCurrentSeconds
	FuncFunc : 获取到现在所经过的秒数
	Input	 : None
	Output	 : long *			— plOutputSeconds	输出所经过的秒数(S)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : 从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentSeconds(long *plOutputSeconds);

/***********************************************************************************************
	FuncName : Tool_GetTickCount
	FuncFunc : 获取到现在所经过的毫秒数
	Input	 : None
	Output	 : double *			— pdOutputMillSeconds	输出所经过的毫秒数(MS)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : 高精度计时器(MS)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTickCount(double *pdOutputMillSeconds);

/***********************************************************************************************
	FuncName : Tool_GetSystemTimeFromUTC
	FuncFunc : 从UTC时间值获取到现在所经过的秒数
	Input	 : INT64			— llUTCTime,输入UTC时间值
	           unsigned char	— ucTimestampFlag,输入时间戳标志:0-秒级 1-毫秒级
	           unsigned char	— ucGmtFlag,输入时区标志:0-北京时区 非0-非北京时区
		       unsigned char	— ucSetTimeFlag,是否设置为当前系统时间 0-不设置 1-设置时间为当前系统时间
	           unsigned char   	— ucFormatFlag,输出日期格式 0x00-YYYYMMDD 0x01-YYYY 0x02-YYYYMM 
															 0x03-YYMM 0x04-YYMMDD 0x05-MMDD 
															 0x06-MM 0x07-DD 08-YYYYMMDDHHMMSS
															 0x09-YYYYMMDDHHMMSSMSMSMS
															 0x0A-YYYYMMDDHHMMSS.MSMSMS
															 0x0B-YYYY-MM-DD HH:MM:SS
															 0x0C-YYYY/MM/DD HH:MM:SS
															 其它-YYYYMMDD
	Output	 : unsigned char *	— pucOutputDate,输出日期信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : 从公元1970年1月1日的UTC时间从0时0分0秒算起到现在所经过的秒数
	History  : 北京时间是中国采用国际时区东八时区的区时作为标准时间:北京时区为GMT加8小时时间差;
	           北京时间并不是北京(东经116.4°)的地方时间,而是东经120°的地方时间,
	           故东经120度地方时比北京的地方时早约14分半钟;
	           因为北京处于国际时区划分中的东八区,
	           同格林尼治时间(世界时)整整相差8小时(即北京时间=世界时+8小时,GMT+8);
	           东八区包括的范围从东经112.5°到东经127.5°,以东经120°为中心线,
	           东西各延伸7.5°,总宽度为15°的区域;
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetSystemTimeFromUTC(INT64 llUTCTime,unsigned char ucTimestampFlag,unsigned char ucGmtFlag,
													unsigned char ucSetTimeFlag,unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetTimestamp
	FuncFunc : 将一个秒数转换为日期时间信息
	Input	 : long				— lInputSeconds	输入所经过的秒数(S)
			   unsigned char 	— ucFormatFlag		输出的日期时间格式标志
			   											0x00-YYYYMMDD
			   											0x01-YYYY
			   											0x02-YYYYMM 
														0x03-YYMM
														0x04-YYMMDD
														0x05-MMDD 
														0x06-MM 
														0x07-DD 
														08-YYYYMMDDHHMMSS
														0x09-YYYY-MM-DD HH:MM:SS
														0x0A-YYYY/MM/DD HH:MM:SS
														其它-YYYYMMDDHHMMSS
	Output	 : unsigned char *	— pucOutputData	输出日期信息YYYYMMDDHHMMSS
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : lInputSeconds最大4294967295(2^32-1)
	History  : 世界时(UTC)也被称为格林尼治标准时间(GMT)来表示
	Other    : 输入的秒数为从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimestamp(long lInputSeconds,unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetTimestampEx
	FuncFunc : 将一个秒数转换为日期时间信息
	Input	 : INT64			— lInputSeconds	输入所经过的秒数(S)
			   unsigned char 	— ucFormatFlag		输出的日期时间格式标志
			   											0x00-YYYYMMDD
			   											0x01-YYYY
			   											0x02-YYYYMM 
														0x03-YYMM
														0x04-YYMMDD
														0x05-MMDD 
														0x06-MM 
														0x07-DD 
														08-YYYYMMDDHHMMSS
														0x09-YYYY-MM-DD HH:MM:SS
														0x0A-YYYY/MM/DD HH:MM:SS
														其它-YYYYMMDDHHMMSS
	Output	 : unsigned char *	— pucOutputData	输出日期信息YYYYMMDDHHMMSS
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : lInputSeconds可以大于4294967295(2^32-1),如32503651199
	           输入lInputSeconds=4294967295(2^32-1),pucOutputData=21060207142815;
			   输入lInputSeconds=32503651199,pucOutputData=29991231235959;
	History  : 世界时(UTC)也被称为格林尼治标准时间(GMT)来表示
	Other    : 输入的秒数为从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimestampEx(INT64 lInputSeconds,unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_TimeToGmt
    FuncFunc : 将YYYYMMDDHHMMSS格式日期转换GMT时间,即从1970/1/1 0时0分0秒到指定时刻的秒数
	Input	 : const char *		— pucInputDate	输入时间信息(YYYYMMDDHHMMSS)
	           unsigned char	— ucGmtFlag,输入时区标志:0-北京时区 非0-非北京时区
	Output	 : time_t *			— plOutputData	输出转换后time_t格式的时间信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : GMT Time(S)
	History  : 世界时(UTC)也被称为格林尼治标准时间(GMT)来表示
	           北京时间是中国采用国际时区东八时区的区时作为标准时间:北京时区为GMT加8小时时间差;
	Other    : 例如: 
			   输入pcInputData=20090228102130,输出plOutputData=134531388
			   输入pcInputData=21060207142815,输出最大4294967295(2^32-1)
*************************************************************************************************/  
EXPORT unsigned char Tool_TimeToGmt(const unsigned char *pucInputDate,unsigned char ucGmtFlag,time_t *plOutputData);

/***********************************************************************************************
	FuncName : Tool_TimeToGmtEx
    FuncFunc : 将YYYYMMDDHHMMSS格式日期转换GMT时间,即从1970/1/1 0时0分0秒到指定时刻的秒数
	Input	 : const char *		— pucInputDate	输入时间信息(YYYYMMDDHHMMSS)
	           unsigned char	— ucGmtFlag,输入时区标志:0-北京时区 非0-非北京时区
	Output	 : INT64 *			— plOutputData	输出转换后time_t格式的时间信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : GMT Time(S):实现类似_mktime64功能,mktime的扩展
	History  : 世界时(UTC)也被称为格林尼治标准时间(GMT)来表示
	           北京时间是中国采用国际时区东八时区的区时作为标准时间:北京时区为GMT加8小时时间差;
	Other    : 例如: 
			   输入pcInputData=20090228102130,输出plOutputData=134531388
			   输入pcInputData=21060207142815,输出plOutputData=4294967295(2^32-1)
			   输入pcInputData=29991231235959,输出32503651199			   
*************************************************************************************************/  
EXPORT unsigned char Tool_TimeToGmtEx(const unsigned char *pucInputDate,unsigned char ucGmtFlag,INT64 *plOutputData);

/***********************************************************************************************
	FuncName : Tool_ConvertDateAndTime
	FuncFunc : 日期时间格式转换
	Input	 : unsigned char 	— ucFormatFlag		输入的日期时间格式转换标志
								   0x00:YYYYMMDDHHMMSS->YYYY/MM/DD HH:MM:SS
								   0x01:YYYYMMDDHHMMSS->YYYY-MM-DD HH:MM:SS
								   0x02:YYYY/MM/DD HH:MM:SS->YYYYMMDDHHMMSS
								   0x03:YYYY-MM-DD HH:MM:SS->YYYYMMDDHHMMSS
								   0x04:YYYY-MM-DD HH:MM:SS->YYYY/MM/DD HH:MM:SS
								   0x05:YYYY/MM/DD->YYYYMMDD
								   0x06:YYYY-MM-DD->YYYYMMDD
								   0x07:YYYYMMDD->星期几(星期一-1,星期二-2,星期三-3,星期四-4,星期五-5,星期六-6,星期日-7)
								   0x08:YYYY/MM/DD HH:MM:SS(非标准2020/8/12 9:09:12)->YYYY/MM/DD HH:MM:SS(标准2020/08/12 09:09:12)
								   0x09:YYYY/MM/DD HH:MM:SS(非标准2020/8/12 9:09:12)->YYYYMMDDHHMMSS(标准20200812090912)
								   0x0A:YYYYMMDDHHMMSS->YYYY年MM月DD日 HH:MM:SS
			   unsigned char *	— pucInputData		输入的日期时间信息
	Output	 : unsigned char *	— pucOutputData	输出的日期时间信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : 不检查格式本身
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConvertDateAndTime(unsigned char ucFormatFlag,unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetSysTime
	FuncFunc : 获取系统的UTC时间信息
	Input	 : unsigned char   	— ucFormatFlag,输入输出的日期格式标志:
                                                             0x00-YYYYMMDD 0x01-YYYY 0x02-YYYYMM 
															 0x03-YYMM 0x04-YYMMDD 0x05-MMDD 
															 0x06-MM 0x07-DD 08-YYYYMMDDHHMMSS
															 0x09-YYYYMMDDHHMMSSMSMSMS
															 0x0A-YYYYMMDDHHMMSS.MSMSMS
															 0x0B-YYYY-MM-DD HH:MM:SS
															 0x0C-YYYY/MM/DD HH:MM:SS
															 0x0D-S(世界时区:所经过的秒数)
															 0x0E-S(北京时区:所经过的秒数)
															 其它-YYYYMMDD
	Output	 : unsigned char *	— pucOutputDate,输出日期信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : UTC时间
	History  : None
	Other    : 输入的年是从1970年开始的计数
*************************************************************************************************/
EXPORT unsigned char Tool_GetSysTime(unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_SetSysTime
	FuncFunc : 设置系统日期时间信息
	Input	 : unsigned char 	— ucFormatFlag		输入的日期时间格式标志 0:YYYYMMDDHHMMSS 非0:YYYY-MM-DD HH:MM:SS或YYYY/MM/DD HH:MM:SS
			   unsigned char *	— pucInputData		输入日期信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : 日期时间的字符串 YYYYMMDDHHMMSS(ucFormatFlag==0)或YYYY-MM-DD HH:MM:SS(ucFormatFlag!=0)
	History  : None
	Other    : 输入的年是从1970年开始的计数
*************************************************************************************************/
EXPORT unsigned char Tool_SetSysTime(unsigned char ucFormatFlag,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_GetMonDay
    FuncFunc : 取得某年某月的具体天数
	Input	 : int				— iYear	输入的年份
		       int				— iMonth	输入的月份
	Output	 : int *			— piDay	输出的天数
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 根据年份和月份确定这个月的天数
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonDay(int iYear,int iMonth,int *piDay);

/*********************************************************************************************** 
	FuncName : Tool_GetByteOfSysDataType  
	FuncFunc : 获取当前系统数据类型所占的字节数
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetByteOfSysDataType( void );

/*********************************************************************************************** 
	FuncName : Tool_Rand  
	FuncFunc : 随机生成数据(数据范围为0~255)
	Input	 : unsigned int 	— uiInputRandNumer   	输入需要生成的随机数据个数
	Output	 : unsigned char *  — pucOutputData  		输出生成的随机数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 数据取值范围0~255
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Rand(unsigned int uiInputRandNumer,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandInt 
	FuncFunc : 随机生成数据(数据范围为uiMin~uiMax)
	Input	 : unsigned int 	— uiInputRandNumer   	输入需要生成的随机数据个数
			   unsigned int 	— uiMin   				输入生成的最小的数
	           unsigned int 	— uiMax   				输入生成的最大的数
	Output	 : unsigned int *  	— puiOutputData  		输出生成的随机数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 数据取值范围uiMin~uiMax
	History  : 0~32767
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandInt(unsigned int uiInputRandNumer,unsigned int uiMin,unsigned int uiMax,unsigned int *puiOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandEx  
	FuncFunc : 随机生成数据(数据范围为ucMin~ucMax)
	Input	 : unsigned int 	— uiInputRandNumer   	输入需要生成的随机数据个数
	           unsigned char 	— ucMin   				输入生成的最小的数
	           unsigned char 	— ucMax   				输入生成的最大的数
	Output	 : unsigned char *  — pucOutputData  		输出生成的随机数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 数据取值范围ucMin~ucMax
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandEx(unsigned int uiInputRandNumer,unsigned char ucMin,unsigned char ucMax,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandFilter  
	FuncFunc : 随机生成数据如果产生X用Y代替(数据范围为0~255)
	Input	 : unsigned char 	— ucInputRandNumer   	输入需要生成的随机数据个数
			   unsigned char 	— ucX   				不可以生成的数据
			   unsigned char 	— ucY   				如果生成了不可以生成的数据使用该数据替代
	Output	 : unsigned char *  — pucOutputData  		输出生成的随机数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 数据取值范围0~255,当等于ucX时取值为ucY
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandFilter(unsigned int uiInputRandNumer,unsigned char ucX,unsigned char ucY,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandLarge  
	FuncFunc : 随机生成数据(数据范围为Min~Max)
	Input	 : unsigned int 	— uiInputRandNumer   	输入需要生成的随机数据个数
	           unsigned long 	— ulMin   				输入生成的最小的数
	           unsigned long 	— ulMax   				输入生成的最大的数
	Output	 : unsigned long *  — pulOutputData  		输出生成的随机数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 数据取值范围(数据范围为Min~Max)
	History  : None
	Other    : unsigned int
*************************************************************************************************/
EXPORT unsigned char Tool_RandLarge(unsigned int uiInputRandNumer,unsigned long ulMin,unsigned long ulMax,unsigned long *pulOutputData);

/*********************************************************************************************** 
	FuncName : Tool_Pow2gt  
	FuncFunc : 获取比x等于或大于的最小的2的N次方数
	Input	 : int 				— iInputData,输入数据
	Output	 : int *  			— piOutputData,输出比x等于或大于的最小的2的N次方数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : 如iInputData=2,*piOutputData=2;iInputData=3,*piOutputData=4;iInputData=4,*piOutputData=4;iInputData=5,*piOutputData=8;
*************************************************************************************************/
EXPORT unsigned char Tool_Pow2gt(int iInputData,int *piOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_Xor
	FuncFunc 	:  两组数据之间异或运算
	Input	 	:  unsigned char *	—pucInputData1 		输入的数据1
    			   unsigned char *	—pucInputData2 		输入的数据2
    			   unsigned int 	—uiInputDataLen	    输入异或数据的长度
	Output	 	:  unsigned char * 	—pucOutputData  		输出数据
	Return	 	:  unsigned	char 	—成功,返回TOOL_SUCCESS(0x00)
							 	 	—失败,返回TOOL_FAILURE(0x01)
							 	 	—输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  pucInputData1=0x00 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88
	               pucInputData2=0xFF 0xEE 0xDD 0xCC 0xBB 0xAA 0x99 0x88 0x77
	               uiInputDataLen=8;
	               pucOutputData=0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_Xor(unsigned char *pucInputData1,unsigned char *pucInputData2,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_StrXor
	FuncFunc 	:  两组字符串数据之间异或运算
	Input	 	:  unsigned char *	—pucInputData1 		输入的数据1
    			   unsigned char *	—pucInputData2 		输入的数据2
    			   unsigned int 	—uiInputDataLen	    输入异或数据的长度
	Output	 	:  unsigned char * 	—pucOutputData  		输出数据
	Return	 	:  unsigned	char 	—成功,返回TOOL_SUCCESS(0x00)
							 	 	—失败,返回TOOL_FAILURE(0x01)
							 	 	— 输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  pucInputData1="001122334455667788"
	               pucInputData2="FFEEDDCCBBAA998877"
	               pucOutputData="FFFFFFFFFFFFFFFFFF"
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_StrXor(unsigned char *pucInputData1,unsigned char *pucInputData2,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_DataXor  
	FuncFunc : 求n个数据的异或值(初始值为0)
	Input	 : unsigned char *  — pucInputData   	输入数据
			   unsigned int     — uiInputDataLen   输入异或数据的长度
	Output	 : unsigned char *  — pucOutputData  	输出数据LRC 
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_DataXor(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_DataXorEx  
	FuncFunc : 求n个数据的异或值(初始值为ucValue)
	Input	 : unsigned char	— ucValue	   	  LRC的初始值
			   unsigned char *  — pucInputData   输入的数据
			   unsigned int     — uiInputDataLen 输入异或数据的长度
	Output	 : unsigned char *  — pucOutputData  输出数据LRC 
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author   : Sunrier    
	Date     : 2010-09-23 13:12:52
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_DataXorEx(unsigned char ucValue,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_Not
	FuncFunc 	:  数据非
	Input	 	:  unsigned char *	—pucInputData	 	输入的数据
    			   unsigned int 	—uiInputDataLen	输入的长度
	Output	 	:  unsigned char * 	—pucOutputData  	输出的数据
	Return	 	:  unsigned	char 	—成功,返回TOOL_SUCCESS(0x00)
							 	 	—失败,返回TOOL_FAILURE(0x01)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  None
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_Not(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_GetCheckSum  
	FuncFunc : 获取和检验值
	Input	 : unsigned char *  — pucInputData   	输入数据
			   unsigned int     — uiInputDataLen   输入数据长度
	Output	 : unsigned char *  — pucCheckSum    	输出检验值
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01) 
	Author   : Sunrier    
	Date     : 2010-09-23 13:12:52
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_GetCheckSum(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucCheckSum);

/***********************************************************************************************
	FuncName : Tool_IsRangeByte
	FuncFunc : 比较字节数据是否在指定的范围内
	Input	 : unsigned char 	— ucCompareFlag,输入比较范围标志
	           unsigned char	— ucMin,输入最小范围
	           unsigned char	— ucMax,输入最大范围
	           unsigned char 	— ucInputData,输入的数据
	Output	 : None
	Return	 : unsigned char	— 范围内,返回TOOL_SUCCESS(0x00)
					 			   超出范围,返回TOOL_FAILURE(0x01)
					 			   数据无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 字节数据(unsigned char)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsRangeByte(unsigned char ucCompareFlag,unsigned char ucMin,unsigned char ucMax,unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_AscToHex
	FuncFunc : ASCII转化为HEX
	Input	 : unsigned char *	— pucInputData		输入的ASCII数据(输入的数据长度是输出的两倍,即2*uiOutputLen)
			   unsigned int 	— uiOutputDataLen	输出的HEX数据长度
	Output	 : unsigned char *	— pucOutputData	输出的HEX数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如 输入0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII即为"CC6D61E66185CBB6"),uiOutputDataLen = 8;
    			  输出0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6
    		   如 输入"123A45C67CF8",uiOutputDataLen = 6
    			  输出0x12 0x3A 0x45 0xC6 0x7C 0xF8
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToHex(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AscToHexEx
	FuncFunc : ASCII转化为主机序的HEX数值
	Input	 : unsigned char *	— pucInputData		输入的ASCII数据
	           int 				— iInputDataLen	输入的ASCII数据长度
			   int 				— iOutputDataLen	输出的HEX数据长度
	Output	 : unsigned char *	— pucOutputData	输出的HEX数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如 输入12345,iInputDataLen = 5;
    			  输出12345,iOutputDataLen = sizeof(INT32);
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToHexEx(unsigned char *pucInputData,int iInputDataLen,unsigned char *pucOutputData,int iOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_AscToBcd
	FuncFunc : ASCII转化为BCD
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiInputDataLen	输入的数据长度
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"12345678",uiInputDataLen = 8,uiOutputDataLen = 4
    			  输出0x12 0x34 0x56 0x78
    		   如 输入"123A45C67CF8",uiInputDataLen = 12,uiOutputDataLen = 6
    			  输出0x12 0x31 0x45 0x36 0x73 0x68
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToBcd(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AscToLong
	FuncFunc : ASCII码转化为无符号长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度位数
	Output	 : unsigned long *	— pulOutputData	输出的无符号长整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数有误,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"123",uiOutputDataLen = 3;
    			  输出123
    		   如 输入"123",uiOutputDataLen = 2;
    			  输出12
	History  : None
	Other    : 该函数转换的数应小于1000000000
*************************************************************************************************/
EXPORT unsigned char Tool_AscToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToHex
	FuncFunc : 二进制转换成十六进制字符串
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int 	— uiInputDataLen	输入数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BinaryToHex(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToDec
	FuncFunc : 将无符号二进制字符串转换为十进制数值(字符串长度不能小于1和大于32)
	Input	 : unsigned char 	— pucInputData	输入的数据
	Output	 : int *			— piOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 输入字符串长度不能小于1和大于32
	History  : None
	Other    : pucInputData="1010" *piOutputData=10
*************************************************************************************************/
EXPORT unsigned char Tool_BinaryToDec(unsigned char *pucInputData,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToAsc
	FuncFunc : BCD转化为ASCII
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  输出"0123456"
    		   如 输入0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 16;
    			  输出0x30 0x30 0x36 0x30 0x36 0x31 0x30 0x36 0x36 0x31 0x38 0x35 0x30 0x30 0x30 0x36
    		   和Tool_HexToAsc区别为:'A'到'F'转换为0x30
   	History  : None
	Other    : 默认左填充,不足左边补0
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToAsc(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToAscEx
	FuncFunc : BCD转化为ASCII扩展函数(带BCD码压缩方式)
	Input	 : unsigned char 	— ucFillFlag		输入BCD码填充标志,0-左填充 非0-右填充
													若输出长度不为偶数位,右靠的数字内容前补零(右填充),
													左靠的数字内容后补零(左填充)
			   unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 BCD码左填充输入0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  输出"0123456"
    		   如 BCD码右填充输入0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  输出"1234560"
    		   注:该函数中BCD码中的'A'到'F'转换为0x30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToAscEx(unsigned char ucFillFlag,unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToLong
	FuncFunc : BCD码转换成无符号长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned long *	— pulOutputData	输出的无符号长整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34,uiOutputDataLen = 1;
    			  输出2
    		   如 输入0x12 0x34,uiOutputDataLen = 2;
    			  输出12
    		   如 输入0x12 0x34,uiOutputDataLen = 3;
    			  输出234
    		   如 输入0x12 0x34,uiOutputDataLen = 4;
    			  输出1234
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToStr
	FuncFunc : BCD码转换成字符串
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34,uiOutputDataLen = 1;
    			  输出'2'
    		   如 输入0x12 0x34,uiOutputDataLen = 2;
    			  输出"12"
    		   如 输入0x12 0x34,uiOutputDataLen = 3;
    			  输出"234"
    		   如 输入0x12 0x34,uiOutputDataLen = 4;
    			  输出"1234"
    		   注:该函数中BCD码中的'A'到'F'转换为0x30
	History  : None
	Other    : 将字符串每“半个字节”转换为一个字节的ASCII码(从0~9)
     		   并且在所得字符串的结尾以0x00字符结束； 这个过程是将uiDestLen个“半个字符”转换为uiDestLen个字节长度的字符串。 
     		   如果uiDestLen是奇数，转换将会从指定的第二个“半个字符”开始(从第一个字节的低4位开始)
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToStr(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToAsc
	FuncFunc : 将一个字符的十进制值转换成ASCII码
	Input	 : unsigned char 	— ucInputData		输入的字符数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'z' = 0x7A = 122,uiOutputDataLen = 2;
    			  输出"22"
    		   如 输入'z' = 0x7A = 122,uiOutputDataLen = 3;
    			  输出"122"
    		   如 输入'z' = 0x7A = 122,uiOutputDataLen = 5;
    			  输出"00122"
	History  : None
	Other    : 将unsigned  char 类型(字符的10进制)数据转换为对应的ASCII 码字符串(ASCII value = digit value + 0x30)；
      		   目标字符串(pucOutputData)在转换前总是赋值为0x30 (字符'0')；
      		   unsigned  char 类型的数据最大值有3个阿拉伯数字,因此转换后的字符串最多是3个字符的阿拉伯字符组成的ASCII字符串
*************************************************************************************************/
EXPORT unsigned char Tool_CharToAsc(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToBcd
	FuncFunc : 将一个字符转换成BCD码
	Input	 : unsigned char 	— ucInputData		输入的字符数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'z' = 0x7A = 122,uiOutputDataLen = 1;
    			  输出0x22
    		   如 输入'z' = 0x7A = 122,uiOutputDataLen = 4;
    			  输出0x00/0x00/0x01/0x22
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToBcd(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToBitStr
	FuncFunc : 将一个字符转换二进制字符串
	Input	 : unsigned char 	— ucInputData		输入的字符数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'z' = 0x7A = 122
    			  输出"01111010"
    		   如 输入0x32
    			  输出"00110010"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToBitStr(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToHex
	FuncFunc : 字符转化为HEX对应的十进制数
	Input	 : unsigned char	— ucInputData	输入的数据
	Output	 : None
	Return	 : unsigned	char 	— 成功,返回HEX形式对应的十进制数
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如输入ucInputData='0'
    			 返回0
    		   如输入ucInputData='1'
    			 返回1
    		   如输入ucInputData='9'
    			 返回9
    		   如输入ucInputData='a'或者ucInputData='A'
    			 返回10
    		   如输入ucInputData='f'或者ucInputData='F'
    			 返回15
    		   如输入ucInputData=0x20
    			 返回0
    		   如输入ucInputData=0xFF
    			 返回8
	History  : 默认输入数据合法,不检查输入数据有效性
	Other    : 功能同Tool_HexToDec,如果需要检查数据的有效性,请使用Tool_HexToDec
*************************************************************************************************/
EXPORT unsigned char Tool_CharToHex(unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_CharToStr
	FuncFunc : 字符转换成字符串
	Input	 : unsigned char	— ucInputData		输入的字符数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'z' = 0x7A = 122,uiOutputDataLen = 2;
    			  输出"22"
    		   如 输入'z' = 0x7A = 122,uiOutputDataLen = 5;
    			  输出"00122"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToStr(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharLowCase
	FuncFunc : 字符转换成小写字符
	Input	 : unsigned char	— ucInputData		输入的一个字符
	Output	 : unsigned char *	— pucOutputData	输出的小写字符
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'Z'
    			  输出'z'
    		   如 输入'A'
    			  输出'a'
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharLowCase(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharUpperCase
	FuncFunc : 字符转换成小写字符
	Input	 : unsigned char	— ucInputData		输入的一个字符
	Output	 : unsigned char *	— pucOutputData	输出的小写字符
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'z'
    			  输出'Z'
    		   如 输入'a'
    			  输出'A'
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharUpperCase(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DecToHex
	FuncFunc : HEX对应的十进制数转化为十六进制字符
	Input	 : int				— iInputData	输入的数据
	Output	 : None
	Return	 : unsigned	char	— 成功,返回十进制数对应的HEX字符串形式('0'~'9','A'~'F')
	                            — 失败,返回0
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如输入ucInputData=0
    			 返回'0'==0x30
    		   如输入ucInputData=1
    			 返回'1'==0x31
    		   如输入ucInputData=9
    			 返回'9'==0x39
    		   如输入ucInputData=10
    			 返回'A'==0x41
    		   如输入ucInputData=12
    			 返回'C'==0x43
    		   如输入ucInputData=15
    			 返回'F'==0x46
    		   如输入ucInputData=-1
    			 返回失败0
    		   如输入ucInputData=128
    			 返回失败0
    		   如输入ucInputData=255
    			 返回失败0
	History  : 检查输入数据有效性,默认大写字母
	Other    : 和Tool_HexToDec相反操作
*************************************************************************************************/
EXPORT unsigned char Tool_DecToHex(int iInputData);

/***********************************************************************************************
	FuncName : Tool_DecToHexEx
	FuncFunc : HEX对应的十进制数转化为十六进制字符
	Input	 : int				— iInputData	输入的数据
	           unsigned char	— ucCaseFlag	输入大小写字母标志:0-大写 非0-小写
	Output	 : None
	Return	 : unsigned	char	— 成功,返回十进制数对应的HEX字符串形式('0'~'9','A'~'F'或'a'~'f')
	                            — 失败,返回0
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如输入ucInputData=0
    			 返回'0'==0x30
    		   如输入ucInputData=1
    			 返回'1'==0x31
    		   如输入ucInputData=9
    			 返回'9'==0x39
    		   如输入ucInputData=10,ucCaseFlag=0
    			 返回'A'==0x41
    		   如输入ucInputData=12,ucCaseFlag=0
    			 返回'C'==0x43
    		   如输入ucInputData=15,ucCaseFlag=0
    			 返回'F'==0x46
    		   如输入ucInputData=10,ucCaseFlag=1
    			 返回'a'==0x61
    		   如输入ucInputData=12,ucCaseFlag=1
    			 返回'c'==0x63
    		   如输入ucInputData=15,ucCaseFlag=1
    			 返回'f'==0x66
    		   如输入ucInputData=-1
    			 返回失败0
    		   如输入ucInputData=128
    			 返回失败0
    		   如输入ucInputData=255
    			 返回失败0
	History  : 检查输入数据有效性
	Other    : 和Tool_HexToDec相反操作
*************************************************************************************************/
EXPORT unsigned char Tool_DecToHexEx(int iInputData,unsigned char ucCaseFlag);

/***********************************************************************************************
	FuncName : Tool_HexToBinary
	FuncFunc : 十六进制字符串转换成二进制数
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int 	— uiInputDataLen	输入数据的长度
			   unsigned int 	— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据(输出的长度为uiInputDataLen/2)
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBinary(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToBinaryEx
	FuncFunc : 十六进制字符串转换成二进制数
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int 	— uiInputDataLen	输入数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据(输出的长度为uiInputDataLen/2)
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBinaryEx(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToAsc
	FuncFunc : HEX转化为ASCII
	Input	 : unsigned char *	— pucInputData		输入的HEX数据
			   unsigned int 	— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的ASCII数据(输出的长度为uiSrcLen*2)
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 16;
    			  输出0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII即为"CC6D61E66185CBB6")
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToAsc(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToBcdLong
	FuncFunc : 将一个十六进制转换成BCD码的长整型
	Input	 : unsigned char 	— ucInputData		输入的一个十六进制数
	Output	 : unsigned long *	— pulOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0xA8
    			  输出0x4138
    		   如 输入0x12
    			  输出0x3132
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBcdLong(unsigned char ucInputData,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToStr
	FuncFunc : 十六进制数据转换成字符串
	Input	 : unsigned char 	— pucInputData		输入的十六进制数据
	           unsigned int 	— uiOutputDataLen		输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 8;
    			  输出0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII即为"CC6D61E66185CBB6")
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToStr(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToDec
	FuncFunc : 十六进制字符转化为HEX对应的十进制数
	Input	 : unsigned char	— ucInputData	输入的数据
	Output	 : None
	Return	 : unsigned	char	— 成功,返回HEX形式对应的十进制数(<16)
	                            — 失败,返回>=16
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如输入ucInputData='0'
    			 返回0
    		   如输入ucInputData='1'
    			 返回1
    		   如输入ucInputData='9'
    			 返回9
    		   如输入ucInputData='a'或者ucInputData='A'
    			 返回10
    		   如输入ucInputData='f'或者ucInputData='F'
    			 返回15
    		   如输入ucInputData=0x20
    			 返回失败16
    		   如输入ucInputData=0xFF
    			 返回失败16
	History  : 检查输入数据有效性
	Other    : 和Tool_DecToHex相反操作
*************************************************************************************************/
EXPORT unsigned char Tool_HexToDec(unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_HexToInt
	FuncFunc : 十六进制转换成无符号整型
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int 	— uiOutputDataLen	输出的数据长度位数
	Output	 : unsigned int*	— puiOutputData	输出的无符号整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34 0x56 0x78,uiOutputDataLen = 1;
    			  输出0x12
    		   如 输入0x12 0x34 0x56 0x78,uiOutputDataLen = 2;
    			  输出0x1234
    		   如 输入0x12 0x34 0x56 0x78,uiOutputDataLen = 4;
    			  输出0x12345678
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Tool_HexToInt(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_HexStrToInt
	FuncFunc : 十六进制字符串转换成无符号整型
	Input	 : unsigned char *	— pucInputData		输入的数据
	Output	 : unsigned int*	— puiOutputData	输出的无符号整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入'1234',输出0x1234==4660
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexStrToInt(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToLong
	FuncFunc : 十六进制转换成无符号长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned long *	— pulOutputData	输出的无符号长整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 1;
    			  输出0x12
    		   如 输入0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 2;
    			  输出0x1234
    		   如 输入0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 4;
    			  输出0x12345678
	History  : 最大输入0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 4,
	           最大输出0xFFFFFFFF=4294967295
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToULongLong
	FuncFunc : 十六进制转换成无符号超长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度位数
	Output	 : UINT64 *			— pullOutputData	输出的无符号超长整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 1;
    			  输出0x12
    		   如 输入0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 2;
    			  输出0x1234
    		   如 输入0x12 0x34 0x56 0x78 0x90 0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 8;
    			  输出0x1234567812345678
			   如 输入0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 8;
    			  输出0xFFFFFFFFFFFFFFFF=18446744073709551615    		   
	History  : 最大输入0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 8,
	           最大输出0xFFFFFFFFFFFFFFFF=18446744073709551615
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToULongLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,UINT64 *pullOutputData);

/***********************************************************************************************
	FuncName : Tool_HexStrToLong
	FuncFunc : 十六进制字符串转换成无符号长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiInputDataLen	输入的数据长度
	Output	 : unsigned long *	— pulOutputData	输出的无符号长整型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"0001",uiInputDataLen = 2;
    			  输出*pulOutputData=0
    		   如 输入"0C3F",uiInputDataLen = 2;
    			  输出*pulOutputData=12
    		   如 输入"1000",uiInputDataLen = 2;
    			  输出*pulOutputData=16
    		   如 输入"FFFF",uiInputDataLen = 2;
    			  输出*pulOutputData=255
    		   如 输入"0001",uiInputDataLen = 4;
    			  输出*pulOutputData=1
    		   如 输入"0C3F",uiInputDataLen = 4;
    			  输出*pulOutputData=3135
    		   如 输入"1000",uiInputDataLen = 4;
    			  输出*pulOutputData=4096
    		   如 输入"FFFF",uiInputDataLen = 4;
    			  输出*pulOutputData=65535
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexStrToLong(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToAsc
	FuncFunc : 无符号整型转换成ASCII码
	Input	 : unsigned int		— uiInputData		输入的整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度位数
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12345,uiOutputDataLen = 2;
    			  输出"45"
    		   如 输入12345,uiOutputDataLen = 7;
    			  输出"0012345"
	History  : None
	Other    : 转换无符号整型到ASCII码
*************************************************************************************************/
EXPORT unsigned char Tool_IntToAsc(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToBcd
	FuncFunc : 无符号整型转换成BCD码
	Input	 : unsigned int 	— uiInputData		输入的整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12340,uiOutputDataLen = 2;
    			  输出0x23/0x40
    		   如 输入12340,uiOutputDataLen = 5;
    			  输出0x00/0x00/0x01/0x23/0x40
	History  : None
	Other    : 转换整形到BCD码,当输出的数据长度大于有效位数时函数将自动前补零;当长度小于有效位长,取末位有效位长
*************************************************************************************************/
EXPORT unsigned char Tool_IntToBcd(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToHex
	FuncFunc : 无符号整型转换成十六进制码
	Input	 : unsigned int 	— uiInputData		输入的整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12345(0x3039),uiOutputDataLen = 2;
    			  输出0x0x3039
    		   如 输入12345(0x3039),uiOutputDataLen = 5;
    			  输出0x0000003039
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IntToHex(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToStr
	FuncFunc : 无符号整型转换成字符串
	Input	 : unsigned int		— uiInputData		输入的整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12345,uiOutputDataLen = 2;
    			  输出"45"
    		   如 输入12345,uiOutputDataLen = 7;
    			  输出"0012345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IntToStr(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToStrEx
    FuncFunc : 将int型数据转换为字符串,长度不足时前补0
	Input	 : int				— iInputData		输入int型数据
	           int 				— iOutputDataLen	输入转换后的字符串数据长度
	Output	 : char *			— pcOutputData		输出转换后的字符串数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 长度不足时前补0
	History  : 和ltona功能相同
	Other    : 如:iInputData=123,iOutputDataLen=5,pcOutputData="00123"
*************************************************************************************************/
EXPORT unsigned char Tool_IntToStrEx(int iInputData,int iOutputDataLen,char *pcOutputData);

/***********************************************************************************************
	FuncName : Tool_Int32ToStr
	FuncFunc : INT32整型转换成字符串
	Input	 : INT32			— i32InputData		输入的INT32整型数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12345,输出"12345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int32ToStr(INT32 i32InputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Int64ToStr
	FuncFunc : INT64整型转换成字符串
	Input	 : INT64			— i64InputData		输入的INT64整型数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入12345,输出"12345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int64ToStr(INT64 i64InputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToAsc
	FuncFunc : 无符号长整型转换成ASCII码
	Input	 : unsigned long	— ulInputData		输入的长整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890,uiOutputDataLen = 2;
    			  输出"90"
    		   如 输入1234567890,uiOutputDataLen = 12;
    			  输出"001234567890"
	History  : None
	Other    : 转换无符号长整型到ASCII码
*************************************************************************************************/
EXPORT unsigned char Tool_LongToAsc(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToBcd
	FuncFunc : 无符号长整型转换成BCD码
	Input	 : unsigned long 	— ulInputData		输入的长整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890,uiOutputDataLen = 2;
    			  输出0x78/0x90
    		   如 输入1234567890,uiOutputDataLen = 7;
    			  输出0x00/0x00/0x12/0x34/0x56/0x78/0x90
	History  : None
	Other    : 转换长整形到BCD码,当输出的数据长度大于有效位数时函数将自动前补零;当长度小于有效位长,取末位有效位长
*************************************************************************************************/
EXPORT unsigned char Tool_LongToBcd(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToHex
	FuncFunc : 无符号长整型转换成十六进制码
	Input	 : unsigned long 	— ulInputData		输入的长整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890(0x499602D2),uiOutputDataLen = 2;
    			  输出0x02D2
    		   如 输入1234567890(0x499602D2),uiOutputDataLen = 5;
    			  输出0x00499602D2
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHex(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToHexEx
	FuncFunc : 无符号长整型转换成十六进制码
	Input	 : unsigned long 	— ulInputData		输入的长整型数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	           unsigned int *	— puiOutputDataLen	输出的数据长度
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890(0x499602D2);
    			  输出0x499602D2,*puiOutputDataLen = 4;
    		   如 输入12(4D2);
    			  输出0x4D2,*puiOutputDataLen = 2;
	History  : None
	Other    : unsigned long 最大4294967295
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHexEx(unsigned long ulInputData,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_LongToHexStr
	FuncFunc : 无符号长整型转换成十六进制码字符串
	Input	 : unsigned long 	— ulInputData		输入的长整型数据
	Output	 : unsigned char *	— pucOutputData	输出的数据
	           unsigned int *	— puiOutputDataLen	输出的数据长度
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890(0x499602D2),ucOutputDataLen = 4;
    			  输出"02D2"
    		   如 输入1234567890(0x499602D2),ucOutputDataLen = 10;
    			  输出"0x00499602D2"
	History  : 输出长度为偶数
	Other    : unsigned long 最大4294967295
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHexStr(unsigned long ulInputData, unsigned char ucOutputDataLen, unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToStr
	FuncFunc : 无符号长整型转换成字符串
	Input	 : unsigned long	— ulInputData		输入的长整型数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入1234567890,uiOutputDataLen = 2;
    			  输出"90"
    		   如 输入1234567890,uiOutputDataLen = 12;
    			  输出"001234567890"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_LongToStr(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToStrEx
    FuncFunc : 将long型数据转换为字符串,长度不足时前补0
	Input	 : long				— lInputData		输入long型数据
	           int 				— iOutputDataLen	输入转换后的字符串数据长度
	Output	 : char *			— pcOutputData		输出转换后的字符串数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 长度不足时前补0
	History  : 和ltona功能相同
	Other    : 如:lInputData=123,iOutputDataLen=5,pcOutputData="00123"
*************************************************************************************************/
EXPORT unsigned char Tool_LongToStrEx(long lInputData,int iOutputDataLen,char *pcOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToHex
	FuncFunc : 无符号64位长整型转换成十六进制码
	Input	 : UINT64 			— ui64InputData	输入的数据
	           unsigned int		— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如果不足8字节前面补0x00
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToHex(UINT64 ui64InputData,unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToHexEx
	FuncFunc : 无符号64位长整型转换成十六进制码
	Input	 : UINT64 			— ui64InputData	输入的数据
	           unsigned int	*	— puiOutputDataLen	输入输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	           unsigned int	*	— puiOutputDataLen	输出数据的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如果不足8字节前面不补0x00
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToHexEx(UINT64 ui64InputData,unsigned char* pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_Itoa
	FuncFunc : 将一个字符转换指定进制的字符串
	Input	 : int 				— iInputData		输入的整型数据
	           int 				— iRadix			输入的转换后的进制数
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 iInputData=122,iRadix=2
    			  pucOutputData="01111010"
    		   如 输入iInputData=50,iRadix=2
    			  pucOutputData="00110010"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Itoa(int iInputData,int iRadix,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_FloatToStr
	FuncFunc : 字符串符点类型转换为字符串
	Input	 : unsigned char *	— pucInOuputData	输入的数据
	Output	 : unsigned char *	— pucInOuputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 默认最长精度两位
	History  : None
	Other    : 如 输入"2796437180.95";
    			  输出"00000000279643718095"
    		   如 输入"2796437180.7";
    			  输出"00000000279643718070"
    		   如 输入"3.4030752576e+11";
    			  输出"00000034030752576000"
*************************************************************************************************/
EXPORT unsigned char Tool_FloatToStr(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DoubleToStr
	FuncFunc : 字符串符点类型转换为字符串
	Input	 : double			— dInputData		输入的double型数据
	           unsigned int		— uiOutputDataLen	输入的转换后的数据长度
	Output	 : unsigned char *	— pucOuputData		输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 默认最长精度意一位
	History  : None
	Other    : 如 输入1234,输出"1234.0"
*************************************************************************************************/
EXPORT unsigned char Tool_DoubleToStr(double dInputData,unsigned int uiOutputDataLen,unsigned char *pucOuputData);

/***********************************************************************************************
	FuncName : Tool_StrToBcd
	FuncFunc : 字符串转换成BCD码
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int 	— uiOutputDataLen	输出的数据长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"12345678",uiOutputDataLen = 4
    			  输出0x12 0x34 0x56 0x78
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToBcd(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToHex
	FuncFunc : 字符串转换成十六进制码
	Input	 : unsigned char *	— pucInputData		输入的ASCII数据(输入的数据长度是输出的两倍,即2*uiOutputLen)
			   unsigned int 	— uiOutputDataLen	输出的HEX数据长度
	Output	 : unsigned char *	— pucOutputData	输出的HEX数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : 如 输入0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII即为"CC6D61E66185CBB6"),uiOutputDataLen = 8;
    			  输出0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToHex(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt
    FuncFunc : 将字符串转换为INT型
	Input	 : unsigned char *	— pucInputData		输入字符串数据
			   int				— iInputDataLen	输入字符串数据的长度
	Output	 : int *			— piOutputData		输出整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 字符串
	History  : 和natoi功能相同
	Other    : 如:pcInputData="123",iInputDataLen=3,*piOutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt(unsigned char *pucInputData,int iInputDataLen,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToLong
	FuncFunc : 字符串转换成无符号长整型
	Input	 : unsigned char *	— pucInputData		输入的数据
	Output	 : unsigned long *	— pulOutputData	输出的无符号长整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"123"
    			  输出123
	History  : None
	Other    : 该函数转换的数应小于1000000000
*************************************************************************************************/
EXPORT unsigned char Tool_StrToLong(unsigned char *pucInputData,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt32
    FuncFunc : 将字符串转换为INT32型
	Input	 : unsigned char *	— pucInputData		输入字符串数据
			   int				— iInputDataLen	输入字符串数据的长度
	Output	 : INT32 *			— pi32OutputData	输出整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : 如:pcInputData="123",iInputDataLen=3,*pi32OutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt32(unsigned char *pucInputData,int iInputDataLen,INT32 *pi32OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt64
    FuncFunc : 将字符串转换为INT64型
	Input	 : unsigned char *	— pucInputData		输入字符串数据
			   int				— iInputDataLen	输入字符串数据的长度
	Output	 : INT64 *			— pi64OutputData	输出整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : INT64范围:-9223372036854775808~9223372036854775807
	History  : None
	Other    : 如:pcInputData="123",iInputDataLen=3,*pi32OutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt64(unsigned char *pucInputData,int iInputDataLen,INT64 *pi64OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToUint64
    FuncFunc : 将字符串转换为UINT64型
	Input	 : unsigned char *	— pucInputData		输入字符串数据
			   int				— iInputDataLen	输入字符串数据的长度
	Output	 : UINT64 *			— pui64OutputData	输出整型数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : UINT64范围:0~18446744073709551615
	History  : None
	Other    : 如:pcInputData="10446744073709551615",iInputDataLen=20,*pi32OutputData=10446744073709551615
*************************************************************************************************/
EXPORT unsigned char Tool_StrToUint64(unsigned char *pucInputData,int iInputDataLen,UINT64 *pui64OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToFloat
	FuncFunc : 字符串转换为字符串符点类型
	Input	 : unsigned char *	— pucInOuputData	输入的数据
	           unsigned char 	— ucBit			输入的截取的位数
	Output	 : unsigned char *	— pucInOuputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : 如 输入"00000000279643718095",ucBit = 10;
    			  输出"27.9643718095"
    		   如 输入"00000000279643718070",ucBit = 10;
    			  输出"27.964371807"
    		   如 输入"00000034030752576000",ucBit = 10;
    			  输出"3403.0752576"
*************************************************************************************************/
EXPORT unsigned char Tool_StrToFloat(unsigned char *pucInputData,unsigned char ucBit,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToDouble
	FuncFunc : 字符串转换成double型
	Input	 : unsigned char *	— pucInputData		输入的数据
			   unsigned int		— uiInputDataLen	输入的数据长度
	Output	 : double *			— pdOutputData		输出的double型数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入"1234"
    			  输出123
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToDouble(unsigned char *pucInputData,unsigned int uiInputDataLen,double *pdOutputData);

/***********************************************************************************************
	FuncName : Tool_StrReverse
	FuncFunc : 字符串反转
	Input	 : unsigned char *	— pucInOutputData	输入的数据
	           unsigned char *	— uiInputDataLen	输入的数据长度
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrReverse(unsigned char *pucInOutputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_StrLowerCase
	FuncFunc : 字符串转换成小写字符串
	Input	 : unsigned char *	— pucInOutputData	输入的数据
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrLowerCase(unsigned char *pucInOutputData);

/***********************************************************************************************
	FuncName : Tool_StrUpperCase
	FuncFunc : 字符串转换成大写字符串
	Input	 : unsigned char *	— pucInOutputData	输入的数据
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrUpperCase(unsigned char *pucInOutputData);

/***********************************************************************************************
	FuncName : Tool_StrCaseCmp
	FuncFunc : 不区分大小写比较两个字符串
	Input	 : const unsigned char *	— pucInputData1,输入的数据1
	           const unsigned char *	— pucInputData2,输入的数据2
	Output	 : None
	Return	 : unsigned	char 			— 数据1=数据2,返回0
							 			— 数据1>数据2,返回>0
							 			— 数据1<数据2,返回<0
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCaseCmp(const unsigned char* pucInputData1, const unsigned char* pucInputData2);

/***********************************************************************************************
	FuncName : Tool_StrNCaseCmp
	FuncFunc : 不区分大小写比较两个字符串的iLen位
	Input	 : const unsigned char *	— pucInputData1,输入的数据1
	           const unsigned char *	— pucInputData2,输入的数据2
	           int						— iLen,输入比较的数据长度
	Output	 : None
	Return	 : unsigned	char 			— 数据1=数据2,返回0
							 			— 数据1>数据2,返回>0
							 			— 数据1<数据2,返回<0
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrNCaseCmp(const unsigned char* pucInputData1, const unsigned char* pucInputData2,int iLen);

/***********************************************************************************************
	FuncName : Tool_StrEqual
	FuncFunc : 比较两个字符串值是否相等(区分大小写)
	Input	 : char *			— pInStr1				输入字符串1
			   char *			— pInStr2				输入字符串2
			   unsigned char	— ucUpperLowerFlag		区分大小写标志 0-不区分大小写 1-区分大小写
	Output	 : None
	Return	 : unsigned char	— 相等,返回TOOL_SUCCESS(0x00)
					 			— 不相等,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrEqual(char *pInStr1,char *pInStr2,unsigned char ucUpperLowerFlag);

/***********************************************************************************************
	FuncName : Tool_StrTrimRight
	FuncFunc : 去掉字符串右边所有字符ucCh
	Input	 : unsigned char *	— pucInOutputData	输入的数据
			   unsigned char 	— ucInputCh		去掉的字符
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 只包含指定的ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimRight(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimLeft
	FuncFunc : 去掉字符串左边所有字符ucCh
	Input	 : unsigned char *	— pucInOutputData	输入的数据
			   unsigned char 	— ucInputCh		去掉的字符
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 只包含指定的ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimLeft(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimLeftRight
	FuncFunc : 去掉字符串左边和右边所有字符ucCh
	Input	 : unsigned char *	— pucInOutputData	输入的数据
			   unsigned char 	— ucInputCh		去掉的字符
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 只包含指定的ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimLeftRight(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimCharLeft
	FuncFunc : 去掉字符串左边开始的第N次出现的字符之后的所有字符(不包括该次出现的字符)
	Input	 : unsigned char *	— pucInputData	输入的数据
			   unsigned int 	— uiTimes			第N次的字符,ucTimes=0,仅去掉该字符串中所有的该字符;ucTimes!=0,去掉截止第ucTimes次之后所有的字符
			   unsigned char 	— ucInputCh		匹配去掉的字符
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimCharLeft(unsigned char *pucInputData,unsigned int uiTimes,unsigned char ucInputCh,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrTrimM
	FuncFunc : 去掉字符串中间的空格
	Input	 : unsigned char *	— pucInOuputData	输入的数据
	Output	 : unsigned char *	— pucInOuputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 包括换行(\n)和制表符(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimM(unsigned char *pucInOuputData);

/***********************************************************************************************
	FuncName : Tool_StrAllTrim
	FuncFunc : 去掉字符串左边和右边的空格
	Input	 : unsigned char *	— pucInOuputData	输入的数据
	Output	 : unsigned char *	— pucInOuputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 包括换行(\n)和制表符(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimAll(unsigned char *pucInOuputData);

/***********************************************************************************************
	FuncName : Tool_StrTrim
	FuncFunc : 去掉字符串中的空格
	Input	 : unsigned char *	— pucInOuputData	输入的数据
	           unsigned char 	— ucTrimFlag		输入去掉的标志 0-左边 1-右边 2-中间 3-左边和右边 4-全部
	Output	 : unsigned char *	— pucInOuputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 包括换行(\n)和制表符(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrim(unsigned char *pucInOuputData,unsigned char ucTrimFlag);

/***********************************************************************************************
	FuncName : Tool_StrRightAlign
	FuncFunc : 字符串右边对齐,左边不足补特定字符
	Input	 : unsigned char *	— pucInOutputData		输入字符串,字符长度最大为规定的长度(可以输入字符串为空)
			   unsigned int 	— uiAlignLen			规定的长度,最大256位
			   unsigned char 	— ucInputCh			不足长度,左补特定字符-可显示字符,如果为不可显示字符默认补空格
	Output	 : unsigned char *	— pucInOutputData		输出字符串
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 右对齐,左补特定字符
	History  : None
	Other    : 可以输入字符串为空
*************************************************************************************************/
EXPORT unsigned char Tool_StrRightAlign(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrAlignAddSymbol
	FuncFunc : 字符串对齐,不足补特定字符
	Input	 : unsigned char *	— pucInOutputData		输入字符串,字符长度最大为规定的长度(可以输入字符串为空)
			   unsigned int 	— uiAlignLen			规定的长度,最大256位
			   unsigned char 	— ucInputCh			不足长度,左补特定字符-可显示字符,如果为不可显示字符默认补空格
			   unsigned char 	— ucFlag				补齐标志,0-右补齐 1或其它非0-左补齐
	Output	 : unsigned char *	— pucInOutputData		输出字符串
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 注意大小端问题
	History  : None
	Other    : 可以输入字符串为空
*************************************************************************************************/
EXPORT unsigned char Tool_StrAlignAddSymbol(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_StrToAmt
	FuncFunc : 将字符串转为金额模式
	Input	 : unsigned char *	— pucInputData			输入字符串
	Output	 : unsigned char *	— pucOutputData		输出字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 如输入"89235"则输出"892.35"
    		   如输入"2"则输出"0.02"
    		   如输入"0"则输出"0.00"
    		   如输入"0100"则输出"1.00"
    		   如输入没有为NULL,则输出"0.00"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmt(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToAmtEx
	FuncFunc : 把一个字符串转换为字符串金额
	Input	 : unsigned char *	— pucInputAmount	输入的字符串金额(ASC格式,最大长度12位)
			   unsigned char *	— pucCurrencyName	输入货币名称
			   unsigned char 	— ucNegativeFlag	输入的金额正负标志 '-'或'D'表示负数;其它标志为正数
	Output	 : unsigned char *	— pucOutputAmount	输出字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : 如输入000000012030,为正标志返回120.30
    		   如输入000000012030,为负标志返回-120.30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmtEx(unsigned char *pucInputAmount,unsigned char *pucCurrencyName,unsigned char ucNegativeFlag,unsigned char *pucOutputAmount);

/***********************************************************************************************
	FuncName : Tool_StrToAmtLong
	FuncFunc : 把一个字符串金额转换为整数金额
	Input	 : unsigned char *	— pucInputAmount	输入的字符串金额(ASC格式,最大长度12位)
	Output	 : unsigned long *	— pulOutputAmount	输出整数金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : 如输入000000012030,为正标志返回120.30
    		   如输入000000012030,为负标志返回-120.30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmtLong(unsigned char *pucInputAmount,unsigned long *pulOutputAmount);

/***********************************************************************************************
	FuncName : Tool_StrCopy
	FuncFunc : 中文智能截断函数
	Input	 : const unsigned char *	— pucInputData		输入数据
               int 						— iOutputDataLen	截取的长度,只拷贝最多iLen-1个字节并最后附加0x00
	Output	 : unsigned char *			— pucOutputData	输出数据,返回已拷贝的字符数, 不包含NULL 
	Return	 : int						— 返回已拷贝的字符数
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : pucDest 与 pucSrc指针不得重叠
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCopy(const unsigned char *pucInputData,int iOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrCopyEx
	FuncFunc : 中文智能截断函数
	Input	 : const unsigned char *	— pucInputData		输入数据
               int 						— iOutputDataLen	截取的长度,只拷贝最多iLen-1个字节并最后附加0x00
	Output	 : unsigned char *			— pucOutputData  	输出数据,返回已拷贝的字符数, 不包含NULL 
	Return	 : int						— 返回已拷贝的字符数
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : pucDest 与 pucSrc指针不得重叠
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCopyEx(const unsigned char *pucInputData,int iOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Strrchr
	FuncFunc : 查找字符串中最后一个字符出现的开始位置
	Input	 : unsigned char *	— pucInputData			输入字符串
			   unsigned int 	— ucInputCh			截取的字符
			   unsigned char 	— ucCutFlag			ucCutFlag:0x00-截取位置从最后一个出现的字符开始
			                                                      0x01-截取位置从最后一个出现的字符后面开始
			                                                      0x02-截取位置从开始位置到最后一个出现的字符(包括此字符)
			                                                      0x03-截取位置从开始位置到最后一个出现的字符(不包括此字符)
			                                                      其它-截取位置从最后一个出现的字符开始
	Output	 : unsigned char *	— pucOutputData		输出字符串
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 查找字符串中最后一个字符出现的开始位置的字符串
	History  : None
	Other    : 可以输出字符串为空
*************************************************************************************************/
EXPORT unsigned char Tool_Strrchr(unsigned char *pucInputData,unsigned char ucInputCh,unsigned char ucCutFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrFind
	FuncFunc : 查找字符串中是否存在某个子字符窜
	Input	 : unsigned char *	— pucInputData			输入字符串
			   unsigned char *	— pucInputSubData		输入子字符串
	Output	 : None
	Return	 : unsigned char	— 存在,返回TOOL_SUCCESS(0x00)
								— 不存在,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 字符串不可以输入为空
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrFind(unsigned char *pucInputData,unsigned char *pucInputSubData);

/***********************************************************************************************
	FuncName : Tool_StrFindSubTimes
	FuncFunc : 查找字符串中是否存在某个子字符窜
	Input	 : unsigned char *	— pucInputData			输入字符串
			   unsigned char *	— pucInputSubData		输入子字符串
	Output	 : unsigned int *	— puiTimes				输出出现的次数
	Return	 : unsigned char	— 存在,返回TOOL_SUCCESS(0x00)
								— 不存在,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 字符串不可以输入为空
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrFindSubTimes(unsigned char *pucInputData,unsigned char *pucInputSubData,unsigned int *puiTimes);

/***********************************************************************************************
	FuncName : Tool_StrReplace
	FuncFunc : 用pucNewStr替换字符串pucInputData中的pucOldStr
	Input	 : unsigned char *	— pucInOutputData		输入的字符串
			   unsigned char * 	— pucOldStr			输入被替换的字符串
			   unsigned char * 	— pucNewStr			输入用来替换的字符串
	Output	 : unsigned char *	— pucInOutputData		输出的字符串
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 查找字符串中最后一个字符出现的开始位置的字符串
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrReplace(unsigned char *pucInOutputData,unsigned char *pucOldStr,unsigned char *pucNewStr);

/***********************************************************************************************
	FuncName : Tool_GetBitFromUlongToHex
	FuncFunc : 获取从无符号长整型转换成十六进制码字符后的位数
	Input	 : unsigned long 	— ulInputData		输入的长整型数据
	Output	 : unsigned char *	— pucOutputDataLen	输出数据的位数
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入54(0x36),输出pucOutputDataLen = 2;
		       如输入130(0x82),输出pucOutputDataLen = 2;
		       如输入511(0x1FF),输出pucOutputDataLen = 3;
    		   如输入1879048191(0x6FFFFFFF),输出pucOutputDataLen = 8;
	History  : None
	Other    : unsigned long 最大4294967295(0xFFFFFFFF),输出pucOutputDataLen = 8;
*************************************************************************************************/
EXPORT unsigned char Tool_GetBitFromUlongToHex(unsigned long ulInputData,unsigned char *pucOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetBitFromUlonglongToHex
	FuncFunc : 获取从无符号超长整型转换成十六进制码字符后的位数
	Input	 : UINT64 			— ullInputData		输入的超长整型数据
	Output	 : unsigned char *	— pucOutputDataLen	输出数据的位数
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入54(0x36),输出pucOutputDataLen = 2;
		       如输入130(0x82),输出pucOutputDataLen = 2;
		       如输入511(0x1FF),输出pucOutputDataLen = 3;
    		   如输入1879048191(0x6FFFFFFF),输出pucOutputDataLen = 8;
    		   如输入4294967295(0xFFFFFFFF),输出pucOutputDataLen = 8;
    		   如输入18446744073709551615(0xFFFFFFFFFFFFFFFF),输出pucOutputDataLen = 16;
	History  : None
	Other    : unsigned long 最大18446744073709551615(0xFFFFFFFFFFFFFFFF),输出pucOutputDataLen = 16;
*************************************************************************************************/
EXPORT unsigned char Tool_GetBitFromUlonglongToHex(UINT64 ullInputData,unsigned char *pucOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckHexVaildByBits
	FuncFunc : 根据位数检查十六进制数是否有效
	Input	 : unsigned char *	— pucInputData		输入十六进制数据
	           unsigned int 	— uiInputDataLen	输入十六进制数据的长度
	           unsigned char 	— ucBits			输入有效位数(1到64位)
	Output	 : None
	Return	 : unsigned	char 	— 有效,返回TOOL_SUCCESS(0x00)
							 	— 无效,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入pucInputData=0x36,uiInputDataLen=1,ucBits=3,返回无效;
		       如 输入pucInputData=0x36,uiInputDataLen=1,ucBits=9,返回无效;
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckHexVaildByBits(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucBits);

/***********************************************************************************************
	FuncName : Tool_DigitalStrRightAlign
	FuncFunc : 数字组成的字符串右边对齐,左边不足补特定字符
	Input	 : unsigned char *	— pucInOutputData		输入字符串只从数字部分开始处理,字符长度最大为规定的长度(可以输入字符串为空)
			   unsigned int 	— uiAlignLen			规定的长度,最大256位
			   unsigned char 	— ucInputCh			不足长度,左补特定字符-可显示字符,如果为不可显示字符默认补'0'
	Output	 : unsigned char *	— pucInOutputData		输出字符串
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 右对齐,左补特定字符
	History  : None
	Other    : 可以输入字符串为空
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrRightAlign(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_DigitalStrAdd
	FuncFunc : 两ASC数字串相加,相加结果放在被加数里,结果数字串自动以右对齐
	Input	 : unsigned char *	— pucInOutputAugend		输入被加数
			   unsigned char *	— pucInputAddend			输入加数
			   unsigned int 	— uiInputAlignLen			输入输出的规定长度
	Output	 : unsigned char *	— pucInOutputAugend		输出被加数
			   unsigned char *	— pucOutputCarryFlag		进位标志0-没进位 1-有进位
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 两字符串数字相加
	History  : None
	Other    : 解决大数相加问题
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrAdd(unsigned char *pucInOutputAugend,unsigned char *pucInputAddend,unsigned int uiInputAlignLen,unsigned char *pucOutputCarryFlag);

/***********************************************************************************************
	FuncName : Tool_DigitalStrSub
	FuncFunc : 两ASC数字串相减,相减结果放在被减数里,结果数字串自动以右对齐
	Input	 : unsigned char *	— pucInOutputMinuend		输入被减数
			   unsigned char *	— pucInputSubtrahend		输入减数
			   unsigned int 	— uiInputAlignLen			输入输出的规定长度
	Output	 : unsigned char *	— pucInOutputAugend		输出被减数
			   unsigned char *	— pucOutputCarryFlag		借位标志0-没借位 1-有借位
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 两字符串数字相减
	History  : None
	Other    : 解决大数相减问题
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrSub(unsigned char *pucInOutputMinuend,unsigned char *pucInputSubtrahend,unsigned int uiInputAlignLen,unsigned char *pucOutputCarryFlag);

/***********************************************************************************************
	FuncName : Tool_GetEndian
	FuncFunc : 获取主机的数值类型的字序类型
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 大端模式,返回(0x02)
								— 小端模式,返回(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetEndian( void );

/***********************************************************************************************
	FuncName : Tool_ConvEndian
	FuncFunc : 从当前主机字节序转换为指定字节序
	Input	 : unsigned char	— ucEndianType	输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           unsigned char *	— pucInOutputData	输入的数据
	           unsigned int		— uiInputDataLen	输入数据的长度
	Output	 : unsigned char *	— pucInOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Tool_ConvEndian(unsigned char ucEndianType,unsigned char *pucInOutputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckBigEndian
	FuncFunc : 判断是否为大端模式
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功大端模式,返回TOOL_SUCCESS(0x00)
								— 失败小端模式,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBigEndian( void );

/***********************************************************************************************
	FuncName : Tool_LittleEndian
	FuncFunc : 小端模式高低位转化
	Input	 : unsigned char *	— pucInputData		输入的数据
	Output	 : unsigned int *	— pucOutputData	输出对应信息域的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 2Bytes,低位在后,高位在前
	History  : None
	Other    : 如输入"23" pucInputData = 2*256 + 3
*************************************************************************************************/
EXPORT unsigned char Tool_LittleEndian(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_BigEndian
	FuncFunc : 大端模式高低位转化
	Input	 : unsigned char *	— pucInputData		输入的数据
	Output	 : unsigned int *	— pucOutputData	输出对应信息域的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 2Bytes,低位在前,高位在后
	History  : None
	Other    : 如输入"23" pucInputData = 3*256 + 2
*************************************************************************************************/
EXPORT unsigned char Tool_BigEndian(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_ByteToInt32
	FuncFunc : 从当前主机字节序转换为指定字节序
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int		— uiInputDataLen	输入数据的长度
	           unsigned char	— ucEndianType	输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           
	Output	 : INT32 *			— pi32Data	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ByteToInt32(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,INT32 *pi32Data);

/***********************************************************************************************
	FuncName : Tool_ByteToUint64
	FuncFunc : 从当前主机字节序转换为指定字节序
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned int		— uiInputDataLen	输入数据的长度
	           unsigned char	— ucEndianType	输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式	           
	Output	 : UINT64 *			— pui64Data		输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ByteToUint64(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,UINT64 *pui64Data);

/***********************************************************************************************
	FuncName : Tool_Int64ToByte
	FuncFunc : 从当前主机字节序转换为指定字节序
	Input	 : INT64 			— i64InputData		输入的数据
	           unsigned int		— uiInputDataLen	输入数据的长度
	           unsigned char	— ucEndianType		输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           unsigned int		— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int64ToByte(INT64 i64InputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToByte
	FuncFunc : 从当前主机字节序转换为指定字节序
	Input	 : UINT64 			— ui64InputData	输入的数据
	           unsigned int		— uiInputDataLen	输入数据的长度
	           unsigned char	— ucEndianType		输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           unsigned int		— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)或TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 大端模式,低位在前(高地址),高位在后(低地址)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToByte(UINT64 ui64InputData,unsigned int uiInputDataLen,unsigned char ucEndianType,
									unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToValue
	FuncFunc : 根据输入所需要的数据类型,将二进制流转换为指定的数据类型
	Input	 : unsigned char 	— pucInputData		输入的二进制流数据
	           unsigned int 	— uiInputDataLen	输入二进制流数据的长度
	           unsigned char	— ucEndianType		输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           unsigned char 	— ucDataType		输入的数据类型,参考DATA_TYPE
	Output	 : unsigned int *	— puiOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned int Tool_BinaryToValue(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned char ucDataType,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_ValueToBinary
	FuncFunc : 根据输入所需要的数据类型,将原数据类型转换为指定的二进制流
	Input	 : unsigned int 	— uiInputData		输入的数据
	           unsigned char 	— ucDataType		输入的数据类型,参考DATA_TYPE
	           unsigned int 	— uiOutputDataLen	输出二进制流数据的长度
	Output	 : unsigned int *	— puiOutputData	输出的二进制流数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ValueToBinary(unsigned int uiInputData,unsigned char ucDataType,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DataConv
	FuncFunc : 按照字节序数据之间转换
	Input	 : unsigned char 	— pucInputData		输入的数据
	           unsigned int 	— uiInputDataLen	输入数据的长度
	           unsigned char	— ucEndianType		输入转换后的字节序类型
	                               0x01:小端模式 0x02:大端模式
	           unsigned char 	— ucDataType		输入的数据类型,参考DATA_TYPE
	           unsigned char 	— ucSignFlag		输入是否为有符号:1-有符号, 0-无符号
	           unsigned int 	— uiOutputDataLen	输出数据的长度
	Output	 : unsigned char *	— pucOutputData	输出的数据
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
							 	— 失败,返回TOOL_FAILURE(0x01)
							 	— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DataConv(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned char ucDataType,unsigned char ucSignFlag,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CheckBit
	FuncFunc : 检查输入的数据的某个BIT位是否为1
	Input	 : unsigned char *	— pucInputData		输入的数据 
			   unsigned int *	— uiBit			输入的检查第uiBit位数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)	该位为1
					 			— 失败,返回TOOL_FAILURE(0x01)	该位为0
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 起始位从0开始算起
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBit(unsigned char *pucInputData,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_CheckBitEx
	FuncFunc : 检查输入的数据的某个BIT位是否为1
	Input	 : unsigned long	— ulInputData		输入的数据
			   unsigned int *	— uiBit			输入的检查第uiBit位数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)	该位为1
					 			— 失败,返回TOOL_FAILURE(0x01)	该位为0
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 起始位从0开始算起
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBitEx(unsigned long ulInputData,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_SetBit
	FuncFunc : 设置一个数据某个位置为1
	Input	 : unsigned char *	— pucInputOutputData	输入的数据
			   unsigned int 	— uiInputDataLen		输入数据的长度
			   unsigned int *	— uiBit				输入设置的第uiBit位数
	Output	 : unsigned char *	— pucInputOutputData	输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回TOOL_FAILURE
					 			— 输入参数无效,返回TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : uiBit起始位从1开始算起,最大uiInputDataLen*8位
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetBit(unsigned char *pucInputOutputData,unsigned int uiInputDataLen,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_GetBit
	FuncFunc : 获取一个数据某个位置是否为1
	Input	 : unsigned char *	— pucInputData			输入的数据
			   unsigned int 	— uiInputDataLen		输入数据的长度
			   unsigned int *	— uiBit				输入获取的第uiBit位数
	Output	 : unsigned char *	— pucOutputData		输出的数据 1-该位为1 0-该位为0
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : uiBit起始位从1开始算起,最大uiInputDataLen*8位
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetBit(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiBit,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ConvertDataByMask
	FuncFunc : 根据设置屏蔽数据
	Input	 : unsigned char *	— pucInputData			输入数据
	           unsigned int		— uiInputDataLen		输入数据长度
	           unsigned int 	— uiHeaderLen			显示前几位
	           unsigned int 	— uiTailLen			显示后几位
	           unsigned char 	-  ucMaskChar			屏蔽后的字符使用该字符代替
	Output	 : unsigned char *	— pucOutputData		输出数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2014-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConvertDataByMask(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiHeaderLen,unsigned int uiTailLen,unsigned char ucMaskChar,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetFieldInfor
	FuncFunc : 获取数据各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char	— ucSeparator		各个域信息之间分隔符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : 如:123|33f9df|898jjdk2|
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInfor(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforEx
	FuncFunc : 获取数据各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char	— ucSeparator		各个域信息之间分隔符
			   unsigned char	— ucStopChar		特殊截止或者停止字符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 支持特殊截止或者停止字符
	History  : None
	Other    : 如:123|33f9df|898jjdk2|
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetStrFieldInfor
	FuncFunc : 获取数据串各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char *	— pucSeparator		各个域信息之间分隔数据串
			   unsigned int 	— uiSeparatorLen	分隔数据串的数据长度
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : 如:123|=33f9df|=898jjdk2|=xx|=
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrFieldInfor(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char *pucSeparator,unsigned int uiSeparatorLen,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetStrFieldInforEx
	FuncFunc : 获取数据串各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char *	— pucSeparator		各个域信息之间分隔数据串
			   unsigned int 	— uiSeparatorLen	分隔数据串的数据长度
			   unsigned char	— ucStopChar		特殊截止或者停止字符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 支持特殊截止或者停止字符
	History  : None
	Other    : 如:123|=33f9df|=898jjdk2|=xx|=
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrFieldInforEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char *pucSeparator,unsigned int uiSeparatorLen,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforBySep
	FuncFunc : 获取数据各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char	— ucSeparator		各个域信息之间分隔符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned int *	— puiOffset		输出下一个信息域开始位置
	           unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 支持连续分隔符
	History  : None
	Other    : 如:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforBySep(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforBySepEx
	FuncFunc : 获取数据各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char	— ucSeparator		各个域信息之间分隔符
			   unsigned char	— ucStopChar		特殊截止或者停止字符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned int *	— puiOffset		输出下一个信息域开始位置
	           unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 支持连续分隔符
	History  : None
	Other    : 如:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforBySepEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforByMultiSep
	FuncFunc : 获取数据各个信息域
	Input	 : unsigned char *	— pucInputData		输入的数据
	           int     			— iInputDataLen	输入的数据长度
			   unsigned int		— uiFieldFlag		哪个信息域标志
			   unsigned char	— ucSeparator		各个域信息之间分隔符
			   unsigned char	— ucStopChar		特殊截止或者停止字符
			   unsigned char    -  ucZeroStopFlag	是否支持0x00截止字符0-不支持 1或非0-支持
	Output	 : unsigned int *	— puiOffset		输出下一个信息域开始位置
	           unsigned char *	— pucOutputData	输出对应信息域的数据
	           unsigned int *	— puiOutputDatalen	输出对应信息域的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 支持连续分隔符,但是连续的分隔符只看作一个
	History  : None
	Other    : 如:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforByMultiSep(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,
			unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);
			
/***********************************************************************************************
	FuncName : Tool_BuildStrField
	FuncFunc : 打包MIS每个域
	Input	 : const unsigned char *	— pucInputData		输入的打包数据
			   unsigned int				— uiInputDataLen	输入的打包数据长度
			   unsigned char 			— ucSepFlag		是否打包域分隔符 0-不打包域分隔符 1-打包域分隔符
			   unsigned char * 			— pucSeparator		输入的域分隔符
			   unsigned int  			— uiSeparatorLen	输入的域分隔符长度
	Output	 : unsigned char *			— pucOutputData	输出最终的打包数据
			   unsigned int	*			— puiOutputDataLen 输出最终的打包数据长度
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS
										— 失败,返回相应错误信息(非0x00)
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BuildStrField(const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucSepFlag,
								unsigned char *pucSeparator,unsigned int uiSeparatorLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_BuildMisField
	FuncFunc : 打包MIS每个域
	Input	 : const unsigned char *	— pucInputData		输入的打包数据
			   unsigned int				— uiInputDataLen	输入的打包数据长度
			   unsigned char 			— ucSepFlag		是否打包域分隔符 0-不打包域分隔符 1-打包域分隔符
			   unsigned char 			— ucFiledSepSign	输入的域分隔符(默认输入FS=0x1C)
	Output	 : unsigned char *			— pucOutputData	输出最终的打包数据
			   unsigned int	*			— puiOutputDataLen 输出最终的打包数据长度
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS
										— 失败,返回相应错误信息(非0x00)
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BuildMisField(const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucSepFlag,unsigned char ucFiledSepSign,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMisField
	FuncFunc : 根据uiFieldIndex获取指定的参数值
	Input	 : unsigned int				— uiFieldIndex		输入的域索引
			   unsigned char			— ucNullFlag		输入的域索引该域是否可以为空标志 0-不可以为空 1或非0-可以为空
			   unsigned char 			— ucFiledSepSign	输入的域分隔符(默认输入FS=0x1C)
			   const unsigned char *	— pucInputData		输入的数据
			   unsigned int				— uiInputDataLen	输入的数据长度
	Output	 : unsigned char *			— pucOutputData	输出的参数
	           unsigned int *			— puiOutputLen		输出的参数长度
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS
										— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMisField(unsigned int uiFieldIndex,unsigned char ucNullFlag,unsigned char ucFiledSepSign,const unsigned char *pucInputData,const unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetDataField
	FuncFunc : 根据域表索引获取指定域的参数值
	Input	 : const unsigned char *	— pucInputData		输入的数据
	           DataFieldTab *			— pDataFieldTab	输入的域表
			   unsigned int				— uiExpectLen		获取该域最大输出的长度
			   unsigned char			— ucNullFlag		输入的域索引该域是否可以为空标志 0-不可以为空 1或非0-可以为空
			   DataFieldTab *			— pDataFieldTab	输入的数据
	Output	 : unsigned char *			— pucOutputData	输出的参数
	           unsigned int *			— puiOutputLen		输出的参数长度
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS
										— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDataField(const unsigned char *pucInputData,DataFieldTab *pDataFieldTab,unsigned int uiExpectLen,unsigned char ucNullFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_BuildDataField
	FuncFunc : 打包每个数据域
	Input	 : const unsigned char *	— pucInputData		输入的打包数据
			   unsigned int				— uiInputDataLen	输入的打包数据长度
			   unsigned char 			— ucFiledSepSign	输入的域分隔符(默认输入FS=0x1C)
			   unsigned int 			— uiMaxFiledSize	输入的最多域个数
	Output	 : DataFieldTab *			— DataFieldTab		输出最终的打包数据
	           unsigned int *			— puiDataFiledNum	输出打包域个数
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS
										— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BuildDataField(const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFiledSepSign,unsigned int uiMaxFiledSize,DataFieldTab *pDataField,unsigned int *puiDataFiledNum);

/***********************************************************************************************
	FuncName 	: Tool_DisplayAscData
	FuncFunc 	: 显示报文日志到屏幕
    Input	 	: unsigned char *	—	pucInputTitle 	显示日志标题
    			  unsigned char *	—	pucInputData	显示输入数据
	Output	 	: None
	Return	 	: unsigned char		— 成功,返回TOOL_SUCCESS(0x00)
									— 失败,返回TOOL_FAILURE(0x01)
	Author		: Sunrier
	Date     	: 2013-12-24 19:13:21
	Descp    	: None
	History  	: None
	Other    	: None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayAscData(unsigned char *pucInputTitle,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_DisplayHexData
	FuncFunc : 16进制方式显示数据到界面
	Input	 : unsigned char *	— pucInputTitle	输入的标题
			   unsigned char *	— pucInputData		输入的数据
			   unsigned int		— uiInputDataLen	输入的数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayHexData(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_BeepWarning
	FuncFunc : 显示提示信息并警报
	Input	 : unsigned char *	— pucInputData	输入的提示信息
	Output	 : None
	Return	 : unsigned char 	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BeepWarning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_Warning
	FuncFunc : 显示提示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
	Output	 : None
	Return	 : unsigned char 	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 默认5秒超时
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Warning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_WarningEx
	FuncFunc : 显示提示信息
	Input	 : unsigned char    — ucTimerFlag	    输入是否支持超时 0-不支持 1-支持
			   unsigned long	— ulInputSeconds	输入设置的超时时间(S)
	           unsigned char *	— pucInputData		输入的提示信息
	Output	 : None
	Return	 : unsigned char 	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 可设置超时时间
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_FormatWarning
	FuncFunc : 显示提示信息
	Input	 : const char *		— pFmt			格式化字符串
	Output	 : None
	Return	 : unsigned char 	— ucKey		输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FormatWarning(const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_FormatWarningEx
	FuncFunc : 显示提示信息
	Input	 : unsigned char    — ucTimerFlag	    输入是否支持超时 0-不支持 1-支持
			   unsigned long	— ulInputSeconds	输入设置的超时时间(S)
			   const char *		— pFmt				格式化字符串
	Output	 : None
	Return	 : unsigned char 	— ucKey			输出获取的按键值	0x00-表示超时
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 可设置超时时间
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FormatWarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_CheckLogLevel
	FuncFunc : 检查当前日志标志是否为指定的日志等级
	Input	 : unsigned char	— ucInputLogFlag 	输入的调试等级
		       unsigned char 	— ucLogCheckLevel	检查的日志等级
		       										LOG_CHECK_LEVEL:
		       										           0-无日志级别
		       												   1-ERROR级别 
		       												   2-WARN级别
		       												   3-INFO级别
		       												   4-DEBUG级别
		       												   5-ALL级别
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLogLevel(unsigned char ucInputLogFlag,unsigned char ucLogCheckLevel);

/***********************************************************************************************
	FuncName : Tool_TraceLog
	FuncFunc : 跟踪信息显示到文件
	Input	 : unsigned char	— ucLogFlag		LOG标志:0-不检查日志级别,输出不带调试信息 
	                                                        1-检查日志级别,输出带对应日志级别的调试信息 
	                                                        2-不检查日志级别,输出带调试信息
	                                                        3-检查日志级别,输出不带调试信息 
			   unsigned char	— ucInputLogLevel 	输入的调试等级(枚举类型LOG_LEVEL的组合使用)
		       unsigned char 	— ucCheckLogLevel	检查的日志等级(参考枚举类型LOG_CHECK_LEVEL)
		                                                           :0-无日志级别
		       												   	   1-ERROR级别
		       												   	   2-WARN级别
		       												   	   3-INFO级别
		       												   	   4-DEBUG级别
		       												   	   5-ALL级别
			   unsigned char *	— pucInputFilePathName	输入保存的文件路径
			   unsigned char *	— pucInputFileName		输入保存的文件名
			   unsigned char    — ucFileFlag			输入保存文件附加标志
			   											ucFileFlag:0-无附加信息 1-保存的文件名加入日期后缀
			   unsigned char    — ucCRFlag				输入格式换行标志
			                                            ucCRFlag 0x00-不换行 
										    	        ucCRFlag&0x01-写文件信息之前先换行
										    	        ucCRFlag&0x02-写文件信息完换行 
		       char *			— pcDebugFileName		当前程序跟踪的文件名
			   int				— iLine				该文件跟踪所在行
			   const char *		— pFmt					格式化字符串
			   ...				-  						格式化字符串
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : 如ucCRFlag=0x03-写文件信息之前先换行和写文件信息完都换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TraceLog(unsigned char ucLogFlag,unsigned char ucInputLogLevel,unsigned char ucCheckLogLevel,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,char *pcDebugFileName,int iLine,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_TraceInfor
	FuncFunc : 跟踪信息显示到界面
	Input	 : unsigned char    — ucFormatFlag		输入格式标志
	           char *			— pcDebugFileName	当前程序跟踪的文件名
			   int				— iLine			该文件跟踪所在行
			   const char *		— pFmt				格式化字符串
			   ...				-  					格式化字符串
	Output	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01或其它非0)
	Return	 : void
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : ucFormatFlag 0x00-不换行 
    	       ucFormatFlag&0x01-显示信息之前先换行 
    		   ucFormatFlag&0x02-显示信息完换行 
    		   ucFormatFlag&0x03-显示信息之前先换行和写文件信息完都换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TraceInfor(unsigned char ucFormatFlag,char *pcDebugFileName,int iLine,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_IsNullData
	FuncFunc : 判断输入数据是否为空
	Input	 : unsigned char *	— pucInputData		输入数据
			   unsigned int *	— uiInputDataLen	输入数据的长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS 	表示为空
								— 失败,返回TOOL_FAILURE	表示不为空
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsNullData(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_SetStatus
	FuncFunc : 设置某个状态位
	Input	 : unsigned char *	— pucInOutputData 	输入数据
		       unsigned char 	— ucStatusFlag 	输入某个位的状态值
	Output	 : unsigned char *	— pucInOutputData 	输出数据
	Return	 : unsigned char	— 成功返回TOOL_SUCCESS(0x00)
								— 失败返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetStatus(unsigned char *pucInOutputData,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetStatus
	FuncFunc : 复位某个状态位
	Input	 : unsigned char *	— pucInOutputData 	输入数据
		       unsigned char 	— ucStatusFlag 	输入某个位的状态值
	Output	 : unsigned char *	— pucInOutputData 	输出数据
	Return	 : unsigned char	— 成功返回TOOL_SUCCESS(0x00)
								— 失败返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetStatus(unsigned char *pucInOutputData,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetUsStatus
	FuncFunc : 复位某个状态位
	Input	 : unsigned short *	— pusInOutputData 	输入数据
		       unsigned short 	— usStatusFlag 	输入某个位的状态值
	Output	 : unsigned short *	— pusInOutputData 	输出数据
	Return	 : unsigned char	— 成功返回TOOL_SUCCESS(0x00)
								— 失败返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 短整型数据
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetUsStatus(unsigned short *pusInOutputData,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetUiStatus
	FuncFunc : 复位某个状态位
	Input	 : unsigned int *	— puiInOutputData 	输入数据
		       unsigned int 	— uiStatusFlag 	输入某个位的状态值
	Output	 : unsigned int *	— puiInOutputData 	输出数据
	Return	 : unsigned char	— 成功返回TOOL_SUCCESS(0x00)
								— 失败返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 整型数据
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetUiStatus(unsigned int *puiInOutputData,unsigned int uiStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckStatus
	FuncFunc : 检测某个状态位的值是否相同
	Input	 : unsigned char	— ucInputData 		输入数据
		       unsigned char 	— ucStatusFlag 	输入某个位的状态值
	Output	 : None
	Return	 : unsigned char	— 相同返回TOOL_SUCCESS(0x00)
								— 不相同返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 字节
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckStatus(unsigned char ucInputData, unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckUshortStatus
	FuncFunc : 检测某个状态位的值是否相同
	Input	 : unsigned short	— usInputData 	输入数据
		       unsigned short 	— usStatusFlag 	输入某个位的状态值
	Output	 : None
	Return	 : unsigned char	— 相同返回TOOL_SUCCESS(0x00)
								— 不相同返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 短整型
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckUshortStatus(unsigned short usInputData, unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckUihortStatus
	FuncFunc : 检测某个状态位的值是否相同
	Input	 : unsigned int		— uiInputData 	输入数据
		       unsigned int 	— uiStatusFlag 	输入某个位的状态值
	Output	 : None
	Return	 : unsigned char	— 相同返回TOOL_SUCCESS(0x00)
								— 不相同返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : 长整型
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckUihortStatus(unsigned int uiInputData, unsigned int uiStatusFlag);

/***********************************************************************************************
	FuncName : Tool_GetSecByDiffDate
    FuncFunc : 计算输入的起始日期与终止日期之间的间隔秒数
	Input	 : cconst unsigned char *	— pucBeginDate,输入起始日期(YYYYMMDDHHMMSS)
	           const unsigned char *	— pucEndDate,输入终止日期(YYYYMMDDHHMMSS)
	Output	 : long *					— plIntervalSec,输出起始日期与终止日期之间的间隔秒数
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS(0x00)
					 					— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 输入格式:YYYYMMDDHHMMSS
	History  : None
	Other    : 开始日期必须小于等于终止日期
*************************************************************************************************/
EXPORT unsigned char Tool_GetSecByDiffDate(const unsigned char *pucBeginDate,const unsigned char *pucEndDate,long *plIntervalSec);

/***********************************************************************************************
	FuncName : Tool_GetDayByDiffDate
    FuncFunc : 计算输入的起始日期与终止日期之间的间隔天数
	Input	 : cconst unsigned char *	— pucBeginDate,输入起始日期(YYYYMMDD)
	           const unsigned char *	— pucEndDate,输入终止日期(YYYYMMDD)
	Output	 : int *					— piIntervalDay,输出起始日期与终止日期之间的间隔天数
	Return	 : unsigned char			— 成功,返回TOOL_SUCCESS(0x00)
					 					— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 输入格式:YYYYMMDD
	History  : None
	Other    : 开始日期必须小于等于终止日期
*************************************************************************************************/
EXPORT unsigned char Tool_GetDayByDiffDate(unsigned char *pucBeginDate,unsigned char *pucEndDate,int *piIntervalDay);

/***********************************************************************************************
	FuncName : Tool_GetMonthByDiffDate
    FuncFunc : 计算输入的起始日期与终止日期之间的间隔月数
	Input	 : unsigned char *	— pucBeginDate,输入起始日期(YYYYMMDD)
	           unsigned char *	— pucEndDate,输入终止日期(YYYYMMDD)
	Output	 : int *			— piIntervalMonth,输出起始日期与终止日期之间的间隔月数
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 输入格式:YYYYMMDD
	History  : None
	Other    : 开始日期必须小于终止日期
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthByDiffDate(unsigned char *pucBeginDate,unsigned char *pucEndDate,int *piIntervalMonth);

/***********************************************************************************************
	FuncName : Tool_CheckLeapYear
	FuncFunc : 检查一个年份是否为闰年
	Input	 : unsigned long 	— ulInputYear 输入年份(格式:YYYY)
	Output	 : None
	Return	 : unsigned char	— 闰年,返回TOOL_SUCCESS
								— 非闰年,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如2012
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLeapYear(unsigned long ulInputYear);

/***********************************************************************************************
	FuncName : Tool_CheckValidDate
	FuncFunc : 检查日期是否合法
	Input	 : unsigned char 	— ucFormatFlag 输入日期格式: 0x00-YYYYMMDD(8字节) 
															  0x01-YYYYMM(6字节)
														      0x02-YYMMDD(6字节)
														      0x03-YYMM(4字节)
														      0x04-MMDD(4字节)
														      0x05-HHMMSS(6字节)
														      0x06-YYYYMMDDHHMMSS(14字节)
														      0x07-YYYY/MM/DD HH:MM:SS(19字节)
														      0x08-YYYY-MM-DD HH:MM:SS(19字节)													      
														      0x09-HH:MM:SS(8字节)
														      0x10-YYYYMMDD(4字节)
															  0x11-YYYYMM(3字节)
														      0x12-YYMMDD(3字节)
														      0x13-YYMM(2字节)
														      0x14-MMDD(2字节)
														      0x15-HHMMSS(3字节)
														      0x16-YYYYMMDDHHMMSS(7字节)
	           unsigned char *	— pucInputDate 输入日期(格式:YYYYMMDD)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 当为MMDD时,不检查年份
	History  : None
	Other    : 如20120203
*************************************************************************************************/
EXPORT unsigned char Tool_CheckValidDate(unsigned char ucFormatFlag,unsigned char *pucInputDate);

/***********************************************************************************************
	FuncName : Tool_GetYesterday
    FuncFunc : 给出一个日期(YYYYMMDD或YYYY-MM-DD或YYYY/MM/DD),返回这个日期前面的一天
	Input	 : unsigned char *	— pucInputDate		输入日期信息
	           unsigned char   	— ucFormatFlag		输入输出日期的格式 
											        0x00:和原输入格式一样 0x01:YYYYMMDD 0x02:YYYY-MM-DD 0x03:YYYY/MM/DD
	Output	 : unsigned char *	— pucOutputDate	输出日期信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 日期格式:YYYYMMDD
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetYesterday(unsigned char *pucInputDate,unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetTomorrow
	FuncFunc : 给出一个日期(YYYYMMDD或YYYY-MM-DD或YYYY/MM/DD),返回这个日期后面的一天
	Input	 : unsigned char *	— pucInputDate		输入日期信息
	           unsigned char   	— ucFormatFlag		输入输出日期的格式 
											        0x00:和原输入格式一样 0x01:YYYYMMDD 0x02:YYYY-MM-DD 0x03:YYYY/MM/DD
	Output	 : unsigned char *	— pucOutputDate	输出日期信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : 输入日期格式由ucFormatFlag指定
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTomorrow(unsigned char *pucInputDate,unsigned char ucFormatFlag,unsigned char *pucOutputDate);;

/***********************************************************************************************
	FuncName : Tool_CheckDateExp
	FuncFunc : 检查日期是否已经过期
	Input	 : unsigned char *	— pucInputDateExp 输入日期时间的字符串(YYYYMMDD)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)即过期
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 日期时间的字符串 YYYYMMDD
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckDateExp(unsigned char *pucInputDateExp);

/***********************************************************************************************
	FuncName : Tool_CheckDigital
	FuncFunc : 检查输入的数据是否为数字字符组成
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned char 	— ucFlag			输入数据为空是否支持:0-不支持 1-支持
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckDigital(unsigned char *pucInputData,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_CheckAlpOrDig
	FuncFunc : 检查输入的数据是否为数字或字母
	Input	 : unsigned char *	— pucInputData		输入的数据
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAlpOrDig(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAlpOrDigEx
	FuncFunc : 检查输入的数据是否字母和数字组成,可以包含一个特殊字符
	Input	 : unsigned char *	— pucInputData		输入的信息
		       unsigned char 	— ucSpeCh			输入一个可以包含的特殊字符
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAlpOrDigEx(unsigned char *pucInputData,unsigned char ucSpeCh);

/***********************************************************************************************
	FuncName : Tool_CheckHex
	FuncFunc : 检查输入的数据是否为十六进制字符组成
	Input	 : unsigned char *	— pucInputData,输入的数据
	           unsigned int		— uiInputDataLen,输入数据的长度
	           unsigned char 	— ucHexCaseFlag,输入字母是否大小写:0-不检查 1-必须大写 2-必须小写
	           unsigned char 	— ucNullFlag,输入数据为空是否支持:0-不支持 1-支持
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : pucInputData='2E3F0103',返回TOOL_SUCCESS
	           pucInputData='2QDW3DFK',返回TOOL_FAILURE
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckHex(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucHexCaseFlag,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_CheckValidIp
	FuncFunc : 检查输入的IP地址是否有效
	Input	 : unsigned char *	— pucInputData		输入的IP数据
	Output	 : None
	Return	 : unsigned char	— 有效成功,返回TOOL_SUCCESS(0x00)
					 			— 无效失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckValidIp(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAmount
	FuncFunc : 检查输入的金额是否有效
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned char 	— ucCheckBit		是否检查带有小数点金额的位数:0-不检查 1-检查ucCheckBit位金额
	           unsigned char 	— ucFixBitFlag		是否小数点金额的位数固定:0-不固定 1-固定
	           unsigned char 	— ucZeroFlag		金额是否可以为0标志:0-不可以 1-可以
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 最大12位(最大值999999999L)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmount(unsigned char *pucInputData,unsigned char ucCheckBit,unsigned char ucFixBitFlag,unsigned char ucZeroFlag);

/***********************************************************************************************
	FuncName : Tool_CheckAmountEx
	FuncFunc : 检查输入的价格是否合法最大13位(包含小数点)
	Input	 : unsigned char *	— pucInputData		输入的数据	
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 检查输入的价格, 输入价格如果有小数点,小数点后面最多两位
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmountEx(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAmountWithPoint
	FuncFunc : 检查输入的带有小数点金额是否有效
	Input	 : unsigned char *	— pucInputData		输入的数据		       
	           unsigned char 	— ucPointBit		小数点金额的位数
	           unsigned char 	— ucCheckBit		是否检查带有小数点金额的位数:0-不检查 1-检查ucCheckBit位金额
	           unsigned char 	— ucFixBitFlag		是否小数点金额的位数固定:0-不固定 1-固定
	           unsigned char 	— ucZeroFlag		金额是否可以为0标志:0-不可以 1-可以
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ucCheckBit!=0时,最大ucCheckBit位(最大值999999999.99f)
	History  : None
	Other    : 格式:xxx.xx or xxx.x
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmountWithPoint(unsigned char *pucInputData,unsigned char ucPointBit,unsigned char ucCheckBit,unsigned char ucFixBitFlag,unsigned char ucZeroFlag);

/***********************************************************************************************
	FuncName : Tool_CheckFloatZero
	FuncFunc : 检查输入的符点数是否为0
	Input	 : float			— fInputData,输入的数据
	Output	 : None
	Return	 : unsigned char	— 0,返回TOOL_SUCCESS(0x00)
					 			— 不为0,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckFloatZero(float fInputData);

/***********************************************************************************************
	FuncName : Tool_IsBlankspace
	FuncFunc : 检查输入的数据是否为只是空格
	Input	 : unsigned char *	— pucInputData		输入的数据
	           unsigned char 	— ucFlag			输入数据为空是否支持:0-不支持 1-支持
	Output	 : None
	Return	 : unsigned char	— 只是空格,返回TOOL_SUCCESS(0x00)
					 			— 不只是空格,返回相应错误信息(非0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsBlankspace(unsigned char *pucInputData,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_InputText
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputText(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputTextEx
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned char *	— pucInOutputData	输入信息
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
			   unsigned char	— ucAlpFlag		输入是否输入字母和符号支持'#'键切换
	Output	 : unsigned char *	— pucInOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputTextEx(unsigned char* pucInputTitle,unsigned char *pucInOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char ucAlpFlag,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputNum
	FuncFunc : 输入一个数字组成的信息,只由数字字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
			   unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,只由数字字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputNum(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputNumber
	FuncFunc : 输入一个信息,只由数字组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(最小为长度1,不可以为0)
			   unsigned int		— uiMaxLen			输入的信息最大长度
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen 输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,只由数字组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputNumber(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPwd
	FuncFunc : 输入一个信息的密码,只由数字字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucDispMode		输入显示模式-0x00-靠左对齐显示(默认方式) 0x01-靠右对齐显示
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
		       unsigned int *	— puiOutputDataLen 输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个密码,只由数字字符组成(支持显示对齐模式)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPwd(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWord
	FuncFunc : 输入一个信息的密码,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned char	— ucDispMode		输入显示模式-0x00-靠左对齐显示(默认方式) 0x01-靠右对齐显示
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen 输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个密码,可以由数字和字母以及可显示字符组成(支持显示对齐模式)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWord(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWordText
	FuncFunc : 输入一个信息的密码,可以由数字和字母以及可显示字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen 输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个密码,可以由数字和字母以及可显示字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWordText(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWordNum
	FuncFunc : 输入一个数字组成的密码,只由数字字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen 输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个密码,只由数字字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWordNum(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputBcd
	FuncFunc : 输入一个BCD码格式的信息
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个BCD码格式的信息,由'0'到'9'或者'A'到'F'字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputBcd(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputIp
	FuncFunc : 输入一个IP地址信息,只由数字字符和.字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
			   unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个IP地址信息,只由数字和.字符组成,如138.12.89.67
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputIp(unsigned char *pucInputTitle,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputCn
	FuncFunc : 输入一个信息,可以由数字和字母以及可显示中文字符组成
	Input	 : unsigned char *	— pucInputTitle	输入显示的标题
			   unsigned int		— uiMinLen			输入的信息最小长度(如果为0,可以为空)
			   unsigned int		— uiMaxLen			输入的信息最大长度
			   unsigned int		— uiTimeout		输入的超时时间
	Output	 : unsigned char *	— pucOutputData	输出输入信息
	           unsigned int *	— puiOutputDataLen	输出输入信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 超时,返回TOOL_TIMEOUT(0x02)
								— 用户取消,返回TOOL_KEYCANCEL(0x03)(ESC键)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : 输入一个数据信息,可以由数字和字母以及可显示中文字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputCn(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputAmout
	FuncFunc : 输入金额信息,只由数字字符组成
	Input	 : unsigned char 	— ucStartLine			输入的起始行数
	           unsigned char *	— pucMsgPrompt			输入显示的标题
	           unsigned char 	— ucNegativeFlag		输入金额正负标志
	           unsigned char *	— pucCurrencyName		输入的货币名称
			   unsigned char	— ucZeroAmtAllowFlag	输入的是否可以金额为0标志 TRUE-可以为全0 其它-不可以
	Output	 : unsigned char *	— pucOutputData		输出输入的金额信息
	Return	 : unsigned char	— 成功,返回MISAPP_OK
					 			— 失败,返回非MISAPP_OK
	Author	 : Sunrier
	Date     : 2013-05-09 19:10:22
	Descp    : 输入一个金额信息,只由数字字符组成
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputAmout(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char ucNegativeFlag,unsigned char *pucCurrencyName,unsigned char ucZeroAmtAllowFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountCmp
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
EXPORT int Tool_AmountCmp(unsigned char *pucAmount1,unsigned char *pucAmount2);

/***********************************************************************************************
	FuncName : Tool_AddAmountPoint
	FuncFunc : 将字符串金额末尾添加小数点
	Input	 : unsigned char *	— pucInputData		输入字符串金额
	           unsigned char 	— ucTrimZeroFlag	输入末尾0是否去掉标志:0-不去掉 1-去掉
	Output	 : unsigned char *	— pucOutputData	输出带有小数点的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : 例:pucInputData=2000068,ucTrimZeroFlag=0,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=0,pucOutputData=200006.80
	              pucInputData=2000068,ucTrimZeroFlag=1,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=1,pucOutputData=200006.8
*************************************************************************************************/
EXPORT unsigned char Tool_AddAmountPoint(unsigned char *pucInputData,unsigned char ucTrimZeroFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_TrimAmountPoint
	FuncFunc : 去掉字符串金额小数点
	Input	 : unsigned char *	— pucInputData		输入带有小数点的字符串金额
	Output	 : unsigned char *	— pucOutputData	输出的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : 例:pucInputData=20000.68,pucOutputData=2000068;pucInputData=200006.8,pucOutputData=20000680
*************************************************************************************************/
EXPORT unsigned char Tool_TrimAmountPoint(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountAdd
	FuncFunc : 两个字符串字符金额相加
	Input	 : unsigned char *	— pucAdd1			输入字符串金额1
			   unsigned char *	— pucAdd2			输入字符串金额2
			   unsigned char 	— ucMaxLen			输入字符串金额最大长度(当ucMaxLen=0时,默认ucMaxLen;其它为0<ucMaxLen<=50)
	Output	 : unsigned char *	— pucOutputData	输出的相加后的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucAdd1 + pucAdd2
	History  : None
	Other    : 例:100+203=303
*************************************************************************************************/
EXPORT unsigned char Tool_AmountAdd(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountAddEx
	FuncFunc : 两个字符串字符金额相加
	Input	 : unsigned char *	— pucAdd1			输入字符串金额1
			   unsigned char *	— pucAdd2			输入字符串金额2
			   unsigned char 	— ucMaxLen			输入字符串金额最大长度(当ucMaxLen=0时,默认ucMaxLen;其它为0<ucMaxLen<=50)
	Output	 : unsigned char *	— pucOutputData	输出的相加后的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回相应错误信息
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 + pucSub2
	History  : None
	Other    : 例:1.00+2.03=3.03
*************************************************************************************************/
EXPORT unsigned char Tool_AmountAddEx(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountSub
	FuncFunc : 两个字符串字符金额相减
	Input	 : unsigned char *	— pucSub1			输入字符串金额1
			   unsigned char *	— pucSub2			输入字符串金额2
	Output	 : unsigned char *	— pucOutputData	输出的相减后的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 - pucSub2
	History  : None
	Other    : pucSub1>=pucSub2
*************************************************************************************************/
EXPORT unsigned char Tool_AmountSub(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountSubEx
	FuncFunc : 两个字符串字符金额相减
	Input	 : unsigned char *	— pucSub1			输入字符串金额1
			   unsigned char *	— pucSub2			输入字符串金额2
	Output	 : unsigned char *	— pucOutputData	输出的相减后的字符串金额
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 - pucSub2
	History  : None
	Other    : 例:3.00-2.03=0.97
*************************************************************************************************/
EXPORT unsigned char Tool_AmountSubEx(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_GetPrincipalInterest
	FuncFunc : 获取利息或本金
	Input	 : double 			— dPrincipal,输入本金
			   double			— dInterestRate,输入利率或者投资回报率
			   unsigned int		— uiInterestYear,输入投资年限
			   unsigned char	— ucFlag,输入获取利息或本金标志:0-本利和(包含利息) 1-利息
	Output	 : double *			— pdPrincipalInterest,输出利息或本金
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPrincipalInterest(double dPrincipal,double dInterestRate,unsigned int uiInterestYear,unsigned char ucFlag,double *pdPrincipalInterest);

/*********************************************************************************************** 
	FuncName : Tool_GetAnnualInterestRate
	FuncFunc : 获取年复合率
	Input	 : double 			— dOrgPrincipal,输入原始本金
			   double 			— dFinalPrincipal,输入最终本金(本利和)
			   unsigned int		— uiInterestYear,输入投资年限
	Output	 : unsigned char *	— pucInterestRate,输出年复合率(单位%)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : 输出5%,表示0.05
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetAnnualInterestRate(double dOrgPrincipal,double dFinalPrincipal,unsigned int uiInterestYear,unsigned char *pucInterestRate);

/*********************************************************************************************** 
	FuncName : Tool_GetInterestYear
	FuncFunc : 获取利息或本金
	Input	 : double 			— dPrincipal,输入本金(不包含利息)
	           double 			— dInterest,输入利息
			   double			— dInterestRate,输入利率或者投资回报率
	Output	 : unsigned int *	— puiInterestYear,输出投资年限
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInterestYear(double dPrincipal,double dInterest,double dInterestRate,unsigned int *puiInterestYear);

/***********************************************************************************************
	FuncName : Tool_GetRoi
	FuncFunc : 获取ROI
	Input	 : unsigned char *	— pucInputData1    输入的原始金额
	           unsigned char *	— pucInputData2    输入的当前金额
	           unsigned char 	— ucRoiFlag    	输入的ROI格式标志:0-不带百分比 非0-带百分比
	Output	 : unsigned char *	— pucOutputData    输出ROI
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRoi(unsigned char *pucInputData1,unsigned char *pucInputData2,unsigned char ucRoiFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetExpWeightFactor
	FuncFunc : 获取指数权重系数比例分配
	Input	 : WEIGHTFACTOR_PRM *	— pWeightFactor    输入的权重系数信息
	           unsigned int			— uiWeightNum    	输入的权重数量
	           double				— dMinWeight    	输入的最小权重
	           long					— lPrecision    	输入的总比例
	           unsigned char		— ucPercentFactor  输入的权重系数比例分配因子:0-权重系数越大比例分配越小 
	                                                                               1-权重系数越大比例分配越大
	Output	 : WEIGHTFACTOR_PRM *	— pWeightFactor    输出的权重系数信息
	Return	 : unsigned char		— 成功,返回TOOL_SUCCESS(0x00)
									— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetExpWeightFactor(WEIGHTFACTOR_PRM pWeightFactor[],unsigned int uiWeightNum,double dMinWeight,long lPrecision,unsigned char ucPercentFactor);

/***********************************************************************************************
	FuncName : Tool_GetWeightFactor
	FuncFunc : 获取标准权重系数比例分配
	Input	 : WEIGHTFACTOR_PRM *	— pWeightFactor    输入的权重系数信息
	           unsigned int			— uiWeightNum    	输入的权重数量
	           long					— lPrecision    	输入的总比例
	           unsigned char		— ucPercentFactor  输入的权重系数比例分配因子:0-权重系数越大比例分配越小 
	                                                                               1-权重系数越大比例分配越大
	Output	 : WEIGHTFACTOR_PRM *	— pWeightFactor    输出的权重系数信息
	Return	 : unsigned char		— 成功,返回TOOL_SUCCESS(0x00)
									— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetWeightFactor(WEIGHTFACTOR_PRM pWeightFactor[],unsigned int uiWeightNum,long lPrecision,unsigned char ucPercentFactor);

/***********************************************************************************************
	FuncName : Tool_GetComputerName
	FuncFunc : 获取当前电脑名称
	Input	 : None
	Output	 : unsigned char *	— pucOutputData    输出的信息
	           unsigned int *	— puiOutputDataLen 输出的信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetComputerName(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetPriceTrend
	FuncFunc : 获取趋势
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPriceTrend( void );

/***********************************************************************************************
	FuncName : Tool_GetROI
	FuncFunc : 获取ROI
	Input	 : unsigned char *	— pucInputData1    输入的信息1
	           unsigned char *	— pucInputData2    输入的信息2
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetROI(unsigned char *pucInputData1,unsigned char *pucInputData2);

/***********************************************************************************************
	FuncName : Tool_GetUserName
	FuncFunc : 获取当前用户名
	Input	 : None
	Output	 : unsigned char *	— pucOutputData    输出的信息
	           unsigned int *	— puiOutputDataLen 输出的信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetUserName(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_IsTlv
	FuncFunc : 判断并解析一段内存是否是一个TLV结构并输出TLV结构信息
	Input	 : unsigned char *	— pucInputData    输入的信息
	           int 			    — iInputDataLen   输入的信息长度
	           TLV *			— pTlv    		   输入的TLV结构信息
	Output	 : int *			— piOutputTlvLen  输出解析的TLV结构长度
	Return	 : unsigned char	— 是一个TLV结构,返回TOOL_SUCCESS(0x00)
								— 不是一个TLV结构,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsTlv(unsigned char* pucInputData,int iInputDataLen,TLV *pTlv,int *piOutputTlvLen);

/***********************************************************************************************
	FuncName : Tool_CheckTlv
	FuncFunc : 判断是否是一个TLV结构
	Input	 : unsigned char *	— pucInputData    输入的信息
	           int 			    — iInputDataLen   输入的信息长度
	Output	 : None
	Return	 : unsigned char	— 是一个TLV结构,返回TOOL_SUCCESS(0x00)
								— 不是一个TLV结构,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTlv(unsigned char *pucInputData,int iInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetTlvLen
	FuncFunc : 获取TLV结构数据长度
	Input	 : TLV *			— pTlv    			输入的TLV结构信息
	Output	 : int *			— piOutputTlvLen  	输出解析的TLV结构长度
	Return	 : unsigned char	— 是一个TLV结构,返回TOOL_SUCCESS(0x00)
								— 不是一个TLV结构,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTlvLen(TLV *pTlv,int *piOutputTlvLen);

/***********************************************************************************************
	FuncName : Tool_TlvEncode
	FuncFunc : TLV编码,将一个TLV结构转输出到一个缓冲区
	Input	 : TLV *			— pTlv    		   输入的TLV结构信息
	           int 				— iTlvLen  	   输入的TLV结构信息长度
	           int 				— iMaxBufDataLen  输入的输出缓冲区最大长度
	Output	 : unsigned char *	— pucOutputData   输出的信息
	           int * 			— piOutputDataLen 输出的信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TlvEncode(TLV *pTlv,int iTlvLen,int iMaxBufDataLen,unsigned char* pucOutputData,int *piOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_TlvDecode
	FuncFunc : TLV解码,将一个缓冲区信息转换为一个TLV结构
	Input	 : unsigned char *	— pucInputData   输入的信息
			   int 				— iInputDataLen  输入的信息长度	           
	           int 				— iMaxTlvCount   输入的最大TLV数目
	Output	 : TLV *			— pTlv    		  输出的TLV结构信息
	           int * 			— piTlvCount 	  输出的TLV数目
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TlvDecode(unsigned char *pucInputData,int iInputDataLen,int iMaxTlvCount,TLV *pTlv,int *piTlvCount);

/***********************************************************************************************
	FuncName : Tool_GetTlvByTag
	FuncFunc : TLV解码tag,根据对应的TAG获取TLV信息
	Input	 : unsigned char *	— pucInputData   输入的信息
			   int 				— iInputDataLen  输入的信息长度	           
	           int 				— iInputTag   	  输入的TAG
	Output	 : TLV *			— pTlv    		  输出的TLV结构信息	           
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTlvByTag(unsigned char* pucInputData,int iInputDataLen,int iInputTag,TLV *pTlv);

/***********************************************************************************************
	FuncName : Tool_GetTagInfo
    FuncFunc : 获取EMV标签信息
	Input	 : int				— iInputTag输入标签
	Output	 : TLVTAG_PRM *		— pTlvTag	输出EMV标签信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTagInfo(int iInputTag,TLVTAG_PRM *pTlvTag);

/***********************************************************************************************
	FuncName : Tool_GetTagInfoEx
    FuncFunc : 获取EMV标签信息
	Input	 : unsigned char *	— pucInputTag	输入标签
	           int				— iInputTagLen	输入标签的长度
	Output	 : TLVTAG_PRM *		— pTlvTag		输出EMV标签信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTagInfoEx(unsigned char *pucInputTag,int iInputTagLen,TLVTAG_PRM *pTlvTag);

/***********************************************************************************************
	FuncName : Tool_CheckTemplateTag
	FuncFunc : 检查标签是否为模板标签
	Input	 : unsigned char *	— pucInputTag 	输入的标签
	           unsigned char 	— ucInputTagLen输入标签的长度
	Output	 : None
	Return	 : unsigned char	— 模板标签,返回TOOL_SUCCESS
					 			— 非模板标签,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTemplateTag(unsigned char *pucInputTag,unsigned char ucInputTagLen);

/***********************************************************************************************
	FuncName : Tool_GetDescpFromApduCode
    FuncFunc : 获取EMV APDU指令相关返回码描述信息
	Input	 : unsigned char *	— pucInputApduCode 	输入的返回码
	Output	 : unsigned char *	— pucOutputDescpInfo 	输出的返回码对应的描述信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromApduCode(unsigned char *pucInputApduCode,unsigned char *pucOutputDescpInfo);

/***********************************************************************************************
	FuncName : Tool_Des
	FuncFunc : 对数据进行DES加解密或者3DES加解密或者3倍长密钥DES加解密
	Input	 : unsigned char 	— ucDesType		DES加解密算法类型：	
													0表示DES加密数据(Key为8个字节)、1表示DES解密数据(Key为8个字节)、
													2表示3DES加密数据(Key为16个字节)、3表示3DES解密数据(Key为16个字节)、
													4表示三倍长密钥加密数据(Key为24个字节)、5表示三倍长密钥解密数据(Key为24个字节)
			   unsigned char *	— pucInputData		输入的待加密的明文数据/输入的待解密的密文数据,必须为8字节
			   unsigned char *	— pucInputKey		输入的用作加密的传输密钥/输入的用作解密的传输密钥,字节数必须为8的倍数
	Output	 : unsigned char *	— pucOutputData	输出的加密后的密文数据/输出的解密后的明文数据,必须为8字节
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 输入长度必须为8字节
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Des(unsigned char ucDesType,unsigned char *pucInputData,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DesEx
	FuncFunc : 对字符串数据进行DES加解密或者3DES加解密或者3倍长密钥DES加解密
	Input	 : unsigned char 	— ucDesType		DES加解密算法类型：	
													0表示DES加密数据(Key为8个字节)、1表示DES解密数据(Key为8个字节)、
													2表示3DES加密数据(Key为16个字节)、3表示3DES解密数据(Key为16个字节)、
													4表示三倍长密钥加密数据(Key为24个字节)、5表示三倍长密钥解密数据(Key为24个字节)
			   unsigned char *	— pucInputData		输入的待加密的明文数据/输入的待解密的密文数据
			   unsigned	int 	— uiInputDataLen	输入数据长度
			   unsigned char *	— pucInputKey		输入的用作加密的传输密钥/输入的用作解密的传输密钥,字节数必须为8的倍数
	Output	 : unsigned char *	— pucOutputData	输出的加密后的密文数据/输出的解密后的明文数据(同输入长度)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 输入/输出长度不限定为8的倍数
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DesEx(unsigned char ucDesType,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrDes
	FuncFunc : 对字符串数据进行DES加解密或者3DES加解密或者3倍长密钥DES加解密
	Input	 : unsigned char 	— ucDesType		DES加解密算法类型：	
													0表示DES加密数据(Key为16个字节)、1表示DES解密数据(Key为16个字节)、
													2表示3DES加密数据(Key为32个字节)、3表示3DES解密数据(Key为32个字节)、
													4表示三倍长密钥加密数据(Key为48个字节)、5表示三倍长密钥解密数据(Key为48个字节)
			   unsigned char *	— pucInputData		输入的待加密的明文数据/输入的待解密的密文数据,必须为16字节
			   unsigned char *	— pucInputKey		输入的用作加密的传输密钥/输入的用作解密的传输密钥,字节数必须为16/32/48
	Output	 : unsigned char *	— pucOutputData	输出的加密后的密文数据/输出的解密后的明文数据,必须为16字节
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 输入长度必须为16字节字符串数据
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrDes(unsigned char ucDesType,unsigned char *pucInputData,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrDesEx
	FuncFunc : 对字符串数据进行DES加解密或者3DES加解密或者3倍长密钥DES加解密
	Input	 : unsigned char 	— ucDesType		DES加解密算法类型：	
													0表示DES加密数据(Key为16个字节)、1表示DES解密数据(Key为16个字节)、
													2表示3DES加密数据(Key为32个字节)、3表示3DES解密数据(Key为32个字节)、
													4表示三倍长密钥加密数据(Key为48个字节)、5表示三倍长密钥解密数据(Key为48个字节)
			   unsigned char *	— pucInputData		输入的待加密的明文数据/输入的待解密的密文数据,必须为8字节
			   unsigned	int 	— uiInputDataLen	输入数据长度
			   unsigned char *	— pucInputKey		输入的用作加密的传输密钥/输入的用作解密的传输密钥,字节数必须为16的倍数
	Output	 : unsigned char *	— pucOutputData	输出的加密后的密文数据/输出的解密后的明文数据(同输入长度)
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 输入长度不限制
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrDesEx(unsigned char ucDesType,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Diversify
	FuncFunc : 分散算法
	Input	 : unsigned char *	— pucInputData		输入的待分散的原始数据
	           unsigned	int 	— uiInputDataLen	输入的数据长度(输入数据长度必须为8的整数倍,可为8位,16位,24位,对应分散次数)
			   unsigned char *	— pucInputKey		输入的分散密钥
			   unsigned char 	— ucInputKeyLen	输入的密钥长度(16位)
			   unsigned char 	— ucDiversifyTimes	输入的分散次数:1-一次　2-两次　3-三次
	Output	 : unsigned char *	— pucOutputData	输出的分散数据
	           unsigned int  *	— puiOutputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Diversify(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char ucInputKeyLen,unsigned char ucDiversifyTimes,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_EcbCbc
	FuncFunc : DES算法ECB或CBC模式对数据加解密
	Input	 : unsigned	char 	— ucCryptType加解密类型：0表示加密数据、1或其它非0表示解密数据
			   unsigned	char 	— ucMode加解密模式：0表示ECB模式、1或其它非0表示CBC模式
			   unsigned	char *	— pucInputData输入数据(输入数据长度必须为8的整数倍,不足需要自行填充)
			   unsigned	int 	— uiInputDataLen输入数据长度(输入数据长度必须为8的整数倍)
			   unsigned	char *	— pucInputKey输入密钥(可为8字节/16字节/24字节)支持3密钥
			   unsigned	char 	— ucInputKeyLen输入密钥长度(必须为8字节/16字节/24字节三个中的一种)
			   unsigned	char *	— pucInputVector输入icv向量(CBC模式8字节)
	Output	 : unsigned char *	— pucOutputData输出数据(同输入数据长度)
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : 一般默认为ECB模式,输入数据不足8的整数倍函数不会自动填充
	History  : CBC模式8字节icv向量如不指定,默认为8字节的0x00
	Other    : X9.52算法为24字节密钥
*************************************************************************************************/
EXPORT unsigned char Tool_EcbCbc(unsigned char ucCryptType,unsigned char ucMode,unsigned char *pucInputData,unsigned int uiInputDataLen,
			const unsigned char *pucInputKey,const unsigned char ucInputKeyLen,unsigned char *pucInputVector,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrEcbCbc
	FuncFunc : DES算法ECB或CBC模式对字符串数据加解密
	Input	 : unsigned	char 	— ucCryptType加解密类型：0表示加密数据、1或其它非0表示解密数据
			   unsigned	char 	— ucMode加解密模式：0表示ECB模式、1或其它非0表示CBC模式
			   unsigned	char *	— pucInputData输入数据(输入数据长度必须为16的整数倍,不足需要自行填充)
			   unsigned	char *	— pucInputKey输入密钥(必须为16位,32位,48位三个中的一种)支持3密钥
			   unsigned	char *	— pucInputVector输入icv向量(CBC模式16位)
	Output	 : unsigned char *	— pucOutputData输出数据(16位的整数倍)
	Return	 : unsigned	char 	— 成功,返回(0x00)
								— 失败,返回(0x01)
	Author	 : Sunrier
    Date     : 2016-12-05 19:00:55
    Descp    : 一般默认为ECB模式,输入数据不足16的整数倍函数不会自动填充
	History  : CBC模式16位如不指定,默认为16字节的"0000000000000000"
	Other    : X9.52算法为48位密钥
*************************************************************************************************/
EXPORT unsigned char Tool_StrEcbCbc(unsigned char ucCryptType,unsigned char ucMode,unsigned char *pucInputData,
			const unsigned char *pucInputKey,unsigned char *pucInputVector,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_EnDeFile
	FuncFunc : DES/3DES算法对文件加解密
	Input	 : unsigned	char *	— pcuInputReadFullFileName,输入文件名
	           unsigned	char *	— pcuInputWriteFullFileName,输出文件名
	           unsigned char 	— ucDesType,DES加解密算法类型：	
											 0表示DES加密数据(Key为8个字节)、1表示DES解密数据(Key为8个字节)、
											 2表示3DES加密数据(Key为16个字节)、3表示3DES解密数据(Key为16个字节)、
											 4表示三倍长密钥加密数据(Key为24个字节)、5表示三倍长密钥解密数据(Key为24个字节)
			   unsigned	char *	— pucInputKey输入密钥(32位)
	Output	 : None
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								   输入参数错误,TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : 文件名为绝对路径
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_EnDeFile(unsigned char *pcuInputReadFullFileName,char *pcuInputWriteFullFileName,unsigned char ucDesType,unsigned char *pucInputKey);

/***********************************************************************************************
	FuncName : Tool_GeneraterRsaKey
	FuncFunc : 生成RSA公私钥对
	Input	 : unsigned char 		— ucProtoKeyBit	RSA算法密钥长度:模长:0-512位 1-1024位 2-2048位
	           unsigned char 		— ucPubExp			RSA算法指数:0-3 1-65537
	Output	 : RSAPUBLICKEY_PRM *	— pPublicKey		RSA公钥
	           RSAPRIVATEKEY_PRM *	— pPrivateKey		RSA私钥
	Return	 : unsigned char		— 成功,返回(0x00)
									-  失败,返回(0x01或非0)
	Author	 : Sunrier
    Date     : 2016-12-05 19:00:55
    Descp    : 随机生成一对RSA公私钥
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GeneraterRsaKey(unsigned char ucProtoKeyBit,unsigned char ucPubExp,RSAPUBLICKEY_PRM *pPublicKey,RSAPRIVATEKEY_PRM *pPrivateKey);

/***********************************************************************************************
	FuncName : Tool_RsaPublicKey
	FuncFunc : RSA公钥加/解密
	Input	 : unsigned char			— ucRsaType			输入RSA公钥加/解密类型:0-RSA公钥加密数据 1-RSA公钥解密数据
	           unsigned int				— uiRSABit				输入RSA公钥位数 取值为范围为512,1024,2048中的一个
	           unsigned char * 			— pucInputExponent		输入RSA公钥指数
	           unsigned int 			— uiInputExponentLen	输入RSA公钥指数长度
	           unsigned char * 			— pucInputModulus		输入RSA公钥模数
	           unsigned int 			— uiInputModulusLen	输入RSA公钥模数长度
	           unsigned char			— ucPaddingFlag		输入的公钥数据对齐方式:0-RSA_NO_PADDING 1-RSA_PKCS1_PADDING
	           unsigned char * 			— pucInputData			输入的加/解密数据
	           unsigned char * 			— uiInputDataLen		输入的加/解密数据长度
	Output	 : unsigned char *			— pucOutputData		输出公钥加/解密后的数据
	           unsigned int *  			— puiOutputDataLen		输出数据长度
	Return	 : unsigned char			— 成功,返回(0x00)
										— 失败,返回(0x01或非0)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : 公钥加/解密数据
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RsaPublicKey(unsigned char ucRsaType,unsigned int uiRSABit,unsigned char *pucInputExponent,unsigned int uiInputExponentLen,unsigned char *pucInputModulus,unsigned int uiInputModulusLen,unsigned char ucPaddingFlag,const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_RsaPrivateKey
	FuncFunc : RSA私钥加/解密
	Input	 : unsigned char			— ucRsaType			输入RSA私钥加/解密类型:0-RSA私钥加密数据 1-RSA私钥解密数据
	           unsigned int				— uiRSABit				输入RSA私钥位数 取值为范围为512,1024,2048中的一个
	           unsigned char * 			— pucInputModulus		输入RSA私钥模数
	           unsigned int 			— uiInputModulusLen	输入RSA私钥模数长度
	           unsigned char * 			— pucInputP			输入RSA私钥参数P
	           unsigned int 			— uiInputPLen			输入RSA私钥参数P长度
	           unsigned char * 			— pucInputQ			输入RSA私钥参数Q
	           unsigned int 			— uiInputQLen			输入RSA私钥参数Q长度
	           unsigned char * 			— pucInputDp			输入RSA私钥参数Dp
	           unsigned int 			— uiInputDpLen			输入RSA私钥参数Dp长度
	           unsigned char * 			— pucInputDq			输入RSA私钥参数Dq
	           unsigned int 			— uiInputDqLen			输入RSA私钥参数Dq长度
	           unsigned char * 			— pucInputQinv			输入RSA私钥参数Qinv
	           unsigned int 			— uiInputQinvLen		输入RSA私钥参数Qinv长度
	           unsigned char			— ucPaddingFlag		输入的私钥数据对齐方式:0-RSA_NO_PADDING 1-RSA_PKCS1_PADDING
	           unsigned char * 			— pucInputData			输入的私钥加/解密数据
	           unsigned char * 			— uiInputDataLen		输入的私钥加/解密的数据长度
	Output	 : unsigned char *			— pucOutputData		输出私钥加/解密后的数据
	           unsigned int *  			— puiOutputDataLen		输出私钥加/解密后的数据长度
	Return	 : unsigned char			— 成功,返回(0x00)
										— 失败,返回(0x01或非0)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : 私钥加/解密数据
	History  : 私钥加密即私钥签名
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RsaPrivateKey(unsigned char ucRsaType,unsigned int uiRSABit,
	unsigned char *pucInputModulus,unsigned int uiInputModulusLen,
	unsigned char *pucInputP,unsigned int uiInputPLen,
	unsigned char *pucInputQ,unsigned int uiInputQLen,
	unsigned char *pucInputDp,unsigned int uiInputDpLen,
	unsigned char *pucInputDq,unsigned int uiInputDqLen,
	unsigned char *pucInputQinv,unsigned int uiInputQinvLen,
	unsigned char ucPaddingFlag,
	const unsigned char *pucInputData,unsigned int uiInputDataLen,
	unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_SetMEMILineLen
	FuncFunc : 设置Base64的MIME型编码每行最长字符数
	Input	 : int			 	— iMEMILen	输入MIME型编码每行最长字符数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : MIME友好格式,输出每行默认不超过76字符
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetMEMILineLen(int iMEMILen);

/***********************************************************************************************
	FuncName : Tool_Base64Encrypt
	FuncFunc : Base64加密数据
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   unsigned char 	— ucCoderFlag		输入编码编制:
			   											0x00-基本型编码(默认)
			   											0x01-URL和文件名安全型编码
			   											0x02-MIME型编码
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64编码(支持GB2312中文)
	History  : 注意:编码的原始数据如果多次切割处理,输入的每次切割数据长度必须每次为3的倍数长度
	Other    : 和Tool_Base64Decrypt配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Encrypt(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Decrypt
	FuncFunc : Base64解密数据
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   unsigned char 	— ucCoderFlag		输入编码编制:
			   											0x00-基本型编码(默认)
			                                       		0x01-URL和文件名安全型编码
			                                       		0x02-MIME型编码
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64解码(支持GB2312中文)
	History  : None
	Other    : 和Tool_Base64Encrypt配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Decrypt(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64UrlEncode
	FuncFunc : 使用URL base64编码方案
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   int	*			— piOuputDataLen	输出的长度最大BUFFER空间
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 特殊字符处理格式:字符%+HEX 如等号=(%3D)
	History  : 字符’a’-‘z’,’A’-‘Z’,’0’-‘9’,'.','-','_','*'和'/'都不被编码,维持原值;
			   空格' '被转换为加号'+'
			   其他每个字节都被表示成"%XY"的格式,X和Y分别代表一个十六进制位,编码为UTF-8
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Base64UrlEncode(unsigned char* pucInputData,int iInputDataLen,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Encode
	FuncFunc : Base64编码
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   unsigned char 	— ucCoderFlag		输入编码编制:
			   											0x00-基本型编码(默认)
			   											0x01-URL和文件名安全型编码
			   											0x02-MIME型编码		
			   int *			— piOuputDataLen	输出的长度最大BUFFER空间
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int *		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64编码(支持UTF-8中文)
	History  : 注意:编码的原始数据如果多次切割处理,输入的每次切割数据长度必须每次为3的倍数长度
	Other    : 和Tool_Base64Decode配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Encode(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,
										unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Decode
	FuncFunc : Base64解码
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   unsigned char 	— ucCoderFlag		输入编码编制:
			   											0x00-基本型编码(默认)
			   											0x01-URL和文件名安全型编码
			   											0x02-MIME型编码		
			   int *			— piOuputDataLen	输出的长度最大BUFFER空间
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int *		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64解码(支持UTF-8中文)
	History  : None
	Other    : 和Tool_Base64Encode配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Decode(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,
										unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UrlEncode
	FuncFunc : 使用URL编码方案
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   unsigned char 	— ucUrlCode		输入URL编码的方式:0-encodeURI 非0-encodeURIComponent
			   int	*			— piOuputDataLen	输出的长度最大BUFFER空间
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 除字母和数字以及/.外作为特殊字符处理,格式:字符%+HEX 如等号=(%3D)
	           字符’a’-‘z’,’A’-‘Z’,’0’-‘9’,'.','-','_','*','!','~','(',')','''都不被编码,维持原值;
	           特殊含义9个符号.-_*!~()'不进行编码
			   这里空格' '不会被转换为加号'+'
			   其他每个字节都被表示成"%XY"的格式,X和Y分别代表一个十六进制位,编码为UTF-8
	History  : encodeURI()着眼于对整个URL进行编码,特殊含义10个符号:/?&@;,=+#不进行编码
			   encodeURIComponent()对URL的组成部分进行个别编码,所以:/?&@;,=+#在这里是可以进行编码
	Other    : 和Tool_UrlDecode配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_UrlEncode(unsigned char* pucInputData,int iInputDataLen,unsigned char ucUrlCode,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UrlDecode
	FuncFunc : 使用URL解码方案
	Input	 : unsigned char *	— pucInputData		输入的数据
			   int			 	— iInputDataLen	输入的数据长度
			   int	*			— piOuputDataLen	输出的长度最大BUFFER空间
	Output	 : unsigned char *	— pucOutputData	输出的数据
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 输入参数有误,返回TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 除字母和数字以及/.外作为特殊字符处理,格式:字符%+HEX 如等号=(%3D)
	History  : None
	Other    : 和Tool_UrlEncode配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_UrlDecode(unsigned char* pucInputData,int iInputDataLen,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToUnicode
	FuncFunc : 中文编码转换为UNICODE
	Input	 : unsigned char *	— pucInputData		输入的中文编码
	           unsigned char 	— ucConvFlag		输入转换后的格式标志:
	                                                 	0-简写格式(不带\u打头)  
	                                                	1-完整格式(带\u打头)
	Output	 : unsigned char *	— pucOutputData	输出的UNICODE编码
			   int	*		 	— piOuputDataLen	输出的数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入"中国",ucConvFlag=0,输出0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44,*piOuputDataLen = 8
    		   如输入"华伟",ucConvFlag=0,输出0x35 0x33 0x34 0x45 0x34 0x46 0x31 0x46,*piOuputDataLen = 8
    		   如输入"王文兵",ucConvFlag=0,输出0x37 0x33 0x38 0x42 0x36 0x35 0x38 0x37 0x35 0x31 0x37 0x35,*piOuputDataLen = 12
    		   如输入"中国123",ucConvFlag=0,输出0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44 0x00 0x31 0x00 0x32 0x00 0x33,*piOuputDataLen = 20
    		   如输入"中国123",ucConvFlag=1,输出0x5C 0x75 0x34 0x45 0x32 0x44 0x5C 0x75 0x35 0x36 0x46 0x44 0x5C 0x75 0x00 0x31 
    		   0x5C 0x75 0x00 0x32 0x5C 0x75 0x00 0x33,*piOuputDataLen = 30
    		   0x5C 0x75 0x34 0x45 0x32 0x44 0x5C 0x75 0x35 0x36 0x46 0x44 0x5C 0x75 0x00 0x31 0x5C 0x75 0x00 0x32 0x5C 0x75 0x00 0x33
    		   (即字符串\u4E2D\u56FD\u0031\u0032\u0033)
	History  : 当ucConvFlag=0时,输出格式XXXX形式;
			   当ucConvFlag不为0时,输出格式\uXXXX形式;
	Other    : 和Tool_UnicodeToChinese配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToUnicode(unsigned char *pucInputData,unsigned char ucConvFlag,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UnicodeToChinese
	FuncFunc : 将UNICODE转换为中文编码
	Input	 : unsigned char *	— pucInputData,输入的UNICODE编码
	           unsigned char 	— ucConvFlag  ,输入数据格式标志:
	                                                 	0-简写格式(不带\u打头)  
	                                                	1-完整格式(带\u打头)
	Output	 : unsigned char *	— pucOutputData,输出的中文GB2312编码
			   int	*		 	— piOuputDataLen,输出中文GB2312编码的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44,输出"中国"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   如输入0x35 0x33 0x34 0x45 0x34 0x46 0x31 0x46,输出"华伟"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   如输入0x37 0x33 0x38 0x42 0x36 0x35 0x38 0x37 0x35 0x31 0x37 0x35,输出"王文兵"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : Unicode只是一个符号集,它只规定了符号的二进制代码,却没有规定这个二进制代码应该如何存储;
	           如果有一种编码能将世界上所有的符号都纳入其中,
	           也就是说每一个符号都有一个独一无二的编码那么乱码问题就会消失,这就是Unicode(统一码);
	           互联网的普及强烈要求出现一种统一的编码方式,
	           UTF-8就是在互联网上使用最广的一种Unicode的实现方式,
	           其他实现方式还包括UTF-16(字符用两个字节或四个字节表示)和
	           UTF-32(字符用四个字节表示)当然这些在互联网几乎不用我们不用关心;
	           重复一遍,这里的关系是UTF-8是Unicode的实现方式之一;
      		   UTF-8最大的一个特点:它是一种变长的编码方式,它可以使用1~4个字节表示一个符号,
      		   根据不同的符号而变化字节长度,UTF-8的编码规则很简单,只有如下二条:
			   1)对于单字节的符号,字节的第1位设为0,后面7位为这个符号的 Unicode码,
			     因此对于英语字母UTF-8编码和ASCII码是相同的;
			   2)对于n字节的符号(n>1),第1个字节的前n位都设为1,第n + 1位设为0,
			     后面字节的前两位一律设为10,剩下的没有提及的二进制位,全部为这个符号的Unicode码;
			   当ucConvFlag=0时,输入格式XXXX形式;
			   当ucConvFlag不为0时,输入格式\uXXXX形式;
	Other    : 和Tool_ChineseToUnicode配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_UnicodeToChinese(unsigned char *pucInputData,unsigned char ucConvFlag,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToGB2312
	FuncFunc : 中文编码转换为GB2312十六进数
	Input	 : unsigned char *	— pucInputData,输入的中文编码
	Output	 : unsigned char *	— pucOutputData,输出的十六进数字符串
			   int	*		 	— piOuputDataLen,输出十六进数字符串的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入"中国",输出0xD6 0xD0 0xB9 0xFA,*piOuputDataLen = 4
    		   如输入"华伟",输出0xBB 0xAA 0xCE 0xB0,*piOuputDataLen = 4
    		   如输入"王文兵",输出0xCD 0xF5 0xCE 0xC4 0xB1 0xF8,*piOuputDataLen = 6
	History  : 为使计算机支持更多语言,通常使用0x80~0xFF范围的2个字节来表示1个字符,
			   比如:汉字'中'在中文操作系统中,使用[0xD6,0xD0]这两个字节存储;
　　		   不同的国家和地区制定了不同的标准,由此产生了GB2312,BIG5,JIS等各自的编码标准;
               这些使用2个字节来代表一个字符的各种汉字延伸编码方式,称为ANSI编码;
               在简体中文系统下ANSI编码代表GB2312编码,在日文操作系统下ANSI编码代表JIS编码;
	           1980年中国发布了第一个汉字编码标准,也即GB2312,全称<<信息交换用汉字编码字符集.基本集>>,
			   通常简称GB("国标"汉语拼音首字母),共收录了6763个常用的汉字和字符,
			   此标准于次年5月实施,它满足了日常99%汉字的使用需求;
	           GBK是国家标准GB2312基础上扩容后兼容GB2312的标准;
	           GBK的文字编码是用双字节来表示的,即不论中、英文字符均使用双字节来表示,
	           为了区分中文,将其最高位都设定成1;
	           GBK包含全部中文字符,是国家编码,通用性比UTF8差,不过UTF8占用的数据库比GBD大;
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToGB2312(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToGB2312Str
	FuncFunc : 中文编码转换为GB2312十六进数字符串
	Input	 : unsigned char *	— pucInputData,输入的中文编码
	Output	 : unsigned char *	— pucOutputData,输出的十六进数字符串
			   int	*		 	— piOuputDataLen,输出十六进数字符串的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入"中国",输出0x44 0x36 0x44 0x30 0x42 0x39 0x46 0x41(D6D0B9FA),*piOuputDataLen = 8
    		   如输入"华伟",输出0x42 0x42 0x41 0x41 0x43 0x45 0x42 0x30(BBAACEB0),*piOuputDataLen = 8
    		   如输入"王文兵",输出0x43 0x44 0x46 0x35 0x43 0x45 0x43 0x34 0x42 0x31 0x46 0x38(CDF5CEC4B1F8),*piOuputDataLen = 12
	History  : 为使计算机支持更多语言,通常使用0x80~0xFF范围的2个字节来表示1个字符,
			   比如:汉字'中'在中文操作系统中,使用[0xD6,0xD0]这两个字节存储;
　　		   不同的国家和地区制定了不同的标准,由此产生了GB2312,BIG5,JIS等各自的编码标准;
               这些使用2个字节来代表一个字符的各种汉字延伸编码方式,称为ANSI编码;
               在简体中文系统下ANSI编码代表GB2312编码,在日文操作系统下ANSI编码代表JIS编码;
	           1980年中国发布了第一个汉字编码标准,也即GB2312,全称<<信息交换用汉字编码字符集.基本集>>,
			   通常简称GB("国标"汉语拼音首字母),共收录了6763个常用的汉字和字符,
			   此标准于次年5月实施,它满足了日常99%汉字的使用需求;
	           GBK是国家标准GB2312基础上扩容后兼容GB2312的标准;
	           GBK的文字编码是用双字节来表示的,即不论中、英文字符均使用双字节来表示,
	           为了区分中文,将其最高位都设定成1;
	           GBK包含全部中文字符,是国家编码,通用性比UTF8差,不过UTF8占用的数据库比GBD大;
	Other    : 和Tool_GB2312StrToChinese配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToGB2312Str(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GB2312StrToChinese
	FuncFunc : 将GB2312转换为中文编码
	Input	 : unsigned char *	— pucInputData,输入的UNICODE编码
	Output	 : unsigned char *	— pucOutputData,输出的中文GB2312编码
			   int	*		 	— piOuputDataLen,输出中文GB2312编码的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如 输入0x44 0x36 0x44 0x30 0x42 0x39 0x46 0x41,输出"中国"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   如 输入0x42 0x42 0x41 0x41 0x43 0x45 0x42 0x30,输出"华伟"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   如 输入0x43 0x44 0x46 0x35 0x43 0x45 0x43 0x34 0x42 0x31 0x46 0x38,输出"王文兵"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : 为使计算机支持更多语言,通常使用0x80~0xFF范围的2个字节来表示1个字符,
			   比如:汉字'中'在中文操作系统中,使用[0xD6,0xD0]这两个字节存储;
　　		   不同的国家和地区制定了不同的标准,由此产生了GB2312,BIG5,JIS等各自的编码标准;
               这些使用2个字节来代表一个字符的各种汉字延伸编码方式,称为ANSI编码;
               在简体中文系统下ANSI编码代表GB2312编码,在日文操作系统下ANSI编码代表JIS编码;
	           1980年中国发布了第一个汉字编码标准,也即GB2312,全称<<信息交换用汉字编码字符集.基本集>>,
			   通常简称GB("国标"汉语拼音首字母),共收录了6763个常用的汉字和字符,
			   此标准于次年5月实施,它满足了日常99%汉字的使用需求;
	           GBK是国家标准GB2312基础上扩容后兼容GB2312的标准;
	           GBK的文字编码是用双字节来表示的,即不论中、英文字符均使用双字节来表示,
	           为了区分中文,将其最高位都设定成1;
	           GBK包含全部中文字符,是国家编码,通用性比UTF8差,不过UTF8占用的数据库比GBD大;
	Other    : 和Tool_ChineseToGB2312Str配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_GB2312StrToChinese(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Utf8ToGB2312
	FuncFunc : 将UTF8转换为GB2312
	Input	 : unsigned char *	— pucInputData,输入的UTF8编码
	Output	 : unsigned char *	— pucOutputData,输出的GB2312编码
			   int	*		 	— piOuputDataLen,输出GB2312编码的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入0xE4 0xB8 0xAD 0xE5 0x9B 0xBD,输出"中国"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   如输入0xE5 0x8D 0x8E 0xE4 0xBC 0x9F,输出"华伟"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   如输入0xE7 0x8E 0x8B 0xE6 0x96 0x87 0xE5 0x85 0xB5,输出"王文兵"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : Unicode只是一个符号集,它只规定了符号的二进制代码,却没有规定这个二进制代码应该如何存储;
	           如果有一种编码能将世界上所有的符号都纳入其中,
	           也就是说每一个符号都有一个独一无二的编码那么乱码问题就会消失,这就是 Unicode(统一码);
	           互联网的普及强烈要求出现一种统一的编码方式,
	           UTF-8就是在互联网上使用最广的一种Unicode的实现方式,
	           其他实现方式还包括UTF-16(字符用两个字节或四个字节表示)和
	           UTF-32(字符用四个字节表示)当然这些在互联网几乎不用我们不用关心;
	           重复一遍,这里的关系是UTF-8是Unicode的实现方式之一;
      		   UTF-8最大的一个特点:它是一种变长的编码方式,它可以使用1~4个字节表示一个符号,
      		   根据不同的符号而变化字节长度,UTF-8的编码规则很简单,只有如下二条:
			   1)对于单字节的符号,字节的第1位设为0,后面7位为这个符号的 Unicode码,
			     因此对于英语字母UTF-8编码和ASCII码是相同的;
			   2)对于n字节的符号(n>1),第1个字节的前n位都设为1,第n + 1位设为0,
			     后面字节的前两位一律设为10,剩下的没有提及的二进制位,全部为这个符号的Unicode码;
	Other    : 和Tool_GB2312ToUtf8配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_Utf8ToGB2312(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GB2312ToUtf8
	FuncFunc : 将GB2312转换为UTF8
	Input	 : unsigned char *	— pucInputData,输入的GB2312编码
	Output	 : unsigned char *	— pucOutputData,输出的UTF8编码
			   int	*		 	— piOuputDataLen,输出UTF8编码的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如输入"中国"(0xD6 0xD0 0xB9 0xFA),输出0xE4 0xB8 0xAD 0xE5 0x9B 0xBD,*piOuputDataLen = 6
    		   如输入"华伟"(0xBB 0xAA 0xCE 0xB0),输出0xE5 0x8D 0x8E 0xE4 0xBC 0x9F,*piOuputDataLen = 6
    		   如输入"王文兵"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),输出0xE7 0x8E 0x8B 0xE6 0x96 0x87 0xE5 0x85 0xB5,*piOuputDataLen = 9
	History  : Unicode只是一个符号集,它只规定了符号的二进制代码,却没有规定这个二进制代码应该如何存储;
	           如果有一种编码能将世界上所有的符号都纳入其中,
	           也就是说每一个符号都有一个独一无二的编码那么乱码问题就会消失,这就是 Unicode(统一码);
	           互联网的普及强烈要求出现一种统一的编码方式,
	           UTF-8就是在互联网上使用最广的一种Unicode的实现方式,
	           其他实现方式还包括UTF-16(字符用两个字节或四个字节表示)和
	           UTF-32(字符用四个字节表示)当然这些在互联网几乎不用我们不用关心;
	           重复一遍,这里的关系是UTF-8是Unicode的实现方式之一;
      		   UTF-8最大的一个特点:它是一种变长的编码方式,它可以使用1~4个字节表示一个符号,
      		   根据不同的符号而变化字节长度,UTF-8的编码规则很简单,只有如下二条:
			   1)对于单字节的符号,字节的第1位设为0,后面7位为这个符号的 Unicode码,
			     因此对于英语字母UTF-8编码和ASCII码是相同的;
			   2)对于n字节的符号(n>1),第1个字节的前n位都设为1,第n + 1位设为0,
			     后面字节的前两位一律设为10,剩下的没有提及的二进制位,全部为这个符号的Unicode码;
	Other    : 和Tool_Utf8ToGB2312配合使用
*************************************************************************************************/
EXPORT unsigned char Tool_GB2312ToUtf8(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetCrc8
    FuncFunc : 计算CRC8
	Input	 : unsigned char *	— pucInputData		输入需要计算的数据
			   unsigned int		— uiInputDataLen	输入数据长度
			   unsigned char 	— ucCrc8Type		输入哈希类型:
			   												0x01-CRC8
			   												0x02-自定义客户化CRC8
	Output	 : unsigned char *	— pucOutputData	输出计算结果:
															0x01-CRC8输出1个字节
															0x02-CRC8输出1个字节
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc8(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char ucCrc8Type,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCrc16
    FuncFunc : 计算CRC16
	Input	 : unsigned char *	— pucInputData		输入需要计算的数据
			   unsigned int		— uiInputDataLen	输入数据长度
			   unsigned char 	— ucCrc16Type		输入CRC类型(参考枚举类型CRC_MODE):
			   												CRC16_IBM:CRC_MODE_CRC16_IBM
			   												CRC16_MAXIM:CRC_MODE_CRC16_MAXIM
			   												CRC16_USB:CRC_MODE_CRC16_USB
			   												CRC16_MODBUS:CRC_MODE_CRC16_MODBUS
			   												CRC16_CCITT:CRC_MODE_CRC16_CCITT
			   												CRC16_CCITT_FALSE:CRC_MODE_CRC16_CCITT_FALSE
			   												CRC16_X25:CRC_MODE_CRC16_X25
			   												CRC16_XMODEM:CRC_MODE_CRC16_XMODEM
			   												CRC16_DNP:CRC_MODE_CRC16_DNP 												
	Output	 : unsigned short *	— pusOutputData	输出计算结果
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc16(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char ucCrc16Type,unsigned short *pusOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCrc
    FuncFunc : 计算CRC循环冗余校验码
	Input	 : CRC_TYPE			— crcType,输入CRC类型结构信息
	           const uint8_t *	— buffer,输入需要计算的数据
			   uint32_t			— length,输入需要计算的数据长度
	Output	 : uint32_t*		— puiOutputData,输出CRC循环冗余校验码
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 支持CRC1-CRC32
	History  : 通用CRC算法
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc(CRC_TYPE crcType, unsigned char* pucInputData,unsigned int uiInputDataLen, uint32_t *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_GetGeneralCrc
    FuncFunc : 计算通用CRC算法循环冗余校验码
	Input	 : unsigned char 	— ucCrc16Type		输入CRC类型(参考枚举类型CRC_MODE):
			   												CRC4_ITU:CRC_MODE_CRC4_ITU
			   												CRC5_EPC:CRC_MODE_CRC5_EPC
			   												CRC5_ITU:CRC_MODE_CRC5_ITU
			   												CRC5_USB:CRC_MODE_CRC5_USB
			   												CRC6_ITU:CRC_MODE_CRC6_ITU
			   												CRC7_MMC:CRC_MODE_CRC7_MMC
			   												CRC8:CRC_MODE_CRC8
			   												CRC8_ITU:CRC_MODE_CRC8_ITU
			   												CRC8_ROHC:CRC_MODE_CRC8_ROHC
			   												CRC8_MAXIM:CRC_MODE_CRC8_MAXIM
			   												CRC16_IBM:CRC_MODE_CRC16_IBM
			   												CRC16_MAXIM:CRC_MODE_CRC16_MAXIM
			   												CRC16_USB:CRC_MODE_CRC16_USB
			   												CRC16_MODBUS:CRC_MODE_CRC16_MODBUS
			   												CRC16_CCITT:CRC_MODE_CRC16_CCITT
			   												CRC16_CCITT_FALSE:CRC_MODE_CRC16_CCITT_FALSE
			   												CRC16_X25:CRC_MODE_CRC16_X25
			   												CRC16_XMODEM:CRC_MODE_CRC16_XMODEM
			   												CRC16_DNP:CRC_MODE_CRC16_DNP
			   												CRC32:CRC_MODE_CRC32
			   												CRC32_MPEG2:CRC_MODE_CRC32_MPEG2			   												
	           unsigned char *	— pucInputData		输入需要计算的数据
			   unsigned int		— uiInputDataLen	输入数据长度			   
	Output	 : uint32_t*		— puiOutputData,输出CRC循环冗余校验码
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 支持CRC4/CRC5/CRC6/CRC7/CRC8/CRC16/CRC32
	History  : 常用的CRC算法
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetGeneralCrc(unsigned char ucCrc16Type,unsigned char* pucInputData,unsigned int uiInputDataLen,uint32_t *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_GetDescpFromCrcMode
	FuncFunc : 通过CRC模型类型获取相关信息描述
	Input	 : unsigned char	— ucCrcMode 	 输入的CRC模型类型
	Output	 : unsigned char *	— pucOutputData 输出的相关CRC模型类型对应描述信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 输入参数有误,返回TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 获取CRC模型类型相关信息描述
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromCrcMode(unsigned char ucCrcMode,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Hash
    FuncFunc : 计算哈希值
	Input	 : unsigned char *	— pucInputData		输入需要计算的数据
			   int				— iInputDataLen	输入数据长度
			   unsigned char 	— ucHashType		输入哈希类型:
			   												0x01-MD5 
			   												0x02-SHA1 
			   												0x03-SHA224 
			   												0x04-SHA256
			   												0x05-SHA384 
			   												0x06-SHA512
	Output	 : unsigned char *	— pucOutputData	输出计算结果:
															0x01-MD5输出16个字节 
															0x02-SHA1输出20个字节 
															0x03-SHA224输出28个字节 
															0x04-SHA256输出32个字节
															0x05-SHA384输出48个字节 
															0x06-SHA512输出64个字节
	           unsigned int *	— puiOutputDataLen	输出计算结果长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Hash(unsigned char* pucInputData,int iInputDataLen,unsigned char ucHashType,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FileHash
    FuncFunc : 计算文件哈希值
	Input	 : unsigned char *	— pucFileName				输入进行计算的文件名(绝对路径)
	           unsigned char 	— ucHashType				输入哈希类型:
	                                                        0x01-MD5 
	                                                        0x02-SHA1 
	                                                        0x03-SHA224 
	                                                        0x04-SHA256
	                                                        0x05-SHA384
	                                                        0x06-SHA512
	           unsigned char 	— ucTrimFileTailHashFlag	输入文件末尾哈希值是否剔除:
	                                      					0x00-不剔除
	                                      					0x01-不剔除并计算追加到文件尾
	                                                        0x02-剔除计算 
	                                                        0x03-剔除计算并比较 
	                                                        其他-剔除计算
	Output	 : unsigned char *	— pucOutputData			输出计算结果:
	                                                        0x01-MD5输出16个字节 
	                                                        0x02-SHA1输出20个字节 
	                                                        0x03-SHA224输出28个字节 
	                                                        0x04-SHA256输出32个字节
	                                                        0x05-SHA384输出48个字节 
	                                                        0x06-SHA512输出64个字节
	           unsigned int *	— puiOutputDataLen			输出计算结果长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 输入文件名
	History  : 如果文件末尾带有哈希值,计算时可以通过设置ucTrimFileTailHashFlag计算
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FileHash(unsigned char *pucFileName,unsigned char ucHashType,unsigned char ucTrimFileTailHashFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FilePointHash
    FuncFunc : 计算文件哈希值
	Input	 : FILE *			— fpHash					输入计算的哈希文件指针
	           unsigned char 	— ucHashType				输入哈希类型:
	                                                        0x01-MD5 
	                                                        0x02-SHA1 
	                                                        0x03-SHA224 
	                                                        0x04-SHA256
	                                                        0x05-SHA384
	                                                        0x06-SHA512
	           unsigned char 	— ucTrimFileTailHashFlag	输入文件末尾哈希值是否剔除:
	           												0x00-不剔除
	           												0x01-不剔除并计算追加到文件尾
	                                                        0x02-剔除计算 
	                                                        0x03-剔除计算并比较 
	                                                        其他-剔除计算
	Output	 : unsigned char *	— pucOutputData			输出计算结果:
	                                                        0x01-MD5输出16个字节 
	                                                        0x02-SHA1输出20个字节 
	                                                        0x03-SHA224输出28个字节 
	                                                        0x04-SHA256输出32个字节
	                                                        0x05-SHA384输出48个字节 
	                                                        0x06-SHA512输出64个字节
	           unsigned int *	— puiOutputDataLen			输出计算结果长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回相应错误信息(非0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 输入文件指针
	History  : 如果文件末尾带有哈希值,计算时可以通过设置ucTrimFileTailHashFlag计算
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FilePointHash(FILE *fpHash,unsigned char ucHashType,unsigned char ucTrimFileTailHashFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CodeConvert
	FuncFunc : ANSI与UTF-8相互转换
	Input	 : unsigned int		— uiInputCode		输入的代码
			   void * 			— pInputData		输入的数据
			   unsigned int		— uiOuputCode		输出的代码
	Output	 : void * 			— pOutputData		输出的数据
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : 如ANSI转UTF-8,uiInputCode=CP_ACP,uiOuputCode=CP_UTF8;UTF-8转ANSI,uiInputCode=CP_UTF8,uiOuputCode=CP_ACP
	History  : None
	Other    : UTF-8与GB2312
*************************************************************************************************/
EXPORT unsigned char Tool_CodeConvert(unsigned int uiInputCode,void* pInputData,unsigned int uiOuputCode,void* pOutputData);

/***********************************************************************************************
	FuncName : Tool_CheckConfigSectionName
	FuncFunc : 检查配置文件节名是否存在
	Input	 : unsigned char *	— pucInputFileName		输入文件名
			   unsigned char *	— pucInputSectionName	输入的节名
	Output	 : None
	Return	 : unsigned char	— 存在,返回TOOL_SUCCESS(0x00)
					 			— 不存在,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckConfigSectionName(unsigned char *pucInputFileName,unsigned char *pucInputSectionName);

/***********************************************************************************************
	FuncName : Tool_GetKey
	FuncFunc : 获取配置文件键值
	Input	 : unsigned char *	— pucInputFileName		输入文件名
			   unsigned char *	— pucInputKeyName		输入键名
	Output	 : unsigned char *	— pucOutputKeyValue	输出的键值
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : 不区分大小写
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetKey(unsigned char *pucInputFileName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetKeyValue
	FuncFunc : 获取配置文件键值
	Input	 : unsigned char *	— pucInputFileName		输入文件指针名
			   unsigned char *	— pucInputKeyName		输入键名
	Output	 : unsigned char *	— pucOutputKeyValue	输出的键值
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : 区分大小写
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetKeyValue(unsigned char *pucInputFileName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetConfigStringValue
	FuncFunc : 获取配置文件中字符串的值
	Input	 : unsigned char *	— pucInputFileName		输入文件名
			   unsigned char *	— pucInputSectionName	输入的节名
			   unsigned char *	— pucInputKeyName		输入键名
	Output	 : unsigned char *	— pucOutputKeyValue	输出的键值
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetConfigStringValue(unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned char *pOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetConfigIntValue
	FuncFunc : 获取配置文件中整型的值
	Input	 : unsigned char *	— pucInputFileName		输入文件名
			   unsigned char *	— pucInputSectionName	输入的节名
			   unsigned char *	— pucInputKeyName		输入键名
	Output	 : unsigned long *	— pulOutputKeyValue	输出的键值
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回相应错误信息(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetConfigIntValue(unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned long *pulOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_SetCfgFile
	FuncFunc : 设置默认配置参数文件名
	Input	 : unsigned char *	— pucInputCfgFileName,输入配置参数文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-07 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetCfgFile(unsigned char *pucInputCfgFileName);

/***********************************************************************************************
	FuncName : Tool_GetCfgFile
	FuncFunc : 获取默认配置参数文件名
	Input	 : None
	Output	 : unsigned char *	— pucOutputCfgFileName,输出默认配置参数文件名
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-07 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCfgFile(unsigned char *pucOutputCfgFileName);

/***********************************************************************************************
	FuncName : Tool_GetCurrPathFile
	FuncFunc : 获取当前目录全路径
	Input	 : unsigned int		— uiMaxLen,当前目录的绝对路径地址长度大小
	Output	 : unsigned char *	— pucOuputFilePathName,输出文件的全路径
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径(全路径,不包含应用名称),如快捷方式运行的绝对路径(不包含应用名称)
	History  : uiMaxLen太小无法保存绝对路径地址,返回NULL 
	Other    : 如应用实际路径为:G:\App\Test\Release\Test.exe,
	             应用快捷方式实际路径为:C:\Users\Administrator\Desktop\Test.exe,
	             执行返回:C:\Users\Administrator\Desktop
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrPathFile(unsigned int uiMaxLen,unsigned char *pucOuputFilePathName);

/***********************************************************************************************
	FuncName : Tool_GetCurrAppPathFile
	FuncFunc : 获取当前应用执行的目录全路径(包含应用名称)
	Input	 : unsigned int		— uiMaxLen,当前目录的绝对路径地址长度大小
	Output	 : unsigned char *	— pucOuputAppPathName,输出文件的全路径
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径包含应用名称(全路径)
	History  : uiMaxLen太小无法保存绝对路径地址
	Other    : 如应用实际路径为:G:\App\Test\Release\Test.exe,
	             应用快捷方式实际路径为:C:\Users\Administrator\Desktop\Test.exe,
	             执行返回:G:\App\Test\Release\Test.exe
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrAppPathFile(unsigned int uiMaxLen,unsigned char *pucOuputAppPathName);

/***********************************************************************************************
	FuncName : Tool_GetCurrAppPath
	FuncFunc : 获取当前应用执行的目录全路径(不包含应用名称)
	Input	 : unsigned int		— uiMaxLen,当前目录的绝对路径地址长度大小
	Output	 : unsigned char *	— pucOuputAppPath,输出文件的全路径
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径不包含应用名称(全路径)
	History  : uiMaxLen太小无法保存绝对路径地址
	Other    : 如应用实际路径为:G:\App\Test\Release\Test.exe,
	             应用快捷方式实际路径为:C:\Users\Administrator\Desktop\Test.exe,
	             执行返回:G:\App\Test\Release\
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrAppPath(unsigned int uiMaxLen,unsigned char *pucOuputAppPath);

/***********************************************************************************************
	FuncName : Tool_GetPathName
	FuncFunc : 获取一个全路径文件名的目录路径
	Input	 : unsigned char *	— pucInputFullPathName		输入读取的全路径文件名
	Output	 : unsigned char *	— pucOuputFilePathName		输出文件的路径
	Return	 : unsigned char	— 存在返回成功,返回TOOL_SUCCESS(0x00)
								— 不存在返回失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPathName(unsigned char *pucInputFullPathName,unsigned char *pucOuputFilePathName);

/***********************************************************************************************
	FuncName : Tool_GetFileName
	FuncFunc : 获取一个全路径文件的文件名
	Input	 : unsigned char *	— pucInputFullPathName		输入读取的全路径文件名
	Output	 : unsigned char *	— pucOutputFileName		输出文件名
	Return	 : unsigned char	— 存在返回成功,返回TOOL_SUCCESS(0x00)
								— 绝对路径有误返回失败,返回TOOL_FAILURE(0x01)
								— 不存在文件名,返回(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileName(unsigned char *pucInputFullPathName,unsigned char *pucOutputFileName);

/***********************************************************************************************
	FuncName : Tool_GetFileNamePrefix
	FuncFunc : 获取文件名的前缀
	Input	 : unsigned char *	— pucInputFileName			输入文件名
	           unsigned char 	— ucSuffixFlag				输入是否指定文件名的后缀:
	                                                        0-不查找后缀以第一个.之前为前缀
	                                                        1-不查找后缀以第一个.之前为前缀
	                                                        2-不查找后缀以最后一个.之前为前缀
	                                                        3-查找后缀,不匹配时以第一个.之前为前缀
	                                                        4-查找后缀,不匹配时以最后一个.之前为前缀
	                                                        5-查找后缀且必须匹配
	           unsigned char *	— pucInputSuffix			输入指定的文件名后缀
	Output	 : unsigned char *	— pucOutputPrefix			输出文件名的前缀
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 其他错误,返回TOOL_FAILURE(0x01)
								— 输入参数有误,返回TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径或相对路径,此函数不检查文件是否已经存在
	History  : 如:
	           例1:test.txt 返回test
	           例2:d:\Demo\test.txt 返回test
	           例3:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=5 pucInputSuffix=".txt" 返回X.20131201.DATA
	           例4:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=1 返回X
	           例5:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=2 返回X.20131201.DATA
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNamePrefix(unsigned char *pucInputFileName,unsigned char ucSuffixFlag,unsigned char *pucInputSuffix,unsigned char *pucOutputPrefix);

/***********************************************************************************************
	FuncName : Tool_GetFileNameSuffix
	FuncFunc : 获取文件名的后缀
	Input	 : unsigned char *	— pucInputFileName			输入文件名
	Output	 : unsigned char *	— pucOutputSuffix			输出文件名的后缀
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 其他错误,返回TOOL_FAILURE(0x01)
								— 输入参数有误,返回TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 绝对路径或相对路径,此函数不检查文件是否已经存在
	History  : 如:
	           例1:test.txt 返回.txt
	           例2:d:\Demo\test.txt 返回.txt
	           例3:d:\Demo\X.20131201.DATA.txt 返回.txt
	           例4:d:\Demo\X.20131201.DATA 返回.DATA
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNameSuffix(unsigned char *pucInputFileName,unsigned char *pucOutputSuffix);

/***********************************************************************************************
	FuncName : Tool_CheckPathFile
	FuncFunc : 检查目录
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
	Output	 : None
	Return	 : unsigned char	— 存在返回成功,返回TOOL_SUCCESS(0x00)
								— 不存在返回失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 检查目录是否存在,如果不存在不会创建目录
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckPathFile(unsigned char *pucInputFilePathName);

/***********************************************************************************************
	FuncName : Tool_CreatePathFile
	FuncFunc : 检查并创建目录
	Input	 : unsigned char *	— pucInputFilePathName		输入创建的文件路径
	           unsigned char 	— ucParentDirFlag			输入是否支持创建父目录 0-不支持 1-支持
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_CREATEDIRFAIL(0x07)创建目录失败
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 检查目录是否存在,如果不存在就创建目录
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CreatePathFile(unsigned char *pucInputFilePathName,unsigned char ucParentDirFlag);

/***********************************************************************************************
	FuncName : Tool_CreateFile
	FuncFunc : 创建文件
	Input	 : unsigned char *	— pucInputFilePathName	输入创建的文件路径
		       unsigned char *	— pucInputFileName		输入创建的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 检查文件是否存在,如果不存在就创建文件
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CreateFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_IsExistFile
	FuncFunc : 检查文件是否存在
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char    — ucNullFlag  			检查的文件内容是否可以为空 0-不可以为空 1或非0-可以为空  
	Output	 : None
	Return	 : unsigned char	— 文件存在,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件目录不存在,返回TOOL_DIRNOTEXIST(0x09)
					 			— 文件不存在,返回TOOL_FILENOTEXIST(0x08)
					 			— 文件存在但内容为空,返回TOOL_FILENULL(0x1A)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsExistFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_IsExistFileEx
	FuncFunc : 检查文件是否存在
	Input	 : unsigned char *	— pucInputFullFileName	输入保存的全路径文件名
		       unsigned char    — ucNullFlag  			检查的文件内容是否可以为空 0-不可以为空 1或非0-可以为空  
	Output	 : None
	Return	 : unsigned char	— 文件存在,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件目录不存在,返回TOOL_DIRNOTEXIST(0x09)
					 			— 文件不存在,返回TOOL_FILENOTEXIST(0x08)
					 			— 文件存在但内容为空,返回TOOL_FILENULL(0x1A)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsExistFileEx(unsigned char *pucInputFullFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_ReadHeadLine
	FuncFunc : 获取文件首行信息
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
			   unsigned char 	— uiMinLen					输入读取的最小长度
			   unsigned char 	— uiMaxLen					输入读取的最大长度
	Output	 : unsigned char *	— pucOutputData			输出文件首行信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回非TOOL_SUCCESS
										参数错误TOOL_PARAMERROR(0x04)
										获取失败TOOL_FAILURE(0x01)
										打开文件失败TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 主要读取第一行信息
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadHeadLine(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadLine
	FuncFunc : 获取文件某行信息
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
			   unsigned char 	— uiMinLen					输入读取的最小长度
			   unsigned char 	— uiMaxLen					输入读取的最大长度
			   unsigned long 	— ulLine					输入读取的某行信息
			   unsigned char 	— ucSizeFlag				输入是否记录已经读取的文件大小:0-否 1-是
	Output	 : unsigned long *	— pulOutputSize			输出文件已经读取的文件大小(字节)
	           unsigned char * 	— pucEofFlag				输出文件结束标志
			   unsigned char *	— pucOutputData			输出文件某行信息
			   unsigned long *	— pulOutputDataLen			输出文件某行信息的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回非TOOL_SUCCESS
										参数错误TOOL_PARAMERROR(0x04)
										获取失败TOOL_FAILURE(0x01)
										打开文件失败TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 读取某一行信息(默认开始行为1)
	History  : 记录已经读取的文件大小(字节)
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadLine(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned long ulLine,unsigned char ucSizeFlag,unsigned long *pulOutputSize,unsigned char *pucEofFlag,unsigned char *pucOutputData,unsigned long *pulOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_ReadFile
	FuncFunc : 获取文件信息
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
			   unsigned long 	— ulSize					输入读取的大小
	Output	 : unsigned char *	— pucOutputData			输出读取的文件中的信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回非TOOL_SUCCESS
										参数错误TOOL_PARAMERROR(0x04)
										获取失败TOOL_FAILURE(0x01)
										打开文件失败TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 文件总大小必须为ulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadFileEx
	FuncFunc : 获取文件信息
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
			   unsigned long 	— ulOutputDataLen			输入读取的大小
	Output	 : unsigned char *	— pucOutputData			输出读取的文件中的信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回非TOOL_SUCCESS
										参数错误TOOL_PARAMERROR(0x04)
										获取失败TOOL_FAILURE(0x01)
										打开文件失败TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : 文件总大小可以大于ulOutputDataLen
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFileEx(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,
								unsigned long ulOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadFileAllInfor
	FuncFunc : 获取文件所有信息
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
	Output	 : unsigned char *	— pucOutputData			输出读取的文件中的信息
	           unsigned long *	— pulOutputLen				输出读取的长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回非TOOL_SUCCESS(0x01或其它非0)
										打开文件失败TOOL_OPENFILEFAIL(0x05)
										文件长度为空TOOL_FILENULL(0x15)
										申请内存失败TOOL_GETMEMORYFAIL(0x14)
										读取文件失败TOOL_READFILEFAIL(0x0C)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFileAllInfor(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucOutputData,unsigned long *pulOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetFileSize
	FuncFunc : 获取文件字节数
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
	Output	 : unsigned long *	— pulOutputLen				输入文件的大小
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
    Date     : 2013-02-21 19:00:55
    Descp    : 字节
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileSize(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long *pulOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetFileNum
	FuncFunc : 获取文件记录数
	Input	 : unsigned char *	— pucInputFilePathName		输入读取的文件路径
			   unsigned char *	— pucInputFileName			输入读取的文件名称
			   unsigned char 	— ucFirstLineFlag			输入第一行是否支持:0-不支持 1-支持
			   unsigned char *	— pucFristData				输入第一行不支持满足的条件
	Output	 : unsigned long *	— pulOutputNum				输入文件的记录数
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
    Date     : 2013-02-21 19:00:55
    Descp    : 每行长度一样
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNum(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFirstLineFlag,unsigned char *pucFristData,unsigned long *pulOutputNum);

/***********************************************************************************************
	FuncName : Tool_RunApp
	FuncFunc : 执行应用
	Input	 : unsigned char *	— pucInputFilePath	输入应用的文件路径
			   unsigned char *	— pucInputApp		输入执行的应用
	           unsigned char *	— pucInputParam	输入执行的参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RunApp(unsigned char *pucInputFilePath,unsigned char *pucInputApp,unsigned char *pucInputParam);

/***********************************************************************************************
	FuncName : Tool_RunSelf
	FuncFunc : 运行指定信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
    Date     : 2014-04-21 19:20:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RunSelf( void );

/***********************************************************************************************
	FuncName : Tool_SetAttribFile
	FuncFunc : 修改指定文件或文件夹(包括子文件和子文件夹)属性
	Input	 : unsigned char *	— pucSourFile	输入源文件名(绝对路径)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 清除只读,存档,系统,隐藏属性
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetAttribFile(unsigned char *pucSourFile);

/***********************************************************************************************
	FuncName : Tool_GetDirToListFile
	FuncFunc : 获取某个目录下所有的文件夹名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	           unsigned char *	— pucInputListFilePath		输入列表文件的输出路径
	           unsigned char *	— pucInputListFileName		输入列表文件的输出文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 只获取目录名(即文件夹名)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDirToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetFileToListFile
	FuncFunc : 获取某个目录下所有的文件名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	           unsigned char *	— pucInputListFilePath		输入列表文件的输出路径
	           unsigned char *	— pucInputListFileName		输入列表文件的输出文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 只获取文件名(不包含目录,即文件夹名)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetInfoToListFile
	FuncFunc : 获取某个目录下所有的文件和文件夹名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	           unsigned char *	— pucInputListFilePath		输入列表文件的输出路径
	           unsigned char *	— pucInputListFileName		输入列表文件的输出文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 包括目录名(即文件夹名)和文件名
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInfoToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetDirListToBuf
	FuncFunc : 获取某个目录下所有的文件夹名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	Output	 : unsigned char *	— pucOutputData			输出文件目录名列表信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE(0x01)
								— 文件不存在,返回TOOL_FILENOTEXIST(0x08)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 只获取目录名(即文件夹名)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDirListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetFileListToBuf
	FuncFunc : 获取某个目录下所有的文件名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	Output	 : unsigned char *	— pucOutputData			输出文件列表信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 只获取文件名(不包含目录,即文件夹名)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetInfoListToBuf
	FuncFunc : 获取某个目录下所有的文件和文件夹名称
	Input	 : unsigned char *	— pucInputFilePathName		输入需要列出的文件目录路径
	Output	 : unsigned char *	— pucOutputData			输出文件列表信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE(0x01)
								— 文件不存在,返回TOOL_FILENOTEXIST(0x08)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : 包括目录名(即文件夹名)和文件名
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInfoListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CopyFile
	FuncFunc : 把指定目录下的文件拷贝到另一个目录下
	Input	 : unsigned char *	— pucInputSourceFilePath		输入源文件的目录路径
	           unsigned char *	— pucInputSourceFileName		输入源文件的的文件名
	           unsigned char *	— pucInputCopyFilePath			输入拷贝后的目录路径
	           unsigned char *	— pucInputCopyFileName			输入拷贝后的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE或非TOOL_SUCCESS(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 只拷贝目录下的文件
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CopyFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputCopyFilePath,unsigned char *pucInputCopyFileName);

/***********************************************************************************************
	FuncName : Tool_CopyFiles
	FuncFunc : 把指定目录下的所有目录和文件拷贝到另一个目录下
	Input	 : unsigned char *	— pucInputSourceFilePath		输入源文件的目录路径
	           unsigned char *	— pucInputCopyFilePath			输入拷贝到的目标目录路径
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE或非TOOL_SUCCESS(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 只拷贝目录下的子目录和文件
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CopyFiles(unsigned char *pucInputSourceFilePath,unsigned char *pucInputCopyFilePath);

/***********************************************************************************************
	FuncName : Tool_RenameFile
	FuncFunc : 重命文件名
	Input	 : unsigned char *	— pucInputSourceFilePath		输入源文件的目录路径
	           unsigned char *	— pucInputSourceFileName		输入源文件的的文件名
	           unsigned char *	— pucInputRenameFilePath		输入重命名的目录路径
	           unsigned char *	— pucInputRenameFileName		输入重命名的的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE或非TOOL_SUCCESS(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RenameFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputRenameFilePath,unsigned char *pucInputRenameFileName);

/***********************************************************************************************
	FuncName : Tool_MoveFile
	FuncFunc : 移动一个文件
	Input	 : unsigned char *	— pucInputSourceFilePath	输入源文件路径
			   unsigned char *	— pucInputSourceFileName	输入源文件名
			   unsigned char *	— pucInputMoveFilePath		输入移动的文件路径
			   unsigned char *	— pucInputMoveFileName		输入移动的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 可以重命名文件
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_MoveFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputMoveFilePath,unsigned char *pucInputMoveFileName);

/***********************************************************************************************
	FuncName : Tool_MoveDir
	FuncFunc : 移动一个目录
	Input	 : unsigned char *	— pucInputSourceFilePath	输入源文件路径
			   unsigned char *	— pucInputMoveFilePath		输入移动的文件路径
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 可以重命名目录
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_MoveDir(unsigned char *pucInputSourceFilePath,unsigned char *pucInputMoveFilePath);

/***********************************************************************************************
	FuncName : Tool_ClearFile
	FuncFunc : 清空指定文件
	Input	 : unsigned char *	— pucInputFilePathName	输入清空的文件目录路径
	           unsigned char *	— pucInputFileName		输入清空的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回0x00
					 			— 失败,返回非0x00
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 只清空文件内容
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ClearFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_DelFile
	FuncFunc : 直接删除指定文件
	Input	 : unsigned char *	— pucInputDelFullFileName	输入删除的源文件名(绝对路径)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DelFile(unsigned char *pucInputDelFullFileName);

/***********************************************************************************************
	FuncName : Tool_DelFileEx
	FuncFunc : 直接删除指定文件
	Input	 : unsigned char *	— pucInputDelFilePath	输入删除的文件目录路径
	           unsigned char *	— pucInputDelFileName	输入删除的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DelFileEx(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : Tool_RemoveFile
	FuncFunc : 过滤后再删除指定文件
	Input	 : unsigned char *	— pucInputDelFilePath	输入删除的文件目录路径
	           unsigned char *	— pucInputDelFileName	输入删除的文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveFile(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : Tool_RemoveDir
	FuncFunc : 删除指定的目录
	Input	 : unsigned char *	— pucInputDelFilePath	输入的删除目录(绝对路径)
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveDir(unsigned char *pucInputDelFilePath);

/***********************************************************************************************
	FuncName : Tool_AppendInfoToFile
	FuncFunc : 将信息以字符串或十六进制格式保存到文件
	Input	 : unsigned char	— ucInputFileModeFlag	输入的保存文件模式:0-追加	其它-覆盖
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
					 			— 失败,返回TOOL_FAILURE(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : 以Windows格式,换行符(0x0D 0x0A)
	History  : None
	Other    : 如:ucCRFlag=0x06-写文件信息之前先换行和写文件信息完都换行,一行最大长度4096
*************************************************************************************************/
EXPORT unsigned char Tool_AppendInfoToFile(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : Tool_AppendInfoToFileEx
	FuncFunc : 将信息以字符串或十六进制格式保存到文件
	Input	 : unsigned char	— ucInputFileModeFlag	输入的保存文件模式:0-追加	其它-覆盖
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
					 			— 失败,返回TOOL_FAILURE(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : 以Linux/Unix格式,换行符(0x0A)
	History  : None
	Other    : 如:ucCRFlag=0x06-写文件信息之前先换行和写文件信息完都换行,一行最大长度4096
*************************************************************************************************/
EXPORT unsigned char Tool_AppendInfoToFileEx(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : Tool_AppendFileRecord
	FuncFunc : 追加文件记录并对记录完整性进行检查
	Input	 : unsigned char	— ucInputFileModeFlag	输入的保存文件模式			0-追加	其它-覆盖
		       unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char *	— pucInputData			输入保存的数据信息
		       unsigned long    — ulInputDataLen		输入保存的数据信息大小
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 以输入的ulInputDataLen为一个记录块大小
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AppendFileRecord(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetNumberFileRecord
	FuncFunc : 获取文件记录数
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       unsigned long *	— pulRecordNumber		输出文件记录数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 文件记录不完整,返回TOOL_RECORDNOTFULL(0x19)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 文件每个记录大小为ulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetNumberFileRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName : Tool_GetRecord
	FuncFunc : 搜索指定的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       DBInfor *    	— pDBInfor  			输入搜索的文件记录信息    
	Output	 : unsigned char *	— pucOutputData		输出获取的某条索引记录信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 文件每个记录大小为ulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_UpdateRecord
	FuncFunc : 更新指定的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       DBInfor *    	— pDBInfor  			输入搜索的文件记录信息
		       unsigned char *	— pucInputData			输入更新的某条索引记录信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 只更新指定文件记录信息,不存在指定文件信息也不追加
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_DeleteRecord
	FuncFunc : 删除指定的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       DBInfor *    	— pDBInfor  			输入搜索的文件记录信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 只删除指定文件记录信息,不存在指定文件信息也不追加
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor);

/***********************************************************************************************
	FuncName : Tool_GetRecordByIndex
	FuncFunc : 获取指定索引的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       unsigned long   	— ulIndex  			输入获取的文件记录索引号
	Output	 : unsigned char *	— pucOutputData		输出获取的某条索引记录信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_UpdateRecordByIndex
	FuncFunc : 更新指定索引的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned char *	— pucInputData			输入更新的某条索引记录信息
		       unsigned long    — ulSize  				输入每个记录的大小
		       unsigned long   	— ulIndex  			输入更新的文件记录索引号
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : Tool_DeleteRecordByIndex
	FuncFunc : 删除指定索引的文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned long    — ulSize  				输入每个记录的大小
		       unsigned long   	— ulIndex  			输入删除的文件记录索引号
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : Tool_ReadTlvRecord
	FuncFunc : 读取非定长记录TLV的信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned int   	— uiTag  				输入标签Tag 
	Output	 : unsigned char *	— pucOutputData		输出标签Tag的值
	           unsigned int *	— puiOutputLen			输出标签Tag的值长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 文件存在,但是为空,返回TOOL_FILENULL(0x15)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag,unsigned char *pucOutputData,unsigned int *puiOutputLen);

/***********************************************************************************************
	FuncName : Tool_WriteTlvRecord
	FuncFunc : 写入非定长记录TLV的信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned int   	— uiTag  				输入标签Tag
		       unsigned char *	— pucOutputData		输入标签Tag的值
		       unsigned int 	— uiInputDataLen		输入标签Tag的值长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 文件存在,但是为空,返回TOOL_FILENULL(0x15)
								— 写文件失败,返回TOOL_WRITEFILEFAIL(0x0D)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WriteTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DeleteTlvRecord
	FuncFunc : 删除非定长记录TLV的信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的文件路径
		       unsigned char *	— pucInputFileName		输入保存的文件名
		       unsigned int   	— uiTag  				输入删除的标签Tag
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 文件存在,但是为空,返回TOOL_FILENULL(0x15)
								— 写文件失败,返回TOOL_WRITEFILEFAIL(0x0D)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag);

/***********************************************************************************************
	FuncName : Tool_CreateDBFile
	FuncFunc : 创建数据库文件
	Input	 : unsigned char *	— pucInputFilePathName	输入创建的数据库文件路径
		       unsigned char *	— pucInputFileName		输入创建的数据库文件名
		       unsigned long    — ulSize  				输入保存的数据字典文件结构信息大小
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : 检查文件是否存在,如果不存在就创建文件
*************************************************************************************************/
EXPORT unsigned char Tool_CreateDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize);

/***********************************************************************************************
	FuncName : Tool_ClearDBFile
	FuncFunc : 清空数据库文件
	Input	 : unsigned char *	— pucInputFilePathName	输入创建的数据库文件路径
		       unsigned char *	— pucInputFileName		输入创建的数据库文件名
		       unsigned long    — ulSize  				输入保存的数据字典文件结构信息大小
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : 不删除该数据库文件,仅清空记录信息
*************************************************************************************************/
EXPORT unsigned char Tool_ClearDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize);

/***********************************************************************************************
	FuncName : Tool_RemoveDBFile
	FuncFunc : 删除数据库文件
	Input	 : unsigned char *	— pucInputFilePathName	输入删除的数据库文件路径
		       unsigned char *	— pucInputFileName		输入删除的数据库文件名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回非0x00(0x01或其它非0)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_ReadDBRecord
	FuncFunc : 读取指定索引的数据库文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       unsigned long	— ulRecIndex			输入读取的记录索引
	Output	 : DBKEY *    		— pOutputDbKey  		输出获取的文件记录信息
			   unsigned char *	— pucOutputData		输出获取的某条索引记录信息
			   unsigned int *	— puiOutputDataLen		输出获取的某条索引记录信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : 索引从0开始,如获取第一条记录输入索引0
*************************************************************************************************/
EXPORT unsigned char Tool_ReadDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulRecIndex,DBKEY *pOutputDbKey,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FindDBRecord
	FuncFunc : 搜索指定的数据库文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       DBKEY *    		— pDbKey  				输入搜索的文件记录信息
	Output	 : unsigned char *	— pucOutputData		输出获取的某条索引记录信息
			   unsigned int *	— puiOutputDataLen		输出获取的某条索引记录信息长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 读文件失败,返回TOOL_READFILEFAIL(0x0C)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FindDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_AppendDBRecord
	FuncFunc : 追加指定的数据库文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       DBKEY *    		— pDbKey  				输入追加的文件记录信息
	 		   unsigned char *	— pucInputData			输入追加的某条索引记录信息
			   unsigned int 	— uiInputDataLen		输入追加的某条索引记录信息长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 读文件失败,返回TOOL_READFILEFAIL(0x0C)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : 如果已经存在不追加
*************************************************************************************************/
EXPORT unsigned char Tool_AppendDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_UpdateDBRecord
	FuncFunc : 更新指定的数据库文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       DBKEY *    		— pDbKey  				输入更新的文件记录信息
	 		   unsigned char *	— pucInputData			输入更新的某条索引记录信息
			   unsigned int 	— uiInputDataLen		输入更新的某条索引记录信息长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 读文件失败,返回TOOL_READFILEFAIL(0x0C)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : 如果不存在则追加
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DeleteDBRecord
	FuncFunc : 删除指定的数据库文件记录信息
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       DBKEY *    		— pDbKey  				输入删除的文件记录信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 读文件失败,返回TOOL_READFILEFAIL(0x0C)
					 			— 申请内存失败失败,返回TOOL_GETMEMORYFAIL(0x14)
					 			— 指定文件记录信息不存在,返回TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey);

/***********************************************************************************************
	FuncName : Tool_GetNumberDBRecord
	FuncFunc : 获取数据库文件记录数
	Input	 : unsigned char *	— pucInputFilePathName	输入保存的数据库文件路径
		       unsigned char *	— pucInputFileName		输入保存的数据库文件名
		       unsigned long    — ulSize  				输入保存的数据字典文件结构信息大小
		       unsigned long *	— pulRecordNumber		输出文件记录数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
					 			— 文件不存在打开文件失败,返回TOOL_OPENFILEFAIL(0x05)
					 			— 文件记录不完整,返回TOOL_RECORDNOTFULL(0x19)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : 数据库字典文件操作
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetNumberDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName 	:  Tool_GetMac
	FuncFunc 	:  获取报文数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen 	输入数据长度
    			   unsigned char *	—pucInputInitVector输入的初始向量数据
    			   unsigned char 	—ucKeyType 		输入密钥类型 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(DES为8字节或者2DES为16个字节或者3DES为24个字节)
	Output	 	:  unsigned char * 	—pucOutputData 	输出标准MAC(8个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  标准算法
	History  	:  3DES为24个字节为X9.52
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetX919Mac
	FuncFunc 	:  获取报文数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen 	输入数据长度
    			   unsigned char *	—pucInputInitVector输入的初始向量数据
    			   unsigned char 	—ucKeyType 		输入密钥类型 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(DES为8字节或者2DES为16个字节或者3DES为24个字节)
	Output	 	:  unsigned char * 	—pucOutputData 	输出X9.19 MAC(8个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  X9.19算法
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetX919Mac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetX99Mac
	FuncFunc 	:  获取报文数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen 	输入的数据长度
    			   unsigned char *	—pucInputInitVector输入的初始向量数据
    			   unsigned char 	—ucKeyType 		输入密钥类型 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(DES为8字节或者2DES为16个字节或者3DES为24个字节)
    			   unsigned char    —ucMacType 		X9.9算法类型标志 0-CBC算法 1-ECB算法
	Output	 	:  unsigned char * 	—pucOutputData  	输出X9.9 MAC(8个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  X9.9 区分CBC算法和ECB算法,推荐使用CBC算法
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetX99Mac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetCupMac
	FuncFunc 	:  获取报文数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen	输入数据长度
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(8个字节)
	Output	 	:  unsigned char * 	—pucOutputData		输出MAC(8个字节)
	Return	 	:  unsigned	char 	—成功,返回TOOL_SUCCESS(0x00)
								 	—失败,返回TOOL_FAILURE(0x01)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  银联CUP算法
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCupMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetIccMac
	FuncFunc 	:  获取报文数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen 	输入的数据长度
    			   unsigned char *	—pucInputInitVector输入的初始向量数据
    			   unsigned char 	—ucKeyType 		输入密钥类型 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(DES为8字节或者2DES为16个字节或者3DES为24个字节)
    			   unsigned char    —ucMacType 		Icc算法类型标志 0-CBC算法 1-ECB算法
	Output	 	:  unsigned char * 	—pucOutputData  	输出Icc卡MAC(8个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  Icc卡区分CBC算法和ECB算法,推荐使用CBC算法
	History  	:  3DES为24个字节为ICC X9.52
	Other    	:  不足末尾追加0x80
*************************************************************************************************/
EXPORT unsigned char Tool_GetIccMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetStrToHexIccMac
	FuncFunc 	:  获取报文字符串数据域1-8的鉴别码
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen 	输入的数据长度
    			   unsigned char *	—pucInputInitVector输入的初始向量数据
    			   unsigned char 	—ucKeyType 		输入密钥类型 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(DES为8字节或者2DES为16个字节或者3DES为24个字节)
    			   unsigned char    —ucMacType 		Icc算法类型标志 0-CBC算法 1-ECB算法
	Output	 	:  unsigned char * 	—pucOutputData  	输出Icc卡MAC(16个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  Icc卡区分CBC算法和ECB算法,推荐使用CBC算法
	History  	:  输入和输出都是字符串格式
	Other    	:  末尾追加0x80
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrToHexIccMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,
									unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);
									
/***********************************************************************************************
	FuncName 	:  Tool_GetCardMac
	FuncFunc 	:  获取卡片MAC
    Input	 	:  unsigned char *	—pucInputData 		输入的数据
    			   unsigned int	 	—uiInputDataLen	输入数据长度
    			   unsigned char * 	—pucInitVector  	输入初始向量(8个字节)
    			   unsigned char 	—ucKeyType 		输入密钥类型 0x01-2DES 0x02-3DES
    			   unsigned char * 	—pucInputMakKey	输入加密密钥(2DES为16个字节或者3DES为24个字节)
	Output	 	:  unsigned char * 	—pucOutputData  	输出MAC(8个字节)
	Return	 	:  unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								 	— 失败,返回TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  None
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCardMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetSubSetResult
    FuncFunc : 从长度为iSubSetNum的数组里选出m个数使和为固定值mFixData.lData,且子结合所有子集合的和最接近mFixData.aucData
	Input	 : SUBSET_PRM *			— pSubSetData		输入所有子集集合数据信息
	           int 					— iSubSetNum		输入所有子集集合数据数量
	           SUBSET_PRM 			— mFixData			输入固定值mFixData信息          
	Output	 : SUBSETRESULT_PRM	*	— pSubSetResult	输出符合所有条件的子集集合
	Return	 : unsigned char		— 成功,返回TOOL_SUCCESS
									— 失败,返回TOOL_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 选出m个数时,每个子集只获取满足条件的一条数据
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_GetSubSetResult(SUBSET_PRM *pSubSetData,int iSubSetNum,SUBSET_PRM mFixData,SUBSETRESULT_PRM *pSubSetResult);

/***********************************************************************************************
	FuncName : Tool_Exit
	FuncFunc : 退出应用
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Exit( void );

/***********************************************************************************************
	FuncName : Tool_Cls
	FuncFunc : 清屏
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Cls( void );

/***********************************************************************************************
	FuncName : Tool_Beep
	FuncFunc : 响铃警告声
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Beep( void );

/***********************************************************************************************
	FuncName : Tool_ErrorBeep
	FuncFunc : 响铃警告声
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ErrorBeep( void );

/***********************************************************************************************
	FuncName : Tool_BeepEx
	FuncFunc : 发声
	Input	 : unsigned	int 	— uiFreq,输入发声频率
			   unsigned	long 	— ulMillSec,输入发声时间间隔(MS)
	Output	 : None
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 毫秒
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BeepEx(unsigned int uiFreq,unsigned long ulMillSec);

/*************************************************************************************************
	FuncName : Tool_DispProgressBar
	FuncFunc : 显示当前下载进度
	Input	 : unsigned long 	— ulCurrProg	当前进度
			   unsigned long 	— ulTotalProg	总的进度
			   unsigned char	— ucRunFlag 	运行标志:0-执行标志
               											 1-结束标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispProgressBar(unsigned long ulCurrProg,unsigned long ulTotalProg,unsigned char ucRunFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayCenter
	FuncFunc : 居中显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
               BOOL			 	— bInvertFlag	是否反显 TRUE-是 FALSE-否
               unsigned char 	— ucMaxCol		一行最大显示的个数
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayCenter(unsigned char *pucInputData,unsigned char ucStartLine,unsigned char bInvertFlag,unsigned char ucMaxCol);

/***********************************************************************************************
	FuncName : Tool_DisplayCenterEx
	FuncFunc : 居中显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               BOOL			 	— bInvertFlag	是否反显 TRUE-是 FALSE-否
               unsigned char 	— ucMaxCol		一行最大显示的个数
               unsigned char 	— ucCRFlag		是否自动换行 0-否 1-是
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 不自动换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayCenterEx(unsigned char *pucInputData,unsigned char bInvertFlag,unsigned char ucMaxCol,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayLeft
	FuncFunc : 靠左显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x01)
								— 失败,返回TOOL_FAILURE(0x00)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 自动换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayLeft(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayLeftEx
	FuncFunc : 靠左显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucCRFlag	是否自动换行 0-否 1-是
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 不自动换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayLeftEx(unsigned char *pucInputData,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayRight
	FuncFunc : 靠右显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayRight(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayRightEx
	FuncFunc : 靠右显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucCRFlag	ucCRFlag	是否自动换行 0-否 1-是
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 不自动换行
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayRightEx(unsigned char *pucInputData,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayMultiLine
	FuncFunc : 靠左显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
               unsigned char 	— ucStartLine	起始行
	Output	 : None
	Return	 : unsigned char	— 返回下一次显示的行
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 支持多行显示
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayMultiLine(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayText
	FuncFunc : 显示信息
	Input	 : unsigned char *	— pucInputData	输入的提示信息
			   unsigned	char	— ucDispMode	显示方式:0-左对齐 1-右对齐 2-居中
               unsigned	char	— ucInvertFlag	是否反显 TRUE-是 FALSE-否
               unsigned	char	— ucInvertColor反显颜色:低四位控制前景色:高亮|红|绿|蓝,高四位来控制背景色:高亮|红|绿|蓝
               unsigned char 	— ucMaxCol		一行最大显示的个数
               unsigned char 	— ucCRFlag		是否自动换行 0-否 1-是
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : 支持彩色
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayText(unsigned char *pucInputData,unsigned char ucDispMode,unsigned char ucInvertFlag,unsigned char ucInvertColor,unsigned char ucMaxCol,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_Zip
	FuncFunc : 压缩文件
	Input	 : unsigned char *	— pucInputZipFilePath			输入压缩文件保存的文件目录
	           unsigned char *	— pucInputZipFileName			输入压缩文件保存的文件名
	           unsigned char *	— pucInputZipResourePathName	输入压缩的资源文件目录
	           unsigned char *	— pucInputExcludePathFlag		输入是否包含当前资源文件目录及子目录:0-否 1-是
	           unsigned char *	— pucInputExcludeFilePath		输入排除的目录:NULL表示不需要排除目录
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Zip(unsigned char *pucInputZipFilePath,unsigned char *pucInputZipFileName,unsigned char *pucInputZipResourePathName,unsigned char pucInputExcludePathFlag,unsigned char *pucInputExcludeFilePath);

/***********************************************************************************************
	FuncName : Tool_UnZip
	FuncFunc : 压缩文件
	Input	 : unsigned char *	— pucInputZipFilePath		输入解压文件目录
	           unsigned char *	— pucInputZipFileName		输入解压文件名
	           unsigned char *	— pucInputUnZipFilePath	输入解压后的文件目录
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UnZip(unsigned char *pucInputZipFilePath,unsigned char *pucInputZipFileName,unsigned char *pucInputUnZipFilePath);

/***********************************************************************************************
	FuncName : Tool_Bak
    FuncFunc : 备份应用工程
	Input	 : unsigned char *	— pucAppName,输入应用名
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
								— 失败,返回TOOL_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Bak(unsigned char *pucAppName);

/***********************************************************************************************
	FuncName : Tool_GetPrivateData
	FuncFunc : 获取数据
	Input	 : unsigned char *	— pucInputData		输入数据
			   unsigned int 	— uiInputDataLen	输入数据长度
			   unsigned char 	— ucPrivateType	输入私有数据类型
	Output	 : unsigned char *	— pucOutputData	输出数据
			   unsigned int *	— puiOutputDataLen	输出数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPrivateData(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucPrivateType,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckCardNo
	FuncFunc : 检查卡号是否有效
	Input	 : unsigned char *	— pucInputData		输入数据
			   unsigned int 	— uiInputDataLen	输入数据长度
	Output	 : None
	Return	 : unsigned char	— 有效,返回TOOL_SUCCESS(0x00)
					 			— 无效,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : Luhn算法
	History  : 卡号的最后一位都是通过Luhn算法进行计算或校验
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckCardNo(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckId
	FuncFunc : 检查身份证是否有效
	Input	 : unsigned char *	— pucInputData		输入数据
			   unsigned int 	— uiInputDataLen	输入数据长度
	Output	 : None
	Return	 : unsigned char	— 有效,返回TOOL_SUCCESS(0x00)
					 			— 无效,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckId(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetIdInfo
	FuncFunc : 获取身份证区域信息
	Input	 : unsigned char *	— pucInputData		输入2位或6位身份证区域码
			   unsigned int 	— uiInputDataLen	输入数据长度
			   unsigned char 	— ucFlag			获取信息标志:
			   											0-获取区域信息 
			                                       		1-获取直辖市或省会 
			                                        	2-获取直辖市或省会简称 
			                                        	3-获取直辖市或省会及简称			   											   
	Output	 : unsigned char *	— pucOutputData	输出数据
			   unsigned int *	— puiOutputDataLen	输出数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetIdInfo(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMonthInfoByIntValue
	FuncFunc : 根据整型月份获取月份对应的字符串信息
	Input	 : int				— iMonth,输入月份
			   unsigned char 	— ucFlag,获取信息标志:			                                        
			                                       	0-获取英文全称信息 
			                                    	1-获取英文简称信息
			                                    	2-获取英文全称(简称)信息
			                                       	3-获取中文信息
			                                       	4-获取中文(英文全称)信息
			                                       	5-获取中文(英文简称)信息
	Output	 : unsigned char *	— pucOutputData	输出数据
			   unsigned int *	— puiOutputDataLen	输出数据长度
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 输入iMonth=1,ucFlag=0,*pucOutputData="January"
			   输入iMonth=10,ucFlag=0,*pucOutputData="October"
	           输入iMonth=11,ucFlag=0,*pucOutputData="November"
	           输入iMonth=12,ucFlag=0,*pucOutputData="December"
	           输入iMonth=1,ucFlag=1,*pucOutputData="Jan"
	           输入iMonth=1,ucFlag=2,*pucOutputData="January(Jan)"
	           输入iMonth=1,ucFlag=3,*pucOutputData="一月"
	           输入iMonth=1,ucFlag=4,*pucOutputData="一月(January)"
	           输入iMonth=1,ucFlag=5,*pucOutputData="一月(Jan)"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthInfoByIntValue(int iMonth,unsigned char ucFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMonthByStrValue
	FuncFunc : 根据月份字符串获取月份对应的信息
	Input	 : unsigned char *	— pucInputData,输入月份信息
			   unsigned int 	— uiInputDataLen,输入月份信息的长度
	Output	 : int *			— piOutputData,输出对应的月份
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 如:
	           输入"January",*piOutputData=1
	           输入"February",*piOutputData=2
	           输入"March",*piOutputData=3
	           输入"April",*piOutputData=4
	           输入"May",*piOutputData=5
	           输入"June",*piOutputData=6
	           输入"July",*piOutputData=7
	           输入"August",*piOutputData=8
	           输入"September",*piOutputData=9
	           输入"October",*piOutputData=10
	           输入"November",*piOutputData=11
	           输入"December",*piOutputData=12
	           输入"Jan",*piOutputData=1
	           输入"Feb",*piOutputData=2
	           输入"Mar",*piOutputData=3
	           输入"Apr",*piOutputData=4
	           输入"May",*piOutputData=5
	           输入"Jun",*piOutputData=6
	           输入"Jul",*piOutputData=7
	           输入"Aug",*piOutputData=8
	           输入"Sep",*piOutputData=9
	           输入"Oct",*piOutputData=10
	           输入"Nov",*piOutputData=11
	           输入"Dec",*piOutputData=12
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthByStrValue(unsigned char *pucInputData,unsigned int uiInputDataLen,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_VerifyManage
	FuncFunc : 权限管理
	Input	 : unsigned char *	— pucInputData		认证数据
			   unsigned char *	— uiInputDataLen	认证数据长度
			   unsigned char 	— ucVerifyLevel	认证等级:0x00-高级 	 0x01-一级   0x02-二级 
			   												 0x03-三级 	 0x04-四级   0x05-五级
			   												 0x06-认证级 0x07-权限级 0x08-开放
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_VerifyManage(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucVerifyLevel);

/***********************************************************************************************
	FuncName : Tool_ConLicense
	FuncFunc : 认证控制
	Input	 : unsigned char *	— pucInputData				认证数据
			   unsigned int 	— uiInputDataLen			认证数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConLicense(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckLicense
	FuncFunc : 证书认证
	Input	 : unsigned char *	— pucInputKis				软件唯一特征码
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLicense(unsigned char *pucInputKis);

/***********************************************************************************************
	FuncName : Tool_AuthLicense
	FuncFunc : 认证本地证书并生成新的本地证书
	Input	 : unsigned char *	— pucInputKis,输入软件唯一特征码
	           unsigned char *	— pucInputData,输入认证数据
	           unsigned int		— uiInputDataLen,输入认证数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AuthLicense(unsigned char *pucInputKis,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DispAppRegCode
	FuncFunc : 显示软件注册相关错误信息
	Input	 : unsigned char	— ucRetCode 输入的返回码为检查应用软件注册函数或者注册软件函数返回码
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 仅限用于软件注册失败时候获取错误信息
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispAppRegCode(unsigned char ucRetCode);

/***********************************************************************************************
	FuncName : Tool_CheckAppValid
	FuncFunc : 检查软件的有效性,注册信息是否失效
	Input	 : unsigned char *	— pucInputAppPath			输入的注册应用文件目录路径(二级路径)
			   unsigned char *	— pucInputAppName			输入的当前注册应用软件的名称
			   unsigned char *	— pucInputProtName			输入的当前注册保护文件的名称
			   
			   unsigned char *	— pucInputKis				软件唯一特征码(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputAppFileMacKey	注册应用文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputProtFileMacKey	注册保护文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputAppFileProKey	注册应用文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
			   unsigned char *  — pucInputProtFileProKey	注册保护文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
	Output	 : unsigned char *  — pucOutputData			输出用户信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS
					 			— 失败,返回其它,具体错误信息可以使用Tool_DispAppRegCode函数查看
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : 此函数可以控制软件是否需要注册成功才可以运行,应用软件自行控制
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAppValid(unsigned char *pucInputAppPath,unsigned char *pucInputAppName,unsigned char *pucInputProtName,unsigned char *pucInputKis,unsigned char *pucInputAppFileMacKey,unsigned char *pucInputProtFileMacKey,
											unsigned char *pucInputAppFileProKey,unsigned char *pucInputProtFileProKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AppRegister
	FuncFunc : 注册软件
	Input	 : unsigned char *	— pucInputAppPath			输入的注册应用文件目录路径(二级路径)
			   unsigned char *	— pucInputAppName			输入的当前注册应用软件的名称
			   unsigned char *	— pucInputProtName			输入的当前注册保护文件的名称
			   
			   unsigned char *	— pucInputKis				软件唯一特征码(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定32位
			   unsigned char *  — pucInputTranProKey		传输密钥的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputLimiProKey		有效信息的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputKisProKey		软件特征码的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定32位
			   unsigned char *  — pucInputLicProKey		注册码的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定48位
			   
			   unsigned char *  — pucInputAppFileMacKey	注册应用文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputProtFileMacKey	注册保护文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputAppFileProKey	注册应用文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
			   unsigned char *  — pucInputProtFileProKey	注册保护文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
	Output	 : unsigned char *  — pucOutputData			输出用户信息
	Return	 : unsigned char	— 成功,返回0x00
					 			— 失败,返回其它,具体错误信息可以使用Tool_DispAppRegCode函数查看
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AppRegister(unsigned char *pucInputAppPath,unsigned char *pucInputAppName,unsigned char *pucInputProtName,unsigned char *pucInputKis,unsigned char *pucInputTranProKey,unsigned char *pucInputLimiProKey,
									unsigned char *pucInputKisProKey,unsigned char *pucInputLicProKey,unsigned char *pucInputAppFileMacKey,
									unsigned char *pucInputProtFileMacKey,unsigned char *pucInputAppFileProKey,unsigned char *pucInputProtFileProKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AppUnregister
	FuncFunc : 注销软件
	Input	 : unsigned char *	— pucInputAppPath	输入的注册应用文件目录路径(二级路径)
			   unsigned char *	— pucInputAppName	输入的当前注册应用软件的名称
			   unsigned char *	— pucInputProtName	输入的当前注册保护文件的名称
	Output	 : unsigned char *  — pucOutputData	输出用户信息
	Return	 : unsigned char	— 成功,返回0x00
					 			— 失败,返回其它,具体错误信息可以使用Tool_DispAppRegCode函数查看
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AppUnregister(unsigned char *pucInputAppPath,unsigned char *pucInputAppName,unsigned char *pucInputProtName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetAppLicenseInfor
	FuncFunc : 获取应用注册相关信息
	Input	 : unsigned char *	— pucInputKis				软件唯一特征码(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputTranProKey		传输密钥的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputLimiProKey		有效信息的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputKisProKey		软件特征码的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定32位
			   unsigned char *  — pucInputLicProKey		注册码的保护密钥(应用软件要和注册机软件匹配),由数字,A~Z,a~z取值,固定48位
			   
			   unsigned char *  — pucInputAppFileMacKey	注册应用文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputProtFileMacKey	注册保护文件信息的MAC密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定16位
			   unsigned char *  — pucInputAppFileProKey	注册应用文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
			   unsigned char *  — pucInputProtFileProKey	注册保护文件信息的保护密钥(应用软件自行定义),由数字,A~Z,a~z取值,固定48位
	Output	 : None
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetAppLicenseInfor(unsigned char *pucInputKis,unsigned char *pucInputTranProKey,unsigned char *pucInputLimiProKey,
									unsigned char *pucInputKisProKey,unsigned char *pucInputLicProKey,unsigned char *pucInputAppFileMacKey,
									unsigned char *pucInputProtFileMacKey,unsigned char *pucInputAppFileProKey,unsigned char *pucInputProtFileProKey);

/***********************************************************************************************
	FuncName : Tool_GetDescpFromCode
	FuncFunc : 通过返回码获取相关信息描述
	Input	 : unsigned char	— ucRetCode 	 输入的返回码
	Output	 : unsigned char *	— pucOutputData 输出的相关返回码对应描述信息
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 获取工具库返回码相关信息描述
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromCode(unsigned char ucRetCode,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DispCode
	FuncFunc : 显示相关返回码信息
	Input	 : unsigned char	— ucRetCode 输入的返回码
	Output	 : None
	Return	 : unsigned char	— 成功,返回TOOL_SUCCESS(0x00)
					 			— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 获取工具库返回码信息描述并显示
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispCode(unsigned char ucRetCode);

/***********************************************************************************************
	FuncName : Tool_GetRevisionInfo
	FuncFunc : 获取库版本修订信息
	Input	 : unsigned int *	— puiOutputDataLen	输入修订信息的最大存储长度
	Output	 : unsigned char *	— pucOutputData	输出修订信息
	           unsigned int *	— puiOutputDataLen	输出修订信息的长度
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRevisionInfo(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetLibVersion
	FuncFunc : 获取库版本
	Input	 : unsigned int *	— puiOutputDataLen	输入库版本的最大存储长度
	Output	 : unsigned char *	— pucOutputData	输出当前库版本
	           unsigned int *	— puiOutputDataLen	输出库版本的最大存储长度
	Return	 : unsigned	char 	— 成功,返回TOOL_SUCCESS(0x00)
								— 失败,返回TOOL_FAILURE(0x01)
								— 无效参数,返回TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetLibVersion(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

#ifdef __cplusplus   
}  

#endif


#endif 
