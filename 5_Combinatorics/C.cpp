// 1010 다리 놓기

#include<cstdio>

int n,m,T;
int D[31][31];

int main(){
  for(int i=1;i<=30;i++){
    D[i][0] = D[i][i] = 1;
    for(int j=1;j<i;j++){
      D[i][j] = D[i-1][j-1] + D[i-1][j];
    }
  }
  
  scanf("%d", &T);
  for(int i=0;i<T;i++){
    scanf("%d%d", &n, &m);
    printf("%d\n", D[m][n]);
  }
}
