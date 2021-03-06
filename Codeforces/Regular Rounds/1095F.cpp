#include <bits/stdc++.h>
using namespace std;
long long int w[200100];
int parent[200100];
vector<pair<long long int, pair<int,int> > > vi;
int root(int x)
{
	if(parent[x] == x)
		return x;
	else
		return parent[x] = root(parent[x]);
}
int main() {
	int n,i,j,k,x,y,idx;
	long long int mini = 1e18;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		
		scanf("%lld",&w[i+1]);
		if(mini > w[i+1])
		{
			mini = w[i+1];
			idx = i+1;
		}
	}
	long long int cost,ans,curr,temp;
	for(i=0;i<k;i++)
	{
		scanf("%d %d %lld",&x,&y,&cost);
		vi.push_back(make_pair(cost,make_pair(x,y)));
	}
	for(i=1;i<=n;i++)
	{
		if(i != idx)
		{
			vi.push_back(make_pair(w[i]+w[idx],make_pair(i,idx)));
		}
	}
	for(i=1;i<=200000;i++)
	{
		parent[i] = i;
	}
	ans = 0;
	long long int sz = vi.size();
	sort(vi.begin(),vi.end());
	int counter = 0;
	for(i=0;i<sz;i++)
	{
		if(counter == n-1)
			break;
		x = vi[i].second.first;
		y = vi[i].second.second;
		if(root(x) == root(y)) continue;
		parent[root(x)] = root(y);
		ans += vi[i].first;
		counter++;
	}
	printf("%lld\n",ans);
	return 0;
}
