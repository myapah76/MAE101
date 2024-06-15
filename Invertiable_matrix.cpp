#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
double a[100][100];
double adj[100][100];
int row=3, colum=3;
int k=0,sign=1,count=0, adj_x=0,adj_y=0;
double fac=0,faction=0,det;
string s="0123456789.-",space=" ";
string temp,temp_ch="";
//=============================================================================================================================================================
string convert_input(string temp){
    string temp_input="";
    for(int i=0;i<temp.length();i++){
        if(s.find(temp[i]) || temp[i] == '0' || temp[i] =='.')temp_input+=temp[i];
        if(i!=temp.length()-1)
            if(temp[i]==' ' && (s.find(temp[i+1])==true || temp[i+1] == '0'))temp_input+=' ';
    }
return temp_input;
}
void input(){
        cout<<"   GIVE THE VALUE OF EVERYTHING WITH A SPACE BEWTEEW EACH VALUE\n";
        cout<<"AT THE END AND THE BEGINING OF EACH LINE INPUT DO NOT CONTAIN ANYTHING BUT A NUMBER\n";
        cout<<"=======================================================================================\n";
        cout <<"Give the size of matrix, row and colum : ";
        cin >> row >> colum;
        while(row != colum){
            cout << "The size of matrix is not allow to be Invertible \n";
            cout <<"Give the size of matrix, row and colum : "; cin >> row >> colum;
        }
    //ÉP NGƯỜI DÙNG PHẢI NHẬP MA TRẬN VUÔNG CẤP N
    
   getline(cin,temp);
    for(int i=0;i<row;i++){
        cout <<"Enter the value of row "<< i+1<<": ";
        getline(cin,temp); temp=temp +" "; //cout <<temp<<"a\n";
            for(int j=0;j<temp.length();j++){
                if(s.find(temp[j]) || temp[j] == '0' || temp[j] =='.'){ //ham find không tìm được kí tự 0 nên cho điều kiện vào luôn
                    temp_ch=temp_ch + temp[j];
                }
                if((int)temp[j] == 46) fac=1; //Kiếm tra người dùng có nhập số thực không

                if((int)temp[j]==32){
                    if(fac==0) a[i][k]=stoi(temp_ch);   
                        else a[i][k]=stod(temp_ch);
                    k++; //ĐẾM SỐ LƯỢNG SỐ ĐÃ ĐƯỢC NHẬP
                    temp_ch="";
                    fac=0;
                }
               
            }
            k=0; //Trả về 0 đến tiếp tục đếm cho dòng tiếp theo
    }

}

//=============================================================================================================================================================
void compute_cofactor(double a[100][100], double cofactor[100][100], int x, int y, int row_of_a){
    int dong=0,cot=0;
        for(int i=0;i<row_of_a;i++){
            for(int j=0;j<row_of_a;j++){
                if(i!=x && j!=y){ //Điều kiện là khác dòng và cột của aij
                    cofactor[dong][cot]=a[i][j];
                    cot++;
                
                    if(cot == row_of_a-1){ //det cua ma tran con luon nhỏ hơn 1 cột so với ma trận mẹ
                        cot=0;              //, ma trận con là cofactor, ma trận mẹ là ma trận đang tính det
                        dong++;
                    }
                }
            }
        }

    
}
//=============================================================================================================================================================
int compute_det(double a[100][100], int row_of_a){
    int det_temp=0, sign=1,temp_adj=0; 
   
        if(row_of_a == 1) // đệ quy quy về ma trận 1x1, lúc này det là a[0][0]
            return a[0][0];
            
    double cofactor[100][100];
     for(int i=0;i<row_of_a;i++){
         det_temp=0;
        for(int j=0;j<row_of_a;j++){
            compute_cofactor(a, cofactor, i, j, row_of_a); //tạo cofactor
            det_temp+=pow(-1,j+i+2)*a[i][j]*compute_det(cofactor, row_of_a-1); // tính det của confactor, và det của conf luôn có ít hơn 1 cột nên row-1 
           
            if(row_of_a == row){ //xét nếu tại lần đệ quy này đang ở mảng a thì gán det vào adj
                adj[adj_y][adj_x]=det*pow(-1,i+j+2);
                adj_y++;
                    if(adj_y == row){
                        adj_y=0;
                        adj_x++;
                }
            }
        }
    }
    //tạo adj đã chuyển vị
    det=det_temp;    

   
    return det_temp;
}
//=============================================================================================================================================================
void invertiable(){
        for(int i=0;i<row;i++){
            if(i == row/2)cout<<"Adj Maxtrix of A =         ";else cout <<"                           ";
            for(int j=0;j<colum;j++) {
               if(j == 0){
                    if(adj[i][j]<0){
                        cout<<"|"<<fixed<<setprecision(3)<<setw(4)<< adj[i][j];
                    }else{
                        cout<<"| "<<fixed<<setprecision(3)<<setw(4)<< adj[i][j];
                    }
                    
                }else if(j == colum-1){
                    cout<<fixed<<setprecision(3)<<setw(10)<<adj[i][j]<<"|";
                }else{
                    cout<<fixed<<setprecision(3)<<setw(10)<<adj[i][j];
                }
            }
        cout <<endl;
        }
        cout<<"==============================================\n";
        for(int i=0;i<row;i++){
            for(int j=0;j<colum;j++) {
                adj[i][j]/=det;
            }
        }
        for(int i=0;i<row;i++){
            if(i == row/2)cout<<"Invertiable Maxtrix of A = ";else cout <<"                           ";
            for(int j=0;j<colum;j++) {
                if(j == 0){
                    if(adj[i][j]<0){
                        cout<<"|"<<fixed<<setprecision(3)<<setw(4)<< adj[i][j];
                    }else{
                        cout<<"| "<<fixed<<setprecision(3)<<setw(4)<< adj[i][j];
                    }
                    
                }else if(j == colum-1){
                    cout<<fixed<<setprecision(3)<<setw(10)<<adj[i][j]<<"|";
                }else{
                    cout<<fixed<<setprecision(3)<<setw(10)<<adj[i][j];
                }
            }
        cout <<endl;
        }
}
//=============================================================================================================================================================
int main(){
    ifstream f1("matrix.inp.txt");
    ofstream f2("matrix.out.txt");
    input();    
    for(int i=0;i<row;i++){
            for(int j=0;j<colum;j++) 
                if(a[i][j] == -0)f2 << a[i][j]*a[i][j]<<" ";
                    else
                    f2 << a[i][j]*1<<" ";
        f2 <<endl;
        }
    if(row ==1){adj[0][0]=a[0][0];
        cout<<"=======================================================================================\n";
        cout << " The input matrix is invertible !\n";
        cout << " Here is the adj and invertible matrix !\n";
        cout<<"Invertiable Maxtrix of A = "<<1/adj[0][0] <<endl;
        return 0;
    }   
    if(compute_det(a, row) != 0) {
        cout<<"=======================================================================================\n";
        cout << " The input matrix is invertible !\n";
        cout << " Here is the invertible matrix !\n";
        invertiable();
    }else{
        cout<<"=======================================================================================\n";
        cout << " The input matrix is unnvertible !\n";
    }
    cout<<"The determinant is "<<det;
f1.close();
return 0;
}