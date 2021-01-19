// 11404 플로이드

/*
// 강사님 풀이
플로이드 문제
dp를 사용해서 문제 해결
i-->k 최단 경로 = min(i--->k, i-->j + j-->k)

N이 크면 타임아웃이 남. O(N^3)-> n이 100 대이면 플로이드로 풀 수 있다

시간복잡도 계산할때 1억 -> 1초로 생각함. 1억대 맞추면 1초 내에 풀 수 있다.
*/
#include<cstdio>
#include<vector>
using namespace std;

#define INF 20000000

int n, m, dist[110][110]; // [i][j]: i ----> j로 가는 비용

void floyd(){
  for(int j=1;j<=n;j++){ // 중간점
    for(int i=1;i<=n;i++){ // 시작점
      if(dist[i][j] == INF) continue; // INF끼리 더해서 오버플로우로 오류 발생할수 있음.
      for(int k=1;k<=n;k++){  // 끝점
        if(dist[j][k] == INF) continue; // INF끼리 더해서 오버플로우로 오류 발생할수 있음.
        if(dist[i][j] + dist[j][k] < dist[i][k]){
          dist[i][k] = dist[i][j] + dist[j][k];
        }
      }
    }
  }
}

int main(){
  scanf("%d", &n);
  scanf("%d", &m);
  
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      if(i == j) dist[i][j] = 0;
      else dist[i][j] = INF;
    }
  
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c); // a-->b c의 비용
    
    // 시작도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다
    if(c < dist[a][b]){ //최솟값만 유지하기 위해서
      dist [a][b] = c; 
    }
  }
      
  floyd();
  
  // 출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(dist[i][j] == INF) printf("%d ", 0);
      else printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
}
