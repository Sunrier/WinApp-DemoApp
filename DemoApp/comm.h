/*************************************************************************************************
	FileName : comm.h
    FileFunc : 实现应用层通讯库函数接口头文件
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2011-03-05 19:13:15
	Descp    : 实现应用通讯库
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

/*串口通讯端口号*/
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

/*串口通讯波特率*/
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

/*通讯格式*/
typedef enum
{
	COMM_FMT_NOFMT = 0,					/*无格式:Data*/
	COMM_FMT_ASCLEN_DATA,				/*4位长度(Asc)+数据:AscLen(4位)+Data(Len位)*/
	COMM_FMT_HEXLEN_DATA,				/*2位长度(Hex)+数据:HexLen(2位)+Data(Len位)*/
	COMM_FMT_STX_HEXLEN_DATA_ETX_LRC,	/*STX+2位长度(Hex)+数据+ETX+LRC:STX(1位)+HexLen(2位)+Data(Len位)+ETX(1位)+LRC(1位)*/
	COMM_FMT_STX_HEXLEN_DATA_LRC_ETX,	/*STX+2位长度(Hex)+数据+LRC+ETX:STX(1位)+HexLen(2位)+Data(Len位)+LRC(1位)+ETX(1位)*/
	COMM_FMT_STX_DATA_ETX_LRC,			/*STX+数据+ETX+LRC:STX(1位)+Data(Len位)+ETX(1位)+LRC(1位)*/
	COMM_FMT_STX_DATA_LRC_ETX,			/*STX+数据+LRC+ETX:STX(1位)+Data(Len位)+LRC(1位)+ETX(1位)*/
}COMM_FMT;

/***********************************************************************************************
	FuncName : Comm_InitCfg
	FuncFunc : 初始化通讯库配置
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitCfg( void );

/***********************************************************************************************
	FuncName : Comm_InitLib
	FuncFunc : 初始化库参数
	Input	 : unsigned char	— ucCNTipFlag,中文提示信息标志:0-英文提示 非0-中文提示
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitLib(unsigned char ucCNTipFlag);

/***********************************************************************************************
	FuncName : Comm_InitComm
	FuncFunc : 初始化串口通讯参数
	Input	 : unsigned int		— uiCommPort,串口号
	           unsigned int		— uiBaudRate,波特率
	           unsigned short	— usRecvTimeout,接收数据超时时间(S)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitComm(unsigned int uiCommPort,unsigned int uiBaudRate,unsigned short usRecvTimeout);

/***********************************************************************************************
	FuncName : Comm_InitSock
	FuncFunc : 初始化网络通讯参数
	Input	 : unsigned char *	— pucHostIP,主机IP
	           unsigned short	— usHostPort,主机端口
	           unsigned char	— ucSockBakFlag,是否支持备机
	           unsigned char *	— pucBakHostIP,备机IP
	           unsigned short	— usBakHostPort,备机端口
	           unsigned char	— ucHostNameFlag,是否使用域名或服务名代替IP 
	                                              0-使用主机或备机的IP
	                                              1-使用域名或服务名 
	           unsigned char *	— pucHostName,主机域名或服务名
	           unsigned char *	— pucBakHostName,备机域名或服务名
	           unsigned char    — ucSelfHttpProtocolFlag,http通讯时是否支持库的协议:0-不支持 非0-支持
	           unsigned char *  — pucHttpUrl,http的URL,当ucSelfHttpProtocolFlag=1时有效
	           unsigned char 	— ucHttpRequestWayFlag,http的请求方法,0-Post方法 1-Get方法
	           unsigned char *  — pucDownloadFilePath,http下载文件目录
	           unsigned char *  — pucDownloadFileName,http下载文件名
	           unsigned char *	— pucServerIP,作为服务器时的本地IP:当为空时任意地址
	           unsigned short   — usServerListenPort,作为服务器时的监听端口
	           unsigned long    — ulServerBlockTimeout,作为服务器阻塞时间(S):0-非阻塞 非0-阻塞时间
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 超时时间(S)
	History  : None
	Other    : ucSelfHttpProtocolFlag - 第八位0x01 http是否支持URL自解析
										第七位0x02 http是否支持URL自解析失败后尝试Host IP/Name
										第六位0x04 http是否支持库的协议
										第五位0x08 http是否接收的包自解析
										第四位0x10 http接收的包保存为文件
										第三位0x20 预留
										第二位0x40 预留
										第一位0x50 预留
*************************************************************************************************/
EXPORT unsigned char Comm_InitSock(unsigned char *pucHostIP,unsigned short usHostPort,unsigned char ucSockBakFlag,unsigned char *pucBakHostIP,unsigned short usBakHostPort,unsigned char ucHostNameFlag,unsigned char *pucHostName,unsigned char *pucBakHostName,unsigned char ucSelfHttpProtocolFlag,unsigned char *pucHttpUrl,unsigned char ucHttpRequestWayFlag,unsigned char *pucDownloadFilePath,unsigned char *pucDownloadFileName,unsigned char *pucServerIP,unsigned short usServerListenPort,unsigned long ulServerBlockTimeout);

/***********************************************************************************************
	FuncName : Comm_InitSSL
	FuncFunc : 初始化SSL网络通讯参数
	Input	 : unsigned char *	— pucSSLHostIP,SSL主机IP
	           unsigned short	— usSSLHostPort,SSL主机端口
	           unsigned char	— ucSSLBakFlag,是否支持SSL备机
	           unsigned char *	— pucBakSSLHostIP,SSL备机IP
	           unsigned short	— usBakSSLHostPort,SSL备机端口
	           unsigned char	— ucSSLHostNameFlag,SSL是否使用域名或服务名代替IP 
	                                              	0-SSL使用主机或备机的IP
	                                              	1-SSL使用域名或服务名 
	           unsigned char *	— pucSSLHostName,SSL主机域名或服务名
	           unsigned char *	— pucBakSSLHostName,SSL备机域名或服务名
	           unsigned char 	— ucSSLMethodType,客户端SSL协议类型:1-SSLv2 2-SSLv3 3-SSLv23 4-TLSv1 5-DTLSv1 其它-SSLv23
	           unsigned char	— ucIsVerifyCA,是否验证CA证书:0-不验证 1-验证
			   unsigned char	— ucChainDepth,CA证书寻址的目录深度指数:0-不校验CA 1-1级CA证书 2-2级CA证书
			   unsigned char *	— pucCACertFile,客户端CA公钥文件存放位置和文件名
			   unsigned char	— ucServerVerifyType, 0-不校验服务端证书:1-服务器要验证对方,双向认证 2-服务器向客户端请求证书 3-客户端需要验证对方,而服务器不需要单向认证
			   unsigned char    — ucCertFileType,证书文件类型编码格式编码格式:1-SSL_FILETYPE_PEM 2-SSL_FILETYPE_ASN1 3-SSL_FILETYPE_P12
			   unsigned char *	— pucCACertFile,客户端认证证书存放位置和文件名
			   unsigned char *	— pucClPrivateKey,客户端私钥存放位置和文件名
			   unsigned char *	— pucPKeyPassword,客户端私钥密码
			   unsigned char    -  ucSelfHttpsProtocolFlag,https通讯时是否支持库的协议标志:0-不支持 非0-支持
	           unsigned char *  -  pucHttpsUrl,https的URL,当ucSelfHttpsProtocolFlag=1时有效
	           unsigned char 	-  ucHttpsRequestWayFlag,https的请求方法,0-Post方法 1-Get方法
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : 超时时间(S)
	History  : None
	Other    : ucSelfHttpsProtocolFlag - 第八位0x01 https是否支持URL自解析
										 第七位0x02 https是否支持URL自解析失败后尝试Host IP/Name
										 第六位0x04 https是否支持库的协议
										 第五位0x08 https是否接收的包自解析
										 第四位0x10 预留
										 第三位0x20 预留
										 第二位0x40 预留
										 第一位0x80 预留
*************************************************************************************************/
EXPORT unsigned char Comm_InitSSL(unsigned char *pucSSLHostIP,unsigned short usSSLHostPort,unsigned char ucSSLBakFlag,unsigned char *pucBakSSLHostIP,unsigned short usBakSSLHostPort,
								unsigned char ucSSLHostNameFlag,unsigned char *pucSSLHostName,unsigned char *pucBakSSLHostName,
								unsigned char ucSSLMethodType,unsigned char ucIsVerifyCA,unsigned char ucChainDepth,unsigned char *pucCACertFile,
								unsigned char ucServerVerifyType,unsigned char ucCertFileType,unsigned char *pucClCertFile,unsigned char *pucClPrivateKey,
								unsigned char *pucPKeyPassword,unsigned char ucSelfHttpsProtocolFlag,unsigned char *pucHttpsUrl,unsigned char ucHttpsRequestWayFlag);

/***********************************************************************************************
	FuncName : Comm_InitFtp
	FuncFunc : 初始化FTP网络通讯参数
	Input	 : unsigned char *	— pucFtpHostIP,FTP主机IP
	           unsigned short	— usFtpHostPort,FTP主机端口
	           unsigned char	— ucFtpSockBakFlag,FTP是否支持备机
	           unsigned char *	— pucFtpBakHostIP,FTP备机IP
	           unsigned short	— usFtpBakHostPort,FTP备机端口
	           unsigned char	— ucFtpHostNameFlag,FTP是否使用域名或服务名代替IP 
	                                              0-使用主机或备机的IP
	                                              1-使用域名或服务名 
	           unsigned char *	— pucFtpHostName,FTP主机域名或服务名
	           unsigned char *	— pucFtpBakHostName,FTP备机域名或服务名
	           unsigned char *  — pucFtpUser,FTP用户名
	           unsigned char *  — pucFtpUserPassword,FTP用户密码          
	           unsigned char *	— pucLocalIP,作为服务器时的本地IP:当为空时任意地址
	           unsigned short	— usFtpTimeout,FTP超时时间(S)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 超时时间(S)
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_InitFtp(unsigned char *pucFtpHostIP,unsigned short usFtpHostPort,unsigned char ucFtpSockBakFlag,unsigned char *pucFtpBakHostIP,unsigned short usFtpBakHostPort,unsigned char ucFtpHostNameFlag,unsigned char *pucFtpHostName,unsigned char *pucFtpBakHostName,unsigned char *pucFtpUser,unsigned char *pucFtpUserPassword,unsigned char *pucLocalIP,unsigned short usFtpTimeout);

/***********************************************************************************************
	FuncName : Comm_GetInfoFromUrl
	FuncFunc : 从URL获取网络信息
	Input	 : unsigned char *	— pucInputUrl		输入的URL
			   unsigned char 	— ucNetInfoFlag	输入获取的信息标志
	Output	 : unsigned char *	— pucOutputIP 		输出IP地址
		       unsigned short *	— pusOutputPort	输出端口
		       unsigned char *	— pucOutputDomain	输出域名
		       unsigned char *	— pucOutputPage	输出Page页面
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2013-12-26 19:12:55
	Descp    : ucNetInfoFlag:	0x01	-	获取IP地址
								0x02	-	获取端口
								0x04	-	获取域名
								0x08	-	获取Page页面
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetInfoFromUrl(unsigned char *pucInputUrl,unsigned char ucNetInfoFlag,unsigned char *pucOutputIP,unsigned short *pusOutputPort,unsigned char *pucOutputDomain,unsigned char *pucOutputPage);

/***********************************************************************************************
	FuncName : Comm_SetHttpParam
	FuncFunc : 设置库的http或https参数
	Input	 : unsigned char *  — pucHttpUrl,http的URL,只改变HttpURL,如果需要改变IP或者page需要重新调用Comm_InitSock或Comm_InitSSL
			   unsigned char	— ucHttpOrHttpsRequestWayFlag,http或https的请求方法:0-Post方法 1-Get方法
			   unsigned char	— ucHttpOrHttpsParseFlag,http或https接收的包是否自解析:0-不解析 1-解析
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 需支持库的http或https协议,http或https必须先初始化该函数才生效
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SetHttpParam(unsigned char *pucHttpUrl,unsigned char ucHttpOrHttpsRequestWayFlag,unsigned char ucHttpOrHttpsParseFlag);

/***********************************************************************************************
	FuncName : Comm_SetServerParam
	FuncFunc : 设置库的服务器参数
	Input	 : unsigned char *	— pucServerIp,作为服务器时的本地IP:当为空时任意地址
			   unsigned short	— usServerListenPort,作为服务器时的监听端口
			   unsigned short	— usServerBlockTimeout,作为服务器阻塞时间(S):0-非阻塞 非0-阻塞时间
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : TCP Server参数
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SetServerParam(unsigned char *pucServerIp,unsigned short usServerListenPort,unsigned short usServerBlockTimeout);

/***********************************************************************************************
	FuncName : Comm_CheckConnect
	FuncFunc : 检查串口或网络
	Input	 : unsigned char	— ucCommFlag	当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_CheckConnect(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_SendPacket
	FuncFunc : 发送通讯数据包
	Input	 : unsigned char	— ucCommFlag		当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
		       unsigned char	— ucCommFormat		输入发送的通讯格式,见COMM_FMT格式
			   unsigned char *	— pucInputData 	发送的数据
		       unsigned int		— uiInputDataLen	发送数据的长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_SendPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Comm_RecvPacket
	FuncFunc : 接收通讯数据包
	Input	 : unsigned char	— ucCommFlag		当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
		       unsigned char	— ucCommFormat		输入接收的通讯格式,见COMM_FMT格式
	           unsigned long	— ulTimeOut		输入接收的超时时间(S)
	Output	 : unsigned char *	— pucOutputData 	接收的数据
		       unsigned int	 *	— puiOutputDataLen	接收数据的长度
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_RecvPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned long ulTimeOut,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_GetHttpData
	FuncFunc : 获取HTTP或HTTPS请求数据
	Input	 : unsigned char	— ucCommFlag		当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
			   unsigned char *	— pucInputData		发送的数据
			 : unsigned int	 	— uiInputDataLen	发送的数据长度
	Output	 : unsigned char *	— pucOutputData 	接收的数据
		       unsigned int	 *	— puiOutputDataLen	接收数据的长度
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetHttpData(unsigned char ucCommFlag,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_ParseHttpData
	FuncFunc : 分析HTTP或HTTPS返回数据
	Input	 : unsigned char	— ucCommFlag		当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
			   unsigned char *	— pucInputData		接收的源数据
			 : unsigned int	 	— uiInputDataLen	接收的源数据长度
	Output	 : unsigned char *	— pucOutputData 	接收的数据
		       unsigned int	 *	— puiOutputDataLen	接收数据的长度
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ParseHttpData(unsigned char ucCommFlag,unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_StartServer
	FuncFunc : 开启Server服务
	Input	 : unsigned char	— ucCommFlag,当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StartServer(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_CheckServerAccept
	FuncFunc : 判断是否接收到一个客户端的连接
	Input	 : unsigned char	— ucCommFlag,当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	Output	 : unsigned char *	— pucOutputRemoteClientIp 		客户端IP地址
			   unsigned short*	— pusOutputRemoteClientPort	客户端端口号
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_CheckServerAccept(unsigned char ucCommFlag,unsigned char *pucOutputRemoteClientIp,unsigned short *pusOutputRemoteClientPort);

/***********************************************************************************************
	FuncName : Comm_ServerSendPacket
	FuncFunc : server发送数据包给客户端
	Input	 : unsigned char	— ucCommFlag,当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	           unsigned char	— ucCommFormat		输入发送的通讯格式,见COMM_FMT格式
			   unsigned char *	— pucInputData 	发送的数据
		       unsigned int		— uiInputDataLen	发送数据的长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回WCOMM_SUCCESS
								— 失败,返回非WCOMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ServerSendPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : Comm_ServerRecvPacket
	FuncFunc : server接收客户端通讯数据包
	Input	 : unsigned char	— ucCommFlag		当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
		       unsigned char	— ucCommFormat		输入接收的通讯格式,见COMM_FMT格式
	           unsigned long	— ulTimeOut		输入接收的超时时间(S)
	Output	 : unsigned char *	— pucOutputData 	接收的数据
		       unsigned int	 *	— puiOutputDataLen	接收数据的长度
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回COMM_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-26 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_ServerRecvPacket(unsigned char ucCommFlag,unsigned char ucCommFormat,unsigned long ulTimeOut,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : Comm_StopClient
	FuncFunc : 服务器端断开客户端的连接
	Input	 : unsigned char	— ucCommFlag,当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 服务器端不会断开
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StopClient(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_StopServer
	FuncFunc : 断开Server服务
	Input	 : unsigned char	— ucCommFlag,当前通讯标志 0-串口 1-网络(TCP) 2-公网(SSL) 3-网络HTTP 4-公网HTTPS 5-网络(UDP)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 自动断开客户端连接
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_StopServer(unsigned char ucCommFlag);

/***********************************************************************************************
	FuncName : Comm_Disconnect
	FuncFunc : 断开串口或网络通讯
	Input	 : unsigned char	— ucDisconnectFlag,断开通讯标志:	0-所有通讯 1-串口 2-网络(TCP) 
																	3-公网(SSL) 4-网络HTTP 5-公网HTTPS
																	6-网络(UDP) 7-TCP Server的客户端 
																	8-TCP Server 9-UDP Server的客户端
																	10-TCP Server
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 断开串口或网络失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_Disconnect(unsigned char ucDisconnectFlag);

/***********************************************************************************************
	FuncName : Comm_FtpParseList
	FuncFunc : 解析FTP返回的文件列表
	Input	 : unsigned char * 	— pucInputData,输入信息
	           unsigned char	— ucListType,输入的获取列表类型:0-文件名
	                                                         	 1-文件和目录名
	                                                         	 2-只返回文件名
			                                                     3-只返回目录名
			                                                     4-只返回文件名和目录名
			                                                     其他-只返回文件名
	Output	 : unsigned char * 	— pucOutputData,输出过滤后的文件列表信息
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 文件名和目录名之间以|分隔,文件名支持空格
	History  : None
	Other    : 当ucListType=0时,pucInputData信息通过LIST -l获取;
			   当ucListType=1时,pucInputData信息通过NLST获取;
			   当ucListType=2时,pucInputData信息通过LIST -l获取;
			   当ucListType=3时,pucInputData信息通过LIST -l获取;
			   当ucListType=4时,pucInputData信息通过LIST -l获取;
*************************************************************************************************/
EXPORT unsigned char Comm_FtpParseList(unsigned char *pucInputData,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpParseListEx
	FuncFunc : 解析FTP返回的文件列表信息
	Input	 : unsigned char	— ucListType,输入的获取列表类型:2-文件名 3-目录名 4-文件名和目录名
	           unsigned char * 	— pucDetialInfo,输入文件和目录详细信息
	           unsigned char * 	— pucListName,输入文件名和目录名列表
	Output	 : unsigned char * 	— pucOutputData,输出过滤后的文件列表信息
	Return	 : unsigned char	— 成功,返回WCOMM_SUCCESS
								— 失败,返回非WCOMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 文件名和目录名之间以|分隔,文件名和目录名支持空格
	History  : None
	Other    : pucDetialInfo信息通过LIST -l获取;
			   pucListName信息通过NLST获取;
*************************************************************************************************/
EXPORT unsigned char Comm_FtpParseListEx(unsigned char ucListType,unsigned char *pucDetialInfo,unsigned char *pucListName,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpGetFileList
	FuncFunc : 获取FTP Server目录列表信息
	Input	 : unsigned char * 	— pucFtpUser,输入FTP Server登录用户
	           unsigned char * 	— pucFtpPassword,输入FTP Server登录用户的密码
			   unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
			   unsigned char	— ucListType,输入返回的列表类型:0-返回FTP文件和目录明细 
			                                                     1-返回FTP文件和目录名列表
			                                                     2-只返回文件名
			                                                     3-只返回目录名
			                                                     4-只返回文件名和目录名
			                                                     其他-返回文件和目录明细
	Output	 : unsigned char *	— pucOutputData,输出目录列表信息
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 文件名和目录名之间以|分隔
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpGetFileList(unsigned char *pucFtpUser,unsigned char *pucFtpPassword,unsigned char *pucRemotePath,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpDownloadFile
	FuncFunc : FTP文件下载
	Input	 : unsigned char * 	— pucLocalPath,输入本地文件目录
	           unsigned char * 	— pucLocalFileName,输入本地文件名
	           unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
	           unsigned char * 	— pucRemoteFileName,输入FTP Server端文件名
	           unsigned char * 	— pucFileType,输入FTP文件传输类型(ASCII-A/BINARY-I/EBCDIC-E,默认BINARY-I)
	           unsigned char 	— ucSupportFileNullFlag,输入本地文件为空是否支持:0-不支持 1-支持
	           int			 	— iDelRemoteFileFlag,输入FTP文件下载后是否删除FTP端文件标志(0-不删除 1-删除)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 必须先调用Comm_InitFtp
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpDownloadFile(unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
                   unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iDelRemoteFileFlag);

/***********************************************************************************************
	FuncName : Comm_FtpUploadFile
	FuncFunc : FTP文件上传
	Input	 : unsigned char * 	— pucLocalPath,输入本地文件目录
	           unsigned char * 	— pucLocalFileName,输入本地文件名
	           unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
	           unsigned char * 	— pucRemoteFileName,输入FTP Server端文件名
	           unsigned char * 	— pucFileType,输入FTP文件传输类型(ASCII-A/BINARY-I/EBCDIC-E,默认BINARY-I)
	           unsigned char 	— ucSupportFileNullFlag,输入本地文件为空是否支持:0-不支持 1-支持
	           int			 	— iUploadTmpFileFlag,输入FTP文件过程中是否使用临时文件标志(0-不使用 1-使用)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 必须先调用Comm_InitFtp
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpUploadFile(unsigned char *pucLocalPath,unsigned char *pucLocalFileName,
            unsigned char *pucRemotePath,unsigned char *pucRemoteFileName,unsigned char *pucFileType,unsigned char ucSupportFileNullFlag,int iUploadTmpFileFlag);

/***********************************************************************************************
	FuncName : Comm_FtpGetFileListEx
	FuncFunc : 获取FTP Server目录列表信息
	Input	 : unsigned char * 	— pucFtpServerIp,输入FTP Server IP地址
			   short int	 	— iFtpServerPort,输入FTP Server 端口PORT
			   unsigned char * 	— pucFtpUser,输入FTP Server登录用户
	           unsigned char * 	— pucFtpPassword,输入FTP Server登录用户的密码
			   unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
			   unsigned char	— ucListType,输入返回的列表类型:0-返回FTP文件和目录明细 
			                                                     1-返回FTP文件和目录名列表
			                                                     2-只返回文件名
			                                                     3-只返回目录名
			                                                     4-只返回文件名和目录名
			                                                     其他-返回文件和目录明细
	Output	 : unsigned char *	— pucOutputData,输出目录列表信息
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
	Author	 : Sunrier
	Date     : 2011-03-05 19:12:55
	Descp    : 文件名和目录名之间以|分隔
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_FtpGetFileListEx(unsigned char *pucFtpServerIp,short int iFtpServerPort,unsigned char *pucFtpUser,unsigned char *pucFtpPassword,unsigned char *pucRemotePath,unsigned char ucListType,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : Comm_FtpDownloadFileEx
	FuncFunc : FTP文件下载
	Input	 : unsigned char * 	— pucFtpServerIp,输入FTP Server IP地址
			   int			 	— iFtpServerPort,输入FTP Server 端口PORT
			   unsigned char * 	— pucFtpUser,输入FTP Server登录用户
	           unsigned char * 	— pucFtpPassword,输入FTP Server登录用户的密码
	           unsigned char * 	— pucLocalPath,输入本地文件目录
	           unsigned char * 	— pucLocalFileName,输入本地文件名
	           unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
	           unsigned char * 	— pucRemoteFileName,输入FTP Server端文件名
	           unsigned char * 	— pucFileType,输入FTP文件传输类型(ASCII-A/BINARY-I/EBCDIC-E,默认BINARY-I)
	           unsigned char 	— ucSupportFileNullFlag,输入本地文件为空是否支持:0-不支持 1-支持
	           int			 	— iDelRemoteFileFlag,输入FTP文件下载后是否删除FTP端文件标志(0-不删除 1-删除)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
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
	FuncFunc : FTP文件上传
	Input	 : unsigned char * 	— pucFtpServerIp,输入FTP Server IP地址
			   int			 	— iFtpServerPort,输入FTP Server 端口PORT
			   unsigned char * 	— pucFtpUser,输入FTP Server登录用户
	           unsigned char * 	— pucFtpPassword,输入FTP Server登录用户的密码
	           unsigned char * 	— pucLocalPath,输入本地文件目录
	           unsigned char * 	— pucLocalFileName,输入本地文件名
	           unsigned char * 	— pucRemotePath,输入FTP Server端文件存放目录
	           unsigned char * 	— pucRemoteFileName,输入FTP Server端文件名
	           unsigned char * 	— pucFileType,输入FTP文件传输类型(ASCII-A/BINARY-I/EBCDIC-E,默认BINARY-I)
	           unsigned char 	— ucSupportFileNullFlag,输入本地文件为空是否支持:0-不支持 1-支持
	           int			 	— iUploadTmpFileFlag,输入FTP文件过程中是否使用临时文件标志(0-不使用 1-使用)
	Output	 : None
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS
								— 失败,返回非COMM_SUCCESS
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
	FuncFunc : 通过通讯返回码获取相关信息描述
	Input	 : unsigned char	— ucRetCode 	,输入通讯的返回码
	Output	 : unsigned char *	— pucOutputData,返回通讯相关信息描述
	Return	 : unsigned char	— 成功,返回COMM_SUCCESS(0x00)
					 			— 失败,返回COMM_SUCCESS(0x01)
	Author	 : Sunrier
	Date     : 2011-03-21 15:00:55
	Descp    : 获取通讯库返回码相关信息描述
	History  : None
	Other    : None
*************************************************************************************************/
EXPORT unsigned char Comm_GetDescpFromCode(unsigned char ucRetCode,unsigned char *pucOutputData);

/*********************************************************************************************** 
    FuncName : Comm_GetLibVersion
	FuncFunc : 获取通讯库版本信息
	Input	 : None
	Output	 : unsigned char *   — pucOutputData	Lib库版本号信息
	Return	 : unsigned char	 — 成功,返回0x00
								 — 失败,返回非0
	Author   : Sunrier    
	Date     : 2013-12-18 19:37:43
	Descp    : None
	History  : None 
*************************************************************************************************/
EXPORT unsigned char Comm_GetLibVersion(unsigned char *pucOutputData);

#endif














