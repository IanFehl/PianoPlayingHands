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
int counter = 0;
int buttonState = 0;
const int button = PUSH1;     // the number of the pushbutton pin
int octave = 1;

int IN1 = 23; // input 1
int IN2 = 24; // input 2
int EN = 25; // enable

//int buttonState = 0;
//const int button = PUSH2;     // the number of the pushbutton pin

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
//  for(int i = 0; i < (sizeof(OfficePositionsTreble)/sizeof(int));i++){
//    if     (OfficePositionsTreble[i] == -3) OfficePositionsTreble[i] = 10;
//    else if(OfficePositionsTreble[i] == -2) OfficePositionsTreble[i] = 3;
//    else if(OfficePositionsTreble[i] == -1) OfficePositionsTreble[i] = 4;
//    else if(OfficePositionsTreble[i] == 0) OfficePositionsTreble[i] = 5;
//    else if(OfficePositionsTreble[i] == 1) OfficePositionsTreble[i] = 6;
//    else if(OfficePositionsTreble[i] == 2) OfficePositionsTreble[i] = 7;
//    else if(OfficePositionsTreble[i] ==  3) OfficePositionsTreble[i] = 8;
//    else if(OfficePositionsTreble[i] ==  4) OfficePositionsTreble[i] = 9;
//  }
}

void loop() {
  if(counter == 0){
    buttonState = digitalRead(button);
    while(buttonState = HIGH){
      buttonState = digitalRead(button);
      if(buttonState == LOW){
        break;
      }
    }
    playOffice();
      counter++;
  }
  else{
    while(1){}
  }
  //moveLeft();
  //waitForSong();
//  buttonState = digitalRead(button);
//  while(buttonState = HIGH){
//    buttonState = digitalRead(button);
//    if(buttonState == LOW){
//      break;
//    }
//  }

}

void moveNegativeThreeToNegativeOne(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(165);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(165);
  octave = 2;
}

void moveNegativeOneToNegativeThree(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(EN,HIGH);
  delay(155);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(155);
  octave = 1;
}

void moveNegativeThreeToFive(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(375);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  delay(375);
  octave = 3;
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
        if(octave == 1) pressFirstOctave(OfficePositionsTreble[j]);
        else if(octave == 2) pressSecondOctave(OfficePositionsTreble[j]);
        else if(octave == 3) pressThirdOctave(OfficePositionsTreble[j]);
          //digitalWrite(OfficePositionsTreble[j],HIGH);
      }
      delay(timeOn);
      for(int j = add; j < add + OfficeCounterTreble[i];j++){
        if(octave == 1) releaseFirstOctave(OfficePositionsTreble[j]);
        else if(octave == 2) releaseSecondOctave(OfficePositionsTreble[j]);
        else if(octave == 3) releaseThirdOctave(OfficePositionsTreble[j]);
        //digitalWrite(OfficePositionsTreble[j],LOW);
      }

      if(OfficeDurationsTreble[i] == 1) delay(Whole);
      else if(OfficeDurationsTreble[i] == 2) delay(Half);
      else if(OfficeDurationsTreble[i] == 4) delay(Quarter);
      else if(OfficeDurationsTreble[i] == 8) delay(Eighth);
      else if(OfficeDurationsTreble[i] == 16) delay(Sixteenth);
      else if(OfficeDurationsTreble[i] == 32) delay(Thirty);
    }
    add += OfficeCounterTreble[i];
    if (add == 34) moveNegativeThreeToNegativeOne();
    else if (add == 38) moveNegativeOneToNegativeThree();
    else if (add == 48) moveNegativeThreeToNegativeOne();
    else if (add == 57) moveNegativeOneToNegativeThree();
    else if (add == 66) moveNegativeThreeToNegativeOne();
    else if (add == 73) moveNegativeOneToNegativeThree();
    else if (add == 80) moveNegativeThreeToNegativeOne();
    else if (add == 86) moveNegativeOneToNegativeThree();
    else if (add == 139) moveNegativeThreeToFive();
  }
}

void pressFirstOctave(int note){
  if(note == -3) digitalWrite(10,HIGH);
  else if(note == -2) digitalWrite(3,HIGH);
  else if(note == -1) digitalWrite(4,HIGH);
  else if(note == 0) digitalWrite(5,HIGH);
  else if(note == 1) digitalWrite(6,HIGH);
  else if(note == 2) digitalWrite(7,HIGH);
  else if(note == 3) digitalWrite(8,HIGH);
  else if(note == 4) digitalWrite(9,HIGH);
}

void releaseFirstOctave(int note){
  if(note == -3) digitalWrite(10,LOW);
  else if(note == -2) digitalWrite(3,LOW);
  else if(note == -1) digitalWrite(4,LOW);
  else if(note == 0) digitalWrite(5,LOW);
  else if(note == 1) digitalWrite(6,LOW);
  else if(note == 2) digitalWrite(7,LOW);
  else if(note == 3) digitalWrite(8,LOW);
  else if(note == 4) digitalWrite(9,LOW);
}

void pressSecondOctave(int note){
  if(note == -1) digitalWrite(10,HIGH);
  else if(note == 0) digitalWrite(3,HIGH);
  else if(note == 1) digitalWrite(4,HIGH);
  else if(note == 2) digitalWrite(5,HIGH);
  else if(note == 3) digitalWrite(6,HIGH);
  else if(note == 4) digitalWrite(7,HIGH);
  else if(note == 5) digitalWrite(8,HIGH);
  else if(note == 6) digitalWrite(9,HIGH);
}

void releaseSecondOctave(int note){
  if(note == -1) digitalWrite(10,LOW);
  else if(note == 0) digitalWrite(3,LOW);
  else if(note == 1) digitalWrite(4,LOW);
  else if(note == 2) digitalWrite(5,LOW);
  else if(note == 3) digitalWrite(6,LOW);
  else if(note == 4) digitalWrite(7,LOW);
  else if(note == 5) digitalWrite(8,LOW);
  else if(note == 6) digitalWrite(9,LOW);
}

void pressThirdOctave(int note){
  if(note == 5) digitalWrite(10,HIGH);
  else if(note == 6) digitalWrite(3,HIGH);
  else if(note == 7) digitalWrite(4,HIGH);
  else if(note == 8) digitalWrite(5,HIGH);
  else if(note == 9) digitalWrite(6,HIGH);
  else if(note == 10) digitalWrite(7,HIGH);
  else if(note == 11) digitalWrite(8,HIGH);
  else if(note == 12) digitalWrite(9,HIGH);
}

void releaseThirdOctave(int note){
  if(note == 5) digitalWrite(10,LOW);
  else if(note == 6) digitalWrite(3,LOW);
  else if(note == 7) digitalWrite(4,LOW);
  else if(note == 8) digitalWrite(5,LOW);
  else if(note == 9) digitalWrite(6,LOW);
  else if(note == 10) digitalWrite(7,LOW);
  else if(note == 11) digitalWrite(8,LOW);
  else if(note == 12) digitalWrite(9,LOW);
}
