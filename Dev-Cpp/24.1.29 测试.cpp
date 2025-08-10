#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n ,m, t;
  cin >> n >> m >> t;
  vector<vector<int> >map(n,vector<int>(m, 0));
  int r1, c1, r2, c2;
  for(int i = 0; i < t; i++){
    cin >> r1 >> c1 >> r2 >> c2;
    for(int j = r1; j <= r2; j++){
      for(int k = c1; k <= c2; k++){
        map[j][k] = 1;
      }
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(map[i][j] == 0)
        cnt++;
    }
  }
  cout << cnt;
  return 0;
}
