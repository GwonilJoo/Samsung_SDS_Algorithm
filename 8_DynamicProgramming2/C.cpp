// 9252 LCS 2

/*
강사님 방법

LCS: 최장 공통 부분 문자열. 연속적이지는 않지만 순서는 맞는 subsequence 중 가장 긴 문자열을 의미
*/

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Info{
  int p1, p2;
};

char str1[1010], str2[1010], ans[1010];
int len1, len2, dp[1010][1010];
Info tracking[1010][1010];

int getmax(int a, int b) {return a>b?a:b;}

// p1, p2까지의 것들 중에서 LCS(꼭 p1,p2를 포함할 필요는 없음)
int calc(int p1, int p2){
  if(p1<0 || p2<0) return 0;
  
  if(dp[p1][p2] != -1){
    return dp[p1][p2];
  }
  
  // 문자열 같으면
  if(str1[p1] == str2[p2]){
    dp[p1][p2] = calc(p1-1, p2-1) + 1;
    tracking[p1][p2] = {p1-1, p2-1};
    return dp[p1][p2];
  }
  // 다르면
  int tmp1, tmp2;
  tmp1 = calc(p1-1, p2); // str1의 끝 문자를 빼고 고려했을 때
  tmp2 = calc(p1, p2-1); // str2의 끝 문자를 빼고 고려했을 때
  
  if(tmp1 > tmp2){
    dp[p1][p2] = tmp1;
    tracking[p1][p2] = {p1-1, p2};
  }
  else{
    dp[p1][p2] = tmp2;
    tracking[p1][p2] = {p1, p2-1};
  }
  
  return dp[p1][p2];
}

int main(){
  memset(dp, 0xff, sizeof(dp));
  scanf("%s", str1);
  scanf("%s", str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
  
  printf("%d\n", calc(len1-1, len2-1));
  
  // 문자열 출력 - 내 방식
  /*
  int p1 = len1-1, p2 = len2-1, len_ans = 0;
  while(true){
    if(p1<0 || p2<0) break;
    Info next = tracking[p1][p2];
    if(p1-1 == next.p1 && p2-1 == next.p2) {
      ans[len_ans] = str1[p1];
      len_ans++;
    }
    p1 = next.p1;
    p2 = next.p2;
  }
  for(int i=len_ans-1;i>=0;i--)
    printf("%c", ans[i]);
  printf("\n");
  */
  
  // 문자열 출력 - 강사님 방식
  // 여기서는 tracking을 사용해서 문자열을 찾음
  // 하지만, tracking을 쓰지 않고 dp로만으로도 찾을 수 있음
  int p1 = len1-1, p2 = len2-1, len_ans = 0;
  vector<char> stk;
  while(0 <= p1 && 0 <= p2){
    if(str1[p1]  == str2[p2]) stk.push_back(str1[p1]);
    Info next = tracking[p1][p2];
    p1 = next.p1;
    p2 = next.p2;
  }
  while(!stk.empty()){
    printf("%c", stk.back());
    stk.pop_back();
  }
  printf("\n");
  

  
  // debuging
  /*
  printf("\n");
  for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
      printf("%2d", dp[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");
  for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
      printf("(%2d, %2d) ", tracking[i][j].p1, tracking[i][j].p2);
    }
    printf("\n");
  }
  */
}
