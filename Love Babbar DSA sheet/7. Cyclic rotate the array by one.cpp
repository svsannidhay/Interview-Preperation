void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

void rotate(int arr[], int n) {
    int prev = arr[0];
    for(int i = 1;i <= n; i++) {
        int next = arr[i%n];
        arr[i%n] = prev;
        prev = next;
    }
}