#include<bits/stdc++.h>

#define pb push_back
#define se second
#define fi first

using namespace std;
typedef pair<float,pair<int,int> > p;
priority_queue<p , vector<p>, greater<p> > pq;
vector<pair<int,int> > mst;

vector<pair<int,int> > v;


int main(){
    ifstream infile;
    infile.open("graph_points.txt");
    string s;
    infile >> s;
    int i=0,a,b,j,p1,p2;
    float d;
    while(s!="-99"){
        if(i%2==0)
            a=atoi(s.c_str());
        else{
            b=atoi(s.c_str());
            v.pb(make_pair(a,b));
        }
        i++;
        infile >> s;
    }
    int n=v.size();

    float edge[n][n];
    bool visit[n];
    for(i=0;i<n;i++)
        visit[i]=false;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            edge[i][j]=0;
    }

    infile >> s;
    i=0;

    while(s!="-99"){
        if(i%4==0)
            a=atoi(s.c_str());
        else if(i%4==1){
            b=atoi(s.c_str());
            for(j=0;j<v.size();j++){
                if(abs(v[j].fi-a)+abs(v[j].se-b)<=40){
                    p1=j;
                    break;
                }
            }
        }
        else if(i%4==2){
            a=atoi(s.c_str());
        }
        else{
            b=atoi(s.c_str());
            for(j=0;j<v.size();j++){
                if(abs(v[j].fi-a)+abs(v[j].se-b)<=40){
                    p2=j;
                    break;
                }
            }
            d=sqrt(pow((v[p1].fi-v[p2].fi),2)+pow((v[p1].se-v[p2].se),2));
            edge[p1][p2]=d;
            edge[p2][p1]=d;
        }
        infile >> s;
        i++;
    }


    for(i=1;i<n;i++){
        if(edge[0][i])
            pq.push(make_pair(edge[0][i],make_pair(0,i)));
    }
    visit[0]=true;

    while(!pq.empty()){
        p popped=pq.top();
        pq.pop();
        if(visit[popped.se.fi]&&visit[popped.se.se])
            continue;
        int x=popped.se.se;
        visit[x]=true;
        mst.pb(make_pair(popped.se.fi,popped.se.se));
        for(i=0;i<n;i++){
            if(edge[x][i] && i!=x && !visit[i]){
                pq.push(make_pair(edge[x][i],make_pair(x,i)));
            }
        }

    }

    ofstream outfile;
    outfile.open("mst_points.txt");


    for(i=0;i<mst.size();i++){
        outfile << v[mst[i].fi].fi << " "<< v[mst[i].fi].se << " " << v[mst[i].se].fi  << " " << v[mst[i].se].se << endl;
    }

    return 0;
}
