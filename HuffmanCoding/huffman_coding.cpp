#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

map<char,int> freq;
map<char,string> code;
typedef pair<int,string> p;
priority_queue<p,vector<p>,greater<p> > pq;

ifstream::pos_type filesize(const char* filename);

int main(){
    string s="",z="",line;
    ifstream infile("text.txt");

    int e;
    infile.seekg(0,ios_base::end);
    e=infile.tellg();
    infile.close();
    infile.open("text.txt");
    while(getline(infile,line)){
        s+=line;
    }

    int i,cs=0;
    int n=s.length();
    for(i=0;i<n;i++){
        freq[s[i]]++;
    }
    for(map<char,int>::iterator it=freq.begin();it!=freq.end();it++){
       //cout << it->first << " " << it->second << " ";
       z.pb(it->first);
       pq.push(make_pair(it->second,z));
       code[it->first]="";
       z="";
    }

    while(pq.size()!=1){
        p a,b;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        //cout << a.se << " " << b.se << endl;
        for(i=0;i<a.se.length();i++){
            code[a.se[i]].insert(0,"0");
        }
        for(i=0;i<b.se.length();i++){
           code[b.se[i]].insert(0,"1");
        }
        pq.push(make_pair(a.fi+b.fi,a.se+b.se));
    }

    for(map<char,string>::iterator it=code.begin();it!=code.end();it++){
        cout << it->first << " " << it->second << endl;
        cs+=freq[it->first]*it->second.length();
    }

    cout << "Original file size: " << e << endl;
    cout << "Compressed size using Huffman Codes: " << cs/8;
    return 0;
}
