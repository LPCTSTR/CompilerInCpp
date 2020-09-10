#include "./REX_LPCT_/Header.h"

HANDLE g_hSemaphore = nullptr;

HANDLE get_g_hSemaphore() {
	return g_hSemaphore;
}

void P() {
	WaitForSingleObject(g_hSemaphore, INFINITE);
}

void V() {
	ReleaseSemaphore(g_hSemaphore, 1, NULL);
}

int main(int argc, char** argv) {
	static char str[40 * 40] =
		"include p\n"
		"x = 1\n"
		"p=x\n";
	LEXER << str;



	//g_hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
	//if (g_hSemaphore == nullptr)
	//	return 0;

	//new std::thread([argc, argv] {
	//	P();
	//	GUI_LOOP(argc, argv);
	//	V();
	//	});
	//while (1) {
	//	int x;
	//	std::cin >> x;
	//	std::cout << x << std::endl;
	//	if (x == 10) {
	//		std::cout << "GUI画面が閉じ次第、このアプリケーションを安全に閉じります" << std::endl;
	//		break;
	//	}
	//}

	//P();
}



void Content(){
	Kashiko::runCommand();
	
}


