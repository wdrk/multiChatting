#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <conio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#include <WS2tcpip.h>
#include <tchar.h>

// �޼����� �� �� ������ �����ϴ� ����Դϴ�.
#define LOOP_COUNT 10

// ������ ������ IP �ּҸ� �����ϴ� ����Դϴ�.
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

	// 1. �õ� ������: �ý��� Ŭ���� �̿��Ͽ� �õ� ����
	std::random_device rd;  // ���� �ϵ���� ��Ʈ���� �ҽ� ���(�ý��ۿ� ���� �ٸ� �� ����)
	std::mt19937 gen(rd()); // Mersenne Twister ���� ������, �õ�� �ʱ�ȭ

	// 2. ���� ����: 1���� 100������ ���� ����
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