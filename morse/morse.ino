/*
 * Author:   Michael Vartan
 * Title:    Digispark/Arduino Morse Code Transmitter
 * Details:  Transmits morse code at 13wpm (default).
 *           Transmits through audio and light.
 *           Default Wiring:
 *             * Internal LED on pin 0
 *             * Speaker hooked up from PIN 1 to GND
 */

#define SPEAKER     0             // The speaker is on pin 0 
#define LED         1             // The   LED   is on pin 1


#define TIME_UNIT   WPM(13)       // In milliseconds; 92ms = 13wpm
#define MESSAGE     "THANK YOU"   // In ALPHANUMERIC ALLCAPS


#define WPM(x)    (92*13)/x

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
}
void loop() {
  sendMorse(MESSAGE);
  delay(1000);
}
  
  
void sendMorse(String s) {
  for(int i = 0; i < s.length(); i++) {
    if(s[i]==' ')
      delay(TIME_UNIT*3);         // total delay of 7 time units. 3+(3+1).
    else
      sendMorseChar(s[i]);
    delay(TIME_UNIT*3);
  }
  
}
void sendMorseChar(char c) {
  String morseString = getMorseSequence(c);
  for(int i = 0; i < morseString.length(); i++) {
    char sound = morseString[i];
    switch(sound) {
      case '-':
        sendBeep(true);
        delay(TIME_UNIT*3);
        break;
      case '.':
        sendBeep(true);
        delay(TIME_UNIT*1);
        break;
      default:
      break;
    }
    sendBeep(false);
    delay(TIME_UNIT*1);


  }
}
void sendBeep(boolean b) {
  if(b) {
      tone(SPEAKER, 500);
      digitalWrite(LED, HIGH);
  } else {
      noTone(SPEAKER);
      digitalWrite(LED, LOW);
  }
}

String getMorseSequence(char c) {
  switch(c) {
    case '0': return "-----";  //0x30  0
    case '1': return ".----";  //0x31  1
    case '2': return "..---";  //0x32  2
    case '3': return "...--";  //0x33  3
    case '4': return "....-";  //0x34  4
    case '5': return ".....";  //0x35  5
    case '6': return "-....";  //0x36  6
    case '7': return "--...";  //0x37  7
    case '8': return "---..";  //0x38  8
    case '9': return "----.";  //0x39  9
    case 'A': return ".-";     //0x41  A
    case 'B': return "-...";   //0x42  B
    case 'C': return "-.-.";   //0x43  C
    case 'D': return "-..";    //0x44  D
    case 'E': return ".";      //0x45  E
    case 'F': return "..-.";   //0x46  F
    case 'G': return "--.";    //0x47  G
    case 'H': return "....";   //0x48  H
    case 'I': return "..";     //0x49  I
    case 'J': return ".---";   //0x4A  J
    case 'K': return "-.-";    //0x4B  K
    case 'L': return ".-..";   //0x4C  L
    case 'M': return "--";     //0x4D  M
    case 'N': return "-.";     //0x4E  N
    case 'O': return "---";    //0x4F  O
    case 'P': return ".--.";   //0x50  P 
    case 'Q': return "--.-";   //0x51  Q
    case 'R': return ".-.";    //0x52  R
    case 'S': return "...";    //0x53  S
    case 'T': return "-";      //0x54  T
    case 'U': return "..-";    //0x55  U
    case 'V': return "...-";   //0x56  V
    case 'W': return ".--";    //0x57  W
    case 'X': return "-..-";   //0x58  X
    case 'Y': return "-.--";   //0x59  Y
    case 'Z': return "--..";   //0x5A  Z
    case ' ': return ' ';
    default:  return ' ';  
  }
}


/*
Below was attempt #1. Was accessed by morse[char].
There was not enough RAM to support this method on the
digispark.
const char[]  morse[] = {
                   "",       //0x00
                   "",       //0x01
                   "",       //0x02
                   "",       //0x03
                   "",       //0x04
                   "",       //0x05
                   "",       //0x06
                   "",       //0x07
                   "",       //0x08
                   "",       //0x09
                   "",       //0x0A
                   "",       //0x0B
                   "",       //0x0C
                   "",       //0x0D
                   "",       //0x0E
                   "",       //0x0F
                   "",       //0x10
                   "",       //0x11
                   "",       //0x12
                   "",       //0x13
                   "",       //0x14
                   "",       //0x15
                   "",       //0x16
                   "",       //0x17
                   "",       //0x18
                   "",       //0x19
                   "",       //0x1A
                   "",       //0x1B
                   "",       //0x1C
                   "",       //0x1D
                   "",       //0x1E
                   "",       //0x1F
                   "  ",     //0x20
                   "",       //0x21
                   "",       //0x22
                   "",       //0x23
                   "",       //0x24
                   "",       //0x25
                   "",       //0x26
                   "",       //0x27
                   "",       //0x28
                   "",       //0x29
                   "",       //0x2A
                   "",       //0x2B
                   "",       //0x2C
                   "",       //0x2D
                   "",       //0x2E
                   "",       //0x2F            
                   "-----",  //0x30  0
                   ".----",  //0x31  1
                   "..---",  //0x32  2
                   "...--",  //0x33  3
                   "....-",  //0x34  4
                   ".....",  //0x35  5
                   "-....",  //0x36  6
                   "--...",  //0x37  7
                   "---..",  //0x38  8
                   "----.",  //0x39  9
                   "",       //0x3A
                   "",       //0x3B
                   "",       //0x3C
                   "",       //0x3D
                   "",       //0x3E
                   "",       //0x3F
                   "",       //0x40
                   ".-",     //0x41  A
                   "-...",   //0x42  B
                   "-.-.",   //0x43  C
                   "-..",    //0x44  D
                   ".",      //0x45  E
                   "..-.",   //0x46  F
                   "--.",    //0x47  G
                   "....",   //0x48  H
                   "..",     //0x49  I
                   ".---",   //0x4A  J
                   "-.-",    //0x4B  K
                   ".-..",   //0x4C  L
                   "--",     //0x4D  M
                   "-.",     //0x4E  N
                   "---",    //0x4F  O
                   ".--.",   //0x50  P 
                   "--.-",   //0x51  Q
                   ".-.",    //0x52  R
                   "...",    //0x53  S
                   "-",      //0x54  T
                   "..-",    //0x55  U
                   "...-",   //0x56  V
                   ".--",    //0x57  W
                   "-..-",   //0x58  X
                   "-.--",   //0x59  Y
                   "--.."    //0x5A  Z                  
} ;
*/
