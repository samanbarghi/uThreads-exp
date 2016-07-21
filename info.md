- Scheduler: Intrusive Lock-free runqueue per kThread
- [x] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [ ] Timed semaphore in poller thread
- [x] NonBlocking Local poll
- [x] Yield before read
- [x] Using a counter with nonblocking polls (uThread)
- [ ] IO Semaphore

---

Poller thread do a nonblocking poll only when a kThread is out of work.
Also, before every read command there is a yield.
An epoch counter is added to poller thread to decrease the number of polls.

## Poller thread

```
    while(true){
        read pollCounter
        usleep(1000)
        if(pollCounter unchanged)
            if(atomic_flag acquired){
                ++pollUTCounter;
                blocking_poll();
            }
    }
```

## Blocking context switch in scheduler
```
    if(atomic_flag acquired){
        pollCounter++;
        nonblocking_poll();
    }
    own.sem.wait();

    ...
```
