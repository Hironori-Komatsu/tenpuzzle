#include <iostream>
#include <string>
using namespace std;


//計算関数
double calc(double a,double b,char op) {
    if(op == '+'){
      return a + b;
    }
    else if(op == '-'){
      return a - b;
    }
    else if(op == '*'){
      return a * b;
    }
    else if(op == '/'){
      return a / b;
    }
    return 0;
}


int main(){
  
  int inputNumber;
  int n1, n2, n3, n4;
  char op[] = {'+','-','*','/'};

  //入力
  cout << "4桁の数字を入力してください" << endl;
  cin >> inputNumber;

  //数字の分割
  n1 = inputNumber/1000;
  n2 = (inputNumber/100) % 10;
  n3 = (inputNumber/10) % 10;
  n4 = inputNumber % 10;


  
 //四則演算
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
       double r1 = calc(n1, n2, op[i]);
       double r2 = calc(r1, n3, op[j]);
       double result = calc(r2, n4, op[k]);
        
        //結果
        if(result == 10){
          cout << n1 << op[i] << n2 << op[j] << n3 << op[k] << n4 << "=" << result <<endl;
        }
      }
    }
  }

}