//
// Created by ahmad on 20/12/2018.
//

#include "locker.h"

pthread_mutex_t m;

Locker::Locker(pthread_mutex_t &mutex) {
    p_m_mutex = &mutex;
    pthread_mutex_lock(p_m_mutex);
}

Locker::~Locker() {
    pthread_mutex_unlock(p_m_mutex);
}
//
//void Locker::get() {
//    std::cout << "in" << std::endl;
//}
//void *do_the_fucking_job(void* args){
//
//    Locker x(m);
//    x.get();
//    return 0;
//}
//int main() {
//
//    pthread_t t0;
//    pthread_t t1;
//    pthread_mutex_init(&m, 0);
//
//
//    pthread_create(&t1, 0, do_the_fucking_job, 0);
//    pthread_create(&t0, 0, do_the_fucking_job, 0);
//
//
//    pthread_join(t0, NULL);
//    pthread_join(t1, NULL);
//
//    std::cout << "TEXE " << std::endl;
//    return 0;
//}