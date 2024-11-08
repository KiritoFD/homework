int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int j=0,i=digitsSize-1;
    for(;i>=0;i--){
        if(digits[i]!=9) {
        j=1;
        break;}
    }
    if(j==0){
        int *a=(int*)malloc(sizeof(int)*(digitsSize+1));
        a[0]=1;
        for(i=1;i<=digitsSize;i++) a[i]=0;
        *returnSize=digitsSize+1;
        return a;
    }
    else{*returnSize=digitsSize;
    digits[digitsSize-1]++;
        int *a=(int*)malloc(sizeof(int)*(digitsSize));
        for(i=digitsSize-1;i>=0;i--){
            if(digits[i]==10){
                digits[i]=0;
                digits[i-1]++;
                
            }
            a[i]=digits[i];
        }
        return a;
    }
}