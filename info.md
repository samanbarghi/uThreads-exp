- Scheduler: Intrusive Lock-free runqueue per kThread
- [ ] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [x] Timed semaphore in poller thread: 5ms
- [ ] NonBlocking Local poll
- [x] Yield before read
- [ ] Using a counter with nonblocking polls (uThread)
- [x] IO Semaphore

---

Poller thread polls only when a kThread is out of work,
or semaphore timer is expired (5ms). Yield before run.

## Poller thread

```
    while(true){
        //if timer is not expired, post
        if(!sem.timedwait(ts))
            sem.post();
        else{
            clock_gettime(CLOCK_REALTIME, &ts);
            ts.tv_nsec += 5000000;
            if (ts.tv_nsec >= BILLION) {
              ts.tv_nsec -= BILLION;
              ts.tv_sec += 1;
            }
        }
        blocking_poll();
    }
```

## Blocking context switch in scheduler
```
    io.sem.post();
    own.sem.wait();
    io.sem.wait();

    ...
```