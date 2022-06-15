bool canPlace(int minDist, int cows, vector<int> &locs, int n) {
	int lastCow = locs[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (locs[i] - lastCow >= minDist) {
			cnt++;
			lastCow = locs[i];
		}
		if (cnt == cows) return true;
	}
	return false;
}


int bser(int cows, vector<int> &locs, int n) {
	int l = 1, h = locs[n - 1] - locs[0], res = -1;

	while (l <= h) {
		int mid = (l + h) / 2;
		if (canPlace(mid, cows, locs, n)) {
			res = mid;
			l = mid + 1;
		} else h = mid - 1;
	}
	return res;
}
