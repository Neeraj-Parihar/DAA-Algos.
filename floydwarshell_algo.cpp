//to implement floydwarshell algorithm
#include<iostream>
using namespace std;
# define nV 4
# define INF 999
void printmatrix(int temp[nV][nV]){
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            if(temp[i][j]==INF){
                cout<<"INF"<<" ";
            }
            else
                cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floydwarshell(int graph[][nV]){
    int temp[nV][nV],i,j,k;
    for(i=0;i<nV;i++)
    {
        for(j=0;j<nV;j++){
            temp[i][j]=graph[i][j];
        }
    }
    for(k=0;k<nV;k++){
        for(i=0;i<nV;i++){
            for(j=0;j<nV;j++){
                if(temp[i][k] + temp[k][j]<temp[i][j]){
                    temp[i][j]=temp[i][k] + temp[k][j];
                }
            }
        }
    }
    printmatrix(temp);
}
int main(){
    int graph[nV][nV]={{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    floydwarshell(graph);
}
