#include<stdio.h>
int a[1000001];
int b[1000001];
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int j=0;j<q;j++) scanf("%d%d",&a[j],&b[j]);
		for(int s=0;s<q-1;s++)
		{
			if(a[s+1]-a[s]==2)
				printf("%d %d\n",a[s]+1,b[s]);
			if(b[s+1]-b[s]==-2)
				printf("%d %d\n",a[s],b[s]-1);
			if(b[s+1]-b[s]==2)
				printf("%d %d\n",a[s],b[s]+1);
			if(a[s+1]-a[s]==1&&b[s+1]-b[s]==1) {
				if(a[s]%2==1) printf("%d %d\n",a[s],b[s]+1);
				else printf("%d %d\n",a[s]+1,b[s]);
			}
			if(a[s+1]-a[s]==1&&b[s+1]-b[s]==-1)
			{
				if(a[s]%2==1) printf("%d %d\n",a[s]+1,b[s]);
				else printf("%d %d\n",a[s],b[s]-1);
			}
		}
	}
	return 0;
}