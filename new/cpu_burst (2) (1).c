 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 int main()
{

 FILE *fp = fopen("cpu_burst.txt", "r");
 
    int burst_time[20],process[20],waiting_time[20],tat[20],i=0,j,n=5,total=0,pos,temp;
    float avg_wt,avg_tat;  
    
    printf("\nReading CPU_BURST.txt File\n");
     
    while((getc(fp))!=EOF)
    {
        fscanf(fp, "%d", &burst_time[i]);
        if(burst_time[i]>0)
		{
                 process[i]=i+1;
	         i++;
		}    //contains process number
    }
    
    n=i;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
            pos=j;
        }
    
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    
    waiting_time[0]=0;            //waiting time for first process will be zero
//calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
    
    avg_wt=(float)total/n; //average waiting time
     total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
       tat[i]=burst_time[i]+waiting_time[i];       //calculate turnaround time
       total+=tat[i];
       printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],burst_time[i],waiting_time[i],tat[i]);
    }
    
   avg_tat=(float)total/n;     //average turnaround time
   
   printf("\n\nAverage Waiting Time=%f",avg_wt);
   printf("\nAverage Turnaround Time=%f\n",avg_tat);
   fclose(fp);
   return 0;
}
