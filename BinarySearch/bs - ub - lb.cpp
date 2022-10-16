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

// index of element immediate greater than el
int upperBound(vector<int> &nums, int el){
    int l = 0, h = nums.size()-1;
    while(l <= h){
        int mid = (l + h)/2;
        if(nums[mid] <= el) l = mid+1;
        else h = mid-1;
    }
    return l;
}

// index of first greater or equal element than el
int lowerBound(vector<int> &nums, int el){
    int l = 0, h = nums.size()-1;
    while(l <= h){
        int mid = (l + h)/2;
        if(nums[mid] < el) l = mid+1; // insted of <= it is <
        else h = mid-1;
    }
    return l;
}
