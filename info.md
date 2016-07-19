- Scheduler: Intrusive Lock-free runqueue per kThread
- [ ] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [ ] Timed semaphore in poller thread
- [ ] NonBlocking Local poll
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
        poll(-1,0);
    }
```

## Blocking context switch in scheduler
```
    io.sem.post();
    own.sem.wait();
    io.sem.wait();

    ...
```