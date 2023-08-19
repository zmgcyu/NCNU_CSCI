#include "string.h"
#include <stdio.h>
#include <conio.h>
char prog[80], token[8]; // prog�����洢Ҫ����Ķ���token������ؼ��ֱȽ�
/*
    syn���ֱ��룬
    pΪprog�����ָ�룬
    mΪtoken�����ָ�룬
    nΪrwtab�����ָ�룬
    sumΪ�ʷ����������������ֵ��С
*/
int syn, p, m, n, sum = 0;

char chBuf; // ch�����洢һ���ַ�
char *rwtab[6] = {"begin", "if", "then", "while", "do", "end"};
void scaner()
{
    m = 0;
    for (n = 0; n < 8; n++)
        token[n] = ' ';
    chBuf = prog[p++];
    while (chBuf == ' ')
        chBuf = prog[p++];
    if ((chBuf >= 'a' && chBuf <= 'z') || (chBuf >= 'A' && chBuf <= 'Z'))
    {
        while ((chBuf >= 'a' && chBuf <= 'z') || (chBuf >= 'A' && chBuf <= 'Z') || (chBuf >= '0' && chBuf <= '9'))
        {
            token[m++] = chBuf;
            chBuf = prog[p++];
        }
        token[m++] = '\0';
        syn = 10;
        p = p - 1; //����һ���ַ�
        for (n = 0; n < 6; n++)
        {
            if (strcmp(token, rwtab[n]) == 0)
            {
                syn = n + 1;
                break;
            }
        }
    }
    else if (chBuf >= '0' && chBuf <= '9')
    {
        sum = 0;
        while (chBuf >= '0' && chBuf <= '9')
        {
            sum = sum * 10 + chBuf - '0';
            chBuf = prog[p++];
        }
        p = p - 1;
        syn = 11;
    }
    else
    {
        switch (chBuf)
        {
        case '<':
            m = 0;
            token[m++] = chBuf;
            chBuf = prog[p];
            if (chBuf == '>')
            {
                syn = 21;
                token[m++] = chBuf;
            }
            else if (chBuf == '=')
            {
                syn = 22;
                token[m++] = chBuf;
            }
            else
            {
                syn = 20;
                p = p - 1;
            }
            p = p + 1;
            token[m] = '\0';
            break;
        case '>':
            m = 0;
            token[m++] = chBuf;
            chBuf = prog[p++];
            if (chBuf == '=')
            {
                syn = 24;
                token[m++] = chBuf;
            }
            else
            {
                syn = 23;
                p = p - 1;
            }
            break;
        case ':':
            m = 0;
            token[m++] = chBuf;
            chBuf = prog[p++];
            if (chBuf == '=')
            {
                syn = 18;
                token[m++] = chBuf;
            }
            else
            {
                syn = 17;
                p = p - 1;
            }
            break;
        case '+':
            syn = 13;
            token[0] = chBuf;
            break;
        case '-':
            syn = 14;
            token[0] = chBuf;
            break;
        case '*':
            syn = 15;
            token[0] = chBuf;
            break;
        case '/':
            syn = 16;
            token[0] = chBuf;
            break;
        case ';':
            syn = 26;
            token[0] = chBuf;
            break;
        case '(':
            syn = 27;
            token[0] = chBuf;
            break;
        case ')':
            syn = 28;
            token[0] = chBuf;
            break;
        case '=':
            syn = 25;
            token[0] = chBuf;
            break;
        case '#':
            syn = 0;
            token[0] = chBuf;
            break;
        default:
            syn = -1;
        }
    }
}
