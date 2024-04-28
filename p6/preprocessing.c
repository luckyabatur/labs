#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "student.h"


void usage()
{
	printf("Usage: program filename\n");
}


int readstudent(student *st)
{
	return scanf("%[^;]; %[^;]; %c; %[^;]; %d; %d; %d; %d; %d\n",
	st->name, st->initials, &st->gender, st->group, &st->la, &st->inf, &st->py, &st->dm, &st->ma) == 9;
}


int main(int argc, char* argv[])
	{

	if (argc != 2) 
	{
		usage();
		return 1;
	}

	FILE *out = fopen(argv[1], "w");

	if (!out) 
	{
		perror("Can't open file");
		return 2;
	}

	student st;
	student* s = &st;

	while (readstudent(&st))
	{
		fwrite(s->name, sizeof(char), SIZE_N, out);
		fwrite(s->initials, sizeof(char), SIZE_I, out);
		fwrite(&s->gender, sizeof(char), 1, out);
		fwrite(s->group, sizeof(char), SIZE_G, out);
		fwrite(&s->la, sizeof(int), 1, out);
		fwrite(&s->inf, sizeof(int), 1, out);
		fwrite(&s->py, sizeof(int), 1, out);
		fwrite(&s->dm, sizeof(int), 1, out);
		fwrite(&s->ma, sizeof(int), 1, out);
	}

	fclose(out);

	return 0;
}