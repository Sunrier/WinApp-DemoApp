/*************************************************************************************************
	FileName : demotapp.c
    FileFunc : 实现demo应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2013-08-05 18:13:15
	Descp    : 实现demo应用入口函数
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"



/***********************************************************************************************
	FuncName : DemoApp_InitTranCfg
    FuncFunc : 初始化配置文件信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 18:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_InitTranCfg( void )
{

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : DemoApp_GetTranCfg
    FuncFunc : 获取Demo项目配置信息
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
unsigned char DemoApp_GetTranCfg( void )
{
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];	/*键值*/
	unsigned char ucRetCode = APP_FAILURE;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter DemoApp_GetTranCfg!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DemoApp_GetTranCfg APP_FAILURE!");
		return APP_FAILURE;
	}
	
	//memset(&g_mApp,0,sizeof(App_Prm));
	//Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME);
	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s","COMM");

	/*获取当前通讯类型*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","COMMTYPE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 2==strlen((char *)aucKeyValue) )
	{
		if( !memcmp(aucKeyValue,"08",2) )
		{
			g_mTermCfg.ucCommFlag = 0;
		}
		else if( !memcmp(aucKeyValue,"09",2) )
		{
			g_mTermCfg.ucCommFlag = 1;
		}
		else if( !memcmp(aucKeyValue,"10",2) )
		{
			g_mTermCfg.ucCommFlag = 2;
		}
		else
		{
			g_mTermCfg.ucCommFlag = 1;
		}

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CurrentCommMode[%s]!",aucKeyValue);
	}

	/*获取串口号COMMPORT*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","COMMPORT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && ((strlen(aucKeyValue)>0) &&  (strlen(aucKeyValue)<=2) ) )
	{
		//if( COMM_TYPE_RS232==g_mTermCfg.ucCurrentCommMode )
		{
			if( 1==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM1;
			}
			else if( 2==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM2;
			}
			else if( 3==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM3;
			}
			else if( 4==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM4;
			}
			else if( 5==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM5;
			}
			else if( 6==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM6;
			}
			else if( 7==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM7;
			}
			else if( 8==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM8;
			}
			else if( 9==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM9;
			}

			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "COMMPORT[%s]!",aucKeyValue);
		}
	}

	/*获取串口波特率BAUDRATE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BAUDRATE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && ( strlen(aucKeyValue)>0 &&  strlen(aucKeyValue)<7 ) )
	{
		//if( COMM_TYPE_RS232==g_mTermCfg.ucCurrentCommMode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BAUDRATE[%s]!",aucKeyValue);
			
			switch( atol(aucKeyValue) )
			{
				case UBPS300:
				case UBPS1200:
				case UBPS2400:
				case UBPS4800:
				case UBPS7200:
				case UBPS9600:
				case UBPS19200:
				case UBPS38400:
				case UBPS57600:
				case UBPS76800:
				case UBPS115200:
						g_mTermCfg.uiBaudRate = atol(aucKeyValue);
						break;
				default:
						break;
			}
		}
	}
	
	/*获取TCP通讯地址IP1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","IP1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucTCPIP1,0,sizeof(g_mTermCfg.aucTCPIP1));
		memcpy(g_mTermCfg.aucTCPIP1,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP1[%s]!",aucKeyValue);
	}

	/*获取TCP通讯端口PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
	}

	/*获取TCP通讯备机地址IP2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","IP2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucTCPIP2,0,sizeof(g_mTermCfg.aucTCPIP2));
		memcpy(g_mTermCfg.aucTCPIP2,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP2[%s]!",aucKeyValue);
	}
	
	//获取TCP通讯备机端口PORT2
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT2[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时是否支持库的协议0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPLIBFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x04;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPLIBFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时URL是否自解析0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x01;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https是否支持URL自解析失败后尝试Host IP/Name 0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLCOMMFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x02;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLCOMMFLAG[%s]!",aucKeyValue);
	}

	/*http或https接收的包是否不自解析:0-不解析 1-解析*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOHTTPPARSEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x08;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOHTTPPARSEFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时请求方法:0-POST方法 1-GET方法*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPWAYFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucRequestWayFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPWAYFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https的URL*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","URL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=256) ) )
	{
		strcpy(g_mTermCfg.aucHttpURL,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "URL[%s]!",aucKeyValue);
	}

	/*获取http或https的DOMAIN*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DOMAIN");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpDomain,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DOMAIN[%s]!",aucKeyValue);
	}

	/*获取http或https的PAGE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PAGE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpPage,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PAGE[%s]!",aucKeyValue);
	}

	/*获取TCP通讯主机域名HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取TCP通讯备机域名HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}

	/*获取是否支持备机*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);

	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取是否支持备机域名解析*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DomainNameFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucDomainNameFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucDomainNameFlag = 0;
	}

	/*获取串口通讯超时(S)RS232Timeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*获取TCP通讯超时时间(S)TcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*获取是否支持SSL通讯*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucSSLFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucSSLFlag = 0;
	}

	/*获取SSL通讯超时时间(S)SSLTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}

	/*获取服务器设定的IP地址*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}

	/*获取服务器监听PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}

	/*获取TCP服务器阻塞时超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerBlockTimeout");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpServerBlockTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerBlockTimeout[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : DemoApp_InitComm
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
unsigned char DemoApp_InitComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,2,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter DemoApp_InitComm");
	
	AppUtils_DisplayLeft("通讯初始化...\n", LINE2);
	AppUtils_DisplayLeft("请稍候...\n", LINE3);

	Tool_TraceLog(1,g_mApp.ucLogLevel,2,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_InitComm [CommPort=COM%d,BaudRate=%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_InitSock [BakCommFlag=%d,TCPIP1=%s,TCPHostPort1=%d,TCPIP2=%s,TCPHostPort2=%d,SelfHttpProtocolFlag=%d,HttpURL=%s,HttpRequestWayFlag=%d,TCPServerIP=%s,TCPServerPort=%d,TcpServerBlockTimeout=%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DemoApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : DemoApp_Init
    FuncFunc : Demo应用初始化
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Init(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter DemoApp_Init!");

	DemoApp_GetTranCfg();
	ucRetCode = DemoApp_InitComm();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DemoApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : DemoApp_Help
    FuncFunc : DEMO项目帮助菜单
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Help(void *pDummy)
{
	unsigned char aucDispBuf[128],aucTitle[64];

	AppUtils_FormatDisp("\n");
	if( strlen(g_mApp.aucUserName) )
	{
		
		memset(aucDispBuf,0,sizeof(aucDispBuf));
		memset(aucDispBuf,'*',61);

		memset(aucTitle,0,sizeof(aucTitle));
		sprintf(aucTitle,"欢迎%s使用",g_mApp.aucUserName);
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.58s",DEMOAPP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",DEMOAPP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",DEMOAPP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",DEMOAPP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",DEMOAPP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",DEMOAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : DemoApp_Menu
    FuncFunc : Demo项目应用菜单
	Input	 : void *	— pDummy	入口参数标志
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
unsigned char DemoApp_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "基础项目",	BaseApp_Menu, (void *) 0 },
		{ 2, "FTP项目",		FtpApp_Menu, (void *) 0 },
		{ 3, "Email项目",	EmailApp_Menu, (void *) 0 },
		{ 4, "帮助",    	DemoApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "测试项目应用");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}







