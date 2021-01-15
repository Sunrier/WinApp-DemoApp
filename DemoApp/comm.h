/*************************************************************************************************
	FileName : comm.h
    FileFunc : ʵ��Ӧ�ò�ͨѶ�⺯���ӿ�ͷ�ļ�
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2011-03-05 19:13:15
	Descp    : ʵ��Ӧ��ͨѶ��
    History  : None
	Other    : None
*************************************************************************************************/
#ifndef __COMM_H__
#define __COMM_H__

#ifdef __cplusplus   
#define	EXPORT	extern "C"	__declspec(dllexport)
#else
#ifndef EXPORT
#define EXPORT __declspec(dllexport)
#endif
#endif

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

/*����ͨѶ�˿ں�*/
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
	COM9,
	COM10
}COMM_PORT;

/*����ͨѶ������*/
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
}COMM_BAUDRATE;

/*ͨѶ��ʽ*/
typedef enum
{
	COMM_FMT_NOFMT = 0,					/*�޸�ʽ:Data*/
	COMM_FMT_ASCLEN_DATA,				/*4λ����(Asc)+����:AscLen(4λ)+Data(Lenλ)*/
	COMM_FMT_HEXLEN_DATA,				/*2λ����(Hex)+����:HexLen(2λ)+Data(Lenλ)*/
	COMM_FMT_STX_HEXLEN_DATA_ETX_LRC,	/*STX+2λ����(Hex)+����+ETX+LRC:STX(1λ)+HexLen(2λ)+Data(Lenλ)+ETX(1λ)+LRC(1λ)*/
	COMM_FMT_STX_HEXLEN_DATA_LRC_ETX,	/*STX+2λ����(Hex)+����+LRC+ETX:STX(1λ)+HexLen(2λ)+Data(Lenλ)+LRC(1λ)+ETX(1λ)*/
	COMM_FMT_STX_DATA_ETX_LRC,			/*STX+����+ETX+LRC:STX(1λ)+Data(Lenλ)+ETX(1λ)+LRC(1λ)*/
	COMM_FMT_STX_DATA_LRC_ETX,			/*STX+����+LRC+ETX:STX(1λ)+Data(Lenλ)+LRC(1λ)+ETX(1λ)*/
}COMM_FMT;

/***********************************************************************************************
	FuncName : Comm_InitCfg
	FuncFunc : ��ʼ��ͨѶ������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitCfg( void );

/***********************************************************************************************
	FuncName : Comm_InitLib
	FuncFunc : ��ʼ�������
	Input	 : unsigned char	�� ucCNTipFlag,������ʾ��Ϣ��־:0-Ӣ����ʾ ��0-������ʾ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitLib(unsigned char ucCNTipFlag);

/***********************************************************************************************
	FuncName : Comm_InitComm
	FuncFunc : ��ʼ������ͨѶ����
	Input	 : unsigned int		�� uiCommPort,���ں�
	           unsigned int		�� uiBaudRate,������
	           unsigned short	�� usRecvTimeout,�������ݳ�ʱʱ��(S)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitComm(unsigned int uiCommPort,unsigned int uiBaudRate,unsigned short usRecvTimeout);

/***********************************************************************************************
	FuncName : Comm_InitSock
	FuncFunc : ��ʼ������ͨѶ����
	Input	 : unsigned char *	�� pucHostIP,����IP
	           unsigned short	�� usHostPort,�����˿�
	           unsigned char	�� ucSockBakFlag,�Ƿ�֧�ֱ���
	           unsigned char *	�� pucBakHostIP,����IP
	           unsigned short	�� usBakHostPort,�����˿�
	           unsigned char	�� ucHostNameFlag,�Ƿ�ʹ�����������������IP 
	                                              0-ʹ�������򱸻���IP
	                                              1-ʹ������������� 
	           unsigned char *	�� pucHostName,���������������
	           unsigned char *	�� pucBakHostName,���������������
	           unsigned char    �� ucSelfHttpProtocolFlag,httpͨѶʱ�Ƿ�֧�ֿ��Э��:0-��֧�� ��0-֧��
	           unsigned char *  �� pucHttpUrl,http��URL,��ucSelfHttpProtocolFlag=1ʱ��Ч
	           unsigned char 	�� ucHttpRequestWayFlag,http�����󷽷�,0-Post���� 1-Get����
	           unsigned char *  �� pucDownloadFilePath,http�����ļ�Ŀ¼
	           unsigned char *  �� pucDownloadFileName,http�����ļ���
	           unsigned char *	�� pucServerIP,��Ϊ������ʱ�ı���IP:��Ϊ��ʱ�����ַ
	           unsigned short   �� usServerListenPort,��Ϊ������ʱ�ļ����˿�
	           unsigned long    �� ulServerBlockTimeout,��Ϊ����������ʱ��(S):0-������ ��0-����ʱ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : ��ʱʱ��(S)
	History  : None
	Other    : ucSelfHttpProtocolFlag - �ڰ�λ0x01 http�Ƿ�֧��URL�Խ���
										����λ0x02 http�Ƿ�֧��URL�Խ���ʧ�ܺ���Host IP/Name
										����λ0x04 http�Ƿ�֧�ֿ��Э��
										����λ0x08 http�Ƿ���յİ��Խ���
										����λ0x10 http���յİ�����Ϊ�ļ�
										����λ0x20 Ԥ��
										�ڶ�λ0x40 Ԥ��
										��һλ0x50 Ԥ��
*************************************************************************************************/
EXPORT unsigned char Comm_InitSock(unsigned char *pucHostIP,unsigned short usHostPort,unsigned char ucSockBakFlag,unsigned char *pucBakHostIP,unsigned short usBakHostPort,unsigned char ucHostNameFlag,unsigned char *pucHostName,unsigned char *pucBakHostName,unsigned char ucSelfHttpProtocolFlag,unsigned char *pucHttpUrl,unsigned char ucHttpRequestWayFlag,unsigned char *pucDownloadFilePath,unsigned char *pucDownloadFileName,unsigned char *pucServerIP,unsigned short usServerListenPort,unsigned long ulServerBlockTimeout);

/***********************************************************************************************
	FuncName : Comm_InitSSL
	FuncFunc : ��ʼ��SSL����ͨѶ����
	Input	 : unsigned char *	�� pucSSLHostIP,SSL����IP
	           unsigned short	�� usSSLHostPort,SSL�����˿�
	           unsigned char	�� ucSSLBakFlag,�Ƿ�֧��SSL����
	           unsigned char *	�� pucBakSSLHostIP,SSL����IP
	           unsigned short	�� usBakSSLHostPort,SSL�����˿�
	           unsigned char	�� ucSSLHostNameFlag,SSL�Ƿ�ʹ�����������������IP 
	                                              	0-SSLʹ�������򱸻���IP
	                                              	1-SSLʹ������������� 
	           unsigned char *	�� pucSSLHostName,SSL���������������
	           unsigned char *	�� pucBakSSLHostName,SSL���������������
	           unsigned char 	�� ucSSLMethodType,�ͻ���SSLЭ������:1-SSLv2 2-SSLv3 3-SSLv23 4-TLSv1 5-DTLSv1 ����-SSLv23
	           unsigned char	�� ucIsVerifyCA,�Ƿ���֤CA֤��:0-����֤ 1-��֤
			   unsigned char	�� ucChainDepth,CA֤��Ѱַ��Ŀ¼���ָ��:0-��У��CA 1-1��CA֤�� 2-2��CA֤��
			   unsigned char *	�� pucCACertFile,�ͻ���CA��Կ�ļ����λ�ú��ļ���
			   unsigned char	�� ucServerVerifyType, 0-��У������֤��:1-������Ҫ��֤�Է�,˫����֤ 2-��������ͻ�������֤�� 3-�ͻ�����Ҫ��֤�Է�,������������Ҫ������֤
			   unsigned char    �� ucCertFileType,֤���ļ����ͱ����ʽ�����ʽ:1-SSL_FILETYPE_PEM 2-SSL_FILETYPE_ASN1 3-SSL_FILETYPE_P12
			   unsigned char *	�� pucCACertFile,�ͻ�����֤֤����λ�ú��ļ���
			   unsigned char *	�� pucClPrivateKey,�ͻ���˽Կ���λ�ú��ļ���
			   unsigned char *	�� pucPKeyPassword,�ͻ���˽Կ����
			   unsigned char    -  ucSelfHttpsProtocolFlag,httpsͨѶʱ�Ƿ�֧�ֿ��Э���־:0-��֧�� ��0-֧��
	           unsigned char *  -  pucHttpsUrl,https��URL,��ucSelfHttpsProtocolFlag=1ʱ��Ч
	           unsigned char 	-  ucHttpsRequestWayFlag,https�����󷽷�,0-Post���� 1-Get����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : ��ʱʱ��(S)
	History  : None
	Other    : ucSelfHttpsProtocolFlag - �ڰ�λ0x01 https�Ƿ�֧��URL�Խ���
										 ����λ0x02 https�Ƿ�֧��URL�Խ���ʧ�ܺ���Host IP/Name
										 ����λ0x04 https�Ƿ�֧�ֿ��Э��
										 ����λ0x08 https�Ƿ���յİ��Խ���
										 ����λ0x10 Ԥ��
										 ����λ0x20 Ԥ��
										 �ڶ�λ0x40 Ԥ��
										 ��һλ0x80 Ԥ��
*************************************************************************************************/
EXPORT unsigned char Comm_InitSSL(unsigned char *pucSSLHostIP,unsigned short usSSLHostPort,unsigned char ucSSLBakFlag,unsigned char *pucBakSSLHostIP,unsigned short usBakSSLHostPort,
								unsigned char ucSSLHostNameFlag,unsigned char *pucSSLHostName,unsigned char *pucBakSSLHostName,
								unsigned char ucSSLMethodType,unsigned char ucIsVerifyCA,unsigned char ucChainDepth,unsigned char *pucCACertFile,
								unsigned char ucServerVerifyType,unsigned char ucCertFileType,unsigned char *pucClCertFile,unsigned char *pucClPrivateKey,
								unsigned char *pucPKeyPassword,unsigned char ucSelfHttpsProtocolFlag,unsigned char *pucHttpsUrl,unsigned char ucHttpsRequestWayFlag);

/***********************************************************************************************
	FuncName : Comm_InitFtp
	FuncFunc : ��ʼ��FTP����ͨѶ����
	Input	 : unsigned char *	�� pucFtpHostIP,FTP����IP
	           unsigned short	�� usFtpHostPort,FTP�����˿�
	           unsigned char	�� ucFtpSockBakFlag,FTP�Ƿ�֧�ֱ���
	           unsigned char *	�� pucFtpBakHostIP,FTP����IP
	           unsigned short	�� usFtpBakHostPort,FTP�����˿�
	           unsigned char	�� ucFtpHostNameFlag,FTP�Ƿ�ʹ�����������������IP 
	                                              0-ʹ�������򱸻���IP
	                                              1-ʹ������������� 
	           unsigned char *	�� pucFtpHostName,FTP���������������
	           unsigned char *	�� pucFtpBakHostName,FTP���������������
	           unsigned char *  �� pucFtpUser,FTP�û���
	           unsigned char *  �� pucFtpUserPassword,FTP�û�����          
	           unsigned char *	�� pucLocalIP,��Ϊ������ʱ�ı���IP:��Ϊ��ʱ�����ַ
	           unsigned short	�� usFtpTimeout,FTP��ʱʱ��(S)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : ��ʱʱ��(S)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitFtp(unsigned char *pucFtpHostIP,unsigned short usFtpHostPort,unsigned char ucFtpSockBakFlag,unsigned char *pucFtpBakHostIP,unsigned short usFtpBakHostPort,unsigned char ucFtpHostNameFlag,unsigned char *pucFtpHostName,unsigned char *pucFtpBakHostName,unsigned char *pucFtpUser,unsigned char *pucFtpUserPassword,unsigned char *pucLocalIP,unsigned short usFtpTimeout);

/***********************************************************************************************
	FuncName : Comm_GetInfoFromUrl
	FuncFunc : ��URL��ȡ������Ϣ
	Input	 : unsigned char *	�� pucInputUrl		�����URL
			   unsigned char 	�� ucNetInfoFlag	�����ȡ����Ϣ��־
	Output	 : unsigned char *	�� pucOutputIP 		���IP��ַ
		       unsigned short *	�� pusOutputPort	����˿�
		       unsigned char *	�� pucOutputDomain	�������
		       unsigned char *	�� pucOutputPage	���Pageҳ��
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2013-12-26 19:12:55
	Descp    : ucNetInfoFlag:	0x01	-	��ȡIP��ַ
								0x02	-	��ȡ�˿�
								0x04	-	��ȡ����
								0x08	-	��ȡPageҳ��
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetInfoFromUrl(unsigned char *pucInputUrl,unsigned char ucNetInfoFlag,unsigned char *pucOutputIP,unsigned short *pusOutputPort,unsigned char *pucOutputDomain,unsigned char *pucOutputPage);

/***********************************************************************************************
	FuncName : Comm_SetHttpParam
	FuncFunc : ���ÿ��http��https����
	Input	 : unsigned char *  �� pucHttpUrl,http��URL,ֻ�ı�HttpURL,�����Ҫ�ı�IP����page��Ҫ���µ���Comm_InitSock��Comm_InitSSL
			   unsigned char	�� ucHttpOrHttpsRequestWayFlag,http��https�����󷽷�:0-Post���� 1-Get����
			   unsigned char	�� ucHttpOrHttpsParseFlag,http��https���յİ��Ƿ��Խ���:0-������ 1-����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : ��֧�ֿ��http��httpsЭ��,http��https�����ȳ�ʼ���ú�������Ч
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SetHttpParam(unsigned char *pucHttpUrl,unsigned char ucHttpOrHttpsRequestWayFlag,unsigned char ucHttpOrHttpsParseFlag);

/***********************************************************************************************
	FuncName : Comm_SetServerParam
	FuncFunc : ���ÿ�ķ���������
	Input	 : unsigned char *	�� pucServerIp,��Ϊ������ʱ�ı���IP:��Ϊ��ʱ�����ַ
			   unsigned short	�� usServerListenPort,��Ϊ������ʱ�ļ����˿�
			   unsigned short	�� usServerBlockTimeout,��Ϊ����������ʱ��(S):0-������ ��0-����ʱ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : TCP Server����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SetServerParam(unsigned char *pucServerIp,unsigned short usServerListenPort,unsigned short usServerBlockTimeout);

/***********************************************************************************************
	FuncName : Comm_CheckConnect
	FuncFunc : ��鴮�ڻ�����
	Input	 : unsigned char	�� ucCommFlag	��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_CheckConnect(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_SendPacket
	FuncFunc : ����ͨѶ���ݰ�
	Input	 : unsigned char	�� ucCommFlag		��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
		       unsigned char	�� ucCommFormat		���뷢�͵�ͨѶ��ʽ,��COMM_FMT��ʽ
			   unsigned char *	�� pucInputData 	���͵�����
		       unsigned int		�� uiInputDataLen	�������ݵĳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SendPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Comm_RecvPacket
	FuncFunc : ����ͨѶ���ݰ�
	Input	 : unsigned char	�� ucCommFlag		��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
		       unsigned char	�� ucCommFormat		������յ�ͨѶ��ʽ,��COMM_FMT��ʽ
	           unsigned long	�� ulTimeOut		������յĳ�ʱʱ��(S)
	Output	 : unsigned char *	�� pucOutputData 	���յ�����
		       unsigned int	 *	�� puiOutputDataLen	�������ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_RecvPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned long ulTimeOut,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_GetHttpData
	FuncFunc : ��ȡHTTP��HTTPS��������
	Input	 : unsigned char	�� ucCommFlag		��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
			   unsigned char *	�� pucInputData		���͵�����
			 : unsigned int	 	�� uiInputDataLen	���͵����ݳ���
	Output	 : unsigned char *	�� pucOutputData 	���յ�����
		       unsigned int	 *	�� puiOutputDataLen	�������ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetHttpData(unsigned char ucCommFlag,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_ParseHttpData
	FuncFunc : ����HTTP��HTTPS��������
	Input	 : unsigned char	�� ucCommFlag		��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
			   unsigned char *	�� pucInputData		���յ�Դ����
			 : unsigned int	 	�� uiInputDataLen	���յ�Դ���ݳ���
	Output	 : unsigned char *	�� pucOutputData 	���յ�����
		       unsigned int	 *	�� puiOutputDataLen	�������ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ParseHttpData(unsigned char ucCommFlag,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_StartServer
	FuncFunc : ����Server����
	Input	 : unsigned char	�� ucCommFlag,��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StartServer(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_CheckServerAccept
	FuncFunc : �ж��Ƿ���յ�һ���ͻ��˵�����
	Input	 : unsigned char	�� ucCommFlag,��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	Output	 : unsigned char *	�� pucOutputRemoteClientIp 		�ͻ���IP��ַ
			   unsigned short*	�� pusOutputRemoteClientPort	�ͻ��˶˿ں�
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_CheckServerAccept(unsigned char ucCommFlag,unsigned char *pucOutputRemoteClientIp,unsigned short *pusOutputRemoteClientPort);

/***********************************************************************************************
	FuncName : Comm_ServerSendPacket
	FuncFunc : server�������ݰ����ͻ���
	Input	 : unsigned char	�� ucCommFlag,��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	           unsigned char	�� ucCommFormat		���뷢�͵�ͨѶ��ʽ,��COMM_FMT��ʽ
			   unsigned char *	�� pucInputData 	���͵�����
		       unsigned int		�� uiInputDataLen	�������ݵĳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����WCOMM_SUCCESS
								�� ʧ��,���ط�WCOMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ServerSendPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Comm_ServerRecvPacket
	FuncFunc : server���տͻ���ͨѶ���ݰ�
	Input	 : unsigned char	�� ucCommFlag		��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
		       unsigned char	�� ucCommFormat		������յ�ͨѶ��ʽ,��COMM_FMT��ʽ
	           unsigned long	�� ulTimeOut		������յĳ�ʱʱ��(S)
	Output	 : unsigned char *	�� pucOutputData 	���յ�����
		       unsigned int	 *	�� puiOutputDataLen	�������ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,����COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ServerRecvPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned long ulTimeOut,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_StopClient
	FuncFunc : �������˶Ͽ��ͻ��˵�����
	Input	 : unsigned char	�� ucCommFlag,��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �������˲���Ͽ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StopClient(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_StopServer
	FuncFunc : �Ͽ�Server����
	Input	 : unsigned char	�� ucCommFlag,��ǰͨѶ��־ 0-���� 1-����(TCP) 2-����(SSL) 3-����HTTP 4-����HTTPS 5-����(UDP)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �Զ��Ͽ��ͻ�������
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StopServer(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_Disconnect
	FuncFunc : �Ͽ����ڻ�����ͨѶ
	Input	 : unsigned char	�� ucDisconnectFlag,�Ͽ�ͨѶ��־:	0-����ͨѶ 1-���� 2-����(TCP) 
																	3-����(SSL) 4-����HTTP 5-����HTTPS
																	6-����(UDP) 7-TCP Server�Ŀͻ��� 
																	8-TCP Server 9-UDP Server�Ŀͻ���
																	10-TCP Server
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� �Ͽ����ڻ�����ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_Disconnect(unsigned char ucDisconnectFlag);

/***********************************************************************************************
	FuncName : Comm_FtpParseList
	FuncFunc : ����FTP���ص��ļ��б�
	Input	 : unsigned char * 	�� pucInputData,������Ϣ
	           unsigned char	�� ucListType,����Ļ�ȡ�б�����:0-�ļ���
	                                                         	 1-�ļ���Ŀ¼��
	                                                         	 2-ֻ�����ļ���
			                                                     3-ֻ����Ŀ¼��
			                                                     4-ֻ�����ļ�����Ŀ¼��
			                                                     ����-ֻ�����ļ���
	Output	 : unsigned char * 	�� pucOutputData,������˺���ļ��б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �ļ�����Ŀ¼��֮����|�ָ�,�ļ���֧�ֿո�
	History  : None
	Other    : ��ucListType=0ʱ,pucInputData��Ϣͨ��LIST -l��ȡ;
			   ��ucListType=1ʱ,pucInputData��Ϣͨ��NLST��ȡ;
			   ��ucListType=2ʱ,pucInputData��Ϣͨ��LIST -l��ȡ;
			   ��ucListType=3ʱ,pucInputData��Ϣͨ��LIST -l��ȡ;
			   ��ucListType=4ʱ,pucInputData��Ϣͨ��LIST -l��ȡ;
*************************************************************************************************/
EXPORT unsigned char Comm_FtpParseList(unsigned char *pucInputData,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpParseListEx
	FuncFunc : ����FTP���ص��ļ��б���Ϣ
	Input	 : unsigned char	�� ucListType,����Ļ�ȡ�б�����:2-�ļ��� 3-Ŀ¼�� 4-�ļ�����Ŀ¼��
	           unsigned char * 	�� pucDetialInfo,�����ļ���Ŀ¼��ϸ��Ϣ
	           unsigned char * 	�� pucListName,�����ļ�����Ŀ¼���б�
	Output	 : unsigned char * 	�� pucOutputData,������˺���ļ��б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����WCOMM_SUCCESS
								�� ʧ��,���ط�WCOMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �ļ�����Ŀ¼��֮����|�ָ�,�ļ�����Ŀ¼��֧�ֿո�
	History  : None
	Other    : pucDetialInfo��Ϣͨ��LIST -l��ȡ;
			   pucListName��Ϣͨ��NLST��ȡ;
*************************************************************************************************/
EXPORT unsigned char Comm_FtpParseListEx(unsigned char ucListType,unsigned char *pucDetialInfo,unsigned char *pucListName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpGetFileList
	FuncFunc : ��ȡFTP ServerĿ¼�б���Ϣ
	Input	 : unsigned char * 	�� pucFtpUser,����FTP Server��¼�û�
	           unsigned char * 	�� pucFtpPassword,����FTP Server��¼�û�������
			   unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
			   unsigned char	�� ucListType,���뷵�ص��б�����:0-����FTP�ļ���Ŀ¼��ϸ 
			                                                     1-����FTP�ļ���Ŀ¼���б�
			                                                     2-ֻ�����ļ���
			                                                     3-ֻ����Ŀ¼��
			                                                     4-ֻ�����ļ�����Ŀ¼��
			                                                     ����-�����ļ���Ŀ¼��ϸ
	Output	 : unsigned char *	�� pucOutputData,���Ŀ¼�б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �ļ�����Ŀ¼��֮����|�ָ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpGetFileList(unsigned char *pucFtpUser,unsigned char *pucFtpPassword,unsigned char *pucRemotePath,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpDownloadFile
	FuncFunc : FTP�ļ�����
	Input	 : unsigned char * 	�� pucLocalPath,���뱾���ļ�Ŀ¼
	           unsigned char * 	�� pucLocalFileName,���뱾���ļ���
	           unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
	           unsigned char * 	�� pucRemoteFileName,����FTP Server���ļ���
	           unsigned char * 	�� pucFileType,����FTP�ļ���������(ASCII-A/BINARY-I/EBCDIC-E,Ĭ��BINARY-I)
	           unsigned char 	�� ucSupportFileNullFlag,���뱾���ļ�Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	           int			 	�� iDelRemoteFileFlag,����FTP�ļ����غ��Ƿ�ɾ��FTP���ļ���־(0-��ɾ�� 1-ɾ��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �����ȵ���Comm_InitFtp
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpDownloadFile(unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
                   unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iDelRemoteFileFlag);

/***********************************************************************************************
	FuncName : Comm_FtpUploadFile
	FuncFunc : FTP�ļ��ϴ�
	Input	 : unsigned char * 	�� pucLocalPath,���뱾���ļ�Ŀ¼
	           unsigned char * 	�� pucLocalFileName,���뱾���ļ���
	           unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
	           unsigned char * 	�� pucRemoteFileName,����FTP Server���ļ���
	           unsigned char * 	�� pucFileType,����FTP�ļ���������(ASCII-A/BINARY-I/EBCDIC-E,Ĭ��BINARY-I)
	           unsigned char 	�� ucSupportFileNullFlag,���뱾���ļ�Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	           int			 	�� iUploadTmpFileFlag,����FTP�ļ��������Ƿ�ʹ����ʱ�ļ���־(0-��ʹ�� 1-ʹ��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �����ȵ���Comm_InitFtp
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpUploadFile(unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
            unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iUploadTmpFileFlag);

/***********************************************************************************************
	FuncName : Comm_FtpGetFileListEx
	FuncFunc : ��ȡFTP ServerĿ¼�б���Ϣ
	Input	 : unsigned char * 	�� pucFtpServerIp,����FTP Server IP��ַ
			   short int	 	�� iFtpServerPort,����FTP Server �˿�PORT
			   unsigned char * 	�� pucFtpUser,����FTP Server��¼�û�
	           unsigned char * 	�� pucFtpPassword,����FTP Server��¼�û�������
			   unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
			   unsigned char	�� ucListType,���뷵�ص��б�����:0-����FTP�ļ���Ŀ¼��ϸ 
			                                                     1-����FTP�ļ���Ŀ¼���б�
			                                                     2-ֻ�����ļ���
			                                                     3-ֻ����Ŀ¼��
			                                                     4-ֻ�����ļ�����Ŀ¼��
			                                                     ����-�����ļ���Ŀ¼��ϸ
	Output	 : unsigned char *	�� pucOutputData,���Ŀ¼�б���Ϣ
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : �ļ�����Ŀ¼��֮����|�ָ�
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpGetFileListEx(unsigned char *pucFtpServerIp,short int iFtpServerPort,unsigned char *pucFtpUser,unsigned char *pucFtpPassword,unsigned char *pucRemotePath,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpDownloadFileEx
	FuncFunc : FTP�ļ�����
	Input	 : unsigned char * 	�� pucFtpServerIp,����FTP Server IP��ַ
			   int			 	�� iFtpServerPort,����FTP Server �˿�PORT
			   unsigned char * 	�� pucFtpUser,����FTP Server��¼�û�
	           unsigned char * 	�� pucFtpPassword,����FTP Server��¼�û�������
	           unsigned char * 	�� pucLocalPath,���뱾���ļ�Ŀ¼
	           unsigned char * 	�� pucLocalFileName,���뱾���ļ���
	           unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
	           unsigned char * 	�� pucRemoteFileName,����FTP Server���ļ���
	           unsigned char * 	�� pucFileType,����FTP�ļ���������(ASCII-A/BINARY-I/EBCDIC-E,Ĭ��BINARY-I)
	           unsigned char 	�� ucSupportFileNullFlag,���뱾���ļ�Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	           int			 	�� iDelRemoteFileFlag,����FTP�ļ����غ��Ƿ�ɾ��FTP���ļ���־(0-��ɾ�� 1-ɾ��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpDownloadFileEx(unsigned char *pucFtpServerIp,int iFtpServerPort,unsigned char *pucFtpUser,unsigned char *pucFtpPassword,
                   unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
                   unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iDelRemoteFileFlag);

/***********************************************************************************************
	FuncName : Comm_FtpUploadFileEx
	FuncFunc : FTP�ļ��ϴ�
	Input	 : unsigned char * 	�� pucFtpServerIp,����FTP Server IP��ַ
			   int			 	�� iFtpServerPort,����FTP Server �˿�PORT
			   unsigned char * 	�� pucFtpUser,����FTP Server��¼�û�
	           unsigned char * 	�� pucFtpPassword,����FTP Server��¼�û�������
	           unsigned char * 	�� pucLocalPath,���뱾���ļ�Ŀ¼
	           unsigned char * 	�� pucLocalFileName,���뱾���ļ���
	           unsigned char * 	�� pucRemotePath,����FTP Server���ļ����Ŀ¼
	           unsigned char * 	�� pucRemoteFileName,����FTP Server���ļ���
	           unsigned char * 	�� pucFileType,����FTP�ļ���������(ASCII-A/BINARY-I/EBCDIC-E,Ĭ��BINARY-I)
	           unsigned char 	�� ucSupportFileNullFlag,���뱾���ļ�Ϊ���Ƿ�֧��:0-��֧�� 1-֧��
	           int			 	�� iUploadTmpFileFlag,����FTP�ļ��������Ƿ�ʹ����ʱ�ļ���־(0-��ʹ�� 1-ʹ��)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS
								�� ʧ��,���ط�COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpUploadFileEx(unsigned char *pucFtpServerIp,int iFtpServerPort,unsigned char *pucFtpUser,unsigned char *pucFtpPassword,
            unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
            unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iUploadTmpFileFlag);

/***********************************************************************************************
	FuncName : Comm_GetDescpFromCode
	FuncFunc : ͨ��ͨѶ�������ȡ�����Ϣ����
	Input	 : unsigned char	�� ucRetCode 	,����ͨѶ�ķ�����
	Output	 : unsigned char *	�� pucOutputData,����ͨѶ�����Ϣ����
	Return	 : unsigned char	�� �ɹ�,����COMM_SUCCESS(0x00)
					 			�� ʧ��,����COMM_SUCCESS(0x01)
	Author	 : Sunrier
	Date     : 2011-03-21 15:00:55
	Descp    : ��ȡͨѶ�ⷵ���������Ϣ����
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetDescpFromCode(unsigned char ucRetCode,unsigned char *pucOutputData);

/*********************************************************************************************** 
    FuncName : Comm_GetLibVersion
	FuncFunc : ��ȡͨѶ��汾��Ϣ
	Input	 : None
	Output	 : unsigned char *   �� pucOutputData	Lib��汾����Ϣ
	Return	 : unsigned char	 �� �ɹ�,����0x00
								 �� ʧ��,���ط�0
	Author   : Sunrier    
	Date     : 2013-12-18 19:37:43
	Descp    : None
	History  : None 
*************************************************************************************************/
EXPORT unsigned char Comm_GetLibVersion(unsigned char *pucOutputData);

#endif














