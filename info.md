- Scheduler: Intrusive Lock-free runqueue per kThread
- [x] Poller thread timeout without semaphore (usleep(1ms))
- [ ] Bulk Push
- [ ] Timed semaphore in poller thread
- [ ] NonBlocking Local poll
- [ ] Yield before read
- [ ] Using a counter with nonblocking polls (uThread)
- [x] No IO Semaphore

---

Poller thread polls in a loop with 1ms timeout.

poller thread:

while(true){
    poll(-1,0);
    usleep(1000);
}