#include <stdio.h>

int main()
{
    int state = 0, count = 0;
    char s;
    while ((scanf("%c", &s)) != EOF)
    {
        switch (state)
        {
            case 0:
                if (s != ' ' && s != '\n' && s != '\t' && s != ',')
                {
                    state = 1;
                }
                break;
            case 1:
                if (s != ' ' && s != '\n' && s != '\t' && s != ',')
                {
                    state = 2;
                }
                else
                {
                    state = 0;
                }
                break;
            case 2:
                if (s != ' ' && s != '\n' && s != '\t' && s != ',')
                {
                    count += 1;
                    state = 3;
                }
                else
                {
                    state = 0;
                }
                break;
            case 3:
                if (s == ' ' || s == '\n' || s == '\t' || s == ',')
                {
                    state = 0;
                }
        }
    }
    printf("\nКоличесво слов, содержащих не менее 3-х букв: %d", count);
}
