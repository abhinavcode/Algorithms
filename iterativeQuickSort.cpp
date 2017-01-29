#include<bits/stdc++.h>
#define pb push_back
using namespace std;


int n;
vector<int> v;

int parition(int l,int h){
    int i=l-1;
    int x=v[h];
    int j,t;
    for(j=l;j<=h-1;j++){
        if(v[j]<=x){
            i++;
            t=v[i];
            v[i]=v[j];
            v[j]=t;
        }
    }
    t=v[h];
    v[h]=v[i+1];
    v[i+1]=t;
    return i+1;
}

void quickSort(){
    int h,l;
    stack<int> ms;
    ms.push(0);
    ms.push(n-1);
    while(!ms.empty()){

        h=ms.top();
        ms.pop();
        l=ms.top();
        ms.pop();
        int p=parition(l,h);

        if(p-1>l){
            ms.push(l);
            ms.push(p-1);
        }
        if(h>p+1){
            ms.push(p+1);
            ms.push(h);
        }
    }
}


int main(){
    int i,x;
    n=100000;
    srand(time(NULL));
    for(i=0;i<n;i++){
        x=rand()%n;
        v.pb(x);
    }
    quickSort();
    for(i=0;i<n-1;i++)
        if(v[i+1]<v[i]){
        cout << "NO";
        return 0;
        }
    cout << "Sorted!";
    return 0;
}
