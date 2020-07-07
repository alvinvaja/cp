/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
/*
    Suffix Array Template by alvinvaja

    Tested on EDU Codeforces with 1232ms time processing string with length up to 4*10^5
    Speed might be increased significantly by applying radix sort instead of std::sort()
*/
#include<bits/stdc++.h>
using namespace std;
int ranking[400400];
int skip[400400], previous[400400], lcpArr[400400];
map<char, int> mp;
vector<pair<char,int> > v;
vector<pair<pair<int,int>, int> > vprev, vnext;
string s;
void init() // initialize equivalence classes
{
    char last = '$';
    int curr = 0;
    for(auto x : v) {
        if(x.first > last) {
            curr++;
            last = x.first;
        }
        ranking[x.second] = curr;
    }
}
void rerank() // rerank equivalence classes
{
    int curr = 0;
    pair<int,int> p = {0, 0};
    for(auto x : vnext) {
        if(x.first > p) {
            curr++;
            p = x.first;
        }
        ranking[x.second] = curr;
    }
}
int getLCP(int now, int prev, int n)
{
    int ans = skip[now];
    int i;
    for(i=ans;i<n;i++) {
        if(s[(now+i)%n] == s[(prev+i)%n]) {
            ans++;
        } else break;
    }
    return ans;
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    cin >> s;
    s += '$';
    n = s.length();
    for(i=0;i<n;i++) {
        v.push_back({s[i], i});
    }
    sort(v.begin(), v.end());
    init();
    for(auto x : v) {
        vprev.push_back({{ranking[x.second], ranking[(x.second+1)%n]}, x.second});
    }
    for(i=2;i<n;i*=2) {
        sort(vprev.begin(), vprev.end());
        vnext.swap(vprev);
        rerank();
        vprev.clear();
        for(auto x : vnext) {
            vprev.push_back({{ranking[x.second], ranking[(x.second+i)%n]}, x.second});
            // we save the rank of each suffixes by storing index of beginning of every suffixes
        }
    }
    sort(vprev.begin(), vprev.end());
    cout << "Suffix Array\n";
    for(auto x : vprev) {
        cout << x.second << " ";
    }
    cout << endl << endl;

    // LCP part starts here
    for(i=1;i<n;i++) {
        x = vprev[i].second;
        previous[x] = vprev[i-1].second;
    }
    for(i=0;i<n-1;i++) {
        int lcp = getLCP(i, previous[i], n);
        lcpArr[i] = lcp;
        if(lcp > 1) skip[i+1] = lcp-1;
    }
    cout << "LCP Array\n";
    for(i=1;i<n;i++) {
        cout << lcpArr[vprev[i].second] << " ";
    }
    cout << endl;
    return 0;
}
