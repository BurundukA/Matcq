double determ(double** Arr, int size);

void multAB(double** a, double** b, double** x,int row1,int col1, int row2, int col2)
{
  for (int i = 0; i < row1; i++)
  {
    x[i] = new double[col2];
    for (int j = 0; j < col2; j++)
    {
      x[i][j] = 0;
      for (int k = 0; k < col1; k++)
        x[i][j] += a[i][k] * b[k][j];
    }
  }
}

double power(int s, int p)
{
    int i = p;
    int k = 1;

            if (p > 0)
            {
                k=s*power(s, p-1);

            }
return k;
}
int minor (double**m ,int row1)
  {
       int k;


          for (int i=0; i<row1; i++)
       {
          for (int j=i; j<row1; j++)
             {
               k=m[i][j];
               m[i][j]=m[j][i];
               m[j][i]=k;
              }
         }
          for (int i=0; i<row1-1; i++)
       {
          for (int j=0; j<row1-1; j++)
             {
                    if (i==j)
                    {
                       k=m[i][j];
               m[i][j]=m[i+1][j+1];
               m[i+1][j+1]=k;
                    }
              }
         }
         return k;
  };
int trans (double**At ,int row1,int col1)
  {
    int k;
    for (int i=0; i<row1; i++)
       {
          for (int j=i; j<col1; j++)
             {
               k=At[i][j];
               At[i][j]=At[j][i];
               At[j][i]=k;
              }
         }
         return k;
  };

  double determ(double** Arr, int size)
{
        int i,j;
        double det=0;
        double** matr;
        if(size==1)
        {
                det=Arr[0][0];
        }
        else if(size==2)
        {
                det=Arr[0][0]*Arr[1][1]-Arr[0][1]*Arr[1][0];
        }
        else
        {
                matr=new double*[size-1];
                for(i=0;i<size;++i)
                {
                        for(j=0;j<size-1;++j)
                        {
                                if(j<i){
                                        matr[j]=Arr[j];
                                }

                                else{
                                        matr[j]=Arr[j+1];
                                }

                        }
                        det+=pow((double)-1, (i+j))*determ(matr, size-1)*Arr[i][size-1];
                }
                delete[] matr;
        }
        return det;
}
void liner(double ** matrix, float * xx, int n, int m)
{
    float  tmp;
    int k;
    int i,j;

for (i = 0; i<n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j<n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp*matrix[i][k];
        }
    }
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j<n; j++) xx[i] -= matrix[i][j] * xx[j];
    }
}
