#include<stdio.h>
#include<conio.h>
#define max 30

void main(){
	
	// declarations
	int i,j,np;
	int bt[max], at[max], tat[max], wt[max], temp[max];
	float awt=0, atat=0; // awt= avg waiting time and atat= avg turn around time
	
	printf("\n Enter the no. of process: ");
	scanf("%d",&np);
	
	printf("\n Enter the burst time of the process: ");
	for(i=0; i<np; i++)
		scanf("%d",&bt[i]);
	
	printf("\n Enter the arrival time of the process: ");
	for(i=0; i<np; i++)
		scanf("%d",&at[i]);
	
	temp[0]=0;
	printf("Process\t Burst Time\t Arrival Time\t Waiting Time\t Turn Around Time\n");
	for(i=0; i<np; i++){
		wt[i]=0;
		tat[i]=0;
		temp[i+1]=temp[i]+bt[i];
		wt[i]=temp[i]-at[i];
		tat[i]=wt[i]+bt[i];
		awt= awt+ wt[i];
		atat= atat + tat[i];
		printf("%d\t%d\t\t%d\t\t%d\t\t%d", i+1,bt[i],at[i], wt[i], tat[i]);
	}
	awt= awt/np;
	atat= atat/np;
	printf("\nAvg waiting time: %f",awt);
	printf("\nAvg turn around time: %f",atat);
}
