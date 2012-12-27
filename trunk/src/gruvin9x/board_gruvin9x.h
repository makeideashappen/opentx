/*
 * Authors (alphabetical order)
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Jean-Pierre Parisy
 * - Karl Szmutny <shadow@privy.de>
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * open9x is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef board_gruvin9x_h
#define board_gruvin9x_h

#define TIMER_16KHZ_VECT TIMER2_OVF_vect
#define COUNTER_16KHZ TCNT2
#define TIMER_10MS_VECT  TIMER2_COMPA_vect
#define PAUSE_10MS_INTERRUPT() TIMSK2 &= ~(1<<OCIE2A)
#define RESUME_10MS_INTERRUPT() TIMSK2 |= (1<<OCIE2A)
#define PAUSE_PULSES_INTERRUPT() TIMSK1 &= ~(1<<OCIE1A)
#define RESUME_PULSES_INTERRUPT() TIMSK1 |= (1<<OCIE1A)
#define PAUSE_PPMIN_INTERRUPT() TIMSK3 &= ~(1<<ICIE3)
#define RESUME_PPMIN_INTERRUPT() TIMSK3 |= (1<<ICIE3)

#define SLAVE_MODE() (PING & (1<<INP_G_RF_POW))
#define JACK_PPM_OUT() PORTG |= (1<<OUT_G_SIM_CTL)
#define JACK_PPM_IN() PORTG &= ~(1<<OUT_G_SIM_CTL)

extern void sdPoll10ms();

#define SPEAKER_ON   TCCR0A |=  (1 << COM0A0)
#define SPEAKER_OFF  TCCR0A &= ~(1 << COM0A0)
#define __BACKLIGHT_ON  PORTC |=  (1 << OUT_C_LIGHT)
#define __BACKLIGHT_OFF PORTC &= ~(1 << OUT_C_LIGHT)
#define IS_BACKLIGHT_ON() (PORTC & (1<<OUT_C_LIGHT))

#endif
