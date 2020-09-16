#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n,a,b,count = 0;
int m = 0;
vector<vector<int> > graf; vector<int> ver; vector<int> family; bool ok = false; vector<int> ans; vector<bool> popa;

int bfs(int beg, int end){ // ������� ������� ��������� ������� � ������ ������,������� �� ����������,� �������� �� ��� ��� �����������
    count++;
    if(beg == end){
        ok = true;
        return 1;
    }else{
        for(int i = graf[beg].size() - 1;i >= 0;i--){
            if(!popa[graf[beg][i]]){
                ver.push_back(graf[beg][i]);
                family.push_back(beg);
                popa[graf[beg][i]] = true;
            }
        }
    }
    return 0;
}

int main() {
       setlocale(LC_ALL, "rus");
    fstream text;
    ofstream file;
    file.open("output.txt");
    text.open("text.txt");
    string buk;
    getline(text,buk);
    int n = buk[0] - '0';
  //  cout << "n = "<< n<< endl;
    int mas[n][n];
    int y=0;
    int v = 0;
    int r = 0;
    int a,b;
    while (!text.eof())
    {
        getline(text,buk);
        a = buk[0]- '0';
        b= buk[2]- '0';
         for (int i=0;i<buk.size()-1; i++)
        {
            if(buk[i]!=' ')
            {
                if(buk[i+1]!=' ')
                {
                    mas[v][r] = (buk[i] - '0')*10+(buk[i+1] - '0');
                r++;
                i++;
                }
               else
                    {
                        mas[v][r] = buk[i] - '0';
                r++;

                    }

            }


        }

        v++;
        r=0;
    }
   // cout<<"a="<<a<<endl;
  //  cout<<"b="<<b<<endl;
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
       // cout<<mas[i][j]<<" ";
        if(mas[i][j]==1)
        {
            m++;
        }
    }
    //cout<<endl;
}
//cout<<"m="<<m<<endl;
int st1[m];
    int st2[m];
    int o =0;
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        if(mas[i][j]==1)
        {
            st1[o] = i+1;
            st2 [o] = j+1;
            o++;
        }
    }
  //  cout<<endl;
}
o=0;
for (int i=0;i<m;i++)
{
   // cout<<st1[i]<<" "<<st2[i]<<endl;
}
    ios::sync_with_stdio(false);
    //cin >> a >> b;
    for(int i = 0 ; i <= n; i++){ // ������� ����� ���������
            graf.push_back(ans);
            popa.push_back(false);
    }
    ver.push_back(a);family.push_back(a);
    for(int i = 0; i < m; i++){ //� ������ ������� ��������� �� �������,� ������� ��� ��������
        int x,y;
        x = st1[i];
        y = st2[i];
        if(x != y){ // �������� �� �����
            graf[x].push_back(y);
            graf[y].push_back(x);
        }
    }
    if(!graf[a].empty()){ //���� ������� ������ �� ������������
        while(!ok && count < ver.size() ){ //����,���� �� �� ������ �������� �������,��� ���� �� �� ������ ��� ������� � ������� "�����"
            if(bfs(ver[count],b)){ //���� �� ����� �����,�� ������ ��������������� ����
                count--;// ��� ���� ������ � ��������� �������,� ��� count - 1 �������
                int p = 1; //����� ����������,������� �����,��� ���������� ������� ��������� "����" ������ �������
                ans.push_back(b);//������ ������
                while(ver[count] != a){ // ���� �� ����� �� ��������� �������
                    while(ver[p] != family[count]){//��������� ����� ���������� �� ������� ������ �����,� ���� ������ ��������� ������� ����
                        p++;
                    }
                    ans.push_back(ver[p]);//��������� � ����� �������,�� ������� �� ������ � ���������� (����)
                    count = p;// ������ ���� ���� ���� � ��� �����,���� �� ������ �� ��������� �������
                    p = 1;
                }
            }
        }
        if(ans.size() > 0){ // ���� ������ ������ �� ����(����� ������ ���� ������� �� ����)
            //cout << ans.size()-1 << endl;
            file << ans.size()-1 << endl;
            for(int i = ans.size()-1; i >= 0; i--){
               // cout << ans[i] << " "; // ������� ����� ������ �� ����,��� ������� � �������
            }
        }else{ // ����� -1
            cout << "-1\n";
        }
    }else{//���� ��������� ������� �����������,�� ����� ������� -1
        cout << "-1\n";
    }
    cout<< "�������� � ����� output"<<endl;
    return 0;
}
