void checkTempo(){
  long stamp;
  stamp=analogRead(A2)/2;
  if(stamp<10){tempo=120; return;}
  stamp*=stamp;
  stamp/=512;
  stamp=512-stamp;
  stamp+=50;
  tempo=stamp;
}

void checkPattern(){
  sPatt=analogRead(A3)>>7;
  for(byte i=0;i<3;i++){
    curPatt[i]=patt[sPatt*3+i];
    curDur[i]=dur[sPatt*3+i];
  }
}
