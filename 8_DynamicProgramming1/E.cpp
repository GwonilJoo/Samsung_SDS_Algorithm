// 1915 가장 큰 정사각형

/*
강사님 방법
진행방향을 행마다 하는 것이 좋다
----------->
---------->
----------->
.
.
.

[i-1][j], [i][j-1], [i-1][j-1] 중 작은값 + 1가  [i][j]가 가질수 있는 정각삭형 한 변의
길이가 된다.  (단 [i][j] != 0)

*/

#include<cstdio>

int n, m, a[1001][1001], ans;
int dp[1001][1001]; // [i][j]를 오른쪽 아래로 했을 때 가장 큰 정사각형
char buf[1001];

int getmax(int a, int b){return a>b?a:b;}
int getmin(int a, int b){return a<b?a:b;}

int main(){
  scanf("%d%d", &n, &m);
  for(int i=1;i<=n;i++){
    scanf("%s", buf);
    for(int j=1;j<=m;j++){
      a[i][j] = buf[j-1] - '0';
    }
  }
  
  // 구하기
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j] == 0){  // 우측 하단에 있는 점이 0이니까 당연히 정사각형을 만들 수 없음
        dp[i][j] = 0;
        continue;
      }
      // 조사를 해야 하는데 이웃한 곳들: 왼쪽, 위쪽, 대각선왼쪽 위를 조사하자!
      // 가장 작은 것
      int min = getmin(getmin(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
      dp[i][j] = min+1;
      ans = getmax(ans, dp[i][j]);
    }
  }
  
  printf("dp: \n");
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  
  // 출력
  printf("%d\n", ans*ans);
}
