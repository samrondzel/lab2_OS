#include "stdio.h"
#include "stdlib.h"

int main(void){

    int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int requestsSize = 8;
    int requestsIndexer = requestsSize - 1;

    int head_movements = 0, head_position = 53;
    bool goLeft = true, goRight = false;
    int leftBorder = 0, rightBorder = 199;


    while(requestsSize>0){
        for(int i = 0; i < requestsSize; i++){
            if(requests[i]==head_position){
                if(requestsSize>1){
                    int temp = requests[i];
                    requests[i] = requests[requestsIndexer];
                    requests[requestsIndexer--] = temp;
                }
                requestsSize--;
            }
        }

        if(requestsSize==0)
            break;
        
        if(head_position == leftBorder){
            goLeft = false;
            goRight = true;
        }else if(head_position == rightBorder){
            goLeft = true;
            goRight = false;
        }

        if(goLeft){
            head_position--;
        }else if(goRight){
            head_position++;
        }
        head_movements++;

    }

    printf("Total head movements: %i\n", head_movements);   

    return 1;
}