#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <conio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#include <WS2tcpip.h>
#include <tchar.h>

// 메세지를 몇 번 보낼지 설정하는 상수입니다.
#define LOOP_COUNT 10

// 접속할 서버의 IP 주소를 설정하는 상수입니다.
#define IP_ADDRESS "127.0.0.1"

#define THREADS_COUNT 10

SOCKADDR_IN& svraddrInit(SOCKADDR_IN& svraddr)
{
	svraddr.sin_family = AF_INET;
	svraddr.sin_port = htons(25000);
	inet_pton(AF_INET, IP_ADDRESS, &svraddr.sin_addr.S_un.S_addr);
	return svraddr;
}

DWORD WINAPI chatThread(LPVOID pParam)
{
	SOCKET hSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN svraddr = { 0 };
	svraddrInit(svraddr);
	::connect(hSocket, (SOCKADDR*)&svraddr, sizeof(svraddr));

	std::string strRandomWords[]{ 
		"hello",
		"hi",
		"greeting",
		"welcome",
		"bye",
		"good",
		"bad",
		"nice",
		"cpp",
		"prog",
		"mac",
		"windows",
		"ok",
		"what" };

	// 1. 시드 생성기: 시스템 클럭을 이용하여 시드 생성
	std::random_device rd;  // 실제 하드웨어 엔트로피 소스 기반(시스템에 따라 다를 수 있음)
	std::mt19937 gen(rd()); // Mersenne Twister 난수 생성기, 시드로 초기화

	// 2. 분포 정의: 1부터 100까지의 정수 범위
	std::uniform_int_distribution<> dis(0, 9);

	for (int i = 0; i < LOOP_COUNT; ++i)
	{

		::send(hSocket, strRandomWords[dis(gen)].c_str(), strRandomWords[dis(gen)].size(), 0);
		Sleep(1);
	}

	OutputDebugStringA("[ Thread Send Complete ]\n");
	return 0;
}

auto __cdecl main(int argc, char* argv[]) -> int
{
	WSADATA wsa = { 0 };
	::WSAStartup(0x0202, &wsa);

	printf("Input Any Key");
	_getch();
	putchar('\n');

	HANDLE hThreadArray[THREADS_COUNT] = { nullptr };
	for (int i = 0; i < THREADS_COUNT; ++i)
	{
		SOCKET hSocket = ::socket(AF_INET, SOCK_STREAM, 0);
		std::string strObject{ "**** Thread [ " + std::to_string(i) + " ] Running ****" };
		hThreadArray[i] = ::CreateThread(NULL, 0, chatThread, (LPVOID)hSocket, 0, NULL);
		std::cout << strObject << "\n";
		OutputDebugStringA(strObject.c_str());
		::shutdown(hSocket, SD_BOTH);
		::closesocket(hSocket);
	}
	DWORD dwTemp = WaitForMultipleObjects(THREADS_COUNT, hThreadArray, true, INFINITE);
	
	::Sleep(100);
	::WSACleanup();
	OutputDebugStringA("[[[[[[[[[[ Good Bye ]]]]]]]]]]]");

	return 0;
}