#include "wordscan.h"

void lrparser();    // �жϳ����Ƿ�ȱʧ��ͷ��β
void yucu();        // �ж���䴮�Ƿ�Ϸ�
void statement();   // �ж�����Ƿ�Ϸ�
void expression();  // �жϱ��ʽ�Ƿ�Ϸ�
void term();        // �ж����Ƿ�Ϸ�
void factor();      // �ж������Ƿ�Ϸ�
int kk = 0; // kk���ж��Ƿ�end�й�

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
    { //Ϊ��ʶ��
        scaner();
        if (syn == 18)
        { //Ϊ :=
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
        //Ϊ��ʶ����������ʱ������һ�����ʷ���
        scaner(); 
    else if (syn == 27)
    {
        scaner();
        expression();
        if (syn == 28)
            scaner();
        else
        {
            printf(" ')' ����\n");
            kk = 1;
        }
    }
    else
    {
        printf("���ʽ����\n");
        kk = 1;
    }
    return;
}

void main()
{
    p = 0;
    int i;
    printf("********************�﷨��������***************\n");
    printf("������Դ����:\n");
    do
    {
        scanf("%c", &chBuf);
        prog[p++] = chBuf;
    } while (chBuf != '#');
    p = 0;
    scaner();
    lrparser();
    printf("�﷨����������\n");

    getch();
}
