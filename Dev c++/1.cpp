//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n = 50;
//	int total = 0;
//	for(int i = 1; i < 50; i++){
//		total += i;
//	}
//	for(int i = 1;i < 7; i++){
//		total -= i;
//	}
//	cout << total;
//	
//	return 0;
//} 

//小球反弹 
#include <bits/stdc++.h>
using namespace std;



int main(){
	int x = 0, y = 0;
	if()
	
	return 0;
} 

//好数 
//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int N, total;
//	cin >> N;
//	for(int i = 1; i <= N; i += 2){
//		int flag = 1;
//		int p = i;
//		int num = 1;//位数 
//		while(p){
//			int x = p % 10;
//			if(num % 2 == 1 && x % 2 == 1){
//				p = p/10;
//				num++;
//				continue;
//			}
//			if(num % 2 == 0 && x % 2 == 0){
//				p = p/10;
//				num++;
//				continue;
//			}
//			flag = 0;
//			break;
//		}
//		num = 1;
//		if(flag){
//			total++; 
//		}
//	}
//	cout << total;
//	return 0;
//} 

//R格式
//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	double x;
//	int n;
//	cin >> n >> x;
//	double num = x * pow(2, n);
//	int num2 = (int)(num*10.0);
//	int p =  num2 % 10;
//	
//	cout << (int)num + 1;
//	return 0;
//} 



//宝石组合
//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[100005];
//int n;
//
//vector<int>ls;
//int max_ls[3];
//int LCM(int a, int b, int c){
//	int x = max(a, max(b, c));
//	for(int i = 1; ; i++){
//		if(i * x % a == 0 && i * x % b == 0 && i * x % c == 0)
//		return i * x;
//	}
//}
//int LCM2(int a, int b){
//	int x = max(a, b);
//	for(int i = 1; ; i++){
//		if(i * x % a == 0 && i * x % b == 0)
//		return i * x;
//	}
//}
//
//int max_S = 0;
//void dfs(int No, int num){//当前检索的序号 当前的宝石数量 
//	if(num == 3){
//		int S = ls[0]*ls[1]*ls[2]*(LCM(ls[0],ls[1],ls[2]))/(LCM2(ls[0],ls[1])*LCM2(ls[0],ls[2])*LCM2(ls[1],ls[2]));
//		if(S > max_S){
//			max_S = S;
//			for(int i = 0; i < 3; i++){
//				max_ls[i] = ls[i];
//			}
//		}
//		return;
//	}
//	for(int i = No; i <= n; i++){
//		ls.push_back(arr[i]);
//		dfs(i + 1, num + 1);
//		ls.pop_back();
//	}
//}
//
//int main(){
//	cin >> n;
//	for(int i = 1; i <= n; i++){
//		cin >> arr[i];
//	}
//	dfs(1 , 0);
//	
//	for(int i = 0; i < 3; i++){
//		cout << max_ls[i] << " ";
//	}
//	return 0;
//}


//数字接龙 
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, k, xx, yy, total = 0;
//int arr[11][11];
//bool op[11][11];
//int dx[8] = {-1,-1,0,1,1,1,0,-1};
//int dy[8] = {0,1,1,1,0,-1,-1,-1};
//vector<int>num_ls;
//
//int next_num(int num){
//	if(num == k - 1)
//		num = 0;
//	else
//		num++;
//	return num;
//}
//
//void dfs(int x, int y, int step){
//	if(x == n - 1 && y == n - 1){
//		
//		for(int i = 0; i < n * n - 1; i++){
//			cout << num_ls[i];
//		}
//		
//		if(total == n*n){
//			cout << "get" << endl;
//			for(int i = 0; i < n * n - 1; i++){
//			cout << num_ls[i];
//			}
//		}
//		return;
//	}
//	for(int i = 0; i < 8; i++){
//		xx = x + dx[i];
//		yy = y + dy[i];
//		if(xx >= 0 && xx < n && yy >= 0 && yy < n){
//			if(arr[xx][yy] == next_num(step) && op[xx][yy] == false){
//				op[xx][yy] = true;
//				cout<< x << " " << y << "→" << xx << " " << yy << endl;
//				
//				num_ls.push_back(i);
//				total++;
//				dfs(xx, yy, next_num(step));
//				num_ls.pop_back();
//				total--;
//				op[xx][yy] = false;
//			}
//		}
//	}
//}
//
//int main(){
//	memset(op, false, sizeof(op));
//	cin >> n >> k;
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			cin >> arr[i][j];
//		}
//	}
//	op[0][0] = true;
//	total++;
//	dfs(0, 0, 0);
//	
//	return 0;
//}

////爬山 
//#include <bits/stdc++.h>
//using namespace std;
//int arr[100005];
//
//int main(){
//	int n, p ,q;
//	cin >> n >> p >> q;
//	for(int i = 0; i < n; i++){
//		cin >> arr[i];
//	}
//	int flag = n - 1;
//	while(p + q){
//		sort(arr, arr + n);
//		int x = arr[flag];
//		if(x / 2 < pow(x, 0.5)){
//			if(q > 0){
//				q--;
//				arr[flag] = x/2;
//			}
//			else{
//				p--;
//				arr[flag] = pow(x, 0.5);
//			}
//		}
//		else{
//			if(p > 0){
//				p--;
//				arr[flag] = pow(x, 0.5);
//			}
//			else{
//				q--;
//				arr[flag] = x/2;
//			}
//		}
//	}
//	double total = 0;
//	for(int i = 0; i < n; i++){
//		total += arr[i];
//	}
//	cout << (int)total;
//	return 0;
//}



//拔河 
//#include <bits/stdc++.h>
//using namespace std;
//
//int n = 0;
//long long min_num = INT_MAX;
//long long l1 = 0, l2 = 0;
//long long arr[1003];
//
//void dfs(int No, int num){
//	if(num == n){
//		long long k = abs(l1 - l2);
//		min_num = min(min_num, k);
//	}
//	for(int i = No; i <= n; i++){
//		l1 += arr[i];
//		dfs(i + 1, num + 1);
//		l1 -= arr[i];
//		l2 += arr[i];
//		dfs(i + 1, num + 1);
//		l2 -= arr[i];
//	}
//}
//
//int main(){
//	cin >> n;
//	for(int i = 1; i <= n ;i ++){
//		cin >> arr[i];
//	}
//	
//	dfs(1, 0);
//	
//	cout << min_num;
//	return 0;
//}

