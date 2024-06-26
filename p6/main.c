#include <stdio.h>
#include <stdlib.h>
#include "student.h"


void usage()
{
    printf("Usage: 'program filename' -f for print -p <parameter> for action\n");
}

int main(int argc, char* argv[])
{   
    if (argc != 3 && argc != 4)
    {
        usage();
        return 1;
    }

    char* name = argv[1]; 

    FILE *in = fopen(name, "r");

    if (!in) 
    {
        perror("Can't open file");
        return 2;
    }

    if (argv[2][0] == '-' && argv[2][1] == 'f')
    {
        print_table(in);
        fclose(in);
        return 0;
        
    }

    if (argv[2][0] == '-' && argv[2][1] == 'p') 
    {
        student s; 

        int answer = 0;
        while (read_file(&s, in))
        {
            if (s.group != atoi(argv[3]) || s.gender == 'm')
                continue;
            int count = 0;
            int grades[] = { s.dm, s.inf, s.la, s.ma, s.py };
            for (int i = 0; i < sizeof(grades)/sizeof(int); i++)
            {
                if (grades[i] == 5)
                    count++;
                if (count == 2)
                    break;
            }
            if (count == 1)
                answer++;
        }

        fclose(in);

        printf("Количество студенток с одной пятёркой в группе %d: %d\n", atoi(argv[3]), answer);
    }

    return 0;
}
