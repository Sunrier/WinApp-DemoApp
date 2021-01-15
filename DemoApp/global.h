/*************************************************************************************************
	FileName : global.h
    FileFunc : ʵ��ȫ����Ϣͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-08-05 11:13:15
    Descp    : ����Ӧ��ȫ����Ϣ
    History  : None
*************************************************************************************************/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define DEBUG_DISP
#define DEBUG        					__FILE__,__LINE__



/*Ӧ�������Ϣ*/
#define GLOBAL_APPNAME   				"DEMOAPP"		/*Ӧ����*/
#define	GLOBAL_APPCOMMSECNAME			"COMM"			/*Ӧ��ͨѶ��������*/

/*Ӧ���޹���Ϣ*/
#define APP_MAXBUFFER					2048	/*��󻺳���*/
#define APP_TIMER_SEC					(60*1)	/*��ʱ��ʱʱ�� 1����*/
#define APP_WAITTIME					(60*1)	/*��ʱ�ȴ��û�������ʱʱ�� 1����*/

#define APP_MAXCOMMBUF           		(4096*2)

#define GLOBAL_DEFAULTCONFIGPATH		".\\CONFIG\\"				/*�����ļ�Ĭ��·��*/
#define GLOBAL_CONFIGFILENAME			GLOBAL_APPNAME ".ini"		/*Ӧ�������ļ���*/

#define	GLOBAL_DEFAULTLOGPATH			".\\LOG\\"					/*LOG��־Ĭ��·��*/
#define	GLOBAL_LOGFILENAME				GLOBAL_APPNAME "_LOG"		/*LOG��־�ļ���ǰ׺*/
#define	GLOBAL_LOGSECNAME				GLOBAL_APPNAME "LOG"		/*LOG��־��������*/
#define GLOBAL_TRACELOGFILENAME			"TRACE"						/*���ٵĵ�����Ϣ*/

#define APP_ALIGNWIDTH					(58)

/*APP*/
#define APP_NAME						GLOBAL_APPNAME
#define APP_FUNCTION					GLOBAL_APPNAME "Ӧ�����"
#define APP_VERSION						"00.00.01"
#define APP_AUTHOR						"Sunrier"
#define APP_CONTACT						"Sunrier@163.com"
#define APP_DATE						"2013-06-08 10:26:10"
#define APP_DESCPTION					"ʵ�����"


/*��־����-LOG_OFF>LOG_ERROR>LOG_WARN>LOG_INFO>LOG_DEBUG>LOG_ALL*/
typedef enum _LOG_LEVEL
{
	LOG_OFF  	= 0x00,	/*�ر�������־��¼-��߼���*/
	LOG_ERROR	= 0x01,	/*����Ӧ�ó��������з����Ĵ�����Ϣ*/
	LOG_WARN	= 0x02,	/*����Ӧ�ó��������з����ľ�����Ϣ*/
	LOG_INFO 	= 0x03,	/*����Ӧ�ó������й���*/
	LOG_DEBUG 	= 0x04,	/*�򿪵�����־*/
	LOG_ALL 	= 0x05, /*��������־��¼*/
	LOG_MAX,
}LOG_LEVEL;


/*AppӦ�ýṹ����*/
typedef struct {
	unsigned char ucOverFlag;				/*������־*/
	unsigned long ulStartTimer;				/*��ʱ��ʼʱ��*/
	unsigned long ulEndTimer;				/*��ʱ����ʱ��*/
	unsigned char ucTimeOutFlag;			/*��ʱ��־*/
	unsigned char ucCNTipFlag;				/*������ʾ��Ϣ��־:0-Ӣ����ʾ 1-������ʾ*/
	unsigned char ucLogLevel;				/*��־����,���汨�ı�־:0-��������ص�����Ϣ ��0-������ص�����Ϣ,��־����-LOG_OFF>LOG_ERR>LOG_INFO>LOG_DEBUG>LOG_ALL*/
	unsigned char ucDispFlag;				/*��ʾ���ı�־:0-����ʾ��ص�����Ϣ 1-��ʾ��ص�����Ϣ*/
	unsigned char ucUserNameLen;			/*�û�������*/
	unsigned char aucUserName[15+1];		/*�û���*/
	unsigned char ucFirstRun;				/*��һ��������־	0-��һ������ ����-�Ѿ�����*/
	unsigned char aucTitle[64+1];			/*����*/
	unsigned char aucCurrDate[8+1];			/*��ǰ����*/
	unsigned char ucLastRunNodeFlag;		/*��һ�����жϵ���*/
	unsigned char aucLastRunData[8+1];		/*��һ����������*/
	unsigned char aucCfgFileName[64+1];		/*�����ļ���*/
	unsigned char ucLogFileFlag;			/*��־LOG�ļ���־:0-�̶��ļ� 1-�Զ����ļ�*/
	unsigned char aucLogFileName[64];		/*�Զ���LOG��־�ļ���*/
	unsigned char ucCommFlag;				/*0-Ĭ��ϵͳ�ļ��еĴ�ͨѶ��Ϣ 1-�����ļ��л�ȡ*/
	unsigned char aucDefTmpPath[512+1];		/*�Զ���Ĭ����ʱĿ¼*/
	unsigned char aucDefTmpFile[512+1];		/*�Զ���Ĭ����ʱ�ļ�*/
	unsigned char ucAppFlag;				/*Ӧ�ñ�־*/
}App_Prm;

typedef struct {
	unsigned short  usRS232Timeout;	    		/*����ͨѶ��ʱ(S)*/
	unsigned short  usTcpTimeout;       		/*TCP��ʱʱ��(S)*/
	unsigned short  usSSLTimeout;       		/*SSL��ʱʱ��(S)*/
	unsigned short  usTcpServerTimeout; 		/*TCP��������ʱʱ��(S)*/
	unsigned short  usTcpServerBlockTimeout; 	/*TCP����������ʱ��ʱʱ��(S)*/
	unsigned short  usFTPServerTimeout; 		/*��ΪFTP��ʱʱ��(S)*/
	
	unsigned short  usSSLHostPort1;     		/*SSL HostPort1*/
	unsigned short  usSSLHostPort2;     		/*SSL HostPort2*/
	unsigned short  usTCPHostPort1;    			/*TCP HostPort1*/
	unsigned short  usTCPHostPort2;    			/*TCP HostPort2*/

	unsigned short  usTCPServerPort1;   		/*TCP Server Port1*/
	unsigned short  usTCPServerPort2;   		/*TCP Server Port2*/

	unsigned short usFTPServerPort1;			/*��ΪFTP Server�����˿�1*/
	unsigned short usFTPServerPort2;			/*��ΪFTP Server�����˿�2*/
	
	//����/TCP
	unsigned char ucCurrentCommMode;        	/*��ǰͨѶģʽ*/
	unsigned char ucRetrys;                 	/*���Դ���*/

	//���²���Ϊ��������
	unsigned char aucLocalIP[16];              	/*������ַ*/
	unsigned char aucSubNetMask[16];           	/*����MASK*/
	unsigned char aucGateWay[16];              	/*����*/
	unsigned char aucPriDNS[16];               	/*DNS1*/
	unsigned char aucSecDNS[16];               	/*DNS2*/

	// FTP
	unsigned char aucFTPLocalIP[16];			/*��ΪFTP����IP��ַ*/

	// HTTP���
	unsigned char aucHttpURL[256+1];		/*HTTP������URL1*/
	unsigned char aucHttpDomain[64+1];		/*HTTP������Domain*/
	unsigned char aucHttpPage[64+1];		/*HTTP������Page1*/
	//unsigned char aucHttpIP1[16];			/*HTTP������IP1*/
	//unsigned char aucHttpIP2[16];			/*HTTP������IP2*/

	// HTTPS���
	unsigned char aucHttpsURL[256+1];			/*HTTPS������URL1*/
	unsigned char aucHttpsDomain[64+1];			/*HTTPS������Domain*/
	unsigned char aucHttpsPage[64+1];			/*HTTPS������Page1*/
	//unsigned char aucHttpsIP1[16];			/*HTTPS������IP1*/
	//unsigned char aucHttpsIP2[16];			/*HTTPS������IP2*/

	// TCP
	unsigned char aucTCPIP1[16];				/*TCP Host IP1*/
	unsigned char aucTCPIP2[16];				/*TCP Host IP2*/
	
	unsigned char aucTCPDomainName1[64+1];		/*TCP Host ����1*/
	unsigned char aucTCPDomainName2[64+1];		/*TCP Host ����2*/

	// TCP Server
	unsigned char aucTCPServerIP1[16];			/*TCP������IP1*/
	unsigned char aucTCPServerIP2[16];			/*TCP������IP2*/

	// FTP
	unsigned char aucFTPServerIP1[16];			/*��ΪFTP ������IP1*/
	unsigned char aucFTPServerIP2[16];			/*��ΪFTP ������IP2*/

	unsigned char aucFTPHostName1[128+1];		/*Windows FTP����������1*/
	unsigned char aucFTPHostName2[128+1];		/*Windows FTP����������2*/

	unsigned char aucFTPUserName[256+1];		/*FTP�û���*/
	unsigned char aucFTPUserPassword[256+1];	/*FTP�û�����*/

	unsigned char aucFTPLocalPath[256+1];		/*FTP����Ŀ¼*/
	unsigned char aucFTPRemotePath[256+1];		/*FTPԶ��Ŀ¼*/
	unsigned char aucFTPFileType[1+1];			/*FTP�ļ�����(ASCII-A/BIN-I/EBCD-E,Ĭ��BIN-I)*/
	unsigned char ucFTPListType;				/*FTP�ļ������б�����:0-�ļ���Ŀ¼��ϸ 1-�ļ���Ŀ¼���б� 2-ֻ�����ļ��� 3-ֻ����Ŀ¼�� 4-ֻ�����ļ�����Ŀ¼�� ����-ֻ�����ļ���*/
	unsigned char ucFTPFileNullFlag;			/*FTP�ļ�Ϊ���Ƿ�֧�ֱ�־:0-��֧�� 1-֧��*/
	unsigned char ucFTPUploadTmpFileFlag;		/*FTP�ļ��ϴ��Ƿ�֧��tmp�ļ���־:0-��֧�� 1-֧��*/
	unsigned char ucFTPDelRemoteFileFlag;		/*FTPԶ���ļ�ɾ����־:0-��ɾ�� 1-ɾ��*/
	
	unsigned int uiCommPort;				/*���ں�*/
	unsigned int uiBaudRate;				/*������*/

	
	unsigned char ucDomainNameFlag;			/*ͨѶ�Ƿ�ʹ��������־*/
	unsigned char ucFTPHostNameFlag;		/*FTP�Ƿ�ʹ�����������������IP:0-�� 1-��*/
	unsigned char ucBakCommFlag;			/*ͨѶ�Ƿ�ʹ�ñ�����־*/
	unsigned char ucSSLFlag;				/*ͨѶ�Ƿ�SSL*/
	unsigned char ucFTPSockBakFlag;			/*FTP����ͨѶ�Ƿ�֧��:0-��֧�� 1-֧��*/

	unsigned char ucCommFlag;				/*��ǰͨѶ��־ 0-���� 1-���� 2-���� 3-HTTP 4-HTTPS*/
	unsigned char ucSelfProtocolFlag;		/*http��httpsЭ��ʱ�Ƿ�֧�ֿ��Э��: 0-��֧�� 1-֧��*/
	unsigned char ucRequestWayFlag;			/*http��https�����󷽷�:0-Post���� 1-Get����,Ĭ��0*/
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
    //���ݰ����Բ���
    unsigned char        ucAppType;                          /*Ӧ������*/
    unsigned char        aucMisTraceID[6+1];                 /*MISPOSΨһ��ʶ(MISPOS��ˮ��)*/
    
    //����ָ��Բ���
    unsigned char        aucCmdCode[2+1];                    /*ָ�����*/
    unsigned char        aucMPMerchantCode[15+1];            /*�̻���*/
    unsigned char        aucMPTerminalCode[8+1];             /*�ն˺�*/
    unsigned char        aucMPMerchantNameChn[60+1];         /*�̻�������*/
    unsigned char        aucMPMerchantNameEng[60+1];         /*�̻�Ӣ����*/
    unsigned char        aucMPCashierNo[15+1];               /*��̨��*/
    unsigned char        aucMPOperNo[15+1];                  /*����Ա��*/
    unsigned char        aucMPSysTraceNo[20+1];              /*������ˮ��*/
	unsigned char		 aucMPOrderNum[64+1];				 /*�������*/

	unsigned char		 ucAppFlag;							 /*Ӧ�ñ�־*/
	unsigned char		 ucEnFlag;							 /*�Ƿ���� 0-������ ����-����*/
	
	//unsigned char        ucTimeOut;                        /*������ʱʱ��*/
	//unsigned char        ucIsListen;                       /*�Ƿ�ʼ����,  0-��1-��*/
	unsigned char 		 ucMisTranFlag;						 /*��ǰMIS���ױ�־ 0-�� 1-��*/
	unsigned char        ucTransType;						 /*��ǰMIS��������*/
	unsigned char 		 aucAmount[12 + 1];     			 /*���׽��*/
	unsigned char        aucOrgSysTraceNo[6+1];				 /*ԭʼƾ֤��*/
	unsigned char        aucOrgRefNo[12+1];				 	 /*ԭʼ�ο���*/
	unsigned char        aucOrgAuthNo[6+1];				 	 /*ԭ��Ȩ��*/
	unsigned char        aucOrgDate[4+1];				 	 /*ԭʼ����MMDD*/
	unsigned char		 aucOrgCardNum[19+1];				 /*ԭ����*/
	unsigned char 		 aucOrgExpDate[4+1];				 /*ԭ������Ч��*/
	unsigned char		 ucCardInputMode;					 /*�������뷽ʽ 0-Ĭ�� 1-�ֹ�����*/
	unsigned char		 ucCmdFlag;							 /*ָ���־ 0-��Ӳ�ѯ��־ 1-��ǰִ�е�ָ���־*/
	unsigned char		 ucSSLFlag;							 /*�Ƿ�SSLͨѶ��־,SSLͨѶ��Ҫ����*/
	unsigned char		 ucSSLAuthTimes;					 /*SSLͨѶ��֤����,2����֤��һ���������̲���Ͽ�����*/
	unsigned char 		 ucCommFlag;						 /*ͨѶ��־ 0-���� 1-���� 2-SSL 3-HTTP 4-HTTPS*/
	unsigned char        ucDataFormat;						 /*���ݸ�ʽ*/
	unsigned char        ucAckNak;						 	 /*��������Ӧ*/
	unsigned char        ucReLinkFlag;						 /*������־*/
	unsigned char        ucTimeoutFlag;						 /*��ʱ��־*/
	unsigned char        ucSupportEscFlag;					 /*����֧��ȡ����־ 0-��֧�� 1-֧��*/
	unsigned char		 ucLoopTimes;						 /*����֧��ȡ��ʱѭ������*/
	unsigned char		 ucProjFlag;						 /*��ǰ��Ŀ��־ 0-��׼��Ŀ*/
	unsigned short       usTimeout;						 	 /*��ʱʱ��*/
	
}Trans_Prm;

/*Ӧ��ʧ�ܵķ��ش�����Ϣ��*/
typedef enum
{
	APP_SUCCESS 	= 0x00,	/*�ɹ�*/
	APP_FAILURE,			/*ʧ��*/
	APP_TIMEOUT,			/*��ʱ*/
	APP_ESC,				/*�û�ȡ��*/
	APP_PARAMERROR,			/*�����������*/
	APP_EXIT,    			/*�˳�*/
	
	APP_HEADLENFAIL = 0x30,	/*����ͷ������ʧ��*/
    APP_STXERROR,			/*�������ݵĿ�ʼ��־����*/
 	APP_ETXERROR,			/*���յĽ�����־����*/
	APP_LENGTHERROR,		/*���յ����ݳ��ȴ���*/
	APP_LRCERROR,			/*���յ�����У����LRC����*/
	APP_SENDFAIL,			/*��������ʧ��*/
	APP_SENDOVERLIMIT,		/*�������ݳ����������*/
	APP_RECVFAIL,			/*��������ʧ��*/
	APP_RECVDATAERROR,		/*���յ����ݳ��Ⱥ��������յ����ݳ��Ȳ�һ��*/
	APP_COMMTYPEINVALID, 	/*ͨѶ������Ч,��������*/
	APP_COMMFORMATINVALID, 	/*ͨѶ��ʽ��Ч,��������*/
	APP_MAXCODE,
}APP_CODE;

#if 0
/*ͨѶ��־*/
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

/*ͨѶ��ʽ*/
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

/*ͨѶ��ʱ��־*/
typedef enum
{
	TIMEOUT_RS232 = 0,
	TIMEOUT_TCP,
	TIMEOUT_SSL,
	TIMEOUT_SCAN,
	TIMEOUT_ESC,
}TimeOutFlag;

/*��������--ע��ͬMsg��һ��*/
typedef enum __TransType
{
	TTYPE_LOGON = 1,                  /*POSǩ��*/
	TTYPE_LOGOUT,                     /*POSǩ��*/
	TTYPE_LOGON_CASHIER,              /*����Ա����ǩ��*/
	TTYPE_SETTLE,                     /*����*/
	TTYPE_SETTLE_END,                 /*�������*/ 
	TTYPE_BATCH_UPLOAD,               /*������*/
	TTYPE_SCRIPTADVICE,               /*�����д���ű����֪ͨ*/
	TTYPE_ICOFFLINE_UPLOAD,           /*IC���ѻ���������*/
	TTYPE_TC_UPLOAD,                  /*IC����������*/
	TTYPE_TC_UPLOAD_END,              /*IC�����������������*/
	TTYPE_DOWNLOAD_PARAMETERS,        /*��������(����)*/
	TTYPE_QPS_PARAMETERS_DOWNLOAD,    /*QPS�ǽӲ�������*/
	TTYPE_UPLOAD_STATUS,              /*״̬����(�����������ѯ)*/
	TTYPE_ECHO_TESTING,				  /*�������*/
	TTYPE_DOWNLOAD_END,               /*�������ؽ���*/

	TTYPE_BALANCE,                    /*����ѯ*/
	TTYPE_SALE,                       /*����*/
	TTYPE_SALE_VOID,                  /*���ѳ���*/
	TTYPE_REFUND,                     /*�˻�*/

	TTYPE_PREAUTH,                    /*Ԥ��Ȩ*/
	TTYPE_PREAUTH_VOID,               /*Ԥ��Ȩ����*/
	TTYPE_COMPLETE,                   /*Ԥ��Ȩ�������(����)*/
	TTYPE_COMPLETE_VOID,              /*Ԥ��Ȩ��ɳ���*/
	TTYPE_OFFLINE_COMPLETE,           /*Ԥ��Ȩ���֪ͨ(����)*/

	TTYPE_OFFLINE_SETTLE,             /*���߽���(�ѻ�)*/
	TTYPE_OFFLINE_ADJUST,             /*�������(�ѻ�)*/
	
	TTYPE_ECASH_BALANCE,              /*�����ֽ�����*/
	TTYPE_ECASH_CASH_RELOAD,          /*�����ֽ��ֽ��ֵ*/ 
	TTYPE_ECASH_CASH_RELOAD_VOID,     /*�����ֽ��ֽ��ֵ����*/ 
	TTYPE_ECASH_IN_RELOAD,            /*�����ֽ�ָ���˻�Ȧ��*/
	TTYPE_ECASH_OUT_RELOAD,           /*�����ֽ��ָ���˻�Ȧ��*/ 
	TTYPE_ECASH_REFUND,               /*�����ֽ��ѻ������˻�*/
	
	TTYPE_MAG_ACCT_VERIFY,            /*�������ֽ��ֵ�˻���֤*/
	TTYPE_MAG_CASHLOAD,               /*�������ֽ��ֵ*/
	TTYPE_MAG_CASHLOAD_CONFIRM,       /*�������ֽ��ֵȷ��*/ 
	TTYPE_MAG_ACCTLOAD,               /*�������˻���ֵ*/
	
	TTYPE_INSTALLMENT,                /*���ڸ���*/
	TTYPE_INSTALLMENT_VOID,           /*���ڸ����*/
	
	TTYPE_YUYUE_SALE,                 /*ԤԼ����*/
	TTYPE_YUYUE_SALE_VOID,            /*ԤԼ���ѳ���*/ 
	TTYPE_YUYUE_REFUND,               /*ԤԼ�˻�*/

	TTYPE_ISSUER_SCORE_SALE,          /*�����л�������*/
	TTYPE_ISSUER_SCORE_SALE_VOID,     /*�����л��ֳ���*/
	TTYPE_UNION_SCORE_SALE,           /*���˻�������*/
	TTYPE_UNION_SCORE_SALE_VOID,      /*���˻��ֳ���*/
	TTYPE_UNION_SCORE_BALANCE,        /*���˻��ֲ�ѯ*/
	TTYPE_UNION_SCORE_REFUND,         /*���˻����˻�*/ 

	TTYPE_MCHIP_BALANCE,              /*�ֻ�оƬ����ѯ*/ 
	TTYPE_MCHIP_SALE,                 /*�ֻ�оƬ����*/
	TTYPE_MCHIP_SALE_VOID,            /*�ֻ�оƬ���ѳ���*/ 
	TTYPE_MCHIP_REFUND,               /*�ֻ�оƬ�˻�*/ 
	TTYPE_MCHIP_PREAUTH,              /*�ֻ�оƬԤ��Ȩ*/ 
	TTYPE_MCHIP_PREAUTH_VOID,         /*�ֻ�оƬԤ��Ȩ����*/ 
	TTYPE_MCHIP_COMPLETE,             /*�ֻ�оƬԤ��Ȩ�������(����)*/ 
	TTYPE_MCHIP_COMPLETE_VOID,        /*�ֻ�оƬԤ��Ȩ��ɳ���*/ 
	TTYPE_MCHIP_OFFLINE_COMPLETE,     /*�ֻ�оƬԤ��Ȩ���֪ͨ(����)*/

	TTYPE_ORDER_CARDHOLDER_VERIFY,    /*�������׳ֿ��������֤*/
	TTYPE_ORDER_SALE,                 /*��������*/
	TTYPE_ORDER_SALE_VOID,            /*�������ѳ���*/ 
	TTYPE_ORDER_REFUND,               /*�����˻�*/ 
	TTYPE_ORDER_PREAUTH,              /*����Ԥ��Ȩ*/ 
	TTYPE_ORDER_PREAUTH_VOID,         /*����Ԥ��Ȩ����*/ 
	TTYPE_ORDER_COMPLETE,             /*����Ԥ��Ȩ�������(����)*/ 
	TTYPE_ORDER_COMPLETE_VOID,        /*����Ԥ��Ȩ��ɳ���*/
	TTYPE_ORDER_OFFLINE_COMPLETE,     /*����Ԥ��Ȩ���֪ͨ(����)*/ 

	TTYPE_AID_INQUERY,                /*��ѯAID INDEX LIST*/
	TTYPE_AID_UPDATE,                 /*����AID����*/
	TTYPE_AID_END,                    /*����AID���*/
	TTYPE_CAKEY_INQUERY,              /*��ѯCAPK INDEX LIST*/
	TTYPE_CAKEY_UPDATE,               /*���¹�Կ*/
	TTYPE_CAKEY_END,                  /*���¹�Կ���*/
	TTYPE_BLACK_UPDATE,               /*���º���������*/
	TTYPE_BLACK_END,                  /*���º��������*/
	TTYPE_TMS_UPDATE_PARAMETER,       /*����TMS*/
	TTYPE_REVERSAL,                   /*����*/

	TTYPE_LINK,						  /*���Ӳ��Խ���*/
	TTYPE_CANCEL,					  /*ȡ������*/
	TTYPE_GETBATTERY,				  /*��ȡ����*/
	TTYPE_GETAPPVER,				  /*��ȡĳ��Ӧ�ð汾*/
	TTYPE_GETAPPINFO,			  	  /*��ȡӦ����Ϣ*/
	TTYPE_GETPARAM,					  /*��ȡ����*/
	TTYPE_SETPARAM,				      /*���ò���*/
	TTYPE_BARSCAN,				      /*��ȡɨ����Ϣ*/
	TTYPE_BARCLOSE,				      /*�ر�ɨ��*/
	TTYPE_SETRSAKEY,				  /*����RSA��ԿKEY*/
	TTYPE_GETCARDINFO,				  /*��ȡˢ����Ϣ*/
	TTYPE_TRANS_INQUIRY,			  /*���ײ�ѯ*/
	TTYPE_GETPRINTINFO,				  /*ȡ������Ϣ��ӡ*/
	TTYPE_GETREPRINTINFO,			  /*ȡ������Ϣ���ش�ӡ*/
	TTYPE_GETSETTLEINFO,			  /*ȡ������Ϣ��ӡ*/
	TTYPE_GETRESETTLEINFO,			  /*ȡ������Ϣ���ش�ӡ*/
	TTYPE_ORDER_INQUIRY,			  /*������ѯ����*/
	TTYPE_ACTIVATE,			  	  	  /*�������*/
	TTYPE_INACTIVATE,			  	  /*�����������*/
	TTYPE_CARDQUERY,			  	  /*��״̬��ѯ����*/
	TTYPE_NOTICEINFO,				  /*֪ͨ��Ϣ����*/
	TTYPE_POSINIT,				  	  /*��װ����ʼ��*/
	TTYPE_DOWNKEY,				  	  /*������Կ*/
	TTYPE_PINPADAUTH,				  /*˫����֤*/
	TTYPE_ONLINEREG,				  /*����ע��*/
	TTYPE_ONLINEREPORT,				  /*��������*/
	TTYPE_REPLACEPOS,				  /*����*/
	TTYPE_TEST,				  		  /*����*/
	TTYPE_UPDATEAPP,				  /*�̼�����*/

	TTYPE_GETDATATYPE,			  	  /*��ȡ������������*/
	TTYPE_RSATEST,			  	  	  /*RSA����*/
	TTYPE_TESTSERVER,				  /*���Է�����*/
	TTYPE_TCPSERVER1,			  	  /*TCP������*/

	TTYPE_TESTHTTP,			  		  /*HTTP���ײ���*/

	TTYPE_EMAIL,			  		  /*�����ʼ�*/

	TTYPE_FTP_DOWNLOADFILE,			  /*FTP�����ļ�*/
	TTYPE_FTP_UPLOADFILE,			  /*FTP�ϴ��ļ�*/
	
	TTYPE_MAX_TRANTYPE,
} TRANSTYPE;



#ifdef __cplusplus   
}  

#endif

#endif





