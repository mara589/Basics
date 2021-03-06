#include <iostream>

using namespace std;

int n, m, s[100], k;

void first(int k)
{
    s[k]=0;
}

int next(int k)
{
    if(s[k]<n-m+k)
    {
        s[k]++;
        return 1;
    }
    else return 0;
}

int valid(int k)
{
    int i;
    for(i=1;i<k;i++)
    if(s[k] == s[i])
    return 0;

    if(s[k] < s[k-1])
    return 0;

    return 1;
}

int is_solution(int k)
{
    if(k==m)
    return 1;
    else
    return 0;
}

void out(int k)
{
    for(int i=1;i<=k;i++)
    cout<<s[i]<<" ";
    cout<<endl;
}

void backtracking(int k)
{
    first(k);
    while(next(k))
    if(valid(k))
    if (is_solution(k))
    out(k);
    else
    backtracking(k+1);
}

// Backtracking Problem - Combinations of n taken m

int main()
{
    cin>>n; cin>>m;
    backtracking(1);
}
