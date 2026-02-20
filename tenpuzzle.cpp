#include <iostream>
#include <string>
#include <vector>
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
  string inputNumber;
  vector<int> digit;
  char op[] = {'+', '-' , '*', '/'};

  cout << "4桁の数字を入力してください:" << endl;
  cin >> inputNumber;


  //数字の分割
  for(int d = 0; d < inputNumber.size(); d++){
    if(inputNumber.size() != 4){
      cout << "「4桁」の数字を入力してください" << endl;
      return 1;
    }

    if(isdigit(inputNumber[d])){
      digit.push_back(inputNumber[d] - '0');
    }
    else{
      cout << "文字が入力されています" << endl;
      return 1;
    }   
  }


  //四則演算の組み合わせ(64通り)
  for(int i = 0; i < sizeof(op); i++){
    for(int j = 0; j < sizeof(op); j++){
      for(int k = 0; k < sizeof(op); k++){
       char op1 = op[i];
       char op2 = op[j];
       char op3 = op[k];
        

        //()の位置の通り数(5通り)
        double position[5];
        //(((n1 op1 n2) op2 n3) op3 n4)
        position[0] = calc(calc(calc(digit[0], digit[1], op1),digit[2],op2),digit[3],op3);
      
        //((n1 op1 (n2 op2 n3)) op3 n4)
        position[1] = calc(calc(digit[0],calc(digit[1],digit[2],op2),op1),digit[3],op3);

        //((n1 op1 n2) op2 (n3 op3 n4))
        position[2] = calc(calc(digit[0],digit[1],op1),calc(digit[2],digit[3],op3),op2);
        
        //(n1 op1 ((n2 op2 n3) op3 n4))
        position[3] = calc(digit[0],calc(calc(digit[1],digit[2],op2),digit[3],op3),op1);

        //(n1 op1 (n2 op2 (n3 op3 n4)))
        position[4] = calc(digit[0],calc(digit[1],calc(digit[2],digit[3],op3),op2),op1);

            
        //結果
        if(position[0] == 10.0){
          cout << "(((" << digit[0] << op1 << digit[1] << ")" << op2 << digit[2] << ")" << op3 << digit[3] << ")" << '=' << position[0] << endl;
        }
        if(position[1] == 10.0){
          cout << "((" << digit[0] << op1 << "(" << digit[1] << op2 << digit[2] << "))" << op3 << digit[3] << ")" << '=' << position[1] << endl;
        }
        if(position[2] == 10.0){
          cout << "((" << digit[0] << op1  << digit[1] << ")" << op2 << "(" << digit[2] << op3 << digit[3] << "))" << '=' << position[2] << endl;
        }
        if(position[3] == 10.0){
          cout << "(" << digit[0] << op1  << "((" << digit[1] << op2  << digit[2] << ")" << op3 << digit[3] << "))" << '=' << position[3] << endl;
        }  
        if(position[4] == 10.0){
          cout << "(" << digit[0] << op1  << "(" << digit[1] << op2 << "(" << digit[2] << op3 << digit[3] << ")))" << '=' << position[4] << endl;
        }
        
      }        
    }  
  }
  return 0;
}