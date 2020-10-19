#include <iostream>
#include <fstream>
using namespace std;


int main(){
    setlocale(LC_ALL, "rus");
    fstream text;
    ofstream file;
    text.open("text.txt");
    file.open("file.txt");
    int n;
    text >> n;
    //cout<<"n="<<n<<endl;
    int w[n][n];
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            text >> w[i][j];
        }
    }
      for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            //cout<< w[i][j]<<" ";
        }
       // cout<<endl;
    }

    for( int k=0 ; k<n ; k++ ){
        for( int i=0 ; i<n ; i++ ){
            for( int j=0 ; j<n ; j++ ){
                w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
            }
        }
    }

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            file << w[i][j] << " ";
        }
        file <<endl;
    }
    cout<<"Смотрите ответ в file"<<endl;
    file.close();
    text.close();
}
