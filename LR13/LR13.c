#include <stdio.h>


int intersection(int a, int b)
{
    return a & b;
}

int num(char c)
{
    int number = 27;
    if (c < 'a')
    {
        c = c + 32;
    }

    if (c > 'a' && c < 'e')
    {
        number = c - 'a' - 1;
    }
    
    else if (c > 'e' && c < 'i')
    {
        number = c - 'a' - 2;
    }

    else if (c > 'i' && c < 'o')
    {
        number = c - 'a' - 3;
    }

    else if (c > 'o' && c < 'u')
    {
        number = c - 'a' - 4;
    }

    else if (c > 'u' && c < 'y')
    {
        number = c - 'a' - 5;
    }

    else if (c > 'y')
    {
        number = c - 'a' - 6;
    }
    return number;
}


int main()
{
    int a, b;
    int g = 0;
    int ans = 1;
    int set = 0;  
    char c;
    int state = 0;
    while (scanf("%c", &c) != EOF)  
    {
        int number = 27;
        switch (state)
        {
        case 0:
            if (c != ' ' && c != '\n')
                {
                    state = 1;
                    number = num(c);
                    if (number < 27)
                    {
                        set |= (1<<number);
                    }
                }
            break;
        case 1:
            if (c != ' ' && c != '\n')
                number = num(c);
                if (number < 27)
                {
                    set |= (1<<number);
                }
            else
            {
                a = set;
                state = 2;
                set = 0;
                if (a != 0)
                {
                    g = 1;
                }
            }
            break;
        case 2:
            if (c != ' ' && c != '\n')
            {
                g = 1;
                state = 3;
                number = num(c);
                if (number < 27)
                {
                    set |= (1<<number);
                }
                
            }
            break;       
        case 3:
            if (c != ' ' && c != '\n')
            {
                number = num(c);
                if (number < 27)
                {
                    set |= (1<<number);
                }
            }
            else
            {
                b = set;
                if (intersection(a, b) == 0)
                {
                    ans = 0;
                }
                a = intersection(a, b);
                set = 0;
                state = 2;
            }
        }
    }

    if (g == 0)
    {
        if (set == 0)
        {
            ans = 0;
        }
    }
    
    if (state == 3)
    {
        if (intersection(a, set) == 0)
        {
            ans = 0;
        } 
    }

    if (ans == 0)
    {
        printf("\nНЕТ");
    }
    else
    {
        printf("\nДА");
    }
}