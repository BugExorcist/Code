#include <iostream>
#include <string>
using namespace std;

void Score(int score)
{
	int arr[5] = { 90,80,70,60 };
	string arr2[5] = { "����","����", "�е�", "����", "������" };
	int maxLavel = sizeof(arr2) / sizeof(arr[0]);
	string grand = "����";
	int level = 0;
	while (score < arr[level] && level < maxLavel)
	{
		level++;
	}
	grand = arr2[level];
	cout << (grand) << endl;
}


int main()
{
	Score(25);
	return 0;
}