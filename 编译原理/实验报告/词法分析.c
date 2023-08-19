#include <stdio.h>
#include <string.h>
int isDigit(char chBuf)
{
    if (chBuf >= '0' && chBuf <= '9')
        return 1;
    else
        return 0;
}

int isLitter(char chBuf)
{
    if (chBuf >= 'a' && chBuf <= 'z' || chBuf >= 'A' && chBuf <= 'Z')
        return 1;
    else
        return 0;
}

int isKeyword(char tmp[])
{
    if (!strcmp(tmp, "main") ||
        !strcmp(tmp, "if") || !strcmp(tmp, "else") ||
        !strcmp(tmp, "for") || !strcmp(tmp, "while") ||
        !strcmp(tmp, "int") || !strcmp(tmp, "return"))
        return 1;
    else
        return 0;
}
void get()
{
    char chBuf;
    int line = 0; //����
    char tmp[100];
    int i = 0;
    while (scanf("%c", &chBuf))
    {
        if (chBuf == ' ' || chBuf == '\t') //Ϊ�ո����tab
            continue;
        //�س�
        else if (chBuf == '\n')
            line++;
        //�Ƿ��ǽ��
        else if (chBuf == '(' || chBuf == ')' ||
                 chBuf == '{' || chBuf == '}' ||
                 chBuf == ',' || chBuf == ';')
        {
            printf("(boundary,%c)\n", chBuf);
        }
        else if (isDigit(chBuf)) //���������
        {
            while (isDigit(chBuf))
            {
                tmp[i++] = chBuf;
                scanf("%c", &chBuf);
            }
            tmp[i] = '\0'; //���Ͻ�����
            i = 0;
            printf("(integer,%s)\n", tmp);
            ungetc(chBuf, stdin); //���ַ��˻ص���������
        }
        else if (isLitter(chBuf) || chBuf == '_')
        {
            while (isLitter(chBuf) || isDigit(chBuf) || chBuf == '_')
            {
                tmp[i++] = chBuf;
                scanf("%c", &chBuf);
            }
            tmp[i] = '\0';
            i = 0;
            if (isKeyword(tmp)) //�ؼ���
                printf("(keyword,%s)\n", tmp);
            else //�Զ����ʶ��
                printf("(identifier,%s)\n", tmp);
            ungetc(chBuf, stdin);
        }

        //�Ƿ��������
        else
        {
            tmp[i++] = chBuf;
            while (scanf("%c", &chBuf) && (chBuf == '=' || chBuf == '<' || chBuf == '>' || chBuf == '!'))
            {
                tmp[i++] = chBuf;
            }
            tmp[i] = '\0'; //���Ͻ�����
            i = 0;
            printf("(operator,%s)\n", tmp);
            ungetc(chBuf, stdin);
        }
    }
}
int main()
{
    // ��Ϊ��in.txt�ж�������
    freopen("in.txt", "r", stdin);
    // ��ȡ�ַ�������
    get();
    return 0;
}
