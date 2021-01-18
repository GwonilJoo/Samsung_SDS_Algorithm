// 1922 네트워크 연결

/*
강사님 방법
MST(최소 스패닝 트리) 문제!
경우의 수 -> 가장 적은 비용 (prim, 크루스칼 등의 알고리즘 사용)

여기서는 크루스칼을 적용해보았음
비용 적은 것부터 연결 (union) 
연결할것인가? (find) -> 연결이 되어있으면 굳이 불필요한 연결을 하지 않기 위해 사용
*/

#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1010

struct Node{
  int a, b, c;
};

int N, M, ANSWER = 0;
Node *edge;
int *pr;

void init(){
  pr = new int[N+1];
  for(int i=1;i<=N;i++) pr[i] = i;
}

int find(int a){
  if(a==pr[a]) return a;
  
  pr[a] = find(pr[a]);
  return pr[a];
}

void unionf(int a, int b){
  a = find(a);
  b = find(b);
  pr[a] = b;
}

bool compare(Node A, Node B){
  return A.c < B.c;
}


int main(){
  scanf("%d", &N);
  scanf("%d", &M);
  edge = new Node[M];
  
  for(int i=0;i<M;i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    // 어디에 어떻게 넣을까?? -> struct 배열에 넣기!
    edge[i].a = a;
    edge[i].b = b;
    edge[i].c = c;
  }
  
  // 간선의 크기 순으로 정렬
  sort(edge, edge+M, compare);
  
  // 정렬 잘 되었는지 출력해보기(디버깅)
  /*
  for(int i=0;i<M;i++)
    printf("%d ", edge[i].c);
  printf("\n");
  */
  
  // 크루스칼 알고리즘 사용 = 간선의 비용이 작은 것부터 트리 구성
  // union find 이용해서 트리 구성
  init();
  int cnt = 0; // 연결 횟수 = MST 간선 개수 = 노드 개수-1개가 되어야 함
  for(int i=0;i<M;i++){
    // 간선 정보를 읽어옴
    int a, b, c;
    a = edge[i].a; // 한쪽 끝 노드
    b = edge[i].b; // 다른쪽 끝 노드
    c = edge[i].c; // 간선의 비용
    
    // 둘이 연결되어 있는지 = 같은 그룹인지 확인
    if(find(a) != find(b)){
      // 서로 다른 그룹이면 연결해줌, 비용도 추가
      unionf(a,b);
      
      // 비용을 계산
      ANSWER += c;
      cnt++; // 연결 횟수 증가
    }
  }
  
  // cnt != N-1  -> MST 구성이 안됨을 의미! 이문제에서는 모두 연결된다는 가정이므로 주석처리
  printf("%d\n", ANSWER);
  
  delete [] edge;
  delete [] pr;
}
