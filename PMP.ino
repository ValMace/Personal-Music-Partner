
unsigned long mil;                //to store millis()
byte milMod;                      //millis modulo 10
unsigned long curMil;             //current millis
unsigned long prevMil=0;          //millis at last nextStep()
unsigned long diffPrevCurStep;    //ms since last nextStep()
byte curStep=31;                  //from 1 to nbrBeat
byte nbrStep=32;                  //from 1 to 32
int tempo=500;
byte sPatt=0;                     //selected pattern
long curPatt[]={0,0,0};           //currently Played Pattern
byte curDur[]={20,20,20};         //current ON time for each output
unsigned long patt[]={            //patterns//////////////////////////<<<here you paste the patterns
  0x11111111,0xC9494949,0x4C4444C4,
  0x11114111,0x04054404,0x42413040,
  0x1111CD11,0x40440004,0x01014905,
  0x05111105,0x4C454C44,0x01110011,
  0x29292929,0x10451045,0x46114411,
  0x04A1920C,0x01516103,0xF00F00F0,
  0x49494949,0x01010101,0x101110C0,
  0x0,0x0,0x0
};
const byte shutMode[]={0,0,1};    //(0=>momentary (in ms) , 1=>fraction (in % of a step)
byte dur[]{                      //durations related to selected pattern
  20,30,30,
  20,30,50,
  20,30,100,
  20,30,30,
  20,30,50,
  20,30,100,
  20,30,100,
  20,30,15
};


void setup() { 
  DDRB=B00000111;           //define IN & OUT pins   
}

void loop() {
  mil=millis();
  if(curMil != mil){
    curMil = mil;
    checkTime();
    milMod=mil%10;
    if(milMod==0){
      checkTempo();
    }else if(milMod==5){
      checkPattern();
    }
  }
}
