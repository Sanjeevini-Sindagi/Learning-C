#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, len;
    int map[26] = {0};

    printf("Enter the string: ");
    scanf("%99s", str);
    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        char ch = str[i];
        map[ch - 'a']++;
    }

    printf("Duplicate letters in the string:\n");

    for(i = 0; i < 26; i++)
    {
        if(map[i] > 1)
        {
            printf("%c repeated %d times\n", 'a' + i, map[i]);
        }
    }

    return 0;
}