// myCmdBase.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
			{"pf1", testCmd},  // �̰��� �Լ��� �߰��ϸ� �˴ϴ�.
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
	// ����� �Է��� ���� ������ ������ ��� 
	int inputArgc = parseCommand(input, inputArgv);
	// Ŀ�ǵ带 ���Ͽ� ������ Ŀ�ǵ� �Լ��� �޴´�.
	PF pf = getCommander(inputArgv);
	// Ŀ�ǵ� �Լ� ȣ��
	pf(inputArgc, inputArgv);
	return 0;
}

// ���ڿ��� ���� ������ ������.
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

// ���� �� ���ڿ��� �̿��Ͽ� ��ġ�ϴ� Ŀ�ǵ带 �����´�.
PF getCommander(ARGV argv){
	for( int i=0; i<sizeof(cmds)/sizeof(Cmds); i++)
		if( strcmp(argv[0], cmds[i].cmdName ) == 0 )
			return cmds[i].cmd;
	return NULL;
}
