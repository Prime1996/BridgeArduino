const int trigPin1 = 13;
const int echoPin1 = 12;
const int trigPin2 = 11;
const int echoPin2 = 10;
long duration1;
int distance1;
long duration2;
int distance2;
const int LED1 = 7;
const int LED2 = 6;
static int flag1 = 0;
static int flag2 = 0;

void setup() {
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  Serial.print("Distance1: ");
  Serial.println(distance1); 

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  Serial.print("Distance2: ");
  Serial.println(distance2);

  if(distance1 < 15 && flag1 == 0){
    digitalWrite(LED2, HIGH);
    flag1 = 1;
  }
  else if(distance2 < 15 && flag1 == 1){
    digitalWrite(LED2, LOW);
    flag1 = 0;
  }
  else if(distance2 < 15 && flag2 == 0){
    digitalWrite(LED1, HIGH);
    flag2 = 0;
  }
  else if(distance1 < 15 && flag2 == 1){
    digitalWrite(LED1, LOW);
    flag2 = 1;
  }
  else if(distance1 < 15 && distance2 < 15){
    for(int i = 0; i <= 10; i++){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      delay(1000);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(1000);
    }
  }
}
