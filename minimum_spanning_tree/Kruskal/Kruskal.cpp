#include<bits/stdc++.h>

#define pb push_back
#define se second
#define fi first

using namespace std;

vector<pair<int,int> > v;
vector<pair<float,pair<int,int> > > edge,mst;
vector<int> id,sz;

int root(int p){
    int i=p;
    while(i!=id[i])
        i=id[i];
    return i;
}

bool connected(int a,int b){
    return (root(a)==root(b));
}

void quick_union(int p,int q){
    int a=root(p);
    int b=root(q);
    if(sz[a]>sz[b]){ id[b]=a;sz[a]+=sz[b]; }
    else{ id[a]=b;sz[b]+=sz[a]; }
}

int main(){
    int i=0,a,b,j,p1,p2;
    string s;
    ifstream file;
    file.open("graph_points.txt");
    file >> s;
    while(s!="-99"){
        if(i%2==0)
            a=atoi(s.c_str());
        else{
            b=atoi(s.c_str());
            v.pb(make_pair(a,b));
        }
        i++;
        file >> s;
    }

    int n=v.size();float d;
    file >> s;
    i=0;

    while(s!="-99"){
        if(i%4==0)
            a=atoi(s.c_str());
        else if(i%4==1){
            b=atoi(s.c_str());
            for(j=0;j<v.size();j++){
                if(abs(v[j].fi-a)+abs(v[j].se-b)<=20){
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
                if(abs(v[j].fi-a)+abs(v[j].se-b)<=20){
                    p2=j;
                    break;
                }
            }
            d=sqrt(pow((v[p1].fi-v[p2].fi),2)+pow((v[p1].se-v[p2].se),2));
            edge.pb(make_pair(d,make_pair(p1,p2)));
        }
        file >> s;
        i++;
    }


    for(i=0;i<n;i++){
        id.pb(i);
        sz.pb(1);
    }
    sort(edge.begin(),edge.end());


    pair<float,pair<int,int> > p;
    i=0;
    int mst_len=0;

    while(mst_len!=n-1){
        p=edge[i];
        if(!connected(p.se.fi,p.se.se)){
            mst.pb(p);
            quick_union(p.se.fi,p.se.se);
            mst_len++;
        }
        i++;
    }
    ofstream outfile;
    outfile.open("mst_points.txt");
    for(i=0;i<mst_len;i++){
        outfile << v[mst[i].se.fi].fi << " " << v[mst[i].se.fi].se << " " << v[mst[i].se.se].fi << " " << v[mst[i].se.se].se << endl;
    }

    return 0;
}

