#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>arr(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = (i - 1) * n + j;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, r, z, temp;
		cin >> x >> y >> r >> z;

		for (int t = 1; t <= r; t++)
		{
			for (int j = 0; j < 2 * t; j++)
			{
				if (z == 1)
				{
					temp = arr[x - t + j][y - t];
					arr[x - t + j][y - t] = arr[x - t][y + t - j];
					arr[x - t][y + t - j] = arr[x + t - j][y + t];
					arr[x + t - j][y + t] = arr[x + t][y - t + j];
					arr[x + t][y - t + j] = temp;
				}
				else if (z == 0)
				{
					temp = arr[x - t + j][y - t];
					arr[x - t + j][y - t] = arr[x + t][y - t + j];
					arr[x + t][y - t + j] = arr[x + t - j][y + t];
					arr[x + t - j][y + t] = arr[x - t][y + t - j];
					arr[x - t][y + t - j] = temp;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}





//string bigAdd(string s1, string s2)
//{
//	int l1 = s1.length();  123  741 369
//	int l2 = s2.length();  456  852 258
//	if (l1 > l2)           789  963 147
//	{
//		for (int i = l1 - l2; i > 0; i--)
//		{
//			s2 = "0" + s2;
//		}
//	}
//	else
//	{
//		for (int i = l2 - l1; i > 0; i--)
//		{
//			s1 = "0" + s1;
//		}
//	}
//	int temp = 0;
//	int num = 0;
//	string str;
//	for (int i = max(s1.length(), s2.length()) - 1; i >= 0; i--)
//	{
//		temp = s1[i] - '0' + s2[i] - '0' + num;
//		num = temp / 10;
//		temp %= 10;
//		str = char(temp + '0') + str;
//	}
//	if (num != 0)
//	{
//		str = char(num + '0') + str;
//	}
//	return str;
//}
//
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	cout << bigAdd(s1, s2);
//
//	return 0;
//}

//int n, m;
//int arr[100005] = { 0 };
//string name[100005];
//int instructions[100005][2];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i] >> name[i];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cin >> instructions[i][0] >> instructions[i][1];
//	}
//	int flag = 0;
//	for (int i = 0; i < m; i++)
//	{
//		if (instructions[i][0] == 0)
//		{
//			if (arr[flag] == 1)
//			{
//				flag += instructions[i][1];
//				flag %= n;
//			}
//			else if (arr[flag] == 0)
//			{
//				flag -= instructions[i][1];
//				if (flag < 0)
//				{
//					flag += n;
//				}
//			}
//		}
//		else if (instructions[i][0] == 1)
//		{
//			if (arr[flag] == 1)
//			{
//				flag -= instructions[i][1];
//				if (flag < 0)
//				{
//					flag += n;
//				}
//			}
//			else if (arr[flag] == 0)
//			{
//				flag += instructions[i][1];
//				flag %= n;
//			}
//		}
//	 }
//
//	cout << name[flag];
//	return 0;
//}


//
//int number = 0;
//int f11 = 0, f21 = 0;
//vector<int>score11;
//vector<int>score21;
//string str;
//
//bool ReadLine(string str) {
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == 'E')
//		{
//			if (number % 11 != 0 || number == 0)
//				score11.push_back(f11);
//			if (number % 21 != 0 || number == 0)
//				score21.push_back(f21);
//			return true;
//		}
//		if (str[i] == 'W')
//		{
//			f11++;
//			f21++;
//		}
//		number++;
//		if (number % 11 == 0)
//		{
//			score11.push_back(f11);
//			f11 = 0;
//		}
//		if (number % 21 == 0)
//		{
//			score21.push_back(f21);
//			f21 = 0;
//		}
//	}
//	return false;
//}
//
//void ScorePrint()
//{
//	for (int i = 0; i < score11.size() - 1; i++) {
//		cout << score11[i] << ":" << 11 - score11[i] << endl;
//	}
//	cout << score11[score11.size() - 1] << ":" << ((number % 11) == 0 ? 0 : (number % 11 - score11[score11.size() - 1])) << endl;
//	cout << endl;
//	for (int i = 0; i < score21.size() - 1; i++) {
//		cout << score21[i] << ":" << 21 - score21[i] << endl;
//	}
//	cout << score21[score21.size() - 1] << ":" << ((number % 21) == 0 ? 0 : (number % 21 - score21[score21.size() - 1])) << endl;
//}
//
//int main()
//{
//	while (1)
//	{
//		cin >> str;
//		if (ReadLine(str))
//		{
//			break;
//		}
//	}
//	ScorePrint();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int f1[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//int f2[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
//
//int main()
//{
//	int n, m;
//	char arr[102][102];
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (arr[i][j] == '*')
//			{
//				for(int k = 0; k < 8; k++)
//				{
//					if (arr[i + f1[k]][j + f2[k]] == '*')
//						continue;
//					else if (arr[i + f1[k]][j + f2[k]] == '?')
//						arr[i + f1[k]][j + f2[k]] = '1';
//					else
//						arr[i + f1[k]][j + f2[k]] = char(int(arr[i + f1[k]][j + f2[k]]) + 1);
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (arr[i][j] == '?')
//			{
//				cout << "0";
//				continue;
//			}
//			cout << arr[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}


 