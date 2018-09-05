#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;


bool IsOperand(char ch){
if ((ch >= '0' && ch <= '9') ) {
return true;
}
return false;
}

bool IsOperator(char C)
{
if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^') {
return true;
}
return false;
}
bool IsLeftParenthesis(char ch)
{
if (ch == '(') {
return true;
}
return false;
}

bool IsRightParenthesis(char ch)
{
if (ch == ')') {
return true;
}
return false;
}

bool Flag(char ch)
{
if (!IsOperand(ch) || !IsOperator(ch) || !IsLeftParenthesis(ch) || !IsRightParenthesis(ch)) {
return false;
}
return true;
}

int IsRightAssociative(char op)
{
if (op == '^') {
return true;
}
return false;
}

int GetOperatorWeight(char op)
{
int weight = -1;
switch (op) {
case '+':
case '-':
weight = 1;
break;
case '*':
case '/':
weight = 2;
break;
case '^':
weight = 3;
break;
}
return weight;
}

bool HasHigherPrecedence(char op1, char op2)
{
int op1Weight = GetOperatorWeight(op1);
int op2Weight = GetOperatorWeight(op2);


if (op1Weight == op2Weight) {
    if (IsRightAssociative(op1)) {
        return false;
    }
    else {
        return true;
    }
}
return op1Weight > op2Weight ? true : false;
}

string InfixToPostfix(string expression)
{
stack<char> S;
string postfix = "";
for (auto& elem : expression) {
if (Flag(elem)) {
continue;
}

else if (IsOperator(elem)) {
while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), elem)) {
postfix += S.top();
S.pop();
}
S.push(elem);
}
else if (IsOperand(elem)) {
postfix += elem;
}
else if (elem == '(') {
S.push(elem);
}
else if (elem == ')') {
while (!S.empty() && S.top() != '(') {
postfix += S.top();
S.pop();
}
S.pop();
}
}

while (!S.empty()) {
    postfix += S.top();
    S.pop();
}

return postfix;
}

// void CalculateResult( char oper, stack<int>& tmpStack) {
//     if (tmpStack.size() < 2) {
//         return;
//     }
//
//     int secondVal = tmpStack.top();
//     tmpStack.pop();
//     int firstVal = tmpStack.top();
//     tmpStack.pop();
//
//     int result = 0;
//     switch (oper) {
//     case '+':
//         result = firstVal + secondVal;
//         break;
//     case '-':
//         result = firstVal - secondVal;
//         break;
//     case '*':
//         result = firstVal * secondVal;
//         break;
//     case '/':
//         result = firstVal / secondVal;
//         break;
//     case '^':
//         result = pow(firstVal,secondVal);
//     default:
//         break;
//     }
//
//     tmpStack.push(result);
// }


// int getResultUseSuffix(string& s) {
//     if (s.length() <= 0) {
//         return 0;
//     }
//
//     stack<int> tmpStack;
//     for (int i = 0; i < s.length(); i++) {
//         if (IsOperand(s.at(i))) {
//             tmpStack.push(s.at(i) - '0');
//         } else {
//             CalculateResult(s.at(i), tmpStack);
//         }
//     }
//     return tmpStack.top();
// }

int main()
{
  int t = 0;
  cin>>t;


  for(int num = 0;num < t;num++){

  string infix;
  cin>>infix;
  string postfix = InfixToPostfix(infix);
  cout<<postfix;
  // int result = getResultUseSuffix(postfix);
  // cout<<result<<endl;

  }


}
