byte ac1 = 5;
byte ac2 = 4;
byte relay1 = 14;
byte relay2 = 12;

void setup(){
    pinMode(ac1, INPUT);
    pinMode(ac2, INPUT);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    Serial.begin(9600);
    delay(1000);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
}
void loop(){
    byte tegangan1 = digitalRead(ac1);
    byte tegangan2 = digitalRead(ac2);
    Serial.print("Tegangan PLN = ");
    Serial.println(tegangan1);
    Serial.print("Tegangan Panel = ");
    Serial.println(tegangan2);
    delay(500);
    if(tegangan1 == 0 && tegangan2 == 0) {
        delay(500);
        digitalWrite(relay1, HIGH);
        delay(1000);
        digitalWrite(relay2, HIGH);
        Serial.println("NC");
    }else if(tegangan1 == 1 && tegangan2 == 0){
        delay(500);
        digitalWrite(relay1, HIGH);
        delay(1000);
        digitalWrite(relay2, HIGH);
        Serial.println("NC");
    }else if(tegangan1 == 1 && tegangan2 == 1){
        delay(500);
        digitalWrite(relay1, HIGH);
        delay(1000);
        digitalWrite(relay2, LOW);
        Serial.println("NC");
    }else{
        delay(500);
        digitalWrite(relay2, LOW);
        delay(1000);
        digitalWrite(relay1, LOW);
        Serial.println("Relay 2 Aktif");
    }
}
