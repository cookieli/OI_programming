#include <iostream>

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define ll long long int
ll a[200005];
ll sum[200005];
int n;
int solve(int m1,int m2,int i)
{1
    ll s1=sum[n]-sum[n-m1]+sum[i]-sum[i-m1-1];
    ll s2=sum[n]-sum[n-m2]+sum[i]-sum[i-m2-1];
    return s1*(2*m2+1)<s2*(2*m1+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    if(n<=2)
    {
        printf("1\n");
        printf("%I64d",a[1]);
        return 0;
    }
    sort(a+1,a+n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++)//预处理，后面在查询的时候能在o（1）的时间内知道某一段连续区间的和
        sum[i]=sum[i-1]+a[i];

    int wei1=1,wei2,len1=0,len2;
    int l,r;
    ll sum1=0,sum2;
    for(int i=2;i<n;i++)//枚举中位数
    {
        l=1,r=min(n-i,i-1);//最多取的数量
        int t=100;//三分次数
        while(t--)
        {

            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3; //向上取整
            if(solve(m1,m2,i))
                l=m1+1;
            else
                r=m2-1;
        }
        sum2=sum[n]-sum[n-l]+sum[i]-sum[i-l-1]-(2*l+1)*a[i];
        len2=l;
        wei2=i;
        if(sum2*(2*len1+1)>sum1*(2*len2+1))
        {
            sum1=sum2;
            wei1=wei2;
            len1=len2;
        }

    }
    printf("%d\n",2*len1+1);
    for(int j=wei1-len1;j<=wei1;j++)
        printf("%I64d ",a[j]);
    for(int j=n-len1+1;j<=n;j++)
        printf("%I64d ",a[j]);
}