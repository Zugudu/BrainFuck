#include <stdio.h>

void main(int argc,char *argv[])
{
FILE *fdo;
if((fdo=fopen(argv[1],"wb"))==NULL)
	return ;
char a;
while((a=(char)getc(stdin))!='\n')
{
putc(a,fdo);
}//WHILE
fclose(fdo);
}
