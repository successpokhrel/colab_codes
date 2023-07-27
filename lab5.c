#include<stdio.h>
#include<string.h>
int count = 0;
void printcurrentoutput(int a)
{
    if(a == 1)
        printf("0");
    else if(a == 2)
        printf("0");
    else if(a == 3)
        printf("0");
    else if(a == 4)
    {
        printf("1");
        count++;
    }
}
int changestate(int a, char b)
{
    if(a == 1)
    {
        if(b == 'a')
            return 2;
        else if(b == 'b')
            return 1;
    }
    else if(a == 2)
    {
        if(b == 'a')
            return 3;
        else if(b == 'b')
            return 1;
    }
    else if(a == 3)
    {
        if(b == 'a')
            return 3;
        else if(b == 'b')
            return 4;
    }
    else if(a == 4)
    {
        if(b == 'a')
            return 2;
        else if(b == 'b')
            return 1;
    }
}

int main()
{
    char input[40];
    printf("\n Alphabet set: {a,b}\n");
    printf("\n MOORE MACHINE TO COUNT OCCURENCE OF 'aab'\n");
    printf("\n Enter input string: ");
    scanf("%s",input);
    printf(" Output String: ");
    int currstate = 1;
    int i;
    for(i=0;i<strlen(input);i++)
    {
        printcurrentoutput(currstate);
        currstate = changestate(currstate, input[i]);
    }
    printcurrentoutput(currstate);
    printf("\n Total 'aab' count: %d",count);
}
