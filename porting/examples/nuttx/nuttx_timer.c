
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include "os/os.h"
#include "hal/hal_timer.h"
#include "os/os_trace_api.h"
/**
 *
 * Initialize the HAL timer structure with the callback and the callback
 * argument. Also initializes the HW specific timer pointer.
 *
 * @param cb_func
 *
 * @return int
 */
int
hal_timer_set_cb(int timer_num, struct hal_timer *timer, hal_timer_cb cb_func,
                 void *arg)
{
    // int rc;
    // struct nrf52_hal_timer *bsptimer;

    // NRF52_HAL_TIMER_RESOLVE(timer_num, bsptimer);

    // timer->cb_func = cb_func;
    // timer->cb_arg = arg;
    // timer->link.tqe_prev = NULL;
    // timer->bsp_timer = bsptimer;

    // rc = 0;

    // err:
    // return rc;
}

int
hal_timer_start_at(struct hal_timer *timer, uint32_t tick)
{
    // os_sr_t sr;
    // struct hal_timer *entry;
    // struct nrf52_hal_timer *bsptimer;

    // if ((timer == NULL) || (timer->link.tqe_prev != NULL) ||
    //     (timer->cb_func == NULL)) {
    //     return EINVAL;
    // }
    // bsptimer = (struct nrf52_hal_timer *)timer->bsp_timer;
    // timer->expiry = tick;

    // OS_ENTER_CRITICAL(sr);

    // if (TAILQ_EMPTY(&bsptimer->hal_timer_q)) {
    //     TAILQ_INSERT_HEAD(&bsptimer->hal_timer_q, timer, link);
    // } else {
    //     TAILQ_FOREACH(entry, &bsptimer->hal_timer_q, link) {
    //         if ((int32_t)(timer->expiry - entry->expiry) < 0) {
    //             TAILQ_INSERT_BEFORE(entry, timer, link);
    //             break;
    //         }
    //     }
    //     if (!entry) {
    //         TAILQ_INSERT_TAIL(&bsptimer->hal_timer_q, timer, link);
    //     }
    // }

    // /* If this is the head, we need to set new OCMP */
    // if (timer == TAILQ_FIRST(&bsptimer->hal_timer_q)) {
    //     nrf_timer_set_ocmp(bsptimer, timer->expiry);
    // }

    // OS_EXIT_CRITICAL(sr);

    // return 0;
}

/**
 * hal timer stop
 *
 * Stop a timer.
 *
 * @param timer
 *
 * @return int
 */
int
hal_timer_stop(struct hal_timer *timer)
{
    // os_sr_t sr;
    // int reset_ocmp;
    // struct hal_timer *entry;
    // struct nrf52_hal_timer *bsptimer;

    // if (timer == NULL) {
    //     return EINVAL;
    // }

    // bsptimer = (struct nrf52_hal_timer *)timer->bsp_timer;

    // OS_ENTER_CRITICAL(sr);

    // if (timer->link.tqe_prev != NULL) {
    //     reset_ocmp = 0;
    //     if (timer == TAILQ_FIRST(&bsptimer->hal_timer_q)) {
    //         /* If first on queue, we will need to reset OCMP */
    //         entry = TAILQ_NEXT(timer, link);
    //         reset_ocmp = 1;
    //     }
    //     TAILQ_REMOVE(&bsptimer->hal_timer_q, timer, link);
    //     timer->link.tqe_prev = NULL;
    //     if (reset_ocmp) {
    //         if (entry) {
    //             nrf_timer_set_ocmp((struct nrf52_hal_timer *)entry->bsp_timer,
    //                                entry->expiry);
    //         } else {
    //             if (bsptimer->tmr_rtc) {
    //                 nrf_rtc_disable_ocmp((NRF_RTC_Type *)bsptimer->tmr_reg);
    //             } else {
    //                 nrf_timer_disable_ocmp(bsptimer->tmr_reg);
    //             }
    //         }
    //     }
    // }

    // OS_EXIT_CRITICAL(sr);

    // return 0;
}


static uint32_t
hal_timer_read_bsptimer(struct nrf52_hal_timer *bsptimer)
{
    // uint32_t low32;
    // os_sr_t sr;
    // uint32_t tcntr;
    // NRF_RTC_Type *rtctimer;

    // rtctimer = (NRF_RTC_Type *)bsptimer->tmr_reg;
    // OS_ENTER_CRITICAL(sr);
    // tcntr = bsptimer->tmr_cntr;
    // low32 = rtctimer->COUNTER;
    // if (rtctimer->EVENTS_OVRFLW) {
    //     tcntr += (1UL << 24);
    //     bsptimer->tmr_cntr = tcntr;
    //     low32 = rtctimer->COUNTER;
    //     rtctimer->EVENTS_OVRFLW = 0;
    //     NVIC_SetPendingIRQ(bsptimer->tmr_irq_num);
    // }
    // tcntr |= low32;
    // OS_EXIT_CRITICAL(sr);

    // return tcntr;
}

/**
 * hal timer read
 *
 * Returns the timer counter. NOTE: if the timer is a 16-bit timer, only
 * the lower 16 bits are valid. If the timer is a 64-bit timer, only the
 * low 32-bits are returned.
 *
 * @return uint32_t The timer counter register.
 */
uint32_t
hal_timer_read(int timer_num)
{
    // int rc;
    // uint32_t tcntr;
    // struct nrf52_hal_timer *bsptimer;

    // NRF52_HAL_TIMER_RESOLVE(timer_num, bsptimer);
    // if (bsptimer->tmr_rtc) {
    //     tcntr = hal_timer_read_bsptimer(bsptimer);
    // } else {
    //     tcntr = nrf_read_timer_cntr(bsptimer->tmr_reg);
    // }

    // return tcntr;

    // /* Assert here since there is no invalid return code */
    // err:
    // assert(0);
    // rc = 0;
    // return rc;
}
