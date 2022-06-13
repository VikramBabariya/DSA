// using recursion

int bs(int l, int r, int val, int arr[]) {
	if (l > r) return -1;

	int mid = (l + r) / 2;
	if (arr[mid] == val) return mid;
	if (arr[mid] > val) return bs(l, mid - 1, val, arr);
	if (arr[mid] < val) return bs(mid + 1, r, val, arr);
}

// using iteration
int bs(int l, int r, int val, vector<int> &arr){
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == val) return mid;
		if (arr[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	rteurn -1;
}
