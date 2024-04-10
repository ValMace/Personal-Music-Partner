void checkTime(){
  diffPrevCurStep = curMil - prevMil;// is it time to switch to next step?
  if(diffPrevCurStep >= tempo){
    nextStep();
    prevMil=curMil;
  }else{          // nope
   checkOffs();
  }
}

void nextStep(){
  curStep++;// who's next step?
  if(curStep==nbrStep){
    curStep=0;
  }
  PORTB&=B11111000;
  for(int i = 0 ; i<3 ; i++){ // play pattern
    if(curPatt[i] & (1L<<curStep)){
      PORTB|=1<<i;
    }
  }
}

void checkOffs(){               //look for the right time to shut things
  for(int i = 0 ; i<3 ; i++){
    if(shutMode[i]==0){
      if(diffPrevCurStep>curDur[i]){
        PORTB&=~(1<<i);
      }
    }else{
      unsigned long adv;//advancement in step
      adv=diffPrevCurStep*100;
      adv/=tempo;
      if(adv>curDur[i]){
        PORTB&=~(1<<i);
      }
    }
  }
}
