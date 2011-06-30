// myCmdBase.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>

#define ARG_SIZE 256
#define ARG_NUM 20

#include "cmdTest.h"
#include "june_cmd.h"

typedef char (*ARGV)[ARG_SIZE];
typedef int (*PF)(int, ARGV);

struct Cmds{
	char cmdName[256];
	PF cmd;
} cmds[] = {{"pf0", testCmd},
			{"pf1", testCmd},  // 이곳에 함수를 추가하면 됩니다.
			{"pf2", testCmd},	
			{"jc",june_cmd}	
};

int parseCommand(char* str, ARGV argv);
PF getCommander(ARGV argv);

int _tmain(int argc, _TCHAR* argv[])
{
	char input[256];
	char inputArgv[ARG_NUM][ARG_SIZE] = {0,};

	cout<<"input your command : ";
	cin>>input;
	// 사용자 입력을 띄어쓰기 단위로 나누고 몇개로 
	int inputArgc = parseCommand(input, inputArgv);
	// 커맨드를 비교하여 적절한 커맨드 함수를 받는다.
	PF pf = getCommander(inputArgv);
	// 커맨드 함수 호출
	pf(inputArgc, inputArgv);
	return 0;
}

// 문자열을 띄어쓰기 단위로 나눈다.
int parseCommand(char* str, ARGV argv){
	if( strlen(str) <= 0 )
		return 0;               // no command
	char* ptr = strtok( str, " ");
	strcpy( argv[0], ptr);
	int i;
	for( i=1; ptr = strtok( NULL, " "); i++)
		strcpy(argv[i], ptr);
	return i;
}

// 가장 앞 문자열을 이용하여 일치하는 커맨드를 가져온다.
PF getCommander(ARGV argv){
	for( int i=0; i<sizeof(cmds)/sizeof(Cmds); i++)
		if( strcmp(argv[0], cmds[i].cmdName ) == 0 )
			return cmds[i].cmd;
	return NULL;
}
