/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
    cin >> tc;
    while(tc--) {
        ll num, moves;
        cin >> num >> moves;
        if(num % 2 == 0) {
            num += moves * 2;
        } else {
            moves--;
            ll akar = sqrt(num);
            bool can = 0;
            for(i=2;i<=akar;i++) {
                if(num % i == 0) {
                    num += i;
                    can = 1;
                    break;
                }
            }
            if(!can) num *= 2;
            num += moves * 2;
        }
        cout << num << endl;
    }
	return 0;
}
