#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int pp,qq,rr,ss,tt;  //各个逻辑变量的值
stack<int> s;

bool isvariables(char ch);  //判断ch是否为变量p q r s t，若是则把其当前值入栈
void operators(char op);   //根据操作符op对栈执行操作

int main()
  {
      char WFF[110];
      while(cin>>WFF && WFF[0]!='0')
      {
          int len=strlen(WFF);  //逻辑表达式的长度

          bool flag=true;  //标记逻辑表达式是否为永真式
          for(pp=0;pp<=1;pp++)  //枚举逻辑变量的值
          {
              for(qq=0;qq<=1;qq++)
             {
                  for(rr=0;rr<=1;rr++)
                  {
                      for(ss=0;ss<=1;ss++)
                      {
                          for(tt=0;tt<=1;tt++)
                          {
                             for(int pw=len-1;pw>=0;pw--)
                              {
                                  if(!isvariables(WFF[pw]))
                                      operators(WFF[pw]);
                              }
                              int ans=s.top();   //最后栈剩一个值，即为逻辑表达式的值
                              s.pop();  //清空栈
                              if(!ans)  //只要表达式有一个值为假，它就不是永真式
                              {
                                  flag=false;
                                  break;
                              }
                          }
                          if(!flag)
                              break;
                      }
                      if(!flag)
                          break;
                  }
                  if(!flag)
                      break;
              }
              if(!flag)
                  break;
          }
          if(flag)
              cout<<"tautology"<<endl;
          else
              cout<<"not"<<endl;
      }
      return 0;
  }

  bool isvariables(char ch)
  {
      switch(ch)
      {
          case 'p':s.push(pp);return true;
          case 'q':s.push(qq);return true;
          case 'r':s.push(rr);return true;
          case 's':s.push(ss);return true;
          case 't':s.push(tt);return true;
      }
      return false;
  }

  void operators(char op)
  {
      switch(op)
      {
          case 'K':
              {
                  int x=s.top();


                  s.pop();
                 int y=s.top();
                  s.pop();
                  s.push(x&&y);
                  break;
              }
          case 'A':
              {
                  int x=s.top();
                  s.pop();
                  int y=s.top();
                  s.pop();
                  s.push(x||y);
                 break;
             }
         case 'C':
             {
                 int x=s.top();
                 s.pop();
                 int y=s.top();
                 s.pop();
                 s.push((!x)||y);
                 break;
             }
         case 'E':
             {
                 int x=s.top();
                 s.pop();
                 int y=s.top();
                 s.pop();
                 s.push(x==y);
                break;
             }
         case 'N':
            {
                 int x=s.top();
                s.pop();
                 s.push(!x);
                 break;
             }
     }
     return;
 }
