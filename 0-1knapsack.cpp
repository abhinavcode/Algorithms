#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n,i,j;
    cin >> n;
    int wt[n],val[n];
    for(i=0;i<n;i++){
        cin >> wt[i] >> val[i];
    }

    int ks[n][t+1];
    for(i=0;i<n;i++){
        for(j=0;j<=t;j++){
            if(j==0)
                ks[i][j]=0;
            else if(wt[i]>j){
                if(i>0)
                    ks[i][j]=ks[i-1][j];
                else
                    ks[i][j]=0;
            }
            else{
                if(i>0)
                    ks[i][j]=max(ks[i-1][j],ks[i-1][j-wt[i]]+val[i]);
                else
                    ks[i][j]=val[i];
            }
        }
    }



    for(i=0;i<n;i++){
        for(j=0;j<=t;j++)
            cout << ks[i][j] << " ";
        cout << endl;
    }

    i=n-1;j=t;
    while(ks[i][j]!=0){

        if(i==0&&ks[i][j]){
            cout << wt[i] << " " << val[i] << endl;
            break;
        }
        if(ks[i][j]==ks[i-1][j])
            i--;
        else{
            cout << wt[i] << " " << val[i] << endl;
             j-=wt[i];
            i--;
        }
    }

    return 0;
}
