// 2725 보이는 점의 개수

#include<iostream>
using namespace std;

int arr[1001];

int gcd(int a, int b){
  while(b!=0){
    int r = a%b;
    a = b;
    b = r;
  }
  
  return a;
}

void func(int n){
  for(int i=2;i<=n;i++){
    if(arr[i] == 0){
      int cnt = 0;
      for(int j=1;j<i;j++){
        if(gcd(i,j) == 1)
          cnt++;
      }
      arr[i] = cnt*2 + arr[i-1];
    }
  }
}

void show(){
  cout << "arr: ";
  for(int i=1;i<=1000;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int C, N;
  cin >> C;
  
  arr[1] = 3;
  func(1000);
  //show();
  
  for(int i=0;i<C;i++){
    cin >> N;
    cout << arr[N] << "\n";
  }
}
