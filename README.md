# thread-safe queue

One problem that multi-threaded code needs to face again and again is how to pass data from one thread to another. For example, a common way to parallelize serial algorithms is to divide them into blocks and make a pipe. Any piece of the pipeline can be run in a single thread. After each phase is completed, the data is given to the input queue of the next stage.

Basic Thread Safety uses mutex for simple thread safety
The easiest way is to encapsulate a non-thread-safe queue and protect it with mutex 

If more than one thread receives data from the queue, the current design will be subject to race conditions, and empty, front, and pop will compete with each other. But for a consumer system it will be fine. But if the queue is empty, multiple threads may have nothing to do, and thats why semaphores were used

In order to lock the mutex more efficiently, I wrapped the mutex in a class that lock the mutex in the constructer and unlock it in the destructor (locker class), using this strategy I will be able to unlock the mutex no matter what, even if an error occurred to a thread after looking the mutex -- the destructor will be called and the mutex will be free to other thread to use






