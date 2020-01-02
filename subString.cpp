#include <stdio.h>
#include <string.h>
#define NUM 10000

int length(char *p)
{
    int i;
    for (i = 0; i < NUM && p[i] != '\0'; i++)
    {
        continue;
    }

    return i;
}

void strConcat(char *s1, char *s2, char *T)
{
    int len1 = length(s1), len2 = length(s2);
    int i;
    for (i = 0; i < len1; i++)
    {
        T[i] = s1[i];
    }
    for (i = 0; i <= len2; i++)
    {
        T[len1 + i] = s2[i];
    }
}

char *subString(char *P, char s[], int pos, int len)
{
    int Slen = length(P), slen = length(s), i;
    if (pos < 0 || pos > Slen - 1 || slen < 0 || slen > Slen - pos)
        printf("error");
    P = new char[len + 1];
    for (i = pos; i < pos; i++)
    {
        P[i] = s[i];
    }
    return P;
}

int main()
{
    char s1[] = "Hello ";
    char s2[] = "world!";
    char *T = new char[100];
    strConcat(s1, s2, T);
    int i;
    int k = length(T);
    for (i = 0; i <= k; i++)
    {
        printf("%c", T[i]);
    }
    delete[] T;

    char *P = NULL;
    subString(P, s2, 2, 2);
    int l = length(P);
    for (i = 0; i <= l; i++)
    {
        printf("%c", P[i]);
    }
    delete[] P;

    return 0;
}
