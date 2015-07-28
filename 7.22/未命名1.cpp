#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int p, a[4];
void j(int x)
{
	a[abs(x)]--;
	printf("%d ", p+=x);
}
int main()
{
	int T, n, x, i, f;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &a[1], &a[2], &a[3]);
		n=a[1]+a[2]+a[3]+1;
		x=a[3]/3;
		p=0;
		printf("%d ", p);
		if (a[3]%3==0)
		{
			for (i=0; i<x; i++) j(3);	j(1);
			for (i=0; i<x; i++) j(-3);	j(1);
			for (i=0; i<x; i++) j(3);
		} else if (a[3]%3==1)
		{
			for (i=0; i<x+1; i++) j(3);	j(-2);
			for (i=0; i<x; i++) j(-3);	j(1);
			for (i=0; i<x; i++) j(3);	j(2);
		} else
		{
			for (i=0; i<x+1; i++) j(3);	j(-2);
			for (i=0; i<x; i++) j(-3);	j(1);
			for (i=0; i<x+1; i++) j(3);	j(-1); j(2);
		}
		f=a[2]&1;
		x=a[2]/2;
		while (a[1]>1) j(1);
		while (a[2]>x) j(2);
		if (f) j(-1); else j(1);
		for (i=0; i<x; i++) j(-2);
		printf("\n");
	}
	return 0;
}
