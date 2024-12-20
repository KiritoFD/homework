double myPow(double x, int n) {
     double result=1.00;
     if(n==0) return 1;
     if(x==1) return 1;
     if(x==-1) return n%2?-1:1;
     if(n<0){
        x=1/x;
        if(n<-2147483647) return 0;
        n=-n;
     }
    while(n){
        if(n%2){
            result*=x;
        }
        x*=x;
        n/=2;
    }return result;
}