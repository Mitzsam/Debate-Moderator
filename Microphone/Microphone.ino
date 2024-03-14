const int micPin = A2;
const int greenLED = 13;
int micState = 0;

void setup(){
  pinMode(micPin, INPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  micState = analogRead(micPin);
  Serial.println(micState);

  if (micState > 600){
    digitalWrite(greenLED, HIGH);
    Serial.println("sound");
    delay(100);
  }
  else{
    digitalWrite(greenLED, LOW);
    delay(10);
    Serial.println("quiet");
  }
delay(500);
//hiii

}
