//
// Created by ahmad on 19/12/2018.
//

#include "SafeQueue.h"

SafeQueue::SafeQueue(int capacity) {
    sem_init(&m_semaphoreFull, 0, 0);
    sem_init(&m_semaphoreEmpty, 0, capacity);
    pthread_mutex_init(&m_mutex, NULL);
}

SafeQueue::~SafeQueue() {}

void SafeQueue::push(void *args) {

    sem_wait(&m_semaphoreEmpty);
    {
        int item = *(int *) args;
        Locker lock(m_mutex);
        std::cout << item << std::endl;
        m_queue.push(item);
    }
    sem_post(&m_semaphoreFull);
}

void SafeQueue::pop() {
    sem_wait(&m_semaphoreFull);
    {
        Locker lock(m_mutex);
        std::cout << m_queue.front() << "XX" << std::endl;
        m_queue.pop();
    }
    sem_post(&m_semaphoreEmpty);
}

int SafeQueue::front() {
    Locker lock(m_mutex);
    return m_queue.front();
}
//
//int main(){
//    SafeQueue s(5);
//    int x = 5, y = 10;
//    s.push(&x);
//    s.push(&x);
//    s.push(&x);
//    s.push(&y);
//    int i ;
//    for(i = 0 ; i < 4; i++) {
//        std::cout << s.front() << std::endl;
//        s.pop();
//    }
//    return 0;
//}