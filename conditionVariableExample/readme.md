# examples of conditional variable

### 0. procedure of using conditional variable

```c++
cv.wait(lk, []{return CONDITION;});
```
`cv` evaluates `condition`. If `condition` is `True`,
jumps to the next line. Else, releases the lock and 
blocks itself. When another thread invokes `cv.nofity()`,
the current thread is awake and evaluates `condition`: repeats
the above step. 

### 1. example 1

t4 sends signal, t1 & t2 & t3 creates the unique lock.
```c++
std::unique_lock<std::mutex> lk(cv_m);
```
This line of code acquires the lock. An instance of the procedure
is:


*  t1 aquires the lock, t2 and t3 are blocked(waiting for the lock).
*  t1 runs the line of conditional variable, finding the condition isn't
satisfied. t1 releases the lock and is blocked(waiting for cv.nofity)
*  t2 acquires the lock, t3 are still blocked(waiting for the lock).
*  t2 runs the line of conditional variable, finding the condition isn't
satisfied. t2 releases the lock and is blocked(waiting for cv.nofity)
*  t3 acquires the lock.
*  t3 runs the line of conditional variable, finding the condition isn't
satisfied. t3 releases the lock and is blocked(waiting for cv.nofity)
*  t4 notifies t1, t2 and t3.
*  t1, t2 and t3 wake up at the same time. All of them find
that the condition is satisfied, so all of them try to acquires 
the lock again.
*  t1 acquires the lock, t2 and t3 are blocked(waiting for the lock).
*  t1 exits and releases the lock. t2 acquires the lock, t3 are boocked(waiting for the lock).
*  t2 exits and releases the lock. t3 acquires the lock.

### 2. example 2
This is an example of producer and consumer.

* Consumer runs first. Acquires the lock and evaluates the condition.
The condition isn't satisfied. Therefore, the consumer releases
the lock and is blocked. 
* Producer runs second. Generates data and wakes consumer up. 
* Consumer wakes up and evaluates the condition. The condition
is True, so consumer consumes data. 

### 3. example 3
to be continued...