## semaphore

### sem_init(sem_t * sem, int pshared, unsigned int value)

* pshared
```
If pshared has the value 0, then the semaphore is shared between
the threads of a process, and should be located at some address
that is visible to all threads (e.g., a global variable, or a
variable allocated dynamically on the heap).

If pshared is nonzero, then the semaphore is shared between
processes, and should be located in a region of shared memory
(see shm_open(3), mmap(2), and shmget(2)).  (Since a child
created by fork(2) inherits its parent's memory mappings, it can
also access the semaphore.)  Any process that can access the
shared memory region can operate on the semaphore using
sem_post(3), sem_wait(3), and so on.
```
* value
```
value in sem_init() means how many times we could execute 
sem_wait() without really waiting without any sem_post().
```
