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
    int line = 0; //行数
    char tmp[100];
    int i = 0;
    while (scanf("%c", &chBuf))
    {
        if (chBuf == ' ' || chBuf == '\t') //为空格或是tab
            continue;
        //回车
        else if (chBuf == '\n')
            line++;
        //是否是界符
        else if (chBuf == '(' || chBuf == ')' ||
                 chBuf == '{' || chBuf == '}' ||
                 chBuf == ',' || chBuf == ';')
        {
            printf("(boundary,%c)\n", chBuf);
        }
        else if (isDigit(chBuf)) //如果是数字
        {
            while (isDigit(chBuf))
            {
                tmp[i++] = chBuf;
                scanf("%c", &chBuf);
            }
            tmp[i] = '\0'; //加上结束符
            i = 0;
            printf("(integer,%s)\n", tmp);
            ungetc(chBuf, stdin); //将字符退回到输入流中
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
            if (isKeyword(tmp)) //关键字
                printf("(keyword,%s)\n", tmp);
            else //自定义标识符
                printf("(identifier,%s)\n", tmp);
            ungetc(chBuf, stdin);
        }

        //是否是运算符
        else
        {
            tmp[i++] = chBuf;
            while (scanf("%c", &chBuf) && (chBuf == '=' || chBuf == '<' || chBuf == '>' || chBuf == '!'))
            {
                tmp[i++] = chBuf;
            }
            tmp[i] = '\0'; //加上结束符
            i = 0;
            printf("(operator,%s)\n", tmp);
            ungetc(chBuf, stdin);
        }
    }
}
int main()
{
    // 改为从in.txt中读入数据
    freopen("in.txt", "r", stdin);
    // 获取字符并分析
    get();
    return 0;
}
