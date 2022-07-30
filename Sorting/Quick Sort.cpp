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

void qs(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int pi = partition(arr, low, high);
    qs(arr, low, pi-1);
    qs(arr, pi+1, high);
}
