/*
 * Authors (alphabetical order)
 * - Bertrand Songis <bsongis@gmail.com>
 * - Martin Hotar <mhotar@gmail.com>
 *
 * opentx is based on code named
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

#include "../opentx.h"

enum PolishPrompts {
  PL_PROMPT_NUMBERS_BASE = 0,
  PL_PROMPT_ZERO = PL_PROMPT_NUMBERS_BASE+0,    //0-99
  PL_PROMPT_STO = PL_PROMPT_NUMBERS_BASE+100,   //100,200 .. 900
  PL_PROMPT_TISIAC = PL_PROMPT_NUMBERS_BASE+109, //1000
  PL_PROMPT_TISIACE = PL_PROMPT_NUMBERS_BASE+110,
  PL_PROMPT_JEDNA = PL_PROMPT_NUMBERS_BASE+111,
  PL_PROMPT_JEDNO = PL_PROMPT_NUMBERS_BASE+112,
  PL_PROMPT_DWIE = PL_PROMPT_NUMBERS_BASE+113,
  PL_PROMPT_CALA = PL_PROMPT_NUMBERS_BASE+114,
  PL_PROMPT_CALE = PL_PROMPT_NUMBERS_BASE+115,
  PL_PROMPT_CALYCH = PL_PROMPT_NUMBERS_BASE+116,
  PL_PROMPT_MINUS = PL_PROMPT_NUMBERS_BASE+117,
  PL_PROMPT_DZIESIATKI_ZENSKIE=PL_PROMPT_NUMBERS_BASE+120, // 22(0122.wav),32(123.wav),42,52,62,72,82,92(129.wav) - this are special female numbers when the unit is female

  PL_PROMPT_UNITS_BASE = 160,
  PL_PROMPT_VOLTS = PL_PROMPT_UNITS_BASE+UNIT_VOLTS, //(jeden)wolt,(dwa)wolty,(piec+)woltów i tak dla wszytkich unitów
  PL_PROMPT_AMPS = PL_PROMPT_UNITS_BASE+(UNIT_AMPS*4),
  PL_PROMPT_METERS_PER_SECOND = PL_PROMPT_UNITS_BASE+(UNIT_METERS_PER_SECOND*4),
  PL_PROMPT_SPARE1 = PL_PROMPT_UNITS_BASE+(UNIT_RAW*4),
  PL_PROMPT_KMH = PL_PROMPT_UNITS_BASE+(UNIT_KMH*4),
  PL_PROMPT_METERS = PL_PROMPT_UNITS_BASE+(UNIT_METERS*4),
  PL_PROMPT_DEGREES = PL_PROMPT_UNITS_BASE+(UNIT_DEGREES*4),
  PL_PROMPT_PERCENT = PL_PROMPT_UNITS_BASE+(UNIT_PERCENT*4),
  PL_PROMPT_MILLIAMPS = PL_PROMPT_UNITS_BASE+(UNIT_MILLIAMPS*4),
  PL_PROMPT_MAH = PL_PROMPT_UNITS_BASE+(UNIT_MAH*4),
  PL_PROMPT_WATTS = PL_PROMPT_UNITS_BASE+(UNIT_WATTS*4),
  PL_PROMPT_DB = PL_PROMPT_UNITS_BASE+(UNIT_DBM*4),
  PL_PROMPT_FEET = PL_PROMPT_UNITS_BASE+(UNIT_FEET*4),
  PL_PROMPT_KTS = PL_PROMPT_UNITS_BASE+(UNIT_KTS*4),
  PL_PROMPT_HOURS = PL_PROMPT_UNITS_BASE+(UNIT_HOURS*4),
  PL_PROMPT_MINUTES = PL_PROMPT_UNITS_BASE+(UNIT_MINUTES*4),
  PL_PROMPT_SECONDS = PL_PROMPT_UNITS_BASE+(UNIT_SECONDS*4),
  PL_PROMPT_RPMS = PL_PROMPT_UNITS_BASE+(UNIT_RPMS*4),
  PL_PROMPT_G = PL_PROMPT_UNITS_BASE+(UNIT_G*4),
 
  PL_PROMPT_LABELS_BASE = 250,
  PL_PROMPT_TIMER1 = PL_PROMPT_LABELS_BASE+TELEM_TM1,
  PL_PROMPT_TIMER2 = PL_PROMPT_LABELS_BASE+TELEM_TM2,
  PL_PROMPT_RSSI_TX = PL_PROMPT_LABELS_BASE+TELEM_RSSI_TX,
  PL_PROMPT_RSSI_RX = PL_PROMPT_LABELS_BASE+TELEM_RSSI_RX,
  PL_PROMPT_A1 = PL_PROMPT_LABELS_BASE+TELEM_A1,
  PL_PROMPT_A2 = PL_PROMPT_LABELS_BASE+TELEM_A2,
  PL_PROMPT_ALTITUDE = PL_PROMPT_LABELS_BASE+TELEM_ALT,
  PL_PROMPT_RPM = PL_PROMPT_LABELS_BASE+TELEM_RPM,
  PL_PROMPT_ESSENCE = PL_PROMPT_LABELS_BASE+TELEM_FUEL,
  PL_PROMPT_T1 = PL_PROMPT_LABELS_BASE+TELEM_T1,
  PL_PROMPT_T2 = PL_PROMPT_LABELS_BASE+TELEM_T2,
  PL_PROMPT_VITESSE = PL_PROMPT_LABELS_BASE+TELEM_SPEED,
  PL_PROMPT_DISTANCE = PL_PROMPT_LABELS_BASE+TELEM_DIST,
  PL_PROMPT_GPSALTITUDE = PL_PROMPT_LABELS_BASE+TELEM_GPSALT,
  PL_PROMPT_ELEMENTS_LIPO = PL_PROMPT_LABELS_BASE+TELEM_CELL,
  PL_PROMPT_TOTAL_LIPO = PL_PROMPT_LABELS_BASE+TELEM_CELLS_SUM,
  PL_PROMPT_VFAS = PL_PROMPT_LABELS_BASE+TELEM_VFAS,
  PL_PROMPT_COURANT = PL_PROMPT_LABELS_BASE+TELEM_CURRENT,
  PL_PROMPT_CONSOMMATION = PL_PROMPT_LABELS_BASE+TELEM_CONSUMPTION,
  PL_PROMPT_PUISSANCE = PL_PROMPT_LABELS_BASE+TELEM_POWER,
  PL_PROMPT_ACCELx = PL_PROMPT_LABELS_BASE+TELEM_ACCx,
  PL_PROMPT_ACCELy = PL_PROMPT_LABELS_BASE+TELEM_ACCy,
  PL_PROMPT_ACCELz = PL_PROMPT_LABELS_BASE+TELEM_ACCz,
  PL_PROMPT_HDG = PL_PROMPT_LABELS_BASE+TELEM_HDG,
  PL_PROMPT_VARIO = PL_PROMPT_LABELS_BASE+TELEM_VSPD,
 
};

#if defined(VOICE)

#if defined(CPUARM)
  #define PL_PUSH_UNIT_PROMPT(p, u) pl_pushUnitPrompt((p), (u), id)
#else
  #define PL_PUSH_UNIT_PROMPT(p, u) pushUnitPrompt((p), (u))
#endif

#define MESKI 0x80
#define ZENSKI 0x81
#define NIJAKI 0x82

I18N_PLAY_FUNCTION(pl, pushUnitPrompt, int16_t number, uint8_t unitprompt)
{
#if defined(SIMU)
  printf("numer do powiedzenia %d",number); 
#endif
  if (number == 1)
    PUSH_NUMBER_PROMPT(unitprompt);
  else if (number > 1 && number < 5)
    PUSH_NUMBER_PROMPT(unitprompt+1);
  else {
    int test_2 =0;
    test_2 =number % 10;
    int dziesiatka=0;
    dziesiatka=(number - (number % 10))/10;
    if ((test_2 > 1 && test_2 < 5) && dziesiatka >2)
	PUSH_NUMBER_PROMPT(unitprompt+1);
    else
	PUSH_NUMBER_PROMPT(unitprompt+2);
    }
}

I18N_PLAY_FUNCTION(pl, playNumber, getvalue_t number, uint8_t unit, uint8_t att)
{

  if (number < 0) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_MINUS);
    number = -number;
  }

  if (unit) {
    unit--;
    convertUnit(number, unit);
    if (IS_IMPERIAL_ENABLE()) {
      if (unit == UNIT_METERS) {
        unit = UNIT_FEET;
      }
    }
#if defined(CPUARM)
    if ((att & PREC1) && (unit == UNIT_FEET || (unit == UNIT_METERS && number >= 100))) {
      number /= 10;
      att -= PREC1;
    }
#endif
    unit++;
  }

  int8_t mode = MODE(att);
  if (mode > 0) {
    // we assume that we are PREC1
    div_t qr = div(number, 10);   
      if (qr.rem) {
        PLAY_NUMBER(qr.quot, 0, ZENSKI);
        if (qr.quot == 0)
          PUSH_NUMBER_PROMPT(PL_PROMPT_CALA);
        else
          PL_PUSH_UNIT_PROMPT(qr.quot, PL_PROMPT_CALA);
        PLAY_NUMBER(qr.rem, 0, ZENSKI);
        PUSH_NUMBER_PROMPT(PL_PROMPT_UNITS_BASE+((unit-1)*4)+3);
        return;
      }
      else
        number = qr.quot;
  }

  int16_t tmp = number;
  
  switch(unit) {
    case 0:
      break;
    case 10:
    case 13:
    case 15:
    case 16:
    case 17:
      att = ZENSKI;
      break;
    case 100:
      att = NIJAKI;
      break;
    default:
      att = MESKI;
      break;
  }

  if ((number == 1) && (att == ZENSKI)) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_JEDNA);
    number = -1;
  }
  
  if ((number == 1) && (att == NIJAKI)) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_JEDNO);
    number = -1;
  }
  
  if ((number == 2) && (att == ZENSKI)) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_DWIE);
    number = -1;
  }
  




  if (number >= 1000) {
    if (number >= 2000) 
      PLAY_NUMBER(number / 1000, 0, 0);
    if (number >= 2000 && number < 5000)
      PUSH_NUMBER_PROMPT(PL_PROMPT_TISIACE);
    else
      PUSH_NUMBER_PROMPT(PL_PROMPT_TISIAC);
    number %= 1000;
    if (number == 0)
      number = -1;
  }
  if (number >= 100) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_STO + (number/100)-1);
    number %= 100;
    if (number == 0)
      number = -1;
  }
  
  if (number >= 0) {
    int test_2 =0;
    test_2 =number % 10;
    int dziesiatka=0;
    dziesiatka=(number - (number % 10))/10;
#if defined(SIMU)
    printf("dziesiatki %d - %d ==== ",dziesiatka,test_2);
#endif
    if (att == ZENSKI && test_2==2 && dziesiatka >= 2 ) {
      
      PUSH_NUMBER_PROMPT(PL_PROMPT_DZIESIATKI_ZENSKIE+dziesiatka);
    }else 
       PUSH_NUMBER_PROMPT(PL_PROMPT_ZERO+number);
  }

  if (unit) {
    PL_PUSH_UNIT_PROMPT(tmp, (PL_PROMPT_UNITS_BASE+((unit-1)*4)));
  }
}


// The whole funtion has to be changed
I18N_PLAY_FUNCTION(pl, playDuration, int16_t seconds)
{
  if (seconds < 0) {
    PUSH_NUMBER_PROMPT(PL_PROMPT_MINUS);
    seconds = -seconds;
  }

  uint8_t tmp = seconds / 3600;
  seconds %= 3600;
  if (tmp > 0) {
    PLAY_NUMBER(tmp, UNIT_HOURS+1, ZENSKI);
  }

  tmp = seconds / 60;
  seconds %= 60;
  if (tmp > 0) {
    PLAY_NUMBER(tmp, UNIT_MINUTES+1, ZENSKI);
  }

  if (seconds > 0) {
    PLAY_NUMBER(seconds, UNIT_SECONDS+1, ZENSKI);
  }
}

LANGUAGE_PACK_DECLARE(pl, "Polish");

#endif
