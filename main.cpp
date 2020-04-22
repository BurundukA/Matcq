#include <iostream>
#include <vector>

using namespace std;



int main()
{int vibor;
cin>>vibor;
if (vibor==1)
{
    int N1;
    int M1;
    cin>>N1;
    cin>>M1;
    vector <vector <double> > A(N1, vector<double>(M1));//объ€вление 1-ого вектора

    for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M1;j++)

        {
            cin>>A[i][j];
        }
    }
     for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M1;j++)

        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    int N2;
    int M2;
    cin>>N2;
    cin>>M2;
    vector <vector <double> > B(N2, vector<double>(M2));//объ€вление 2-ого вектора

    for (int i=0;i<N2;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cin>>B[i][j];
        }
    }
     for (int i=0;i<N2;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    vector <vector <double> > X(N1, vector<double>(M2));//объ€вление вектора-ответа
              if (N1!=M2)
              {
                  cout<<"NO"<<endl;
              }
                else
                {
                    int sum1=1;
                    int sum2=1;
                    int sum=0;
                    for (int i=0;i<N1;i++)//вычесление суммы главной лиагонали
                    {
                       sum1 = sum1 * A[i][i] ;
                    }
                    cout<<"sum1="<<sum1<<endl;
                    int j=0;
                    for (int i=M1-1;i>=0;i--)//вычисление суумы побочной диагонали
                    {
                       sum2 = sum2 * A[j][i] ;
                       j++;
                    }
                    cout<<"sum2="<<sum2;
                    sum= sum1-sum2;//вычисление определител€
                    cout<<"sum="<<sum<<endl;
                    vector <vector <double> > S(N1, vector<double>(M1));//объ€вление промежуточного вектора
                    for (int i=0;i<N1;i++)//обнулание промежуточного вектора
                    {
                        for (int j=0;j<M1;j++)
                        {
                            S[i][j]=0;
                        }
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    int p=N1-1;
                    for (int i=0;i<N1;i++)//перезапись главной диагонли 1-ого вектора
                    {
                       S[i][i]= A [p][p];
                       p--;
                    }
                      cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    j=0;
                    for (int i=M1-1;i>=0;i--)//перезапись побочной диагонали 1-ого вектора
                    {
                        cout<<"a="<<-A[j][i];
                       S[i][j]= -A[i][j];
                       j++;
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                     for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                           S[i][j]=S[i][j]/sum;
                        }
                        cout<<endl;
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    /*X[0][0]=S[0][0]*B[0][0]+S[0][1]*B[1][0];
                    X[0][1]=S[0][0]*B[0][1]+S[0][1]*B[1][1];
                    X[1][0]=S[1][0]*B[0][0]+S[1][1]*B[1][0];
                    X[1][1]=S[1][0]*B[0][1]+S[1][1]*B[1][1];*/
                    for (int i = 0; i < N1; i++)
  {
    for (int j = 0; j < M2; j++)
    {
      X[i][j] = 0;
      for (int k = 0; k < N1; k++)
        X[i][j] += S[i][k] * B[k][j];
    }
                cout<<"X;"<<endl;
 for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cout<<X[i][j]<<" ";
        }
        cout<<endl;
    }
}
}
}
if (vibor==2)
{
 int N1;
    int M1;
    cin>>N1;
    cin>>M1;
    vector <vector <double> > A(N1, vector<double>(M1));//объ€вление 1-ого вектора

    for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M1;j++)

        {
            cin>>A[i][j];
        }
    }
     for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M1;j++)

        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    int N2;
    int M2;
    cin>>N2;
    cin>>M2;
    vector <vector <double> > B(N2, vector<double>(M2));//объ€вление 2-ого вектора

    for (int i=0;i<N2;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cin>>B[i][j];
        }
    }
     for (int i=0;i<N2;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    vector <vector <double> > X(N1, vector<double>(M2));//объ€вление вектора-ответа
              if (N1!=M2)
              {
                  cout<<"NO"<<endl;
              }
                else
                {
                    int sum1=1;
                    int sum2=1;
                    int sum=0;
                    for (int i=0;i<N1;i++)//вычесление суммы главной лиагонали
                    {
                       sum1 = sum1 * A[i][i] ;
                    }
                    cout<<"sum1="<<sum1<<endl;
                    int j=0;
                    for (int i=M1-1;i>=0;i--)//вычисление суумы побочной диагонали
                    {
                       sum2 = sum2 * A[j][i] ;
                       j++;
                    }
                    cout<<"sum2="<<sum2;
                    sum= sum1-sum2;//вычисление определител€
                    cout<<"sum="<<sum<<endl;
                    vector <vector <double> > S(N1, vector<double>(M1));//объ€вление промежуточного вектора
                    for (int i=0;i<N1;i++)//обнулание промежуточного вектора
                    {
                        for (int j=0;j<M1;j++)
                        {
                            S[i][j]=0;
                        }
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    int p=N1-1;
                    for (int i=0;i<N1;i++)//перезапись главной диагонли 1-ого вектора
                    {
                       S[i][i]= A [p][p];
                       p--;
                    }
                      cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    j=0;
                    for (int i=M1-1;i>=0;i--)//перезапись побочной диагонали 1-ого вектора
                    {
                        cout<<"a="<<-A[j][i];
                       S[i][j]= -A[i][j];
                       j++;
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                     for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                           S[i][j]=S[i][j]/sum;
                        }
                        cout<<endl;
                    }
                    cout<<"S;"<<endl;
                    for (int i=0;i<N1;i++)
                    {
                        for (int j=0;j<M1;j++)
                        {
                            cout<<S[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    /*X[0][0]=S[0][0]*B[0][0]+S[0][1]*B[1][0];
                    X[0][1]=S[0][0]*B[0][1]+S[0][1]*B[1][1];
                    X[1][0]=S[1][0]*B[0][0]+S[1][1]*B[1][0];
                    X[1][1]=S[1][0]*B[0][1]+S[1][1]*B[1][1];*/
                    for (int i = 0; i < N1; i++)
  {
    for (int j = 0; j < M2; j++)
    {
      X[i][j] = 0;
      for (int k = 0; k < N1; k++)
        X[i][j] += B[i][k] * S[k][j];
    }
                cout<<"X;"<<endl;
 for (int i=0;i<N1;i++)
    {
        for (int j=0;j<M2;j++)

        {
            cout<<X[i][j]<<" ";
        }
        cout<<endl;
    }
}
}
}

    return 0;
}
