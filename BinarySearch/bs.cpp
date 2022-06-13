// using recursion

int bs(int l, int r, int val, int arr[]) {
	if (l > r) return -1;

	int mid = (l + r) / 2;
	if (arr[mid] == val) return mid;
	if (arr[mid] > val) return bs(l, mid - 1, val, arr);
	if (arr[mid] < val) return bs(mid + 1, r, val, arr);
}

// using iteration

  int l = 0, r = 4, val = 8;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == val) {
			cout << mid;
			return;
		}
		if (arr[mid] > val) r = mid - 1;
		if (arr[mid] < val) l = mid + 1;
	}
	cout << -1;
