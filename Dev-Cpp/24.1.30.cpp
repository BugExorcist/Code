#include <bits/stdc++.h>
using namespace std;

int main()
{
  char arr[10004];
  cin >> arr;
  int num[10] = { 0 };
  int i = 0;
  while(arr[i] != '\0'){
    num[arr[i] - '0']++;
    i++;
  }
  for(int j = 0; j < 10; j++){
    cout << num[j] << " ";
  }
  return 0;
}
