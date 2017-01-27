#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> v;

void insertion(int x){
    int i;
    v.pb(x);
    i=v.size()-1;
    while(i>0){
        int par=(i-1)/2;
        if(par>=0&&v[i]>v[par]){
            int t=v[par];
            v[par]=v[i];
            v[i]=t;
        }
        i=par;
    }
}


void del_root(int x){
    int i;
    int t=v[x-1];
    v[x-1]=v[0];
    v[0]=t;
    i=0;

    x--;
    int l=2*i+1;
    int r=2*i+2;
    while(r<x){
        int m;
        if(l>x)
            return;
        else if(l==x-1&&v[l]>v[i]){
            int t=v[l];
            v[l]=v[i];
            v[i]=t;
            return;
        }
        if(v[i]>=v[l]&&v[i]>=v[r])
            return;
        if(v[l]>v[r]){
            m=l;
        }
        else
            m=r;
        int t=v[m];
        v[m]=v[i];
        v[i]=t;
        i=m;
        l=2*i+1;
        r=l+1;
    }
}

void printHeap(){
    int i,n=v.size();
    for(i=0;i<n;i++)
        cout << v[i] << " ";
    cout <<endl;
}

void heapSort(){
    int n=v.size();
    int x=n,i;
    for(i=0;i<n;i++){
        del_root(x);
        x--;
        cout << "Iter " << i+1 << ": ";
        printHeap();
    }
}

int main(){
    int ch,n;
    cout << "1. Insertion" << endl << "2. Print Heap so far" << endl << "3. Sort" << endl << "4. Terminate" << endl;
    while(1){
        cout << "Choice: ";
        cin >> ch;
        switch(ch){
            case 1: cout << "Number: ";
                cin >> n;
                insertion(n);
                break;
            case 2:printHeap();
            break;
            case 3:heapSort();
            break;
            case 4:exit(0);
        }
    }
    return 0;
}
