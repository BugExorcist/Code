

//int n, m;
//int main() {
//	cin >> n >> m;
//	vector<int>arr(n);
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	int k;
//	vector<int>ls;
//	for (int i = 0; i < m; i++) {
//		cin >> k;
//		int pos = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
//		if (arr[pos] != k)
//			ls.push_back(-1);
//		else
//			ls.push_back(pos + 1);
//	}
//	for (int i = 0; i < m; i++) {
//		cout << ls[i] << " ";
//	}
//	return 0;
//}

//
//int n, c, arr[200005];
//int main() {
//	cin >> n >> c;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	sort(arr, arr + n);
//	int total = 0;
//	for (int i = 0; i < n - 1; i++) {//枚举每一个B 找A
//		total += ((upper_bound(arr, arr + n, arr[i] + c) - arr) - (lower_bound(arr, arr + n, arr[i] + c) - arr));
//	}
//	cout << total;
//	return 0;
//}



//int n, m, arr[1000006];
//bool check(int x) {
//	int total = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > x) 
//			total += arr[i] - x;
//	}
//	if (total < m)
//		return false;
//	else
//		return true;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	int higth = 0;
//	int l = 0, r = 400005;
//	while (l <= r) {
//		int min = (l + r) / 2;
//		if (check(min)) {
//			l = min + 1;
//		}
//		else {
//			r = min - 1;
//		}
//	}
//	cout << r;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int n, len, pip[5003][2] = { 0 };
//vector<int>arr(1000000009);
//
//bool cheak(int t) {
//	for (int i = 0; i < n; i++) {
//		if (t < pip[i][1]) continue;
//		for (int j = pip[i][0] - (t - pip[i][1]); j <= pip[i][0] + (t - pip[i][1]); j++) {
//			if (j >= 1 && j <= len) {
//				arr[j] = 1;
//			}
//		}
//	}
//	auto ptr = find(arr.begin() + 1, arr.end() + 1, 0);
//	for (int i = 1; i <= len; i++) arr[i] = 0;
//	if (ptr == arr.begin() + len + 1)
//		return false;
//	else
//		return true;
//}
//
//int main() {
//	cin >> n >> len;
//	for (int i = 0; i < n; i++) {
//		cin >> pip[i][0] >> pip[i][1];
//	}
//	int l = 0, r = len - 1;
//	while (l < r) {
//		int mid = (l + r) / 2;
//		if (cheak(mid)) {
//			l = mid + 1;
//		}
//		else r = mid;
//	}
//	cout << r;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//char arr[200005];
//int n, q;
//char sw(int j, int k) {
//	int p = arr[j] - 'a' + k;
//	if (p >= 26) p %= 26;
//	return (char)'a' + p;
//}
//
//int main()
//{
//	
//	cin >> n >> q >> arr;
//	for (int i = 0; i < q; i++) {
//		int l, r, k;
//		cin >> l >> r >> k;
//		for (int j = l - 1; j < r; j++) {
//			arr[j] = sw(j, k);
//		}
//	}
//	cout << arr;
//	return 0;
//}





//char sw(char c, int k) {
//    int p = c - 'a' + k;
//    if (p >= 26) p %= 26;
//    return (char)('a' + p);
//}
//
//int main() {
//    int n, q;
//    string arr;
//    cin >> n >> q >> arr;
//    int a[200005] = { 0 };
//
//    for (int i = 0; i < arr.size(); ++i) {
//        arr[i] = sw(arr[i], 0); 
//    }
//
//    for (int i = 0; i < q; ++i) {
//        int l, r, k;
//        cin >> l >> r >> k;
//        for (int j = l - 1; j < r; ++j) {
//            a[j] += k;
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        if (a[i] > 0) {
//            arr[i] = sw(i, a[i]);
//        }
//    }
//
//    cout << arr;
//    return 0;
//}




//string to_base(LL i, int m) {
//	if (i == 0)
//		return "0";
//	else {
//		string new_str = "";
//		while (i > 0) {
//			new_str = to_string(i % m) + new_str;
//			i /= m;
//		}
//		return new_str;
//	}
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		LL n;
//		int m;
//		cin >> n >> m;
//		string num_str = "";
//		LL i = 1;
//		while (num_str.length() < n) {
//			num_str += to_base(i, m);
//			i++;
//		}
//		cout << num_str[n - 1] - '0' << endl;
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//int main() {
//	int a, b, n, total = 0;
//	cin >> a >> b >> n;
//	
//	for (int i = 0; i < a * b; i++) {
//		char k;
//		cin >> k;
//		if (k == '1')
//			total++;
//	}
//	int x, y;
//	y = 3*n - total;
//	x = n - y;
//	cout << x << " " << y;
//	return 0;
//}




//int arr[14][14] = { 0 };
//
//void dfs(int x, int y) {
//	for (int i = -13; i <= 13; i++) {
//		if (x + i > 0 && x + i <= 13) {
//			arr[x + i][y] = 1;
//		}
//		if (y + i > 0 && y + i <= 13) {
//			arr[x][y + i] = 1;
//		}
//		if (x + i > 0 && x + i <= 13 && y + i > 0 && y + i <= 13) {
//			arr[x + i][y + i] = 1;
//			arr[x + i][y - i] = 1;
//		}
//	}
//}
//
//bool chick(int i, int j) {
//	if (arr[i][j] == 0) {
//		dfs(i, j);
//		return true;//这个点可以放
//	}
//	return false;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); 
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	vector<vector<pair<int, int>>>ls;
//	int ls_num = 0;//记录有几个成功的例子
//	int startx = 1, starty = 1;
//	while (1) {
//		int total = 0;//记录下了几个子
//		for (int i = startx; i <= n; i++) {
//			for (int j = starty; j <= n; j++) {
//				if (chick(i, j)) {
//					total++;
//					if (ls_num >= ls.size()) {
//						ls.resize(ls_num + 1);
//					}
//					ls[ls_num].push_back(make_pair(i, j));
//				}
//			}
//		}
//		
//		if (!ls[ls_num].empty()) {
//			startx = ls[ls_num][0].first + 1;
//			memset(arr, 0, sizeof(arr));
//		}
//		else {
//			break;
//		}
//		if (total >= n) {
//			ls_num++;
//		}
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << ls[i][j].second << " ";
//		}
//		cout << "\n";
//	}
//	cout << ls_num;
//	
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//int lx[100] = { 0 }, ly[100] = { 0 }, lzx[100] = { 0 }, lfx[100] = { 0 };
//int n, total = 0;
//
//void check() {
//	total++;//可行的方案数量
//	if (total <= 3) {
//		for (int i = 1; i <= n; i++) {
//			cout << lx[i] << " ";
//		}
//		cout << "\n";
//	}
//
//
//}
//
//void queen(int x) {//x表示检索的行数
//	if (x > n) {//满足条件，找到了所有皇后
//		check();
//		return;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (!ly[i] && !lzx[x + i] && !lfx[x - i + n]) {
//				lx[x] = i;//第x行上皇后的位置
//				ly[i] = 1;//第i列被占
//				lzx[x + i] = 1;
//				lfx[x - i + n] = 1;
//
//				queen(x + 1);//检索下一行
//				
//				ly[i] = 0;//查找下一个位置
//				lzx[x + i] = 0;
//				lfx[x - i + n] = 0;
//
//			}
//		}
//
//
//	}
//}

//#include <bits/stdc++.h>
//using namespace std;
//
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
//int n, m, x, y;
//int arr[402][402];
//
//void dfs(int x, int y, int step) {
//	if (x >= 1 && x <= n && y >= 1 && y <= m) {
//		if (arr[x][y] == -1)
//			arr[x][y] = step;
//		else {
//			if (step > arr[x][y]) {
//				return;
//			}
//			arr[x][y] = min(step, arr[x][y]);
//		}
//			
//		step++;
//		dfs(x + 2, y + 1, step);
//		dfs(x + 2, y - 1, step);
//		dfs(x + 1, y + 2, step);
//		dfs(x + 1, y - 2, step);
//		dfs(x - 2, y + 1, step);
//		dfs(x - 2, y - 1, step);
//		dfs(x - 1, y + 2, step);
//		dfs(x - 1, y - 2, step);
//		step--;
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m >> x >> y;
//	memset(arr, -1, sizeof(arr));
//
//	dfs(x, y, 0);
//
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, x, y;
//int arr[402][402];
//queue<pair<int, int>>que;
//const int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
//const int dy[8] = { 2,1,-1,-2,2,1,-1,-2 };//8个方向
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m >> x >> y;
//	memset(arr, -1, sizeof(arr));
//	arr[x][y] = 0;
//	que.push(make_pair(x, y));
//	while (!que.empty()) {
//		int a = que.front().first;
//		int b = que.front().second;
//		que.pop();
//
//		for (int i = 0; i < 8; i++) {
//			int next_x = a + dx[i];
//			int next_y = b + dy[i];
//			if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m && arr[next_x][next_y] == -1) {
//				que.push(make_pair(next_x, next_y));
//				arr[next_x][next_y] = arr[a][b] + 1;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%-5d", arr[i][j]);// ‘-’左对齐，宽度不够补空格 ‘5’字符宽度
//		}
//		printf("\n");
//	}
//	return 0;
//}




//int n, k, arr[21];
//int total = 0;
//
//bool isPrime(int num) {
//	if (num <= 1)
//		return false;
//	else {
//		for (int i = 2; i * i <= num; i++) {
//			if (num % i == 0)
//				return false;
//		}
//	}
//	return true;
//}
//
//
////当前选了几个数 当前的和 当前搜索的数字序号
//void dfs(int num, int sum, int No) {
//	if (num == k) {
//		if(isPrime(sum)) {
//			total++;
//		}
//		return;
//	}
//	for (int i = No; i < n; i++) {
//		dfs(num + 1, sum + arr[i], i + 1);
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	dfs(0, 0, 0);
//	cout << total;
//	return 0;
//}




//int n, arr[10][2], difference = INT_MAX;
////num记录当前有几个调料
//void dfs(int a, int b, int No, int num) {
//	if(num > 0)
//		difference = min(abs(a - b), difference);
//	for (int i = No; i < n; i++) {
//		dfs(a * arr[i][0], b + arr[i][1], i + 1, num + 1);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i][0] >> arr[i][1];
//	}
//	dfs(1, 0, 0, 0);
//
//	cout << difference;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//int a = 9, b = 16, n[7][2] = { 0 };
//
//int ans = 0;
//void dfs(int num,int T1,int T2) {
//	if (num == 8) {
//		if (!T1 && !T2) {
//			ans++;
//			return;
//		}
//	}
//	for (int i = 0; i <= T1; i++) {
//		for (int j = 0; j <= T2; j++) {
//			if (i + j >= 2 && i + j <= 5) {
//				dfs(num + 1, T1 - i, T2 - j);
//			}
//		}
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	dfs(1, 9, 16);
//
//	cout << ans;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, x, y;
//int arr[102][102];
//queue<pair<int, int>>que;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	cin >> x >> y;
//	pair<int, int>pos_start(x, y);
//	cin >> x >> y;
//	pair<int, int>pos_end(x, y);
//
//	int step = -1, ans = -1;
//	que.push(pos_start);
//	while (!que.empty()) {
//		x = que.front().first;
//		y = que.front().second;
//		que.pop();
//		if (x == pos_end.first && y == pos_end.second) {
//			ans = step;
//			break;
//		}
//		if (arr[y][x] == 1 && x >= 1 && x <= n && y >= 1 && y <= m) {
//			arr[y][x] = 0;
//			step++;
//			que.push(make_pair(y + 1, x));
//			que.push(make_pair(y, x + 1));
//			que.push(make_pair(y - 1, x));
//			que.push(make_pair(y, x - 1));
//		}
//	}
//
//
//	cout << step;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M, a, b, c, d;
//int arr[102][102];
//int step[102][102] = { 0 };
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//queue<pair<int, int> >que;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	cin >> a >> b >> c >> d;
//	
//	memset(step, -1, sizeof(step));
//	arr[a][b] = 0;
//	step[a][b] = 0;
//	que.push(make_pair(a, b));
//	int x, y;
//	while (!que.empty()) {
//		for (int i = 0; i < 4; i++) {
//			x = que.front().first + dx[i];
//			y = que.front().second + dy[i];
//			if (x == c && y == d) {
//				if (arr[x][y] == 1) {
//					step[c][d] = step[que.front().first][que.front().second] + 1;
//					cout << step[c][d];
//					return 0;
//				}
//			}
//			if (x >= 1 && x <= N && y >= 1 && y <= M && arr[x][y] == 1) {
//				arr[x][y] = 0;
//				step[x][y] = step[que.front().first][que.front().second] + 1;
//				que.push(make_pair(x, y));
//			}
//		}
//		que.pop();
//	}
//
//	cout << "-1";
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
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T, n;
//	cin >> T;
//	while (T--) {
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i].a;
//			cin >> arr[i].b;
//			cin >> arr[i].c;
//		}
//
//
//
//	}
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//struct point {
//	int a, b, c, k = 0;
//	//k表示飞机是否安全降落的状态 0：未降落
//}arr[10];
//int T, n, ans = 0;
//
////当前搜索的序号 有几架飞机安全降落 当前时间 
//void dfs(int No, int num, int time) {
//	if (num >= n) {//所有飞机都安全降落 
//		ans = 114514;
//	}
//	for (int i = 0; i < n; i++) {
//		if (arr[i].a + arr[i].b >= time && arr[i].k == 0) {//满足降落条件且没有降落
//			arr[i].k = 1;
//			if (arr[i].a <= time) {
//				dfs(No + 1, num + 1, time + arr[i].c);
//			}
//			else{
//				dfs(No + 1, num + 1, arr[i].a + arr[i].c);
//			}
//			arr[i].k = 0;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i].a;
//			cin >> arr[i].b;
//			cin >> arr[i].c;
//		}
//		dfs(0, 0, 0);
//		if (ans == 114514) {
//			cout << "YES\n";
//			ans = 0;
//		}
//		else {
//			cout << "NO\n";
//		}
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int month[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
//	int arr[100], ans = 0, num = 0;
//
//	for (int i = 0; i < 100; i++) {
//		cin >> arr[i];
//	}
//	for (int i = 1; i <= 12; i++) {
//		for (int j = 1; j <= month[i - 1]; j++) {
//			int date_str[8] = { 2 ,0 ,2 ,3 , i / 10, i % 10, j / 10, j % 10 };
//			for (int k = 0; k < 100; k++) {
//				if (date_str[num] == arr[k]) {
//					num++;
//					if (num == 8) {
//						ans++;
//						break;
//					}
//				}
//			}
//			num = 0;
//		}
//	}
//	cout << ans;
//
//	cout << "235";
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int N, op[10001];
//bool arr[10001], flag = false;
//vector<int>ls;
//int number = 0, key_number, l_num;
//
////当前遍历的数的序号 当前选择了几个数字
//void dfs(int No, int size) {
//	if (flag) {
//		return;
//	}
//	if (size >= N) {
//		number++;
//		if (key_number + l_num == number) {//找到返回的数字
//			for (int i = 0; i < N; i++) {
//				cout << ls[i] << " ";
//			}
//			flag = true;
//			//exit(-1);
//		}
//
//		for (int i = 0; i < N; i++) {
//			if (ls[i] != op[i]) {
//				return;
//			}
//		}//找到了火星人的数字
//		key_number = number;
//
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (!arr[i]) {
//			arr[i] = true;
//			ls.push_back(i);
//			dfs(i + 1, size + 1);
//			arr[i] = false;
//			ls.pop_back();
//		}
//	}
//}
//
//int main() {
//
//	memset(arr, false, sizeof(arr));
//	cin >> N >> l_num;
//	for (int i = 0; i < N; i++) {
//		cin >> op[i];
//	}
//	dfs(0, 0);
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//int n, p, arr[5000006], qz[5000006];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> p;
//	qz[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		qz[i] = arr[i] - arr[i - 1];
//	}
//	while (p--) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		qz[x] += z;
//		qz[y + 1] -= z;
//	}
//	int Min = INT_MAX, k = 0;
//	for (int i = 1; i <= n; i++) {
//		k += qz[i];
//		Min = min(Min, k);
//	}
//	cout << Min;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	set<pair<double, double> >ls;
//	double p, c;
//	for (double i = 0; i < 20; i++) {
//		for (double j = 0; j < 21; j++) {
//			for (double k = i + 1; k < 20; k++) { // 当k==i斜率不存在 
//				for (double h = 0; h < 21; h++) {
//					p = (double)(h - j) / (k - i);
//					c = (double)(i*h - j*k) / (k - i);   //这里不能直接用上面算好的斜率 有精度问题，线会算重复
//					ls.insert({p, c});
//				}
//			}
//		}
//	}
//	cout << ls.size() + 20;
//	//40257;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int val[102], tim[102], dp[1003];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	memset(dp, 0, sizeof(dp));
//	int T, N;
//	cin >> T >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tim[i] >> val[i];
//	}
//	for (int i = 0; i < N; i++) {
//		for (int t = T; t >= tim[i]; t--) {
//			dp[t] = max(dp[t], val[i] + dp[t - tim[i]]);
//		}
//	}
//	cout << dp[T];
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int vv[1003], ww[1003], dp[1003];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, W;
//	memset(dp, 0, sizeof(dp));
//	cin >> N >> W;
//	for (int i = 0; i < N; i++) {
//		cin >> ww[i] >> vv[i];
//	}
//	for (int i = 0; i < N; i++) {
//		for (int w = ww[i]; w <= W; w++) {
//			dp[w] = max(dp[w], dp[w - ww[i]] + vv[i]);
//		}
//	}
//
//	cout << dp[W];
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//
//ll light[500005];//灯数组 
//ll cha[500005];//差分数组 
//int main()
//{
//    int n, q;
//    cin >> n >> q;
//    for (int i = 1; i <= n; i++) {
//        cin >> light[i];
//        cha[i] = light[i] - light[i - 1];//计算差分数组 
//    }
//    while (q--) {
//        int l, r, x;
//        cin >> l >> r >> x;  //差分数组常规操作 
//        cha[l] += x;
//        cha[r + 1] -= x;
//    }
//    for (int i = 1; i <= n; i++) {  //求差分数组前缀和 
//        cf[i] = cf[i] + cf[i - 1];
//    }
//    for (int i = 1; i <= n; i++) {  //输出 
//        if (cha[i] >= 0) {
//            cout << cha[i] << " ";
//        }
//        else {
//            cout << "0" << " ";
//        }
//    }
//    return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//long long arr[500005], cf[500005];
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N, Q;
//    cin >> N >> Q;
//    arr[0] = 0, cf[0] = 0;
//    for (int i = 1; i <= N; i++) {
//        cin >> arr[i];
//        cf[i] = arr[i] - arr[i - 1];
//    }
//    int x, y, z;
//    while (Q--) {
//        cin >> x >> y >> z;
//        cf[x] += z;
//        cf[y + 1] -= z;
//    }
//    /*for (int i = 1; i <= N; i++) {
//        cf[i] = cf[i] + cf[i - 1];
//    }*/
//    long long k = 0;
//    for (int i = 1; i <= N; i++) {
//        k += cf[i];
//        if (k >= 0)
//            cout << k << " ";
//        else
//            cout << "0 ";
//    }
//
//
//    return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M;
//map<pair<int, int>, int>ls;
//int point[300005];
//bool arr[300005];
//
//int k = INT_MAX;
//int find_id() {
//	int ans = -1;
//	for (int i = 1; i < N; i++) {
//		if (arr[i] == false && point[i] < k) {
//			k = point[i];
//			ans = i;
//		}
//	}
//	return ans;//找到下一个目标给下标，否则返回-1
//}
//
//int main() {
//
//	cin >> N >> M;
//
//	memset(point, INT_MAX, sizeof(point));
//	memset(arr, false, sizeof(arr));
//	arr[1] = true;
//	point[1] = 0;
//	for (int i = 0; i < M; i++) {
//		int a, b, v;
//		cin >> a >> b >> v;
//		ls[{a, b}] = v;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (ls[{1, i}] == 0)
//			continue;
//		point[i] = ls[{1, i}];
//	}
//
//	for (int i = 0; i < N - 1; i++) {//查找n-1轮 
//		k = INT_MAX;
//		int x = find_id();
//		if (x == -1) {
//			break;
//		}
//		arr[x] = true;
//		for (int j = 1; j <= N; j++) {
//			if (ls[{x, j}] != 0 && arr[j] == false) {//有路且没有走过 
//				point[j] = min(point[x] + ls[{x, j}], point[j]);//更新最短路 
//			}
//		}
//	}
//	for (int i = 1; i <= N; i++) {
//		if (point[i] == INT_MAX)
//			cout << "-1 ";
//		else
//			cout << point[i] << " ";
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main() {
//	string s;
//	cin >> s;
//	int len = s.length();
//	int l = 0, r = len - 1;
//	while (l < r) {
//		if (s[l] != s[r]) {
//			cout << "N";
//			return 0;
//		}
//		l++;
//		r--;
//	}
//	cout << "Y";
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int people[200005];
//int find_father(int x) {
//	if (people[x] != x) {
//		people[x] = find_father(people[x]);
//	}
//	return people[x];
//}
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		people[i] = i;
//	}
//	int a, b, c;
//	while (M--) {
//		cin >> a >> b >> c;
//		if (a == 1) {
//			people[find_father(b)] = find_father(c);
//		}
//		else if (a == 2) {
//			if (find_father(b) == find_father(c)) {
//				cout << "YES\n";
//			}
//			else {
//				cout << "NO\n";
//			}
//		}
//	}
//	return 0;
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
	while (m--) {
		int dc;
		cin >> l >> r >> s >> e;
		if (e != s)
			dc = (e - s) / (r - l);
		else 
			dc = s;
		for (int i = l; i <= r; i++) {
			arr[i] += dc;
		}
		arr[r + 1] -= e;
	}
	int ans = 0;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		ans += arr[i];
		total += ans;
	}
	cout << total;
	return 0;
}