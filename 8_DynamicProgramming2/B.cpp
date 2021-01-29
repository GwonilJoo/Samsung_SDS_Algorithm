// 5582 공통 부분 문자열

/*
강사님 방법

LCS 문제! 단 여기서는 연속적이어야 함.
*/
#include<cstdio>
#include<cstring>

char str1[4010], str2[4010];
int len1, len2, ans;
int dp[4010][4010];

// p1, p2로 끝나는 문자열의 LCS
int calc(int p1, int p2){
  if(p1<0 || p2<0){
    return 0;
  }
  
  if(dp[p1][p2] != -1){
    return dp[p1][p2];
  }
  
  if(str1[p1] == str2[p2]){
    dp[p1][p2] = calc(p1-1, p2-1) + 1;
    return dp[p1][p2];
  }
  else {
    dp[p1][p2] = 0;
    return 0;
  }
}

int main(){
  memset(dp, 0xff, sizeof(dp));
  
  scanf("%s", str1);
  scanf("%s", str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
  
  for(int i=0;i<=len1-1;i++){
    for(int j=0;j<=len2-1;j++){
      int tmp = calc(i, j);
      if(ans < tmp) ans = tmp;
    }
  }
  
  printf("%d\n", ans);
}
