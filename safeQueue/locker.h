//
// Created by ahmad on 20/12/2018.
//

#ifndef PTHREAD_PRODUCER_CONSUMER_LOCKER_H
#define PTHREAD_PRODUCER_CONSUMER_LOCKER_H

#include <iostream>
#include <pthread.h>

class Locker{
public:
    Locker(pthread_mutex_t &mutex);
    ~Locker();
//    void get() ;
private:
    pthread_mutex_t* p_m_mutex;

};
#endif //PTHREAD_PRODUCER_CONSUMER_LOCKER_H
