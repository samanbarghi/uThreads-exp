/*
 * Scheduler.h
 *
 *  Created on: May 4, 2016
 *      Author: Saman Barghi
 */

#ifndef SRC_RUNTIME_SCHEDULERS_SCHEDULER_H_
#define SRC_RUNTIME_SCHEDULERS_SCHEDULER_H_

#if SCHEDULERNO == 1
#include "Scheduler_01.h"
#elif SCHEDULERNO == 2
#include "Scheduler_02.h"
#endif


#endif /* SRC_RUNTIME_SCHEDULERS_SCHEDULER_H_ */