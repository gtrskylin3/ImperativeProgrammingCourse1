int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ; i < n; ++ i){
        int cur;
        scanf("%d", &cur);
        arr[i] = cur;
    }
    for (int k = 1; k <= n; ++k){
        int tk = 0;
        for (int j = 1; j <= n/k; ++j){
            tk += arr[j*k-1];
        }
        printf("%d\n", tk);
    }
}