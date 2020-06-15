#include<stdio.h>
#include<string.h>

int next(int i)
{//prime number next calculation
	int count,j;
	while(i)//read the next cha
	{
		i++;
		count=0;
		for(int j=2;j<i+1;j++)
			if(i%j==0)
				count++;
		if(count==1)
			return i;
	}
}

int rev(int m)
{//calculate the previous prime number
	int count=0;
	for(int k=m; k>2;k--)
		{
			if(k<2)
				break;
			else
			{
				count=0;
				for(int j=2;j<(k+1);k++)
					if(k%j==0)
						count++;
				if(count==1)
					return k;
			}
		}
}
int main()
{
	int t;//input for test case
  char s[5];//characters of size 100
	int qw[10],ql[10],i=0,count,count1,j;//qw is temporary array whereas ql is final array    
	printf("Enter t:");
		scanf("%d",&t);
		t--;//decrement
		printf("Enter s: ");//for(int loop=0;loop<5;loop++)
		 scanf("%s",&s);
    printf("Before s[i]");//success
		while(s[i]!='\0')//until the string gets terminated
			qw[i]=(int)s[i];//copy each char into qw[i]
    printf("After s[i]");//success
		i=0;
		while(qw[i]!='\0')
		{
			if(qw[i]<=65)//because hash needs to be in alphabets
			{
				qw[i]=65;
				count=next(qw[i]);//sending character to next function
				count1=rev(qw[i]);//sending character to rev function
				if(count-i>=i-count1)
					ql[i]=(char)count1;
				else
					ql[i]=(char)count;
			}
			else if(qw[i]<97 && qw[i]>=91)//character in specified range that are not alphabets
			{
                if (qw[i]-91>=97-qw[i])//
                    qw[i]=97;
                else
                    qw[i]=91;
                count=next(qw[i]);  //calling  function by passing character
                count1=rev(qw[i]);//calling function by passing character
                if (count-qw[i]>=qw[i]-count1)
                    ql[i]=(char)count1;
                else
                    ql[i]=(char)count;
            }//elseif
            else if(qw[i]>=122)
            {// in previous case it was converting y to null value
            	qw[i]=122;
            	count1=rev(qw[i]);
            	ql[i]=(char)count1;//QL
            }
            else if(j==121)
            {// similar to previous
            	count1=rev(qw[i]);
            	ql[i]=(char)count1;
            }
            else
        	{//for all the characters call function and 
        		count=next(qw[i]);
                count1=rev(qw[i]);
                if (count-qw[i]>=qw[i]-count1)
                    ql[i]=(char)count1;
                else
                    ql[i]=(char)count;
        	}
		}
  printf("%s",&ql);
}