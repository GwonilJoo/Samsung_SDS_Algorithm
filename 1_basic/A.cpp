// 3425 고스택

#include<iostream>
#include<string>
using namespace std;

int stack[10001];
string command[20001];
int stack_size = 0, command_size = 0;

void func(int n);

void show_command(){
  cout << "\n";
  for(int i=0;i<command_size;i++)
    cout << command[i] << endl;
}

void show_stack(){
  cout << "\n";
  for(int i=0;i<stack_size;i++){
    cout << stack[i] << endl;
  }
}

int main(){
  int N;
  while(true){
    while(true){
      string s;
      getline(cin, s);
    
      if(s == "END") break;
      else if(s == "QUIT") return 0;
      else{
        command[command_size] = s;
        command_size++;
      }
    }
    
    //show_command();
    
    int N, v;
    cin >> N;
    for(int i=0;i<N;i++){
      cin >> v;
      func(v);
    }
    
    cout << "\n";
    
  }
}

void func(int n){
  for(int i=0;i<command_size;i++){
    cout << "command: " << command[i] << endl;
    if(command[i].){
      stack[stack_size] = 2;
      stack_size++; i++;
      show_stack();
    }
  }
}

