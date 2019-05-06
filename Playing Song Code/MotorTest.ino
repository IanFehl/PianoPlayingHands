int IN1 = 7; // input 1
int IN2 = 8; // input 2
int EN = 14; // enable
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT); // IN1
  pinMode(IN2,OUTPUT); // IN2
  pinMode(EN,OUTPUT); // EN
}

void loop() {
  // put your main code here, to run repeatedly: 
 // if(counter == 0){
  moveRight();
  moveLeft();

 
//  counter++;
//  }
//  else{
//    while(1){}
//  }

}

void moveRight(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  //analogWrite(EN,181);
  delay(30); // 355  for MSP432

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  //analogWrite(EN,181);
  delay(30);
}

void moveLeft(){
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(EN,HIGH);
  //analogWrite(EN,181);
  delay(30); // 345 for MSP432

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN,HIGH);
  //analogWrite(EN,181);
  delay(30);
}
