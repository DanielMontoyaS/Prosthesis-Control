/*
 *
 * Prosthesis Control (Servo fingers)
 *
 * Date           Author
 * 2022-11-10     Daniel Montoya/Victor Asanza

 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define PWM_DEV_NAME_2        "pwm2" /* PWM 2  */
#define PWM_DEV_CHANNEL_2_1     1 /* Channel 2  PWM2   */
#define PWM_DEV_CHANNEL_2_3     3 /* Channel 3  PWM2  */

#define PWM_DEV_NAME_3       "pwm3" /* PWM 3 */
#define PWM_DEV_CHANNEL_3_1     1 /* Channel 1  PWM3   */
#define PWM_DEV_CHANNEL_3_2     2 /* Channel 2  PWM3   */


struct rt_device_pwm *pwm_dev2; /* Handle PWM 2  */

struct rt_device_pwm *pwm_dev3; /* Handle PWM 3  */

void main(void)
{
    rt_uint32_t period, pos1,pos2;

    period = 20000000; /* Period for servo MG90S */

    pos1 = 700000; /* PWM Pulse   blunt   wide   degree   value ,  single   position   by   nanosecond ns */

    pos2 = 2000000;/* PWM Pulse   blunt   wide   degree   value ,  single   position   by   nanosecond ns */

    pwm_dev2 = (struct rt_device_pwm *)rt_device_find(PWM_DEV_NAME_2);

    pwm_dev3 = (struct rt_device_pwm *)rt_device_find(PWM_DEV_NAME_3);

    /*  Set up PWM  */

    rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_1, period, pos2);
    rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_3, period, pos1);
    rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_1, period, pos2);
    rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_2, period, pos1);

    /*  Enable Channel  */
    rt_pwm_enable(pwm_dev2, PWM_DEV_CHANNEL_2_1);
    rt_pwm_enable(pwm_dev2, PWM_DEV_CHANNEL_2_3);
    rt_pwm_enable(pwm_dev3, PWM_DEV_CHANNEL_3_1);
    rt_pwm_enable(pwm_dev3, PWM_DEV_CHANNEL_3_2);


    while (1)
    {

        rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_1, period, pos2);/*Thumb*/
        rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_3, period, pos1);/*Middle*/
        rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_1, period, pos2);/* Index*/
        rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_2, period, pos1);/*Ring / Little */


        rt_kprintf("Abierto");

        rt_thread_mdelay(5000);

        rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_1, period, pos1);/*Thumb*/
        rt_pwm_set(pwm_dev2, PWM_DEV_CHANNEL_2_3, period, pos2);/*Middle*/
        rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_1, period, pos1);/* Index*/
        rt_pwm_set(pwm_dev3, PWM_DEV_CHANNEL_3_2, period, pos2); /*Ring / Little */



         rt_kprintf("Cerrada");
        rt_thread_mdelay(5000);


    }
}

