#include<bits/stdc++.h>
using namespace std;
int a(int b){
    int c=0,e=b;
    while(b){
        int d=b%10;
        c+=d*d*d;
        b/=10;
    }

    if(c==e) return 1;
    else return 0;

}
int main()
{
    int q,w;cin>>q>>w;
    for(int i=q;i<=w;i++)
        if(a(i)==1) cout<<i<<endl;

}