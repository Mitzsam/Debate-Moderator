const int rightMic = A3;
const int leftMic = A2;
int rightMicState = 0;
int leftMicState = 0;

int buzzerPin = 9;
int flashPin = 3;
int flashDelay = 165;

int loudnessThreshold = 300;

void setup(){
  pinMode(rightMic, INPUT);
  pinMode(leftMic, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  rightMicState = analogRead(rightMic);
  leftMicState = analogRead(leftMic);
  Serial.print("Right: ");
  Serial.println(rightMicState);
  
  Serial.print("Left: ");
  Serial.println(leftMicState);
  delay(100);
  digitalWrite(buzzerPin, HIGH);

  if (rightMicState > loudnessThreshold || leftMicState > loudnessThreshold){
    flashAndBuzz();
    //message "Please refrain from screaming and maintain proper volume control"
  }

}

void flashAndBuzz(){
  tone(buzzerPin, 1000);

  digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  delay(flashDelay);
   digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  delay(flashDelay);
   digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  digitalWrite(buzzerPin, LOW);

  noTone(buzzerPin);
}