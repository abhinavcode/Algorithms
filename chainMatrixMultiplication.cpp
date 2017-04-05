#include<bits/stdc++.h>

using namespace std;

int n,g=1,m=100;
int factor[100][100];

void print_path(int i,int j){
    if(i==j){
        cout << g;
        g++;
        return;
    }
    cout << "(";
    int k=factor[i][j];
    print_path(i,k);
    print_path(k+1,j);
    cout << ")";
}

int main(){
    int i,j,k,h=0,m,x;
    cin >> n;
    int r[n+1];
    for(i=0;i<=n;i++)
        cin >> r[i];
    int matrix[n+1][n+1];

    for(i=0;i<=n;i++)
    for(j=0;j<=n;j++){
    matrix[i][j]=-1;
    factor[i][j]=-1;
    }

    for(x=0;x<n;x++){
        for(i=1;i<=n;i++){
            j=i+h;
            m=INT_MAX;
            if(j<=n){
                if(!h)
                    matrix[i][j]=0;
                else{
                    for(k=i;k<j;k++){
                        if(matrix[i][k]+matrix[k+1][j]+r[i-1]*r[k]*r[j] < m){
                            m=matrix[i][k]+matrix[k+1][j]+r[i-1]*r[k]*r[j];
                            factor[i][j]=k;
                        }
                        matrix[i][j]=m;
                    }
                }
            }
        }
        h++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout << factor[i][j] << " ";
        cout << endl;
    }

    print_path(1,n);

    return 0;
}
