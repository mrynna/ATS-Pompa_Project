byte ac1 = 5;
byte ac2 = 4;
byte relay1 = 14;
byte relay2 = 12;

void setup(){
    pinMode(ac1, INPUT);
    pinMode(ac2, INPUT);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Serial.begin(9600);
    delay(1000);
}
void loop(){
    byte tegangan1 = digitalRead(ac1);
    byte tegangan2 = digitalRead(ac2);
    Serial.print("Tegangan PLN = ");
    Serial.println(tegangan1);
    Serial.print("Tegangan Panel = ");
    Serial.println(tegangan2);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    delay(2000);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(2000);
}
