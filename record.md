## 塔奇克马的实现

1. 图片png，gif素材使用python获取处理
2. 客户端用QT写，实现桌宠
3. 学一下网络编程——实现在线塔奇克马聊天室、与好友通信
4. 在右键菜单栏中添加各种小工具（截图、英译中、
5. 登录注册数据库、部署腾讯云。
6. Git版本管理



可参考的学习资料

https://blog.csdn.net/Fdog_/article/details/115864249  仿QQ（登录注册部署实现！！大佬！）

去除背景:https://www.remove.bg/zh/upload

[网络编程之Socket详解 - 糯米粥 - 博客园 (cnblogs.com)](https://www.cnblogs.com/nsky/p/4501782.html) 

[Windows编程-6.网络编程-酷程网 (kucoding.com)](https://www.kucoding.com/article/90)

### 网络编程

端口：不同的端口对应于不同的服务(应用程序)http 使用80端口 ftp使用21端口 smtp使用 25端口。

socket：通常也称作“套接字”，用于描述IP地址和端口，是一个通信链的句柄。

**Socket有两种类型**

流式Socket（STREAM）：是一种面向连接的Socket，针对于面向连接的TCP服务应用，安全，但是效率低；

数据报式Socket（DATAGRAM）：是一种无连接的Socket,对应于无连接的UDP服务应用.不安全(丢失,顺序混乱,在接收端要分析重排及要求重发),但效率高.

服务器端的Socket(至少需要两个)，一个负责接收客户端连接请求(但不负责与客户端通信)，每成功接收到一个客户端的连接便在服务端产生一个对应的负责通信的Socket（端口号大于1024） 

客户端Socket 必须指定要连接的服务端地址和端口。 通过创建一个Socket对象来初始化一个到服务器端的TCP连接。

<img src="https://images0.cnblogs.com/blog2015/450977/201505/132050239072043.jpg" alt="img" style="zoom:50%;" />

```c++
SOCKET socket(
int af,	//地址类型，常用IPv4地址：AF_INET，和IPv6地址：AF_INET6
int type, //套接字类型，常用TCP协议：SOCK_STREAM,UDP协议：SOCK_DGRAM
int protocol //协议类型，一般填0，自动选择即可
);
//返回值，INVALID_SOCKET失败，该宏实则定义为-1，否则成功
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>
#include<iostream>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

class Server
{
public:
	int server() {
		// 初始化网络
		WSADATA data;
		int ret = WSAStartup(MAKEWORD(2, 2), &data);
		if (ret) {  // 返回值 0 代表成功
			std::cout << "初始化网络错误！" << std::endl;
			return -1;
		}
		// 创建套接字
		sock_sever = socket(AF_INET, SOCK_STREAM, 0);
		if (sock_sever == -1) {
			std::cout << "创建套接字失败";
			WSACleanup();
			return -1;
		}
		sockaddr_in addr;
		addr.sin_family = AF_INET; // ipv4
		addr.sin_port = htons(9999); // pot : 9999
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // 绑定到本机的ip地址
		ret = bind(sock_sever, (sockaddr*)&addr, sizeof(addr));
		if (ret == -1) {
			std::cout << "绑定地址端口失败";
			WSACleanup();
			return -1;
		}
		ret = listen(sock_sever, 5);  // 等待连接的最大队列长度 = 5
		if (ret == -1) {
			std::cout << "监听套接字失败";
			WSACleanup();
			return -1;
		}
		sockaddr addrCli;
		int len = sizeof(addrCli);
		std::cout << "等待接收客户端连接";
		SOCKET sockCli = accept(sock_sever, &addrCli, &len);
		if (sockCli == -1) {
			std::cout << "接收客户端连接失败";
			WSACleanup();
			return -1;
		}
		std::cout << "接收客户端连接成功";
		char buf[0xFF] = "我是服务器";
		ret = send(sockCli, buf, strlen(buf), 0);
		if (ret == -1) {
			std::cout << "发送信息失败";
			WSACleanup();
			return -1;
		}
		ret = recv(sockCli, buf, 0xFF, 0);
		if (ret <= 0) {
			std::cout << "接受客户端数据失败";
			WSACleanup();
			return -1;
		}
		WSACleanup();
		return 0;
	}


private:
	SOCKET sock_sever;
	

};

class Client
{
public:
	int client() {
		WSADATA data;
		int ret = WSAStartup(MAKEWORD(2, 2), &data);
		if (ret) {
			std::cout << "初始化网络错误！" << std::endl;
			WSACleanup();
			return -1;
		}
		SOCKET sock_cli = socket(AF_INET, SOCK_STREAM, 0);
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(9999);
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		ret = connect(sock_cli, (sockaddr*)&addr, sizeof(addr));
		if (ret == -1) {
			WSACleanup();
			std::cout << "连接服务器失败" << std::endl;
			return -1;
		}
		char buf[0xFF]{};
		ret = recv(sock_cli, buf, sizeof(buf), 0);
		if (ret <= 0) {
			WSACleanup();
			std::cout << "接收服务器数据失败" << std::endl;
			return -1;
		}
		std::cout << "服务器：" << buf << std::endl;

		ret = send(sock_cli, buf, ret, 0); //将接收到的数据发回服务器
		if (ret <= 0) {
			WSACleanup();
			std::cout << "发送服务器数据失败" << std::endl;
			return -1;
		}
		WSACleanup();
	}
	

private:
	
	SOCKET sock_cli;

};

int main() {

	Server s ;
	s.server();

	//Client c;
	//c.client();

}
```

### Qt 中 网络编程

快捷键：F2 跳转到函数定义，F4，h和cpp文件的切换。末尾Alt+Enter快速实现函数

.pro文件中 添加 

```c++
QT       += core gui network
```

网络编程的头文件

```c++
#include<QUdpSocket>
// 功能待补充：
udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

// broadcast msg
    udpSocket->writeDatagram(array.data(), array.size(), QHostAddress::Broadcast, this->port);
    
```

## 目前的bug

1. 发送消息是报错内存溢出——解决咯！2024-06-19 11:27

2. 退出会话窗口时，整个程序跟着退出——发现了问题connect(m_pMinAction,SIGNAL(triggered(bool)),this,SLOT(minwidget()));连接时，this是menu而不是Taqikema，可能是这有问题。md或许不用自定义的menu类了，全给它写Taqikema里面

3. 实现登录成功后，释放登录界面的内存，同时系统图标的菜单进行更改。——ok！2024-06-29 14:31
   1. 主窗口点击关闭按钮，释放了内存，但，程序没退出？？？

4. 目前的线上群聊貌似并不能实现真正的线上聊天，这仅是局域网的广播。——使用服务器-客户端模式实现群聊系统，同时为后续的数据库添加做准备。
