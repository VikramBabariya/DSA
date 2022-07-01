void run_case() {
	int arr[] = {237, 146, 259, 348, 152, 152, 163, 235, 48, 36, 62};

	int n = 11;
	vector<queue<int>> bucks(10);
	int pass = ceil(log10(*max_element(arr, arr + n)));
	for (int p = 0, div = 1; p < pass; p++, div *= 10) {
		for (int i = 0; i < n; i++) {
			int digit = (arr[i] / div) % 10;
			bucks[digit].push(arr[i]);
		}

		int it = 0;
		for (int i = 0; i < 10; i++) {
			while (!bucks[i].empty()) {
				arr[it] = bucks[i].front();
				it++;
				bucks[i].pop();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
