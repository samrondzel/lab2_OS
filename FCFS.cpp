#include "stdio.h"
#include "stdlib.h"

int main(void){

    int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int requestsSize = 8;

    int head_movements = 0;
    int head_position = 53;

    for(int i = 0; i < requestsSize; i++){
        head_movements +=  abs(requests[i] - head_position);
        head_position = requests[i];
    }

    printf("Total head movements: %i\n", head_movements);

    return 1;
}