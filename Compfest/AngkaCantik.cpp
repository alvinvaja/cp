/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
    Mbak Seulgi Dong
*/
#include<bits/stdc++.h>
#include <string>
using namespace std;
int arr[15];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
    }
    string jadi = "";
    for(i=1;i<=n;i++) {
        if(arr[i] == 0) continue;
        map<int,int> mp;
        j = 1;
        int now = arr[i];
        mp[now % m] = j;
        while(1) {
            now = (now * 10 + arr[i]) % m;
            j++;
            if(mp[now] != 0) break;
            else mp[now] = j;
        }
        temp = j;
        char c = '0' + arr[i];
        for(j=mp[now]+1;j<=temp;j++) jadi += c;
        for(j=1;j<=mp[now];j++) jadi += "0";
    }
    cout << jadi << endl;
    return 0;
}