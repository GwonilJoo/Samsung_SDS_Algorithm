// 11660 구간 합 구하기5

/*
강사님 방법
*/

#include<cstdio>

int n, m, a[1025][1025];
int subsum[1025][1025]; // [i][j] : 1행 1열부터 i행 j열까지의 합

int main(){
  scanf("%d%d", &n, &m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%d", &a[i][j]);
    }
  }
  for(int i=1;i<=n;i++){
    int linesum = 0;  // i행에 있는 숫자들의 누적합
    for(int j=1;j<=n;j++){
      linesum += a[i][j];
      subsum[i][j] = subsum[i-1][j] + linesum;
      
      //printf("%d ", subsum[i][j]);
    }
    //printf("\n");
  }
  for(int i=0;i<m;i++){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    
    printf("%d\n", subsum[x2][y2] - subsum[x2][y1-1] - subsum[x1-1][y2] + subsum[x1-1][y1-1]);
  }
}
