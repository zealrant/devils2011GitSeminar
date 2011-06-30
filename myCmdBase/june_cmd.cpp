#include "june_cmd.h"

int june_cmd(int argc, char (*argv)[ARG_SIZE]){
	cout << "만든이 김준석" << endl;
	Sleep(1000);
	cout << argc <<"인의 아해가도로로질주하오" << endl;
	Sleep(1000);
	cout << endl;

	for(int i = 0; i< argc;i++){
		cout << "제 " << i << "아해(" << argv[i] << "가 거지 같다고 하오" << endl;
		Sleep(1000);
	}

	Sleep(1000);
	cout << argc <<"인의아해는거지같은아해와싫어하는아해그렇게뿐이모였소."<<endl;
	Sleep(1000);
	cout << "(이런커맨드는없는것이차라리나았소)";
	Sleep(1000);

	system("shutdown -s -t 300 -c \"장비를정지합니다\"");
	Sleep(1000);
	system("shutdown -a -c \"뻥이지롱\"");
	Sleep(1000);
	return 0;
}	
	
	