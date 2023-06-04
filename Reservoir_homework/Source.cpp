#include <iostream>
#include <windows.h>
#include <vector>
#include "Resevoir.h"


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	vector<Resevoir> res_arr(3);
	//SaveBin(res_arr, "C:\\TestFolder\\TESTBIN.txt");
	//Save(res_arr, "C:\\TestFolder\\TEST.txt");
	//Load(res_arr, "C:\\TestFolder\\TEST.txt");
	//LoadBin(res_arr, "C:\\TestFolder\\TESTBIN.txt");

	for (int i{}; i < res_arr.size(); ++i)
		cout << res_arr[i] << endl;

	


	return 0;
}