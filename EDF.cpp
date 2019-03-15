#include "stdio.h"
#include "stdlib.h"

typedef struct Request{
    int arrivalTime;
    int requiredCylinder;
    int deadline;
} Request;

int main(void){
    int requestsSize = 8;
    Request* requests = (Request*) malloc(sizeof(Request)*requestsSize);
    Request r1 = {0, 98, 50};
    Request r2 = {4, 183, 60};
    Request r3 = {2, 37, 25};
    Request r4 = {0, 122, 74};
    Request r5 = {3, 14, 40};
    Request r6 = {2, 124, 50};
    Request r7 = {1, 65, 76};
    Request r8 = {1, 67, 31};
    requests[0] = r1;
    requests[1] = r2;
    requests[2] = r3;
    requests[3] = r4;
    requests[4] = r5;
    requests[5] = r6;
    requests[6] = r7;
    requests[7] = r8;

    Request* arrivedRequests = (Request*) malloc(sizeof(Request)*requestsSize);
    int arrivedRequestsIndexer = 0;
    int currentTime = 0;
    int counter = 0;
    int head_movements = 0, head_position = 53;

    while(counter<requestsSize){
        Request mostPriorRequest = {0,0,999999};
        int arrivedCounter = 0;
        for(int i = 0; i < requestsSize; i++){
            if(requests[i].arrivalTime==currentTime){
                if(mostPriorRequest.deadline > requests[i].deadline){
                    arrivedRequests[arrivedRequestsIndexer++] = mostPriorRequest;
                    mostPriorRequest = requests[i];
                    arrivedCounter++;
                }else{
                    arrivedRequests[arrivedRequestsIndexer++] = requests[i];
                    arrivedCounter++;
                }
            }
        }

        if(arrivedCounter!=0){
            for(int i = 0; i < arrivedRequestsIndexer; i++){
                if(mostPriorRequest.deadline > arrivedRequests[i].deadline){
                    Request temp = arrivedRequests[i];
                    arrivedRequests[i] = mostPriorRequest;
                    mostPriorRequest = temp;
                }
            }
        }else{
            int index = 0;
            for(int i = 0; i < arrivedRequestsIndexer; i++){
                if(mostPriorRequest.deadline > arrivedRequests[i].deadline){
                    mostPriorRequest = arrivedRequests[i];
                    index = i;
                }
            }

            arrivedRequestsIndexer--;
            for(int i = index; i < arrivedRequestsIndexer; i++){
                arrivedRequests[i] = arrivedRequests[i+1];
            }
        }
        

        head_movements += abs(mostPriorRequest.requiredCylinder - head_position);
        head_position = mostPriorRequest.requiredCylinder;
        //printf("Current head position: %i\n", head_position);
        counter++;
        currentTime++;
    }

    printf("Total head movements: %i\n", head_movements);   

    return 1;
}