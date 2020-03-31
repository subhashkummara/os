#include<stdio.h> 
#include<conio.h>

void kk(int nme,int rmie[10],int Cur_t,int arvlie[10], int brtie[10]);

main() 
{
	
        int variable,j,nme,CurT,rmiigaibe,indicator,tmqantm,wtai,tute,arvlie[10],brtie[10],rmie[10],z=1;
	indicator = 0;
	wtai = 0;
	tute = 0;
	printf("Enter the  number of processes "); 
	scanf("%d",&nme);
	rmiigaibe = nme;
	

	printf("\n\n  Enter the arrival time and burst time of the processes\n");
	for(variable = 0;variable < nme;variable++) 
	{
		printf("\nProcess P%d\n",variable+1);
		printf("Arrival time = "); 
		scanf("%d",&arvlie[variable]);
		printf("Burst time = "); 
		scanf("%d",&brtie[variable]); 
		rmie[variable]=brtie[variable]; 
	} 
	printf("The details of time quantum are as follows:\n");
	printf("The time quantum for first round is 3.\n"); 
	tmqantm=3;
	CurT=0;

	for(variable=0;rmiigaibe!=0;) 
	{

		if(rmie[variable]<=tmqantm && rmie[variable]>0)
		{ 
			CurT+=rmie[variable]; 
			rmie[variable]=0; 
			indicator=1; 
		} 
		else if(rmie[variable]>0)
		{ 
			rmie[variable]-=tmqantm; 
			CurT+=tmqantm; 
		} 
		if(rmie[variable]==0 && indicator==1)			
		{ printf("%d",variable);
			rmiigaibe--;				
			printf("P %d",variable+1); 
			printf("\t\t\t%d",CurT-arvlie[variable]);
			printf("\t\t\t%d\n",CurT-brtie[variable]-arvlie[variable]);
			wtai+=CurT-arvlie[variable]-brtie[variable]; 
			tute+=CurT-arvlie[variable]; 
			indicator=0; 
                       
		} 
		if(variable==nme-1){
			z++;
			if(z==2){
				variable=0;
				tmqantm=10;
				
				printf("time quantum for  the second round is 6. \n");
			}
			else{
				break;
			}
		}
		else if(CurT >= arvlie[variable+1]){
			variable++;
		}
		else{
			variable=0;
		}
	}
	
	kk(nme,rmie,CurT,arvlie,brtie);
	
	return 0;
	getch();
}


void kk(int nme,int rmie[10],int Cur_t,int arvlie[10], int brtie[10]){
	
	float average_wtai,avg_tute;
    int i,j,n=nme,temp,btime[20],variable[20],w_time[20],tute_t[20],total=0,loc;
    
    printf(" the Third round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=rmie[i];
        w_time[i]=Cur_t-arvlie[i]-btime[i];
		variable[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=variable[i];
        variable[i]=variable[loc];
        variable[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }


 
    average_wtai=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twtaiing time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tute_t[i]=btime[i]+w_time[i];
        total=total + tute_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",variable[i],btime[i],w_time[i],tute_t[i]);
    }

    avg_tute=(float)total/n;
    printf("\n\nAverage wtaiing time = %f",average_wtai);
    printf("\n Average turnaround time = %f\n",avg_tute);
	getch();
}
