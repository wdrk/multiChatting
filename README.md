# 다중 접속 터미널 채팅 프로그램
---
- Client 프로그램과 Server 프로그램으로 구성한 터미널 기반의 채팅 프로그램입니다.
- Client가 접속할때마다 Server가 Thread를 생성하도록 하여 다중 접속이 가능하도록 만들었습니다.
- Client가 Server에 접속하기 위해서는 Client 코드에 상수로 정의한 IP_ADDRESS 값에 컴퓨터의 로컬 IP 값을 입력하면 됩니다.
- 접속하면 10개의 Thread를 이용해서 Server에 10번의 접속 요청을 하고 각 Thread마다 메세지를 전송하기 시작합니다.
- API Hook과 연계하여 테스트하기 위해 Client가 Server에 접속함과 동시에 임의의 메세지를 전송하는 구조입니다.
