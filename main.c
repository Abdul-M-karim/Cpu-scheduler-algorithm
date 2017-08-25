//
//  main.c
//  FCFS scheduling algorithm
//
//  Created by abdul karim on 6/28/17.
//  Copyright © 2017 Abdul Karim. All rights reserved.
//

#include<stdio.h>
int MAX = 10; // MAX amount of Process to simulate
int main()
{
    int number;                 // amount of Proccess you would like to create MAX = 10
    int burstTime[MAX];         // Time spent on each Process
    int waitTime[MAX];          // Variable to keep track of waiting time
    int turnAroundTime[MAX];  // Total of the average wait time of all process
    double averageWaitTime = 0;    // avergae wait time of a process
    double averageTurnAroundTime =0;  // variable to hold the average turn around time
    int i; // variable for loop
    int j; // another for loop variable.
    int turnAroundTimeSJF[MAX]; //variable to hold turnaround times for SJF algorithm
    float averageWaitTimeSJF; //variable to hold the average wait time for SJF algorithm
    float averageTurnaroundTimeSJF; //variable to hold the average turn around time for SJF algorithm
    int process[MAX]; //process for SJF
    int iSJF; // variable for loop in SJF algorithm
    int jSJF; // variable for loop in SJF algorithm
    int total=0; // total initalized to zero for SJF algorithm
    int pos; //index variable for selection sort
    int temp;  //temp variable for selection sort
    printf("How many process to create (MAX=10 to run FCFS algorithm then SJF algoirthm): ");    // Print Prompt for amount of  Proces to simulate.
 
    scanf("%d",&number); // Read in the user input and store it in Memory loction of number
    
    printf("\nEnter The burst time for the Process to run FCFS algorithm then SJF algoirthm.\n"); // Print Prompt for Burst time for each Process
    
    for ( i =0; i<number; i++) // for loop to loop through each process
    {
        printf( "Process %d:", i+1 ); // Display process with number
        
        scanf("%d",&burstTime[i]);   // Enter in burst Time for the given process
    }
    
    waitTime[0]=0;    //waiting time for first process is initializied to  0
    
    for ( i=1; i < number; i++) // for loop to loop through numbers starting with waitTime = 1
    {
        waitTime[i]=0; // intialize waitTime
        
        for ( j=0; j < i; j++) // for loop to loop through WaitTime array starting with 1.
            waitTime[i] += burstTime[j];  // add the burstTimes of each process to the waitTime Array.
    }
    printf("\n\t\t\t\tFCFS RESULTS\n");
    printf("\n Process # \t BurstTime\t WaitingTime\t TurnaroundTime");
    
    for( i=0; i < number; i++) // for loop to calucalte turnAroundTime
    {
        turnAroundTime[i] = burstTime[i] + waitTime[i];// calculate turnAroundTime by adding BurstTime & WaitTme
        averageWaitTime += waitTime[i]; // add the Array of WaitTimes to the variable averageWaitTime.
    
        averageTurnAroundTime += turnAroundTime[i]; // add turnAroundTimes to AverageTurnAroundTime var.
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t\t%d",i+1,burstTime[i],waitTime[i],turnAroundTime[i]); // displays process #, the burst time, the wait time for process and totalTurnAroundTime.
    }
    
    averageWaitTime /= i; // calulate the average of WaitTimes
    
    averageTurnAroundTime /= i; // calculate the avergae of TurnAroundTime
    
    printf("\n\nAverage Waiting Time: %f\n",averageWaitTime); //display the Average waitTime
    
    printf("\nAverage Turnaround Time: %f\n",averageTurnAroundTime); //display the Average turnAroundTime
    
    printf("!!!!Now lets do a run with the Shortest Job First Algorithm!!!!\n");
    
    
    // selection sort burst time in acending order.
    for(iSJF=0;iSJF<number;iSJF++)
    {
        pos=iSJF;
        for(jSJF=iSJF+1;jSJF<number;jSJF++)
        {
            if(burstTime[jSJF]<burstTime[pos])
                pos=jSJF;
        }
        
        temp=burstTime[iSJF];
        burstTime[iSJF]=burstTime[pos];
        burstTime[pos]=temp;
        
        temp=process[iSJF];
        process[iSJF]=process[pos];
        process[pos]=temp;
    }
    
    waitTime[0]=0;            // zero wait time for first the first process
    
    
    for( iSJF=1; iSJF<number; iSJF++)
    {
        waitTime[iSJF]=0; // initalize array to zero
        for(jSJF=0;jSJF<iSJF;jSJF++) // loop through the array
            waitTime[iSJF]+=burstTime[jSJF]; // add the burstTime of each Process to the WaitTime
        
        total+=waitTime[iSJF]; // add the waitTime to the total
    }
    
    averageWaitTimeSJF=(double)total/number;      // Calculate the average waitTime
    total=0;
    printf("\n\t\t\t\t SJF RESULTS\n");
    printf("\n Process # \t BurstTime\t WaitingTime\t TurnaroundTime");
    for(iSJF=0; iSJF<number; iSJF++)
    {
        turnAroundTimeSJF[iSJF]=burstTime[iSJF]+waitTime[iSJF];     //calculate turn around time for SJF algorithm
        total+=turnAroundTimeSJF[iSJF]; // Calculate total for turnAroundTimes for SJF algorithm
        printf("\np[%d]\t\t  %d\t\t    %d\t\t\t%d",iSJF+1,burstTime[iSJF],waitTime[iSJF],turnAroundTimeSJF[iSJF]);
    }
    
    averageTurnaroundTimeSJF=(double)total/number;     // caluculate Average turnaround time for SJF algorithm for SJF algorithm
    printf("\n\nAverage Waiting Time=%f",averageWaitTimeSJF); // display results for waiting time
    printf("\nAverage Turnaround Time=%f\n",averageTurnaroundTimeSJF); // display results for turnaround time for SJF algorithm
}