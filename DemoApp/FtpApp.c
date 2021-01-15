/*************************************************************************************************
	FileName : FtpApp.c
    FileFunc : 实现FTP测试应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2018-09-08 11:13:15
	Descp    : 实现FTP项目应用入口函数
    History  : None
*************************************************************************************************/
#include "define.h"


/***********************************************************************************************
	FuncName : FtpApp_GetCommCfg
    FuncFunc : 获取FTP项目通讯配置信息
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
unsigned char FtpApp_GetCommCfg(void *pDummy)
{
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*键值*/
	unsigned char ucRetCode = APP_FAILURE;

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter JN_GetCommCfg!");
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "JN_GetCommCfg APP_FAILURE!");
		return APP_FAILURE;
	}
	
	//memset(&g_mApp,0,sizeof(App_Prm));
	//Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME);
	
	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s",DEMOAPP_APPCOMMSECNAME);

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

	/*获取COMMPORT*/
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

	/*获取BAUDRATE*/
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
	
	/*获取IP1*/
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

	/*获取PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
	}

	/*获取IP2*/
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
	
	/*获取PORT2*/
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

	/*获取HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}

	/*获取BakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取HOSTNAMEFLAG*/
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

	/*获取RS232Timeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*获取TcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*获取SSLFLAG*/
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

	/*获取SSLTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}

	/*服务器设定的IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}

	/*服务器监听PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}

	/*TCP服务器阻塞时超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerBlockTimeout");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpServerBlockTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerBlockTimeout[%s]!",aucKeyValue);
	}

	/*获取FTP IP1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP1,0,sizeof(g_mTermCfg.aucFTPServerIP1));
		memcpy(g_mTermCfg.aucFTPServerIP1,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP1[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPServerIP1,"127.0.0.1");
	}

	/*获取FTP PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT1[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort1 = 21;
	}

	/*获取FTP IP2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP2,0,sizeof(g_mTermCfg.aucFTPServerIP2));
		memcpy(g_mTermCfg.aucFTPServerIP2,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP2[%s]!",aucKeyValue);
	}
	
	/*获取FTP PORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT2[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort2 = 21;
	}
	
	/*获取FTP HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPHostName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取FTP HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucFTPHostName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME2[%s]!",aucKeyValue);
	}

	/*获取FTP BakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPBakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPSockBakFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取FTP HOSTNAMEFLAG*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DomainNameFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucFTPHostNameFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucFTPHostNameFlag = 0;
	}

	/*获取FTP USER*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUSER");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserName,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP User[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserName,"ftpuser");
	}

	/*获取FTP USERPASSWORD*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPWD");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Password[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,"ftpuser");
	}

	/*获取FTP Local IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPLocalIP,0,sizeof(g_mTermCfg.aucFTPLocalIP));
		memcpy(g_mTermCfg.aucFTPLocalIP,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local IP[%s]!",aucKeyValue);
	}
	
	/*获取FtpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpTimeout[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerTimeout = 120;
	}

	/*获取FTP Local PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPLocalPath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local PATH[%s]!",aucKeyValue);
	}
	else
	{
		//strcpy(g_mTermCfg.aucFTPLocalPath,"./");
		//strcpy(g_mTermCfg.aucFTPLocalPath,"D:\\FTP\\upload");
		strcpy(g_mTermCfg.aucFTPLocalPath,"D:\\360Download\\Del\\FTP\\upload");
	}

	/*获取FTP Remote PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPREMOTEPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPRemotePath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Remote PATH[%s]!",aucKeyValue);
	}
	else
	{
		//strcpy(g_mTermCfg.aucFTPRemotePath,"download");
		strcpy(g_mTermCfg.aucFTPRemotePath,"LCC_trans");
	}

	/*FTP File type*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILETYPE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('I'==aucKeyValue[0]) || ('A'==aucKeyValue[0]) || ('E'==aucKeyValue[0])))
	{
		g_mTermCfg.aucFTPFileType[0] = aucKeyValue[0];
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP File Type[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.aucFTPFileType[0] = 'I';
	}

	/*FTP Support file null flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILENULLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('0'==aucKeyValue[0]) || ('1'==aucKeyValue[0]) ) )
	{
		g_mTermCfg.ucFTPFileNullFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP FileNullFlag[%s]!",aucKeyValue);
	}

	/*FTP Upload tmp file flag*/ 
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUPLOADTMPFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPUploadTmpFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP UploadTmpFileFlag[%s]!",aucKeyValue);
	}

	/*FTP Del Remote file flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPDELREMOTEFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPDelRemoteFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DelRemoteFileFlag[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_InitComm
    FuncFunc : 初始化通讯信息
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
unsigned char FtpApp_InitComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_InitComm");
	
	AppUtils_DisplayLeft("通讯初始化...\n", LINE2);
	AppUtils_DisplayLeft("请稍候...\n", LINE3);
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CommPort[COM%d],BaudRate[%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%d],TCPIP1[%s],TCPHostPort1[%d],TCPIP2[%s],TCPHostPort2[%d],SelfHttpProtocolFlag[%d],HttpURL[%s],HttpRequestWayFlag[%d],TCPServerIP[%s],TCPServerPort[%d],TcpServerBlockTimeout[%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);

		ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( !ucRetCode )
	{
		ucRetCode = Comm_InitFtp(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.ucFTPSockBakFlag,g_mTermCfg.aucFTPServerIP2,g_mTermCfg.usFTPServerPort2,g_mTermCfg.ucFTPHostNameFlag,g_mTermCfg.aucFTPHostName1,g_mTermCfg.aucFTPHostName2,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalIP,g_mTermCfg.usFTPServerTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_GetCfg
    FuncFunc : 获取FTP项目配置信息
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
unsigned char FtpApp_GetCfg(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	if( ((void *) 0==pDummy) || ((void *) 3==pDummy) )
	{
		ucRetCode = FtpApp_GetCommCfg(pDummy);
	} 
#if 0
	else if( (void *) 1==pDummy )
	{
		ucRetCode = FtpApp_GetCardCfg(pDummy);
	}
#endif

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_Init
    FuncFunc : FTP项目应用初始化
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
unsigned char FtpApp_Init(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG, "Enter FtpApp_Init!");

	ucRetCode = FtpApp_GetCfg(pDummy);

	if( (void *) 3==pDummy )
	{
		ucRetCode = FtpApp_InitComm();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
			return ucRetCode;
		}
	}

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_DownloadFile
    FuncFunc : 下载FTP文件功能
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
unsigned char FtpApp_DownloadFile(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_DownloadFile!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_DOWNLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	//ucRetCode = AppUtils_GetText(LINE2,"请输入文件名:",aucTmpBuf,1,32,0,60);
	ucRetCode = AppUtils_GetCn(LINE2,"请输入文件名:",aucTmpBuf,1,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetCn fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取文件名失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s",aucTmpBuf);

	g_mTermCfg.ucFTPFileNullFlag = 1;
		
	#if 1
	ucRetCode = Comm_FtpDownloadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("下载Ftp文件失败,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpDownloadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("下载Ftp文件失败,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	AppUtils_FormatDisp("下载Ftp文件[%s]成功!\n",aucFileName);
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_DownloadFiles
    FuncFunc : 下载FTP目录文件功能
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
unsigned char FtpApp_DownloadFiles(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiI = 0;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];
	unsigned char aucReplyBuf[1024] = {0};
    unsigned char aucFileList[1024] = {0};    
	unsigned char *pucPtr = NULL;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_DownloadFiles!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_DOWNLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	g_mTermCfg.ucFTPListType = 0;
	g_mTermCfg.ucFTPFileNullFlag = 1;
	//g_mTermCfg.ucFTPDelRemoteFileFlag = 1;

	memset(aucReplyBuf,0,sizeof(aucReplyBuf));
	/*获取ftp上的文件列表*/
	#if 1
	ucRetCode = Comm_FtpGetFileList(g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPRemotePath,g_mTermCfg.ucFTPListType,aucReplyBuf);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpGetFileList fail,ucRetCode[%d],aucFTPRemotePath[%s]!",ucRetCode,g_mTermCfg.aucFTPRemotePath);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("下载Ftp远程目录文件列表失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpGetFileListEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPRemotePath,g_mTermCfg.ucFTPListType,aucReplyBuf);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpGetFileListEx fail,ucRetCode[%d],aucFTPRemotePath[%s]!",ucRetCode,g_mTermCfg.aucFTPRemotePath);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("下载Ftp远程目录文件列表失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	Tool_TraceLog(1,g_mApp.ucLogLevel,2,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucReplyBuf[%s]!",aucReplyBuf);	

	if( !strlen(aucReplyBuf) )
	{
		AppUtils_FormatDisp("下载Ftp远程目录为空,aucFTPRemotePath[%s]!\n",g_mTermCfg.aucFTPRemotePath);
		AppUtils_WaitKey(5);
		return APP_SUCCESS;
	}
	
	if( (2==g_mTermCfg.ucFTPListType) || (3==g_mTermCfg.ucFTPListType) || (4==g_mTermCfg.ucFTPListType) )
	{
		memset(aucFileList,0,sizeof(aucFileList));
	    strcpy(aucFileList,aucReplyBuf);
	}
	else
	{
		memset(aucFileList,0,sizeof(aucFileList));
	    ucRetCode = Comm_FtpParseList(aucReplyBuf,g_mTermCfg.ucFTPListType,aucFileList);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpParseList fail,ucRetCode[%d]!",ucRetCode);
			memset(aucTmpBuf,0,sizeof(aucTmpBuf));
			Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
			AppUtils_FormatDisp("下载Ftp远程目录文件列表失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileList[%s]!",aucFileList);
	
    Tool_StrTrimAll(aucFileList);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_StrTrimAll aucFileList[%s]!",aucFileList);
    pucPtr = aucFileList;
    uiI = 0;
	memset(aucFileName,0,sizeof(aucFileName));
    while( '\0'!=*pucPtr )
    {
        if( '|'==*pucPtr )
        {
            Tool_StrTrimAll(aucFileName);
			//AppUtils_FormatDisp("下载Ftp文件[%s]!",aucFileName);
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Org aucFileName[%s]!",aucFileName);

			/*中文文件名乱码*/
			memset(aucTmpBuf,0,sizeof(aucTmpBuf));
			Tool_CodeConvert(CP_UTF8,aucFileName,CP_ACP,aucTmpBuf);
			Tool_StrTrimAll(aucTmpBuf);
			strcpy(aucFileName,aucTmpBuf);

			AppUtils_FormatDisp("下载Ftp文件[%s]!",aucFileName);
			
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileName[%s]!",aucFileName);

            /*检查文件名是否重复*/
			ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName,1);
			if( !ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_IsExistFile,ucRetCode[0x%02X],aucFileName[%s]!",ucRetCode,aucFileName);
				AppUtils_FormatDisp("文件[%s]已经存在!",aucFileName);
				uiI = 0;
		        pucPtr++;
				memset(aucFileName,0,sizeof(aucFileName));
				continue;
			}
			
			#if 0
			ucRetCode = Comm_FtpDownloadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("下载Ftp文件失败,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#else
			ucRetCode = Comm_FtpDownloadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("下载Ftp文件失败,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#endif

			AppUtils_FormatDisp("下载Ftp文件[%s]成功!",aucFileName);
           	
            uiI = 0;
            pucPtr++;
			memset(aucFileName,0,sizeof(aucFileName));
            continue;
        }

		if( uiI>256 )
		{
			pucPtr = NULL;
			AppUtils_FormatDisp("文件名长度无效,超过最大长度[%d]\n",uiI);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
		
        aucFileName[uiI] = *pucPtr;
        uiI++;
        pucPtr++;
    }

	pucPtr = NULL;

	AppUtils_FormatDisp("\n下载Ftp远程文件成功!\n");
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_UploadFile
    FuncFunc : 上传FTP文件功能
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
unsigned char FtpApp_UploadFile(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_UploadFile!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_UPLOADFILE;
	
	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	//ucRetCode = AppUtils_GetText(LINE2,"请输入文件名:",aucTmpBuf,1,32,0,60);
	ucRetCode = AppUtils_GetCn(LINE2,"请输入文件名:",aucTmpBuf,1,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("获取文件名失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s",aucTmpBuf);

	g_mTermCfg.ucFTPFileNullFlag = 1;
	g_mTermCfg.ucFTPUploadTmpFileFlag = 0;
	
	#if 0
	ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName, g_mTermCfg.ucFTPFileNullFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_IsExistFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Tool_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("上传Ftp文件失败,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif
	
	#if 0
	ucRetCode = Comm_FtpUploadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("上传Ftp文件失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpUploadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode,aucTmpBuf);
		AppUtils_FormatDisp("上传Ftp文件失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	AppUtils_FormatDisp("上传本地文件[%s]到Ftp远程目录成功!\n",aucFileName);
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_UploadFiles
    FuncFunc : 上传FTP目录文件功能
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
unsigned char FtpApp_UploadFiles(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiI = 0;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];
	//unsigned char aucTmpFileName[256+1];
	unsigned char aucReplyBuf[1024] = {0};
    unsigned char aucFileList[1024] = {0};    
	unsigned char *pucPtr = NULL;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_UploadFiles!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_UPLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	g_mTermCfg.ucFTPFileNullFlag = 0; 
	
	/*获取ftp上传的文件目录列表*/
	memset(aucFileList,0,sizeof(aucFileList));
    ucRetCode = Tool_GetFileListToBuf(g_mTermCfg.aucFTPLocalPath,aucFileList);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_GetFileListToBuf fail,[ucRetCode=0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileList[%s]!",aucFileList);
	
    Tool_StrTrimAll(aucFileList);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_StrTrimAll aucFileList[%s]!",aucFileList);
    pucPtr = aucFileList;
    uiI = 0;
	memset(aucFileName,0,sizeof(aucFileName));
    while( '\0'!=*pucPtr )
    {
        if( '|'==*pucPtr )
        {
            Tool_StrTrimAll(aucFileName);
			AppUtils_FormatDisp("上传Ftp文件[%s]!",aucFileName);
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileName[%s]!",aucFileName);

            /*检查文件名是否存在*/
			ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.ucFTPFileNullFlag);
			if( ucRetCode )
			{
				uiI = 0;
		        pucPtr++;
				memset(aucFileName,0,sizeof(aucFileName));
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_IsExistFile fail,ucRetCode[0x%02X],aucFileName[%s]!",ucRetCode,aucFileName);
				AppUtils_FormatDisp("文件[%s]不存在!",aucFileName);
				continue;
			}
			
			#if 1
			ucRetCode = Comm_FtpUploadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("上传Ftp文件失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#else
			ucRetCode = Comm_FtpUploadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("上传Ftp文件失败,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#endif

			AppUtils_FormatDisp("上传Ftp文件[%s]成功!",aucFileName);
           	
            uiI = 0;
            pucPtr++;
			memset(aucFileName,0,sizeof(aucFileName));
            continue;
        }

		if( uiI>256 )
		{
			pucPtr = NULL;
			AppUtils_FormatDisp("文件名长度无效,超过最大长度[%d]\n",uiI);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
		
        aucFileName[uiI] = *pucPtr;
        uiI++;
        pucPtr++;
    }

	pucPtr = NULL;

	AppUtils_FormatDisp("上传本地目录文件到Ftp远程目录成功!\n");
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_Help
    FuncFunc : FTP项目帮助菜单
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
unsigned char FtpApp_Help(void *pDummy)
{
	unsigned char aucDispBuf[128],aucTitle[64];

	AppUtils_FormatDisp("\n");
	if( strlen(g_mApp.aucUserName) )
	{
		
		memset(aucDispBuf,0,sizeof(aucDispBuf));
		memset(aucDispBuf,'*',61);

		memset(aucTitle,0,sizeof(aucTitle));
		//sprintf(aucTitle,"欢迎%s使用",g_mApp.aucUserName);
		sprintf(aucTitle,"欢迎使用");
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.58s",FTPAPP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",FTPAPP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",FTPAPP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",FTPAPP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",FTPAPP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",FTPAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_Menu
    FuncFunc : FTP项目应用菜单
	Input	 : void *			— pDummy	入口参数标志
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
unsigned char FtpApp_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "Ftp单个文件下载",	FtpApp_DownloadFile, (void *) 3 },
		{ 2, "Ftp目录文件下载",	FtpApp_DownloadFiles, (void *) 3 },
		{ 3, "Ftp单个文件上传",	FtpApp_UploadFile, (void *) 3 },
		{ 4, "Ftp目录文件上传",	FtpApp_UploadFiles, (void *) 3 },
		{ 5, "帮助",    		FtpApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "Ftp文件");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}


