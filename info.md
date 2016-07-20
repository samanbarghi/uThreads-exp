- Scheduler: Intrusive Lock-free runqueue per kThread
- [x] Poller thread timeout without semaphore (usleep(1ms))
- [x] Bulk Push
- [ ] Timed semaphore in poller thread
- [ ] NonBlocking Local poll
- [ ] Yield before read
- [ ] Using a counter with nonblocking polls (uThread)
- [x] No IO Semaphore

---

Poller thread polls in a loop with 1ms timeout and bulk push. Also
kThread does a nonblocking poll whenever it runs out of work, only if it can
acquire the atomic flag.

## poller thread:

```
    while(true){
        blocking_poll();
        usleep(1000);
    }
```

## Blocking context switch in scheduler

```
    if(atomic_flag acquired)
        nonblocking_poll();
```