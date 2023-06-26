#include <stdio.h>
#include <winsock.h>

int main()
{
  char SendBuf[100];
  char RecvBuf[100];
  int sendLen;
  int recvLen;
  int Length; // SOCKETADDR的大小

  SOCKET socketServer;
  SOCKET socketReceive;

  SOCKADDR_IN serverAddr;
  SOCKADDR_IN clientAddr;

  WORD wVersionRequested;
  WSADATA wsaData;
  int error;

  error = WSAStartup(wVersionRequested, &wsaData);
  if (error != 0)
  {
    printf("Load socket failed.");
    return 0;
  }

  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
  {
    WSACleanup();
    return 0;
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = htons(9988);

  socketServer = socket(AF_INET, SOCK_STREAM, 0);
  if (socketServer == INVALID_SOCKET)
  {
    printf("Create socket failed.");
    return 0;
  }

  // bind
  if (bind(socketServer, (SOCKADDR *)&serverAddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
  {
    printf("Bind socket failed.");
    return 0;
  }

  // listen
  if (listen(socketServer, 5) < 0)
  {
    printf("Listen socket failed.");
    return 0;
  }

  Length = sizeof(SOCKADDR);
  socketReceive = accept(socketServer, (SOCKADDR *)&clientAddr, &Length);
  if (socketReceive == SOCKET_ERROR)
  {
    printf("Accept connect failed.");
  }

  while (1)
  {
    recvLen = recv(socketReceive, RecvBuf, sizeof(RecvBuf), 0);
    if (recvLen == SOCKET_ERROR)
    {
      printf("Receive data failed.");
      break;
    }

    printf("%s", RecvBuf);
  };

  closesocket(socketReceive);
  closesocket(socketServer);
  WSACleanup();

  return 0;
}