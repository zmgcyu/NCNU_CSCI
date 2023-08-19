#include "wordscan.h"

void lrparser();    // 判断程序是否缺失开头结尾
void yucu();        // 判断语句串是否合法
void statement();   // 判断语句是否合法
void expression();  // 判断表达式是否合法
void term();        // 判断项是否合法
void factor();      // 判断因子是否合法
int kk = 0; // kk与判断是否end有关

void lrparser()
{
    if (syn == 1)
    { // begin
        scaner();
        yucu();
        if (syn == 6)
        { // end
            scaner();
            if (syn == 0 && kk == 0)
                printf("success \n");
        }
        else
        {
            if (kk != 1)
                printf("error,lose 'end' ! \n");
            kk = 1;
        }
    }
    else
    {
        printf("error,lose 'begin' ! \n");
        kk = 1;
    }
    return;
}

void yucu()
{
    statement();
    while (syn == 26)
    {
        scaner();
        statement();
    }
    return;
}

void statement()
{
    if (syn == 10)
    { //为标识符
        scaner();
        if (syn == 18)
        { //为 :=
            scaner();
            expression();
        }
        else
        {
            printf("error!");
            kk = 1;
        }
    }
    else
    {
        printf("error!");
        kk = 1;
    }
    return;
}

void expression()
{
    term();
    while (syn == 13 || syn == 14)
    {
        scaner();
        term();
    }
    return;
}

void term()
{
    factor();
    while (syn == 15 || syn == 16)
    {
        scaner();
        factor();
    }
    return;
}

void factor()
{
    if (syn == 10 || syn == 11)
        //为标识符或整常数时，读下一个单词符号
        scaner(); 
    else if (syn == 27)
    {
        scaner();
        expression();
        if (syn == 28)
            scaner();
        else
        {
            printf(" ')' 错误\n");
            kk = 1;
        }
    }
    else
    {
        printf("表达式错误\n");
        kk = 1;
    }
    return;
}

void main()
{
    p = 0;
    int i;
    printf("********************语法分析程序***************\n");
    printf("请输入源程序:\n");
    do
    {
        scanf("%c", &chBuf);
        prog[p++] = chBuf;
    } while (chBuf != '#');
    p = 0;
    scaner();
    lrparser();
    printf("语法分析结束！\n");

    getch();
}
