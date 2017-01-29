#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int n;
vector<int> v;

void mergeInPlace(int left,int mid1,int mid2,int right){
    int l=right-left+1;
    int tmp[l];
    int i=left,j=mid2;
    int k=0;
    while(i<=mid1&&j<=right){
        if(v[i]<v[j])
            tmp[k++]=v[i++];
        else
            tmp[k++]=v[j++];
    }
    while(i<=mid1)
        tmp[k++]=v[i++];
    while(j<=right)
        tmp[k++]=v[j++];
    k=0;
    for(i=left;i<=right;i++)
        v[i]=tmp[k++];
}

void mergeSort(){
    int width=1,i;
    while(width<n){
        for(i=0;i<n;i+=2*width){
            int left=i;
            int mid1=i+width-1;int mid2=i+width;
            int right=min(i+2*width-1,n-1);
            mergeInPlace(left,mid1,mid2,right);
        }
        width*=2;
    }

}

int main(){
    int i,x;
    //cin >> n;
    n=100000;
    srand(time(NULL));
    for(i=0;i<n;i++){
        //cin >> x;
        x=rand()%n;
        v.pb(x);
    }

    mergeSort();
    for(i=0;i<n-1;i++){
        cout << v[i] << " ";
    }
    return 0;
}
