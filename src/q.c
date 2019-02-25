#include <stdio.h>
#define RAM 8
unsigned char cell[RAM];
char ptr=0;

void main(int argc,char *argv[])
{
FILE *prg;
if((prg=fopen(argv[1],"rb"))==NULL)
	return ;
char com;
while((com=(char)getc(prg))!=EOF)
{
	switch(com)
	{
	case '>':
	ptr++;
	if(ptr>=RAM) ptr--;
	break;

	case '<':
	ptr--;
	if(ptr<0) ptr++;
	break;

	case '+':
	cell[ptr]++;
	break;

	case '-':
	cell[ptr]--;
	break;

	case '.':
	putc(cell[ptr],stdout);
	break;
	}//SWICTH
}//WHILE
fclose(prg);
}

