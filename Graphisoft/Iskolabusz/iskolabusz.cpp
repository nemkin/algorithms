#include<cstdio>
main(){
    int n,x=0;
    scanf("%d",&n);
    for(n*=2;n>>++x;);
    printf("%d\n",n^1<<--x?n^1<<x:n/2);
}
