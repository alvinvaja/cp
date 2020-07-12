/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[100100];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        int q;
        cin >> n >> q;
        for(i=1;i<n;i++) cin >> arr[i];
        vector<int> chaeng;
        while(q--) {
            int s;
            scanf("%d %d",&s,&k);
            int l = s-1;
            int r = s;
            int now = s;
            k--;
            while(k--) {
                if(l < 1) {
                    now = r+1;
                    r++;
                } else if(r >= n) {
                    now = l;
                    l--;
                } else {
                    if(arr[l] > arr[r]) {
                        now = r+1;
                        r++;
                    } else {
                        now = l;
                        l--;
                    }
                }
            }
            chaeng.push_back(now);
        }
        printf("Case #%d:", inc++);
        for(auto x : chaeng) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
