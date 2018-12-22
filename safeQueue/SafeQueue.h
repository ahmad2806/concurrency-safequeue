//
// Created by ahmad on 19/12/2018.
//

#ifndef SAFEQUEUE_SAFEQUEUE_H
#define SAFEQUEUE_SAFEQUEUE_H

#include <iostream>
#include <queue>
#include <pthread.h>
#include <semaphore.h>
#include "locker.h"

class SafeQueue {
public:
    SafeQueue(int capacity);
    ~SafeQueue();
    void pop();
    void push(void *args);
    int front();
private:

    int m_capacity;
    std::queue<int> m_queue;
    pthread_mutex_t m_mutex;
    sem_t m_semaphoreFull;
    sem_t m_semaphoreEmpty;
};

#endif //SAFEQUEUE_SAFEQUEUE_H