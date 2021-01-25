/*************************************************************************************************
	FileName : demotapp.c
    FileFunc : ʵ��demoӦ�ýӿ�
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2013-08-05 18:13:15
	Descp    : ʵ��demoӦ����ں���
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"



/***********************************************************************************************
	FuncName : DemoApp_InitTranCfg
    FuncFunc : ��ʼ�������ļ���Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
    FuncFunc : ��ȡDemo��Ŀ������Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_GetTranCfg( void )
{
	unsigned char aucFileName[100];		/*�����ļ���*/
	unsigned char aucSectionName[100];	/*����*/
	unsigned char aucKeyName[100];		/*����*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];	/*��ֵ*/
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

	/*��ȡ��ǰͨѶ����*/
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

	/*��ȡ���ں�COMMPORT*/
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

	/*��ȡ���ڲ�����BAUDRATE*/
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
	
	/*��ȡTCPͨѶ��ַIP1*/
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

	/*��ȡTCPͨѶ�˿�PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
	}

	/*��ȡTCPͨѶ������ַIP2*/
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
	
	//��ȡTCPͨѶ�����˿�PORT2
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT2[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱ�Ƿ�֧�ֿ��Э��0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPLIBFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x04;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPLIBFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱURL�Ƿ��Խ���0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x01;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https�Ƿ�֧��URL�Խ���ʧ�ܺ���Host IP/Name 0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLCOMMFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x02;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLCOMMFLAG[%s]!",aucKeyValue);
	}

	/*http��https���յİ��Ƿ��Խ���:0-������ 1-����*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOHTTPPARSEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x08;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOHTTPPARSEFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱ���󷽷�:0-POST���� 1-GET����*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPWAYFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucRequestWayFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPWAYFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��URL*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","URL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=256) ) )
	{
		strcpy(g_mTermCfg.aucHttpURL,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "URL[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��DOMAIN*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DOMAIN");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpDomain,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DOMAIN[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��PAGE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PAGE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpPage,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PAGE[%s]!",aucKeyValue);
	}

	/*��ȡTCPͨѶ��������HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*��ȡTCPͨѶ��������HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}

	/*��ȡ�Ƿ�֧�ֱ���*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);

	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*��ȡ�Ƿ�֧�ֱ�����������*/
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

	/*��ȡ����ͨѶ��ʱ(S)RS232Timeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*��ȡTCPͨѶ��ʱʱ��(S)TcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*��ȡ�Ƿ�֧��SSLͨѶ*/
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

	/*��ȡSSLͨѶ��ʱʱ��(S)SSLTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}

	/*��ȡ�������趨��IP��ַ*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}

	/*��ȡ����������PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}

	/*��ȡTCP����������ʱ��ʱʱ��(S)*/
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
    FuncFunc : ��ʼ����Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
	
	AppUtils_DisplayLeft("ͨѶ��ʼ��...\n", LINE2);
	AppUtils_DisplayLeft("���Ժ�...\n", LINE3);

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
    FuncFunc : DemoӦ�ó�ʼ��
	Input	 : void *			�� pDummy	����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
    FuncFunc : DEMO��Ŀ�����˵�
	Input	 : void *			�� pDummy	����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
		sprintf(aucTitle,"��ӭ%sʹ��",g_mApp.aucUserName);
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_FUNCTION);
	AppUtils_FormatDisp("**����汾:%.58s",DEMOAPP_VERSION);  
	AppUtils_FormatDisp("**��Ȩ����:%.58s",DEMOAPP_AUTHOR);
	AppUtils_FormatDisp("**�����ϵ:%.58s",DEMOAPP_CONTACT);
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_DESCPTION);
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : DemoApp_Menu
    FuncFunc : Demo��ĿӦ�ò˵�
	Input	 : void *	�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ذ���ֵ
								�� ʧ��,���س�ʱ��ȡ��
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
		{ 1, "������Ŀ",	BaseApp_Menu, (void *) 0 },
		{ 2, "FTP��Ŀ",		FtpApp_Menu, (void *) 0 },
		{ 3, "Email��Ŀ",	EmailApp_Menu, (void *) 0 },
		{ 4, "����",    	DemoApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "������ĿӦ��");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}







