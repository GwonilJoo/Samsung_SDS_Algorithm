// 1932 정수 삼각형
/*
강사님 방법
*/

#include<cstdio>

int n, tri[501][501], max_val[501][501], ans;

int getmax(int a, int b) {return a>b?a:b;}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      scanf("%d", &tri[i][j]);
    }
  }
  
  max_val[1][1] = tri[1][1];
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      max_val[i][j] =  getmax(max_val[i-1][j], max_val[i-1][j-1]) + tri[i][j];
    } 
  }
  
  for(int i=1;i<=n;i++){
    ans = getmax(max_val[n][i], ans);
  }
  printf("%d\n", ans);
}
