//#include <bits/stdc++.h>
//using namespace std;
//void queickSort(vector<int>& nums, int begin, int end) {
//	if (begin >= end) return;
//	int p = nums[begin], l = begin, r = end;
//	while (l < r) {
//		while (l < r && nums[r] >= p) r--;
//		if (l < r) nums[l++] = nums[r];
//		while (l < r && nums[l] < p) l++;
//		if (l < r) nums[r--] = nums[l];
//	}
//	nums[l] = p;
//	queickSort(nums, begin, l - 1);
//	queickSort(nums, l + 1, end);
//}
//
//void merge(vector<int>& nums, int begin, int mid, int end) {
//	int l = begin,m = mid + 1, k = 0;
//	vector<int>temp(end - begin + 1);
//	while (l <= mid && m <= end) {
//		if (nums[l] < nums[m])
//			temp[k++] = nums[l++];
//		else temp[k++] = nums[m++];
//	}
//	while (l <= mid)
//		temp[k++] = nums[l++];
//	while (m <= end)
//		temp[k++] = nums[m++];
//	for (int i = 0; i < k; i++) {
//		nums[begin + i] = temp[i];
//	}
//}
//
//
//void mergeSort(vector<int>& nums, int begin, int end) {
//	if (begin >= end) return;
//	int mid = begin + (end - begin) / 2;
//	mergeSort(nums, begin, mid);
//	mergeSort(nums, mid + 1, end);
//	merge(nums, begin, mid, end);
//}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[16];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int b[16] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i])
				b[i]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int res = b[i];
		for (int j = 1; j < n - i; j++) {
			res *= j;
		}
		sum += res;
	}
	cout << sum << endl;
	int left = 0, right = n - 1;
	for (int i = n - 1; i > 0; i--) {
		if (arr[i - 1] < arr[i]) {
			left = i - 1;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[left] < arr[i]) {
			right = i;
			break;
		}
	}
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp; 
	sort(arr+ left + 1, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}