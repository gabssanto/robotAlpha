//distance sensor
int trig = 11;
int echo = 10;
//motor esquerdo
int lspeed = 6;
int lmotor = 5;//in2
// motor direito
int rspeed = 3;
int rmotor = 2;//in3
int in4 = 4;
//velocidades
int stspeed = 90;
int halfspeed = 128;

void setup(){
  Serial.begin(9600);
  pinMode(lspeed, OUTPUT);
  pinMode(rspeed, OUTPUT);
  pinMode(lmotor, OUTPUT);
  pinMode(rmotor, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void stopMotor(){
  digitalWrite(lmotor, LOW);
  digitalWrite(rmotor, LOW);
}



void loop(){
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
  
  if(distance<15){
    stopMotor();
    delay(1000);
    digitalWrite(lmotor, LOW);
    digitalWrite(rmotor, HIGH);
    analogWrite(lspeed, halfspeed);
    analogWrite(rspeed, halfspeed);
    delay(500);
    stopMotor();
    delay(1000);
    
    
  }
  else{
  digitalWrite(lmotor, HIGH);
  analogWrite(lspeed, stspeed);
  digitalWrite(rmotor, HIGH);
  analogWrite(rspeed, stspeed);
  }
   Serial.println(distance); 
}


/*void turnLeft(){
  digitalWrite(lmotor, LOW);
  digitalWrite(rmotor, HIGH);
  analogWrite(lspeed, halfspeed);
  analogWrite(rspeed, halfspeed);
  delay(500);
  

}*/
