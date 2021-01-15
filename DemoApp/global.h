/*************************************************************************************************
	FileName : global.h
    FileFunc : 实现全局信息头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-08-05 11:13:15
    Descp    : 定义应用全局信息
    History  : None
*************************************************************************************************/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define DEBUG_DISP
#define DEBUG        					__FILE__,__LINE__



/*应用相关信息*/
#define GLOBAL_APPNAME   				"DEMOAPP"		/*应用名*/
#define	GLOBAL_APPCOMMSECNAME			"COMM"			/*应用通讯参数节名*/

/*应用无关信息*/
#define APP_MAXBUFFER					2048	/*最大缓冲区*/
#define APP_TIMER_SEC					(60*1)	/*定时超时时间 1分钟*/
#define APP_WAITTIME					(60*1)	/*定时等待用户按键超时时间 1分钟*/

#define APP_MAXCOMMBUF           		(4096*2)

#define GLOBAL_DEFAULTCONFIGPATH		".\\CONFIG\\"				/*配置文件默认路径*/
#define GLOBAL_CONFIGFILENAME			GLOBAL_APPNAME ".ini"		/*应用配置文件名*/

#define	GLOBAL_DEFAULTLOGPATH			".\\LOG\\"					/*LOG日志默认路径*/
#define	GLOBAL_LOGFILENAME				GLOBAL_APPNAME "_LOG"		/*LOG日志文件名前缀*/
#define	GLOBAL_LOGSECNAME				GLOBAL_APPNAME "LOG"		/*LOG日志参数节名*/
#define GLOBAL_TRACELOGFILENAME			"TRACE"						/*跟踪的调试信息*/

#define APP_ALIGNWIDTH					(58)

/*APP*/
#define APP_NAME						GLOBAL_APPNAME
#define APP_FUNCTION					GLOBAL_APPNAME "应用软件"
#define APP_VERSION						"00.00.01"
#define APP_AUTHOR						"Sunrier"
#define APP_CONTACT						"Sunrier@163.com"
#define APP_DATE						"2013-06-08 10:26:10"
#define APP_DESCPTION					"实用软件"


/*日志级别-LOG_OFF>LOG_ERROR>LOG_WARN>LOG_INFO>LOG_DEBUG>LOG_ALL*/
typedef enum _LOG_LEVEL
{
	LOG_OFF  	= 0x00,	/*关闭所有日志记录-最高级别*/
	LOG_ERROR	= 0x01,	/*描述应用程序运行中发生的错误信息*/
	LOG_WARN	= 0x02,	/*描述应用程序运行中发生的警告信息*/
	LOG_INFO 	= 0x03,	/*描述应用程序运行过程*/
	LOG_DEBUG 	= 0x04,	/*打开调试日志*/
	LOG_ALL 	= 0x05, /*打开所有日志记录*/
	LOG_MAX,
}LOG_LEVEL;


/*App应用结构定义*/
typedef struct {
	unsigned char ucOverFlag;				/*结束标志*/
	unsigned long ulStartTimer;				/*超时开始时间*/
	unsigned long ulEndTimer;				/*超时结束时间*/
	unsigned char ucTimeOutFlag;			/*超时标志*/
	unsigned char ucCNTipFlag;				/*中文提示信息标志:0-英文提示 1-中文提示*/
	unsigned char ucLogLevel;				/*日志级别,保存报文标志:0-不保存相关调试信息 非0-保存相关调试信息,日志级别-LOG_OFF>LOG_ERR>LOG_INFO>LOG_DEBUG>LOG_ALL*/
	unsigned char ucDispFlag;				/*显示报文标志:0-不显示相关调试信息 1-显示相关调试信息*/
	unsigned char ucUserNameLen;			/*用户名长度*/
	unsigned char aucUserName[15+1];		/*用户名*/
	unsigned char ucFirstRun;				/*第一次启动标志	0-第一次启动 其它-已经启动*/
	unsigned char aucTitle[64+1];			/*标题*/
	unsigned char aucCurrDate[8+1];			/*当前日期*/
	unsigned char ucLastRunNodeFlag;		/*上一次运行断点标记*/
	unsigned char aucLastRunData[8+1];		/*上一次运行数据*/
	unsigned char aucCfgFileName[64+1];		/*配置文件名*/
	unsigned char ucLogFileFlag;			/*日志LOG文件标志:0-固定文件 1-自定义文件*/
	unsigned char aucLogFileName[64];		/*自定义LOG日志文件名*/
	unsigned char ucCommFlag;				/*0-默认系统文件中的从通讯信息 1-配置文件中获取*/
	unsigned char aucDefTmpPath[512+1];		/*自定义默认临时目录*/
	unsigned char aucDefTmpFile[512+1];		/*自定义默认临时文件*/
	unsigned char ucAppFlag;				/*应用标志*/
}App_Prm;

typedef struct {
	unsigned short  usRS232Timeout;	    		/*串口通讯超时(S)*/
	unsigned short  usTcpTimeout;       		/*TCP超时时间(S)*/
	unsigned short  usSSLTimeout;       		/*SSL超时时间(S)*/
	unsigned short  usTcpServerTimeout; 		/*TCP服务器超时时间(S)*/
	unsigned short  usTcpServerBlockTimeout; 	/*TCP服务器阻塞时超时时间(S)*/
	unsigned short  usFTPServerTimeout; 		/*作为FTP超时时间(S)*/
	
	unsigned short  usSSLHostPort1;     		/*SSL HostPort1*/
	unsigned short  usSSLHostPort2;     		/*SSL HostPort2*/
	unsigned short  usTCPHostPort1;    			/*TCP HostPort1*/
	unsigned short  usTCPHostPort2;    			/*TCP HostPort2*/

	unsigned short  usTCPServerPort1;   		/*TCP Server Port1*/
	unsigned short  usTCPServerPort2;   		/*TCP Server Port2*/

	unsigned short usFTPServerPort1;			/*作为FTP Server监听端口1*/
	unsigned short usFTPServerPort2;			/*作为FTP Server监听端口2*/
	
	//串口/TCP
	unsigned char ucCurrentCommMode;        	/*当前通讯模式*/
	unsigned char ucRetrys;                 	/*重试次数*/

	//以下参数为本机参数
	unsigned char aucLocalIP[16];              	/*本机地址*/
	unsigned char aucSubNetMask[16];           	/*网络MASK*/
	unsigned char aucGateWay[16];              	/*网关*/
	unsigned char aucPriDNS[16];               	/*DNS1*/
	unsigned char aucSecDNS[16];               	/*DNS2*/

	// FTP
	unsigned char aucFTPLocalIP[16];			/*作为FTP本地IP地址*/

	// HTTP相关
	unsigned char aucHttpURL[256+1];		/*HTTP服务器URL1*/
	unsigned char aucHttpDomain[64+1];		/*HTTP服务器Domain*/
	unsigned char aucHttpPage[64+1];		/*HTTP服务器Page1*/
	//unsigned char aucHttpIP1[16];			/*HTTP服务器IP1*/
	//unsigned char aucHttpIP2[16];			/*HTTP服务器IP2*/

	// HTTPS相关
	unsigned char aucHttpsURL[256+1];			/*HTTPS服务器URL1*/
	unsigned char aucHttpsDomain[64+1];			/*HTTPS服务器Domain*/
	unsigned char aucHttpsPage[64+1];			/*HTTPS服务器Page1*/
	//unsigned char aucHttpsIP1[16];			/*HTTPS服务器IP1*/
	//unsigned char aucHttpsIP2[16];			/*HTTPS服务器IP2*/

	// TCP
	unsigned char aucTCPIP1[16];				/*TCP Host IP1*/
	unsigned char aucTCPIP2[16];				/*TCP Host IP2*/
	
	unsigned char aucTCPDomainName1[64+1];		/*TCP Host 域名1*/
	unsigned char aucTCPDomainName2[64+1];		/*TCP Host 域名2*/

	// TCP Server
	unsigned char aucTCPServerIP1[16];			/*TCP服务器IP1*/
	unsigned char aucTCPServerIP2[16];			/*TCP服务器IP2*/

	// FTP
	unsigned char aucFTPServerIP1[16];			/*作为FTP 服务器IP1*/
	unsigned char aucFTPServerIP2[16];			/*作为FTP 服务器IP2*/

	unsigned char aucFTPHostName1[128+1];		/*Windows FTP服务器域名1*/
	unsigned char aucFTPHostName2[128+1];		/*Windows FTP服务器域名2*/

	unsigned char aucFTPUserName[256+1];		/*FTP用户名*/
	unsigned char aucFTPUserPassword[256+1];	/*FTP用户密码*/

	unsigned char aucFTPLocalPath[256+1];		/*FTP本地目录*/
	unsigned char aucFTPRemotePath[256+1];		/*FTP远程目录*/
	unsigned char aucFTPFileType[1+1];			/*FTP文件类型(ASCII-A/BIN-I/EBCD-E,默认BIN-I)*/
	unsigned char ucFTPListType;				/*FTP文件下载列表类型:0-文件和目录明细 1-文件和目录名列表 2-只返回文件名 3-只返回目录名 4-只返回文件名和目录名 其他-只返回文件名*/
	unsigned char ucFTPFileNullFlag;			/*FTP文件为空是否支持标志:0-不支持 1-支持*/
	unsigned char ucFTPUploadTmpFileFlag;		/*FTP文件上传是否支持tmp文件标志:0-不支持 1-支持*/
	unsigned char ucFTPDelRemoteFileFlag;		/*FTP远程文件删除标志:0-不删除 1-删除*/
	
	unsigned int uiCommPort;				/*串口号*/
	unsigned int uiBaudRate;				/*波特率*/

	
	unsigned char ucDomainNameFlag;			/*通讯是否使用域名标志*/
	unsigned char ucFTPHostNameFlag;		/*FTP是否使用域名或服务名代替IP:0-否 1-是*/
	unsigned char ucBakCommFlag;			/*通讯是否使用备机标志*/
	unsigned char ucSSLFlag;				/*通讯是否SSL*/
	unsigned char ucFTPSockBakFlag;			/*FTP备机通讯是否支持:0-不支持 1-支持*/

	unsigned char ucCommFlag;				/*当前通讯标志 0-串口 1-网络 2-公网 3-HTTP 4-HTTPS*/
	unsigned char ucSelfProtocolFlag;		/*http或https协议时是否支持库的协议: 0-不支持 1-支持*/
	unsigned char ucRequestWayFlag;			/*http或https的请求方法:0-Post方法 1-Get方法,默认0*/
	unsigned char ucParseFlag;
	unsigned char ucPacketPrintDebugFlag;
	unsigned int  uiParam1;
	unsigned int  uiParam2;
	unsigned int  uiParam3;
	unsigned char aucParam1[256+1];
	unsigned char aucParam2[256+1];
	unsigned char aucParam3[256+1];
	unsigned char aucRFU1[256+1];
	unsigned char aucRFU2[256+1];
	unsigned char aucRFU3[256+1];
	unsigned char aucReserved[120];
} Comm_Prm;

typedef struct
{	
    //数据包属性参数
    unsigned char        ucAppType;                          /*应用类型*/
    unsigned char        aucMisTraceID[6+1];                 /*MISPOS唯一标识(MISPOS流水号)*/
    
    //请求指令共性参数
    unsigned char        aucCmdCode[2+1];                    /*指令代码*/
    unsigned char        aucMPMerchantCode[15+1];            /*商户号*/
    unsigned char        aucMPTerminalCode[8+1];             /*终端号*/
    unsigned char        aucMPMerchantNameChn[60+1];         /*商户中文名*/
    unsigned char        aucMPMerchantNameEng[60+1];         /*商户英文名*/
    unsigned char        aucMPCashierNo[15+1];               /*款台号*/
    unsigned char        aucMPOperNo[15+1];                  /*操作员号*/
    unsigned char        aucMPSysTraceNo[20+1];              /*收银流水号*/
	unsigned char		 aucMPOrderNum[64+1];				 /*订单编号*/

	unsigned char		 ucAppFlag;							 /*应用标志*/
	unsigned char		 ucEnFlag;							 /*是否加密 0-不加密 其它-加密*/
	
	//unsigned char        ucTimeOut;                        /*读卡超时时间*/
	//unsigned char        ucIsListen;                       /*是否开始侦听,  0-否，1-是*/
	unsigned char 		 ucMisTranFlag;						 /*当前MIS交易标志 0-否 1-是*/
	unsigned char        ucTransType;						 /*当前MIS交易类型*/
	unsigned char 		 aucAmount[12 + 1];     			 /*交易金额*/
	unsigned char        aucOrgSysTraceNo[6+1];				 /*原始凭证号*/
	unsigned char        aucOrgRefNo[12+1];				 	 /*原始参考号*/
	unsigned char        aucOrgAuthNo[6+1];				 	 /*原授权号*/
	unsigned char        aucOrgDate[4+1];				 	 /*原始日期MMDD*/
	unsigned char		 aucOrgCardNum[19+1];				 /*原卡号*/
	unsigned char 		 aucOrgExpDate[4+1];				 /*原卡号有效期*/
	unsigned char		 ucCardInputMode;					 /*卡号输入方式 0-默认 1-手工输入*/
	unsigned char		 ucCmdFlag;							 /*指令标志 0-间接查询标志 1-当前执行的指令标志*/
	unsigned char		 ucSSLFlag;							 /*是否SSL通讯标志,SSL通讯需要加密*/
	unsigned char		 ucSSLAuthTimes;					 /*SSL通讯认证次数,2次认证算一个完整流程才算断开连接*/
	unsigned char 		 ucCommFlag;						 /*通讯标志 0-串口 1-网络 2-SSL 3-HTTP 4-HTTPS*/
	unsigned char        ucDataFormat;						 /*数据格式*/
	unsigned char        ucAckNak;						 	 /*返回码响应*/
	unsigned char        ucReLinkFlag;						 /*重连标志*/
	unsigned char        ucTimeoutFlag;						 /*超时标志*/
	unsigned char        ucSupportEscFlag;					 /*交易支持取消标志 0-不支持 1-支持*/
	unsigned char		 ucLoopTimes;						 /*交易支持取消时循环次数*/
	unsigned char		 ucProjFlag;						 /*当前项目标志 0-标准项目*/
	unsigned short       usTimeout;						 	 /*超时时间*/
	
}Trans_Prm;

/*应用失败的返回错误信息码*/
typedef enum
{
	APP_SUCCESS 	= 0x00,	/*成功*/
	APP_FAILURE,			/*失败*/
	APP_TIMEOUT,			/*超时*/
	APP_ESC,				/*用户取消*/
	APP_PARAMERROR,			/*输入参数有误*/
	APP_EXIT,    			/*退出*/
	
	APP_HEADLENFAIL = 0x30,	/*接收头部长度失败*/
    APP_STXERROR,			/*接收数据的开始标志错误*/
 	APP_ETXERROR,			/*接收的结束标志错误*/
	APP_LENGTHERROR,		/*接收的数据长度错误*/
	APP_LRCERROR,			/*接收的数据校验码LRC错误*/
	APP_SENDFAIL,			/*发送数据失败*/
	APP_SENDOVERLIMIT,		/*发送数据超过最大限制*/
	APP_RECVFAIL,			/*接收数据失败*/
	APP_RECVDATAERROR,		/*接收的数据长度和期望接收的数据长度不一致*/
	APP_COMMTYPEINVALID, 	/*通讯类型无效,设置有误*/
	APP_COMMFORMATINVALID, 	/*通讯格式无效,设置有误*/
	APP_MAXCODE,
}APP_CODE;

#if 0
/*通讯标志*/
typedef enum
{
	COMM_RS232 = 0,
	COMM_TCP,
	COMM_SSL,
	COMM_HTTP,
	COMM_HTTPS,
	COMM_UDP,
	COMM_FTP,
	COMM_MAX,
}COMM_FLAG;

/*Comm Port*/
typedef enum
{
	COM1 = 1,
	COM2,
	COM3,
	COM4,
	COM5,
	COM6,
	COM7,
	COM8,
	COM9
}CommPort;

/*BaudRate*/
typedef enum
{
	UBPS300 	= 300,
	UBPS1200 	= 1200,
	UBPS2400 	= 2400,
	UBPS4800	= 4800,
	UBPS7200	= 7200,
	UBPS9600	= 9600,
	UBPS19200	= 19200,
	UBPS38400	= 38400,
	UBPS57600	= 57600,
	UBPS76800	= 76800,
	UBPS115200	= 115200
}BaudRate;

/*通讯格式*/
typedef enum
{
	COMM_FMT_NOFMT = 0,
	COMM_FMT_ASCLEN_DATA,
	COMM_FMT_HEXLEN_DATA,
	COMM_FMT_STX_HEXLEN_DATA_ETX_LRC,
	COMM_FMT_STX_HEXLEN_DATA_LRC_ETX,
	COMM_FMT_STX_DATA_ETX_LRC,
	COMM_FMT_STX_DATA_LRC_ETX,
}CommFormat;
#endif

/*通讯超时标志*/
typedef enum
{
	TIMEOUT_RS232 = 0,
	TIMEOUT_TCP,
	TIMEOUT_SSL,
	TIMEOUT_SCAN,
	TIMEOUT_ESC,
}TimeOutFlag;

/*交易类型--注意同Msg相一致*/
typedef enum __TransType
{
	TTYPE_LOGON = 1,                  /*POS签到*/
	TTYPE_LOGOUT,                     /*POS签退*/
	TTYPE_LOGON_CASHIER,              /*收银员积分签到*/
	TTYPE_SETTLE,                     /*结算*/
	TTYPE_SETTLE_END,                 /*结算完成*/ 
	TTYPE_BATCH_UPLOAD,               /*批上送*/
	TTYPE_SCRIPTADVICE,               /*发卡行处理脚本结果通知*/
	TTYPE_ICOFFLINE_UPLOAD,           /*IC卡脱机交易上送*/
	TTYPE_TC_UPLOAD,                  /*IC卡联机交易*/
	TTYPE_TC_UPLOAD_END,              /*IC卡联机交易上送完成*/
	TTYPE_DOWNLOAD_PARAMETERS,        /*参数下载(传递)*/
	TTYPE_QPS_PARAMETERS_DOWNLOAD,    /*QPS非接参数下载*/
	TTYPE_UPLOAD_STATUS,              /*状态上送(亦可作参数查询)*/
	TTYPE_ECHO_TESTING,				  /*回响测试*/
	TTYPE_DOWNLOAD_END,               /*参数下载结束*/

	TTYPE_BALANCE,                    /*余额查询*/
	TTYPE_SALE,                       /*消费*/
	TTYPE_SALE_VOID,                  /*消费撤销*/
	TTYPE_REFUND,                     /*退货*/

	TTYPE_PREAUTH,                    /*预授权*/
	TTYPE_PREAUTH_VOID,               /*预授权撤销*/
	TTYPE_COMPLETE,                   /*预授权完成请求(联机)*/
	TTYPE_COMPLETE_VOID,              /*预授权完成撤销*/
	TTYPE_OFFLINE_COMPLETE,           /*预授权完成通知(联机)*/

	TTYPE_OFFLINE_SETTLE,             /*离线结算(脱机)*/
	TTYPE_OFFLINE_ADJUST,             /*结算调整(脱机)*/
	
	TTYPE_ECASH_BALANCE,              /*电子现金查余额*/
	TTYPE_ECASH_CASH_RELOAD,          /*电子现金现金充值*/ 
	TTYPE_ECASH_CASH_RELOAD_VOID,     /*电子现金现金充值撤销*/ 
	TTYPE_ECASH_IN_RELOAD,            /*电子现金指定账户圈存*/
	TTYPE_ECASH_OUT_RELOAD,           /*电子现金非指定账户圈存*/ 
	TTYPE_ECASH_REFUND,               /*电子现金脱机交易退货*/
	
	TTYPE_MAG_ACCT_VERIFY,            /*磁条卡现金充值账户验证*/
	TTYPE_MAG_CASHLOAD,               /*磁条卡现金充值*/
	TTYPE_MAG_CASHLOAD_CONFIRM,       /*磁条卡现金充值确认*/ 
	TTYPE_MAG_ACCTLOAD,               /*磁条卡账户充值*/
	
	TTYPE_INSTALLMENT,                /*分期付款*/
	TTYPE_INSTALLMENT_VOID,           /*分期付款撤销*/
	
	TTYPE_YUYUE_SALE,                 /*预约消费*/
	TTYPE_YUYUE_SALE_VOID,            /*预约消费撤销*/ 
	TTYPE_YUYUE_REFUND,               /*预约退货*/

	TTYPE_ISSUER_SCORE_SALE,          /*发卡行积分消费*/
	TTYPE_ISSUER_SCORE_SALE_VOID,     /*发卡行积分撤销*/
	TTYPE_UNION_SCORE_SALE,           /*联盟积分消费*/
	TTYPE_UNION_SCORE_SALE_VOID,      /*联盟积分撤销*/
	TTYPE_UNION_SCORE_BALANCE,        /*联盟积分查询*/
	TTYPE_UNION_SCORE_REFUND,         /*联盟积分退货*/ 

	TTYPE_MCHIP_BALANCE,              /*手机芯片余额查询*/ 
	TTYPE_MCHIP_SALE,                 /*手机芯片消费*/
	TTYPE_MCHIP_SALE_VOID,            /*手机芯片消费撤销*/ 
	TTYPE_MCHIP_REFUND,               /*手机芯片退货*/ 
	TTYPE_MCHIP_PREAUTH,              /*手机芯片预授权*/ 
	TTYPE_MCHIP_PREAUTH_VOID,         /*手机芯片预授权撤销*/ 
	TTYPE_MCHIP_COMPLETE,             /*手机芯片预授权完成请求(联机)*/ 
	TTYPE_MCHIP_COMPLETE_VOID,        /*手机芯片预授权完成撤销*/ 
	TTYPE_MCHIP_OFFLINE_COMPLETE,     /*手机芯片预授权完成通知(联机)*/

	TTYPE_ORDER_CARDHOLDER_VERIFY,    /*订购交易持卡人身份验证*/
	TTYPE_ORDER_SALE,                 /*订购消费*/
	TTYPE_ORDER_SALE_VOID,            /*订购消费撤销*/ 
	TTYPE_ORDER_REFUND,               /*订购退货*/ 
	TTYPE_ORDER_PREAUTH,              /*订购预授权*/ 
	TTYPE_ORDER_PREAUTH_VOID,         /*订购预授权撤销*/ 
	TTYPE_ORDER_COMPLETE,             /*订购预授权完成请求(联机)*/ 
	TTYPE_ORDER_COMPLETE_VOID,        /*订购预授权完成撤销*/
	TTYPE_ORDER_OFFLINE_COMPLETE,     /*订购预授权完成通知(联机)*/ 

	TTYPE_AID_INQUERY,                /*查询AID INDEX LIST*/
	TTYPE_AID_UPDATE,                 /*更新AID参数*/
	TTYPE_AID_END,                    /*更新AID完成*/
	TTYPE_CAKEY_INQUERY,              /*查询CAPK INDEX LIST*/
	TTYPE_CAKEY_UPDATE,               /*更新公钥*/
	TTYPE_CAKEY_END,                  /*更新公钥完成*/
	TTYPE_BLACK_UPDATE,               /*更新黑名单参数*/
	TTYPE_BLACK_END,                  /*更新黑名单完成*/
	TTYPE_TMS_UPDATE_PARAMETER,       /*更新TMS*/
	TTYPE_REVERSAL,                   /*冲正*/

	TTYPE_LINK,						  /*连接测试交易*/
	TTYPE_CANCEL,					  /*取消交易*/
	TTYPE_GETBATTERY,				  /*获取电量*/
	TTYPE_GETAPPVER,				  /*获取某个应用版本*/
	TTYPE_GETAPPINFO,			  	  /*获取应用信息*/
	TTYPE_GETPARAM,					  /*获取参数*/
	TTYPE_SETPARAM,				      /*设置参数*/
	TTYPE_BARSCAN,				      /*获取扫码信息*/
	TTYPE_BARCLOSE,				      /*关闭扫码*/
	TTYPE_SETRSAKEY,				  /*设置RSA公钥KEY*/
	TTYPE_GETCARDINFO,				  /*获取刷卡信息*/
	TTYPE_TRANS_INQUIRY,			  /*交易查询*/
	TTYPE_GETPRINTINFO,				  /*取交易信息打印*/
	TTYPE_GETREPRINTINFO,			  /*取交易信息并重打印*/
	TTYPE_GETSETTLEINFO,			  /*取结算信息打印*/
	TTYPE_GETRESETTLEINFO,			  /*取结算信息并重打印*/
	TTYPE_ORDER_INQUIRY,			  /*订单查询交易*/
	TTYPE_ACTIVATE,			  	  	  /*卡激活交易*/
	TTYPE_INACTIVATE,			  	  /*卡激活撤销交易*/
	TTYPE_CARDQUERY,			  	  /*卡状态查询交易*/
	TTYPE_NOTICEINFO,				  /*通知信息交易*/
	TTYPE_POSINIT,				  	  /*新装机初始化*/
	TTYPE_DOWNKEY,				  	  /*下载密钥*/
	TTYPE_PINPADAUTH,				  /*双向认证*/
	TTYPE_ONLINEREG,				  /*联机注册*/
	TTYPE_ONLINEREPORT,				  /*联机报到*/
	TTYPE_REPLACEPOS,				  /*换机*/
	TTYPE_TEST,				  		  /*测试*/
	TTYPE_UPDATEAPP,				  /*固件升级*/

	TTYPE_GETDATATYPE,			  	  /*获取基础数据类型*/
	TTYPE_RSATEST,			  	  	  /*RSA测试*/
	TTYPE_TESTSERVER,				  /*测试服务器*/
	TTYPE_TCPSERVER1,			  	  /*TCP服务器*/

	TTYPE_TESTHTTP,			  		  /*HTTP交易测试*/

	TTYPE_EMAIL,			  		  /*发送邮件*/

	TTYPE_FTP_DOWNLOADFILE,			  /*FTP下载文件*/
	TTYPE_FTP_UPLOADFILE,			  /*FTP上传文件*/
	
	TTYPE_MAX_TRANTYPE,
} TRANSTYPE;



#ifdef __cplusplus   
}  

#endif

#endif





