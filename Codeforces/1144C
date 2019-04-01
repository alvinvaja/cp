/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
int arr[200200];
bool done[200200];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp;
    cin >> n;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    vector<int> up;
    vector<int> down;
    sort(arr,arr+n);
    int last;
    for(i=0;i<n;i++)
    {
        if(i == 0)
        {
            up.push_back(arr[i]);
            last = arr[i];
            done[i] = 1;
        }
        else
        {
            if(arr[i] > last)
            {
                up.push_back(arr[i]);
                last = arr[i];
                done[i] = 1;
            }
        }
    }
    last = 400000;
    for(i=n-1;i>=0;i--)
    {
        if(done[i] == 0 && arr[i] < last)
        {
            down.push_back(arr[i]);
            last = arr[i];
            done[i] = 1;
        }
    }
    if((int)down.size() + (int)up.size() == n)
    {
        cout << "YES" << endl;
        cout << up.size() << endl;
        for(i=0;i<up.size();i++)
            printf("%d ",up[i]);
        cout << endl;
        cout << down.size() << endl;
        for(i=0;i<down.size();i++)
            printf("%d ",down[i]);
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
