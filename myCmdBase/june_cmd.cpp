#include "june_cmd.h"

int june_cmd(int argc, char (*argv)[ARG_SIZE]){
	cout << "������ ���ؼ�" << endl;
	Sleep(1000);
	cout << argc <<"���� ���ذ����η������Ͽ�" << endl;
	Sleep(1000);
	cout << endl;

	for(int i = 0; i< argc;i++){
		cout << "�� " << i << "����(" << argv[i] << "�� ���� ���ٰ� �Ͽ�" << endl;
		Sleep(1000);
	}

	Sleep(1000);
	cout << argc <<"���Ǿ��ش°����������ؿͽȾ��ϴ¾��ر׷��Ի��̸𿴼�."<<endl;
	Sleep(1000);
	cout << "(�̷�Ŀ�ǵ�¾��°������󸮳��Ҽ�)";
	Sleep(1000);

	system("shutdown -s -t 300 -c \"��������մϴ�\"");
	Sleep(1000);
	system("shutdown -a -c \"��������\"");
	Sleep(1000);
	return 0;
}	
	
	