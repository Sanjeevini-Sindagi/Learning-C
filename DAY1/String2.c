#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int map[52] = {0};

    printf("Enter the string: ");
    scanf("%99s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z')
            map[ch - 'A']++;
        else if (ch >= 'a' && ch <= 'z')
            map[ch - 'a' + 26]++;
    }

    for (int i = 0; i < 52; i++)
    {
        if (map[i] > 1)
        {
            if (i < 26)
                printf("%c repeated %d times\n", 'A' + i, map[i]);
            else
                printf("%c repeated %d times\n", 'a' + i - 26, map[i]);
        }
    }

    return 0;
}