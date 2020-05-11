/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[55][33];
stack<int> st[55];
int dp[55][33];
map<string, int> mp;
struct trie
{
    struct trie *child[26];
    int cnt;
};
ll chaeng;
char s[2000020];
int len, k;
struct trie *getNode()
{
    struct trie *node = new trie;
    node->cnt = 0;
    for(int i = 0; i < 26;i++)
    {
        node->child[i] = NULL;
    }
    return node;
};
void insertNode(struct trie *root)
{
    struct trie *crawl = root;
    for(int i=0;i<len;i++)
    {
        int curr = s[i] - 'A';
        if(!crawl->child[curr]) crawl->child[curr] = getNode();
        crawl = crawl->child[curr];
        crawl->cnt++;
        if(crawl->cnt >= k)
        {
            chaeng++;
            crawl->cnt -= k;
        }
    }
}
int main()
{
    int n,i,j,x,y,ans,temp,curr,m;
    int tc;
    cin >> tc;
    int inc = 1;
    int p;
    while(tc--)
    {
        cin >> n >> k;
        struct trie *root = getNode();
        chaeng = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%s", s);
            len = strlen(s);
            insertNode(root);
        }
        printf("Case #%d: %lld\n", inc++, chaeng);
    }
    return 0;
}
