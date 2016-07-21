- Scheduler: Intrusive Lock-free runqueue per kThread
- [ ] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [ ] Timed semaphore in poller thread
- [x] NonBlocking Local poll
- [x] Yield before read
- [x] Using a counter with nonblocking polls (uThread)
- [x] IO Semaphore

---

Poller thread polls only when a kThread is out of work, and at every context
switch. Also, before every read command there is a yield. An epoch counter is
added to uThreads to decrease the number of polls.

## Poller thread

```
    while(true){
        sem.wait();
        sem.post();
        if(atomic_flag acquired){
            ++pollUTCounter;
            blocking_poll();
        }
    }
```

## Blocking context switch in scheduler
```
    io.sem.post();
    own.sem.wait();
    io.sem.wait();

    ...
```

## Every context switch
```
        if(ut.pollCounter == pollUTCounter && atomic_flag acquired){
            ++pollUTCounter;
            nonblocking_poll();
        }
        ut.pollCounter = pollUTCounter;

```