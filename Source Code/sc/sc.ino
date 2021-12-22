int ac1 = 5;
int ac2 = 4;
int relay1 = 14;
int relay2 = 12;
int relay1b = 13;
int relay2b = 16;
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
    pinMode(relay1b, OUTPUT);
    pinMode(relay2b, OUTPUT);
    Serial.begin(115200);
    delay(1000);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    digitalWrite(relay1b, HIGH);
    digitalWrite(relay2b, LOW);
}
void loop(){
    avalue = analogRead(dcv);
    vmodul = (avalue * 2.4) / 797;
    voltdc = vmodul / (R2/(R1+R2));
    byte tegangan1 = digitalRead(ac1);
    byte tegangan2 = digitalRead(ac2);
    Serial.print("Tegangan PLN = ");
    Serial.println(tegangan1);
    Serial.print("Tegangan Panel = ");
    Serial.println(tegangan2);
    Serial.print("Nilai analog = ");
    Serial.println(avalue);
    Serial.print("Tegangan modul = ");
    Serial.println(vmodul);
    Serial.print("Tegangan Aki = ");
    Serial.println(voltdc);
    delay(500);
    if(voltdc >= 11.4 && tegangan1 == 0 && tegangan2 == 0){
       delay(500);
       digitalWrite(relay1, HIGH);
       digitalWrite(relay1b, HIGH);
       delay(1000);
       digitalWrite(relay2, HIGH);
       digitalWrite(relay2b, HIGH);
       Serial.println("\n Tegangan Aktif : TEGANGAN PLTS \n");
    }else if(voltdc >= 11.4 && tegangan1 == 1 && tegangan2 == 0){
       delay(500);
       digitalWrite(relay1, HIGH);
       digitalWrite(relay1b, HIGH);
       delay(1000);
       digitalWrite(relay2, HIGH);
       digitalWrite(relay2b, HIGH);
       Serial.println("\n Tegangan Aktif : TEGANGAN PLTS \n");
    }else if(voltdc < 11.4 && tegangan1 == 1 && tegangan2 == 0){
       delay(500);
       digitalWrite(relay1, HIGH);
       digitalWrite(relay1b, HIGH);
       delay(1000);
       digitalWrite(relay2, LOW);
       digitalWrite(relay2b, LOW);
       Serial.println("\n Tegangan Aktif : tidak ada \n");
    }else if(voltdc < 11.4 && tegangan1 == 0 && tegangan2 == 0){
       delay(500);
       digitalWrite(relay2, LOW);
       digitalWrite(relay2b, LOW);
       delay(1000);
       digitalWrite(relay1, LOW);
       digitalWrite(relay1b, LOW);
       Serial.println("\n Tegangan Aktif : TEGANGAN PLN \n"); 
    }else if((voltdc < 11.4 || voltdc >= 11.4) && tegangan1 == 1 && tegangan2 == 1){
       delay(500);
       digitalWrite(relay1, HIGH);
       digitalWrite(relay1b, HIGH);
       delay(1000);
       digitalWrite(relay2, LOW);
       digitalWrite(relay2b, LOW);
       Serial.println("\n Tegangan Aktif : tidak ada \n");
     }else{
       delay(500);
       digitalWrite(relay2, LOW);
       digitalWrite(relay2b, LOW);
       delay(1000);
       digitalWrite(relay1, LOW);
       digitalWrite(relay1b, LOW);
       Serial.println("\n Tegangan Aktif : TEGANGAN PLN \n");         
    }
}
