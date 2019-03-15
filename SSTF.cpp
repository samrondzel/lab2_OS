#include "stdio.h"
#include "stdlib.h"

int main(void){

    int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int requestsSize = 8;
    int requestsIndexer = requestsSize - 1;

    int head_movements = 0;
    int head_position = 53;

    while(requestsSize>0){
        int SST_position = 0;
        int SST_movements = abs(requests[SST_position]-head_position);

        for(int i = 0; i < requestsSize; i++){
            if(SST_movements > abs(requests[i]-head_position)){
                SST_movements = abs(requests[i]-head_position);
                SST_position = i;
            }
        }
        head_movements+=SST_movements;
        head_position = requests[SST_position];
        if(SST_position!=requestsIndexer)
            requests[SST_position] = requests[requestsIndexer--];
        else
            requestsIndexer--;
        requestsSize--;
    }

    printf("Total head movements: %i\n", head_movements);   

    return 1;
}