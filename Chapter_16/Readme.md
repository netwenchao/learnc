# TCP套接字

TCP是面向连接的可靠的传输协议。利用TCP协议进行通信时，首先要建立通信双方的连接。一旦连接建立完成，就可以进行通信。TCP提供了数据确认和数据重传的机制，保证了发送的数据一定能到达通信的对方。

## 面向连接的socket变成的服务器端程序流程
-  创建套接字socket；
-  将创建的套接字绑定（bind）到本地的地址和端口上；
-  设置套接字的状态为监听状态（listen），准备接受客户端的连接请求；
-  接受请求 （accept），同时返回得到一个用于连接的新套接字；
-  使用这个新套接字进行通信（通信函数使用send/recv）；
-  通信完毕，释放套接字资源（closesocket）。

## 面向连接的socket变成的客户端程序流程
- 创建套接字socket；
- 向服务器发出连接请求（connect）；
- 连接后，与服务器进行通信操作（send/recv）;
- 释放套接字资源（closesocket）。

对于服务器端来说，一旦建立连接，实际上它已经保存了客户端的IP地址和端口号的信息，因此可以利用返回的套接字进行与客户端的通信。

# UDP套接字

UDP是无连接的不可靠的传输协议。采用UDP进行通信时，不需要建立连接，可以直接向一个IP地址发送数据，但是不能保证对方能收到。

对于基于UDP，面向无连接的套接字编程来说，服务器端和客户端的概念不是特别的严格。可以把服务器称为接收端，客户端就是发送数据的发送端。

## 基于UDP，面向无连接的socket编程的接收端程序流程如下。
- （1）创建套接字socket。
- （2）将套接字绑定（bind）到一个本地地址和端口上。
- （3）等待接收数据（recvfrom）。
- （4）释放套接字资源（closesocket）。
  
## 基于UDP，面向无连接的socket编程的发送端程序流程如下。
- （1）创建套接字socket。
- （2）向服务器发送数据（sendto）。
- （3）释放套接字资源（closesocket）。

注意基于UDP的套接字编程中，仍然需要使用bind进行绑定。虽然面向无连接的socket编程无须建立连接，但为了完成通信，首先应启动接收端，等待接收发送端发来的数据，这样接收端就必须告诉它自己的地址和端口。

因此，必须调用bind函数将套接字绑定到一个本地地址和端口上。基于UDP的套接字编程时，利用的是sendto和recvfrom两个函数实现数据的发送和接收；基于TCP的套接字编程时，发送数据使用的是send函数，接收数据使用的是recv函数。

# 函数

## 1. WSAStartup `int WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData)`

WSAStartup函数用于初始化Ws2_32.dll动态链接库。在使用其他套接字函数之前，必须先初始化Ws2_32.dll动态链接库。
- wVersionRequested：表示调用者使用的WinSock版本，高字节记录修订版本，低字节记录主版本。例如，如果WinSock的版本为2.1，则高字节记录1，低字节记录2。
- lpWSAData：WSADATA结构指针，详细记录了Windows套接字的相关信息。其定义如下：
```
typedef struct WSAData{
  WORD wVersion;               //调用者使用的WS2_32.dll动态库的版本号
  WORD wHighVersion;           //调用者使用的WS2_32.dll支持的最高版本，通常与wVersion相同
  char szDescription[];        //描述信息  --无实际意义
  char szSystemStatus[];       //系统的配置或状态信息  --无实际意义
  unsigned short iMaxSockets;  //最多打开多少个套接字，WinSock2+，成员将被忽略
  unsigned short iMaxUdpDg;    //数据包的做大长度,WinSock2+，成员将被忽略
  char FAR * lpVendorInfo;     //厂商信息，WinSock2+，成员将被忽略
} WSADATA,FAR * LPWSADATA;
```

## 2. socket `SOCKET socket(int af, int type, int protocol)`

创建一个套接字。
- af:表示一个地址家族，通常为AF_INET;
- type:表示套接字类型。winsock2.h头文件中定义
  - SOCKET_STREAM:流式套接字
  - SOCKET_DGRAM:数据报套接字
  - SOCKET_RAW:原始套接字
- protocol:采用的协议，不指定，可设置为 0
- 返回值：创建的套接字句柄

## 3. bind `int bind(SOCKET s, const struct sockaddr FAR* name, int namelen);`

bind函数的功能是将套接字绑定到指定的端口和地址上。
- s：套接字标识。
- name：sockaddr结构指针，包含了要结合的地址和端口号。
- namelen：表示name缓冲区的长度。
- 返回值：如果函数执行成功，则返回值为0，否则为SOCKET_ERROR

## 4. listen `int listen(SOCKET s, int backlog)`

listen函数的功能是将套接字设置为监听模式。对于流式套接字，必须处于监听模式才能够接收客户端套接字的连接。
- s：套接字标识。
- backlog：表示等待连接的最大队列长度。例如，如果backlog被设置为2，此时有3个客户端同时发出连接请求，那么前两个客户端连接会放置在等待队列中，第3个客户端会得到错误信息。

## 5. accept
## 6. closesocket
## 7. connect
## 8. htons
## 9. htonl
## 10. int_addr
## 11. recv
## 12. send
## 13. recvfrom
## 14. sendto
## 15. WSAClearup