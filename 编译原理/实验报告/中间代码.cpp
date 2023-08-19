#include <string.h>
#include <stdio.h>
#include <conio.h>
char w;
int j=1;
struct TOKEN	// ������ 
{
  char t;
  int i;
};
struct TOKEN word, sem[10];

int i_sem;

struct QT	// ��Ԫʽ 
{
  char w;				// op 
  struct TOKEN word1;	// arg1
  struct TOKEN word2;	// arg2
  struct TOKEN temp;	// result
};

char exp[50];	// ������ʽ 
int i=0;

struct QT qt[30];
int q=0;	// ��Ԫʽ�����±� 

/* *�ķ����� 
	D -> E = E
	E -> T + T | T - T | T
	T -> F * F | F / F | F
	F -> ( E ) | [a~z] | [0~9]
*/ 
int D();
int E();
int T();
int F();

void next();	// ɨ���ַ� 

void newt(); 	// ��ʱ���� 

void quat(char);	// �γ���Ԫʽ 

int main()
{
	printf("please input your expression:    ");
	scanf("    %s",exp);
	next();
	D();
	if (w=='\0'){
	    printf("\n");
	    for (i=0;i<q;i++){
	      	printf("  (%d) ",i+1);
			if(qt[i].w!='='){
			    printf(" ( %c",qt[i].w);
			    if (qt[i].word1.t!='t')
					printf(" , %c",qt[i].word1.t);
			    else
					printf(" , %c%d",qt[i].word1.t,qt[i].word1.i);
			    if (qt[i].word2.t!='t')
					printf(" , %c",qt[i].word2.t);
			    else
					printf(" , %c%d",qt[i].word2.t,qt[i].word2.i);
			    printf(" , %c%d )\n",qt[i].temp.t,qt[i].temp.i);
			}else{
			 printf(" ( %c",qt[i].w);
			 printf(" , %c%d ",qt[i-1].temp.t,qt[i-1].temp.i);
			printf(" , _");
			printf(" , %c)",qt[i].word1.t);
			}
		}
		getch();
	}else printf("err");
	printf("\nHello World!\n");
  	return 0;
}
int D()
{
  char w0;
  E();
  while ( w=='=')
  {
    w0=w;
    next();
    E();
    quat(w0);
  }
  return 1;
}
int E()
{
  char w1;
  T();
  while ( w=='+' || w=='-')
  {
    w1=w;
    next();
    T();
    quat(w1);
  }
  return 1;
}
int T()
{
  char w2;
  F();
  while ( w=='*' || w=='/')
  {
    w2=w;
    next();
    F();
    quat(w2);
  }
  return 1;
}
int F()
{
  if ( w=='(')
  {
    next();
    E();
    if ( w!=')')
    {
      printf("err");
      return 0;
    }
  }
  else if ((w>='a' && w<='z')||(w>='0' && w<='9'))
	{
	  word.t=w; word.i=0 ;
	  sem[++i_sem]=word;
	}
	else
	{
	  printf("err");
	  return 0;
	}
  next();
  return 1;
}
 
void next()
{
  w=exp[i];
  i++;
}

void newt()
{
  word.t='t';
  word.i=j++;
}

void quat(char ww)
{
  newt();
  qt[q].w=ww;
  qt[q].word1=sem[i_sem-1];
  qt[q].word2=sem[i_sem];
  qt[q].temp=word;
  i_sem--;
  i_sem--;
  sem[++i_sem]=word;
  q++;
}

