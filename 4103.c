Name:		Bergeron, Andrew
Project:	PA-2 (page replacement)
File:		4103.C
Instructor: 	Feng Chen
Class:		cs4103-sp15
LoginID:	cs410305


#include<stdio.h>
int fr[5];
int fs[5];
int main()
{
int numbers[28] = { 0, 1, 2, 3, 2, 4, 5, 3, 4, 1, 6, 3, 7, 8, 7, 8, 4, 9, 7, 8, 1, 2, 9, 5, 4, 5, 0, 2};
int i = 0;
int j,k,l;
int index = 0;
int flag_1 = 0, flag_2 = 0;
int frame[5];
int frsize;
int pfaultcount=0;

int n = 27;
int input;
int extra = n + 1;
printf("Please Enter 1 or 2 for your selection\n");
printf(" Enter 1 for CLOCK\n");
printf(" Enter 2 for LRU\n");
scanf("%d",&input);
while(input != 1 && input != 2)
{
printf("Please Enter ONLY 1 or 2\n");
printf(" Enter 1 for CLOCK\n");
printf(" Enter 2 for LRU\n");
scanf("%d",&input);
}
            
printf("\n Enter the number of frames from 1 to 5:\n");
scanf("%d",&frsize);
while( frsize != 1 && frsize != 2 && frsize != 3 && frsize != 4 && frsize != 5)
{
printf("\n Enter the number of frames from 1 to 5:\n");
scanf("%d",&frsize);
}
            
if ( input == 1) 
{         
for(i=0;i<frsize;i++)
     {
       frame[i]=-1;
     }                    

                        flag_2=0;
                       
for(i=1;i<=n;i++)
                        {
                                    
                                    flag_1 =0;
                                    for(k=0;k<frsize;k++)
if(frame[k] == numbers[i])
                                                flag_1 =1;
                                    if (flag_1 ==0)
                                    {
                                                
                                                frame[flag_2]=numbers[i];
                                                flag_2=(flag_2+1)%frsize;
                                                pfaultcount++;
                                                
}                                               for(k=0;k<frsize;k++)
                                                printf("\t%d",frame[k]);
                                    printf("\n");
}
                        printf("Number of page faults equals: %d",pfaultcount);
                       
}

if ( input == 2)
{
      for(i=0;i<frsize;i++)
     {
       fr[i]=-1;
     }   
     for( j = 0; j < extra; j++)
       {
       flag_1=0,flag_2=0;
       for(i=0;i<3;i++)
       {
       if(fr[i]==numbers[j])
       {
       flag_1 = 1;
       flag_2 = 1;
       break;
       }}
       if(flag_1==0)
       { 
       for(i=0;i<frsize;i++)
       {
       
       if(fr[i]==-1)
       {
       fr[i]=numbers[j];
       flag_2=1;
       pfaultcount++;
       break;
       }
       }
       }
       if(flag_2==0)
       {
       for(i=0;i<frsize;i++)
       {
          fs[i]=0;
          }
       for(k=j-1,l=1;l<=frsize-1;l++,k--)
       {
       for(i=0;i<frsize;i++)
       {
       if(fr[i]==numbers[k])
       fs[i]=1;
       }
       }
       for(i=0;i<frsize;i++)
       {
       if(fs[i]==0)
       index=i;
       }
       
       fr[index]=numbers[j];
       pfaultcount++;
       }
       printf("\n");
       for(i=0;i<frsize;i++)
       printf("\t%d",fr[i]);
       }
     printf("\nNumber of page faults equals :%d",pfaultcount);
     
} 
               printf("\nEnter any key followed by Enter/Return to close this program");
                       scanf("%d",&input);
        
}
