
void displayTime(void) {

  // get time from the RTC
  DateTime now = RTC.now();
  
  
  //DateTime now;
/*
  // serial print current time
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
*/
  // turn everything off
  watch.fillScreen(0);

  // now we display the appropriate now.minute() counter
  if ((now.minute()>4) && (now.minute()<10)) { 
    MFIVE; 
  } 
  if ((now.minute()>9) && (now.minute()<15)) { 
    MTEN; 
  }
  if ((now.minute()>14) && (now.minute()<20)) {
    AQUARTER; 
  }
  if ((now.minute()>19) && (now.minute()<25)) { 
    TWENTY; 
  }
  if ((now.minute()>24) && (now.minute()<30)) { 
    TWENTY; 
    MFIVE; 
  }  
  if ((now.minute()>29) && (now.minute()<35)) {
    HALF;
  }
  if ((now.minute()>34) && (now.minute()<40)) { 
    TWENTY; 
    MFIVE; 
  }  
  if ((now.minute()>39) && (now.minute()<45)) { 
    TWENTY; 
  }
  if ((now.minute()>44) && (now.minute()<50)) {
    AQUARTER; 
  }
  if ((now.minute()>49) && (now.minute()<55)) { 
    MTEN; 
  } 
  if (now.minute()>54) { 
    MFIVE; 
  }

  if ((now.minute() <5))
  {
    switch (now.hour()) {
    case 1:
    case 13: 
      ONE; 
      break;
    case 2:
    case 14: 
      TWO; 
      break;
    case 3: 
    case 15:
      THREE; 
      break;
    case 4: 
    case 16:
      FOUR; 
      break;
    case 5: 
    case 17:
      FIVE; 
      break;
    case 6: 
    case 18:
      SIX; 
      break;
    case 7: 
    case 19:
      SEVEN; 
      break;
    case 8: 
    case 20:
      EIGHT; 
      break;
    case 9: 
    case 21:
      NINE; 
      break;
    case 10:
    case 22: 
      TEN; 
      break;
    case 11:
    case 23: 
      ELEVEN; 
      break;
    case 0:
    case 12: 
      TWELVE; 
      break;
    }
    //OCLOCK;
  }
  else
    if ((now.minute() < 35) && (now.minute() >4))
    {
      PAST;
      switch (now.hour()) {
      case 1:
      case 13: 
        ONE; 
        break;
      case 2: 
      case 14:
        TWO; 
        break;
      case 3: 
      case 15:
        THREE; 
        break;
      case 4: 
      case 16:
        FOUR; 
        break;
      case 5: 
      case 17:
        FIVE; 
        break;
      case 6: 
      case 18:
        SIX; 
        break;
      case 7: 
      case 19:
        SEVEN; 
        break;
      case 8: 
      case 20:
        EIGHT; 
        break;
      case 9: 
      case 21:
        NINE; 
        break;
      case 10:
      case 22: 
        TEN; 
        break;
      case 11:
      case 23: 
        ELEVEN; 
        break;
      case 0:
      case 12: 
        TWELVE; 
        break;
      }
    }
    else
    {
      // if we are greater than 34 minutes past the hour then display
      // the next hour, as we will be displaying a 'to' sign
      TO;
      switch (now.hour()) {
      case 1: 
      case 13:
        TWO; 
        break;
      case 14:
      case 2: 
        THREE; 
        break;
      case 15:
      case 3: 
        FOUR; 
        break;
      case 4: 
      case 16:
        FIVE; 
        break;
      case 5: 
      case 17:
        SIX; 
        break;
      case 6: 
      case 18:
        SEVEN; 
        break;
      case 7: 
      case 19:
        EIGHT; 
        break;
      case 8: 
      case 20:
        NINE; 
        break;
      case 9: 
      case 21:
        TEN; 
        break;
      case 10: 
      case 22:
        ELEVEN; 
        break;
      case 11: 
      case 23:
        TWELVE; 
        break;
      case 0:
      case 12: 
        ONE; 
        break;
      }
    }
  //watch.writeDisplay();

}









