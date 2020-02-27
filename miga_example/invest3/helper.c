#include <stdio.h>
#include "helper.h"


void calculateGrowth(Investment *invp){
  int i;

  for(i=1; i<= invp->years; i=i+1){
    invp->invarray[i] = invp->growth * invp->invarray[i-1];
  }
}


int getUserInput(Investment *invp){
  int valid;
  char message[MAX_MESSAGE_LENGTH];   // added

  NU32_WriteUART3("Enter investment, growth rate, number of years");    // changed from printf
  NU32_WriteUART3("\r\n");                                              // added
  NU32_ReadUART3(message, MAX_MESSAGE_LENGTH);                          // added
  sscanf(message, "%lf %lf %d", &(invp->inv0), &(invp->growth), &(invp->years));
  NU32_WriteUART3(message);                                             // added
  NU32_WriteUART3("\r\n");                                              // added
  valid = (invp->inv0 > 0) && (invp->growth > 0) && (invp->years > 0) && (invp->years <= MAX_YEARS);

  // this is being weird
  // NU32_WriteUART3("Valid input?");
  // NU32_WriteUART3(valid);
  return(valid);
}


void sendOutput(double *arr, int yrs){
  int i;
  char outstring[100];

  NU32_WriteUART3("\r\nRESULTS:\r\n");                                  // changed; added return carriage tag

  for(i=0; i<=yrs;i++){
    sprintf(outstring, "Year %3d:   %10.2f\r\n", i, arr[i]);

    NU32_WriteUART3(outstring);                                         // changed from printf
  }

  NU32_WriteUART3("\r\n");                                              // added
}
