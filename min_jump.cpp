#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll min_path[n];
    memset(min_path,0,sizeof(min_path));
    for(ll i=1;i<n;i++){
        min_path[i]=i;
        for(ll j=0;j<i;j++){
            if(arr[i]!=arr[j]){
                min_path[i]=min(min_path[i],min_path[j]+(i-j));
            }
            else{
                min_path[i]=min(min_path[i],min_path[j]+1);
            }
        }
    }
    for(ll i=1;i<n;i++){
        for(ll j=n-1;j>0;j--){
            if(j>i){
            if(arr[i]!=arr[j]){
                min_path[i]=min(min_path[i],min_path[j]+(j-i));
            }
            else{
                min_path[i]=min(min_path[i],min_path[j]+1);
            }
            }
            else if(j<i){
            if(arr[i]!=arr[j]){
                min_path[i]=min(min_path[i],min_path[j]+(i-j));
            }
            else{
                min_path[i]=min(min_path[i],min_path[j]+1);
            }
            }
        }
    }
    cout<<"Minimum Jumps Required : "<<min_path[n-1]<<endl;
}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
/*
The input format is
line 1: number of elements (n)
line 2: value of element (arr[i])
*/
