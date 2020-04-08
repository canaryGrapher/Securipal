const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 2;
const int buzzPin = 4;
const int ledPin = 12;
int buttonState = 0;
float duration, distance;
int MAX_CALIBRATED;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
    // turn LED on:
    Serial.println("Calibrating now");
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(3000);
    Serial.print("Distance calibrated at: ");
    MAX_CALIBRATED = distance;
    Serial.println(MAX_CALIBRATED);
  }
  if (distance < MAX_CALIBRATED)
  {
    Serial.println("Intruder!");
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(3000);
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(300);
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(300);
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(300);
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(300);
    tone(buzzPin, 1000);
    delay(100);
    noTone(buzzPin); // Stop sound...
    delay(300);
  }
}
