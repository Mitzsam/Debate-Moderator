const int micPin = A2;
const int greenLED = 12;
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
    delay(100);
    Serial.println("sound");
  }
  else{
    digitalWrite(greenLED, LOW);
    delay(10);
    Serial.println("quiet");
  }

//hiii

}
