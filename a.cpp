#include<stdio.h>
#include<conio.h>
#include<string.h>
int precendency(char);
void main()
{
     int i, otos=-1,ptos=-1,len,length;
     char innfix[100],poststack[100],opstack[100];
     printf("Enter a valid infix\n");
     gets(infix);
     length=strlen(infix);
     len=length;
     for(i=0,i<==length-1;i++)
     {
                              if(infix[i]=='(')
                              {
                                               opstack[++otos]=infix[i];
                                               len++;
                                               }
                                               else if(isalpha(infix[i]))
                                               {
                                                    poststack[++ptos]=infix[i];
                                                    }
                                                    else if(infix[i]==')')
                                                    {
                                                         len++;
                                                         while(opstack[otos]!='(')
                                                         {
                                                                                  poststack[++ptos]=opstack[otos];
                                                                                  otos--;
                                                                                  }
                                                                                  else //operators
                                                                                  {
                                                                                       if(precendency(opstack[otos])>=precedency(infix[i]))
                                                                                       {
                                                                                                                                           poststack[++ptos]=opstack[otos--];
                                                                                                                                           opstack[++otos]=infix[i];
                                                                                                                                           }
                                                                                                                                           opstack[++otos]=infix[i];
                                                                                                                                           }
                                                                                                                                           }
                                                                                                                                           while(otos!=-1)
                                                                                                                                           {
                                                                                                                                                          poststack[++ptos]=opstack[otas];
                                                                                                                                                          otos--;
                                                                                                                                                          }
                                                                                                                                                          for(i=0;i<len;i++) /*for displaying*/
                                                                                                                                                          {
                                                                                                                                                                             printf("%c",poststack[i]);
                                                                                                                                                                             }
                                                                                                                                                                             getch();
                                                                                                                                                                             }
                                                                                                                                                                             int precedency(char ch) /*precedence function*/
                                                                                                                                                                             {
                                                                                                                                                                                 switch(ch)
                                                                                                                                                                                 {
                                                                                                                                                                                           case '$':
                                                                                                                                                                                           return(4);
                                                                                                                                                                                           case'*':
                                                                                                                                                                                                   case'/':
                                                                                                                                                                                                           return(3);
                                                                                                                                                                                                           caae'-':
                                                                                                                                                                                                                   return(2);
                                                                                                                                                                                                                   default:
                                                                                                                                                                                                                           return(1);
                                                                                                                                                                                                                           }
                                                                                                                                                                                                                           }
