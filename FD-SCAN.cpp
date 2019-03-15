#include "stdio.h"
#include "stdlib.h"

typedef struct Request{
    int arrivalTime;
    int requiredCylinder;
    int deadline;
} Request;

bool feasibleDeadline(Request r, int head_position, int current_time){
    int tracksDifference = abs(r.requiredCylinder - head_position);
    int accessN = tracksDifference/40;
    if(r.deadline > (accessN + current_time))
        return true;
    return false;
}

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

    Request* nonfeasibleRequests = (Request*) malloc(sizeof(Request)*requestsSize);
    int nonfeasibleRequestsIndexer = 0;

    Request* feasibleRequests = (Request*) malloc(sizeof(Request)*requestsSize);
    int feasibleRequestsIndexer = 0;


    int currentTime = 0;
    int counter = 0;
    int head_movements = 0, head_position = 53;
    Request currently_served_request;

    while(counter<requestsSize){
        Request* arrivedRequests = (Request*) malloc(sizeof(Request)*requestsSize);
        int arrivedRequestsIndexer = 0;

        Request mostPriorRequest = {0,0,999999};
        int arrivedCounter = 0;

        for(int i = 0; i < requestsSize; i++){
            if(requests[i].arrivalTime==currentTime){
                arrivedRequests[arrivedRequestsIndexer++] = requests[i];
            }
        }

        for(int i = 0; i < arrivedRequestsIndexer; i++){
            if(feasibleDeadline(arrivedRequests[i], head_position, currentTime)){
                feasibleRequests[feasibleRequestsIndexer++] = arrivedRequests[i];
            }else{
                nonfeasibleRequests[nonfeasibleRequestsIndexer++] = arrivedRequests[i];
            }
        }

        if(feasibleRequestsIndexer>0){
            Request current_request = {0,0,999999};
            int index = -2;
            for(int i = 0; i < feasibleRequestsIndexer; i++){
                if(!feasibleDeadline(feasibleRequests[i], head_position, currentTime)){
                    Request temp = feasibleRequests[i];
                    feasibleRequests[i] = feasibleRequests[--feasibleRequestsIndexer];
                    nonfeasibleRequests[nonfeasibleRequestsIndexer++] = temp;
                }else if(current_request.deadline < feasibleRequests[i]){
                    
                }
            }
            if(feasibleRequestsIndexer>0){
                Request current_request = {0,0,999999};
                int index = -2;
                for(int i = 0; i < feasibleRequestsIndexer; i++){
                    if(!feasibleDeadline(feasibleRequests[i], head_position, currentTime)){
                        Request temp = feasibleRequests[i];
                        feasibleRequests[i] = feasibleRequests[--feasibleRequestsIndexer];
                        nonfeasibleRequests[nonfeasibleRequestsIndexer++] = temp;
                    }
                }
            }
        }


        //NOW WE HAVE THE REQUEST TO WHICH WE NEED TO MOVE THE HEAD

        for(int i = 0; i < requestsSize; i++){
            if(requests[i].requiredCylinder == head_position){
                counter++;
                requests[i] = requests[requestsSize--];
            }
        }


        head_movements++;
        if(mostPriorRequest.requiredCylinder < head_position)
            head_position++;
        else
            head_position--;


        head_position = mostPriorRequest.requiredCylinder;
        printf("Current head position: %i\n", head_position);
        currentTime++;
    }

    printf("Total head movements: %i\n", head_movements);   

    return 1;
}