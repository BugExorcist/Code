#include <bits/stdc++.h>
using namespace std;

//struct Point {
//	double x;
//	double y;
//};
//
//double distance(Point p1, Point p2) {
//	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}
//
//double closestPair(vector<Point>& points) {
//	int n = points.size();
//	double minDistance = numeric_limits<double>::max(); // 初始化最小距离为无穷大
//	for (int i = 0; i < n; ++i) {
//		for (int j = i + 1; j < n; ++j) {
//			double dist = distance(points[i], points[j]);
//			if (dist < minDistance) {
//				minDistance = dist;
//			}
//		}
//	}
//	return minDistance;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int m;
//		cin >> m;
//		vector<Point>points(m);
//		for (int j = 0; j < m; j++)
//		{
//			cin >> points[j].x >> points[j].y;
//		}
//		double minDistance = closestPair(points);
//		cout << fixed << setprecision(4) << minDistance << endl;
//	}
//	return 0;
//}


void Merge(vector<int>& arr, int left,int mid, int right) {
	int l = left, m = mid + 1, r = right, k = 0;
	vector<int>temp(right - left + 1);
	while (l <= mid && m <= right)
	{
		if (arr[l] <= arr[m])
			temp[k++] = arr[l++];
		else temp[k++] = arr[m++];
	}
	while(l <= mid)
		temp[k++] = arr[l++];
	while (m <= mid)
		temp[k++] = arr[m++];
	for (int n = 0; n < k; n++)
	{
		arr[left + n] = temp[n];
	}
}

void mergeSort(vector<int>& arr, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}


int main()
{
	vector<int>arr;
	int n = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	mergeSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); i++) {
		if ((i + 1) % 10 == 0) {
			printf("%d\n", arr[i]);
		}
		else {
			if (i == arr.size() - 1) {
				printf("%d\n", arr[i]);
			}
			else {
				printf("%d  ", arr[i]);
			}
		}
	}
	return 0;
}


//void quickSort(vector<int>& nums, int left, int right) {
//    if (left >= right) return;
//    int i = left, j = right, pivot = nums[left];
//    while (i < j) {
//        while (i < j && nums[j] >= pivot) j--;
//        if (i < j) nums[i++] = nums[j];
//        while (i < j && nums[i] < pivot) i++;
//        if (i < j) nums[j--] = nums[i];
//    }
//    nums[i] = pivot;
//    quickSort(nums, left, i - 1);
//    quickSort(nums, i + 1, right);
//}
//
//int main() {
//    vector<int> nums;
//    int num = 0;
//    cin >> num;
//    while (num--) {
//        int x;
//        cin >> x;
//        nums.push_back(x);
//    }
//    quickSort(nums, 0, nums.size() - 1);
//    for (int num : nums) {
//        cout << num << " ";
//    }
//    cout << endl;
//    return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f','g','h','i','g','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z' };
//	int numa[26] = { 0 }, numb[26] = { 0 };
//	int x;
//	cin >> x;
//	for (int i = 0; i < x; i++)
//	{
//		char a[1000], b[1000];
//		cin >> a >> b;
//		int lena = strlen(a);
//		int lenb = strlen(b);
//		if (lena == lenb)
//		{
//			for (int y = 0; y < lena; y++)
//			{
//				for (int t = 0; t < 26; t++)
//				{
//					if (a[y] == arr[t])
//						numa[t]++;
//					if (b[y] == arr[t])
//						numb[t]++;
//				}
//			}
//			int p = 1;
//			for (int n = 0; n < 26; n++)
//				if (numa[n] != numb[n])
//				{
//					cout << "No" << endl;
//					p = 0;
//					break;
//				}
//			if (p)
//			{
//				cout << "Yes" << endl;
//			}
//		}
//		else
//			cout << "No" << endl;
//		for (int m = 0; m < 26; m++)
//		{
//			numa[m] = 0;
//			numb[m] = 0;
//		}
//	}
//	return 0;
//}