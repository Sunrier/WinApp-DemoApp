/*************************************************************************************************
	FileName : Tool.h
    FileFunc : ʵ��TOOL�����ӿڵ���ͷ�ļ�
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2010-09-23 19:13:15
	Descp    : ʵ�ֹ��߼�����
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
   /*  64λͳһ����Ϊ __64BIT__ */
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
//vc6ʹ�õı�������C90��׼�ģ�long long ������C99���¼���ġ������Ҫʹ��int 64 λ����Ҫʹ��__int64��������
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

/*�û�����*/
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
	bALPHAKEY = 0x09,	/*TAB��*/
	bDEL = 0x53,
	bF1 = 0x70,
	bF2 = 0x70,
}UserKey;

/*��־����-LOG_OFF>LOG_ERR>LOG_WARN>LOG_INFO>LOG_DEBUG>LOG_ALL*/
typedef enum _LOG_LEVEL
{
	LOG_OFF  	= 0x00,	/*�ر�������־��¼-��߼���*/
	LOG_ERROR	= 0x01,	/*����Ӧ�ó��������з����Ĵ�����Ϣ*/
	LOG_WARN	= 0x02,	/*����Ӧ�ó��������з����ľ�����Ϣ*/
	LOG_INFO 	= 0x04,	/*����Ӧ�ó������й���*/
	LOG_DEBUG 	= 0x08,	/*�򿪵�����־*/
	LOG_ALL 	= 0x10, /*��������־��¼*/
	LOG_MAX,
}LOG_LEVEL;

/*�����־����-LOG_CHECK_OFF>LOG_CHECK_ERROR>LOG_CHECK_WARN>LOG_CHECK_INFO>LOG_CHECK_DEBUG>LOG_CHECK_ALL*/
typedef enum _LOG_CHECK_LEVEL
{
	LOG_CHECK_OFF  	= 0x00,	/*�ر�������־��¼-��߼���*/
	LOG_CHECK_ERROR	= 0x01,	/*����Ӧ�ó��������з����Ĵ�����Ϣ*/
	LOG_CHECK_WARN	= 0x02,	/*����Ӧ�ó��������з����ľ�����Ϣ*/
	LOG_CHECK_INFO 	= 0x03,	/*����Ӧ�ó������й���*/
	LOG_CHECK_DEBUG = 0x04,	/*�򿪵�����־*/
	LOG_CHECK_ALL 	= 0x05, /*��������־��¼*/
	LOG_CHECK_MAX,
}LOG_CHECK_LEVEL;

/*������ֵ�ֽ�˳��ģʽ*/
typedef enum _ENDIAN
{
    ENDIAN_LITTLE	= 0x01,	/*С��ģʽ(ENDIAN_LITTLE):windowsС��ģʽ*/
	ENDIAN_BIG		= 0x02, /*���ģʽ(ENDIAN_BIG)*/
}TOOL_ENDIAN;

/*��������*/
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

/*�Ƚ����ݷ�Χ����*/
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


/*CRC����*/
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

/*���ݷָ��*/
typedef struct
{
	unsigned int uiOffset;			/*������ʼλ*/
    unsigned int uiFieldLen;		/*���ݳ���*/
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
	long	lOffset;			/*���ݿ�Ҫ�������ṹ������ĳ�Ա����*/
  	unsigned char ucKeyType; 	/*DBKEYTYPE*/
  	unsigned int uiLen;			/*���ݳ���*/
  	long	lKey;			  	/*long������*/
  	unsigned char aucKey[16];	/*String������*/
}DBKEY;

/*����TLV*/
typedef struct _TLV
{
	int iTag;	/*tag*/
	int iLen;	/*iLen*/
	unsigned char *pucValue;	/*pucValue*/
}TLV;

/*TAG��������*/
typedef enum _TLV_TAGTYPE
{
  TAGTYPE_NUMERIC = 0,		/*Alpha numeric*/
  TAGTYPE_BINARY,			/*Binary*/
  TAGTYPE_BCDNUMBER,		/*BCD*/
  TAGTYPE_ALPHANUMERIC,		/*Alpha numeric or special character*/
}TLV_TAGTYPE;

/*TAG������Դ*/
typedef enum _TLV_TAGSOURCE
{
  TAGSOURCE_ICC = 0,		/*IC��*/
  TAGSOURCE_ISSUER,			/*������*/
  TAGSOURCE_TERMINAL,		/*�ն�*/
  TAGSOURCE_ISSUERTERMINAL,	/*�����л��ն�*/
}TLV_TAGSOURCE;

/*EMV TLV��Ϣ�ṹ����*/
typedef struct _TLVTAG_PRM
{
	int iTag;								/*��ǩ����ֵ*/
	unsigned char aucTag[4+1];				/*��ǩ�ַ���ֵ*/
	int iTagLen;							/*��ǩ�ĳ���*/
	int iTagValueLen;						/*��ǩֵ�ĳ���*/
	unsigned char ucTagValueLenVarFlag;		/*��ǩֵ�ĳ��ȿɱ��־:0-���ɱ�,�̶� ��0-�ɱ�*/
	int iTagValueMinLen;					/*��ǩֵ����С����*/
	TLV_TAGTYPE	   ucTagType;				/*��ǩ����:�ο�TLV_TAGTYPE*/
	TLV_TAGSOURCE  ucTagSource;				/*��ǩ��Դ:�ο�TLV_TAGSOURCE*/
	unsigned char ucTemplateFlag;			/*�Ƿ�ģ���־:0-�� ��0-��*/
	unsigned char aucTagEnName[64+1];		/*��ǩӢ����*/
	unsigned char aucTagCnName[64+1];		/*��ǩ������*/
	unsigned char aucTagShortName[12+1];	/*��ǩ�����*/
}TLVTAG_PRM;

/*Ȩ��ϵ��������Ϣ*/
typedef struct
{
	int iIndex;
	double dWeight;
	long lPercent;
}WEIGHTFACTOR_PRM;

/*�Ӽ����ϲ����ṹ��*/
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
	int iOrgIndex;				/*ԭ������*/
}SUBSET_PRM;

/*�����Ӽ�����ƥ������ṹ��*/
typedef struct
{
	int iN;			/*��ǰ����n*/
    int iM;			/*��ǰѡ����m*/
    long lSum;		/*��ǰѡ������sum*/
    int iCount;		/*��ǰ�����*/
    int **piSubSet;	/*��ǰ���:��¼����*/
}SUBSETMATCH_PRM;

/*�����Ӽ����Ͻ�������ṹ��*/
typedef struct
{
	double dMinData;				/*�Ӽ�����С������*/
	double dMaxData;				/*�Ӽ�����������*/
	unsigned char ucSubSetFlag;		/*�Ӽ��ϴ��ڱ�־:0-������ 1-����*/
	int iSetSubNum;					/*�Ӽ��ϵ�ǰ���ݸ���*/
	int *piSubSet;					/*�Ӽ�������*/
}SUBSETRESULT_PRM;

/*RSA��Կ�ṹ����*/
typedef struct
{
	unsigned int  uiBits;    			/*ģλ����bit��λ*/
	unsigned char aucModulus[256];    	/*ģ*/
	unsigned char aucExponent[256];   	/*ָ��*/
}RSAPUBLICKEY_PRM;

/*RSA˽Կ�ṹ����*/
typedef struct
{
	unsigned int  uiBits;    				/*ģλ����bit��λ*/
	unsigned char aucModulus[256];         	/*ģ-N(ģ��)*/
	unsigned char aucPublicExponent[256];   /*��Կָ��*/
	unsigned char aucExponent[256];         /*˽Կָ��-D(˽Կ)*/
	unsigned char aucPrime[2][256];         /*pq����,��������*/
	unsigned char aucPrimeExponent[2][256]; /*CRTָ��,������ָ������ֵDp,Dq*/
	unsigned char aucCoefficient[256];      /*CRTϵ��,��������������ֵQinv*/
}RSAPRIVATEKEY_PRM;

/*CRC���Ͷ���*/
typedef struct
{
	unsigned char width;	/*���ݿ��(��CRC������):CRCУ����ĳ���(������λ��)*/
	uint32_t poly;			/*����ʽ���ʽ(������ļ�д):��16���Ʊ�ʾ;�����11011(polyֵΪ0x1B)�Ķ���ʽΪG(X)=X4+X3+X+1,
	                  			����:CRC-32����0x04C11DB7,���������λ��"1",����������������0x104C11DB7,ʵ��ʹ�ü��ʽ0x04C11DB7*/
	uint32_t init;			/*��ʼֵ:�����㷨��ʼʱ�Ĵ���(crc)�ĳ�ʼ��Ԥ��ֵ,ʮ�����Ʊ�ʾ*/
	unsigned char refIn;	/*����ֵ�Ƿ�ת:�������ݵ�ÿ���ֽ��Ƿ�λ��ת(True��False)*/
	unsigned char refOut;	/*���ֵ�Ƿ�ת:�ڼ����֮��,������֮ǰ:���������Ƿ�λ��ת(True��False)*/
	uint32_t xorOut;		/*������ֵ:��������˲�������õ����յ�CRCֵ*/
}CRC_TYPE;

/***********************************************************************************************
	FuncName : Tool_SetTimer
	FuncFunc : ���ö�ʱ��������
	Input	 : unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
	Output	 : unsigned long *	�� pulEndTimer		����ʱ��(S)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetTimer(unsigned long ulInputSeconds,unsigned long *pulEndTimer);

/***********************************************************************************************
	FuncName : Tool_CheckTimer
	FuncFunc : ��鶨ʱ���������Ƿ���Ч
	Input	 : unsigned long 	�� pulEndTimer		����ʱ��(S)
	Output	 : None
	Return	 : unsigned char	�� ��Ч,����TOOL_SUCCESS(0x00)
								�� ��ʱ��ʧЧ,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTimer(unsigned long pulEndTimer);

/***********************************************************************************************
	FuncName : Tool_TimerOpen
	FuncFunc : �򿪶�ʱ��
	Input	 : unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
	Output	 : unsigned int *	�� puiTimerID		���ض�ʱ��ID
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : Ŀǰֻ֧��5�鶨ʱ��
	History  : None
	Other    : ���Tool_TimerCheck��Tool_TimerCloseʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_TimerOpen(unsigned long ulInputSeconds,unsigned int *puiTimerID);

/***********************************************************************************************
	FuncName : Tool_TimerCheck
	FuncFunc : ��鶨ʱ���Ƿ���������
	Input	 : unsigned int		�� uiTimerID		���붨ʱ��ID
	Output	 : unsigned long *	�� pulLeftTime		�ɹ�����ʣ��ʱ��(S)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : Ŀǰֻ֧��5�鶨ʱ��
	History  : None
	Other    : ���Tool_TimerOpen��Tool_TimerCloseʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_TimerCheck(unsigned int uiTimerID,unsigned long *pulLeftTime);

/***********************************************************************************************
	FuncName : Tool_TimerClose
	FuncFunc : �رն�ʱ��
	Input	 : unsigned int		�� uiTimerID		���붨ʱ��ID
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 10:02:53
	Descp    : Ŀǰֻ֧��5�鶨ʱ��
	History  : None
	Other    : ���Tool_TimerOpen��Tool_TimerCheckʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_TimerClose(unsigned int uiTimerID);

/***********************************************************************************************
	FuncName : Tool_SetTimeOut
	FuncFunc : ���ó�ʱʱ��
	Input	 : unsigned long	�� uiTimeout	�������õĳ�ʱʱ��(S)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetTimeOut(unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : Tool_GetTimeOut
	FuncFunc : ��ȡ��ʱʱ��
	Input	 : None
	Output	 : unsigned int *	�� puiTimeout	������õĳ�ʱʱ��(S)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimeOut(unsigned int *puiTimeout);

/***********************************************************************************************
	FuncName : Tool_WaitKey
	FuncFunc : ��ȡ����ֵ����ʱ����
	Input	 : unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
	Output	 : unsigned char *	�� pucOutputKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Return	 : unsigned char	�� �а����ɹ�,����TRUE
								�� �ް���ʧ��,����FALSE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WaitKey(unsigned long ulInputSeconds,unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_WaitKeyMill
	FuncFunc : ��ȡ����ֵ����ʱ����
	Input	 : unsigned long	�� ulInputMillSeconds	�������õĳ�ʱʱ��(ms)
	Output	 : unsigned char *	�� pucOutputKey			�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Return	 : unsigned char	�� �а����ɹ�,����TRUE
								�� �ް���ʧ��,����FALSE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WaitKeyMill(unsigned long ulInputMillSeconds,unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_Delay
	FuncFunc : ��ʱ����
	Input	 : unsigned long	�� ulInputMillSec	����ȴ���ʱ��(����)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : �Ժ���ͳ������Ҫ�ȴ�1��,���������ulMSec=1000
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Delay(unsigned long ulInputMillSec);

/***********************************************************************************************
	FuncName : Tool_ClrKey
	FuncFunc : �����������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ClrKey( void );

/***********************************************************************************************
	FuncName : Tool_CheckKey
	FuncFunc : ��ⰴ������
	Input	 : None
	Output	 : unsigned char *	�� pucOutputKey	���������ֵ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckKey(unsigned char *pucOutputKey);

/***********************************************************************************************
	FuncName : Tool_GetDateAndTime
	FuncFunc : ��ȡ����ʱ��
	Input	 : unsigned char 	�� ucFormatFlag		���������ʱ���ʽ��־
								   0:YYYYMMDDHHMMSS
								   1:YYYY-MM-DD HH:MM:SS
								   2:YYYYMMDDHHMMSSMS
								   3:YYYY-MM-DD HH:MM:SS.MS
								   4:S(��)
								   5:MS(������)
								   6:YYYYMMDDHHMMSS.MS
								   ����:YYYY-MM-DD HH:MM:SS
	Output	 : unsigned char *	�� pucOutputData	���������ʱ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDateAndTime(unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCurrentDate
	FuncFunc : ��ȡ��ǰ������Ϣ
	Input	 : unsigned char   	�� ucFormatFlag,���ڸ�ʽ
								   0x00-YYYYMMDD 0x01-YYYY(20YY) 0x02-YYMMDD
								   0x03-YYMM 0x04-YYDD 0x05-MMDD
								   0x06-YY 0x07-MM 0x08-DD
								   0x09-YYYY-MM-DD 0x0A-YYYY/MM/DD 0x10-HHMMSS
								   0x11-YYYYMMDDHHMMSS 0x12-YYMMDDHHMMSS 0x13-YYYY-MM-DD HH:MM:SS
								   0x14-YYYY/MM/DD HH:MM:SS 0x15-HH:MM:SS 0x16-YYYY-MM-DD HH:MM
								   0x17-YYYY/MM/DD HH:MM 0x18-HH:MM 0x19-HHMM
								   0x1A-HH 0x1B-MM 0x1C-SS
								   0x20-���ڼ� 0x21-YYYY-MM-DD HH:MM:SS ���ڼ� 0x22-YYYY/MM/DD HH:MM:SS ���ڼ�
								   0x23-����һ:1 ���ڶ�:2 ������:3 ������:4 ������:5 ������:6  ������:7
								   0x24-����������ʱ���ʽ��:2023/04/03 09:59:47(����һ)
								   0x25-����������ʱ���ʽ��:2023-04-03 09:59:47(����һ)
								   0x26-����������ʱ���ʽ��:2023��04��03��09ʱ59��47��(����һ)
								   0x27-����������ʱ���ʽ��:2023��04��03��09:59:47(����һ)
								   0x28-������Ӣ��ʱ���ʽ��:Mon, 3 Apr 2023 09:59:47 +0800
								   ����-YYYYMMDD
	Output	 : unsigned char *	�� pucOutputDate,���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : ������ʱ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentDate(unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetCurrentMillSeconds
	FuncFunc : ��ȡ�������������ĺ�����
	Input	 : None
	Output	 : unsigned long *	�� pulOutputMillSeconds	����������ĺ�����(MS)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : ������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentMillSeconds(unsigned long *pulOutputMillSeconds);

/***********************************************************************************************
	FuncName : Tool_GetCurrentSeconds
	FuncFunc : ��ȡ������������������
	Input	 : None
	Output	 : long *			�� plOutputSeconds	���������������(S)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : �ӹ�Ԫ 1970 ��1 ��1 �յ�UTC ʱ���0 ʱ0 ��0 ����������������������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrentSeconds(long *plOutputSeconds);

/***********************************************************************************************
	FuncName : Tool_GetTickCount
	FuncFunc : ��ȡ�������������ĺ�����
	Input	 : None
	Output	 : double *			�� pdOutputMillSeconds	����������ĺ�����(MS)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : �߾��ȼ�ʱ��(MS)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTickCount(double *pdOutputMillSeconds);

/***********************************************************************************************
	FuncName : Tool_GetSystemTimeFromUTC
	FuncFunc : ��UTCʱ��ֵ��ȡ������������������
	Input	 : INT64			�� llUTCTime,����UTCʱ��ֵ
	           unsigned char	�� ucTimestampFlag,����ʱ�����־:0-�뼶 1-���뼶
	           unsigned char	�� ucGmtFlag,����ʱ����־:0-����ʱ�� ��0-�Ǳ���ʱ��
		       unsigned char	�� ucSetTimeFlag,�Ƿ�����Ϊ��ǰϵͳʱ�� 0-������ 1-����ʱ��Ϊ��ǰϵͳʱ��
	           unsigned char   	�� ucFormatFlag,������ڸ�ʽ 0x00-YYYYMMDD 0x01-YYYY 0x02-YYYYMM 
															 0x03-YYMM 0x04-YYMMDD 0x05-MMDD 
															 0x06-MM 0x07-DD 08-YYYYMMDDHHMMSS
															 0x09-YYYYMMDDHHMMSSMSMSMS
															 0x0A-YYYYMMDDHHMMSS.MSMSMS
															 0x0B-YYYY-MM-DD HH:MM:SS
															 0x0C-YYYY/MM/DD HH:MM:SS
															 ����-YYYYMMDD
	Output	 : unsigned char *	�� pucOutputDate,���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date	 : 2013-07-23 19:00:55
	Descp    : �ӹ�Ԫ1970��1��1�յ�UTCʱ���0ʱ0��0����������������������
	History  : ����ʱ�����й����ù���ʱ������ʱ������ʱ��Ϊ��׼ʱ��:����ʱ��ΪGMT��8Сʱʱ���;
	           ����ʱ�䲢���Ǳ���(����116.4��)�ĵط�ʱ��,���Ƕ���120��ĵط�ʱ��,
	           �ʶ���120�ȵط�ʱ�ȱ����ĵط�ʱ��Լ14�ְ���;
	           ��Ϊ�������ڹ���ʱ�������еĶ�����,
	           ͬ��������ʱ��(����ʱ)�������8Сʱ(������ʱ��=����ʱ+8Сʱ,GMT+8);
	           �����������ķ�Χ�Ӷ���112.5�㵽����127.5��,�Զ���120��Ϊ������,
	           ����������7.5��,�ܿ��Ϊ15�������;
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetSystemTimeFromUTC(INT64 llUTCTime,unsigned char ucTimestampFlag,unsigned char ucGmtFlag,
													unsigned char ucSetTimeFlag,unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetTimestamp
	FuncFunc : ��һ������ת��Ϊ����ʱ����Ϣ
	Input	 : long				�� lInputSeconds	����������������(S)
			   unsigned char 	�� ucFormatFlag		���������ʱ���ʽ��־
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
														����-YYYYMMDDHHMMSS
	Output	 : unsigned char *	�� pucOutputData	���������ϢYYYYMMDDHHMMSS
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : lInputSeconds���4294967295(2^32-1)
	History  : ����ʱ(UTC)Ҳ����Ϊ�������α�׼ʱ��(GMT)����ʾ
	Other    : ���������Ϊ�ӹ�Ԫ 1970 ��1 ��1 �յ�UTC ʱ���0 ʱ0 ��0 ����������������������
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimestamp(long lInputSeconds,unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetTimestampEx
	FuncFunc : ��һ������ת��Ϊ����ʱ����Ϣ
	Input	 : INT64			�� lInputSeconds	����������������(S)
			   unsigned char 	�� ucFormatFlag		���������ʱ���ʽ��־
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
														����-YYYYMMDDHHMMSS
	Output	 : unsigned char *	�� pucOutputData	���������ϢYYYYMMDDHHMMSS
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : lInputSeconds���Դ���4294967295(2^32-1),��32503651199
	           ����lInputSeconds=4294967295(2^32-1),pucOutputData=21060207142815;
			   ����lInputSeconds=32503651199,pucOutputData=29991231235959;
	History  : ����ʱ(UTC)Ҳ����Ϊ�������α�׼ʱ��(GMT)����ʾ
	Other    : ���������Ϊ�ӹ�Ԫ 1970 ��1 ��1 �յ�UTC ʱ���0 ʱ0 ��0 ����������������������
*************************************************************************************************/
EXPORT unsigned char Tool_GetTimestampEx(INT64 lInputSeconds,unsigned char ucFormatFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_TimeToGmt
    FuncFunc : ��YYYYMMDDHHMMSS��ʽ����ת��GMTʱ��,����1970/1/1 0ʱ0��0�뵽ָ��ʱ�̵�����
	Input	 : const char *		�� pucInputDate	����ʱ����Ϣ(YYYYMMDDHHMMSS)
	           unsigned char	�� ucGmtFlag,����ʱ����־:0-����ʱ�� ��0-�Ǳ���ʱ��
	Output	 : time_t *			�� plOutputData	���ת����time_t��ʽ��ʱ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : GMT Time(S)
	History  : ����ʱ(UTC)Ҳ����Ϊ�������α�׼ʱ��(GMT)����ʾ
	           ����ʱ�����й����ù���ʱ������ʱ������ʱ��Ϊ��׼ʱ��:����ʱ��ΪGMT��8Сʱʱ���;
	Other    : ����: 
			   ����pcInputData=20090228102130,���plOutputData=134531388
			   ����pcInputData=21060207142815,������4294967295(2^32-1)
*************************************************************************************************/  
EXPORT unsigned char Tool_TimeToGmt(const unsigned char *pucInputDate,unsigned char ucGmtFlag,time_t *plOutputData);

/***********************************************************************************************
	FuncName : Tool_TimeToGmtEx
    FuncFunc : ��YYYYMMDDHHMMSS��ʽ����ת��GMTʱ��,����1970/1/1 0ʱ0��0�뵽ָ��ʱ�̵�����
	Input	 : const char *		�� pucInputDate	����ʱ����Ϣ(YYYYMMDDHHMMSS)
	           unsigned char	�� ucGmtFlag,����ʱ����־:0-����ʱ�� ��0-�Ǳ���ʱ��
	Output	 : INT64 *			�� plOutputData	���ת����time_t��ʽ��ʱ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : GMT Time(S):ʵ������_mktime64����,mktime����չ
	History  : ����ʱ(UTC)Ҳ����Ϊ�������α�׼ʱ��(GMT)����ʾ
	           ����ʱ�����й����ù���ʱ������ʱ������ʱ��Ϊ��׼ʱ��:����ʱ��ΪGMT��8Сʱʱ���;
	Other    : ����: 
			   ����pcInputData=20090228102130,���plOutputData=134531388
			   ����pcInputData=21060207142815,���plOutputData=4294967295(2^32-1)
			   ����pcInputData=29991231235959,���32503651199			   
*************************************************************************************************/  
EXPORT unsigned char Tool_TimeToGmtEx(const unsigned char *pucInputDate,unsigned char ucGmtFlag,INT64 *plOutputData);

/***********************************************************************************************
	FuncName : Tool_ConvertDateAndTime
	FuncFunc : ����ʱ���ʽת��
	Input	 : unsigned char 	�� ucFormatFlag		���������ʱ���ʽת����־
								   0x00:YYYYMMDDHHMMSS->YYYY/MM/DD HH:MM:SS
								   0x01:YYYYMMDDHHMMSS->YYYY-MM-DD HH:MM:SS
								   0x02:YYYY/MM/DD HH:MM:SS->YYYYMMDDHHMMSS
								   0x03:YYYY-MM-DD HH:MM:SS->YYYYMMDDHHMMSS
								   0x04:YYYY-MM-DD HH:MM:SS->YYYY/MM/DD HH:MM:SS
								   0x05:YYYY/MM/DD->YYYYMMDD
								   0x06:YYYY-MM-DD->YYYYMMDD
								   0x07:YYYYMMDD->���ڼ�(����һ-1,���ڶ�-2,������-3,������-4,������-5,������-6,������-7)
								   0x08:YYYY/MM/DD HH:MM:SS(�Ǳ�׼2020/8/12 9:09:12)->YYYY/MM/DD HH:MM:SS(��׼2020/08/12 09:09:12)
								   0x09:YYYY/MM/DD HH:MM:SS(�Ǳ�׼2020/8/12 9:09:12)->YYYYMMDDHHMMSS(��׼20200812090912)
								   0x0A:YYYYMMDDHHMMSS->YYYY��MM��DD�� HH:MM:SS
			   unsigned char *	�� pucInputData		���������ʱ����Ϣ
	Output	 : unsigned char *	�� pucOutputData	���������ʱ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : ������ʽ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConvertDateAndTime(unsigned char ucFormatFlag,unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetSysTime
	FuncFunc : ��ȡϵͳ��UTCʱ����Ϣ
	Input	 : unsigned char   	�� ucFormatFlag,������������ڸ�ʽ��־:
                                                             0x00-YYYYMMDD 0x01-YYYY 0x02-YYYYMM 
															 0x03-YYMM 0x04-YYMMDD 0x05-MMDD 
															 0x06-MM 0x07-DD 08-YYYYMMDDHHMMSS
															 0x09-YYYYMMDDHHMMSSMSMSMS
															 0x0A-YYYYMMDDHHMMSS.MSMSMS
															 0x0B-YYYY-MM-DD HH:MM:SS
															 0x0C-YYYY/MM/DD HH:MM:SS
															 0x0D-S(����ʱ��:������������)
															 0x0E-S(����ʱ��:������������)
															 ����-YYYYMMDD
	Output	 : unsigned char *	�� pucOutputDate,���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : UTCʱ��
	History  : None
	Other    : ��������Ǵ�1970�꿪ʼ�ļ���
*************************************************************************************************/
EXPORT unsigned char Tool_GetSysTime(unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_SetSysTime
	FuncFunc : ����ϵͳ����ʱ����Ϣ
	Input	 : unsigned char 	�� ucFormatFlag		���������ʱ���ʽ��־ 0:YYYYMMDDHHMMSS ��0:YYYY-MM-DD HH:MM:SS��YYYY/MM/DD HH:MM:SS
			   unsigned char *	�� pucInputData		����������Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : ����ʱ����ַ��� YYYYMMDDHHMMSS(ucFormatFlag==0)��YYYY-MM-DD HH:MM:SS(ucFormatFlag!=0)
	History  : None
	Other    : ��������Ǵ�1970�꿪ʼ�ļ���
*************************************************************************************************/
EXPORT unsigned char Tool_SetSysTime(unsigned char ucFormatFlag,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_GetMonDay
    FuncFunc : ȡ��ĳ��ĳ�µľ�������
	Input	 : int				�� iYear	��������
		       int				�� iMonth	������·�
	Output	 : int *			�� piDay	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ������ݺ��·�ȷ������µ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonDay(int iYear,int iMonth,int *piDay);

/*********************************************************************************************** 
	FuncName : Tool_GetByteOfSysDataType  
	FuncFunc : ��ȡ��ǰϵͳ����������ռ���ֽ���
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetByteOfSysDataType( void );

/*********************************************************************************************** 
	FuncName : Tool_Rand  
	FuncFunc : �����������(���ݷ�ΧΪ0~255)
	Input	 : unsigned int 	�� uiInputRandNumer   	������Ҫ���ɵ�������ݸ���
	Output	 : unsigned char *  �� pucOutputData  		������ɵ��������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ����ȡֵ��Χ0~255
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Rand(unsigned int uiInputRandNumer,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandInt 
	FuncFunc : �����������(���ݷ�ΧΪuiMin~uiMax)
	Input	 : unsigned int 	�� uiInputRandNumer   	������Ҫ���ɵ�������ݸ���
			   unsigned int 	�� uiMin   				�������ɵ���С����
	           unsigned int 	�� uiMax   				�������ɵ�������
	Output	 : unsigned int *  	�� puiOutputData  		������ɵ��������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ����ȡֵ��ΧuiMin~uiMax
	History  : 0~32767
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandInt(unsigned int uiInputRandNumer,unsigned int uiMin,unsigned int uiMax,unsigned int *puiOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandEx  
	FuncFunc : �����������(���ݷ�ΧΪucMin~ucMax)
	Input	 : unsigned int 	�� uiInputRandNumer   	������Ҫ���ɵ�������ݸ���
	           unsigned char 	�� ucMin   				�������ɵ���С����
	           unsigned char 	�� ucMax   				�������ɵ�������
	Output	 : unsigned char *  �� pucOutputData  		������ɵ��������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ����ȡֵ��ΧucMin~ucMax
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandEx(unsigned int uiInputRandNumer,unsigned char ucMin,unsigned char ucMax,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandFilter  
	FuncFunc : ������������������X��Y����(���ݷ�ΧΪ0~255)
	Input	 : unsigned char 	�� ucInputRandNumer   	������Ҫ���ɵ�������ݸ���
			   unsigned char 	�� ucX   				���������ɵ�����
			   unsigned char 	�� ucY   				��������˲��������ɵ�����ʹ�ø��������
	Output	 : unsigned char *  �� pucOutputData  		������ɵ��������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ����ȡֵ��Χ0~255,������ucXʱȡֵΪucY
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RandFilter(unsigned int uiInputRandNumer,unsigned char ucX,unsigned char ucY,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_RandLarge  
	FuncFunc : �����������(���ݷ�ΧΪMin~Max)
	Input	 : unsigned int 	�� uiInputRandNumer   	������Ҫ���ɵ�������ݸ���
	           unsigned long 	�� ulMin   				�������ɵ���С����
	           unsigned long 	�� ulMax   				�������ɵ�������
	Output	 : unsigned long *  �� pulOutputData  		������ɵ��������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ����ȡֵ��Χ(���ݷ�ΧΪMin~Max)
	History  : None
	Other    : unsigned int
*************************************************************************************************/
EXPORT unsigned char Tool_RandLarge(unsigned int uiInputRandNumer,unsigned long ulMin,unsigned long ulMax,unsigned long *pulOutputData);

/*********************************************************************************************** 
	FuncName : Tool_Pow2gt  
	FuncFunc : ��ȡ��x���ڻ���ڵ���С��2��N�η���
	Input	 : int 				�� iInputData,��������
	Output	 : int *  			�� piOutputData,�����x���ڻ���ڵ���С��2��N�η�����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : ��iInputData=2,*piOutputData=2;iInputData=3,*piOutputData=4;iInputData=4,*piOutputData=4;iInputData=5,*piOutputData=8;
*************************************************************************************************/
EXPORT unsigned char Tool_Pow2gt(int iInputData,int *piOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_Xor
	FuncFunc 	:  ��������֮���������
	Input	 	:  unsigned char *	��pucInputData1 		���������1
    			   unsigned char *	��pucInputData2 		���������2
    			   unsigned int 	��uiInputDataLen	    ����������ݵĳ���
	Output	 	:  unsigned char * 	��pucOutputData  		�������
	Return	 	:  unsigned	char 	���ɹ�,����TOOL_SUCCESS(0x00)
							 	 	��ʧ��,����TOOL_FAILURE(0x01)
							 	 	�������������,����TOOL_PARAMERROR(0x04)
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
	FuncFunc 	:  �����ַ�������֮���������
	Input	 	:  unsigned char *	��pucInputData1 		���������1
    			   unsigned char *	��pucInputData2 		���������2
    			   unsigned int 	��uiInputDataLen	    ����������ݵĳ���
	Output	 	:  unsigned char * 	��pucOutputData  		�������
	Return	 	:  unsigned	char 	���ɹ�,����TOOL_SUCCESS(0x00)
							 	 	��ʧ��,����TOOL_FAILURE(0x01)
							 	 	�� �����������,����TOOL_PARAMERROR(0x04)
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
	FuncFunc : ��n�����ݵ����ֵ(��ʼֵΪ0)
	Input	 : unsigned char *  �� pucInputData   	��������
			   unsigned int     �� uiInputDataLen   ����������ݵĳ���
	Output	 : unsigned char *  �� pucOutputData  	�������LRC 
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� �����������,����TOOL_PARAMERROR(0x04)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_DataXor(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_DataXorEx  
	FuncFunc : ��n�����ݵ����ֵ(��ʼֵΪucValue)
	Input	 : unsigned char	�� ucValue	   	  LRC�ĳ�ʼֵ
			   unsigned char *  �� pucInputData   ���������
			   unsigned int     �� uiInputDataLen ����������ݵĳ���
	Output	 : unsigned char *  �� pucOutputData  �������LRC 
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� �����������,����TOOL_PARAMERROR(0x04)
	Author   : Sunrier    
	Date     : 2010-09-23 13:12:52
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_DataXorEx(unsigned char ucValue,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_Not
	FuncFunc 	:  ���ݷ�
	Input	 	:  unsigned char *	��pucInputData	 	���������
    			   unsigned int 	��uiInputDataLen	����ĳ���
	Output	 	:  unsigned char * 	��pucOutputData  	���������
	Return	 	:  unsigned	char 	���ɹ�,����TOOL_SUCCESS(0x00)
							 	 	��ʧ��,����TOOL_FAILURE(0x01)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  None
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_Not(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_GetCheckSum  
	FuncFunc : ��ȡ�ͼ���ֵ
	Input	 : unsigned char *  �� pucInputData   	��������
			   unsigned int     �� uiInputDataLen   �������ݳ���
	Output	 : unsigned char *  �� pucCheckSum    	�������ֵ
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01) 
	Author   : Sunrier    
	Date     : 2010-09-23 13:12:52
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/ 
EXPORT unsigned char Tool_GetCheckSum(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucCheckSum);

/***********************************************************************************************
	FuncName : Tool_IsRangeByte
	FuncFunc : �Ƚ��ֽ������Ƿ���ָ���ķ�Χ��
	Input	 : unsigned char 	�� ucCompareFlag,����ȽϷ�Χ��־
	           unsigned char	�� ucMin,������С��Χ
	           unsigned char	�� ucMax,�������Χ
	           unsigned char 	�� ucInputData,���������
	Output	 : None
	Return	 : unsigned char	�� ��Χ��,����TOOL_SUCCESS(0x00)
					 			   ������Χ,����TOOL_FAILURE(0x01)
					 			   ������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : �ֽ�����(unsigned char)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsRangeByte(unsigned char ucCompareFlag,unsigned char ucMin,unsigned char ucMax,unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_AscToHex
	FuncFunc : ASCIIת��ΪHEX
	Input	 : unsigned char *	�� pucInputData		�����ASCII����(��������ݳ��������������,��2*uiOutputLen)
			   unsigned int 	�� uiOutputDataLen	�����HEX���ݳ���
	Output	 : unsigned char *	�� pucOutputData	�����HEX����
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : �� ����0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII��Ϊ"CC6D61E66185CBB6"),uiOutputDataLen = 8;
    			  ���0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6
    		   �� ����"123A45C67CF8",uiOutputDataLen = 6
    			  ���0x12 0x3A 0x45 0xC6 0x7C 0xF8
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToHex(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AscToHexEx
	FuncFunc : ASCIIת��Ϊ�������HEX��ֵ
	Input	 : unsigned char *	�� pucInputData		�����ASCII����
	           int 				�� iInputDataLen	�����ASCII���ݳ���
			   int 				�� iOutputDataLen	�����HEX���ݳ���
	Output	 : unsigned char *	�� pucOutputData	�����HEX����
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : �� ����12345,iInputDataLen = 5;
    			  ���12345,iOutputDataLen = sizeof(INT32);
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToHexEx(unsigned char *pucInputData,int iInputDataLen,unsigned char *pucOutputData,int iOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_AscToBcd
	FuncFunc : ASCIIת��ΪBCD
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiInputDataLen	��������ݳ���
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� �����������,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"12345678",uiInputDataLen = 8,uiOutputDataLen = 4
    			  ���0x12 0x34 0x56 0x78
    		   �� ����"123A45C67CF8",uiInputDataLen = 12,uiOutputDataLen = 6
    			  ���0x12 0x31 0x45 0x36 0x73 0x68
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AscToBcd(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AscToLong
	FuncFunc : ASCII��ת��Ϊ�޷��ų�����
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���λ��
	Output	 : unsigned long *	�� pulOutputData	������޷��ų���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� �����������,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"123",uiOutputDataLen = 3;
    			  ���123
    		   �� ����"123",uiOutputDataLen = 2;
    			  ���12
	History  : None
	Other    : �ú���ת������ӦС��1000000000
*************************************************************************************************/
EXPORT unsigned char Tool_AscToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToHex
	FuncFunc : ������ת����ʮ�������ַ���
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int 	�� uiInputDataLen	�������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BinaryToHex(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToDec
	FuncFunc : ���޷��Ŷ������ַ���ת��Ϊʮ������ֵ(�ַ������Ȳ���С��1�ʹ���32)
	Input	 : unsigned char 	�� pucInputData	���������
	Output	 : int *			�� piOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �����ַ������Ȳ���С��1�ʹ���32
	History  : None
	Other    : pucInputData="1010" *piOutputData=10
*************************************************************************************************/
EXPORT unsigned char Tool_BinaryToDec(unsigned char *pucInputData,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToAsc
	FuncFunc : BCDת��ΪASCII
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  ���"0123456"
    		   �� ����0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 16;
    			  ���0x30 0x30 0x36 0x30 0x36 0x31 0x30 0x36 0x36 0x31 0x38 0x35 0x30 0x30 0x30 0x36
    		   ��Tool_HexToAsc����Ϊ:'A'��'F'ת��Ϊ0x30
   	History  : None
	Other    : Ĭ�������,������߲�0
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToAsc(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToAscEx
	FuncFunc : BCDת��ΪASCII��չ����(��BCD��ѹ����ʽ)
	Input	 : unsigned char 	�� ucFillFlag		����BCD������־,0-����� ��0-�����
													��������Ȳ�Ϊż��λ,�ҿ�����������ǰ����(�����),
													�󿿵��������ݺ���(�����)
			   unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� BCD�����������0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  ���"0123456"
    		   �� BCD�����������0x12 0x34 0x56 ,uiOutputDataLen = 7;
    			  ���"1234560"
    		   ע:�ú�����BCD���е�'A'��'F'ת��Ϊ0x30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToAscEx(unsigned char ucFillFlag,unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToLong
	FuncFunc : BCD��ת�����޷��ų�����
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned long *	�� pulOutputData	������޷��ų���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34,uiOutputDataLen = 1;
    			  ���2
    		   �� ����0x12 0x34,uiOutputDataLen = 2;
    			  ���12
    		   �� ����0x12 0x34,uiOutputDataLen = 3;
    			  ���234
    		   �� ����0x12 0x34,uiOutputDataLen = 4;
    			  ���1234
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_BcdToStr
	FuncFunc : BCD��ת�����ַ���
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34,uiOutputDataLen = 1;
    			  ���'2'
    		   �� ����0x12 0x34,uiOutputDataLen = 2;
    			  ���"12"
    		   �� ����0x12 0x34,uiOutputDataLen = 3;
    			  ���"234"
    		   �� ����0x12 0x34,uiOutputDataLen = 4;
    			  ���"1234"
    		   ע:�ú�����BCD���е�'A'��'F'ת��Ϊ0x30
	History  : None
	Other    : ���ַ���ÿ������ֽڡ�ת��Ϊһ���ֽڵ�ASCII��(��0~9)
     		   �����������ַ����Ľ�β��0x00�ַ������� ��������ǽ�uiDestLen��������ַ���ת��ΪuiDestLen���ֽڳ��ȵ��ַ����� 
     		   ���uiDestLen��������ת�������ָ���ĵڶ���������ַ�����ʼ(�ӵ�һ���ֽڵĵ�4λ��ʼ)
*************************************************************************************************/
EXPORT unsigned char Tool_BcdToStr(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToAsc
	FuncFunc : ��һ���ַ���ʮ����ֵת����ASCII��
	Input	 : unsigned char 	�� ucInputData		������ַ�����
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'z' = 0x7A = 122,uiOutputDataLen = 2;
    			  ���"22"
    		   �� ����'z' = 0x7A = 122,uiOutputDataLen = 3;
    			  ���"122"
    		   �� ����'z' = 0x7A = 122,uiOutputDataLen = 5;
    			  ���"00122"
	History  : None
	Other    : ��unsigned  char ����(�ַ���10����)����ת��Ϊ��Ӧ��ASCII ���ַ���(ASCII value = digit value + 0x30)��
      		   Ŀ���ַ���(pucOutputData)��ת��ǰ���Ǹ�ֵΪ0x30 (�ַ�'0')��
      		   unsigned  char ���͵��������ֵ��3������������,���ת������ַ��������3���ַ��İ������ַ���ɵ�ASCII�ַ���
*************************************************************************************************/
EXPORT unsigned char Tool_CharToAsc(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToBcd
	FuncFunc : ��һ���ַ�ת����BCD��
	Input	 : unsigned char 	�� ucInputData		������ַ�����
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'z' = 0x7A = 122,uiOutputDataLen = 1;
    			  ���0x22
    		   �� ����'z' = 0x7A = 122,uiOutputDataLen = 4;
    			  ���0x00/0x00/0x01/0x22
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToBcd(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToBitStr
	FuncFunc : ��һ���ַ�ת���������ַ���
	Input	 : unsigned char 	�� ucInputData		������ַ�����
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'z' = 0x7A = 122
    			  ���"01111010"
    		   �� ����0x32
    			  ���"00110010"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToBitStr(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharToHex
	FuncFunc : �ַ�ת��ΪHEX��Ӧ��ʮ������
	Input	 : unsigned char	�� ucInputData	���������
	Output	 : None
	Return	 : unsigned	char 	�� �ɹ�,����HEX��ʽ��Ӧ��ʮ������
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : ������ucInputData='0'
    			 ����0
    		   ������ucInputData='1'
    			 ����1
    		   ������ucInputData='9'
    			 ����9
    		   ������ucInputData='a'����ucInputData='A'
    			 ����10
    		   ������ucInputData='f'����ucInputData='F'
    			 ����15
    		   ������ucInputData=0x20
    			 ����0
    		   ������ucInputData=0xFF
    			 ����8
	History  : Ĭ���������ݺϷ�,���������������Ч��
	Other    : ����ͬTool_HexToDec,�����Ҫ������ݵ���Ч��,��ʹ��Tool_HexToDec
*************************************************************************************************/
EXPORT unsigned char Tool_CharToHex(unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_CharToStr
	FuncFunc : �ַ�ת�����ַ���
	Input	 : unsigned char	�� ucInputData		������ַ�����
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'z' = 0x7A = 122,uiOutputDataLen = 2;
    			  ���"22"
    		   �� ����'z' = 0x7A = 122,uiOutputDataLen = 5;
    			  ���"00122"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharToStr(unsigned char ucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharLowCase
	FuncFunc : �ַ�ת����Сд�ַ�
	Input	 : unsigned char	�� ucInputData		�����һ���ַ�
	Output	 : unsigned char *	�� pucOutputData	�����Сд�ַ�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'Z'
    			  ���'z'
    		   �� ����'A'
    			  ���'a'
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharLowCase(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CharUpperCase
	FuncFunc : �ַ�ת����Сд�ַ�
	Input	 : unsigned char	�� ucInputData		�����һ���ַ�
	Output	 : unsigned char *	�� pucOutputData	�����Сд�ַ�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'z'
    			  ���'Z'
    		   �� ����'a'
    			  ���'A'
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CharUpperCase(unsigned char ucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DecToHex
	FuncFunc : HEX��Ӧ��ʮ������ת��Ϊʮ�������ַ�
	Input	 : int				�� iInputData	���������
	Output	 : None
	Return	 : unsigned	char	�� �ɹ�,����ʮ��������Ӧ��HEX�ַ�����ʽ('0'~'9','A'~'F')
	                            �� ʧ��,����0
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : ������ucInputData=0
    			 ����'0'==0x30
    		   ������ucInputData=1
    			 ����'1'==0x31
    		   ������ucInputData=9
    			 ����'9'==0x39
    		   ������ucInputData=10
    			 ����'A'==0x41
    		   ������ucInputData=12
    			 ����'C'==0x43
    		   ������ucInputData=15
    			 ����'F'==0x46
    		   ������ucInputData=-1
    			 ����ʧ��0
    		   ������ucInputData=128
    			 ����ʧ��0
    		   ������ucInputData=255
    			 ����ʧ��0
	History  : �������������Ч��,Ĭ�ϴ�д��ĸ
	Other    : ��Tool_HexToDec�෴����
*************************************************************************************************/
EXPORT unsigned char Tool_DecToHex(int iInputData);

/***********************************************************************************************
	FuncName : Tool_DecToHexEx
	FuncFunc : HEX��Ӧ��ʮ������ת��Ϊʮ�������ַ�
	Input	 : int				�� iInputData	���������
	           unsigned char	�� ucCaseFlag	�����Сд��ĸ��־:0-��д ��0-Сд
	Output	 : None
	Return	 : unsigned	char	�� �ɹ�,����ʮ��������Ӧ��HEX�ַ�����ʽ('0'~'9','A'~'F'��'a'~'f')
	                            �� ʧ��,����0
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : ������ucInputData=0
    			 ����'0'==0x30
    		   ������ucInputData=1
    			 ����'1'==0x31
    		   ������ucInputData=9
    			 ����'9'==0x39
    		   ������ucInputData=10,ucCaseFlag=0
    			 ����'A'==0x41
    		   ������ucInputData=12,ucCaseFlag=0
    			 ����'C'==0x43
    		   ������ucInputData=15,ucCaseFlag=0
    			 ����'F'==0x46
    		   ������ucInputData=10,ucCaseFlag=1
    			 ����'a'==0x61
    		   ������ucInputData=12,ucCaseFlag=1
    			 ����'c'==0x63
    		   ������ucInputData=15,ucCaseFlag=1
    			 ����'f'==0x66
    		   ������ucInputData=-1
    			 ����ʧ��0
    		   ������ucInputData=128
    			 ����ʧ��0
    		   ������ucInputData=255
    			 ����ʧ��0
	History  : �������������Ч��
	Other    : ��Tool_HexToDec�෴����
*************************************************************************************************/
EXPORT unsigned char Tool_DecToHexEx(int iInputData,unsigned char ucCaseFlag);

/***********************************************************************************************
	FuncName : Tool_HexToBinary
	FuncFunc : ʮ�������ַ���ת���ɶ�������
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int 	�� uiInputDataLen	�������ݵĳ���
			   unsigned int 	�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������(����ĳ���ΪuiInputDataLen/2)
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBinary(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToBinaryEx
	FuncFunc : ʮ�������ַ���ת���ɶ�������
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int 	�� uiInputDataLen	�������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������(����ĳ���ΪuiInputDataLen/2)
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBinaryEx(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToAsc
	FuncFunc : HEXת��ΪASCII
	Input	 : unsigned char *	�� pucInputData		�����HEX����
			   unsigned int 	�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	�����ASCII����(����ĳ���ΪuiSrcLen*2)
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 16;
    			  ���0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII��Ϊ"CC6D61E66185CBB6")
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToAsc(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToBcdLong
	FuncFunc : ��һ��ʮ������ת����BCD��ĳ�����
	Input	 : unsigned char 	�� ucInputData		�����һ��ʮ��������
	Output	 : unsigned long *	�� pulOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0xA8
    			  ���0x4138
    		   �� ����0x12
    			  ���0x3132
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToBcdLong(unsigned char ucInputData,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToStr
	FuncFunc : ʮ����������ת�����ַ���
	Input	 : unsigned char 	�� pucInputData		�����ʮ����������
	           unsigned int 	�� uiOutputDataLen		������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6,uiOutputDataLen = 8;
    			  ���0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII��Ϊ"CC6D61E66185CBB6")
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToStr(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToDec
	FuncFunc : ʮ�������ַ�ת��ΪHEX��Ӧ��ʮ������
	Input	 : unsigned char	�� ucInputData	���������
	Output	 : None
	Return	 : unsigned	char	�� �ɹ�,����HEX��ʽ��Ӧ��ʮ������(<16)
	                            �� ʧ��,����>=16
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : ������ucInputData='0'
    			 ����0
    		   ������ucInputData='1'
    			 ����1
    		   ������ucInputData='9'
    			 ����9
    		   ������ucInputData='a'����ucInputData='A'
    			 ����10
    		   ������ucInputData='f'����ucInputData='F'
    			 ����15
    		   ������ucInputData=0x20
    			 ����ʧ��16
    		   ������ucInputData=0xFF
    			 ����ʧ��16
	History  : �������������Ч��
	Other    : ��Tool_DecToHex�෴����
*************************************************************************************************/
EXPORT unsigned char Tool_HexToDec(unsigned char ucInputData);

/***********************************************************************************************
	FuncName : Tool_HexToInt
	FuncFunc : ʮ������ת�����޷�������
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int 	�� uiOutputDataLen	��������ݳ���λ��
	Output	 : unsigned int*	�� puiOutputData	������޷�����������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34 0x56 0x78,uiOutputDataLen = 1;
    			  ���0x12
    		   �� ����0x12 0x34 0x56 0x78,uiOutputDataLen = 2;
    			  ���0x1234
    		   �� ����0x12 0x34 0x56 0x78,uiOutputDataLen = 4;
    			  ���0x12345678
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Tool_HexToInt(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_HexStrToInt
	FuncFunc : ʮ�������ַ���ת�����޷�������
	Input	 : unsigned char *	�� pucInputData		���������
	Output	 : unsigned int*	�� puiOutputData	������޷�����������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����'1234',���0x1234==4660
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexStrToInt(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToLong
	FuncFunc : ʮ������ת�����޷��ų�����
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned long *	�� pulOutputData	������޷��ų���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 1;
    			  ���0x12
    		   �� ����0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 2;
    			  ���0x1234
    		   �� ����0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 4;
    			  ���0x12345678
	History  : �������0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 4,
	           ������0xFFFFFFFF=4294967295
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_HexToULongLong
	FuncFunc : ʮ������ת�����޷��ų�������
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���λ��
	Output	 : UINT64 *			�� pullOutputData	������޷��ų�����������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 1;
    			  ���0x12
    		   �� ����0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 2;
    			  ���0x1234
    		   �� ����0x12 0x34 0x56 0x78 0x90 0x12 0x34 0x56 0x78 0x90,uiOutputDataLen = 8;
    			  ���0x1234567812345678
			   �� ����0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 8;
    			  ���0xFFFFFFFFFFFFFFFF=18446744073709551615    		   
	History  : �������0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF,uiOutputDataLen = 8,
	           ������0xFFFFFFFFFFFFFFFF=18446744073709551615
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexToULongLong(unsigned char *pucInputData,unsigned int uiOutputDataLen,UINT64 *pullOutputData);

/***********************************************************************************************
	FuncName : Tool_HexStrToLong
	FuncFunc : ʮ�������ַ���ת�����޷��ų�����
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiInputDataLen	��������ݳ���
	Output	 : unsigned long *	�� pulOutputData	������޷��ų���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"0001",uiInputDataLen = 2;
    			  ���*pulOutputData=0
    		   �� ����"0C3F",uiInputDataLen = 2;
    			  ���*pulOutputData=12
    		   �� ����"1000",uiInputDataLen = 2;
    			  ���*pulOutputData=16
    		   �� ����"FFFF",uiInputDataLen = 2;
    			  ���*pulOutputData=255
    		   �� ����"0001",uiInputDataLen = 4;
    			  ���*pulOutputData=1
    		   �� ����"0C3F",uiInputDataLen = 4;
    			  ���*pulOutputData=3135
    		   �� ����"1000",uiInputDataLen = 4;
    			  ���*pulOutputData=4096
    		   �� ����"FFFF",uiInputDataLen = 4;
    			  ���*pulOutputData=65535
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_HexStrToLong(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToAsc
	FuncFunc : �޷�������ת����ASCII��
	Input	 : unsigned int		�� uiInputData		�������������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���λ��
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12345,uiOutputDataLen = 2;
    			  ���"45"
    		   �� ����12345,uiOutputDataLen = 7;
    			  ���"0012345"
	History  : None
	Other    : ת���޷������͵�ASCII��
*************************************************************************************************/
EXPORT unsigned char Tool_IntToAsc(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToBcd
	FuncFunc : �޷�������ת����BCD��
	Input	 : unsigned int 	�� uiInputData		�������������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12340,uiOutputDataLen = 2;
    			  ���0x23/0x40
    		   �� ����12340,uiOutputDataLen = 5;
    			  ���0x00/0x00/0x01/0x23/0x40
	History  : None
	Other    : ת�����ε�BCD��,����������ݳ��ȴ�����Чλ��ʱ�������Զ�ǰ����;������С����Чλ��,ȡĩλ��Чλ��
*************************************************************************************************/
EXPORT unsigned char Tool_IntToBcd(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToHex
	FuncFunc : �޷�������ת����ʮ��������
	Input	 : unsigned int 	�� uiInputData		�������������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12345(0x3039),uiOutputDataLen = 2;
    			  ���0x0x3039
    		   �� ����12345(0x3039),uiOutputDataLen = 5;
    			  ���0x0000003039
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IntToHex(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToStr
	FuncFunc : �޷�������ת�����ַ���
	Input	 : unsigned int		�� uiInputData		�������������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12345,uiOutputDataLen = 2;
    			  ���"45"
    		   �� ����12345,uiOutputDataLen = 7;
    			  ���"0012345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IntToStr(unsigned int uiInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_IntToStrEx
    FuncFunc : ��int������ת��Ϊ�ַ���,���Ȳ���ʱǰ��0
	Input	 : int				�� iInputData		����int������
	           int 				�� iOutputDataLen	����ת������ַ������ݳ���
	Output	 : char *			�� pcOutputData		���ת������ַ�������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ���Ȳ���ʱǰ��0
	History  : ��ltona������ͬ
	Other    : ��:iInputData=123,iOutputDataLen=5,pcOutputData="00123"
*************************************************************************************************/
EXPORT unsigned char Tool_IntToStrEx(int iInputData,int iOutputDataLen,char *pcOutputData);

/***********************************************************************************************
	FuncName : Tool_Int32ToStr
	FuncFunc : INT32����ת�����ַ���
	Input	 : INT32			�� i32InputData		�����INT32��������
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12345,���"12345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int32ToStr(INT32 i32InputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Int64ToStr
	FuncFunc : INT64����ת�����ַ���
	Input	 : INT64			�� i64InputData		�����INT64��������
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����12345,���"12345"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int64ToStr(INT64 i64InputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToAsc
	FuncFunc : �޷��ų�����ת����ASCII��
	Input	 : unsigned long	�� ulInputData		����ĳ���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890,uiOutputDataLen = 2;
    			  ���"90"
    		   �� ����1234567890,uiOutputDataLen = 12;
    			  ���"001234567890"
	History  : None
	Other    : ת���޷��ų����͵�ASCII��
*************************************************************************************************/
EXPORT unsigned char Tool_LongToAsc(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToBcd
	FuncFunc : �޷��ų�����ת����BCD��
	Input	 : unsigned long 	�� ulInputData		����ĳ���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890,uiOutputDataLen = 2;
    			  ���0x78/0x90
    		   �� ����1234567890,uiOutputDataLen = 7;
    			  ���0x00/0x00/0x12/0x34/0x56/0x78/0x90
	History  : None
	Other    : ת�������ε�BCD��,����������ݳ��ȴ�����Чλ��ʱ�������Զ�ǰ����;������С����Чλ��,ȡĩλ��Чλ��
*************************************************************************************************/
EXPORT unsigned char Tool_LongToBcd(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToHex
	FuncFunc : �޷��ų�����ת����ʮ��������
	Input	 : unsigned long 	�� ulInputData		����ĳ���������
			   unsigned int 	�� uiOutputDataLen	���������
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890(0x499602D2),uiOutputDataLen = 2;
    			  ���0x02D2
    		   �� ����1234567890(0x499602D2),uiOutputDataLen = 5;
    			  ���0x00499602D2
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHex(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToHexEx
	FuncFunc : �޷��ų�����ת����ʮ��������
	Input	 : unsigned long 	�� ulInputData		����ĳ���������
	Output	 : unsigned char *	�� pucOutputData	���������
	           unsigned int *	�� puiOutputDataLen	��������ݳ���
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890(0x499602D2);
    			  ���0x499602D2,*puiOutputDataLen = 4;
    		   �� ����12(4D2);
    			  ���0x4D2,*puiOutputDataLen = 2;
	History  : None
	Other    : unsigned long ���4294967295
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHexEx(unsigned long ulInputData,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_LongToHexStr
	FuncFunc : �޷��ų�����ת����ʮ���������ַ���
	Input	 : unsigned long 	�� ulInputData		����ĳ���������
	Output	 : unsigned char *	�� pucOutputData	���������
	           unsigned int *	�� puiOutputDataLen	��������ݳ���
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890(0x499602D2),ucOutputDataLen = 4;
    			  ���"02D2"
    		   �� ����1234567890(0x499602D2),ucOutputDataLen = 10;
    			  ���"0x00499602D2"
	History  : �������Ϊż��
	Other    : unsigned long ���4294967295
*************************************************************************************************/
EXPORT unsigned char Tool_LongToHexStr(unsigned long ulInputData, unsigned char ucOutputDataLen, unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToStr
	FuncFunc : �޷��ų�����ת�����ַ���
	Input	 : unsigned long	�� ulInputData		����ĳ���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����1234567890,uiOutputDataLen = 2;
    			  ���"90"
    		   �� ����1234567890,uiOutputDataLen = 12;
    			  ���"001234567890"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_LongToStr(unsigned long ulInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_LongToStrEx
    FuncFunc : ��long������ת��Ϊ�ַ���,���Ȳ���ʱǰ��0
	Input	 : long				�� lInputData		����long������
	           int 				�� iOutputDataLen	����ת������ַ������ݳ���
	Output	 : char *			�� pcOutputData		���ת������ַ�������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ���Ȳ���ʱǰ��0
	History  : ��ltona������ͬ
	Other    : ��:lInputData=123,iOutputDataLen=5,pcOutputData="00123"
*************************************************************************************************/
EXPORT unsigned char Tool_LongToStrEx(long lInputData,int iOutputDataLen,char *pcOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToHex
	FuncFunc : �޷���64λ������ת����ʮ��������
	Input	 : UINT64 			�� ui64InputData	���������
	           unsigned int		�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : �������8�ֽ�ǰ�油0x00
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToHex(UINT64 ui64InputData,unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToHexEx
	FuncFunc : �޷���64λ������ת����ʮ��������
	Input	 : UINT64 			�� ui64InputData	���������
	           unsigned int	*	�� puiOutputDataLen	����������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	           unsigned int	*	�� puiOutputDataLen	������ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : �������8�ֽ�ǰ�治��0x00
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToHexEx(UINT64 ui64InputData,unsigned char* pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_Itoa
	FuncFunc : ��һ���ַ�ת��ָ�����Ƶ��ַ���
	Input	 : int 				�� iInputData		�������������
	           int 				�� iRadix			�����ת����Ľ�����
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� iInputData=122,iRadix=2
    			  pucOutputData="01111010"
    		   �� ����iInputData=50,iRadix=2
    			  pucOutputData="00110010"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Itoa(int iInputData,int iRadix,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_FloatToStr
	FuncFunc : �ַ�����������ת��Ϊ�ַ���
	Input	 : unsigned char *	�� pucInOuputData	���������
	Output	 : unsigned char *	�� pucInOuputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : Ĭ���������λ
	History  : None
	Other    : �� ����"2796437180.95";
    			  ���"00000000279643718095"
    		   �� ����"2796437180.7";
    			  ���"00000000279643718070"
    		   �� ����"3.4030752576e+11";
    			  ���"00000034030752576000"
*************************************************************************************************/
EXPORT unsigned char Tool_FloatToStr(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DoubleToStr
	FuncFunc : �ַ�����������ת��Ϊ�ַ���
	Input	 : double			�� dInputData		�����double������
	           unsigned int		�� uiOutputDataLen	�����ת��������ݳ���
	Output	 : unsigned char *	�� pucOuputData		���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : Ĭ���������һλ
	History  : None
	Other    : �� ����1234,���"1234.0"
*************************************************************************************************/
EXPORT unsigned char Tool_DoubleToStr(double dInputData,unsigned int uiOutputDataLen,unsigned char *pucOuputData);

/***********************************************************************************************
	FuncName : Tool_StrToBcd
	FuncFunc : �ַ���ת����BCD��
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int 	�� uiOutputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"12345678",uiOutputDataLen = 4
    			  ���0x12 0x34 0x56 0x78
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToBcd(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToHex
	FuncFunc : �ַ���ת����ʮ��������
	Input	 : unsigned char *	�� pucInputData		�����ASCII����(��������ݳ��������������,��2*uiOutputLen)
			   unsigned int 	�� uiOutputDataLen	�����HEX���ݳ���
	Output	 : unsigned char *	�� pucOutputData	�����HEX����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-28 19:10:22
	Descp    : �� ����0x43 0x43 0x36 0x44 0x36 0x31 0x45 0x36 0x36 0x31 0x38 0x35 0x43 0x42 0x42 0x36(ASCII��Ϊ"CC6D61E66185CBB6"),uiOutputDataLen = 8;
    			  ���0xCC 0x6D 0x61 0xE6 0x61 0x85 0xCB 0xB6
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToHex(unsigned char *pucInputData,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt
    FuncFunc : ���ַ���ת��ΪINT��
	Input	 : unsigned char *	�� pucInputData		�����ַ�������
			   int				�� iInputDataLen	�����ַ������ݵĳ���
	Output	 : int *			�� piOutputData		�����������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �ַ���
	History  : ��natoi������ͬ
	Other    : ��:pcInputData="123",iInputDataLen=3,*piOutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt(unsigned char *pucInputData,int iInputDataLen,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToLong
	FuncFunc : �ַ���ת�����޷��ų�����
	Input	 : unsigned char *	�� pucInputData		���������
	Output	 : unsigned long *	�� pulOutputData	������޷��ų���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"123"
    			  ���123
	History  : None
	Other    : �ú���ת������ӦС��1000000000
*************************************************************************************************/
EXPORT unsigned char Tool_StrToLong(unsigned char *pucInputData,unsigned long *pulOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt32
    FuncFunc : ���ַ���ת��ΪINT32��
	Input	 : unsigned char *	�� pucInputData		�����ַ�������
			   int				�� iInputDataLen	�����ַ������ݵĳ���
	Output	 : INT32 *			�� pi32OutputData	�����������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : ��:pcInputData="123",iInputDataLen=3,*pi32OutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt32(unsigned char *pucInputData,int iInputDataLen,INT32 *pi32OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToInt64
    FuncFunc : ���ַ���ת��ΪINT64��
	Input	 : unsigned char *	�� pucInputData		�����ַ�������
			   int				�� iInputDataLen	�����ַ������ݵĳ���
	Output	 : INT64 *			�� pi64OutputData	�����������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : INT64��Χ:-9223372036854775808~9223372036854775807
	History  : None
	Other    : ��:pcInputData="123",iInputDataLen=3,*pi32OutputData=123
*************************************************************************************************/
EXPORT unsigned char Tool_StrToInt64(unsigned char *pucInputData,int iInputDataLen,INT64 *pi64OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToUint64
    FuncFunc : ���ַ���ת��ΪUINT64��
	Input	 : unsigned char *	�� pucInputData		�����ַ�������
			   int				�� iInputDataLen	�����ַ������ݵĳ���
	Output	 : UINT64 *			�� pui64OutputData	�����������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : UINT64��Χ:0~18446744073709551615
	History  : None
	Other    : ��:pcInputData="10446744073709551615",iInputDataLen=20,*pi32OutputData=10446744073709551615
*************************************************************************************************/
EXPORT unsigned char Tool_StrToUint64(unsigned char *pucInputData,int iInputDataLen,UINT64 *pui64OutputData);

/***********************************************************************************************
	FuncName : Tool_StrToFloat
	FuncFunc : �ַ���ת��Ϊ�ַ�����������
	Input	 : unsigned char *	�� pucInOuputData	���������
	           unsigned char 	�� ucBit			����Ľ�ȡ��λ��
	Output	 : unsigned char *	�� pucInOuputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : �� ����"00000000279643718095",ucBit = 10;
    			  ���"27.9643718095"
    		   �� ����"00000000279643718070",ucBit = 10;
    			  ���"27.964371807"
    		   �� ����"00000034030752576000",ucBit = 10;
    			  ���"3403.0752576"
*************************************************************************************************/
EXPORT unsigned char Tool_StrToFloat(unsigned char *pucInputData,unsigned char ucBit,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToDouble
	FuncFunc : �ַ���ת����double��
	Input	 : unsigned char *	�� pucInputData		���������
			   unsigned int		�� uiInputDataLen	��������ݳ���
	Output	 : double *			�� pdOutputData		�����double������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����"1234"
    			  ���123
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToDouble(unsigned char *pucInputData,unsigned int uiInputDataLen,double *pdOutputData);

/***********************************************************************************************
	FuncName : Tool_StrReverse
	FuncFunc : �ַ�����ת
	Input	 : unsigned char *	�� pucInOutputData	���������
	           unsigned char *	�� uiInputDataLen	��������ݳ���
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrReverse(unsigned char *pucInOutputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_StrLowerCase
	FuncFunc : �ַ���ת����Сд�ַ���
	Input	 : unsigned char *	�� pucInOutputData	���������
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrLowerCase(unsigned char *pucInOutputData);

/***********************************************************************************************
	FuncName : Tool_StrUpperCase
	FuncFunc : �ַ���ת���ɴ�д�ַ���
	Input	 : unsigned char *	�� pucInOutputData	���������
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrUpperCase(unsigned char *pucInOutputData);

/***********************************************************************************************
	FuncName : Tool_StrCaseCmp
	FuncFunc : �����ִ�Сд�Ƚ������ַ���
	Input	 : const unsigned char *	�� pucInputData1,���������1
	           const unsigned char *	�� pucInputData2,���������2
	Output	 : None
	Return	 : unsigned	char 			�� ����1=����2,����0
							 			�� ����1>����2,����>0
							 			�� ����1<����2,����<0
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCaseCmp(const unsigned char* pucInputData1, const unsigned char* pucInputData2);

/***********************************************************************************************
	FuncName : Tool_StrNCaseCmp
	FuncFunc : �����ִ�Сд�Ƚ������ַ�����iLenλ
	Input	 : const unsigned char *	�� pucInputData1,���������1
	           const unsigned char *	�� pucInputData2,���������2
	           int						�� iLen,����Ƚϵ����ݳ���
	Output	 : None
	Return	 : unsigned	char 			�� ����1=����2,����0
							 			�� ����1>����2,����>0
							 			�� ����1<����2,����<0
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrNCaseCmp(const unsigned char* pucInputData1, const unsigned char* pucInputData2,int iLen);

/***********************************************************************************************
	FuncName : Tool_StrEqual
	FuncFunc : �Ƚ������ַ���ֵ�Ƿ����(���ִ�Сд)
	Input	 : char *			�� pInStr1				�����ַ���1
			   char *			�� pInStr2				�����ַ���2
			   unsigned char	�� ucUpperLowerFlag		���ִ�Сд��־ 0-�����ִ�Сд 1-���ִ�Сд
	Output	 : None
	Return	 : unsigned char	�� ���,����TOOL_SUCCESS(0x00)
					 			�� �����,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrEqual(char *pInStr1,char *pInStr2,unsigned char ucUpperLowerFlag);

/***********************************************************************************************
	FuncName : Tool_StrTrimRight
	FuncFunc : ȥ���ַ����ұ������ַ�ucCh
	Input	 : unsigned char *	�� pucInOutputData	���������
			   unsigned char 	�� ucInputCh		ȥ�����ַ�
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ֻ����ָ����ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimRight(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimLeft
	FuncFunc : ȥ���ַ�����������ַ�ucCh
	Input	 : unsigned char *	�� pucInOutputData	���������
			   unsigned char 	�� ucInputCh		ȥ�����ַ�
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ֻ����ָ����ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimLeft(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimLeftRight
	FuncFunc : ȥ���ַ�����ߺ��ұ������ַ�ucCh
	Input	 : unsigned char *	�� pucInOutputData	���������
			   unsigned char 	�� ucInputCh		ȥ�����ַ�
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ֻ����ָ����ucInputCh
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimLeftRight(unsigned char *pucInOutputData,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrTrimCharLeft
	FuncFunc : ȥ���ַ�����߿�ʼ�ĵ�N�γ��ֵ��ַ�֮��������ַ�(�������ôγ��ֵ��ַ�)
	Input	 : unsigned char *	�� pucInputData	���������
			   unsigned int 	�� uiTimes			��N�ε��ַ�,ucTimes=0,��ȥ�����ַ��������еĸ��ַ�;ucTimes!=0,ȥ����ֹ��ucTimes��֮�����е��ַ�
			   unsigned char 	�� ucInputCh		ƥ��ȥ�����ַ�
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimCharLeft(unsigned char *pucInputData,unsigned int uiTimes,unsigned char ucInputCh,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrTrimM
	FuncFunc : ȥ���ַ����м�Ŀո�
	Input	 : unsigned char *	�� pucInOuputData	���������
	Output	 : unsigned char *	�� pucInOuputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ��������(\n)���Ʊ��(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimM(unsigned char *pucInOuputData);

/***********************************************************************************************
	FuncName : Tool_StrAllTrim
	FuncFunc : ȥ���ַ�����ߺ��ұߵĿո�
	Input	 : unsigned char *	�� pucInOuputData	���������
	Output	 : unsigned char *	�� pucInOuputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ��������(\n)���Ʊ��(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrimAll(unsigned char *pucInOuputData);

/***********************************************************************************************
	FuncName : Tool_StrTrim
	FuncFunc : ȥ���ַ����еĿո�
	Input	 : unsigned char *	�� pucInOuputData	���������
	           unsigned char 	�� ucTrimFlag		����ȥ���ı�־ 0-��� 1-�ұ� 2-�м� 3-��ߺ��ұ� 4-ȫ��
	Output	 : unsigned char *	�� pucInOuputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ��������(\n)���Ʊ��(\t)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrTrim(unsigned char *pucInOuputData,unsigned char ucTrimFlag);

/***********************************************************************************************
	FuncName : Tool_StrRightAlign
	FuncFunc : �ַ����ұ߶���,��߲��㲹�ض��ַ�
	Input	 : unsigned char *	�� pucInOutputData		�����ַ���,�ַ��������Ϊ�涨�ĳ���(���������ַ���Ϊ��)
			   unsigned int 	�� uiAlignLen			�涨�ĳ���,���256λ
			   unsigned char 	�� ucInputCh			���㳤��,���ض��ַ�-����ʾ�ַ�,���Ϊ������ʾ�ַ�Ĭ�ϲ��ո�
	Output	 : unsigned char *	�� pucInOutputData		����ַ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �Ҷ���,���ض��ַ�
	History  : None
	Other    : ���������ַ���Ϊ��
*************************************************************************************************/
EXPORT unsigned char Tool_StrRightAlign(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_StrAlignAddSymbol
	FuncFunc : �ַ�������,���㲹�ض��ַ�
	Input	 : unsigned char *	�� pucInOutputData		�����ַ���,�ַ��������Ϊ�涨�ĳ���(���������ַ���Ϊ��)
			   unsigned int 	�� uiAlignLen			�涨�ĳ���,���256λ
			   unsigned char 	�� ucInputCh			���㳤��,���ض��ַ�-����ʾ�ַ�,���Ϊ������ʾ�ַ�Ĭ�ϲ��ո�
			   unsigned char 	�� ucFlag				�����־,0-�Ҳ��� 1��������0-����
	Output	 : unsigned char *	�� pucInOutputData		����ַ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ע���С������
	History  : None
	Other    : ���������ַ���Ϊ��
*************************************************************************************************/
EXPORT unsigned char Tool_StrAlignAddSymbol(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_StrToAmt
	FuncFunc : ���ַ���תΪ���ģʽ
	Input	 : unsigned char *	�� pucInputData			�����ַ���
	Output	 : unsigned char *	�� pucOutputData		����ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ������"89235"�����"892.35"
    		   ������"2"�����"0.02"
    		   ������"0"�����"0.00"
    		   ������"0100"�����"1.00"
    		   ������û��ΪNULL,�����"0.00"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmt(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrToAmtEx
	FuncFunc : ��һ���ַ���ת��Ϊ�ַ������
	Input	 : unsigned char *	�� pucInputAmount	������ַ������(ASC��ʽ,��󳤶�12λ)
			   unsigned char *	�� pucCurrencyName	�����������
			   unsigned char 	�� ucNegativeFlag	����Ľ��������־ '-'��'D'��ʾ����;������־Ϊ����
	Output	 : unsigned char *	�� pucOutputAmount	����ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : ������000000012030,Ϊ����־����120.30
    		   ������000000012030,Ϊ����־����-120.30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmtEx(unsigned char *pucInputAmount,unsigned char *pucCurrencyName,unsigned char ucNegativeFlag,unsigned char *pucOutputAmount);

/***********************************************************************************************
	FuncName : Tool_StrToAmtLong
	FuncFunc : ��һ���ַ������ת��Ϊ�������
	Input	 : unsigned char *	�� pucInputAmount	������ַ������(ASC��ʽ,��󳤶�12λ)
	Output	 : unsigned long *	�� pulOutputAmount	����������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2010-09-23 19:00:55
	Descp    : ������000000012030,Ϊ����־����120.30
    		   ������000000012030,Ϊ����־����-120.30
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrToAmtLong(unsigned char *pucInputAmount,unsigned long *pulOutputAmount);

/***********************************************************************************************
	FuncName : Tool_StrCopy
	FuncFunc : �������ܽضϺ���
	Input	 : const unsigned char *	�� pucInputData		��������
               int 						�� iOutputDataLen	��ȡ�ĳ���,ֻ�������iLen-1���ֽڲ���󸽼�0x00
	Output	 : unsigned char *			�� pucOutputData	�������,�����ѿ������ַ���, ������NULL 
	Return	 : int						�� �����ѿ������ַ���
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : pucDest �� pucSrcָ�벻���ص�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCopy(const unsigned char *pucInputData,int iOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrCopyEx
	FuncFunc : �������ܽضϺ���
	Input	 : const unsigned char *	�� pucInputData		��������
               int 						�� iOutputDataLen	��ȡ�ĳ���,ֻ�������iLen-1���ֽڲ���󸽼�0x00
	Output	 : unsigned char *			�� pucOutputData  	�������,�����ѿ������ַ���, ������NULL 
	Return	 : int						�� �����ѿ������ַ���
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : pucDest �� pucSrcָ�벻���ص�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_StrCopyEx(const unsigned char *pucInputData,int iOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Strrchr
	FuncFunc : �����ַ��������һ���ַ����ֵĿ�ʼλ��
	Input	 : unsigned char *	�� pucInputData			�����ַ���
			   unsigned int 	�� ucInputCh			��ȡ���ַ�
			   unsigned char 	�� ucCutFlag			ucCutFlag:0x00-��ȡλ�ô����һ�����ֵ��ַ���ʼ
			                                                      0x01-��ȡλ�ô����һ�����ֵ��ַ����濪ʼ
			                                                      0x02-��ȡλ�ôӿ�ʼλ�õ����һ�����ֵ��ַ�(�������ַ�)
			                                                      0x03-��ȡλ�ôӿ�ʼλ�õ����һ�����ֵ��ַ�(���������ַ�)
			                                                      ����-��ȡλ�ô����һ�����ֵ��ַ���ʼ
	Output	 : unsigned char *	�� pucOutputData		����ַ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �����ַ��������һ���ַ����ֵĿ�ʼλ�õ��ַ���
	History  : None
	Other    : ��������ַ���Ϊ��
*************************************************************************************************/
EXPORT unsigned char Tool_Strrchr(unsigned char *pucInputData,unsigned char ucInputCh,unsigned char ucCutFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrFind
	FuncFunc : �����ַ������Ƿ����ĳ�����ַ���
	Input	 : unsigned char *	�� pucInputData			�����ַ���
			   unsigned char *	�� pucInputSubData		�������ַ���
	Output	 : None
	Return	 : unsigned char	�� ����,����TOOL_SUCCESS(0x00)
								�� ������,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �ַ�������������Ϊ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrFind(unsigned char *pucInputData,unsigned char *pucInputSubData);

/***********************************************************************************************
	FuncName : Tool_StrFindSubTimes
	FuncFunc : �����ַ������Ƿ����ĳ�����ַ���
	Input	 : unsigned char *	�� pucInputData			�����ַ���
			   unsigned char *	�� pucInputSubData		�������ַ���
	Output	 : unsigned int *	�� puiTimes				������ֵĴ���
	Return	 : unsigned char	�� ����,����TOOL_SUCCESS(0x00)
								�� ������,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �ַ�������������Ϊ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrFindSubTimes(unsigned char *pucInputData,unsigned char *pucInputSubData,unsigned int *puiTimes);

/***********************************************************************************************
	FuncName : Tool_StrReplace
	FuncFunc : ��pucNewStr�滻�ַ���pucInputData�е�pucOldStr
	Input	 : unsigned char *	�� pucInOutputData		������ַ���
			   unsigned char * 	�� pucOldStr			���뱻�滻���ַ���
			   unsigned char * 	�� pucNewStr			���������滻���ַ���
	Output	 : unsigned char *	�� pucInOutputData		������ַ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �����ַ��������һ���ַ����ֵĿ�ʼλ�õ��ַ���
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrReplace(unsigned char *pucInOutputData,unsigned char *pucOldStr,unsigned char *pucNewStr);

/***********************************************************************************************
	FuncName : Tool_GetBitFromUlongToHex
	FuncFunc : ��ȡ���޷��ų�����ת����ʮ���������ַ����λ��
	Input	 : unsigned long 	�� ulInputData		����ĳ���������
	Output	 : unsigned char *	�� pucOutputDataLen	������ݵ�λ��
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������54(0x36),���pucOutputDataLen = 2;
		       ������130(0x82),���pucOutputDataLen = 2;
		       ������511(0x1FF),���pucOutputDataLen = 3;
    		   ������1879048191(0x6FFFFFFF),���pucOutputDataLen = 8;
	History  : None
	Other    : unsigned long ���4294967295(0xFFFFFFFF),���pucOutputDataLen = 8;
*************************************************************************************************/
EXPORT unsigned char Tool_GetBitFromUlongToHex(unsigned long ulInputData,unsigned char *pucOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetBitFromUlonglongToHex
	FuncFunc : ��ȡ���޷��ų�������ת����ʮ���������ַ����λ��
	Input	 : UINT64 			�� ullInputData		����ĳ�����������
	Output	 : unsigned char *	�� pucOutputDataLen	������ݵ�λ��
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������54(0x36),���pucOutputDataLen = 2;
		       ������130(0x82),���pucOutputDataLen = 2;
		       ������511(0x1FF),���pucOutputDataLen = 3;
    		   ������1879048191(0x6FFFFFFF),���pucOutputDataLen = 8;
    		   ������4294967295(0xFFFFFFFF),���pucOutputDataLen = 8;
    		   ������18446744073709551615(0xFFFFFFFFFFFFFFFF),���pucOutputDataLen = 16;
	History  : None
	Other    : unsigned long ���18446744073709551615(0xFFFFFFFFFFFFFFFF),���pucOutputDataLen = 16;
*************************************************************************************************/
EXPORT unsigned char Tool_GetBitFromUlonglongToHex(UINT64 ullInputData,unsigned char *pucOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckHexVaildByBits
	FuncFunc : ����λ�����ʮ���������Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		����ʮ����������
	           unsigned int 	�� uiInputDataLen	����ʮ���������ݵĳ���
	           unsigned char 	�� ucBits			������Чλ��(1��64λ)
	Output	 : None
	Return	 : unsigned	char 	�� ��Ч,����TOOL_SUCCESS(0x00)
							 	�� ��Ч,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����pucInputData=0x36,uiInputDataLen=1,ucBits=3,������Ч;
		       �� ����pucInputData=0x36,uiInputDataLen=1,ucBits=9,������Ч;
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckHexVaildByBits(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucBits);

/***********************************************************************************************
	FuncName : Tool_DigitalStrRightAlign
	FuncFunc : ������ɵ��ַ����ұ߶���,��߲��㲹�ض��ַ�
	Input	 : unsigned char *	�� pucInOutputData		�����ַ���ֻ�����ֲ��ֿ�ʼ����,�ַ��������Ϊ�涨�ĳ���(���������ַ���Ϊ��)
			   unsigned int 	�� uiAlignLen			�涨�ĳ���,���256λ
			   unsigned char 	�� ucInputCh			���㳤��,���ض��ַ�-����ʾ�ַ�,���Ϊ������ʾ�ַ�Ĭ�ϲ�'0'
	Output	 : unsigned char *	�� pucInOutputData		����ַ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �Ҷ���,���ض��ַ�
	History  : None
	Other    : ���������ַ���Ϊ��
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrRightAlign(unsigned char *pucInOutputData,unsigned int uiAlignLen,unsigned char ucInputCh);

/***********************************************************************************************
	FuncName : Tool_DigitalStrAdd
	FuncFunc : ��ASC���ִ����,��ӽ�����ڱ�������,������ִ��Զ����Ҷ���
	Input	 : unsigned char *	�� pucInOutputAugend		���뱻����
			   unsigned char *	�� pucInputAddend			�������
			   unsigned int 	�� uiInputAlignLen			��������Ĺ涨����
	Output	 : unsigned char *	�� pucInOutputAugend		���������
			   unsigned char *	�� pucOutputCarryFlag		��λ��־0-û��λ 1-�н�λ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ���ַ����������
	History  : None
	Other    : ��������������
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrAdd(unsigned char *pucInOutputAugend,unsigned char *pucInputAddend,unsigned int uiInputAlignLen,unsigned char *pucOutputCarryFlag);

/***********************************************************************************************
	FuncName : Tool_DigitalStrSub
	FuncFunc : ��ASC���ִ����,���������ڱ�������,������ִ��Զ����Ҷ���
	Input	 : unsigned char *	�� pucInOutputMinuend		���뱻����
			   unsigned char *	�� pucInputSubtrahend		�������
			   unsigned int 	�� uiInputAlignLen			��������Ĺ涨����
	Output	 : unsigned char *	�� pucInOutputAugend		���������
			   unsigned char *	�� pucOutputCarryFlag		��λ��־0-û��λ 1-�н�λ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ���ַ����������
	History  : None
	Other    : ��������������
*************************************************************************************************/
EXPORT unsigned char Tool_DigitalStrSub(unsigned char *pucInOutputMinuend,unsigned char *pucInputSubtrahend,unsigned int uiInputAlignLen,unsigned char *pucOutputCarryFlag);

/***********************************************************************************************
	FuncName : Tool_GetEndian
	FuncFunc : ��ȡ��������ֵ���͵���������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ���ģʽ,����(0x02)
								�� С��ģʽ,����(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetEndian( void );

/***********************************************************************************************
	FuncName : Tool_ConvEndian
	FuncFunc : �ӵ�ǰ�����ֽ���ת��Ϊָ���ֽ���
	Input	 : unsigned char	�� ucEndianType	����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           unsigned char *	�� pucInOutputData	���������
	           unsigned int		�� uiInputDataLen	�������ݵĳ���
	Output	 : unsigned char *	�� pucInOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Tool_ConvEndian(unsigned char ucEndianType,unsigned char *pucInOutputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckBigEndian
	FuncFunc : �ж��Ƿ�Ϊ���ģʽ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ����ģʽ,����TOOL_SUCCESS(0x00)
								�� ʧ��С��ģʽ,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBigEndian( void );

/***********************************************************************************************
	FuncName : Tool_LittleEndian
	FuncFunc : С��ģʽ�ߵ�λת��
	Input	 : unsigned char *	�� pucInputData		���������
	Output	 : unsigned int *	�� pucOutputData	�����Ӧ��Ϣ�������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 2Bytes,��λ�ں�,��λ��ǰ
	History  : None
	Other    : ������"23" pucInputData = 2*256 + 3
*************************************************************************************************/
EXPORT unsigned char Tool_LittleEndian(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_BigEndian
	FuncFunc : ���ģʽ�ߵ�λת��
	Input	 : unsigned char *	�� pucInputData		���������
	Output	 : unsigned int *	�� pucOutputData	�����Ӧ��Ϣ�������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : 2Bytes,��λ��ǰ,��λ�ں�
	History  : None
	Other    : ������"23" pucInputData = 3*256 + 2
*************************************************************************************************/
EXPORT unsigned char Tool_BigEndian(unsigned char *pucInputData,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_ByteToInt32
	FuncFunc : �ӵ�ǰ�����ֽ���ת��Ϊָ���ֽ���
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int		�� uiInputDataLen	�������ݵĳ���
	           unsigned char	�� ucEndianType	����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           
	Output	 : INT32 *			�� pi32Data	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ByteToInt32(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,INT32 *pi32Data);

/***********************************************************************************************
	FuncName : Tool_ByteToUint64
	FuncFunc : �ӵ�ǰ�����ֽ���ת��Ϊָ���ֽ���
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned int		�� uiInputDataLen	�������ݵĳ���
	           unsigned char	�� ucEndianType	����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ	           
	Output	 : UINT64 *			�� pui64Data		���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ByteToUint64(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,UINT64 *pui64Data);

/***********************************************************************************************
	FuncName : Tool_Int64ToByte
	FuncFunc : �ӵ�ǰ�����ֽ���ת��Ϊָ���ֽ���
	Input	 : INT64 			�� i64InputData		���������
	           unsigned int		�� uiInputDataLen	�������ݵĳ���
	           unsigned char	�� ucEndianType		����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           unsigned int		�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Int64ToByte(INT64 i64InputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Uint64ToByte
	FuncFunc : �ӵ�ǰ�����ֽ���ת��Ϊָ���ֽ���
	Input	 : UINT64 			�� ui64InputData	���������
	           unsigned int		�� uiInputDataLen	�������ݵĳ���
	           unsigned char	�� ucEndianType		����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           unsigned int		�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)��TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���ģʽ,��λ��ǰ(�ߵ�ַ),��λ�ں�(�͵�ַ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Uint64ToByte(UINT64 ui64InputData,unsigned int uiInputDataLen,unsigned char ucEndianType,
									unsigned int uiOutputDataLen,unsigned char* pucOutputData);

/***********************************************************************************************
	FuncName : Tool_BinaryToValue
	FuncFunc : ������������Ҫ����������,����������ת��Ϊָ������������
	Input	 : unsigned char 	�� pucInputData		����Ķ�����������
	           unsigned int 	�� uiInputDataLen	��������������ݵĳ���
	           unsigned char	�� ucEndianType		����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           unsigned char 	�� ucDataType		�������������,�ο�DATA_TYPE
	Output	 : unsigned int *	�� puiOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned int Tool_BinaryToValue(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned char ucDataType,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_ValueToBinary
	FuncFunc : ������������Ҫ����������,��ԭ��������ת��Ϊָ���Ķ�������
	Input	 : unsigned int 	�� uiInputData		���������
	           unsigned char 	�� ucDataType		�������������,�ο�DATA_TYPE
	           unsigned int 	�� uiOutputDataLen	��������������ݵĳ���
	Output	 : unsigned int *	�� puiOutputData	����Ķ�����������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ValueToBinary(unsigned int uiInputData,unsigned char ucDataType,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DataConv
	FuncFunc : �����ֽ�������֮��ת��
	Input	 : unsigned char 	�� pucInputData		���������
	           unsigned int 	�� uiInputDataLen	�������ݵĳ���
	           unsigned char	�� ucEndianType		����ת������ֽ�������
	                               0x01:С��ģʽ 0x02:���ģʽ
	           unsigned char 	�� ucDataType		�������������,�ο�DATA_TYPE
	           unsigned char 	�� ucSignFlag		�����Ƿ�Ϊ�з���:1-�з���, 0-�޷���
	           unsigned int 	�� uiOutputDataLen	������ݵĳ���
	Output	 : unsigned char *	�� pucOutputData	���������
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
							 	�� ʧ��,����TOOL_FAILURE(0x01)
							 	�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DataConv(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucEndianType,unsigned char ucDataType,unsigned char ucSignFlag,unsigned int uiOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CheckBit
	FuncFunc : �����������ݵ�ĳ��BITλ�Ƿ�Ϊ1
	Input	 : unsigned char *	�� pucInputData		��������� 
			   unsigned int *	�� uiBit			����ļ���uiBitλ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)	��λΪ1
					 			�� ʧ��,����TOOL_FAILURE(0x01)	��λΪ0
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ʼλ��0��ʼ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBit(unsigned char *pucInputData,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_CheckBitEx
	FuncFunc : �����������ݵ�ĳ��BITλ�Ƿ�Ϊ1
	Input	 : unsigned long	�� ulInputData		���������
			   unsigned int *	�� uiBit			����ļ���uiBitλ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)	��λΪ1
					 			�� ʧ��,����TOOL_FAILURE(0x01)	��λΪ0
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ʼλ��0��ʼ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckBitEx(unsigned long ulInputData,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_SetBit
	FuncFunc : ����һ������ĳ��λ��Ϊ1
	Input	 : unsigned char *	�� pucInputOutputData	���������
			   unsigned int 	�� uiInputDataLen		�������ݵĳ���
			   unsigned int *	�� uiBit				�������õĵ�uiBitλ��
	Output	 : unsigned char *	�� pucInputOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,����TOOL_FAILURE
					 			�� ���������Ч,����TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : uiBit��ʼλ��1��ʼ����,���uiInputDataLen*8λ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetBit(unsigned char *pucInputOutputData,unsigned int uiInputDataLen,unsigned int uiBit);

/***********************************************************************************************
	FuncName : Tool_GetBit
	FuncFunc : ��ȡһ������ĳ��λ���Ƿ�Ϊ1
	Input	 : unsigned char *	�� pucInputData			���������
			   unsigned int 	�� uiInputDataLen		�������ݵĳ���
			   unsigned int *	�� uiBit				�����ȡ�ĵ�uiBitλ��
	Output	 : unsigned char *	�� pucOutputData		��������� 1-��λΪ1 0-��λΪ0
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : uiBit��ʼλ��1��ʼ����,���uiInputDataLen*8λ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetBit(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiBit,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ConvertDataByMask
	FuncFunc : ����������������
	Input	 : unsigned char *	�� pucInputData			��������
	           unsigned int		�� uiInputDataLen		�������ݳ���
	           unsigned int 	�� uiHeaderLen			��ʾǰ��λ
	           unsigned int 	�� uiTailLen			��ʾ��λ
	           unsigned char 	-  ucMaskChar			���κ���ַ�ʹ�ø��ַ�����
	Output	 : unsigned char *	�� pucOutputData		�������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2014-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConvertDataByMask(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned int uiHeaderLen,unsigned int uiTailLen,unsigned char ucMaskChar,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetFieldInfor
	FuncFunc : ��ȡ���ݸ�����Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char	�� ucSeparator		��������Ϣ֮��ָ���
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : ��:123|33f9df|898jjdk2|
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInfor(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforEx
	FuncFunc : ��ȡ���ݸ�����Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
			   int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char	�� ucSeparator		��������Ϣ֮��ָ���
			   unsigned char	�� ucStopChar		�����ֹ����ֹͣ�ַ�
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ֧�������ֹ����ֹͣ�ַ�
	History  : None
	Other    : ��:123|33f9df|898jjdk2|
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetStrFieldInfor
	FuncFunc : ��ȡ���ݴ�������Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char *	�� pucSeparator		��������Ϣ֮��ָ����ݴ�
			   unsigned int 	�� uiSeparatorLen	�ָ����ݴ������ݳ���
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : ��:123|=33f9df|=898jjdk2|=xx|=
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrFieldInfor(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char *pucSeparator,unsigned int uiSeparatorLen,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetStrFieldInforEx
	FuncFunc : ��ȡ���ݴ�������Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char *	�� pucSeparator		��������Ϣ֮��ָ����ݴ�
			   unsigned int 	�� uiSeparatorLen	�ָ����ݴ������ݳ���
			   unsigned char	�� ucStopChar		�����ֹ����ֹͣ�ַ�
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ֧�������ֹ����ֹͣ�ַ�
	History  : None
	Other    : ��:123|=33f9df|=898jjdk2|=xx|=
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrFieldInforEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char *pucSeparator,unsigned int uiSeparatorLen,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforBySep
	FuncFunc : ��ȡ���ݸ�����Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char	�� ucSeparator		��������Ϣ֮��ָ���
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned int *	�� puiOffset		�����һ����Ϣ��ʼλ��
	           unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ֧�������ָ���
	History  : None
	Other    : ��:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforBySep(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforBySepEx
	FuncFunc : ��ȡ���ݸ�����Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char	�� ucSeparator		��������Ϣ֮��ָ���
			   unsigned char	�� ucStopChar		�����ֹ����ֹͣ�ַ�
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned int *	�� puiOffset		�����һ����Ϣ��ʼλ��
	           unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ֧�������ָ���
	History  : None
	Other    : ��:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforBySepEx(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);

/***********************************************************************************************
	FuncName : Tool_GetFieldInforByMultiSep
	FuncFunc : ��ȡ���ݸ�����Ϣ��
	Input	 : unsigned char *	�� pucInputData		���������
	           int     			�� iInputDataLen	��������ݳ���
			   unsigned int		�� uiFieldFlag		�ĸ���Ϣ���־
			   unsigned char	�� ucSeparator		��������Ϣ֮��ָ���
			   unsigned char	�� ucStopChar		�����ֹ����ֹͣ�ַ�
			   unsigned char    -  ucZeroStopFlag	�Ƿ�֧��0x00��ֹ�ַ�0-��֧�� 1���0-֧��
	Output	 : unsigned int *	�� puiOffset		�����һ����Ϣ��ʼλ��
	           unsigned char *	�� pucOutputData	�����Ӧ��Ϣ�������
	           unsigned int *	�� puiOutputDatalen	�����Ӧ��Ϣ������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ֧�������ָ���,���������ķָ���ֻ����һ��
	History  : None
	Other    : ��:123|||33f9df||||898jjdk2||||
*************************************************************************************************/
EXPORT unsigned char Tool_GetFieldInforByMultiSep(unsigned char *pucInputData,int iInputDataLen,unsigned int uiFieldFlag,unsigned char ucSeparator,
			unsigned char ucStopChar,unsigned char ucZeroStopFlag,unsigned int *puiOffset,unsigned char *pucOutputData,unsigned int *puiOutputDatalen);
			
/***********************************************************************************************
	FuncName : Tool_BuildStrField
	FuncFunc : ���MISÿ����
	Input	 : const unsigned char *	�� pucInputData		����Ĵ������
			   unsigned int				�� uiInputDataLen	����Ĵ�����ݳ���
			   unsigned char 			�� ucSepFlag		�Ƿ�����ָ��� 0-�������ָ��� 1-�����ָ���
			   unsigned char * 			�� pucSeparator		�������ָ���
			   unsigned int  			�� uiSeparatorLen	�������ָ�������
	Output	 : unsigned char *			�� pucOutputData	������յĴ������
			   unsigned int	*			�� puiOutputDataLen ������յĴ�����ݳ���
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS
										�� ʧ��,������Ӧ������Ϣ(��0x00)
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
	FuncFunc : ���MISÿ����
	Input	 : const unsigned char *	�� pucInputData		����Ĵ������
			   unsigned int				�� uiInputDataLen	����Ĵ�����ݳ���
			   unsigned char 			�� ucSepFlag		�Ƿ�����ָ��� 0-�������ָ��� 1-�����ָ���
			   unsigned char 			�� ucFiledSepSign	�������ָ���(Ĭ������FS=0x1C)
	Output	 : unsigned char *			�� pucOutputData	������յĴ������
			   unsigned int	*			�� puiOutputDataLen ������յĴ�����ݳ���
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS
										�� ʧ��,������Ӧ������Ϣ(��0x00)
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BuildMisField(const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucSepFlag,unsigned char ucFiledSepSign,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMisField
	FuncFunc : ����uiFieldIndex��ȡָ���Ĳ���ֵ
	Input	 : unsigned int				�� uiFieldIndex		�����������
			   unsigned char			�� ucNullFlag		����������������Ƿ����Ϊ�ձ�־ 0-������Ϊ�� 1���0-����Ϊ��
			   unsigned char 			�� ucFiledSepSign	�������ָ���(Ĭ������FS=0x1C)
			   const unsigned char *	�� pucInputData		���������
			   unsigned int				�� uiInputDataLen	��������ݳ���
	Output	 : unsigned char *			�� pucOutputData	����Ĳ���
	           unsigned int *			�� puiOutputLen		����Ĳ�������
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS
										�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMisField(unsigned int uiFieldIndex,unsigned char ucNullFlag,unsigned char ucFiledSepSign,const unsigned char *pucInputData,const unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetDataField
	FuncFunc : �������������ȡָ����Ĳ���ֵ
	Input	 : const unsigned char *	�� pucInputData		���������
	           DataFieldTab *			�� pDataFieldTab	��������
			   unsigned int				�� uiExpectLen		��ȡ�����������ĳ���
			   unsigned char			�� ucNullFlag		����������������Ƿ����Ϊ�ձ�־ 0-������Ϊ�� 1���0-����Ϊ��
			   DataFieldTab *			�� pDataFieldTab	���������
	Output	 : unsigned char *			�� pucOutputData	����Ĳ���
	           unsigned int *			�� puiOutputLen		����Ĳ�������
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS
										�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDataField(const unsigned char *pucInputData,DataFieldTab *pDataFieldTab,unsigned int uiExpectLen,unsigned char ucNullFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_BuildDataField
	FuncFunc : ���ÿ��������
	Input	 : const unsigned char *	�� pucInputData		����Ĵ������
			   unsigned int				�� uiInputDataLen	����Ĵ�����ݳ���
			   unsigned char 			�� ucFiledSepSign	�������ָ���(Ĭ������FS=0x1C)
			   unsigned int 			�� uiMaxFiledSize	�������������
	Output	 : DataFieldTab *			�� DataFieldTab		������յĴ������
	           unsigned int *			�� puiDataFiledNum	�����������
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS
										�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2013-05-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BuildDataField(const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFiledSepSign,unsigned int uiMaxFiledSize,DataFieldTab *pDataField,unsigned int *puiDataFiledNum);

/***********************************************************************************************
	FuncName 	: Tool_DisplayAscData
	FuncFunc 	: ��ʾ������־����Ļ
    Input	 	: unsigned char *	��	pucInputTitle 	��ʾ��־����
    			  unsigned char *	��	pucInputData	��ʾ��������
	Output	 	: None
	Return	 	: unsigned char		�� �ɹ�,����TOOL_SUCCESS(0x00)
									�� ʧ��,����TOOL_FAILURE(0x01)
	Author		: Sunrier
	Date     	: 2013-12-24 19:13:21
	Descp    	: None
	History  	: None
	Other    	: None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayAscData(unsigned char *pucInputTitle,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_DisplayHexData
	FuncFunc : 16���Ʒ�ʽ��ʾ���ݵ�����
	Input	 : unsigned char *	�� pucInputTitle	����ı���
			   unsigned char *	�� pucInputData		���������
			   unsigned int		�� uiInputDataLen	��������ݳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayHexData(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_BeepWarning
	FuncFunc : ��ʾ��ʾ��Ϣ������
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char 	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BeepWarning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_Warning
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char 	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : Ĭ��5�볬ʱ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Warning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_WarningEx
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char    �� ucTimerFlag	    �����Ƿ�֧�ֳ�ʱ 0-��֧�� 1-֧��
			   unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
	           unsigned char *	�� pucInputData		�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char 	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : �����ó�ʱʱ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_FormatWarning
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : const char *		�� pFmt			��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char 	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FormatWarning(const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_FormatWarningEx
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char    �� ucTimerFlag	    �����Ƿ�֧�ֳ�ʱ 0-��֧�� 1-֧��
			   unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
			   const char *		�� pFmt				��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char 	�� ucKey			�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : �����ó�ʱʱ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FormatWarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_CheckLogLevel
	FuncFunc : ��鵱ǰ��־��־�Ƿ�Ϊָ������־�ȼ�
	Input	 : unsigned char	�� ucInputLogFlag 	����ĵ��Եȼ�
		       unsigned char 	�� ucLogCheckLevel	������־�ȼ�
		       										LOG_CHECK_LEVEL:
		       										           0-����־����
		       												   1-ERROR���� 
		       												   2-WARN����
		       												   3-INFO����
		       												   4-DEBUG����
		       												   5-ALL����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01��������0)
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLogLevel(unsigned char ucInputLogFlag,unsigned char ucLogCheckLevel);

/***********************************************************************************************
	FuncName : Tool_TraceLog
	FuncFunc : ������Ϣ��ʾ���ļ�
	Input	 : unsigned char	�� ucLogFlag		LOG��־:0-�������־����,�������������Ϣ 
	                                                        1-�����־����,�������Ӧ��־����ĵ�����Ϣ 
	                                                        2-�������־����,�����������Ϣ
	                                                        3-�����־����,�������������Ϣ 
			   unsigned char	�� ucInputLogLevel 	����ĵ��Եȼ�(ö������LOG_LEVEL�����ʹ��)
		       unsigned char 	�� ucCheckLogLevel	������־�ȼ�(�ο�ö������LOG_CHECK_LEVEL)
		                                                           :0-����־����
		       												   	   1-ERROR����
		       												   	   2-WARN����
		       												   	   3-INFO����
		       												   	   4-DEBUG����
		       												   	   5-ALL����
			   unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		���뱣����ļ���
			   unsigned char    �� ucFileFlag			���뱣���ļ����ӱ�־
			   											ucFileFlag:0-�޸�����Ϣ 1-������ļ����������ں�׺
			   unsigned char    �� ucCRFlag				�����ʽ���б�־
			                                            ucCRFlag 0x00-������ 
										    	        ucCRFlag&0x01-д�ļ���Ϣ֮ǰ�Ȼ���
										    	        ucCRFlag&0x02-д�ļ���Ϣ�껻�� 
		       char *			�� pcDebugFileName		��ǰ������ٵ��ļ���
			   int				�� iLine				���ļ�����������
			   const char *		�� pFmt					��ʽ���ַ���
			   ...				-  						��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01��������0)
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : ��ucCRFlag=0x03-д�ļ���Ϣ֮ǰ�Ȼ��к�д�ļ���Ϣ�궼����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TraceLog(unsigned char ucLogFlag,unsigned char ucInputLogLevel,unsigned char ucCheckLogLevel,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,char *pcDebugFileName,int iLine,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_TraceInfor
	FuncFunc : ������Ϣ��ʾ������
	Input	 : unsigned char    �� ucFormatFlag		�����ʽ��־
	           char *			�� pcDebugFileName	��ǰ������ٵ��ļ���
			   int				�� iLine			���ļ�����������
			   const char *		�� pFmt				��ʽ���ַ���
			   ...				-  					��ʽ���ַ���
	Output	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01��������0)
	Return	 : void
	Author	 : Sunrier
	Date     : 2010-10-03 19:00:55
	Descp    : ucFormatFlag 0x00-������ 
    	       ucFormatFlag&0x01-��ʾ��Ϣ֮ǰ�Ȼ��� 
    		   ucFormatFlag&0x02-��ʾ��Ϣ�껻�� 
    		   ucFormatFlag&0x03-��ʾ��Ϣ֮ǰ�Ȼ��к�д�ļ���Ϣ�궼����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TraceInfor(unsigned char ucFormatFlag,char *pcDebugFileName,int iLine,const char *pFmt, ...);

/***********************************************************************************************
	FuncName : Tool_IsNullData
	FuncFunc : �ж����������Ƿ�Ϊ��
	Input	 : unsigned char *	�� pucInputData		��������
			   unsigned int *	�� uiInputDataLen	�������ݵĳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS 	��ʾΪ��
								�� ʧ��,����TOOL_FAILURE	��ʾ��Ϊ��
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsNullData(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_SetStatus
	FuncFunc : ����ĳ��״̬λ
	Input	 : unsigned char *	�� pucInOutputData 	��������
		       unsigned char 	�� ucStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned char *	�� pucInOutputData 	�������
	Return	 : unsigned char	�� �ɹ�����TOOL_SUCCESS(0x00)
								�� ʧ�ܷ���TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetStatus(unsigned char *pucInOutputData,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetStatus
	FuncFunc : ��λĳ��״̬λ
	Input	 : unsigned char *	�� pucInOutputData 	��������
		       unsigned char 	�� ucStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned char *	�� pucInOutputData 	�������
	Return	 : unsigned char	�� �ɹ�����TOOL_SUCCESS(0x00)
								�� ʧ�ܷ���TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetStatus(unsigned char *pucInOutputData,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetUsStatus
	FuncFunc : ��λĳ��״̬λ
	Input	 : unsigned short *	�� pusInOutputData 	��������
		       unsigned short 	�� usStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned short *	�� pusInOutputData 	�������
	Return	 : unsigned char	�� �ɹ�����TOOL_SUCCESS(0x00)
								�� ʧ�ܷ���TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : ����������
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetUsStatus(unsigned short *pusInOutputData,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : Tool_ResetUiStatus
	FuncFunc : ��λĳ��״̬λ
	Input	 : unsigned int *	�� puiInOutputData 	��������
		       unsigned int 	�� uiStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned int *	�� puiInOutputData 	�������
	Return	 : unsigned char	�� �ɹ�����TOOL_SUCCESS(0x00)
								�� ʧ�ܷ���TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : ��������
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ResetUiStatus(unsigned int *puiInOutputData,unsigned int uiStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckStatus
	FuncFunc : ���ĳ��״̬λ��ֵ�Ƿ���ͬ
	Input	 : unsigned char	�� ucInputData 		��������
		       unsigned char 	�� ucStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : None
	Return	 : unsigned char	�� ��ͬ����TOOL_SUCCESS(0x00)
								�� ����ͬ����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckStatus(unsigned char ucInputData, unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckUshortStatus
	FuncFunc : ���ĳ��״̬λ��ֵ�Ƿ���ͬ
	Input	 : unsigned short	�� usInputData 	��������
		       unsigned short 	�� usStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : None
	Return	 : unsigned char	�� ��ͬ����TOOL_SUCCESS(0x00)
								�� ����ͬ����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : ������
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckUshortStatus(unsigned short usInputData, unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : Tool_CheckUihortStatus
	FuncFunc : ���ĳ��״̬λ��ֵ�Ƿ���ͬ
	Input	 : unsigned int		�� uiInputData 	��������
		       unsigned int 	�� uiStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : None
	Return	 : unsigned char	�� ��ͬ����TOOL_SUCCESS(0x00)
								�� ����ͬ����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : ������
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckUihortStatus(unsigned int uiInputData, unsigned int uiStatusFlag);

/***********************************************************************************************
	FuncName : Tool_GetSecByDiffDate
    FuncFunc : �����������ʼ��������ֹ����֮��ļ������
	Input	 : cconst unsigned char *	�� pucBeginDate,������ʼ����(YYYYMMDDHHMMSS)
	           const unsigned char *	�� pucEndDate,������ֹ����(YYYYMMDDHHMMSS)
	Output	 : long *					�� plIntervalSec,�����ʼ��������ֹ����֮��ļ������
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS(0x00)
					 					�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ʽ:YYYYMMDDHHMMSS
	History  : None
	Other    : ��ʼ���ڱ���С�ڵ�����ֹ����
*************************************************************************************************/
EXPORT unsigned char Tool_GetSecByDiffDate(const unsigned char *pucBeginDate,const unsigned char *pucEndDate,long *plIntervalSec);

/***********************************************************************************************
	FuncName : Tool_GetDayByDiffDate
    FuncFunc : �����������ʼ��������ֹ����֮��ļ������
	Input	 : cconst unsigned char *	�� pucBeginDate,������ʼ����(YYYYMMDD)
	           const unsigned char *	�� pucEndDate,������ֹ����(YYYYMMDD)
	Output	 : int *					�� piIntervalDay,�����ʼ��������ֹ����֮��ļ������
	Return	 : unsigned char			�� �ɹ�,����TOOL_SUCCESS(0x00)
					 					�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ʽ:YYYYMMDD
	History  : None
	Other    : ��ʼ���ڱ���С�ڵ�����ֹ����
*************************************************************************************************/
EXPORT unsigned char Tool_GetDayByDiffDate(unsigned char *pucBeginDate,unsigned char *pucEndDate,int *piIntervalDay);

/***********************************************************************************************
	FuncName : Tool_GetMonthByDiffDate
    FuncFunc : �����������ʼ��������ֹ����֮��ļ������
	Input	 : unsigned char *	�� pucBeginDate,������ʼ����(YYYYMMDD)
	           unsigned char *	�� pucEndDate,������ֹ����(YYYYMMDD)
	Output	 : int *			�� piIntervalMonth,�����ʼ��������ֹ����֮��ļ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ʽ:YYYYMMDD
	History  : None
	Other    : ��ʼ���ڱ���С����ֹ����
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthByDiffDate(unsigned char *pucBeginDate,unsigned char *pucEndDate,int *piIntervalMonth);

/***********************************************************************************************
	FuncName : Tool_CheckLeapYear
	FuncFunc : ���һ������Ƿ�Ϊ����
	Input	 : unsigned long 	�� ulInputYear �������(��ʽ:YYYY)
	Output	 : None
	Return	 : unsigned char	�� ����,����TOOL_SUCCESS
								�� ������,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��2012
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLeapYear(unsigned long ulInputYear);

/***********************************************************************************************
	FuncName : Tool_CheckValidDate
	FuncFunc : ��������Ƿ�Ϸ�
	Input	 : unsigned char 	�� ucFormatFlag �������ڸ�ʽ: 0x00-YYYYMMDD(8�ֽ�) 
															  0x01-YYYYMM(6�ֽ�)
														      0x02-YYMMDD(6�ֽ�)
														      0x03-YYMM(4�ֽ�)
														      0x04-MMDD(4�ֽ�)
														      0x05-HHMMSS(6�ֽ�)
														      0x06-YYYYMMDDHHMMSS(14�ֽ�)
														      0x07-YYYY/MM/DD HH:MM:SS(19�ֽ�)
														      0x08-YYYY-MM-DD HH:MM:SS(19�ֽ�)													      
														      0x09-HH:MM:SS(8�ֽ�)
														      0x10-YYYYMMDD(4�ֽ�)
															  0x11-YYYYMM(3�ֽ�)
														      0x12-YYMMDD(3�ֽ�)
														      0x13-YYMM(2�ֽ�)
														      0x14-MMDD(2�ֽ�)
														      0x15-HHMMSS(3�ֽ�)
														      0x16-YYYYMMDDHHMMSS(7�ֽ�)
	           unsigned char *	�� pucInputDate ��������(��ʽ:YYYYMMDD)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ΪMMDDʱ,��������
	History  : None
	Other    : ��20120203
*************************************************************************************************/
EXPORT unsigned char Tool_CheckValidDate(unsigned char ucFormatFlag,unsigned char *pucInputDate);

/***********************************************************************************************
	FuncName : Tool_GetYesterday
    FuncFunc : ����һ������(YYYYMMDD��YYYY-MM-DD��YYYY/MM/DD),�����������ǰ���һ��
	Input	 : unsigned char *	�� pucInputDate		����������Ϣ
	           unsigned char   	�� ucFormatFlag		����������ڵĸ�ʽ 
											        0x00:��ԭ�����ʽһ�� 0x01:YYYYMMDD 0x02:YYYY-MM-DD 0x03:YYYY/MM/DD
	Output	 : unsigned char *	�� pucOutputDate	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ���ڸ�ʽ:YYYYMMDD
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetYesterday(unsigned char *pucInputDate,unsigned char ucFormatFlag,unsigned char *pucOutputDate);

/***********************************************************************************************
	FuncName : Tool_GetTomorrow
	FuncFunc : ����һ������(YYYYMMDD��YYYY-MM-DD��YYYY/MM/DD),����������ں����һ��
	Input	 : unsigned char *	�� pucInputDate		����������Ϣ
	           unsigned char   	�� ucFormatFlag		����������ڵĸ�ʽ 
											        0x00:��ԭ�����ʽһ�� 0x01:YYYYMMDD 0x02:YYYY-MM-DD 0x03:YYYY/MM/DD
	Output	 : unsigned char *	�� pucOutputDate	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-07-23 19:00:55
	Descp    : �������ڸ�ʽ��ucFormatFlagָ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTomorrow(unsigned char *pucInputDate,unsigned char ucFormatFlag,unsigned char *pucOutputDate);;

/***********************************************************************************************
	FuncName : Tool_CheckDateExp
	FuncFunc : ��������Ƿ��Ѿ�����
	Input	 : unsigned char *	�� pucInputDateExp ��������ʱ����ַ���(YYYYMMDD)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)������
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ����ʱ����ַ��� YYYYMMDD
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckDateExp(unsigned char *pucInputDateExp);

/***********************************************************************************************
	FuncName : Tool_CheckDigital
	FuncFunc : �������������Ƿ�Ϊ�����ַ����
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned char 	�� ucFlag			��������Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckDigital(unsigned char *pucInputData,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_CheckAlpOrDig
	FuncFunc : �������������Ƿ�Ϊ���ֻ���ĸ
	Input	 : unsigned char *	�� pucInputData		���������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAlpOrDig(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAlpOrDigEx
	FuncFunc : �������������Ƿ���ĸ���������,���԰���һ�������ַ�
	Input	 : unsigned char *	�� pucInputData		�������Ϣ
		       unsigned char 	�� ucSpeCh			����һ�����԰����������ַ�
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAlpOrDigEx(unsigned char *pucInputData,unsigned char ucSpeCh);

/***********************************************************************************************
	FuncName : Tool_CheckHex
	FuncFunc : �������������Ƿ�Ϊʮ�������ַ����
	Input	 : unsigned char *	�� pucInputData,���������
	           unsigned int		�� uiInputDataLen,�������ݵĳ���
	           unsigned char 	�� ucHexCaseFlag,������ĸ�Ƿ��Сд:0-����� 1-�����д 2-����Сд
	           unsigned char 	�� ucNullFlag,��������Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : pucInputData='2E3F0103',����TOOL_SUCCESS
	           pucInputData='2QDW3DFK',����TOOL_FAILURE
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckHex(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucHexCaseFlag,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_CheckValidIp
	FuncFunc : ��������IP��ַ�Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		�����IP����
	Output	 : None
	Return	 : unsigned char	�� ��Ч�ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ��Чʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckValidIp(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAmount
	FuncFunc : �������Ľ���Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned char 	�� ucCheckBit		�Ƿ������С�������λ��:0-����� 1-���ucCheckBitλ���
	           unsigned char 	�� ucFixBitFlag		�Ƿ�С�������λ���̶�:0-���̶� 1-�̶�
	           unsigned char 	�� ucZeroFlag		����Ƿ����Ϊ0��־:0-������ 1-����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ���12λ(���ֵ999999999L)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmount(unsigned char *pucInputData,unsigned char ucCheckBit,unsigned char ucFixBitFlag,unsigned char ucZeroFlag);

/***********************************************************************************************
	FuncName : Tool_CheckAmountEx
	FuncFunc : �������ļ۸��Ƿ�Ϸ����13λ(����С����)
	Input	 : unsigned char *	�� pucInputData		���������	
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : �������ļ۸�, ����۸������С����,С������������λ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmountEx(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_CheckAmountWithPoint
	FuncFunc : �������Ĵ���С�������Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		���������		       
	           unsigned char 	�� ucPointBit		С�������λ��
	           unsigned char 	�� ucCheckBit		�Ƿ������С�������λ��:0-����� 1-���ucCheckBitλ���
	           unsigned char 	�� ucFixBitFlag		�Ƿ�С�������λ���̶�:0-���̶� 1-�̶�
	           unsigned char 	�� ucZeroFlag		����Ƿ����Ϊ0��־:0-������ 1-����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ucCheckBit!=0ʱ,���ucCheckBitλ(���ֵ999999999.99f)
	History  : None
	Other    : ��ʽ:xxx.xx or xxx.x
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAmountWithPoint(unsigned char *pucInputData,unsigned char ucPointBit,unsigned char ucCheckBit,unsigned char ucFixBitFlag,unsigned char ucZeroFlag);

/***********************************************************************************************
	FuncName : Tool_CheckFloatZero
	FuncFunc : �������ķ������Ƿ�Ϊ0
	Input	 : float			�� fInputData,���������
	Output	 : None
	Return	 : unsigned char	�� 0,����TOOL_SUCCESS(0x00)
					 			�� ��Ϊ0,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckFloatZero(float fInputData);

/***********************************************************************************************
	FuncName : Tool_IsBlankspace
	FuncFunc : �������������Ƿ�Ϊֻ�ǿո�
	Input	 : unsigned char *	�� pucInputData		���������
	           unsigned char 	�� ucFlag			��������Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	Output	 : None
	Return	 : unsigned char	�� ֻ�ǿո�,����TOOL_SUCCESS(0x00)
					 			�� ��ֻ�ǿո�,������Ӧ������Ϣ(��0)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsBlankspace(unsigned char *pucInputData,unsigned char ucFlag);

/***********************************************************************************************
	FuncName : Tool_InputText
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputText(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputTextEx
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned char *	�� pucInOutputData	������Ϣ
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
			   unsigned char	�� ucAlpFlag		�����Ƿ�������ĸ�ͷ���֧��'#'���л�
	Output	 : unsigned char *	�� pucInOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputTextEx(unsigned char* pucInputTitle,unsigned char *pucInOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char ucAlpFlag,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputNum
	FuncFunc : ����һ��������ɵ���Ϣ,ֻ�������ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
			   unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,ֻ�������ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputNum(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputNumber
	FuncFunc : ����һ����Ϣ,ֻ���������
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(��СΪ����1,������Ϊ0)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen ���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,ֻ���������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputNumber(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPwd
	FuncFunc : ����һ����Ϣ������,ֻ�������ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucDispMode		������ʾģʽ-0x00-���������ʾ(Ĭ�Ϸ�ʽ) 0x01-���Ҷ�����ʾ
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
		       unsigned int *	�� puiOutputDataLen ���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ������,ֻ�������ַ����(֧����ʾ����ģʽ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPwd(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWord
	FuncFunc : ����һ����Ϣ������,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucDispMode		������ʾģʽ-0x00-���������ʾ(Ĭ�Ϸ�ʽ) 0x01-���Ҷ�����ʾ
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen ���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ������,���������ֺ���ĸ�Լ�����ʾ�ַ����(֧����ʾ����ģʽ)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWord(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWordText
	FuncFunc : ����һ����Ϣ������,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen ���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ������,���������ֺ���ĸ�Լ�����ʾ�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWordText(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputPassWordNum
	FuncFunc : ����һ��������ɵ�����,ֻ�������ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen ���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ������,ֻ�������ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputPassWordNum(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputBcd
	FuncFunc : ����һ��BCD���ʽ����Ϣ
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��BCD���ʽ����Ϣ,��'0'��'9'����'A'��'F'�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputBcd(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputIp
	FuncFunc : ����һ��IP��ַ��Ϣ,ֻ�������ַ���.�ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
			   unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��IP��ַ��Ϣ,ֻ�����ֺ�.�ַ����,��138.12.89.67
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputIp(unsigned char *pucInputTitle,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputCn
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�����ַ����
	Input	 : unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��ʱ,����TOOL_TIMEOUT(0x02)
								�� �û�ȡ��,����TOOL_KEYCANCEL(0x03)(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�����ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputCn(unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_InputAmout
	FuncFunc : ��������Ϣ,ֻ�������ַ����
	Input	 : unsigned char 	�� ucStartLine			�������ʼ����
	           unsigned char *	�� pucMsgPrompt			������ʾ�ı���
	           unsigned char 	�� ucNegativeFlag		������������־
	           unsigned char *	�� pucCurrencyName		����Ļ�������
			   unsigned char	�� ucZeroAmtAllowFlag	������Ƿ���Խ��Ϊ0��־ TRUE-����Ϊȫ0 ����-������
	Output	 : unsigned char *	�� pucOutputData		�������Ľ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����MISAPP_OK
					 			�� ʧ��,���ط�MISAPP_OK
	Author	 : Sunrier
	Date     : 2013-05-09 19:10:22
	Descp    : ����һ�������Ϣ,ֻ�������ַ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_InputAmout(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char ucNegativeFlag,unsigned char *pucCurrencyName,unsigned char ucZeroAmtAllowFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountCmp
	FuncFunc : �Ƚ������ַ������
	Input	 : unsigned char *	�� pucAmount1	�����ַ������1
			   unsigned char *	�� pucAmount2	�����ַ������2
	Output	 : None
	Return	 : int				�� 0:pucAmount1==pucAmount2
								�� >0:pucAmount1>pucAmount2
								�� <0:pucAmount1<pucAmount2
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_AmountCmp(unsigned char *pucAmount1,unsigned char *pucAmount2);

/***********************************************************************************************
	FuncName : Tool_AddAmountPoint
	FuncFunc : ���ַ������ĩβ���С����
	Input	 : unsigned char *	�� pucInputData		�����ַ������
	           unsigned char 	�� ucTrimZeroFlag	����ĩβ0�Ƿ�ȥ����־:0-��ȥ�� 1-ȥ��
	Output	 : unsigned char *	�� pucOutputData	�������С������ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : ��:pucInputData=2000068,ucTrimZeroFlag=0,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=0,pucOutputData=200006.80
	              pucInputData=2000068,ucTrimZeroFlag=1,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=1,pucOutputData=200006.8
*************************************************************************************************/
EXPORT unsigned char Tool_AddAmountPoint(unsigned char *pucInputData,unsigned char ucTrimZeroFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_TrimAmountPoint
	FuncFunc : ȥ���ַ������С����
	Input	 : unsigned char *	�� pucInputData		�������С������ַ������
	Output	 : unsigned char *	�� pucOutputData	������ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : ��:pucInputData=20000.68,pucOutputData=2000068;pucInputData=200006.8,pucOutputData=20000680
*************************************************************************************************/
EXPORT unsigned char Tool_TrimAmountPoint(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountAdd
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucAdd1			�����ַ������1
			   unsigned char *	�� pucAdd2			�����ַ������2
			   unsigned char 	�� ucMaxLen			�����ַ��������󳤶�(��ucMaxLen=0ʱ,Ĭ��ucMaxLen;����Ϊ0<ucMaxLen<=50)
	Output	 : unsigned char *	�� pucOutputData	�������Ӻ���ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucAdd1 + pucAdd2
	History  : None
	Other    : ��:100+203=303
*************************************************************************************************/
EXPORT unsigned char Tool_AmountAdd(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountAddEx
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucAdd1			�����ַ������1
			   unsigned char *	�� pucAdd2			�����ַ������2
			   unsigned char 	�� ucMaxLen			�����ַ��������󳤶�(��ucMaxLen=0ʱ,Ĭ��ucMaxLen;����Ϊ0<ucMaxLen<=50)
	Output	 : unsigned char *	�� pucOutputData	�������Ӻ���ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 + pucSub2
	History  : None
	Other    : ��:1.00+2.03=3.03
*************************************************************************************************/
EXPORT unsigned char Tool_AmountAddEx(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountSub
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucSub1			�����ַ������1
			   unsigned char *	�� pucSub2			�����ַ������2
	Output	 : unsigned char *	�� pucOutputData	������������ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 - pucSub2
	History  : None
	Other    : pucSub1>=pucSub2
*************************************************************************************************/
EXPORT unsigned char Tool_AmountSub(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AmountSubEx
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucSub1			�����ַ������1
			   unsigned char *	�� pucSub2			�����ַ������2
	Output	 : unsigned char *	�� pucOutputData	������������ַ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucOutputData = pucSub1 - pucSub2
	History  : None
	Other    : ��:3.00-2.03=0.97
*************************************************************************************************/
EXPORT unsigned char Tool_AmountSubEx(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucOutputData);

/*********************************************************************************************** 
	FuncName : Tool_GetPrincipalInterest
	FuncFunc : ��ȡ��Ϣ�򱾽�
	Input	 : double 			�� dPrincipal,���뱾��
			   double			�� dInterestRate,�������ʻ���Ͷ�ʻر���
			   unsigned int		�� uiInterestYear,����Ͷ������
			   unsigned char	�� ucFlag,�����ȡ��Ϣ�򱾽��־:0-������(������Ϣ) 1-��Ϣ
	Output	 : double *			�� pdPrincipalInterest,�����Ϣ�򱾽�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPrincipalInterest(double dPrincipal,double dInterestRate,unsigned int uiInterestYear,unsigned char ucFlag,double *pdPrincipalInterest);

/*********************************************************************************************** 
	FuncName : Tool_GetAnnualInterestRate
	FuncFunc : ��ȡ�긴����
	Input	 : double 			�� dOrgPrincipal,����ԭʼ����
			   double 			�� dFinalPrincipal,�������ձ���(������)
			   unsigned int		�� uiInterestYear,����Ͷ������
	Output	 : unsigned char *	�� pucInterestRate,����긴����(��λ%)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : ���5%,��ʾ0.05
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetAnnualInterestRate(double dOrgPrincipal,double dFinalPrincipal,unsigned int uiInterestYear,unsigned char *pucInterestRate);

/*********************************************************************************************** 
	FuncName : Tool_GetInterestYear
	FuncFunc : ��ȡ��Ϣ�򱾽�
	Input	 : double 			�� dPrincipal,���뱾��(��������Ϣ)
	           double 			�� dInterest,������Ϣ
			   double			�� dInterestRate,�������ʻ���Ͷ�ʻر���
	Output	 : unsigned int *	�� puiInterestYear,���Ͷ������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
	Author   : Sunrier    
	Date     : 2010-09-23 16:07:05
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInterestYear(double dPrincipal,double dInterest,double dInterestRate,unsigned int *puiInterestYear);

/***********************************************************************************************
	FuncName : Tool_GetRoi
	FuncFunc : ��ȡROI
	Input	 : unsigned char *	�� pucInputData1    �����ԭʼ���
	           unsigned char *	�� pucInputData2    ����ĵ�ǰ���
	           unsigned char 	�� ucRoiFlag    	�����ROI��ʽ��־:0-�����ٷֱ� ��0-���ٷֱ�
	Output	 : unsigned char *	�� pucOutputData    ���ROI
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRoi(unsigned char *pucInputData1,unsigned char *pucInputData2,unsigned char ucRoiFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetExpWeightFactor
	FuncFunc : ��ȡָ��Ȩ��ϵ����������
	Input	 : WEIGHTFACTOR_PRM *	�� pWeightFactor    �����Ȩ��ϵ����Ϣ
	           unsigned int			�� uiWeightNum    	�����Ȩ������
	           double				�� dMinWeight    	�������СȨ��
	           long					�� lPrecision    	������ܱ���
	           unsigned char		�� ucPercentFactor  �����Ȩ��ϵ��������������:0-Ȩ��ϵ��Խ���������ԽС 
	                                                                               1-Ȩ��ϵ��Խ���������Խ��
	Output	 : WEIGHTFACTOR_PRM *	�� pWeightFactor    �����Ȩ��ϵ����Ϣ
	Return	 : unsigned char		�� �ɹ�,����TOOL_SUCCESS(0x00)
									�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetExpWeightFactor(WEIGHTFACTOR_PRM pWeightFactor[],unsigned int uiWeightNum,double dMinWeight,long lPrecision,unsigned char ucPercentFactor);

/***********************************************************************************************
	FuncName : Tool_GetWeightFactor
	FuncFunc : ��ȡ��׼Ȩ��ϵ����������
	Input	 : WEIGHTFACTOR_PRM *	�� pWeightFactor    �����Ȩ��ϵ����Ϣ
	           unsigned int			�� uiWeightNum    	�����Ȩ������
	           long					�� lPrecision    	������ܱ���
	           unsigned char		�� ucPercentFactor  �����Ȩ��ϵ��������������:0-Ȩ��ϵ��Խ���������ԽС 
	                                                                               1-Ȩ��ϵ��Խ���������Խ��
	Output	 : WEIGHTFACTOR_PRM *	�� pWeightFactor    �����Ȩ��ϵ����Ϣ
	Return	 : unsigned char		�� �ɹ�,����TOOL_SUCCESS(0x00)
									�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetWeightFactor(WEIGHTFACTOR_PRM pWeightFactor[],unsigned int uiWeightNum,long lPrecision,unsigned char ucPercentFactor);

/***********************************************************************************************
	FuncName : Tool_GetComputerName
	FuncFunc : ��ȡ��ǰ��������
	Input	 : None
	Output	 : unsigned char *	�� pucOutputData    �������Ϣ
	           unsigned int *	�� puiOutputDataLen �������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetComputerName(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetPriceTrend
	FuncFunc : ��ȡ����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPriceTrend( void );

/***********************************************************************************************
	FuncName : Tool_GetROI
	FuncFunc : ��ȡROI
	Input	 : unsigned char *	�� pucInputData1    �������Ϣ1
	           unsigned char *	�� pucInputData2    �������Ϣ2
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetROI(unsigned char *pucInputData1,unsigned char *pucInputData2);

/***********************************************************************************************
	FuncName : Tool_GetUserName
	FuncFunc : ��ȡ��ǰ�û���
	Input	 : None
	Output	 : unsigned char *	�� pucOutputData    �������Ϣ
	           unsigned int *	�� puiOutputDataLen �������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetUserName(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_IsTlv
	FuncFunc : �жϲ�����һ���ڴ��Ƿ���һ��TLV�ṹ�����TLV�ṹ��Ϣ
	Input	 : unsigned char *	�� pucInputData    �������Ϣ
	           int 			    �� iInputDataLen   �������Ϣ����
	           TLV *			�� pTlv    		   �����TLV�ṹ��Ϣ
	Output	 : int *			�� piOutputTlvLen  ���������TLV�ṹ����
	Return	 : unsigned char	�� ��һ��TLV�ṹ,����TOOL_SUCCESS(0x00)
								�� ����һ��TLV�ṹ,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsTlv(unsigned char* pucInputData,int iInputDataLen,TLV *pTlv,int *piOutputTlvLen);

/***********************************************************************************************
	FuncName : Tool_CheckTlv
	FuncFunc : �ж��Ƿ���һ��TLV�ṹ
	Input	 : unsigned char *	�� pucInputData    �������Ϣ
	           int 			    �� iInputDataLen   �������Ϣ����
	Output	 : None
	Return	 : unsigned char	�� ��һ��TLV�ṹ,����TOOL_SUCCESS(0x00)
								�� ����һ��TLV�ṹ,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTlv(unsigned char *pucInputData,int iInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetTlvLen
	FuncFunc : ��ȡTLV�ṹ���ݳ���
	Input	 : TLV *			�� pTlv    			�����TLV�ṹ��Ϣ
	Output	 : int *			�� piOutputTlvLen  	���������TLV�ṹ����
	Return	 : unsigned char	�� ��һ��TLV�ṹ,����TOOL_SUCCESS(0x00)
								�� ����һ��TLV�ṹ,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTlvLen(TLV *pTlv,int *piOutputTlvLen);

/***********************************************************************************************
	FuncName : Tool_TlvEncode
	FuncFunc : TLV����,��һ��TLV�ṹת�����һ��������
	Input	 : TLV *			�� pTlv    		   �����TLV�ṹ��Ϣ
	           int 				�� iTlvLen  	   �����TLV�ṹ��Ϣ����
	           int 				�� iMaxBufDataLen  ����������������󳤶�
	Output	 : unsigned char *	�� pucOutputData   �������Ϣ
	           int * 			�� piOutputDataLen �������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TlvEncode(TLV *pTlv,int iTlvLen,int iMaxBufDataLen,unsigned char* pucOutputData,int *piOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_TlvDecode
	FuncFunc : TLV����,��һ����������Ϣת��Ϊһ��TLV�ṹ
	Input	 : unsigned char *	�� pucInputData   �������Ϣ
			   int 				�� iInputDataLen  �������Ϣ����	           
	           int 				�� iMaxTlvCount   ��������TLV��Ŀ
	Output	 : TLV *			�� pTlv    		  �����TLV�ṹ��Ϣ
	           int * 			�� piTlvCount 	  �����TLV��Ŀ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_TlvDecode(unsigned char *pucInputData,int iInputDataLen,int iMaxTlvCount,TLV *pTlv,int *piTlvCount);

/***********************************************************************************************
	FuncName : Tool_GetTlvByTag
	FuncFunc : TLV����tag,���ݶ�Ӧ��TAG��ȡTLV��Ϣ
	Input	 : unsigned char *	�� pucInputData   �������Ϣ
			   int 				�� iInputDataLen  �������Ϣ����	           
	           int 				�� iInputTag   	  �����TAG
	Output	 : TLV *			�� pTlv    		  �����TLV�ṹ��Ϣ	           
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTlvByTag(unsigned char* pucInputData,int iInputDataLen,int iInputTag,TLV *pTlv);

/***********************************************************************************************
	FuncName : Tool_GetTagInfo
    FuncFunc : ��ȡEMV��ǩ��Ϣ
	Input	 : int				�� iInputTag�����ǩ
	Output	 : TLVTAG_PRM *		�� pTlvTag	���EMV��ǩ��Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTagInfo(int iInputTag,TLVTAG_PRM *pTlvTag);

/***********************************************************************************************
	FuncName : Tool_GetTagInfoEx
    FuncFunc : ��ȡEMV��ǩ��Ϣ
	Input	 : unsigned char *	�� pucInputTag	�����ǩ
	           int				�� iInputTagLen	�����ǩ�ĳ���
	Output	 : TLVTAG_PRM *		�� pTlvTag		���EMV��ǩ��Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetTagInfoEx(unsigned char *pucInputTag,int iInputTagLen,TLVTAG_PRM *pTlvTag);

/***********************************************************************************************
	FuncName : Tool_CheckTemplateTag
	FuncFunc : ����ǩ�Ƿ�Ϊģ���ǩ
	Input	 : unsigned char *	�� pucInputTag 	����ı�ǩ
	           unsigned char 	�� ucInputTagLen�����ǩ�ĳ���
	Output	 : None
	Return	 : unsigned char	�� ģ���ǩ,����TOOL_SUCCESS
					 			�� ��ģ���ǩ,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckTemplateTag(unsigned char *pucInputTag,unsigned char ucInputTagLen);

/***********************************************************************************************
	FuncName : Tool_GetDescpFromApduCode
    FuncFunc : ��ȡEMV APDUָ����ط�����������Ϣ
	Input	 : unsigned char *	�� pucInputApduCode 	����ķ�����
	Output	 : unsigned char *	�� pucOutputDescpInfo 	����ķ������Ӧ��������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromApduCode(unsigned char *pucInputApduCode,unsigned char *pucOutputDescpInfo);

/***********************************************************************************************
	FuncName : Tool_Des
	FuncFunc : �����ݽ���DES�ӽ��ܻ���3DES�ӽ��ܻ���3������ԿDES�ӽ���
	Input	 : unsigned char 	�� ucDesType		DES�ӽ����㷨���ͣ�	
													0��ʾDES��������(KeyΪ8���ֽ�)��1��ʾDES��������(KeyΪ8���ֽ�)��
													2��ʾ3DES��������(KeyΪ16���ֽ�)��3��ʾ3DES��������(KeyΪ16���ֽ�)��
													4��ʾ��������Կ��������(KeyΪ24���ֽ�)��5��ʾ��������Կ��������(KeyΪ24���ֽ�)
			   unsigned char *	�� pucInputData		����Ĵ����ܵ���������/����Ĵ����ܵ���������,����Ϊ8�ֽ�
			   unsigned char *	�� pucInputKey		������������ܵĴ�����Կ/������������ܵĴ�����Կ,�ֽ�������Ϊ8�ı���
	Output	 : unsigned char *	�� pucOutputData	����ļ��ܺ����������/����Ľ��ܺ����������,����Ϊ8�ֽ�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ���볤�ȱ���Ϊ8�ֽ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Des(unsigned char ucDesType,unsigned char *pucInputData,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DesEx
	FuncFunc : ���ַ������ݽ���DES�ӽ��ܻ���3DES�ӽ��ܻ���3������ԿDES�ӽ���
	Input	 : unsigned char 	�� ucDesType		DES�ӽ����㷨���ͣ�	
													0��ʾDES��������(KeyΪ8���ֽ�)��1��ʾDES��������(KeyΪ8���ֽ�)��
													2��ʾ3DES��������(KeyΪ16���ֽ�)��3��ʾ3DES��������(KeyΪ16���ֽ�)��
													4��ʾ��������Կ��������(KeyΪ24���ֽ�)��5��ʾ��������Կ��������(KeyΪ24���ֽ�)
			   unsigned char *	�� pucInputData		����Ĵ����ܵ���������/����Ĵ����ܵ���������
			   unsigned	int 	�� uiInputDataLen	�������ݳ���
			   unsigned char *	�� pucInputKey		������������ܵĴ�����Կ/������������ܵĴ�����Կ,�ֽ�������Ϊ8�ı���
	Output	 : unsigned char *	�� pucOutputData	����ļ��ܺ����������/����Ľ��ܺ����������(ͬ���볤��)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ����/������Ȳ��޶�Ϊ8�ı���
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DesEx(unsigned char ucDesType,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrDes
	FuncFunc : ���ַ������ݽ���DES�ӽ��ܻ���3DES�ӽ��ܻ���3������ԿDES�ӽ���
	Input	 : unsigned char 	�� ucDesType		DES�ӽ����㷨���ͣ�	
													0��ʾDES��������(KeyΪ16���ֽ�)��1��ʾDES��������(KeyΪ16���ֽ�)��
													2��ʾ3DES��������(KeyΪ32���ֽ�)��3��ʾ3DES��������(KeyΪ32���ֽ�)��
													4��ʾ��������Կ��������(KeyΪ48���ֽ�)��5��ʾ��������Կ��������(KeyΪ48���ֽ�)
			   unsigned char *	�� pucInputData		����Ĵ����ܵ���������/����Ĵ����ܵ���������,����Ϊ16�ֽ�
			   unsigned char *	�� pucInputKey		������������ܵĴ�����Կ/������������ܵĴ�����Կ,�ֽ�������Ϊ16/32/48
	Output	 : unsigned char *	�� pucOutputData	����ļ��ܺ����������/����Ľ��ܺ����������,����Ϊ16�ֽ�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ���볤�ȱ���Ϊ16�ֽ��ַ�������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrDes(unsigned char ucDesType,unsigned char *pucInputData,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrDesEx
	FuncFunc : ���ַ������ݽ���DES�ӽ��ܻ���3DES�ӽ��ܻ���3������ԿDES�ӽ���
	Input	 : unsigned char 	�� ucDesType		DES�ӽ����㷨���ͣ�	
													0��ʾDES��������(KeyΪ16���ֽ�)��1��ʾDES��������(KeyΪ16���ֽ�)��
													2��ʾ3DES��������(KeyΪ32���ֽ�)��3��ʾ3DES��������(KeyΪ32���ֽ�)��
													4��ʾ��������Կ��������(KeyΪ48���ֽ�)��5��ʾ��������Կ��������(KeyΪ48���ֽ�)
			   unsigned char *	�� pucInputData		����Ĵ����ܵ���������/����Ĵ����ܵ���������,����Ϊ8�ֽ�
			   unsigned	int 	�� uiInputDataLen	�������ݳ���
			   unsigned char *	�� pucInputKey		������������ܵĴ�����Կ/������������ܵĴ�����Կ,�ֽ�������Ϊ16�ı���
	Output	 : unsigned char *	�� pucOutputData	����ļ��ܺ����������/����Ľ��ܺ����������(ͬ���볤��)
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ���볤�Ȳ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_StrDesEx(unsigned char ucDesType,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Diversify
	FuncFunc : ��ɢ�㷨
	Input	 : unsigned char *	�� pucInputData		����Ĵ���ɢ��ԭʼ����
	           unsigned	int 	�� uiInputDataLen	��������ݳ���(�������ݳ��ȱ���Ϊ8��������,��Ϊ8λ,16λ,24λ,��Ӧ��ɢ����)
			   unsigned char *	�� pucInputKey		����ķ�ɢ��Կ
			   unsigned char 	�� ucInputKeyLen	�������Կ����(16λ)
			   unsigned char 	�� ucDiversifyTimes	����ķ�ɢ����:1-һ�Ρ�2-���Ρ�3-����
	Output	 : unsigned char *	�� pucOutputData	����ķ�ɢ����
	           unsigned int  *	�� puiOutputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Diversify(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputKey,unsigned char ucInputKeyLen,unsigned char ucDiversifyTimes,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_EcbCbc
	FuncFunc : DES�㷨ECB��CBCģʽ�����ݼӽ���
	Input	 : unsigned	char 	�� ucCryptType�ӽ������ͣ�0��ʾ�������ݡ�1��������0��ʾ��������
			   unsigned	char 	�� ucMode�ӽ���ģʽ��0��ʾECBģʽ��1��������0��ʾCBCģʽ
			   unsigned	char *	�� pucInputData��������(�������ݳ��ȱ���Ϊ8��������,������Ҫ�������)
			   unsigned	int 	�� uiInputDataLen�������ݳ���(�������ݳ��ȱ���Ϊ8��������)
			   unsigned	char *	�� pucInputKey������Կ(��Ϊ8�ֽ�/16�ֽ�/24�ֽ�)֧��3��Կ
			   unsigned	char 	�� ucInputKeyLen������Կ����(����Ϊ8�ֽ�/16�ֽ�/24�ֽ������е�һ��)
			   unsigned	char *	�� pucInputVector����icv����(CBCģʽ8�ֽ�)
	Output	 : unsigned char *	�� pucOutputData�������(ͬ�������ݳ���)
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : һ��Ĭ��ΪECBģʽ,�������ݲ���8�����������������Զ����
	History  : CBCģʽ8�ֽ�icv�����粻ָ��,Ĭ��Ϊ8�ֽڵ�0x00
	Other    : X9.52�㷨Ϊ24�ֽ���Կ
*************************************************************************************************/
EXPORT unsigned char Tool_EcbCbc(unsigned char ucCryptType,unsigned char ucMode,unsigned char *pucInputData,unsigned int uiInputDataLen,
			const unsigned char *pucInputKey,const unsigned char ucInputKeyLen,unsigned char *pucInputVector,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_StrEcbCbc
	FuncFunc : DES�㷨ECB��CBCģʽ���ַ������ݼӽ���
	Input	 : unsigned	char 	�� ucCryptType�ӽ������ͣ�0��ʾ�������ݡ�1��������0��ʾ��������
			   unsigned	char 	�� ucMode�ӽ���ģʽ��0��ʾECBģʽ��1��������0��ʾCBCģʽ
			   unsigned	char *	�� pucInputData��������(�������ݳ��ȱ���Ϊ16��������,������Ҫ�������)
			   unsigned	char *	�� pucInputKey������Կ(����Ϊ16λ,32λ,48λ�����е�һ��)֧��3��Կ
			   unsigned	char *	�� pucInputVector����icv����(CBCģʽ16λ)
	Output	 : unsigned char *	�� pucOutputData�������(16λ��������)
	Return	 : unsigned	char 	�� �ɹ�,����(0x00)
								�� ʧ��,����(0x01)
	Author	 : Sunrier
    Date     : 2016-12-05 19:00:55
    Descp    : һ��Ĭ��ΪECBģʽ,�������ݲ���16�����������������Զ����
	History  : CBCģʽ16λ�粻ָ��,Ĭ��Ϊ16�ֽڵ�"0000000000000000"
	Other    : X9.52�㷨Ϊ48λ��Կ
*************************************************************************************************/
EXPORT unsigned char Tool_StrEcbCbc(unsigned char ucCryptType,unsigned char ucMode,unsigned char *pucInputData,
			const unsigned char *pucInputKey,unsigned char *pucInputVector,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_EnDeFile
	FuncFunc : DES/3DES�㷨���ļ��ӽ���
	Input	 : unsigned	char *	�� pcuInputReadFullFileName,�����ļ���
	           unsigned	char *	�� pcuInputWriteFullFileName,����ļ���
	           unsigned char 	�� ucDesType,DES�ӽ����㷨���ͣ�	
											 0��ʾDES��������(KeyΪ8���ֽ�)��1��ʾDES��������(KeyΪ8���ֽ�)��
											 2��ʾ3DES��������(KeyΪ16���ֽ�)��3��ʾ3DES��������(KeyΪ16���ֽ�)��
											 4��ʾ��������Կ��������(KeyΪ24���ֽ�)��5��ʾ��������Կ��������(KeyΪ24���ֽ�)
			   unsigned	char *	�� pucInputKey������Կ(32λ)
	Output	 : None
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								   �����������,TOOL_PARAMERROR(0x04)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : �ļ���Ϊ����·��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_EnDeFile(unsigned char *pcuInputReadFullFileName,char *pcuInputWriteFullFileName,unsigned char ucDesType,unsigned char *pucInputKey);

/***********************************************************************************************
	FuncName : Tool_GeneraterRsaKey
	FuncFunc : ����RSA��˽Կ��
	Input	 : unsigned char 		�� ucProtoKeyBit	RSA�㷨��Կ����:ģ��:0-512λ 1-1024λ 2-2048λ
	           unsigned char 		�� ucPubExp			RSA�㷨ָ��:0-3 1-65537
	Output	 : RSAPUBLICKEY_PRM *	�� pPublicKey		RSA��Կ
	           RSAPRIVATEKEY_PRM *	�� pPrivateKey		RSA˽Կ
	Return	 : unsigned char		�� �ɹ�,����(0x00)
									-  ʧ��,����(0x01���0)
	Author	 : Sunrier
    Date     : 2016-12-05 19:00:55
    Descp    : �������һ��RSA��˽Կ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GeneraterRsaKey(unsigned char ucProtoKeyBit,unsigned char ucPubExp,RSAPUBLICKEY_PRM *pPublicKey,RSAPRIVATEKEY_PRM *pPrivateKey);

/***********************************************************************************************
	FuncName : Tool_RsaPublicKey
	FuncFunc : RSA��Կ��/����
	Input	 : unsigned char			�� ucRsaType			����RSA��Կ��/��������:0-RSA��Կ�������� 1-RSA��Կ��������
	           unsigned int				�� uiRSABit				����RSA��Կλ�� ȡֵΪ��ΧΪ512,1024,2048�е�һ��
	           unsigned char * 			�� pucInputExponent		����RSA��Կָ��
	           unsigned int 			�� uiInputExponentLen	����RSA��Կָ������
	           unsigned char * 			�� pucInputModulus		����RSA��Կģ��
	           unsigned int 			�� uiInputModulusLen	����RSA��Կģ������
	           unsigned char			�� ucPaddingFlag		����Ĺ�Կ���ݶ��뷽ʽ:0-RSA_NO_PADDING 1-RSA_PKCS1_PADDING
	           unsigned char * 			�� pucInputData			����ļ�/��������
	           unsigned char * 			�� uiInputDataLen		����ļ�/�������ݳ���
	Output	 : unsigned char *			�� pucOutputData		�����Կ��/���ܺ������
	           unsigned int *  			�� puiOutputDataLen		������ݳ���
	Return	 : unsigned char			�� �ɹ�,����(0x00)
										�� ʧ��,����(0x01���0)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : ��Կ��/��������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RsaPublicKey(unsigned char ucRsaType,unsigned int uiRSABit,unsigned char *pucInputExponent,unsigned int uiInputExponentLen,unsigned char *pucInputModulus,unsigned int uiInputModulusLen,unsigned char ucPaddingFlag,const unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_RsaPrivateKey
	FuncFunc : RSA˽Կ��/����
	Input	 : unsigned char			�� ucRsaType			����RSA˽Կ��/��������:0-RSA˽Կ�������� 1-RSA˽Կ��������
	           unsigned int				�� uiRSABit				����RSA˽Կλ�� ȡֵΪ��ΧΪ512,1024,2048�е�һ��
	           unsigned char * 			�� pucInputModulus		����RSA˽Կģ��
	           unsigned int 			�� uiInputModulusLen	����RSA˽Կģ������
	           unsigned char * 			�� pucInputP			����RSA˽Կ����P
	           unsigned int 			�� uiInputPLen			����RSA˽Կ����P����
	           unsigned char * 			�� pucInputQ			����RSA˽Կ����Q
	           unsigned int 			�� uiInputQLen			����RSA˽Կ����Q����
	           unsigned char * 			�� pucInputDp			����RSA˽Կ����Dp
	           unsigned int 			�� uiInputDpLen			����RSA˽Կ����Dp����
	           unsigned char * 			�� pucInputDq			����RSA˽Կ����Dq
	           unsigned int 			�� uiInputDqLen			����RSA˽Կ����Dq����
	           unsigned char * 			�� pucInputQinv			����RSA˽Կ����Qinv
	           unsigned int 			�� uiInputQinvLen		����RSA˽Կ����Qinv����
	           unsigned char			�� ucPaddingFlag		�����˽Կ���ݶ��뷽ʽ:0-RSA_NO_PADDING 1-RSA_PKCS1_PADDING
	           unsigned char * 			�� pucInputData			�����˽Կ��/��������
	           unsigned char * 			�� uiInputDataLen		�����˽Կ��/���ܵ����ݳ���
	Output	 : unsigned char *			�� pucOutputData		���˽Կ��/���ܺ������
	           unsigned int *  			�� puiOutputDataLen		���˽Կ��/���ܺ�����ݳ���
	Return	 : unsigned char			�� �ɹ�,����(0x00)
										�� ʧ��,����(0x01���0)
	Author	 : Sunrier
	Date     : 2016-12-05 19:00:55
	Descp    : ˽Կ��/��������
	History  : ˽Կ���ܼ�˽Կǩ��
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
	FuncFunc : ����Base64��MIME�ͱ���ÿ����ַ���
	Input	 : int			 	�� iMEMILen	����MIME�ͱ���ÿ����ַ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : MIME�Ѻø�ʽ,���ÿ��Ĭ�ϲ�����76�ַ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetMEMILineLen(int iMEMILen);

/***********************************************************************************************
	FuncName : Tool_Base64Encrypt
	FuncFunc : Base64��������
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   unsigned char 	�� ucCoderFlag		����������:
			   											0x00-�����ͱ���(Ĭ��)
			   											0x01-URL���ļ�����ȫ�ͱ���
			   											0x02-MIME�ͱ���
	Output	 : unsigned char *	�� pucOutputData	���������
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64����(֧��GB2312����)
	History  : ע��:�����ԭʼ�����������и��,�����ÿ���и����ݳ��ȱ���ÿ��Ϊ3�ı�������
	Other    : ��Tool_Base64Decrypt���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Encrypt(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Decrypt
	FuncFunc : Base64��������
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   unsigned char 	�� ucCoderFlag		����������:
			   											0x00-�����ͱ���(Ĭ��)
			                                       		0x01-URL���ļ�����ȫ�ͱ���
			                                       		0x02-MIME�ͱ���
	Output	 : unsigned char *	�� pucOutputData	���������
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64����(֧��GB2312����)
	History  : None
	Other    : ��Tool_Base64Encrypt���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Decrypt(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64UrlEncode
	FuncFunc : ʹ��URL base64���뷽��
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   int	*			�� piOuputDataLen	����ĳ������BUFFER�ռ�
	Output	 : unsigned char *	�� pucOutputData	���������
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �����ַ������ʽ:�ַ�%+HEX ��Ⱥ�=(%3D)
	History  : �ַ���a��-��z��,��A��-��Z��,��0��-��9��,'.','-','_','*'��'/'����������,ά��ԭֵ;
			   �ո�' '��ת��Ϊ�Ӻ�'+'
			   ����ÿ���ֽڶ�����ʾ��"%XY"�ĸ�ʽ,X��Y�ֱ����һ��ʮ������λ,����ΪUTF-8
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Base64UrlEncode(unsigned char* pucInputData,int iInputDataLen,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Encode
	FuncFunc : Base64����
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   unsigned char 	�� ucCoderFlag		����������:
			   											0x00-�����ͱ���(Ĭ��)
			   											0x01-URL���ļ�����ȫ�ͱ���
			   											0x02-MIME�ͱ���		
			   int *			�� piOuputDataLen	����ĳ������BUFFER�ռ�
	Output	 : unsigned char *	�� pucOutputData	���������
			   int *		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64����(֧��UTF-8����)
	History  : ע��:�����ԭʼ�����������и��,�����ÿ���и����ݳ��ȱ���ÿ��Ϊ3�ı�������
	Other    : ��Tool_Base64Decode���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Encode(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,
										unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Base64Decode
	FuncFunc : Base64����
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   unsigned char 	�� ucCoderFlag		����������:
			   											0x00-�����ͱ���(Ĭ��)
			   											0x01-URL���ļ�����ȫ�ͱ���
			   											0x02-MIME�ͱ���		
			   int *			�� piOuputDataLen	����ĳ������BUFFER�ռ�
	Output	 : unsigned char *	�� pucOutputData	���������
			   int *		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : Base64����(֧��UTF-8����)
	History  : None
	Other    : ��Tool_Base64Encode���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_Base64Decode(unsigned char *pucInputData,int iInputDataLen,unsigned char ucCoderFlag,
										unsigned char *pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UrlEncode
	FuncFunc : ʹ��URL���뷽��
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   unsigned char 	�� ucUrlCode		����URL����ķ�ʽ:0-encodeURI ��0-encodeURIComponent
			   int	*			�� piOuputDataLen	����ĳ������BUFFER�ռ�
	Output	 : unsigned char *	�� pucOutputData	���������
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ����ĸ�������Լ�/.����Ϊ�����ַ�����,��ʽ:�ַ�%+HEX ��Ⱥ�=(%3D)
	           �ַ���a��-��z��,��A��-��Z��,��0��-��9��,'.','-','_','*','!','~','(',')','''����������,ά��ԭֵ;
	           ���⺬��9������.-_*!~()'�����б���
			   ����ո�' '���ᱻת��Ϊ�Ӻ�'+'
			   ����ÿ���ֽڶ�����ʾ��"%XY"�ĸ�ʽ,X��Y�ֱ����һ��ʮ������λ,����ΪUTF-8
	History  : encodeURI()�����ڶ�����URL���б���,���⺬��10������:/?&@;,=+#�����б���
			   encodeURIComponent()��URL����ɲ��ֽ��и������,����:/?&@;,=+#�������ǿ��Խ��б���
	Other    : ��Tool_UrlDecode���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_UrlEncode(unsigned char* pucInputData,int iInputDataLen,unsigned char ucUrlCode,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UrlDecode
	FuncFunc : ʹ��URL���뷽��
	Input	 : unsigned char *	�� pucInputData		���������
			   int			 	�� iInputDataLen	��������ݳ���
			   int	*			�� piOuputDataLen	����ĳ������BUFFER�ռ�
	Output	 : unsigned char *	�� pucOutputData	���������
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� �����������,����TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ����ĸ�������Լ�/.����Ϊ�����ַ�����,��ʽ:�ַ�%+HEX ��Ⱥ�=(%3D)
	History  : None
	Other    : ��Tool_UrlEncode���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_UrlDecode(unsigned char* pucInputData,int iInputDataLen,unsigned char* pucOutputData,int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToUnicode
	FuncFunc : ���ı���ת��ΪUNICODE
	Input	 : unsigned char *	�� pucInputData		��������ı���
	           unsigned char 	�� ucConvFlag		����ת����ĸ�ʽ��־:
	                                                 	0-��д��ʽ(����\u��ͷ)  
	                                                	1-������ʽ(��\u��ͷ)
	Output	 : unsigned char *	�� pucOutputData	�����UNICODE����
			   int	*		 	�� piOuputDataLen	��������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������"�й�",ucConvFlag=0,���0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44,*piOuputDataLen = 8
    		   ������"��ΰ",ucConvFlag=0,���0x35 0x33 0x34 0x45 0x34 0x46 0x31 0x46,*piOuputDataLen = 8
    		   ������"���ı�",ucConvFlag=0,���0x37 0x33 0x38 0x42 0x36 0x35 0x38 0x37 0x35 0x31 0x37 0x35,*piOuputDataLen = 12
    		   ������"�й�123",ucConvFlag=0,���0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44 0x00 0x31 0x00 0x32 0x00 0x33,*piOuputDataLen = 20
    		   ������"�й�123",ucConvFlag=1,���0x5C 0x75 0x34 0x45 0x32 0x44 0x5C 0x75 0x35 0x36 0x46 0x44 0x5C 0x75 0x00 0x31 
    		   0x5C 0x75 0x00 0x32 0x5C 0x75 0x00 0x33,*piOuputDataLen = 30
    		   0x5C 0x75 0x34 0x45 0x32 0x44 0x5C 0x75 0x35 0x36 0x46 0x44 0x5C 0x75 0x00 0x31 0x5C 0x75 0x00 0x32 0x5C 0x75 0x00 0x33
    		   (���ַ���\u4E2D\u56FD\u0031\u0032\u0033)
	History  : ��ucConvFlag=0ʱ,�����ʽXXXX��ʽ;
			   ��ucConvFlag��Ϊ0ʱ,�����ʽ\uXXXX��ʽ;
	Other    : ��Tool_UnicodeToChinese���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToUnicode(unsigned char *pucInputData,unsigned char ucConvFlag,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_UnicodeToChinese
	FuncFunc : ��UNICODEת��Ϊ���ı���
	Input	 : unsigned char *	�� pucInputData,�����UNICODE����
	           unsigned char 	�� ucConvFlag  ,�������ݸ�ʽ��־:
	                                                 	0-��д��ʽ(����\u��ͷ)  
	                                                	1-������ʽ(��\u��ͷ)
	Output	 : unsigned char *	�� pucOutputData,���������GB2312����
			   int	*		 	�� piOuputDataLen,�������GB2312����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������0x34 0x45 0x32 0x44 0x35 0x36 0x46 0x44,���"�й�"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   ������0x35 0x33 0x34 0x45 0x34 0x46 0x31 0x46,���"��ΰ"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   ������0x37 0x33 0x38 0x42 0x36 0x35 0x38 0x37 0x35 0x31 0x37 0x35,���"���ı�"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : Unicodeֻ��һ�����ż�,��ֻ�涨�˷��ŵĶ����ƴ���,ȴû�й涨��������ƴ���Ӧ����δ洢;
	           �����һ�ֱ����ܽ����������еķ��Ŷ���������,
	           Ҳ����˵ÿһ�����Ŷ���һ����һ�޶��ı�����ô��������ͻ���ʧ,�����Unicode(ͳһ��);
	           ���������ռ�ǿ��Ҫ�����һ��ͳһ�ı��뷽ʽ,
	           UTF-8�����ڻ�������ʹ������һ��Unicode��ʵ�ַ�ʽ,
	           ����ʵ�ַ�ʽ������UTF-16(�ַ��������ֽڻ��ĸ��ֽڱ�ʾ)��
	           UTF-32(�ַ����ĸ��ֽڱ�ʾ)��Ȼ��Щ�ڻ����������������ǲ��ù���;
	           �ظ�һ��,����Ĺ�ϵ��UTF-8��Unicode��ʵ�ַ�ʽ֮һ;
      		   UTF-8����һ���ص�:����һ�ֱ䳤�ı��뷽ʽ,������ʹ��1~4���ֽڱ�ʾһ������,
      		   ���ݲ�ͬ�ķ��Ŷ��仯�ֽڳ���,UTF-8�ı������ܼ�,ֻ�����¶���:
			   1)���ڵ��ֽڵķ���,�ֽڵĵ�1λ��Ϊ0,����7λΪ������ŵ� Unicode��,
			     ��˶���Ӣ����ĸUTF-8�����ASCII������ͬ��;
			   2)����n�ֽڵķ���(n>1),��1���ֽڵ�ǰnλ����Ϊ1,��n + 1λ��Ϊ0,
			     �����ֽڵ�ǰ��λһ����Ϊ10,ʣ�µ�û���ἰ�Ķ�����λ,ȫ��Ϊ������ŵ�Unicode��;
			   ��ucConvFlag=0ʱ,�����ʽXXXX��ʽ;
			   ��ucConvFlag��Ϊ0ʱ,�����ʽ\uXXXX��ʽ;
	Other    : ��Tool_ChineseToUnicode���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_UnicodeToChinese(unsigned char *pucInputData,unsigned char ucConvFlag,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToGB2312
	FuncFunc : ���ı���ת��ΪGB2312ʮ������
	Input	 : unsigned char *	�� pucInputData,��������ı���
	Output	 : unsigned char *	�� pucOutputData,�����ʮ�������ַ���
			   int	*		 	�� piOuputDataLen,���ʮ�������ַ����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������"�й�",���0xD6 0xD0 0xB9 0xFA,*piOuputDataLen = 4
    		   ������"��ΰ",���0xBB 0xAA 0xCE 0xB0,*piOuputDataLen = 4
    		   ������"���ı�",���0xCD 0xF5 0xCE 0xC4 0xB1 0xF8,*piOuputDataLen = 6
	History  : Ϊʹ�����֧�ָ�������,ͨ��ʹ��0x80~0xFF��Χ��2���ֽ�����ʾ1���ַ�,
			   ����:����'��'�����Ĳ���ϵͳ��,ʹ��[0xD6,0xD0]�������ֽڴ洢;
����		   ��ͬ�Ĺ��Һ͵����ƶ��˲�ͬ�ı�׼,�ɴ˲�����GB2312,BIG5,JIS�ȸ��Եı����׼;
               ��Щʹ��2���ֽ�������һ���ַ��ĸ��ֺ���������뷽ʽ,��ΪANSI����;
               �ڼ�������ϵͳ��ANSI�������GB2312����,�����Ĳ���ϵͳ��ANSI�������JIS����;
	           1980���й������˵�һ�����ֱ����׼,Ҳ��GB2312,ȫ��<<��Ϣ�����ú��ֱ����ַ���.������>>,
			   ͨ�����GB("����"����ƴ������ĸ),����¼��6763�����õĺ��ֺ��ַ�,
			   �˱�׼�ڴ���5��ʵʩ,���������ճ�99%���ֵ�ʹ������;
	           GBK�ǹ��ұ�׼GB2312���������ݺ����GB2312�ı�׼;
	           GBK�����ֱ�������˫�ֽ�����ʾ��,�������С�Ӣ���ַ���ʹ��˫�ֽ�����ʾ,
	           Ϊ����������,�������λ���趨��1;
	           GBK����ȫ�������ַ�,�ǹ��ұ���,ͨ���Ա�UTF8��,����UTF8ռ�õ����ݿ��GBD��;
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToGB2312(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_ChineseToGB2312Str
	FuncFunc : ���ı���ת��ΪGB2312ʮ�������ַ���
	Input	 : unsigned char *	�� pucInputData,��������ı���
	Output	 : unsigned char *	�� pucOutputData,�����ʮ�������ַ���
			   int	*		 	�� piOuputDataLen,���ʮ�������ַ����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������"�й�",���0x44 0x36 0x44 0x30 0x42 0x39 0x46 0x41(D6D0B9FA),*piOuputDataLen = 8
    		   ������"��ΰ",���0x42 0x42 0x41 0x41 0x43 0x45 0x42 0x30(BBAACEB0),*piOuputDataLen = 8
    		   ������"���ı�",���0x43 0x44 0x46 0x35 0x43 0x45 0x43 0x34 0x42 0x31 0x46 0x38(CDF5CEC4B1F8),*piOuputDataLen = 12
	History  : Ϊʹ�����֧�ָ�������,ͨ��ʹ��0x80~0xFF��Χ��2���ֽ�����ʾ1���ַ�,
			   ����:����'��'�����Ĳ���ϵͳ��,ʹ��[0xD6,0xD0]�������ֽڴ洢;
����		   ��ͬ�Ĺ��Һ͵����ƶ��˲�ͬ�ı�׼,�ɴ˲�����GB2312,BIG5,JIS�ȸ��Եı����׼;
               ��Щʹ��2���ֽ�������һ���ַ��ĸ��ֺ���������뷽ʽ,��ΪANSI����;
               �ڼ�������ϵͳ��ANSI�������GB2312����,�����Ĳ���ϵͳ��ANSI�������JIS����;
	           1980���й������˵�һ�����ֱ����׼,Ҳ��GB2312,ȫ��<<��Ϣ�����ú��ֱ����ַ���.������>>,
			   ͨ�����GB("����"����ƴ������ĸ),����¼��6763�����õĺ��ֺ��ַ�,
			   �˱�׼�ڴ���5��ʵʩ,���������ճ�99%���ֵ�ʹ������;
	           GBK�ǹ��ұ�׼GB2312���������ݺ����GB2312�ı�׼;
	           GBK�����ֱ�������˫�ֽ�����ʾ��,�������С�Ӣ���ַ���ʹ��˫�ֽ�����ʾ,
	           Ϊ����������,�������λ���趨��1;
	           GBK����ȫ�������ַ�,�ǹ��ұ���,ͨ���Ա�UTF8��,����UTF8ռ�õ����ݿ��GBD��;
	Other    : ��Tool_GB2312StrToChinese���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_ChineseToGB2312Str(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GB2312StrToChinese
	FuncFunc : ��GB2312ת��Ϊ���ı���
	Input	 : unsigned char *	�� pucInputData,�����UNICODE����
	Output	 : unsigned char *	�� pucOutputData,���������GB2312����
			   int	*		 	�� piOuputDataLen,�������GB2312����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : �� ����0x44 0x36 0x44 0x30 0x42 0x39 0x46 0x41,���"�й�"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   �� ����0x42 0x42 0x41 0x41 0x43 0x45 0x42 0x30,���"��ΰ"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   �� ����0x43 0x44 0x46 0x35 0x43 0x45 0x43 0x34 0x42 0x31 0x46 0x38,���"���ı�"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : Ϊʹ�����֧�ָ�������,ͨ��ʹ��0x80~0xFF��Χ��2���ֽ�����ʾ1���ַ�,
			   ����:����'��'�����Ĳ���ϵͳ��,ʹ��[0xD6,0xD0]�������ֽڴ洢;
����		   ��ͬ�Ĺ��Һ͵����ƶ��˲�ͬ�ı�׼,�ɴ˲�����GB2312,BIG5,JIS�ȸ��Եı����׼;
               ��Щʹ��2���ֽ�������һ���ַ��ĸ��ֺ���������뷽ʽ,��ΪANSI����;
               �ڼ�������ϵͳ��ANSI�������GB2312����,�����Ĳ���ϵͳ��ANSI�������JIS����;
	           1980���й������˵�һ�����ֱ����׼,Ҳ��GB2312,ȫ��<<��Ϣ�����ú��ֱ����ַ���.������>>,
			   ͨ�����GB("����"����ƴ������ĸ),����¼��6763�����õĺ��ֺ��ַ�,
			   �˱�׼�ڴ���5��ʵʩ,���������ճ�99%���ֵ�ʹ������;
	           GBK�ǹ��ұ�׼GB2312���������ݺ����GB2312�ı�׼;
	           GBK�����ֱ�������˫�ֽ�����ʾ��,�������С�Ӣ���ַ���ʹ��˫�ֽ�����ʾ,
	           Ϊ����������,�������λ���趨��1;
	           GBK����ȫ�������ַ�,�ǹ��ұ���,ͨ���Ա�UTF8��,����UTF8ռ�õ����ݿ��GBD��;
	Other    : ��Tool_ChineseToGB2312Str���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_GB2312StrToChinese(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_Utf8ToGB2312
	FuncFunc : ��UTF8ת��ΪGB2312
	Input	 : unsigned char *	�� pucInputData,�����UTF8����
	Output	 : unsigned char *	�� pucOutputData,�����GB2312����
			   int	*		 	�� piOuputDataLen,���GB2312����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������0xE4 0xB8 0xAD 0xE5 0x9B 0xBD,���"�й�"(0xD6 0xD0 0xB9 0xFA),*piOuputDataLen = 4
    		   ������0xE5 0x8D 0x8E 0xE4 0xBC 0x9F,���"��ΰ"(0xBB 0xAA 0xCE 0xB0),*piOuputDataLen = 4
    		   ������0xE7 0x8E 0x8B 0xE6 0x96 0x87 0xE5 0x85 0xB5,���"���ı�"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),*piOuputDataLen = 6
	History  : Unicodeֻ��һ�����ż�,��ֻ�涨�˷��ŵĶ����ƴ���,ȴû�й涨��������ƴ���Ӧ����δ洢;
	           �����һ�ֱ����ܽ����������еķ��Ŷ���������,
	           Ҳ����˵ÿһ�����Ŷ���һ����һ�޶��ı�����ô��������ͻ���ʧ,����� Unicode(ͳһ��);
	           ���������ռ�ǿ��Ҫ�����һ��ͳһ�ı��뷽ʽ,
	           UTF-8�����ڻ�������ʹ������һ��Unicode��ʵ�ַ�ʽ,
	           ����ʵ�ַ�ʽ������UTF-16(�ַ��������ֽڻ��ĸ��ֽڱ�ʾ)��
	           UTF-32(�ַ����ĸ��ֽڱ�ʾ)��Ȼ��Щ�ڻ����������������ǲ��ù���;
	           �ظ�һ��,����Ĺ�ϵ��UTF-8��Unicode��ʵ�ַ�ʽ֮һ;
      		   UTF-8����һ���ص�:����һ�ֱ䳤�ı��뷽ʽ,������ʹ��1~4���ֽڱ�ʾһ������,
      		   ���ݲ�ͬ�ķ��Ŷ��仯�ֽڳ���,UTF-8�ı������ܼ�,ֻ�����¶���:
			   1)���ڵ��ֽڵķ���,�ֽڵĵ�1λ��Ϊ0,����7λΪ������ŵ� Unicode��,
			     ��˶���Ӣ����ĸUTF-8�����ASCII������ͬ��;
			   2)����n�ֽڵķ���(n>1),��1���ֽڵ�ǰnλ����Ϊ1,��n + 1λ��Ϊ0,
			     �����ֽڵ�ǰ��λһ����Ϊ10,ʣ�µ�û���ἰ�Ķ�����λ,ȫ��Ϊ������ŵ�Unicode��;
	Other    : ��Tool_GB2312ToUtf8���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_Utf8ToGB2312(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GB2312ToUtf8
	FuncFunc : ��GB2312ת��ΪUTF8
	Input	 : unsigned char *	�� pucInputData,�����GB2312����
	Output	 : unsigned char *	�� pucOutputData,�����UTF8����
			   int	*		 	�� piOuputDataLen,���UTF8����ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ������"�й�"(0xD6 0xD0 0xB9 0xFA),���0xE4 0xB8 0xAD 0xE5 0x9B 0xBD,*piOuputDataLen = 6
    		   ������"��ΰ"(0xBB 0xAA 0xCE 0xB0),���0xE5 0x8D 0x8E 0xE4 0xBC 0x9F,*piOuputDataLen = 6
    		   ������"���ı�"(0xCD 0xF5 0xCE 0xC4 0xB1 0xF8),���0xE7 0x8E 0x8B 0xE6 0x96 0x87 0xE5 0x85 0xB5,*piOuputDataLen = 9
	History  : Unicodeֻ��һ�����ż�,��ֻ�涨�˷��ŵĶ����ƴ���,ȴû�й涨��������ƴ���Ӧ����δ洢;
	           �����һ�ֱ����ܽ����������еķ��Ŷ���������,
	           Ҳ����˵ÿһ�����Ŷ���һ����һ�޶��ı�����ô��������ͻ���ʧ,����� Unicode(ͳһ��);
	           ���������ռ�ǿ��Ҫ�����һ��ͳһ�ı��뷽ʽ,
	           UTF-8�����ڻ�������ʹ������һ��Unicode��ʵ�ַ�ʽ,
	           ����ʵ�ַ�ʽ������UTF-16(�ַ��������ֽڻ��ĸ��ֽڱ�ʾ)��
	           UTF-32(�ַ����ĸ��ֽڱ�ʾ)��Ȼ��Щ�ڻ����������������ǲ��ù���;
	           �ظ�һ��,����Ĺ�ϵ��UTF-8��Unicode��ʵ�ַ�ʽ֮һ;
      		   UTF-8����һ���ص�:����һ�ֱ䳤�ı��뷽ʽ,������ʹ��1~4���ֽڱ�ʾһ������,
      		   ���ݲ�ͬ�ķ��Ŷ��仯�ֽڳ���,UTF-8�ı������ܼ�,ֻ�����¶���:
			   1)���ڵ��ֽڵķ���,�ֽڵĵ�1λ��Ϊ0,����7λΪ������ŵ� Unicode��,
			     ��˶���Ӣ����ĸUTF-8�����ASCII������ͬ��;
			   2)����n�ֽڵķ���(n>1),��1���ֽڵ�ǰnλ����Ϊ1,��n + 1λ��Ϊ0,
			     �����ֽڵ�ǰ��λһ����Ϊ10,ʣ�µ�û���ἰ�Ķ�����λ,ȫ��Ϊ������ŵ�Unicode��;
	Other    : ��Tool_Utf8ToGB2312���ʹ��
*************************************************************************************************/
EXPORT unsigned char Tool_GB2312ToUtf8(unsigned char *pucInputData,unsigned char *pucOutputData, int *piOuputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetCrc8
    FuncFunc : ����CRC8
	Input	 : unsigned char *	�� pucInputData		������Ҫ���������
			   unsigned int		�� uiInputDataLen	�������ݳ���
			   unsigned char 	�� ucCrc8Type		�����ϣ����:
			   												0x01-CRC8
			   												0x02-�Զ���ͻ���CRC8
	Output	 : unsigned char *	�� pucOutputData	���������:
															0x01-CRC8���1���ֽ�
															0x02-CRC8���1���ֽ�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc8(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char ucCrc8Type,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCrc16
    FuncFunc : ����CRC16
	Input	 : unsigned char *	�� pucInputData		������Ҫ���������
			   unsigned int		�� uiInputDataLen	�������ݳ���
			   unsigned char 	�� ucCrc16Type		����CRC����(�ο�ö������CRC_MODE):
			   												CRC16_IBM:CRC_MODE_CRC16_IBM
			   												CRC16_MAXIM:CRC_MODE_CRC16_MAXIM
			   												CRC16_USB:CRC_MODE_CRC16_USB
			   												CRC16_MODBUS:CRC_MODE_CRC16_MODBUS
			   												CRC16_CCITT:CRC_MODE_CRC16_CCITT
			   												CRC16_CCITT_FALSE:CRC_MODE_CRC16_CCITT_FALSE
			   												CRC16_X25:CRC_MODE_CRC16_X25
			   												CRC16_XMODEM:CRC_MODE_CRC16_XMODEM
			   												CRC16_DNP:CRC_MODE_CRC16_DNP 												
	Output	 : unsigned short *	�� pusOutputData	���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc16(unsigned char* pucInputData,unsigned int uiInputDataLen,unsigned char ucCrc16Type,unsigned short *pusOutputData);

/***********************************************************************************************
	FuncName : Tool_GetCrc
    FuncFunc : ����CRCѭ������У����
	Input	 : CRC_TYPE			�� crcType,����CRC���ͽṹ��Ϣ
	           const uint8_t *	�� buffer,������Ҫ���������
			   uint32_t			�� length,������Ҫ��������ݳ���
	Output	 : uint32_t*		�� puiOutputData,���CRCѭ������У����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ֧��CRC1-CRC32
	History  : ͨ��CRC�㷨
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCrc(CRC_TYPE crcType, unsigned char* pucInputData,unsigned int uiInputDataLen, uint32_t *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_GetGeneralCrc
    FuncFunc : ����ͨ��CRC�㷨ѭ������У����
	Input	 : unsigned char 	�� ucCrc16Type		����CRC����(�ο�ö������CRC_MODE):
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
	           unsigned char *	�� pucInputData		������Ҫ���������
			   unsigned int		�� uiInputDataLen	�������ݳ���			   
	Output	 : uint32_t*		�� puiOutputData,���CRCѭ������У����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0x00)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ֧��CRC4/CRC5/CRC6/CRC7/CRC8/CRC16/CRC32
	History  : ���õ�CRC�㷨
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetGeneralCrc(unsigned char ucCrc16Type,unsigned char* pucInputData,unsigned int uiInputDataLen,uint32_t *puiOutputData);

/***********************************************************************************************
	FuncName : Tool_GetDescpFromCrcMode
	FuncFunc : ͨ��CRCģ�����ͻ�ȡ�����Ϣ����
	Input	 : unsigned char	�� ucCrcMode 	 �����CRCģ������
	Output	 : unsigned char *	�� pucOutputData ��������CRCģ�����Ͷ�Ӧ������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �����������,����TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ȡCRCģ�����������Ϣ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromCrcMode(unsigned char ucCrcMode,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_Hash
    FuncFunc : �����ϣֵ
	Input	 : unsigned char *	�� pucInputData		������Ҫ���������
			   int				�� iInputDataLen	�������ݳ���
			   unsigned char 	�� ucHashType		�����ϣ����:
			   												0x01-MD5 
			   												0x02-SHA1 
			   												0x03-SHA224 
			   												0x04-SHA256
			   												0x05-SHA384 
			   												0x06-SHA512
	Output	 : unsigned char *	�� pucOutputData	���������:
															0x01-MD5���16���ֽ� 
															0x02-SHA1���20���ֽ� 
															0x03-SHA224���28���ֽ� 
															0x04-SHA256���32���ֽ�
															0x05-SHA384���48���ֽ� 
															0x06-SHA512���64���ֽ�
	           unsigned int *	�� puiOutputDataLen	�������������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Hash(unsigned char* pucInputData,int iInputDataLen,unsigned char ucHashType,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FileHash
    FuncFunc : �����ļ���ϣֵ
	Input	 : unsigned char *	�� pucFileName				������м�����ļ���(����·��)
	           unsigned char 	�� ucHashType				�����ϣ����:
	                                                        0x01-MD5 
	                                                        0x02-SHA1 
	                                                        0x03-SHA224 
	                                                        0x04-SHA256
	                                                        0x05-SHA384
	                                                        0x06-SHA512
	           unsigned char 	�� ucTrimFileTailHashFlag	�����ļ�ĩβ��ϣֵ�Ƿ��޳�:
	                                      					0x00-���޳�
	                                      					0x01-���޳�������׷�ӵ��ļ�β
	                                                        0x02-�޳����� 
	                                                        0x03-�޳����㲢�Ƚ� 
	                                                        ����-�޳�����
	Output	 : unsigned char *	�� pucOutputData			���������:
	                                                        0x01-MD5���16���ֽ� 
	                                                        0x02-SHA1���20���ֽ� 
	                                                        0x03-SHA224���28���ֽ� 
	                                                        0x04-SHA256���32���ֽ�
	                                                        0x05-SHA384���48���ֽ� 
	                                                        0x06-SHA512���64���ֽ�
	           unsigned int *	�� puiOutputDataLen			�������������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ļ���
	History  : ����ļ�ĩβ���й�ϣֵ,����ʱ����ͨ������ucTrimFileTailHashFlag����
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FileHash(unsigned char *pucFileName,unsigned char ucHashType,unsigned char ucTrimFileTailHashFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FilePointHash
    FuncFunc : �����ļ���ϣֵ
	Input	 : FILE *			�� fpHash					�������Ĺ�ϣ�ļ�ָ��
	           unsigned char 	�� ucHashType				�����ϣ����:
	                                                        0x01-MD5 
	                                                        0x02-SHA1 
	                                                        0x03-SHA224 
	                                                        0x04-SHA256
	                                                        0x05-SHA384
	                                                        0x06-SHA512
	           unsigned char 	�� ucTrimFileTailHashFlag	�����ļ�ĩβ��ϣֵ�Ƿ��޳�:
	           												0x00-���޳�
	           												0x01-���޳�������׷�ӵ��ļ�β
	                                                        0x02-�޳����� 
	                                                        0x03-�޳����㲢�Ƚ� 
	                                                        ����-�޳�����
	Output	 : unsigned char *	�� pucOutputData			���������:
	                                                        0x01-MD5���16���ֽ� 
	                                                        0x02-SHA1���20���ֽ� 
	                                                        0x03-SHA224���28���ֽ� 
	                                                        0x04-SHA256���32���ֽ�
	                                                        0x05-SHA384���48���ֽ� 
	                                                        0x06-SHA512���64���ֽ�
	           unsigned int *	�� puiOutputDataLen			�������������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,������Ӧ������Ϣ(��0)
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ļ�ָ��
	History  : ����ļ�ĩβ���й�ϣֵ,����ʱ����ͨ������ucTrimFileTailHashFlag����
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FilePointHash(FILE *fpHash,unsigned char ucHashType,unsigned char ucTrimFileTailHashFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CodeConvert
	FuncFunc : ANSI��UTF-8�໥ת��
	Input	 : unsigned int		�� uiInputCode		����Ĵ���
			   void * 			�� pInputData		���������
			   unsigned int		�� uiOuputCode		����Ĵ���
	Output	 : void * 			�� pOutputData		���������
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-07-21 19:10:22
	Descp    : ��ANSIתUTF-8,uiInputCode=CP_ACP,uiOuputCode=CP_UTF8;UTF-8תANSI,uiInputCode=CP_UTF8,uiOuputCode=CP_ACP
	History  : None
	Other    : UTF-8��GB2312
*************************************************************************************************/
EXPORT unsigned char Tool_CodeConvert(unsigned int uiInputCode,void* pInputData,unsigned int uiOuputCode,void* pOutputData);

/***********************************************************************************************
	FuncName : Tool_CheckConfigSectionName
	FuncFunc : ��������ļ������Ƿ����
	Input	 : unsigned char *	�� pucInputFileName		�����ļ���
			   unsigned char *	�� pucInputSectionName	����Ľ���
	Output	 : None
	Return	 : unsigned char	�� ����,����TOOL_SUCCESS(0x00)
					 			�� ������,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckConfigSectionName(unsigned char *pucInputFileName,unsigned char *pucInputSectionName);

/***********************************************************************************************
	FuncName : Tool_GetKey
	FuncFunc : ��ȡ�����ļ���ֵ
	Input	 : unsigned char *	�� pucInputFileName		�����ļ���
			   unsigned char *	�� pucInputKeyName		�������
	Output	 : unsigned char *	�� pucOutputKeyValue	����ļ�ֵ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : �����ִ�Сд
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetKey(unsigned char *pucInputFileName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetKeyValue
	FuncFunc : ��ȡ�����ļ���ֵ
	Input	 : unsigned char *	�� pucInputFileName		�����ļ�ָ����
			   unsigned char *	�� pucInputKeyName		�������
	Output	 : unsigned char *	�� pucOutputKeyValue	����ļ�ֵ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : ���ִ�Сд
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetKeyValue(unsigned char *pucInputFileName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetConfigStringValue
	FuncFunc : ��ȡ�����ļ����ַ�����ֵ
	Input	 : unsigned char *	�� pucInputFileName		�����ļ���
			   unsigned char *	�� pucInputSectionName	����Ľ���
			   unsigned char *	�� pucInputKeyName		�������
	Output	 : unsigned char *	�� pucOutputKeyValue	����ļ�ֵ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetConfigStringValue(unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned char *pOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_GetConfigIntValue
	FuncFunc : ��ȡ�����ļ������͵�ֵ
	Input	 : unsigned char *	�� pucInputFileName		�����ļ���
			   unsigned char *	�� pucInputSectionName	����Ľ���
			   unsigned char *	�� pucInputKeyName		�������
	Output	 : unsigned long *	�� pulOutputKeyValue	����ļ�ֵ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2011-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetConfigIntValue(unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned long *pulOutputKeyValue);

/***********************************************************************************************
	FuncName : Tool_SetCfgFile
	FuncFunc : ����Ĭ�����ò����ļ���
	Input	 : unsigned char *	�� pucInputCfgFileName,�������ò����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-07 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetCfgFile(unsigned char *pucInputCfgFileName);

/***********************************************************************************************
	FuncName : Tool_GetCfgFile
	FuncFunc : ��ȡĬ�����ò����ļ���
	Input	 : None
	Output	 : unsigned char *	�� pucOutputCfgFileName,���Ĭ�����ò����ļ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2016-12-07 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCfgFile(unsigned char *pucOutputCfgFileName);

/***********************************************************************************************
	FuncName : Tool_GetCurrPathFile
	FuncFunc : ��ȡ��ǰĿ¼ȫ·��
	Input	 : unsigned int		�� uiMaxLen,��ǰĿ¼�ľ���·����ַ���ȴ�С
	Output	 : unsigned char *	�� pucOuputFilePathName,����ļ���ȫ·��
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·��(ȫ·��,������Ӧ������),���ݷ�ʽ���еľ���·��(������Ӧ������)
	History  : uiMaxLen̫С�޷��������·����ַ,����NULL 
	Other    : ��Ӧ��ʵ��·��Ϊ:G:\App\Test\Release\Test.exe,
	             Ӧ�ÿ�ݷ�ʽʵ��·��Ϊ:C:\Users\Administrator\Desktop\Test.exe,
	             ִ�з���:C:\Users\Administrator\Desktop
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrPathFile(unsigned int uiMaxLen,unsigned char *pucOuputFilePathName);

/***********************************************************************************************
	FuncName : Tool_GetCurrAppPathFile
	FuncFunc : ��ȡ��ǰӦ��ִ�е�Ŀ¼ȫ·��(����Ӧ������)
	Input	 : unsigned int		�� uiMaxLen,��ǰĿ¼�ľ���·����ַ���ȴ�С
	Output	 : unsigned char *	�� pucOuputAppPathName,����ļ���ȫ·��
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·������Ӧ������(ȫ·��)
	History  : uiMaxLen̫С�޷��������·����ַ
	Other    : ��Ӧ��ʵ��·��Ϊ:G:\App\Test\Release\Test.exe,
	             Ӧ�ÿ�ݷ�ʽʵ��·��Ϊ:C:\Users\Administrator\Desktop\Test.exe,
	             ִ�з���:G:\App\Test\Release\Test.exe
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrAppPathFile(unsigned int uiMaxLen,unsigned char *pucOuputAppPathName);

/***********************************************************************************************
	FuncName : Tool_GetCurrAppPath
	FuncFunc : ��ȡ��ǰӦ��ִ�е�Ŀ¼ȫ·��(������Ӧ������)
	Input	 : unsigned int		�� uiMaxLen,��ǰĿ¼�ľ���·����ַ���ȴ�С
	Output	 : unsigned char *	�� pucOuputAppPath,����ļ���ȫ·��
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·��������Ӧ������(ȫ·��)
	History  : uiMaxLen̫С�޷��������·����ַ
	Other    : ��Ӧ��ʵ��·��Ϊ:G:\App\Test\Release\Test.exe,
	             Ӧ�ÿ�ݷ�ʽʵ��·��Ϊ:C:\Users\Administrator\Desktop\Test.exe,
	             ִ�з���:G:\App\Test\Release\
*************************************************************************************************/
EXPORT unsigned char Tool_GetCurrAppPath(unsigned int uiMaxLen,unsigned char *pucOuputAppPath);

/***********************************************************************************************
	FuncName : Tool_GetPathName
	FuncFunc : ��ȡһ��ȫ·���ļ�����Ŀ¼·��
	Input	 : unsigned char *	�� pucInputFullPathName		�����ȡ��ȫ·���ļ���
	Output	 : unsigned char *	�� pucOuputFilePathName		����ļ���·��
	Return	 : unsigned char	�� ���ڷ��سɹ�,����TOOL_SUCCESS(0x00)
								�� �����ڷ���ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPathName(unsigned char *pucInputFullPathName,unsigned char *pucOuputFilePathName);

/***********************************************************************************************
	FuncName : Tool_GetFileName
	FuncFunc : ��ȡһ��ȫ·���ļ����ļ���
	Input	 : unsigned char *	�� pucInputFullPathName		�����ȡ��ȫ·���ļ���
	Output	 : unsigned char *	�� pucOutputFileName		����ļ���
	Return	 : unsigned char	�� ���ڷ��سɹ�,����TOOL_SUCCESS(0x00)
								�� ����·�����󷵻�ʧ��,����TOOL_FAILURE(0x01)
								�� �������ļ���,����(0x04)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileName(unsigned char *pucInputFullPathName,unsigned char *pucOutputFileName);

/***********************************************************************************************
	FuncName : Tool_GetFileNamePrefix
	FuncFunc : ��ȡ�ļ�����ǰ׺
	Input	 : unsigned char *	�� pucInputFileName			�����ļ���
	           unsigned char 	�� ucSuffixFlag				�����Ƿ�ָ���ļ����ĺ�׺:
	                                                        0-�����Һ�׺�Ե�һ��.֮ǰΪǰ׺
	                                                        1-�����Һ�׺�Ե�һ��.֮ǰΪǰ׺
	                                                        2-�����Һ�׺�����һ��.֮ǰΪǰ׺
	                                                        3-���Һ�׺,��ƥ��ʱ�Ե�һ��.֮ǰΪǰ׺
	                                                        4-���Һ�׺,��ƥ��ʱ�����һ��.֮ǰΪǰ׺
	                                                        5-���Һ�׺�ұ���ƥ��
	           unsigned char *	�� pucInputSuffix			����ָ�����ļ�����׺
	Output	 : unsigned char *	�� pucOutputPrefix			����ļ�����ǰ׺
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ��������,����TOOL_FAILURE(0x01)
								�� �����������,����TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·�������·��,�˺���������ļ��Ƿ��Ѿ�����
	History  : ��:
	           ��1:test.txt ����test
	           ��2:d:\Demo\test.txt ����test
	           ��3:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=5 pucInputSuffix=".txt" ����X.20131201.DATA
	           ��4:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=1 ����X
	           ��5:d:\Demo\X.20131201.DATA.txt ucSuffixFlag=2 ����X.20131201.DATA
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNamePrefix(unsigned char *pucInputFileName,unsigned char ucSuffixFlag,unsigned char *pucInputSuffix,unsigned char *pucOutputPrefix);

/***********************************************************************************************
	FuncName : Tool_GetFileNameSuffix
	FuncFunc : ��ȡ�ļ����ĺ�׺
	Input	 : unsigned char *	�� pucInputFileName			�����ļ���
	Output	 : unsigned char *	�� pucOutputSuffix			����ļ����ĺ�׺
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ��������,����TOOL_FAILURE(0x01)
								�� �����������,����TOOL_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ����·�������·��,�˺���������ļ��Ƿ��Ѿ�����
	History  : ��:
	           ��1:test.txt ����.txt
	           ��2:d:\Demo\test.txt ����.txt
	           ��3:d:\Demo\X.20131201.DATA.txt ����.txt
	           ��4:d:\Demo\X.20131201.DATA ����.DATA
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNameSuffix(unsigned char *pucInputFileName,unsigned char *pucOutputSuffix);

/***********************************************************************************************
	FuncName : Tool_CheckPathFile
	FuncFunc : ���Ŀ¼
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
	Output	 : None
	Return	 : unsigned char	�� ���ڷ��سɹ�,����TOOL_SUCCESS(0x00)
								�� �����ڷ���ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ���Ŀ¼�Ƿ����,��������ڲ��ᴴ��Ŀ¼
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckPathFile(unsigned char *pucInputFilePathName);

/***********************************************************************************************
	FuncName : Tool_CreatePathFile
	FuncFunc : ��鲢����Ŀ¼
	Input	 : unsigned char *	�� pucInputFilePathName		���봴�����ļ�·��
	           unsigned char 	�� ucParentDirFlag			�����Ƿ�֧�ִ�����Ŀ¼ 0-��֧�� 1-֧��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_CREATEDIRFAIL(0x07)����Ŀ¼ʧ��
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ���Ŀ¼�Ƿ����,��������ھʹ���Ŀ¼
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CreatePathFile(unsigned char *pucInputFilePathName,unsigned char ucParentDirFlag);

/***********************************************************************************************
	FuncName : Tool_CreateFile
	FuncFunc : �����ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	���봴�����ļ�·��
		       unsigned char *	�� pucInputFileName		���봴�����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ����ļ��Ƿ����,��������ھʹ����ļ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CreateFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_IsExistFile
	FuncFunc : ����ļ��Ƿ����
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char    �� ucNullFlag  			�����ļ������Ƿ����Ϊ�� 0-������Ϊ�� 1���0-����Ϊ��  
	Output	 : None
	Return	 : unsigned char	�� �ļ�����,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ�Ŀ¼������,����TOOL_DIRNOTEXIST(0x09)
					 			�� �ļ�������,����TOOL_FILENOTEXIST(0x08)
					 			�� �ļ����ڵ�����Ϊ��,����TOOL_FILENULL(0x1A)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsExistFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_IsExistFileEx
	FuncFunc : ����ļ��Ƿ����
	Input	 : unsigned char *	�� pucInputFullFileName	���뱣���ȫ·���ļ���
		       unsigned char    �� ucNullFlag  			�����ļ������Ƿ����Ϊ�� 0-������Ϊ�� 1���0-����Ϊ��  
	Output	 : None
	Return	 : unsigned char	�� �ļ�����,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ�Ŀ¼������,����TOOL_DIRNOTEXIST(0x09)
					 			�� �ļ�������,����TOOL_FILENOTEXIST(0x08)
					 			�� �ļ����ڵ�����Ϊ��,����TOOL_FILENULL(0x1A)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_IsExistFileEx(unsigned char *pucInputFullFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : Tool_ReadHeadLine
	FuncFunc : ��ȡ�ļ�������Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
			   unsigned char 	�� uiMinLen					�����ȡ����С����
			   unsigned char 	�� uiMaxLen					�����ȡ����󳤶�
	Output	 : unsigned char *	�� pucOutputData			����ļ�������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,���ط�TOOL_SUCCESS
										��������TOOL_PARAMERROR(0x04)
										��ȡʧ��TOOL_FAILURE(0x01)
										���ļ�ʧ��TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ��Ҫ��ȡ��һ����Ϣ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadHeadLine(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadLine
	FuncFunc : ��ȡ�ļ�ĳ����Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
			   unsigned char 	�� uiMinLen					�����ȡ����С����
			   unsigned char 	�� uiMaxLen					�����ȡ����󳤶�
			   unsigned long 	�� ulLine					�����ȡ��ĳ����Ϣ
			   unsigned char 	�� ucSizeFlag				�����Ƿ��¼�Ѿ���ȡ���ļ���С:0-�� 1-��
	Output	 : unsigned long *	�� pulOutputSize			����ļ��Ѿ���ȡ���ļ���С(�ֽ�)
	           unsigned char * 	�� pucEofFlag				����ļ�������־
			   unsigned char *	�� pucOutputData			����ļ�ĳ����Ϣ
			   unsigned long *	�� pulOutputDataLen			����ļ�ĳ����Ϣ�ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,���ط�TOOL_SUCCESS
										��������TOOL_PARAMERROR(0x04)
										��ȡʧ��TOOL_FAILURE(0x01)
										���ļ�ʧ��TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : ��ȡĳһ����Ϣ(Ĭ�Ͽ�ʼ��Ϊ1)
	History  : ��¼�Ѿ���ȡ���ļ���С(�ֽ�)
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadLine(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned long ulLine,unsigned char ucSizeFlag,unsigned long *pulOutputSize,unsigned char *pucEofFlag,unsigned char *pucOutputData,unsigned long *pulOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_ReadFile
	FuncFunc : ��ȡ�ļ���Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
			   unsigned long 	�� ulSize					�����ȡ�Ĵ�С
	Output	 : unsigned char *	�� pucOutputData			�����ȡ���ļ��е���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,���ط�TOOL_SUCCESS
										��������TOOL_PARAMERROR(0x04)
										��ȡʧ��TOOL_FAILURE(0x01)
										���ļ�ʧ��TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �ļ��ܴ�С����ΪulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadFileEx
	FuncFunc : ��ȡ�ļ���Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
			   unsigned long 	�� ulOutputDataLen			�����ȡ�Ĵ�С
	Output	 : unsigned char *	�� pucOutputData			�����ȡ���ļ��е���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,���ط�TOOL_SUCCESS
										��������TOOL_PARAMERROR(0x04)
										��ȡʧ��TOOL_FAILURE(0x01)
										���ļ�ʧ��TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : �ļ��ܴ�С���Դ���ulOutputDataLen
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFileEx(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,
								unsigned long ulOutputDataLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_ReadFileAllInfor
	FuncFunc : ��ȡ�ļ�������Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
	Output	 : unsigned char *	�� pucOutputData			�����ȡ���ļ��е���Ϣ
	           unsigned long *	�� pulOutputLen				�����ȡ�ĳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,���ط�TOOL_SUCCESS(0x01��������0)
										���ļ�ʧ��TOOL_OPENFILEFAIL(0x05)
										�ļ�����Ϊ��TOOL_FILENULL(0x15)
										�����ڴ�ʧ��TOOL_GETMEMORYFAIL(0x14)
										��ȡ�ļ�ʧ��TOOL_READFILEFAIL(0x0C)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadFileAllInfor(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucOutputData,unsigned long *pulOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetFileSize
	FuncFunc : ��ȡ�ļ��ֽ���
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
	Output	 : unsigned long *	�� pulOutputLen				�����ļ��Ĵ�С
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
    Date     : 2013-02-21 19:00:55
    Descp    : �ֽ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileSize(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long *pulOutputLen);

/***********************************************************************************************
	FuncName : Tool_GetFileNum
	FuncFunc : ��ȡ�ļ���¼��
	Input	 : unsigned char *	�� pucInputFilePathName		�����ȡ���ļ�·��
			   unsigned char *	�� pucInputFileName			�����ȡ���ļ�����
			   unsigned char 	�� ucFirstLineFlag			�����һ���Ƿ�֧��:0-��֧�� 1-֧��
			   unsigned char *	�� pucFristData				�����һ�в�֧�����������
	Output	 : unsigned long *	�� pulOutputNum				�����ļ��ļ�¼��
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
    Date     : 2013-02-21 19:00:55
    Descp    : ÿ�г���һ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileNum(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFirstLineFlag,unsigned char *pucFristData,unsigned long *pulOutputNum);

/***********************************************************************************************
	FuncName : Tool_RunApp
	FuncFunc : ִ��Ӧ��
	Input	 : unsigned char *	�� pucInputFilePath	����Ӧ�õ��ļ�·��
			   unsigned char *	�� pucInputApp		����ִ�е�Ӧ��
	           unsigned char *	�� pucInputParam	����ִ�еĲ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RunApp(unsigned char *pucInputFilePath,unsigned char *pucInputApp,unsigned char *pucInputParam);

/***********************************************************************************************
	FuncName : Tool_RunSelf
	FuncFunc : ����ָ����Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
    Date     : 2014-04-21 19:20:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RunSelf( void );

/***********************************************************************************************
	FuncName : Tool_SetAttribFile
	FuncFunc : �޸�ָ���ļ����ļ���(�������ļ������ļ���)����
	Input	 : unsigned char *	�� pucSourFile	����Դ�ļ���(����·��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : ���ֻ��,�浵,ϵͳ,��������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_SetAttribFile(unsigned char *pucSourFile);

/***********************************************************************************************
	FuncName : Tool_GetDirToListFile
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ�������
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	           unsigned char *	�� pucInputListFilePath		�����б��ļ������·��
	           unsigned char *	�� pucInputListFileName		�����б��ļ�������ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ֻ��ȡĿ¼��(���ļ�����)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDirToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetFileToListFile
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ�����
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	           unsigned char *	�� pucInputListFilePath		�����б��ļ������·��
	           unsigned char *	�� pucInputListFileName		�����б��ļ�������ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ֻ��ȡ�ļ���(������Ŀ¼,���ļ�����)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetInfoToListFile
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ����ļ�������
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	           unsigned char *	�� pucInputListFilePath		�����б��ļ������·��
	           unsigned char *	�� pucInputListFileName		�����б��ļ�������ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ����Ŀ¼��(���ļ�����)���ļ���
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInfoToListFile(unsigned char *pucInputFilePathName,unsigned char *pucInputListFilePath,unsigned char *pucInputListFileName);

/***********************************************************************************************
	FuncName : Tool_GetDirListToBuf
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ�������
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	Output	 : unsigned char *	�� pucOutputData			����ļ�Ŀ¼���б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� �ļ�������,����TOOL_FILENOTEXIST(0x08)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ֻ��ȡĿ¼��(���ļ�����)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDirListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetFileListToBuf
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ�����
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	Output	 : unsigned char *	�� pucOutputData			����ļ��б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ֻ��ȡ�ļ���(������Ŀ¼,���ļ�����)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetFileListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetInfoListToBuf
	FuncFunc : ��ȡĳ��Ŀ¼�����е��ļ����ļ�������
	Input	 : unsigned char *	�� pucInputFilePathName		������Ҫ�г����ļ�Ŀ¼·��
	Output	 : unsigned char *	�� pucOutputData			����ļ��б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� �ļ�������,����TOOL_FILENOTEXIST(0x08)
	Author	 : Sunrier
	Date     : 2010-09-23 19:10:22
	Descp    : ����Ŀ¼��(���ļ�����)���ļ���
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetInfoListToBuf(unsigned char *pucInputFilePathName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_CopyFile
	FuncFunc : ��ָ��Ŀ¼�µ��ļ���������һ��Ŀ¼��
	Input	 : unsigned char *	�� pucInputSourceFilePath		����Դ�ļ���Ŀ¼·��
	           unsigned char *	�� pucInputSourceFileName		����Դ�ļ��ĵ��ļ���
	           unsigned char *	�� pucInputCopyFilePath			���뿽�����Ŀ¼·��
	           unsigned char *	�� pucInputCopyFileName			���뿽������ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE���TOOL_SUCCESS(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : ֻ����Ŀ¼�µ��ļ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CopyFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputCopyFilePath,unsigned char *pucInputCopyFileName);

/***********************************************************************************************
	FuncName : Tool_CopyFiles
	FuncFunc : ��ָ��Ŀ¼�µ�����Ŀ¼���ļ���������һ��Ŀ¼��
	Input	 : unsigned char *	�� pucInputSourceFilePath		����Դ�ļ���Ŀ¼·��
	           unsigned char *	�� pucInputCopyFilePath			���뿽������Ŀ��Ŀ¼·��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE���TOOL_SUCCESS(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : ֻ����Ŀ¼�µ���Ŀ¼���ļ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CopyFiles(unsigned char *pucInputSourceFilePath,unsigned char *pucInputCopyFilePath);

/***********************************************************************************************
	FuncName : Tool_RenameFile
	FuncFunc : �����ļ���
	Input	 : unsigned char *	�� pucInputSourceFilePath		����Դ�ļ���Ŀ¼·��
	           unsigned char *	�� pucInputSourceFileName		����Դ�ļ��ĵ��ļ���
	           unsigned char *	�� pucInputRenameFilePath		������������Ŀ¼·��
	           unsigned char *	�� pucInputRenameFileName		�����������ĵ��ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE���TOOL_SUCCESS(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RenameFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputRenameFilePath,unsigned char *pucInputRenameFileName);

/***********************************************************************************************
	FuncName : Tool_MoveFile
	FuncFunc : �ƶ�һ���ļ�
	Input	 : unsigned char *	�� pucInputSourceFilePath	����Դ�ļ�·��
			   unsigned char *	�� pucInputSourceFileName	����Դ�ļ���
			   unsigned char *	�� pucInputMoveFilePath		�����ƶ����ļ�·��
			   unsigned char *	�� pucInputMoveFileName		�����ƶ����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : �����������ļ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_MoveFile(unsigned char *pucInputSourceFilePath,unsigned char *pucInputSourceFileName,unsigned char *pucInputMoveFilePath,unsigned char *pucInputMoveFileName);

/***********************************************************************************************
	FuncName : Tool_MoveDir
	FuncFunc : �ƶ�һ��Ŀ¼
	Input	 : unsigned char *	�� pucInputSourceFilePath	����Դ�ļ�·��
			   unsigned char *	�� pucInputMoveFilePath		�����ƶ����ļ�·��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : ����������Ŀ¼
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_MoveDir(unsigned char *pucInputSourceFilePath,unsigned char *pucInputMoveFilePath);

/***********************************************************************************************
	FuncName : Tool_ClearFile
	FuncFunc : ���ָ���ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	������յ��ļ�Ŀ¼·��
	           unsigned char *	�� pucInputFileName		������յ��ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����0x00
					 			�� ʧ��,���ط�0x00
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : ֻ����ļ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ClearFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_DelFile
	FuncFunc : ֱ��ɾ��ָ���ļ�
	Input	 : unsigned char *	�� pucInputDelFullFileName	����ɾ����Դ�ļ���(����·��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DelFile(unsigned char *pucInputDelFullFileName);

/***********************************************************************************************
	FuncName : Tool_DelFileEx
	FuncFunc : ֱ��ɾ��ָ���ļ�
	Input	 : unsigned char *	�� pucInputDelFilePath	����ɾ�����ļ�Ŀ¼·��
	           unsigned char *	�� pucInputDelFileName	����ɾ�����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DelFileEx(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : Tool_RemoveFile
	FuncFunc : ���˺���ɾ��ָ���ļ�
	Input	 : unsigned char *	�� pucInputDelFilePath	����ɾ�����ļ�Ŀ¼·��
	           unsigned char *	�� pucInputDelFileName	����ɾ�����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveFile(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : Tool_RemoveDir
	FuncFunc : ɾ��ָ����Ŀ¼
	Input	 : unsigned char *	�� pucInputDelFilePath	�����ɾ��Ŀ¼(����·��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveDir(unsigned char *pucInputDelFilePath);

/***********************************************************************************************
	FuncName : Tool_AppendInfoToFile
	FuncFunc : ����Ϣ���ַ�����ʮ�����Ƹ�ʽ���浽�ļ�
	Input	 : unsigned char	�� ucInputFileModeFlag	����ı����ļ�ģʽ:0-׷��	����-����
			   unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		���뱣����ļ���
			   unsigned char    �� ucFileFlag			���뱣���ļ����ӱ�־
			   											0x00-�޸�����Ϣ
			   											ucFileFlag&0x01-������ļ����������ں�׺
			   											ucFileFlag&0x02-������ļ���Ϣ��������ʱ����Ϣ
			   											ucFileFlag&0x04-������ļ���Ϣ������������ݳ���
			   unsigned char    �� ucCRFlag				�����ʽ���б�־
			                                            ucCRFlag 0x00-������ 
										    	        ucCRFlag&0x01-д�ļ���Ϣ֮ǰ�Ȼ��� 
										    	        ucCRFlag&0x02-���ڱ���ʱ���� 
										    		    ucCRFlag&0x04-д�ļ���Ϣ�껻��
										    		    ucCRFlag&0x08-�����ļ�ĩβ׷�ӷָ���
		       unsigned char *	�� pucTitle				���������Ϣ
			   unsigned char *	�� pucInputData			��������
		       unsigned int		�� uiInputDataLen		�������ݳ���
		       unsigned char	�� ucFormatFlag  		�洢���ݵĸ�ʽ 0-ASC 1-HEX 2-HEX��ASC 3-ֻ��ʾ����ʾ�ַ� ����ֵ-ASC
		       unsigned int		�� uiLineMaxNum			����ÿ����ʾ������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : ��Windows��ʽ,���з�(0x0D 0x0A)
	History  : None
	Other    : ��:ucCRFlag=0x06-д�ļ���Ϣ֮ǰ�Ȼ��к�д�ļ���Ϣ�궼����,һ����󳤶�4096
*************************************************************************************************/
EXPORT unsigned char Tool_AppendInfoToFile(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : Tool_AppendInfoToFileEx
	FuncFunc : ����Ϣ���ַ�����ʮ�����Ƹ�ʽ���浽�ļ�
	Input	 : unsigned char	�� ucInputFileModeFlag	����ı����ļ�ģʽ:0-׷��	����-����
			   unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		���뱣����ļ���
			   unsigned char    �� ucFileFlag			���뱣���ļ����ӱ�־
			   											0x00-�޸�����Ϣ
			   											ucFileFlag&0x01-������ļ����������ں�׺
			   											ucFileFlag&0x02-������ļ���Ϣ��������ʱ����Ϣ
			   											ucFileFlag&0x04-������ļ���Ϣ������������ݳ���
			   unsigned char    �� ucCRFlag				�����ʽ���б�־
			                                            ucCRFlag 0x00-������ 
										    	        ucCRFlag&0x01-д�ļ���Ϣ֮ǰ�Ȼ��� 
										    	        ucCRFlag&0x02-���ڱ���ʱ���� 
										    		    ucCRFlag&0x04-д�ļ���Ϣ�껻��
										    		    ucCRFlag&0x08-�����ļ�ĩβ׷�ӷָ���
		       unsigned char *	�� pucTitle				���������Ϣ
			   unsigned char *	�� pucInputData			��������
		       unsigned int		�� uiInputDataLen		�������ݳ���
		       unsigned char	�� ucFormatFlag  		�洢���ݵĸ�ʽ 0-ASC 1-HEX 2-HEX��ASC 3-ֻ��ʾ����ʾ�ַ� ����ֵ-ASC
		       unsigned int		�� uiLineMaxNum			����ÿ����ʾ������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : ��Linux/Unix��ʽ,���з�(0x0A)
	History  : None
	Other    : ��:ucCRFlag=0x06-д�ļ���Ϣ֮ǰ�Ȼ��к�д�ļ���Ϣ�궼����,һ����󳤶�4096
*************************************************************************************************/
EXPORT unsigned char Tool_AppendInfoToFileEx(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : Tool_AppendFileRecord
	FuncFunc : ׷���ļ���¼���Լ�¼�����Խ��м��
	Input	 : unsigned char	�� ucInputFileModeFlag	����ı����ļ�ģʽ			0-׷��	����-����
		       unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char *	�� pucInputData			���뱣���������Ϣ
		       unsigned long    �� ulInputDataLen		���뱣���������Ϣ��С
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : �������ulInputDataLenΪһ����¼���С
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AppendFileRecord(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetNumberFileRecord
	FuncFunc : ��ȡ�ļ���¼��
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       unsigned long *	�� pulRecordNumber		����ļ���¼��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �ļ���¼������,����TOOL_RECORDNOTFULL(0x19)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : �ļ�ÿ����¼��СΪulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetNumberFileRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName : Tool_GetRecord
	FuncFunc : ����ָ�����ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       DBInfor *    	�� pDBInfor  			�����������ļ���¼��Ϣ    
	Output	 : unsigned char *	�� pucOutputData		�����ȡ��ĳ��������¼��Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : �ļ�ÿ����¼��СΪulSize
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_UpdateRecord
	FuncFunc : ����ָ�����ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       DBInfor *    	�� pDBInfor  			�����������ļ���¼��Ϣ
		       unsigned char *	�� pucInputData			������µ�ĳ��������¼��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ֻ����ָ���ļ���¼��Ϣ,������ָ���ļ���ϢҲ��׷��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : Tool_DeleteRecord
	FuncFunc : ɾ��ָ�����ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       DBInfor *    	�� pDBInfor  			�����������ļ���¼��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ֻɾ��ָ���ļ���¼��Ϣ,������ָ���ļ���ϢҲ��׷��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor);

/***********************************************************************************************
	FuncName : Tool_GetRecordByIndex
	FuncFunc : ��ȡָ���������ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       unsigned long   	�� ulIndex  			�����ȡ���ļ���¼������
	Output	 : unsigned char *	�� pucOutputData		�����ȡ��ĳ��������¼��Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_UpdateRecordByIndex
	FuncFunc : ����ָ���������ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char *	�� pucInputData			������µ�ĳ��������¼��Ϣ
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       unsigned long   	�� ulIndex  			������µ��ļ���¼������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : Tool_DeleteRecordByIndex
	FuncFunc : ɾ��ָ���������ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				����ÿ����¼�Ĵ�С
		       unsigned long   	�� ulIndex  			����ɾ�����ļ���¼������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : Tool_ReadTlvRecord
	FuncFunc : ��ȡ�Ƕ�����¼TLV����Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned int   	�� uiTag  				�����ǩTag 
	Output	 : unsigned char *	�� pucOutputData		�����ǩTag��ֵ
	           unsigned int *	�� puiOutputLen			�����ǩTag��ֵ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� �ļ�����,����Ϊ��,����TOOL_FILENULL(0x15)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ReadTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag,unsigned char *pucOutputData,unsigned int *puiOutputLen);

/***********************************************************************************************
	FuncName : Tool_WriteTlvRecord
	FuncFunc : д��Ƕ�����¼TLV����Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned int   	�� uiTag  				�����ǩTag
		       unsigned char *	�� pucOutputData		�����ǩTag��ֵ
		       unsigned int 	�� uiInputDataLen		�����ǩTag��ֵ����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� �ļ�����,����Ϊ��,����TOOL_FILENULL(0x15)
								�� д�ļ�ʧ��,����TOOL_WRITEFILEFAIL(0x0D)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_WriteTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DeleteTlvRecord
	FuncFunc : ɾ���Ƕ�����¼TLV����Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned int   	�� uiTag  				����ɾ���ı�ǩTag
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� �ļ�����,����Ϊ��,����TOOL_FILENULL(0x15)
								�� д�ļ�ʧ��,����TOOL_WRITEFILEFAIL(0x0D)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteTlvRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned int uiTag);

/***********************************************************************************************
	FuncName : Tool_CreateDBFile
	FuncFunc : �������ݿ��ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	���봴�������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���봴�������ݿ��ļ���
		       unsigned long    �� ulSize  				���뱣��������ֵ��ļ��ṹ��Ϣ��С
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : ����ļ��Ƿ����,��������ھʹ����ļ�
*************************************************************************************************/
EXPORT unsigned char Tool_CreateDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize);

/***********************************************************************************************
	FuncName : Tool_ClearDBFile
	FuncFunc : ������ݿ��ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	���봴�������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���봴�������ݿ��ļ���
		       unsigned long    �� ulSize  				���뱣��������ֵ��ļ��ṹ��Ϣ��С
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : ��ɾ�������ݿ��ļ�,����ռ�¼��Ϣ
*************************************************************************************************/
EXPORT unsigned char Tool_ClearDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize);

/***********************************************************************************************
	FuncName : Tool_RemoveDBFile
	FuncFunc : ɾ�����ݿ��ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	����ɾ�������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		����ɾ�������ݿ��ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,���ط�0x00(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_RemoveDBFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : Tool_ReadDBRecord
	FuncFunc : ��ȡָ�����������ݿ��ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       unsigned long	�� ulRecIndex			�����ȡ�ļ�¼����
	Output	 : DBKEY *    		�� pOutputDbKey  		�����ȡ���ļ���¼��Ϣ
			   unsigned char *	�� pucOutputData		�����ȡ��ĳ��������¼��Ϣ
			   unsigned int *	�� puiOutputDataLen		�����ȡ��ĳ��������¼��Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : ������0��ʼ,���ȡ��һ����¼��������0
*************************************************************************************************/
EXPORT unsigned char Tool_ReadDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulRecIndex,DBKEY *pOutputDbKey,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_FindDBRecord
	FuncFunc : ����ָ�������ݿ��ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       DBKEY *    		�� pDbKey  				�����������ļ���¼��Ϣ
	Output	 : unsigned char *	�� pucOutputData		�����ȡ��ĳ��������¼��Ϣ
			   unsigned int *	�� puiOutputDataLen		�����ȡ��ĳ��������¼��Ϣ����
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� ���ļ�ʧ��,����TOOL_READFILEFAIL(0x0C)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_FindDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_AppendDBRecord
	FuncFunc : ׷��ָ�������ݿ��ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       DBKEY *    		�� pDbKey  				����׷�ӵ��ļ���¼��Ϣ
	 		   unsigned char *	�� pucInputData			����׷�ӵ�ĳ��������¼��Ϣ
			   unsigned int 	�� uiInputDataLen		����׷�ӵ�ĳ��������¼��Ϣ����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� ���ļ�ʧ��,����TOOL_READFILEFAIL(0x0C)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : ����Ѿ����ڲ�׷��
*************************************************************************************************/
EXPORT unsigned char Tool_AppendDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_UpdateDBRecord
	FuncFunc : ����ָ�������ݿ��ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       DBKEY *    		�� pDbKey  				������µ��ļ���¼��Ϣ
	 		   unsigned char *	�� pucInputData			������µ�ĳ��������¼��Ϣ
			   unsigned int 	�� uiInputDataLen		������µ�ĳ��������¼��Ϣ����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� ���ļ�ʧ��,����TOOL_READFILEFAIL(0x0C)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : �����������׷��
*************************************************************************************************/
EXPORT unsigned char Tool_UpdateDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DeleteDBRecord
	FuncFunc : ɾ��ָ�������ݿ��ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       DBKEY *    		�� pDbKey  				����ɾ�����ļ���¼��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� ���ļ�ʧ��,����TOOL_READFILEFAIL(0x0C)
					 			�� �����ڴ�ʧ��ʧ��,����TOOL_GETMEMORYFAIL(0x14)
					 			�� ָ���ļ���¼��Ϣ������,����TOOL_RECORDNOTEXIST(0x18)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DeleteDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,DBKEY *pDbKey);

/***********************************************************************************************
	FuncName : Tool_GetNumberDBRecord
	FuncFunc : ��ȡ���ݿ��ļ���¼��
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣������ݿ��ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣������ݿ��ļ���
		       unsigned long    �� ulSize  				���뱣��������ֵ��ļ��ṹ��Ϣ��С
		       unsigned long *	�� pulRecordNumber		����ļ���¼��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
					 			�� �ļ������ڴ��ļ�ʧ��,����TOOL_OPENFILEFAIL(0x05)
					 			�� �ļ���¼������,����TOOL_RECORDNOTFULL(0x19)
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ���ݿ��ֵ��ļ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetNumberDBRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName 	:  Tool_GetMac
	FuncFunc 	:  ��ȡ����������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen 	�������ݳ���
    			   unsigned char *	��pucInputInitVector����ĳ�ʼ��������
    			   unsigned char 	��ucKeyType 		������Կ���� 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(DESΪ8�ֽڻ���2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
	Output	 	:  unsigned char * 	��pucOutputData 	�����׼MAC(8���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  ��׼�㷨
	History  	:  3DESΪ24���ֽ�ΪX9.52
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetX919Mac
	FuncFunc 	:  ��ȡ����������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen 	�������ݳ���
    			   unsigned char *	��pucInputInitVector����ĳ�ʼ��������
    			   unsigned char 	��ucKeyType 		������Կ���� 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(DESΪ8�ֽڻ���2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
	Output	 	:  unsigned char * 	��pucOutputData 	���X9.19 MAC(8���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  X9.19�㷨
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetX919Mac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetX99Mac
	FuncFunc 	:  ��ȡ����������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen 	��������ݳ���
    			   unsigned char *	��pucInputInitVector����ĳ�ʼ��������
    			   unsigned char 	��ucKeyType 		������Կ���� 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(DESΪ8�ֽڻ���2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
    			   unsigned char    ��ucMacType 		X9.9�㷨���ͱ�־ 0-CBC�㷨 1-ECB�㷨
	Output	 	:  unsigned char * 	��pucOutputData  	���X9.9 MAC(8���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  X9.9 ����CBC�㷨��ECB�㷨,�Ƽ�ʹ��CBC�㷨
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetX99Mac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetCupMac
	FuncFunc 	:  ��ȡ����������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen	�������ݳ���
    			   unsigned char * 	��pucInputMakKey	���������Կ(8���ֽ�)
	Output	 	:  unsigned char * 	��pucOutputData		���MAC(8���ֽ�)
	Return	 	:  unsigned	char 	���ɹ�,����TOOL_SUCCESS(0x00)
								 	��ʧ��,����TOOL_FAILURE(0x01)
	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  ����CUP�㷨
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCupMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetIccMac
	FuncFunc 	:  ��ȡ����������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen 	��������ݳ���
    			   unsigned char *	��pucInputInitVector����ĳ�ʼ��������
    			   unsigned char 	��ucKeyType 		������Կ���� 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(DESΪ8�ֽڻ���2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
    			   unsigned char    ��ucMacType 		Icc�㷨���ͱ�־ 0-CBC�㷨 1-ECB�㷨
	Output	 	:  unsigned char * 	��pucOutputData  	���Icc��MAC(8���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  Icc������CBC�㷨��ECB�㷨,�Ƽ�ʹ��CBC�㷨
	History  	:  3DESΪ24���ֽ�ΪICC X9.52
	Other    	:  ����ĩβ׷��0x80
*************************************************************************************************/
EXPORT unsigned char Tool_GetIccMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName 	:  Tool_GetStrToHexIccMac
	FuncFunc 	:  ��ȡ�����ַ���������1-8�ļ�����
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen 	��������ݳ���
    			   unsigned char *	��pucInputInitVector����ĳ�ʼ��������
    			   unsigned char 	��ucKeyType 		������Կ���� 00-DES 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(DESΪ8�ֽڻ���2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
    			   unsigned char    ��ucMacType 		Icc�㷨���ͱ�־ 0-CBC�㷨 1-ECB�㷨
	Output	 	:  unsigned char * 	��pucOutputData  	���Icc��MAC(16���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  Icc������CBC�㷨��ECB�㷨,�Ƽ�ʹ��CBC�㷨
	History  	:  �������������ַ�����ʽ
	Other    	:  ĩβ׷��0x80
*************************************************************************************************/
EXPORT unsigned char Tool_GetStrToHexIccMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInputInitVector,
									unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char ucMacType,unsigned char *pucOutputData);
									
/***********************************************************************************************
	FuncName 	:  Tool_GetCardMac
	FuncFunc 	:  ��ȡ��ƬMAC
    Input	 	:  unsigned char *	��pucInputData 		���������
    			   unsigned int	 	��uiInputDataLen	�������ݳ���
    			   unsigned char * 	��pucInitVector  	�����ʼ����(8���ֽ�)
    			   unsigned char 	��ucKeyType 		������Կ���� 0x01-2DES 0x02-3DES
    			   unsigned char * 	��pucInputMakKey	���������Կ(2DESΪ16���ֽڻ���3DESΪ24���ֽ�)
	Output	 	:  unsigned char * 	��pucOutputData  	���MAC(8���ֽ�)
	Return	 	:  unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								 	�� ʧ��,����TOOL_FAILURE(0x01)

	Author		:  Sunrier
	Date     	:  2011-07-18 19:13:21
	Descp    	:  None
	History  	:  None
	Other    	:  None
*************************************************************************************************/
EXPORT unsigned char Tool_GetCardMac(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucInitVector,unsigned char ucKeyType,unsigned char *pucInputMakKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetSubSetResult
    FuncFunc : �ӳ���ΪiSubSetNum��������ѡ��m����ʹ��Ϊ�̶�ֵmFixData.lData,���ӽ�������Ӽ��ϵĺ���ӽ�mFixData.aucData
	Input	 : SUBSET_PRM *			�� pSubSetData		���������Ӽ�����������Ϣ
	           int 					�� iSubSetNum		���������Ӽ�������������
	           SUBSET_PRM 			�� mFixData			����̶�ֵmFixData��Ϣ          
	Output	 : SUBSETRESULT_PRM	*	�� pSubSetResult	������������������Ӽ�����
	Return	 : unsigned char		�� �ɹ�,����TOOL_SUCCESS
									�� ʧ��,����TOOL_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ѡ��m����ʱ,ÿ���Ӽ�ֻ��ȡ����������һ������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT int Tool_GetSubSetResult(SUBSET_PRM *pSubSetData,int iSubSetNum,SUBSET_PRM mFixData,SUBSETRESULT_PRM *pSubSetResult);

/***********************************************************************************************
	FuncName : Tool_Exit
	FuncFunc : �˳�Ӧ��
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Exit( void );

/***********************************************************************************************
	FuncName : Tool_Cls
	FuncFunc : ����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Cls( void );

/***********************************************************************************************
	FuncName : Tool_Beep
	FuncFunc : ���徯����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Beep( void );

/***********************************************************************************************
	FuncName : Tool_ErrorBeep
	FuncFunc : ���徯����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ErrorBeep( void );

/***********************************************************************************************
	FuncName : Tool_BeepEx
	FuncFunc : ����
	Input	 : unsigned	int 	�� uiFreq,���뷢��Ƶ��
			   unsigned	long 	�� ulMillSec,���뷢��ʱ����(MS)
	Output	 : None
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_BeepEx(unsigned int uiFreq,unsigned long ulMillSec);

/*************************************************************************************************
	FuncName : Tool_DispProgressBar
	FuncFunc : ��ʾ��ǰ���ؽ���
	Input	 : unsigned long 	�� ulCurrProg	��ǰ����
			   unsigned long 	�� ulTotalProg	�ܵĽ���
			   unsigned char	�� ucRunFlag 	���б�־:0-ִ�б�־
               											 1-������־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispProgressBar(unsigned long ulCurrProg,unsigned long ulTotalProg,unsigned char ucRunFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayCenter
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
               BOOL			 	�� bInvertFlag	�Ƿ��� TRUE-�� FALSE-��
               unsigned char 	�� ucMaxCol		һ�������ʾ�ĸ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayCenter(unsigned char *pucInputData,unsigned char ucStartLine,unsigned char bInvertFlag,unsigned char ucMaxCol);

/***********************************************************************************************
	FuncName : Tool_DisplayCenterEx
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               BOOL			 	�� bInvertFlag	�Ƿ��� TRUE-�� FALSE-��
               unsigned char 	�� ucMaxCol		һ�������ʾ�ĸ���
               unsigned char 	�� ucCRFlag		�Ƿ��Զ����� 0-�� 1-��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ���Զ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayCenterEx(unsigned char *pucInputData,unsigned char bInvertFlag,unsigned char ucMaxCol,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayLeft
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x01)
								�� ʧ��,����TOOL_FAILURE(0x00)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : �Զ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayLeft(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayLeftEx
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucCRFlag	�Ƿ��Զ����� 0-�� 1-��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ���Զ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayLeftEx(unsigned char *pucInputData,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayRight
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayRight(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayRightEx
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucCRFlag	ucCRFlag	�Ƿ��Զ����� 0-�� 1-��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ���Զ�����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayRightEx(unsigned char *pucInputData,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_DisplayMultiLine
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� ������һ����ʾ����
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ֧�ֶ�����ʾ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayMultiLine(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : Tool_DisplayText
	FuncFunc : ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
			   unsigned	char	�� ucDispMode	��ʾ��ʽ:0-����� 1-�Ҷ��� 2-����
               unsigned	char	�� ucInvertFlag	�Ƿ��� TRUE-�� FALSE-��
               unsigned	char	�� ucInvertColor������ɫ:����λ����ǰ��ɫ:����|��|��|��,����λ�����Ʊ���ɫ:����|��|��|��
               unsigned char 	�� ucMaxCol		һ�������ʾ�ĸ���
               unsigned char 	�� ucCRFlag		�Ƿ��Զ����� 0-�� 1-��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ֧�ֲ�ɫ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DisplayText(unsigned char *pucInputData,unsigned char ucDispMode,unsigned char ucInvertFlag,unsigned char ucInvertColor,unsigned char ucMaxCol,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : Tool_Zip
	FuncFunc : ѹ���ļ�
	Input	 : unsigned char *	�� pucInputZipFilePath			����ѹ���ļ�������ļ�Ŀ¼
	           unsigned char *	�� pucInputZipFileName			����ѹ���ļ�������ļ���
	           unsigned char *	�� pucInputZipResourePathName	����ѹ������Դ�ļ�Ŀ¼
	           unsigned char *	�� pucInputExcludePathFlag		�����Ƿ������ǰ��Դ�ļ�Ŀ¼����Ŀ¼:0-�� 1-��
	           unsigned char *	�� pucInputExcludeFilePath		�����ų���Ŀ¼:NULL��ʾ����Ҫ�ų�Ŀ¼
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Zip(unsigned char *pucInputZipFilePath,unsigned char *pucInputZipFileName,unsigned char *pucInputZipResourePathName,unsigned char pucInputExcludePathFlag,unsigned char *pucInputExcludeFilePath);

/***********************************************************************************************
	FuncName : Tool_UnZip
	FuncFunc : ѹ���ļ�
	Input	 : unsigned char *	�� pucInputZipFilePath		�����ѹ�ļ�Ŀ¼
	           unsigned char *	�� pucInputZipFileName		�����ѹ�ļ���
	           unsigned char *	�� pucInputUnZipFilePath	�����ѹ����ļ�Ŀ¼
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-12-24 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_UnZip(unsigned char *pucInputZipFilePath,unsigned char *pucInputZipFileName,unsigned char *pucInputUnZipFilePath);

/***********************************************************************************************
	FuncName : Tool_Bak
    FuncFunc : ����Ӧ�ù���
	Input	 : unsigned char *	�� pucAppName,����Ӧ����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
								�� ʧ��,����TOOL_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_Bak(unsigned char *pucAppName);

/***********************************************************************************************
	FuncName : Tool_GetPrivateData
	FuncFunc : ��ȡ����
	Input	 : unsigned char *	�� pucInputData		��������
			   unsigned int 	�� uiInputDataLen	�������ݳ���
			   unsigned char 	�� ucPrivateType	����˽����������
	Output	 : unsigned char *	�� pucOutputData	�������
			   unsigned int *	�� puiOutputDataLen	������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetPrivateData(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucPrivateType,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckCardNo
	FuncFunc : ��鿨���Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		��������
			   unsigned int 	�� uiInputDataLen	�������ݳ���
	Output	 : None
	Return	 : unsigned char	�� ��Ч,����TOOL_SUCCESS(0x00)
					 			�� ��Ч,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : Luhn�㷨
	History  : ���ŵ����һλ����ͨ��Luhn�㷨���м����У��
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckCardNo(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckId
	FuncFunc : ������֤�Ƿ���Ч
	Input	 : unsigned char *	�� pucInputData		��������
			   unsigned int 	�� uiInputDataLen	�������ݳ���
	Output	 : None
	Return	 : unsigned char	�� ��Ч,����TOOL_SUCCESS(0x00)
					 			�� ��Ч,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckId(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetIdInfo
	FuncFunc : ��ȡ���֤������Ϣ
	Input	 : unsigned char *	�� pucInputData		����2λ��6λ���֤������
			   unsigned int 	�� uiInputDataLen	�������ݳ���
			   unsigned char 	�� ucFlag			��ȡ��Ϣ��־:
			   											0-��ȡ������Ϣ 
			                                       		1-��ȡֱϽ�л�ʡ�� 
			                                        	2-��ȡֱϽ�л�ʡ���� 
			                                        	3-��ȡֱϽ�л�ʡ�ἰ���			   											   
	Output	 : unsigned char *	�� pucOutputData	�������
			   unsigned int *	�� puiOutputDataLen	������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetIdInfo(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMonthInfoByIntValue
	FuncFunc : ���������·ݻ�ȡ�·ݶ�Ӧ���ַ�����Ϣ
	Input	 : int				�� iMonth,�����·�
			   unsigned char 	�� ucFlag,��ȡ��Ϣ��־:			                                        
			                                       	0-��ȡӢ��ȫ����Ϣ 
			                                    	1-��ȡӢ�ļ����Ϣ
			                                    	2-��ȡӢ��ȫ��(���)��Ϣ
			                                       	3-��ȡ������Ϣ
			                                       	4-��ȡ����(Ӣ��ȫ��)��Ϣ
			                                       	5-��ȡ����(Ӣ�ļ��)��Ϣ
	Output	 : unsigned char *	�� pucOutputData	�������
			   unsigned int *	�� puiOutputDataLen	������ݳ���
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ����iMonth=1,ucFlag=0,*pucOutputData="January"
			   ����iMonth=10,ucFlag=0,*pucOutputData="October"
	           ����iMonth=11,ucFlag=0,*pucOutputData="November"
	           ����iMonth=12,ucFlag=0,*pucOutputData="December"
	           ����iMonth=1,ucFlag=1,*pucOutputData="Jan"
	           ����iMonth=1,ucFlag=2,*pucOutputData="January(Jan)"
	           ����iMonth=1,ucFlag=3,*pucOutputData="һ��"
	           ����iMonth=1,ucFlag=4,*pucOutputData="һ��(January)"
	           ����iMonth=1,ucFlag=5,*pucOutputData="һ��(Jan)"
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthInfoByIntValue(int iMonth,unsigned char ucFlag,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetMonthByStrValue
	FuncFunc : �����·��ַ�����ȡ�·ݶ�Ӧ����Ϣ
	Input	 : unsigned char *	�� pucInputData,�����·���Ϣ
			   unsigned int 	�� uiInputDataLen,�����·���Ϣ�ĳ���
	Output	 : int *			�� piOutputData,�����Ӧ���·�
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��:
	           ����"January",*piOutputData=1
	           ����"February",*piOutputData=2
	           ����"March",*piOutputData=3
	           ����"April",*piOutputData=4
	           ����"May",*piOutputData=5
	           ����"June",*piOutputData=6
	           ����"July",*piOutputData=7
	           ����"August",*piOutputData=8
	           ����"September",*piOutputData=9
	           ����"October",*piOutputData=10
	           ����"November",*piOutputData=11
	           ����"December",*piOutputData=12
	           ����"Jan",*piOutputData=1
	           ����"Feb",*piOutputData=2
	           ����"Mar",*piOutputData=3
	           ����"Apr",*piOutputData=4
	           ����"May",*piOutputData=5
	           ����"Jun",*piOutputData=6
	           ����"Jul",*piOutputData=7
	           ����"Aug",*piOutputData=8
	           ����"Sep",*piOutputData=9
	           ����"Oct",*piOutputData=10
	           ����"Nov",*piOutputData=11
	           ����"Dec",*piOutputData=12
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetMonthByStrValue(unsigned char *pucInputData,unsigned int uiInputDataLen,int *piOutputData);

/***********************************************************************************************
	FuncName : Tool_VerifyManage
	FuncFunc : Ȩ�޹���
	Input	 : unsigned char *	�� pucInputData		��֤����
			   unsigned char *	�� uiInputDataLen	��֤���ݳ���
			   unsigned char 	�� ucVerifyLevel	��֤�ȼ�:0x00-�߼� 	 0x01-һ��   0x02-���� 
			   												 0x03-���� 	 0x04-�ļ�   0x05-�弶
			   												 0x06-��֤�� 0x07-Ȩ�޼� 0x08-����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_VerifyManage(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucVerifyLevel);

/***********************************************************************************************
	FuncName : Tool_ConLicense
	FuncFunc : ��֤����
	Input	 : unsigned char *	�� pucInputData				��֤����
			   unsigned int 	�� uiInputDataLen			��֤���ݳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_ConLicense(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_CheckLicense
	FuncFunc : ֤����֤
	Input	 : unsigned char *	�� pucInputKis				���Ψһ������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckLicense(unsigned char *pucInputKis);

/***********************************************************************************************
	FuncName : Tool_AuthLicense
	FuncFunc : ��֤����֤�鲢�����µı���֤��
	Input	 : unsigned char *	�� pucInputKis,�������Ψһ������
	           unsigned char *	�� pucInputData,������֤����
	           unsigned int		�� uiInputDataLen,������֤���ݳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AuthLicense(unsigned char *pucInputKis,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Tool_DispAppRegCode
	FuncFunc : ��ʾ���ע����ش�����Ϣ
	Input	 : unsigned char	�� ucRetCode ����ķ�����Ϊ���Ӧ�����ע�ắ������ע���������������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : �����������ע��ʧ��ʱ���ȡ������Ϣ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispAppRegCode(unsigned char ucRetCode);

/***********************************************************************************************
	FuncName : Tool_CheckAppValid
	FuncFunc : ����������Ч��,ע����Ϣ�Ƿ�ʧЧ
	Input	 : unsigned char *	�� pucInputAppPath			�����ע��Ӧ���ļ�Ŀ¼·��(����·��)
			   unsigned char *	�� pucInputAppName			����ĵ�ǰע��Ӧ�����������
			   unsigned char *	�� pucInputProtName			����ĵ�ǰע�ᱣ���ļ�������
			   
			   unsigned char *	�� pucInputKis				���Ψһ������(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputAppFileMacKey	ע��Ӧ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputProtFileMacKey	ע�ᱣ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputAppFileProKey	ע��Ӧ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
			   unsigned char *  �� pucInputProtFileProKey	ע�ᱣ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
	Output	 : unsigned char *  �� pucOutputData			����û���Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS
					 			�� ʧ��,��������,���������Ϣ����ʹ��Tool_DispAppRegCode�����鿴
	Author	 : Sunrier
	Date     : 2013-09-19 19:00:55
	Descp    : �˺������Կ�������Ƿ���Ҫע��ɹ��ſ�������,Ӧ��������п���
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_CheckAppValid(unsigned char *pucInputAppPath,unsigned char *pucInputAppName,unsigned char *pucInputProtName,unsigned char *pucInputKis,unsigned char *pucInputAppFileMacKey,unsigned char *pucInputProtFileMacKey,
											unsigned char *pucInputAppFileProKey,unsigned char *pucInputProtFileProKey,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_AppRegister
	FuncFunc : ע�����
	Input	 : unsigned char *	�� pucInputAppPath			�����ע��Ӧ���ļ�Ŀ¼·��(����·��)
			   unsigned char *	�� pucInputAppName			����ĵ�ǰע��Ӧ�����������
			   unsigned char *	�� pucInputProtName			����ĵ�ǰע�ᱣ���ļ�������
			   
			   unsigned char *	�� pucInputKis				���Ψһ������(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�32λ
			   unsigned char *  �� pucInputTranProKey		������Կ�ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputLimiProKey		��Ч��Ϣ�ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputKisProKey		���������ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�32λ
			   unsigned char *  �� pucInputLicProKey		ע����ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�48λ
			   
			   unsigned char *  �� pucInputAppFileMacKey	ע��Ӧ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputProtFileMacKey	ע�ᱣ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputAppFileProKey	ע��Ӧ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
			   unsigned char *  �� pucInputProtFileProKey	ע�ᱣ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
	Output	 : unsigned char *  �� pucOutputData			����û���Ϣ
	Return	 : unsigned char	�� �ɹ�,����0x00
					 			�� ʧ��,��������,���������Ϣ����ʹ��Tool_DispAppRegCode�����鿴
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
	FuncFunc : ע�����
	Input	 : unsigned char *	�� pucInputAppPath	�����ע��Ӧ���ļ�Ŀ¼·��(����·��)
			   unsigned char *	�� pucInputAppName	����ĵ�ǰע��Ӧ�����������
			   unsigned char *	�� pucInputProtName	����ĵ�ǰע�ᱣ���ļ�������
	Output	 : unsigned char *  �� pucOutputData	����û���Ϣ
	Return	 : unsigned char	�� �ɹ�,����0x00
					 			�� ʧ��,��������,���������Ϣ����ʹ��Tool_DispAppRegCode�����鿴
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_AppUnregister(unsigned char *pucInputAppPath,unsigned char *pucInputAppName,unsigned char *pucInputProtName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_GetAppLicenseInfor
	FuncFunc : ��ȡӦ��ע�������Ϣ
	Input	 : unsigned char *	�� pucInputKis				���Ψһ������(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputTranProKey		������Կ�ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputLimiProKey		��Ч��Ϣ�ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputKisProKey		���������ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�32λ
			   unsigned char *  �� pucInputLicProKey		ע����ı�����Կ(Ӧ�����Ҫ��ע������ƥ��),������,A~Z,a~zȡֵ,�̶�48λ
			   
			   unsigned char *  �� pucInputAppFileMacKey	ע��Ӧ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputProtFileMacKey	ע�ᱣ���ļ���Ϣ��MAC��Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�16λ
			   unsigned char *  �� pucInputAppFileProKey	ע��Ӧ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
			   unsigned char *  �� pucInputProtFileProKey	ע�ᱣ���ļ���Ϣ�ı�����Կ(Ӧ��������ж���),������,A~Z,a~zȡֵ,�̶�48λ
	Output	 : None
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
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
	FuncFunc : ͨ���������ȡ�����Ϣ����
	Input	 : unsigned char	�� ucRetCode 	 ����ķ�����
	Output	 : unsigned char *	�� pucOutputData �������ط������Ӧ������Ϣ
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ȡ���߿ⷵ���������Ϣ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetDescpFromCode(unsigned char ucRetCode,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Tool_DispCode
	FuncFunc : ��ʾ��ط�������Ϣ
	Input	 : unsigned char	�� ucRetCode ����ķ�����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : ��ȡ���߿ⷵ������Ϣ��������ʾ
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_DispCode(unsigned char ucRetCode);

/***********************************************************************************************
	FuncName : Tool_GetRevisionInfo
	FuncFunc : ��ȡ��汾�޶���Ϣ
	Input	 : unsigned int *	�� puiOutputDataLen	�����޶���Ϣ�����洢����
	Output	 : unsigned char *	�� pucOutputData	����޶���Ϣ
	           unsigned int *	�� puiOutputDataLen	����޶���Ϣ�ĳ���
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Tool_GetRevisionInfo(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Tool_GetLibVersion
	FuncFunc : ��ȡ��汾
	Input	 : unsigned int *	�� puiOutputDataLen	�����汾�����洢����
	Output	 : unsigned char *	�� pucOutputData	�����ǰ��汾
	           unsigned int *	�� puiOutputDataLen	�����汾�����洢����
	Return	 : unsigned	char 	�� �ɹ�,����TOOL_SUCCESS(0x00)
								�� ʧ��,����TOOL_FAILURE(0x01)
								�� ��Ч����,����TOOL_PARAMERROR(0x05)
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
