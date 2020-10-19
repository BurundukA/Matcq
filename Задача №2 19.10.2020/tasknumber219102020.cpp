#include<iostream>
#define INF 1000000000
#include <fstream>

using namespace std;

int main(){
    setlocale(LC_ALL,"rus");
    fstream text;
    ofstream file;
    text.open("text.txt");
    file.open("file.txt");
    int n,i,j,k,s,t,m;
    text>>n>>m;
    //cout<<"n="<<n<<endl;
    //cout<<"m="<<m<<endl;
    if (m) { int a[n][n];
    for(i=0;i<n;++i)for(j=0;j<n;++j)
        if(i==j)a[i][j]=0;
        else a[i][j]=INF;
    for(k=0;k<m;++k){
            text>>i>>j;
            //cout<<i<<" "<<j<<" ";
            text>>a[i-1][j-1];
            //cout<<a[i-1][j-1]<<endl;
            a[j-1][i-1]=a[i-1][j-1];}
    for(k=0;k<n;++k)
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
               if(a[i][j]>a[i][k]+a[k][j])
               a[i][j]=a[i][k]+a[k][j];
    k=0;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
           if (a[i][j]<INF&&a[i][j]>k)
            k=a[i][j];
            cout<<"ќответ смотрите в file"<<endl;
           file<<k; }

    else {
        cout<<"ќответ смотрите в file"<<endl;
        file<<0;}
return 0;}
