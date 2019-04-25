#include<iostream>
#include<vector>
using namespace std;

void FASTWAY(int** a,int** t,int* e,int* x,int n,int **l){
    f[1][1] = e[1] + a[1][1];
    f[2][1] = e[2] + a[2][1];

    for(int j = 2; j <= n; j++){
        if(f[1][j-1] + a[1][j] < f[2][j-1] + t[2][j-1] + a[1][j]){
            f[1][j] = f[1][j-1] + a[1][j];
            l[1][j-1] = 1;
        }else{
            f[1][j] = f[2][j-1] + t[2][j-1] + a[1][j];
            l[1][j-1] = 2;
        };

        if(f[2][j-1] + a[2][j] < f[1][j-1] + t[1][j-1] + a[2][j]){
            f[2][j] = f[2][j-1] + a[2][j];
            l[2][j-1] = 2;
        }else{
            f[2][j] = f[1][j-1] + t[1][j-1] + a[2][j];
            l[2][j-1] = 1;
        };
    }
    f* = (f[1][n] + x[1] <= f[2][n] + x[2])? f[1][n] + x[1] :f[2][n] + x[2];
    l* = (f[1][n] + x[1] <= f[2][n] + x[2])? 1 : 2 ;

}

void PRINT_STATIONS(int **l,int n,int way){
    cout<<"line:" << way <<" station:"<<n <<endl;
    for(int i =n-1;i >= 1;i--){
        way = l[way][i];
        cout<<"line:"<< way <<" station:"<<i<<endl;
    }
}

void RECURSIVE_PRINT_STATIONS(int **l,int n,int way){
    if(n >= 1){
        RECURSIVE_PRINT_STATIONS(l,n-1,l[way][n-1]);
    };
    cout<<"line: "<<way<<" station:"<<l[way][n];
}
