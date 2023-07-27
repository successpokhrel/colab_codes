#include<stdio.h>
#include<string.h>

typedef struct state
{
	int statename;
	int flag_q1;
	int flag_q2;
	int flag_q3;
	int flag_q4;	
}state;

void nfaimplementation(state *s, char input)
{
	if(s->statename==1)
	{
		if(input == '0')
		{
			s->flag_q1 = 1;
			s->flag_q2 = 1;
			s->flag_q3 = 0;
			s->flag_q4 = 0;
		}
		else
		{
			s->flag_q2= 0;
			s->flag_q3 = 0;
			s->flag_q4 = 1;
		}
	}
	else if(s->statename == 2)
	{
		if(input == '0')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 1;
			s->flag_q4 = 0;
		}
		else if(input == '1')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 0;
			s->flag_q4 = 0;
		}	
	}
	else if(s->statename == 3)
	{
		if(input == '0')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 1;
			s->flag_q4 = 0;
		}
		else if(input == '1')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 1;
			s->flag_q4 = 0;
		}	
	}
	else if(s->statename == 4)
	{
		if(input == '0')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 0;
			s->flag_q4 = 0;
		}
		else if(input == '1')
		{
			s->flag_q1 = 0;
			s->flag_q2 = 0;
			s->flag_q3 = 1;
			s->flag_q4 = 0;
		}	
	}
}
void clearflags(state* s)
{
	s->flag_q1 = 0;
	s->flag_q2 = 0;
	s->flag_q3 = 0;
	s->flag_q4 = 0;
}
int main()
{
	state curr;
	curr.statename = 1;
	char string[20],input;
	printf("Enter string: ");
	scanf("%s",string);
	int i,j;
	clearflags(&curr);
	for(i=0;i<strlen(string);i++)
	{
		input = string[i];
		if (curr.flag_q3 == 1)
		{
			curr.statename = 3;
			printf("\n Taking Q3 \n");
		}
		else
		{
			if(curr.flag_q2 == 1 && input == '0'){
				curr.statename = 2;
				printf("\n Taking Q2 leaving Q1 (we'll reach final state) \n");
				}
			else if(curr.flag_q2 == 1 && input == '1'){
				curr.statename = 1;
				printf("\n Taking Q1 (Q2'll meet it's end) \n");
			}
			if(curr.flag_q4 == 1 && input == '1'){
				curr.statename = 4;
				printf("\n Taking Q4 leaving Q1 (we'll reach final state)\n");
			}
			else if(curr.flag_q4 == 1 && input == '0'){
				curr.statename = 1;
				printf("\n Taking Q1 (Q4'll meet it's end) \n");
			}
		}
		nfaimplementation(&curr,input);
		printf("Current state: Q%d\n",curr.statename);
		printf("Input: %c\n",input);
		printf("next possible states: ");
		if(curr.flag_q1 == 1)
			printf("Q1 ");
		if(curr.flag_q2 == 1)
			printf("Q2 ");
		if(curr.flag_q3 == 1)
			printf("Q3 ");
		if(curr.flag_q4 == 1)
			printf("Q4 ");
		printf("\n");
	}
	if(curr.flag_q3 == 1)
		printf("\n String is accepted !!");
	else
		printf("\n String is not accepted!!");
	return 0;
}

