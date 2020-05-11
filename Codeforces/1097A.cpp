#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k;
    char arr[5];
    scanf("%s",arr);
    char deck[5][5];
    int valid = 0;
    for(i=0;i<5;i++)
    {
        scanf("%s",deck[i]);
        if(arr[0] == deck[i][0] || arr[1] == deck[i][1])
            valid = 1;
    }
    if(valid == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
