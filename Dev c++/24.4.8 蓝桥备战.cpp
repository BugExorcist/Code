//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, x, y;
//int arr[402][402];
//int step = 0;
//
//void dfs(int x, int y){
//	if(x >= 1 && x <= n && y >= 1 && y <= m){
//		arr[x][y] = min(step, arr[x][y]);
//		step++;
//		dfs(x + 2, y + 1);
//		dfs(x + 2, y - 1);
//		dfs(x + 1, y + 2);
//		dfs(x + 1, y - 2);
//		dfs(x - 2, y + 1);
//		dfs(x - 2, y - 1);
//		dfs(x - 1, y + 2);
//		dfs(x - 1, y - 2);
//		step--;
//	}
//}
//
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> n >> m >> x >> y;
//	memset(arr, -1, sizeof(arr));
//
//	dfs(x, y);
//	
//	for(int i = 1; i <= m; i++){
//		for(int j = 1; j <= n; j++){
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}




//int Left, Right, total, ans;
//int s[5];
//int a[21][5];
//
//void search(int level, int ls_num) {
//	if (level > s[ls_num]) {
//		ans = min(ans, max(Left, Right));
//			return;
//	}
//	Left += a[level][ls_num];
//	search(level + 1, ls_num);
//	Left -= a[level][ls_num];
//
//	Right += a[level][ls_num];
//	search(level + 1, ls_num);
//	Right -= a[level][ls_num];
//
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> s[1] >> s[2] >> s[3] >> s[4];
//	for (int i = 1; i <= 4; i++) {
//		Left = Right = 0;
//		ans = INT_MAX;
//		for (int j = 1; j <= s[i]; j++)
//			cin >> a[j][i];
//		search(1, i);
//		total += ans;
//	}
//	cout << total;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M, x1, x2, y, y2;
//int arr[102][102];
//int step[102][102] = { 0 };
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//queue<pair<int, int> >que;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> N >> M;
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//			cin >> arr[i][j];
//		}
//	}
//	cin >> x1 >> y >> x2 >> y2;
//	
//	que.push(make_pair(x1, y));
//	step[x1][y] = 0;
//	int x, y;
//	while(!que.empty()){
//		for(int i = 0; i < 4; i++){
//			x = que.front().first + dx[i];
//			y = que.front().second + dy[i];
//			if(x == x2 && y == y2){
//				step[x2][y2] = step[que.front().first][que.front().second] + 1;
//				break;
//			}
//			if (x >= 1 && x <= N && y >= 1 && y <= M && arr[x][y] == 1){
//				arr[x][y] = 0;
//				step[x][y] = step[que.front().first][que.front().second] + 1;
//				que.push(make_pair(x, y));
//			}
//			que.pop();
//		}
//	}
//	
//	cout << step[x2][y2];
//	
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//struct point{
//	int a, b, c;
//
//}arr[10];
//int T, n;
//
////当前搜索的序号 有几架飞机安全降落 当前时间 
//bool dfs(int No, int num, int time){
//	if (num > n){//所有飞机都安全降落 
//		return true;
//	}
//	for(int i = No; i < n; i++){
//		if(arr[i].a <= time && arr[i].a + arr[i].b >= time){
//			dfs(No + 1, num + 1, time + arr[i].c);
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i].a;
//			cin >> arr[i].b;
//			cin >> arr[i].c;
//		}
//		
//		if(dfs(0, 0, 0)){
//			cout << "YES\n";
//		}
//		else{
//			cout << "NO\n";
//		}
//	}
//	
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int month[12] = {31,28,31,30,31,30,31,30,31,30,31,30};
//	int arr[100], ans = 0;
//	
//	for(int i = 0; i < 100; i++){
//		cin >> arr[i];
//	}
//	
//	for(int i = 0; i < 12; i++){
//		for(int j = 0; j < month[j]; j++){
//			int date_str[8] = {2 ,0 ,2 ,3 , i / 10, i % 10, j /10, j % 10};
//			int num = 0;
//			for(int k = 0; k < 92; k++){
//				if (date_str[num] == k){
//					num++;
//					if(num == 8){
//						ans++;
//						break;
//					}
//				}
//			}
//			num = 0;
//		}
//	}
//	
//	cout << ans;
//	
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int n, m, arr[100005], sum[100005];
//	cin >> n;
//	sum[0] = 0;
//	for (int i = 1; i <= n; i++){
//		cin >> arr[i];
//		sum[i] = sum[i - 1] + arr[i]; 
//	}
//	cin >> m;
//	int a , b;
//	while(m--){
//		cin >> a >> b;
//		cout << sum[b] - sum[a - 1] << "\n";
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int n, x, dp = -INT_MAX, Max = -INT_MAX;
//	cin >> n;
//	cin >> x;
//	dp = x;
//	for(int i = 0; i < n - 1; i++){
//		cin >> x;
//		dp = max(x, dp + x);
//		Max = max(Max, dp);
//	}
//	cout << Max;
//	
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//int sum[122][122];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	memset(sum, 0, sizeof(sum));
//	int n, x, Max = -INT_MAX, num;
//	cin >> n;
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cin >> x;
//			sum[i][j] = x + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//		}
//	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			for(int k = 1; k <= n; k++){
//				for(int h = 1; h <= n; h++){
//					if(k < i || h < j){
//						continue;
//					}
//					num = sum[k][h] - sum[i - 1][h] - sum[k][j - 1] + sum[i -1][j - 1];
//					Max = max(Max, num);
//				}
//			}
//		}
//	}
//	cout << Max;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//int n, p, arr[5000006], qz[5000006];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> n >> p;
//	qz[0] = 0;
//	for(int i = 1; i <= n; i++){
//		cin >> arr[i];
//		qz[i] = arr[i] - arr[i - 1];
//	}
//	while(p--){
//		int x, y, z;
//		cin >> x >> y >> z;
//		qz[x] += z;
//		qz[y + 1] -= z;
//	}
//	int Min = INT_MAX, k = 0;
//	for(int i = 1; i <= n; i++){
//		k += qz[i];
//		Min = min(Min, k);
//	}
//	cout << Min;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int a = 20, b = 21;
//	set<pair<float, float> >ls;
//	float k, c;
//	for(int i = 1; i <= a; i++){
//		for(int j = 1; j <= b; j++){
//			for(int k = 1; k <= a; k++){
//				for(int h = 1; h <= b; h++){
//					if (k <= i || h <= j)
//						continue;
//					k = (h - j)/(k - i);
//					c = j - k * i;
//					ls.insert(make_pair(k, c));
//				}
//			}
//		}
//	}
//	
//	cout << ls.size();
//	return 0;
//} 


//#include <bits/stdc++.h>
//using namespace std;
//int arr[1003][1003];
//int ans[1003][1003];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int n;
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j <= i; j++){
//			cin >> arr[i][j];
//		}
//	}
//	for(int i = n - 1; i >= 0; i--){
//		for(int j = 0; j <= i; j++){
//			if(i == n - 1)
//				ans[i][j] = arr[i][j];
//			ans[i][j] = arr[i][j] + max(ans[i + 1][j], ans[i + 1][j + 1]);
//		}
//	}
//	
//	cout << ans[0][0];
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int val[102], tim[102], dp[1003];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	memset(dp, 0, sizeof(dp));
//	int T, N;
//	cin >> T >> N;
//	for(int i = 0; i < N; i++){
//		cin >> tim[i] >> val[i];
//	}
//	for(int i = 0; i < N; i++){
//		for(int t = T; t >= tim[i]; t--){
//			dp[t] = max(dp[t], val[i] + dp[t - tim[i]]); 
//		}
//	}
//	cout << dp[T];
//	return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//int vv[1003], ww[1003], dp[1003];
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int N, W;
//	memset(dp, 0, sizeof(dp));
//	cin >> N >> W;
//	for(int i = 0; i < N; i++){
//		cin >> ww[i] >> vv[i];
//	}
//	for(int i = 0; i < N; i++){
//		for(int w = ww[i]; w <= W; w++){
//			dp[w] = max(dp[w], dp[w - ww[i]] + vv[i]);
//		}
//	}
//	
//	cout << dp[W];
//	return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[500005], cf[50005];
//int vv[1003], ww[1003], dp[1003];
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int N, Q;
//	cin >> N >> Q;
//	arr[0] = 0;
//	for(int i = 1; i <= N; i++){
//		cin >> arr[i];
//		cf[i] = arr[i] - arr[i - 1];
//	}
//	int x, y, z;
//	while(Q--){
//		cin >> x >> y >> z;
//		cf[x] += z;
//		cf[y + 1] -= z;
//	}
//	int k = 0;
//	for(int i = 1; i <= N; i++){
//		k += cf[i];
//		if(k >= 0)
//			cout << k << " ";
//		else
//			cout << "0 ";
//	}
//	
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[500005];
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int n;
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		cin >> arr[i];
//	}
//	sort(arr, arr + n);
//	for(int i = 0; i < n; i++){
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
//	for(int i = n - 1; i >= 0; i--){
//		cout << arr[i] << " ";
//	}
//	
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//
//struct coin{
//	double m, v, p;
//}arr[102];
//
//bool cmp(coin a, coin b){
//	return a.p > b.p;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int N, T;
//	cin >> N >> T;
//	for(int i = 0; i < N; i++){
//		cin >> arr[i].m >> arr[i].v;
//		arr[i].p = arr[i].v/arr[i].m;
//	}
//	sort(arr, arr + N, cmp);
//	double total = 0;
//	for(int i = 0; i <= N;i++){
//		if(T >= arr[i].m){
//			total += arr[i].v;
//			T -= arr[i].m;
//		}
//		else{
//			total += arr[i].v / arr[i].m * T;
//			break;
//		}
//	}
//	
//	printf("%.2f", total);
//	
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//struct people{
//	int No, num;
//}arr[1003];
//
//bool cmp(people a, people b){
//	return a.num < b.num;
//}
//
//int main(){
//	int N;
//	cin >> N;
//	for(int i = 1; i <= N; i++){
//		cin >> arr[i].num;
//		arr[i].No = i;
//	}
//	sort(arr + 1, arr + N + 1, cmp);
//	double total = 0;
//	for(int i = 1; i < N;i++){
//		total += (N - i) * arr[i].num;
//	}
//	for(int i = 1; i <= N;i++){
//		cout << arr[i].No << " "; 
//	}
//	printf("\n%.2f", total / N);
//	
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M;
//int G[300005][300005];
//int point[300005];
//bool arr[300005];
//
//int k = INT_MAX;
//int find_id(){
//	int ans = -1;
//	for(int i = 0; i < N; i++){
//		if (arr[i] == false && point[i] < k){
//			k = point[i];
//			ans = i;
//		}
//	}
//	return ans;//找到下一个目标给下标，否则返回-1
//}
//
//int main(){
//	
//	cin >> N >> M;
//	memset(G, -1, sizeof(G));
//	memset(point, INT_MAX, sizeof(point));
//	memset(arr, false, sizeof(arr));
//	arr[1] = true;
//	point[1] = 0;
//	for(int i = 0; i <= M; i++){
//		int a, b, v;
//		cin >> a >> b >> v;
//		G[a][b] = v;
//	}
//	for(int i = 1; i <= N; i++){
//		if(G[1][i] != -1)
//		point[i] = G[1][i];
//	}
//	
//	for(int i = 0; i < N - 1; i++){//查找n-1轮 
//		k = INT_MAX;
//		int x = find_id();
//		if (x == -1){
//			break;
//		}
//		arr[x] = true;
//		for(int j = 1; j <= N; j++){
//			if(G[x][j] != -1 && arr[j] == false){//有路且没有走过 
//				point[j] = min(point[x] + G[x][j], point[j]);//更新最短路 
//			}
//		}
//	}
//	for(int i = 1; i <= N; i++){
//		if(point[i] == INT_MAX)
//			cout << "-1 ";
//		else
//			cout << point[i] << " ";
//	}
//	return 0;	
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int ww[102], vv[102], dp[1003];
//int main(){
//	memset(dp, 0, sizeof(dp));
//	int N, V;
//	cin >> N >> V;
//	for(int i = 1; i <= N; i++){
//		cin >> ww[i] >> vv[i];
//	}
//	for(int i = 1;i <= N; i++){
//		for(int w = V; w >= ww[i]; w--){
//			dp[w] = max(dp[w], vv[i] + dp[w - ww[i]]);
//		}
//	}
//	
//	cout << dp[V];
//	return 0;
//}
 
 
//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//	int t;
//	cin >> t;
//	double x;
//	while(t--){
//		cin >> x;
//		printf("%.3lf\n", cbrt(x));
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//	string s;
//	cin >> s;
//	int len = s.length();
//	int l = 0, r = len;
//	while(l < r){
//		if(s[l] != s[r]){
//			cout << "N";
//			return 0;
//		}
//	}
//	cout << "Y";
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int people[200005];
//int find_father(int x){
//	if (people[x] != x){
//		people[x] = find_father(people[x]);
//	}
//	return people[x];
//}
//
//int main(){
//	int N, M;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++){
//		people[i] = i;
//	} 
//	int a, b, c;
//	while(M--){
//		cin >> a >> b >> c;
//		if(a == 1){
//			people[find_father(b)] = find_father(c);
//		}
//		else if(a == 2){
//			if(find_father(b) == find_father(c)){
//				cout << "YES\n";
//			}
//			else{
//				cout << "NO\n";
//			}
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//long long fast_pow(long long base, long long pow_num, long long mod){
//	int ans = 1;
//	base %= mod;
//	while(pow_num > 0){
//		if(pow_num & 1){//pow_num是奇数
//			ans = (ans * base) % mod; 
//		}
//		base = (base * base) % mod;
//		pow_num >>= 1;
//	}
//	return ans;
//}
//
//int main(){
//	long long T;
//	cin >> T;
//	while(T--){
//		long long a, b, c;
//		cin >> a >> b >> c;
//		cout << fast_pow(a, b, c) << endl;
//	}
//	
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		int n;
//		cin >> n;
//		int ans = 0;
//		for(int i = 0; i < n; i++){
//			int x;
//			cin >> x;
//			ans ^= x;
//		}
//		if(ans){
//			cout << "NO\n";
//		}
//		else
//			cout  << "YES\n";
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[500005];
//bool op[500005];
//int main(){
//	int n, m;
//	cin >> n >> m;
//	memset(arr, 1, sizeof(arr));
//	memset(op, false, sizeof(op));
//	int a , b;
//	cin >> a >> b;
//	arr[a] = 1;
//	arr[b] = 2;
//	op[a] = true;
//	op[b] = true;
//	for(int i = 0; i < m - 1; i++){
//		cin >> a >> b;
//		if(op[a] == false && op[b] == false){
//			arr[a] = 1;
//			arr[b] = 2;
//			op[a] = true;
//			op[b] = true;
//		}
//		else if(op[a] == true && op[b] == true){
//			if(arr[a] == arr[b]){
//				cout << a;
//				break;
//			}
//		}
//		else if(op[a] == true && op[b] == false){
//			op[b] = true;
//			if(arr[a] = 1)
//				arr[b] = 2;
//			else
//				arr[b] = 1;
//		}
//		else{
//			op[a] = true;
//			if(arr[b] = 1)
//				arr[a] = 2;
//			else
//				arr[a] = 1;
//		}
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const int N=5*1e6+10;
//int p[N];
//int n,m;
//int find(int x)
//{
//  if(p[x]!=x)  p[x]=find(p[x]);
//  return p[x];
//}
//int main()
//{
//  scanf("%d%d",&n,&m);
//  for(int i=1;i<=2*n;i++)  p[i]=i;
//  while(m--)
//  {
//    int x,y;
//    scanf("%d%d",&x,&y);
//    if(find(x)==find(y)&&find(x+n)==find(y+n)) 
//    {
//      cout<<x<<endl;
//      return 0;
//    }
//    p[find(x)]=find(y+n);
//    p[find(y)]=find(x+n);
//  }
//  return 0;
//}



#include<iostream>
using namespace std;

int arr[10000007];
int main()
{
  	int n, m;
 	 cin >> n >> m;
 	 arr[0] = 0;
  	int l, r, s, e;
  	while(m--){
  		cin >> l >> r >> s >> e;
  		int dc = (e - s) / (r - l);
  		for(int i = l; i <= r; i++){
  			arr[i] += dc;
		}
		arr[r + 1] -= e;
	}
	int ans = 0;
	int total = 0;
	for(int i = 1; i <= n; i++){
		ans += arr[i];
		total += ans;
	}
	cout << total;
	return 0;
}

