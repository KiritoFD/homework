bool isPowerOfTwo(int n) {
    long long a[31];
    a[0]=1;
    for(int i=1;i<31;i++) a[i]=a[i-1]*2;
    for(int i=0;i<31;i++){
        if(a[i]==n) return true;
    }return false;
}