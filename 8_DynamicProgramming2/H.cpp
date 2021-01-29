// 2098 외판원 순회

/*
강사님 방법

[여행에 사용한 도시][마지막 도시]
[여행에 사용한 도시]만큼 도시 방문을 했고, [마지막 도시]는 마지막 방문 지점을 의미 ==> 최소비용

도시들을 비트로 표현

bottom up 방식으로 풀거임.

재귀로 푸는 방식 (top down)은 블로그 참조 
*/

#include<cstdio>

#define INF 20000000

int N;
int w[16][16]; // i -> j까지 이동하는 거리
int dp[(1<<16)][16]; // [i][j] 도시를 i처럼 거쳐왔고, 현재에 j있을때 이동한 거리

int bit_set(int orgbit, int pos){ // pos번째에 비트를 셋팅함: 가장 낮은 자리수가 0
  return orgbit | (1<<pos);
}

int bit_unset(int orgbit, int pos){
  return orgbit & (~(1<<pos));
}

int bit_check(int orgbit, int pos){
  if ((orgbit & (1<<pos)) == 0) return false;
  else return true;
}

int getmin(int a, int b) {return a<b?a:b;}

int main(){
  scanf("%d", &N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d", &w[i][j]);
    }
  }

  // dp 배열 초기화
  for(int i=0; i<(1<<16); i++){
    for(int j=0;j<16;j++){
      dp[i][j] = INF;
    }
  }
  
  // 시작점 셋팅: 0번째 도시에서 시작함...[0번째 도시를 거쳐왔고][현재 0번째에 있으니까]
  dp[1][0] = 0;
  
  for(int i=0;i<(1<<N);i++){
    for(int j=0;j<N;j++){
      // 전개 dp[i][j]
      for(int k=0;k<16;k++){
        // k로 갈 수 있는지
        if (bit_check(i,k) == true) continue;
        if(w[j][k] == 0) continue;
    
        int next = bit_set(i,k);
        dp[next][k] = getmin(dp[next][k], dp[i][j] + w[j][k]);
      }
    }
  }
  
  // 시작으로 가는 처리를 하면서 답을 구함
  int ans = INF;
  int last_state = (1<<N)-1; // 모든 도시를 방문한 상태
  // 모든 도시를 순회했고, 시작으로 돌아가야함
  // 비용을 구하면서 정답을 찾는다
  for(int i=0;i<N;i++){
    if(w[i][0] == 0) continue;// 길이 없음
    int tmp = dp[last_state][i] + w[i][0];
    ans = getmin(ans, tmp);
  }
  
  printf("%d\n", ans);
}
