/*
 WORD CLOCK 
 by Andy Doro
  
 http://andydoro.com/wordclockwristwatch/
 
 
 grid pattern
 
 A T W E N T Y D
 Q U A R T E R Y 
 F I V E H A L F
 D P A S T O R O
 F I V E I G H T
 S I X T H R E E
 T W E L E V E N
 F O U R N I N E
 
 
 TO DO:
 
 *fix fadeout? 
 
 */

//#define FLASHDELAY 500
//#define CLOCKDELAY 500

// brightness level
byte b = 255;

//#define BRIGHTNESS 1 // 0-15, 15 is maximum

// define how to write each of the words
#define MFIVE watch.drawLine(0,2, 3,2, b)
#define MTEN watch.drawPixel(1,0, b); watch.drawLine(3,0,4,0, b)
#define AQUARTER watch.drawPixel(0,0, b); watch.drawLine(0,1, 6,1, b)
#define TWENTY watch.drawLine(1,0, 6,0, b)
#define HALF watch.drawLine(4,2, 7,2, b)
#define PAST watch.drawLine(1,3, 4,3, b)
#define TO watch.drawLine(4,3, 5,3, b)
#define ONE watch.drawPixel(1,7, b); watch.drawLine(6,7, 7,7, b)
#define TWO watch.drawLine(0,6, 1,6, b); watch.drawPixel(1,7, b)
#define THREE watch.drawLine(3,5, 7,5, b)
#define FOUR watch.drawLine(0,7, 3,7, b)
#define FIVE watch.drawLine(0,4, 3,4, b)
#define SIX watch.drawLine(0,5, 2,5, b)
#define SEVEN watch.drawPixel(0,5, b); watch.drawLine(4,6, 7,6, b)
#define EIGHT watch.drawLine(3,4, 7,4, b)
#define NINE watch.drawLine(4,7, 7,7, b)
#define TEN watch.drawLine(7,4, 7,6, b)
#define ELEVEN watch.drawLine(2,6, 7,6, b)
#define TWELVE watch.drawLine(0,6, 3,6, b); watch.drawLine(5,6, 6,6, b)

#define ANDYDORO watch.drawPixel(0,0, b); watch.drawPixel(4,0, b); watch.drawPixel(7,0, b); watch.drawPixel(7,1, b); watch.drawPixel(0,3, b); watch.drawLine(5,3, 7,3, b)


void mode_wordclock(uint8_t action) {

  //DateTime now;

  if(action != ACTION_NONE) {
    // If we just arrived here (whether through mode change
    // or wake from sleep), initialize the matrix driver:

    //fps = watch.setDisplayMode(6, LED_PLEX_4, true);
    if(action >= ACTION_HOLD_LEFT) {
      uint8_t depth = 6, plex = LED_PLEX_4;
      // Reduce depth/plex if battery voltage is low
      if(watch.getmV() < BATT_LOW_MV) {
        depth = 2;
        plex  = LED_PLEX_1;
      }
      // Reconfigure display if needed
      if((watch.getDepth() != depth) || (watch.getPlex() != plex))
        fps = watch.setDisplayMode(depth, plex, true);

      // get time from the RTC
      //DateTime now = RTC.now();
    }


    // Reset sleep timeout on ANY button action
    watch.setTimeout(fps * 5);

  }

  uint16_t t = watch.getTimeout();
  b = (t < sizeof(fade)) ? (uint8_t)pgm_read_byte(&fade[t]) : 255;


  displayTime();
  //delay(100); // don't need to update very often...

}











