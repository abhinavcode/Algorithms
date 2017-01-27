#include<bits/stdc++.h>
#define pb push_back
using namespace std;

string a,b;
vector<string> s;

void make_equal_length(){
    int n1=a.length();
    int n2=b.length();
    while(n1<n2){
        a.insert(0,"0");
        n1++;
    }
    while(n2<n1){
        b.insert(0,"0");
        n2++;
    }
    //cout << a << endl << b << endl;
}

string strip(string x){
    int n=x.length();
    int i=0,j;
    string ans="";
    while(x[i]=='0'){
        i++;
    }
    for(j=i;j<n;j++)
        ans.pb(x[j]);
    return ans;
}

string add_two(string x,string y){
    string p="";
    int i;
    int l1=x.length();
    int l2=y.length();
    while(l1<l2){
        x.insert(0,"0");
        l1++;
    }
    while(l2<l1){
        y.insert(0,"0");
        l2++;
    }
    //cout << "hi " << x << " " << y << endl;
    int carry=0;
    for(i=l1-1;i>=0;i--){
        int a=(x[i]-'0'+y[i]-'0'+carry);
        if(a==2){
            p.insert(0,"0");
            carry=1;
        }
        else if(a==3){
            p.insert(0,"1");
            carry=1;
        }
        else if(a==1){
            p.insert(0,"1");
            carry=0;
        }
        else{
            p.insert(0,"0");
            carry=0;
        }
    }
    if(carry)
        p.insert(0,"1");
    //cout << p << endl;
    return p;
}

void add(){
    int i;
    if(s.size()==1){
        cout << s[0];
        return;
    }
    string p=add_two(s[0],s[1]);
    for(i=2;i<s.size();i++){
        p=add_two(p,s[i]);
    }
    p=strip(p);
    cout << p;
}

void multiply(){
    int n1=a.length();
    int n2=b.length();
    int i,j;
    string p,x="";
    for(i=n1-1;i>=0;i--){
        p=x;
        for(j=n2-1;j>=0;j--){
            if(a[i]=='1'&&b[j]=='1')
                p.insert(0,"1");
            else
                p.insert(0,"0");
        }
        //cout << p << endl;
        s.pb(p);
        x.pb('0');
    }
    add();
}

int main(){
    cin >> a >> b;
    make_equal_length();
    multiply();
    return 0;
}
