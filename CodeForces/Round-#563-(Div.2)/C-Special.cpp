#include <iostream>
using namespace std;
int ans[100005];
int main()
{
    int n,c=0;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        if (!ans[i])
        {
            ans[i]=++c;
            for (int j=i;j<=n;j+=i)
            ans[j]=ans[i];
        }
        printf("%d ",ans[i]);
    }
}