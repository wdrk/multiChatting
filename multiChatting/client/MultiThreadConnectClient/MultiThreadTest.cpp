#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#include <WS2tcpip.h>
#include <tchar.h>
#pragma warning(disable : 4996)

// 메세지를 몇 번 보낼지 설정하는 상수입니다.
#define LOOP_COUNT 10

// 접속할 서버의 IP 주소를 설정하는 상수입니다.
#define IP_ADDRESS "127.0.0.1"

#define THREADS_COUNT 10

SOCKADDR_IN& svraddrInit()
{
	SOCKADDR_IN svraddr = { 0 };
	svraddr.sin_family = AF_INET;
	svraddr.sin_port = htons(25000);
	svraddr.sin_addr.S_un.S_addr = inet_addr(IP_ADDRESS);
	return svraddr;
}

DWORD WINAPI Thread1(LPVOID pParam)
{
	SOCKET hSocket1 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket1, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "11111111111111111111";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket1, szMessage, nLength, 0);
		Sleep(1);
	}

	_tprintf(_T("Thread [ 1 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread1 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread2(LPVOID pParam)
{
	SOCKET hSocket2 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket2, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "22222222222222222222";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket2, szMessage, strlen(szMessage) + 1, 0);
	}
 
	_tprintf(_T("Thread [ 2 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread2 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread3(LPVOID pParam)
{
	SOCKET hSocket3 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket3, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "33333333333333333333";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket3, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 3 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread3 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread4(LPVOID pParam)
{
	SOCKET hSocket1 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket1, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "44444444444444444444";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket1, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 4 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread4 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread5(LPVOID pParam)
{
	SOCKET hSocket2 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket2, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "55555555555555555555";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket2, szMessage, strlen(szMessage) + 1, 0);
	}
 
	_tprintf(_T("Thread [ 5 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread5 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread6(LPVOID pParam)
{
	SOCKET hSocket3 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket3, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "66666666666666666666";
	int nLength = strlen(szMessage);
	++nLength;

	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket3, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 6 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread6 Send Complete ]\n");
	return 0;
}
DWORD WINAPI Thread7(LPVOID pParam)
{
	SOCKET hSocket1 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket1, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "77777777777777777777";

	int nLength = strlen(szMessage);
	++nLength;
	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket1, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 7 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread7 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread8(LPVOID pParam)
{
	SOCKET hSocket2 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket2, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "88888888888888888888";

	int nLength = strlen(szMessage);
	++nLength;
	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket2, szMessage, strlen(szMessage) + 1, 0);
	}
 
	_tprintf(_T("Thread [ 8 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread8 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread9(LPVOID pParam)
{
	SOCKET hSocket3 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket3, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "99999999999999999999";

	int nLength = strlen(szMessage);
	++nLength;
	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket3, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 9 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread9 Send Complete ]\n");
	return 0;
}

DWORD WINAPI Thread0(LPVOID pParam)
{
	SOCKET hSocket3 = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = svraddrInit();
	::connect(hSocket3, (SOCKADDR*)&svraddr, sizeof(svraddr));

	int i = 0;
	char szMessage[32] = "0000000000000000000";

	int nLength = strlen(szMessage);
	++nLength;
	for (i = 0; i < LOOP_COUNT; ++i)
	{
		::send(hSocket3, szMessage, strlen(szMessage) + 1, 0);
	}

	_tprintf(_T("Thread [ 0 ] Count : %d\n"), i);
	OutputDebugStringA("[ Thread0 Send Complete ]\n");
	return 0;
}

auto __cdecl main(int argc, char* argv[]) -> int
{
	WSADATA wsa = { 0 };
	::WSAStartup(0x0202, &wsa);

	printf("Input Any Key");
	_getch();
	putchar('\n');

	HANDLE hThreadArray[10] = { nullptr };
	std::vector<HANDLE> vt(THREADS_COUNT);
	for (int i = 0; i < vt.size(); ++i)
	{
		SOCKET hSocket = ::socket(AF_INET, SOCK_STREAM, 0);
		std::string strObject{ "**** Thread [ " + std::to_string(i) + " ] Running ****" };
		vt[i] = ::CreateThread(NULL, 0, Thread1, (LPVOID)hSocket, 0, NULL);
		OutputDebugStringA(strObject.c_str());
		::shutdown(hSocket, SD_BOTH);
		::closesocket(hSocket);
	}
	DWORD dwTemp = WaitForMultipleObjects(10, hThreadArray, true, INFINITE);
	
	::Sleep(100);
	::WSACleanup();
	OutputDebugStringA("[[[[[[[[[[ Good Bye ]]]]]]]]]]]");

	return 0;
}