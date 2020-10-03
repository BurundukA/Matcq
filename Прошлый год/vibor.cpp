#include <iostream>
#include <cstdlib>
#include <cmath>
#include "func.cpp"
using namespace std;

int main()
{
  int row1, row2, col1, col2;
  double** a, ** b, ** x, ** Aa,**m;
  system("chcp 1251");
  system("color 8B");
  system("cls");
  int number;
   cout<<"Выберите 1) AX=B или 2) XA=B"<<" ";
   cout<<"3) Решение линейных уравнений"<<" ";
   while (number>3 or number<1)
   {
    cin>>number;
    if (number>3 or number<1)
    {
        cout<<"введите снова, такой команды нет"<<endl;
    }
   }
   if (number == 3)
  {
     int i, j, n, m;

   cout << "введи число уравнений: ";
         cin >> n;
         cout << "введи число неизвестных(x): ";
         cin >> m;
         m++;
    double **matr = new double *[n];
         for (i=0; i<n; i++)
             matr[i] = new double [m];



    for (i = 0; i<n; i++)

        for (j = 0; j<m; j++)
        {
            cout << "Элемент " << "[" << i+1 << " , " << j+1 << "]: "  ;

            cin >> matr[i][j];
}


    cout << "matrix: " << endl;
      for (i=0; i<n; i++)
       {
          for (j=0; j<m; j++)
            cout << matr[i][j] << " ";
        cout << endl;
       }
    cout << endl;



    float  tmp;
    int k;
float *dop = new float [m];
    liner(matr,dop,n,m);
//Выводим решения
       for (i=0; i<n; i++)
           cout << dop[i] << " ";
       cout << endl;

    delete[] matr;

   return 0;
}
else{
    cout << "Введите количество строк первой матрицы: ";
  cin >> row1;
  cout << "Введите количество столбцов первой матрицы: ";
  cin >> col1;


  a = new double* [row1];
  b = new double* [row2];
  m = new double* [row1];
  x = new double* [row1];
  Aa = new double* [row1];
  cout << "Введите элементы первой матрицы" << endl;
  for (int i = 0; i < row1; i++)
  {
    a[i] = new double[col1];
    for (int j = 0; j < col1; j++)
    {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
  }


  for (int i = 0; i < row1; i++)
  {
    m[i] = new double[col1];
    for (int j = 0; j < col1; j++)
    {
      m[i][j] = a[i][j];
    }
  }

  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col1; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }


  cout << "Введите количество строк второй матрицы: ";
  cin >> row2;
  cout << "Введите количество столбцов второй матрицы: ";
  cin >> col2;

  cout << "Введите элементы второй матрицы" << endl;
  for (int i = 0; i < row2; i++)
  {
    b[i] = new double[col2];
    for (int j = 0; j < col2; j++)
    {
      cout << "b[" << i << "][" << j << "]= ";
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < col2; j++)
    {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }

   if (col1 != row2 or (row1!=row2 and col1!=col2))
  {
    cout << "No";
    return 0;
  }
  // Умножение матриц
  int determm = determ(a,row1);//Определитель матрицы n-ого порядка
  cout<<"Определитель матрицы: "<<determm<<endl;
  cout<<" "<<endl;
if (determm==0)
{
    cout<<"No";
    return 0;
}
cout<<"Минор функции: "<<endl;
   minor(m,row1);//M минор функции
  for (int i=0;i<row1;i++)
  {
      for (int j=0;j<row1;j++)
      {
          cout<<m[i][j]<<" ";
      }
      cout<<""<<endl;
  }
cout<<"A->: "<<endl;
int h=0;
for (int i=0;i<row1;i++)
  {
       Aa[i] = new double[col1];
      for (int j=0;j<row1;j++)
      {
          h=power(-1, (i+j))*m[i][j];
          Aa[i][j] = h;
          cout<<Aa[i][j]<<" ";
      }
      cout<<""<<endl;
  }


  trans(Aa,row1,col1);
  for (int i=0;i<row1;i++)
  {
      for (int j=0;j<row1;j++)
      {
          cout<<Aa[i][j]<<" ";
      }
      cout<<""<<endl;
  }
  cout<<"A-1: "<<endl;

  float n=1.0/determm;

if (number==1)
{
 multAB(Aa,b,x,row1,col1,row2,col2);//Умножение матриц
}
else if (number==2)
{
     multAB(b,Aa,x,row1,col1,row2,col2);
}
  cout<<" "<<endl;
  cout<<""<<endl;
  // Вывод матрицы произведения
  cout << "Матрица произведения: " << endl;
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col2; j++)
        if (x[i][j]==-0)
    {
        cout << abs((n)*x[i][j]) << " ";
    }
    else{
            cout << (n)*x[i][j] << " ";
    }

    cout << endl;
  }



  return 0;
}
}
