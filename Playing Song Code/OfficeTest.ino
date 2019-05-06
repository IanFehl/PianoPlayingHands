const int OfficeDurationsTreble[] = {8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,4,4,8,8,8,8,2,2,2,8,8,8,8,1,4,4,8,8,8,8,2,2,2,8,8,8,8,2,8,8,8,8,4,4,8,8,8,8,2,2,2,8,8,8,8,1,4,4,8,8,8,8,2,2,2,8,8,8,8,2,8,8,8,8,4,4,8,8,8,8,8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,4,4,8,8,8,8,12,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,1};
int OfficePositionsTreble[] = {0,2,-2,0,2,0,2,-2,0,2,-3,0,2,0,2,-3,0,3,-2,0,3,0,3,-2,1,3,1,3,1,3,0,-1,0,-2,5,5,4,5,4,2,3,1,1,1,0,-1,0,-2,5,5,4,5,6,4,3,2,3,2,0,1,1,1,0,-1,0,-2,5,5,4,5,4,2,3,1,1,1,0,-1,0,-2,5,5,4,5,6,4,3,2,3,2,0,1,1,1,0,-1,0,0,2,-2,0,2,0,2,-2,0,2,-3,0,2,0,2,-3,0,3,-2,0,3,0,3,-2,1,3,1,3,1,3,0,-1,0,-2,0,-2,0,2,0,2,5,2,5,7,5,7,9,7,9,12,12,12};
const int OfficeCounterTreble[] = {2,1,2,2,1,2,1,2,2,1,2,1,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,1,2,1,2,2,1,2,1,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const double OfficeTempo = 180;
const double Whole = ((240/OfficeTempo)*1000) - 30;
const double Half = ((120/OfficeTempo)*1000) - 30;
const double Quarter = ((60/OfficeTempo)*1000) - 30;
const double Eighth = ((30/OfficeTempo)*1000) - 30;
const double Sixteenth = ((15/OfficeTempo)*1000) - 30;
const double Thirty = abs(((7.5/OfficeTempo)*1000)-30);
const double WholeDotted = Whole+(Whole/2);
const double HalfDotted = Half+(Half/2);
const double QuarterDotted = Quarter + (Quarter/2);
const double EightDotted = Eighth + (Eighth/2);
const double SixteenthDotted = Sixteenth + (Sixteenth/2);
const double ThirtyDotted = Thirty + (Thirty/2);
const int timeOn = 75;
int movecounter = 0;

int IN1 = 23; // input 1
int IN2 = 24; // input 2
int EN = 25; // enable

int buttonState = 0;
const int button = PUSH2;     // the number of the pushbutton pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1,OUTPUT); // IN1
  pinMode(IN2,OUTPUT); // IN2
  pinMode(EN,OUTPUT); // EN
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  for(int i = 0; i < (sizeof(OfficePositionsTreble)/sizeof(int));i++){
    if     (OfficePositionsTreble[i] == -6) OfficePositionsTreble[i] = 2;
    else if(OfficePositionsTreble[i] == -5) OfficePositionsTreble[i] = 3;
    else if(OfficePositionsTreble[i] == -4) OfficePositionsTreble[i] = 4;
    else if(OfficePositionsTreble[i] == -3) OfficePositionsTreble[i] = 5;
    else if(OfficePositionsTreble[i] == -2) OfficePositionsTreble[i] = 6;
    else if(OfficePositionsTreble[i] == -1) OfficePositionsTreble[i] = 7;
    else if(OfficePositionsTreble[i] ==  0) OfficePositionsTreble[i] = 8;
    else if(OfficePositionsTreble[i] ==  1) OfficePositionsTreble[i] = 9;
  }
}

void loop() {
  waitForSong();
//  buttonState = digitalRead(button);
//  while(buttonState = HIGH){
//    buttonState = digitalRead(button);
//    if(buttonState == LOW){
//      break;
//    }
//  }

}

void moveRight(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(355);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
}

void moveLeft(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(EN,HIGH);
  delay(345);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
}

void waitForSong(){
  char song = '0';
  while(song == '0'){
    if (Serial.available() > 0) {
      song = Serial.read();
      if(song == 'o')      playOffice();
//      else if(song == 'm') playMortalKombat();
//      else if(song == 's') playSecrets();
//      else if(song == 'l') playOML();
    }
  }
}

void waitForPlay(char songChar){ // waits for user to hit play to start song again
  char play = Serial.read();
  while(play != songChar){
    if (Serial.available() > 0) {
      play = Serial.read();
      if(play == songChar) break;
      else if (play == 'z') waitForSong();
    }
  }
}

void playOffice(){
  int add = 0;
  for(int i = 0; i < (sizeof(OfficeDurationsTreble)/sizeof(int));i++){
    if(OfficeCounterTreble[i] == 0){
      if(OfficeDurationsTreble[i] == 1) delay(Whole);
      else if(OfficeDurationsTreble[i] == 2) delay(Half);
      else if(OfficeDurationsTreble[i] == 4) delay(Quarter);
      else if(OfficeDurationsTreble[i] == 8) delay(Eighth);
      else if(OfficeDurationsTreble[i] == 16) delay(Sixteenth);
      else if(OfficeDurationsTreble[i] == 32) delay(Thirty);
    }
    else{
      for(int j = add; j < add + OfficeCounterTreble[i]; j++){
          digitalWrite(OfficePositionsTreble[j],HIGH);
      }
      delay(timeOn);
      for(int j = add; j < add + OfficeCounterTreble[i];j++){
        digitalWrite(OfficePositionsTreble[j],LOW);
      }

      if(OfficeDurationsTreble[i] == 1) delay(Whole);
      else if(OfficeDurationsTreble[i] == 2) delay(Half);
      else if(OfficeDurationsTreble[i] == 4) delay(Quarter);
      else if(OfficeDurationsTreble[i] == 8) delay(Eighth);
      else if(OfficeDurationsTreble[i] == 16) delay(Sixteenth);
      else if(OfficeDurationsTreble[i] == 32) delay(Thirty);
    }

    add += OfficeCounterTreble[i];
    char pause = Serial.read();
    char songChar = 'o';
    if (Serial.available() > 0) {
      pause = Serial.read();
      if(pause == 'y') waitForPlay(songChar);
      else if (pause == 'z') waitForSong();
    }
//    if (add > 30){
//      if(movecounter == 0) {moveRight(); movecounter++;}
//    }
  }
}
