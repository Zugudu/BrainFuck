#include <stdio.h>
#define RAM 8
unsigned char cell[RAM];
char ptr=0;

void out(void)
{
putc(cell[ptr],stdout);
}

void outDeb(void)
{
printf("%d ",cell[ptr]);
}

void main(int argc,char *argv[])
{
FILE *prg;
if((prg=fopen(argv[1],"rb"))==NULL)
	return ;
void (*trw) (void);
//INIT
trw=out;
//DEFAULT SETTING
if(argc>2)
{
if(*(argv[2])=='d')trw=outDeb;
}
//ARG CHECK
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
	trw();
	break;

	case ',':
	scanf("%d",&cell[ptr]);
	break;

	case '[':
	if(cell[ptr]==(char)0){
	while(getc(prg)!=']'){}
	}
	break;

	case ']':
	if(cell[ptr]!=(char)0){
	do{
	fseek(prg,-2,SEEK_CUR);
	}while((com=getc(prg))!='[');
	}//IF
	break;
	}//SWICTH
}//WHILE
fclose(prg);
}

