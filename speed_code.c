#include <stdio.h>

#define IN 1
#define OUT 0
#define TABSIZE 100

void print_table(char tab[TABSIZE][TABSIZE]);

char tab[100][100];

int main()
{
	char c;	
	int status=OUT;
	int word_number=0;
	int i,j;
	i=0;
	j=0;
	while((c=getchar())!=EOF) {
		if (c==' ' || c=='\t' || c=='\n') {
			if(word_number>0){
				if(status==IN) {
					tab[i][j]='-';
					++j;
					tab[i][j]='\0';
				}
			}
			status=OUT;	
		}
		else {
			if(status==OUT){
				if(word_number>0){
						++i;
						j=0;
					}
				
				status=IN;
				++word_number;
			}			
		}

		
		if(status==IN){
			tab[i][j]=c;
			++j;
		}


	}
	printf("%c\n",tab[2][2]);
	printf("words: %d\n",word_number);
	print_table(tab);
	
	return 0;
}

void print_table(char tab[TABSIZE][TABSIZE])
{
		 for (int i=0;i<TABSIZE;++i)
			for(int j=0;j<TABSIZE;++j){
				putchar(tab[i][j]);
				}
}


