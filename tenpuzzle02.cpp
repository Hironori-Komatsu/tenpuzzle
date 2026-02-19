#include <iostream>
#include <string>
#include <math.h>
using namespace std;


double calc(double a, double b, char op){
  if(op == '+') return a + b;
  if(op == '-') return a - b;
  if(op == '*') return a * b;
  if(op == '/') return a / b;

  return 0;
}

int main(){

  //入力
  int inputNumber;
  int n1,n2,n3,n4;

  cout << "4桁の数字を入力してください:" << endl;
  cin >> inputNumber;

  n1 = inputNumber/1000;
  n2 = (inputNumber/100) % 10;
  n3 = (inputNumber/10) % 10;
  n4 = inputNumber % 10;

  char op[] = {'+', '-' , '*', '/'};

  //四則演算の64通りの全探索
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
       char op1 = op[i];
       char op2 = op[j];
       char op3 = op[k];
        
      //()の位置の通り数は5通り
      double r[5];
      //(((n1 op1 n2) op2 n3) op3 n4)
      r[0] = calc(calc(calc(n1, n2, op1),n3,op2),n4,op3);
    
      //((n1 op1 (n2 op2 n3)) op3 n4)
      r[1] = calc(calc(n1,calc(n2,n3,op2),op1),n4,op3);

      //((n1 op1 n2) op2 (n3 op3 n4))
      r[2] = calc(calc(n1,n2,op1),calc(n3,n4,op3),op2);
      
      //(n1 op1 ((n2 op2 n3) op3 n4))
      r[3] = calc(n1,calc(calc(n2,n3,op2),n4,op3),op1);

      //(n1 op1 (n2 op2 (n3 op3 n4)))
      r[4] = calc(n1,calc(n2,calc(n3,n4,op3),op2),op1);

          
        //結果
        if(r[0] == fabs(10.0)){
          cout << "(((" << n1 << op[i] << n2 << ")" << op[j] << n3 << ")" << op[k] << n4 << ")" << '=' << r[0] << endl;
        }
        if(r[1] == fabs(10.0)){
          cout << "((" << n1 << op[i] << "(" << n2 << op[j] << n3 << "))" << op[k] << n4 << ")" << '=' << r[1] << endl;
        }
        if(r[2] == fabs(10.0)){
          cout << "((" << n1 << op[i]  << n2 << ")" << op[j] << "(" << n3 << op[k] << n4 << "))" << '=' << r[2] << endl;
        }
        if(r[3] == fabs(10.0)){
          cout << "(" << n1 << op[i]  << "((" << n2 << op[j]  << n3 << ")" << op[k] << n4 << "))" << '=' << r[3] << endl;
        }  
        if(r[4] == fabs(10.0)){
          cout << "(" << n1 << op[i]  << "(" << n2 << op[j] << "(" << n3 << op[k] << n4 << ")))" << '=' << r[4] << endl;
        }
        
      }  
    }
  }
}