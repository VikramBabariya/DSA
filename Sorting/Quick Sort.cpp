int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;

    while(i < j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int randomPart(vector<int> &arr, int low, int high){
    srand(time(NULL));
    int ri = low + random() % (high - low + 1);
    swap(arr[ri], arr[low]);
    return partition(arr, low, high);
}

void qs(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int pi = randomPart(arr, low, high);
    qs(arr, low, pi-1);
    qs(arr, pi+1, high);
}
