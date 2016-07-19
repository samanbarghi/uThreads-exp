- Scheduler: Intrusive Lock-free runqueue per kThread
- [ ] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [ ] Timed semaphore in poller thread
- [x] NonBlocking Local poll
- [ ] Yield before read
- [ ] Using a counter with nonblocking polls (uThread)
- [ ] No IO Semaphore

---

Poller thread polls only when a kThread is out of work

## Poller thread

```
    while(true){
        sem.wait();
        sem.post();
        if(atomic_flag acquired)
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

## Every context switch
```
        if(atomic_flag acquired)
            nonblocking_poll();

```