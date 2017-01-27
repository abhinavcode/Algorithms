#include<bits/stdc++.h>
#define pb push_back
using namespace std;

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

int multiply(string a,string b){
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
    int n=n1;
    if(n==0)
        return 0;
    else if(n==1)
        return (a[0]-'0')*(b[0]-'0');
    int fh=n/2;
    int sh=n-n/2;
    string al=a.substr(0,fh);
    string ar=a.substr(fh,sh);
    string bl=b.substr(0,fh);
    string br=b.substr(fh,sh);
    //cout << "hi" << al << " " << ar << " " << bl << " " << br << endl;
    int p1=multiply(al,bl);
    int p2=multiply(add_two(al,ar),add_two(br,bl));
    int p3=multiply(ar,br);
    //cout << p1 << " " << p2 << " " << p3 << endl;
    return p1*(1<<(2*sh))+(p2-p1-p3)*(1<<sh)+p3;
}

int main(){
    string a,b,s="";
    cin >> a >> b;
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
    int ans=multiply(a,b);
    while(ans){
        s.pb(ans%2+'0');
        ans/=2;
    }
    for(int i=s.length()-1;i>=0;i--)
        cout << s[i];
    return 0;
}
