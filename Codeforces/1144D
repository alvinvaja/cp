/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
int cnt[200200];
int arr[200200];
vector<pair<int, pair<int,int> > > vi;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        cnt[arr[i]]++;
    }
    int maxi = 0;
    int cari = 0;
    int pos;
    for(i=0;i<=200000;i++)
    {
        if(cnt[i] > maxi)
        {
            maxi = cnt[i];
            cari = i;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i] == cari)
        {
            pos = i;
            break;
        }
    }
    int l = pos-1;
    int r = pos+1;
    while(l > 0)
    {
        if(arr[l] == cari)
        {
            l--;
        }
        else if(arr[l] < cari)
        {
            arr[l] = cari;
            vi.push_back(make_pair(1,make_pair(l,l+1)));
            l--;
        }
        else
        {
            arr[l] = cari;
            vi.push_back(make_pair(2,make_pair(l,l+1)));
            l--;
        }
    }

    while(r <= n)
    {
        if(arr[r] == cari)
        {
            r++;
        }
        else if(arr[r] < cari)
        {
            arr[r] = cari;
            vi.push_back(make_pair(1,make_pair(r,r-1)));
            r++;
        }
        else
        {
            arr[l] = cari;
            vi.push_back(make_pair(2,make_pair(r,r-1)));
            r++;
        }
    }
    cout << vi.size() << endl;
    for(i=0;i<vi.size();i++)
    {
        printf("%d %d %d\n",vi[i].first, vi[i].second.first, vi[i].second.second);
    }
    return 0;
}
