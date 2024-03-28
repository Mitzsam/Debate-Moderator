const int rightMic = A2;
const int leftMic = A1;
int rightMicState = 0;
int leftMicState = 0;

void setup(){
  pinMode(rightMic, INPUT);
  pinMode(leftMic, INPUT);
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

}
