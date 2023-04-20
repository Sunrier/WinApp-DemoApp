/*************************************************************************************************
	FileName : EmailApp.h
    FileFunc : 实现Email项目应用接口头文件
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : 实现Email项目应用入口函数头文件
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __EMAILAPP_H__
#define __EMAILAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	EMAILAPP_NAME				"Email测试"
#define 	EMAILAPP_FUNCTION			EMAILAPP_NAME "模拟应用软件"
#define 	EMAILAPP_VERSION			"00.00.01"
#define 	EMAILAPP_AUTHOR				APP_AUTHOR
#define 	EMAILAPP_CONTACT			APP_CONTACT
#define 	EMAILAPP_DATE				"2015-09-30 10:26:10"
#define 	EMAILAPP_DESCPTION			"Email项目应用软件"

/*SMTP命令以"行"传输\r\n*/
#define 	EMAILAPP_EOF				"\r\n"		//0x0D 0x0A

/*SMTP命令以"行"末尾无需添加\r\n*/
#define 	EMAILAPP_EOF_NONE			""

/*SMTP命令传输结束标志\r\n.\r\n*/
#define 	EMAILAPP_END				"\r\n.\r\n"		//0x0D 0x0A 0x2E 0x0D 0x0A

/*SMTP命令缩进标志(默认\t)*/
#define 	EMAILAPP_INDENT				"\t"

/*邮件MIME版本最大长度*/
#define		EMAILAPP_MIMEVER_MAXLEN		8

/*邮件编码集最大长度*/
#define		EMAILAPP_CHARSET_MAXLEN		16

/*邮件地址最小长度*/
#define		EMAILAPP_EMAILADDR_MINLEN	9

/*邮件地址最大长度*/
#define		EMAILAPP_EMAILADDR_MAXLEN	64

/*邮件用户名最小长度*/
#define		EMAILAPP_USERNAME_MINLEN	3

/*邮件用户名最大长度*/
#define		EMAILAPP_USERNAME_MAXLEN	32

/*邮件用户密码最大长度*/
#define		EMAILAPP_USERPASSWORD_MAXLEN	32

/*邮件服务器主机域名最小长度*/
#define		EMAILAPP_HOSTDOMAINNAME_MINLEN	5

/*邮件服务器主机域名最大长度*/
#define		EMAILAPP_HOSTDOMAINNAME_MAXLEN	16

/*邮件服务器主机地址最大长度*/
#define		EMAILAPP_HOSTIP_MAXLEN		15

/*邮件boundary标签最大长度*/
#define		EMAILAPP_BOUNDARY_MAXLEN	64

/*接收的邮件最大数量*/
#define		EMAILAPP_TOEMAIL_MAXNUM		50

/*接收的抄送邮件最大数量*/
#define		EMAILAPP_CCEMAIL_MAXNUM		10

/*接收的密送邮件最大数量*/
#define		EMAILAPP_BCCEMAIL_MAXNUM	10

/*发送的邮件标题最大长度*/
#define		EMAILAPP_SUBJECT_MAXLEN		256

/*发送的邮件正文行高度最大长度*/
#define		EMAILAPP_TEXT_LINEHEIGHT_MAXLEN		8

/*发送的邮件正文字体颜色最大长度*/
#define		EMAILAPP_TEXT_COLOR_MAXLEN			6

/*发送的邮件正文字体大小最大长度*/
#define		EMAILAPP_TEXT_FONTSIZE_MAXLEN		8

/*发送的邮件正文字体名称最大长度*/
#define		EMAILAPP_TEXT_FONTFAMILY_MAXLEN		32

/*发送的邮件内容最大长度*/
#define		EMAILAPP_TEXT_MAXLEN		(1024*16)	//16k

/*发送的正文类型最大长度*/
#define		EMAILAPP_CONTENTTYPE_MAXLEN		128

/*发送的邮件附件最大数量*/
#define		EMAILAPP_ATTACHMENT_MAXNUM		10

/*发送的邮件附件文件名最大长度*/
#define		EMAILAPP_ATTACHMENTFILENAME_MAXLEN		256

/*邮件正文类型:主类型/子类型*/
typedef enum _EMAIL_CONTENTTYPE
{	
	CONTENTTYPE_TEXT_PLAIN = 0,				/*text/plain:1.txt(纯文本)*/
	CONTENTTYPE_TEXT_HTML,					/*text/html:1.htm(html文挡)*/
	CONTENTTYPE_TEXT_X_C,					/*text/x-c:1.c/1.cpp/1.h(c文挡)*/
	CONTENTTYPE_TEXT_X_JAVA_SOURCE,			/*text/x-java-source:1.java(java文挡)*/
	CONTENTTYPE_IMAGE_GIF,					/*image/gif:1.gif(GIF图像)*/
	CONTENTTYPE_IMAGE_JPEG,					/*image/jpeg:1.jpeg(JPEG图像)*/
	CONTENTTYPE_IMAGE_PNG,					/*image/png:1.png(PNG图像)*/
	CONTENTTYPE_VIDEO_MPEG,					/*video/mpge:1.mpeg(MPEG动画)*/
	CONTENTTYPE_APPLICATION_XHTML_XML,		/*application/xhtml+xml:1.htm(XHTML文挡)*/
	CONTENTTYPE_APPLICATION_MSWORD,			/*application/msword:1.doc(Microsoft Word文档)*/
	CONTENTTYPE_APPLICATION_MSWORDX,		/*application/vnd.openxmlformats-officedocument.wordprocessingml.document:1.docx(docx文挡)*/
	CONTENTTYPE_APPLICATION_MSXLS,			/*application/msxls:1.xls(xls文档)*/
	CONTENTTYPE_APPLICATION_MSXLSX,			/*application/vnd.openxmlformats-officedocument.spreadsheetml.sheet:1.xlsx(xls文挡)*/
	CONTENTTYPE_APPLICATION_MSPPT,			/*application/msppt:1.ppt(ppt文档)*/
	CONTENTTYPE_APPLICATION_MSPPTX,			/*application/vnd.openxmlformats-officedocument.presentationml.presentation:1.pptx(pptx文挡)*/
	CONTENTTYPE_APPLICATION_PDF,			/*application/pdf:1.pdf(PDF文档)*/
	CONTENTTYPE_APPLICATION_X_TGIF,			/*application/x-tgif:XX.obj*/
	CONTENTTYPE_APPLICATION_OCTET_STREAM,	/*application/octet-stream:323(任意的二进制数据)*/
}EMAIL_CONTENTTYPE;

/*发送的邮件信息*/
typedef struct _FROMEMAIL_PRM{
	unsigned char ucUserPasswordFlag;									/*邮件用户密码标志:0-明文 1-加密(默认)*/
	unsigned short usServerHostPort;									/*发送邮件服务器主机端口(默认25)*/
	unsigned char aucFromEmail[EMAILAPP_EMAILADDR_MAXLEN+1];			/*发送邮件地址:qq邮箱需要设置开启pop3/smtp服务(qq邮箱需要使用验证码作为密码登陆)*/
	unsigned char aucUserName[EMAILAPP_USERNAME_MAXLEN+1];				/*发送邮件用户名*/
	unsigned char aucUserPassword[EMAILAPP_USERPASSWORD_MAXLEN+1];		/*发送邮件用户密码:qq邮箱需要使用验证码作为密码登陆*/
	unsigned char aucServerHostName[EMAILAPP_HOSTDOMAINNAME_MAXLEN+1];	/*发送邮件服务器主机域名*/
	unsigned char aucServerHostIp[EMAILAPP_HOSTIP_MAXLEN+1];			/*发送邮件服务器主机IP*/
	unsigned char aucBoundary[EMAILAPP_BOUNDARY_MAXLEN+1];				/*发送的boundary标签*/
}FROMEMAIL_PRM;

/*接收的邮件地址信息*/
typedef struct _TOEMAIL_PRM{
	unsigned char aucToEmail[EMAILAPP_EMAILADDR_MAXLEN+1];	/*发送的邮件地址*/
}TOEMAIL_PRM;

/*接收的邮件组*/
typedef struct _TOEMAILGROUP_PRM{
	unsigned char ucToEmailHideFlag;						/*接收的邮件组信息是否隐藏:0-不隐藏 非0-隐藏*/
	int iToEmailNum;										/*接收的邮件信息数量*/
	TOEMAIL_PRM mToEmail[EMAILAPP_TOEMAIL_MAXNUM];			/*接收的邮件信息*/
}TOEMAILGROUP_PRM;

/*接收的抄送邮件组*/
typedef struct _CCEMAILGROUP_PRM{
	unsigned char ucCcEmailHideFlag;						/*接收的抄送邮件组信息是否隐藏:0-不隐藏 非0-隐藏*/
	int iCcEmailNum;										/*接收的抄送邮件信息数量*/
	TOEMAIL_PRM mCcEmail[EMAILAPP_CCEMAIL_MAXNUM];			/*接收的抄送邮件信息*/
}CCEMAILGROUP_PRM;

/*接收的密送邮件组*/
typedef struct _BCCEMAILGROUP_PRM{
	unsigned char ucBccEmailHideFlag;						/*接收的密送邮件组信息是否隐藏:0-不隐藏 非0-隐藏*/
	int iBccEmailNum;										/*接收的密送邮件信息数量*/
	TOEMAIL_PRM mBccEmail[EMAILAPP_BCCEMAIL_MAXNUM];		/*接收的密送邮件信息*/
}BCCEMAILGROUP_PRM;

/*
line-height:
检索或设置对象的行高,即字体最底端与字体内部顶端之间的距离;
用line-height只对文字起作用,对于图片时失效;

color:
用来设置文字字体颜色;
字体颜色参考:https://blog.csdn.net/IT1039871366/article/details/46726979

font-size:用来设置文字,字体大小,常用的单位是px像素,还有%百分比,移动端用的单位em;
1)px像素单位font-size：20px；
提示:网页文字默认的字体大小是12px,也就是你设置的字体小于12px,默认都会以12px大小显示;
面试经常会问到,如何在页面小于12px的字体;
2)%百分比单位百分比相对父元素的font-size大小而言字体大小以百分比为单位,相对的是父元素font-size大小;
3)font-size字体粗细设置字体的粗细,通常使用的值有normal和bold两个值或其对应数字400与700来表示normal表示正常；
bold表示加粗;bloder表示更粗的字符;lighter表示更细的字符
number:100,200

font-family:用来设置字体名称;
字体名称参考:https://www.w3school.com.cn/css/css_font.asp
宋体 SimSun
黑体 SimHei
微软雅黑 Microsoft YaHei
微软正黑体 Microsoft JhengHei
新宋体 NSimSun
新细明体 PMingLiU
细明体 MingLiU
标楷体 DFKai-SB
仿宋 FangSong
楷体 KaiTi
仿宋_GB2312 FangSong_GB2312
楷体_GB2312 KaiTi_GB2312
宋体：SimSuncss中中文字体（font-family）的英文名称

Mac OS的一些：
华文细黑：STHeiti Light [STXihei]
华文黑体：STHeiti
华文楷体：STKaiti
华文宋体：STSong
华文仿宋：STFangsong
儷黑 Pro：LiHei Pro Medium
儷宋 Pro：LiSong Pro Light
標楷體：BiauKai
蘋果儷中黑：Apple LiGothic Medium
蘋果儷細宋：Apple LiSung Light

Windows的一些：
新細明體：PMingLiU
細明體：MingLiU
標楷體：DFKai-SB
黑体：SimHei
新宋体：NSimSun
仿宋：FangSong
楷体：KaiTi
仿宋_GB2312：FangSong_GB2312
楷体_GB2312：KaiTi_GB2312
微軟正黑體：Microsoft JhengHei
微软雅黑体：Microsoft YaHei

装Office会生出来的一些：
隶书：LiSu
幼圆：YouYuan
华文细黑：STXihei
华文楷体：STKaiti
华文宋体：STSong
华文中宋：STZhongsong
华文仿宋：STFangsong
方正舒体：FZShuTi
方正姚体：FZYaoti
华文彩云：STCaiyun
华文琥珀：STHupo
华文隶书：STLiti
华文行楷：STXingkai
华文新魏：STXinwei

Windows平台的默认情况下,浏览器的字体是宋体;
中文字体常用的有宋体、微软雅黑;
英文字体比较常用的有Times New Roman、Arial;
Arial是Win与Mac兼有的字体;
*/
/*邮件正文属性信息*/
typedef struct _TEXT_ATTR_PRM{
	//line-height:1.7;color:#538bd7;font-size:20px;font-family:Arial
	unsigned char aucLineHeight[EMAILAPP_TEXT_LINEHEIGHT_MAXLEN+1];	/*行高度*/
	unsigned char aucColor[EMAILAPP_TEXT_COLOR_MAXLEN+1];			/*字体颜色:https://blog.csdn.net/IT1039871366/article/details/46726979*/
	unsigned char aucFontSize[EMAILAPP_TEXT_FONTSIZE_MAXLEN+1];		/*字体大小*/
	unsigned char aucFontFamily[EMAILAPP_TEXT_FONTFAMILY_MAXLEN+1];	/*字体名称*/
}TEXT_ATTR_PRM;

/*邮件正文信息*/
typedef struct _EMAIL_BODY_PRM{
	unsigned char ucTextDecorationFlag;						/*邮件正文是否修饰:0-不修饰 非0-修饰*/
	unsigned char ucTextBase64Flag;							/*邮件内容是否Base64编码:0-不编码 1-编码 其他-编码*/
	unsigned char aucText[EMAILAPP_TEXT_MAXLEN+1];			/*邮件内容*/
	TEXT_ATTR_PRM mTextAttr;								/*邮件正文修饰属性信息(邮件正文修饰才有效)*/
}EMAIL_BODY_PRM;

/*发送的附件信息*/
typedef struct _ATTACHMENT_PRM{
	unsigned char ucContentType;												/*正文类型:参考枚举类型EMAIL_CONTENTTYPE*/
	unsigned char aucContentType[EMAILAPP_CONTENTTYPE_MAXLEN+1];				/*正文类型字符串:提升效率*/
	unsigned char aucAttachmentFileName[EMAILAPP_ATTACHMENTFILENAME_MAXLEN+1];	/*全路径:发送的附件文件名*/
}ATTACHMENT_PRM;

/*发送的附件组*/
typedef struct _ATTACHMENTGROUP_PRM{
	unsigned char ucAttachmentFlag;							/*发送的邮件是否存在附件:0-不存在 非0-存在*/
	unsigned char ucAttachmentEncodeFlag;					/*发送的附件信息(如附件文件名)是否编码:0-不编码 1-GB2312编码 2-UTF8编码 其他-GB2312编码*/
	int iAttachmentNum;										/*发送的附件信息数量*/
	unsigned char aucBoundary[EMAILAPP_BOUNDARY_MAXLEN+1];	/*发送的附件boundary标签*/
	ATTACHMENT_PRM mAttachment[EMAILAPP_ATTACHMENT_MAXNUM];	/*发送的附件信息*/
}ATTACHMENTGROUP_PRM;

/*邮件信息参数*/
typedef struct _EMAIL_PRM{

	unsigned char aucMIMEVer[EMAILAPP_MIMEVER_MAXLEN+1];	/*MIME版本:默认1.0*/
	unsigned char aucCharset[EMAILAPP_CHARSET_MAXLEN+1];	/*默认编码集:GBK(163)/gb18030(qq)/GB2312*/
	unsigned char ucHeadEncodeFlag;							/*邮件头信息(如邮件地址)是否编码:0-不编码 1-GB2312编码 2-UTF8编码 其他-GB2312编码*/
	FROMEMAIL_PRM mFromEmail;								/*发送的邮件信息*/
	TOEMAILGROUP_PRM mToEmailGroup;							/*接收的收件邮件组信息*/
	CCEMAILGROUP_PRM mCcEmailGroup;							/*接收的抄送邮件组信息*/
	BCCEMAILGROUP_PRM mBccEmailGroup;						/*接收的密送邮件组信息*/
	unsigned char ucSubjectEncodeFlag;						/*邮件标题是否编码:0-不编码 1-GB2312编码 2-UTF8编码 其他-GB2312编码*/
	unsigned char aucSubject[EMAILAPP_SUBJECT_MAXLEN+1];	/*邮件标题*/
	EMAIL_BODY_PRM mBody;									/*发送的邮件正文信息*/
	ATTACHMENTGROUP_PRM mAttachmentGroup;					/*发送的附件信息*/
}EMAIL_PRM;

/***********************************************************************************************
	FuncName : EmailApp_Menu
    FuncFunc : Email项目应用菜单
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
unsigned char EmailApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif












