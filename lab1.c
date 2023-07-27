#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,count;
	char s1[20], s2[20], l[20], s[20],comp[20],temp;
	start:
    printf("\nTHE ALPHABET SET IS THE SET OF CHARACTERS IN LARGER STRING\n");
	printf("\nEnter first string: ");
	scanf("%s",s1);
	printf("Enter second string: ");
	scanf("%s",s2);
	if(strlen(s1)>=strlen(s2))
	{
		strcpy(l,s1);
		strcpy(s,s2);
	}
	else
	{
		strcpy(l,s2);
		strcpy(s,s1);
	}
	printf("\n***ANALYSIS OF STRING***\n\n");
	printf("ALPHABET SET = {");
	char alphabetset[strlen(l)];
	int m=0;
	int flag;
	for(i=0;i<strlen(l);i++)
    {
        temp = l[i];
        flag = 0;
        for(j=0;j<=m;j++)
        {
            if(l[i] == alphabetset[j])
                flag = 1;
        }
        if (flag == 0)
        {
            printf("%c, ",temp);
            alphabetset[m] = temp;
            m++;
        }
    }
    printf("}\n");
    printf("RESULTS BELOW IS COMPARISION OF SMALLER STRING WITH BIGGER FOR CONDITIONS BELOW: \n");
	int flagimproper = 0;
	int flagprefix = 0;
	int flagsuffix = 0;
	int flagproper = 0;
	if(strcmp(l,s)==0)
	{
		flagimproper = 1;
	}
	count = 0;
	for(i=0;i<strlen(s);i++)
	{

		if(l[i] == s[i])
			count++;
	}
	if (count == strlen(s))
		flagprefix = 1;
	count = 0;
	int k = strlen(l)-1;
	for(i=strlen(s)-1;i>=0;i--)
	{
		if(l[k] == s[i])
			count++;
		k--;
	}
	if(count == strlen(s))
			flagsuffix = 1;

	int dif;
	dif = strlen(l)-strlen(s);
	k = 0;
	int li = 0;
	while(k<=dif)
	{
		count = 0;
		int ls = li;
		for(i=0;i<strlen(s);i++)
		{
			if(l[ls] == s[i])
				count++;
			ls++;
		}
		li++;
		if(count == strlen(s))
		{
			flagproper = 1;
			break;
		}
		k++;
	}

	if(flagimproper == 1)
	{
		printf("\nImproper subset: Yes");
		flagproper = 0;
	}
	else
		printf("\nImproper subset: No");
    if(flagproper == 1)
		printf("\nProper subset: Yes");
	else
		printf("\nProper subset: No");
	if(flagprefix == 1)
		printf("\nPrefix: Yes");
	else
		printf("\nPrefix: No");
	if(flagsuffix == 1)
		printf("\nSuffix: Yes");
	else
		printf("\nSuffix: No\n");

	int choice;
	printf("\n Press 1 to continue: ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		system("cls");
		goto start;
	}
	return 0;
}
