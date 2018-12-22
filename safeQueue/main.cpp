
#define NUMBER_TO_PUSH 5
#define NUMBER_TO_POP 2

#define ERROR_CODE 255

#include "SafeQueue.h"
#include <iostream>

int capacity = 4;
SafeQueue safe_q(capacity);


void *pop(void *args) {
    safe_q.pop();
    return 0;
}

void *push(void *args) {
    safe_q.push(args);
    return 0;
}


int main() {
    if ( NUMBER_TO_PUSH < NUMBER_TO_POP) {
        std::cout << "Cant pop more than we push" << std::endl;
        exit(ERROR_CODE);
    }

    int vars[5] = {1, 2, 3, 4, 5};

    pthread_t pushers_id[NUMBER_TO_PUSH];
    pthread_t popers_id[NUMBER_TO_POP];
    int index;

    srand(time(NULL));
    for (index = 0; index < NUMBER_TO_PUSH; ++index) {
        if (pthread_create(&pushers_id[index], NULL, push, (void *) &vars[index])) {
            perror("Pthread is not created");
        } else {
            pthread_detach(pushers_id[index]);
        }
    }
    /*create a new consumer*/
    for (index = 0; index < NUMBER_TO_POP; ++index) {

        if (pthread_create(&popers_id[index], NULL, pop, 0)) {
            perror("Pthread is not created");
            exit(ERROR_CODE);
        } else {
            if (index != NUMBER_TO_POP - 1)
                pthread_detach(popers_id[index]);
        }
    }
    pthread_join(popers_id[index - 1], NULL);

//    printf("ss\n\n\n\n\n");
//    for (index = 0; index < NUMBER_OF_CONSUMERS ; ++index)
//        pthread_join(consumer_id[index], NULL);
//
//    for (index = 0; index < NUMBER_OF_PRODUCERS; ++index)
//        pthread_join(producer_id[index], NULL);

    pthread_exit(NULL);
    return 0;

}