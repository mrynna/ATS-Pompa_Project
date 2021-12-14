int ac1 = 5;
int ac2 = 4;
int relay1 = 14;
int relay2 = 12;
int dcv = A0;
float vmodul = 0.0; 
float voltdc = 0.0;
float R1 = 30000.0; //30k
float R2 = 7500.0; //7500 ohm resistor
int avalue = 0;

void setup(){
    pinMode(ac1, INPUT);
    pinMode(ac2, INPUT);
    pinMode(dcv, INPUT);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    Serial.begin(9600);
    delay(1000);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
}
void loop(){
    avalue = analogRead(dcv);
    vmodul = (avalue * 5.0) / 1024.0;
    voltdc = vmodul / (R2/(R1+R2));
    byte tegangan1 = digitalRead(ac1);
    byte tegangan2 = digitalRead(ac2);
    Serial.print("Tegangan PLN = ");
    Serial.println(tegangan1);
    Serial.print("Tegangan Panel = ");
    Serial.println(tegangan2);
    delay(500);
    if((tegangan1 == 0 && tegangan2 == 0) && voltdc >= 10.5) {
        delay(500);
        digitalWrite(relay1, HIGH);
        delay(1000);
        digitalWrite(relay2, HIGH);
        Serial.println("NC");
    }else if((tegangan1 == 1 && tegangan2 == 0) && voltdc >= 10.5){
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
