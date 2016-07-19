- Scheduler: Intrusive Lock-free runqueue per kThread
- [x] Poller thread timeout without semaphore (usleep(5000))
- [ ] Bulk Push
- [ ] Timed semaphore in poller thread
- [ ] NonBlocking Local poll
- [ ] Yield before read
- [ ] Using a counter with nonblocking polls (uThread)
- [x] No IO Semaphore

---

Poller thread polls in a loop with 5ms timeout.

## poller thread:

```
    while(true){
        blocking_poll();
        usleep(5000);
    }
```