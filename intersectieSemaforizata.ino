// SEMAFOR 1
const int pinSemafor1Rosu   = 26;   
const int pinSemafor1Galben = 24;   
const int pinSemafor1Verde  = 22;   

// SEMAFOR 2
const int pinSemafor2Rosu   = 52;   
const int pinSemafor2Galben = 50;   
const int pinSemafor2Verde  = 48;   

// SEMAFOR 3
const int pinSemafor3Rosu   = 11;   
const int pinSemafor3Galben = 12;   
const int pinSemafor3Verde  = 13;   

// SEMAFOR 4
const int pinSemafor4Rosu   = 5;    
const int pinSemafor4Galben = 6;    
const int pinSemafor4Verde  = 7;    

// LED-uri suplimentare
const int pinLed1Verde = 3;   
const int pinLed1Rosu  = 2;   


const int pinLed2Verde = 31;   
const int pinLed2Rosu  = 30;

const int pinLed3Verde = 9;  
const int pinLed3Rosu  = 10;

const int pinLed4Verde = 4;   
const int pinLed4Rosu  = 8;

const int pinBuzzer  = 32;



// Timpi pentru fiecare stare
int contorSemaforRosu   = 7;
int contorSemaforGalben = 2;
int contorSemaforVerde  = 5;

// 0 verde, 1 galben, 2 rosu
int stareSemafor1 = 0;
int stareSemafor2 = 0;
int stareSemafor3 = 2;
int stareSemafor4 = 2;

unsigned long previous;
unsigned long current;
const int interval = 1000;

int contor2Timp = 0;
int contorTimp = 0;

// Variabilă pentru comutarea LED-urilor suplimentare
bool ledVerdeAprins = true;

void setup() {
  // SEMAFOR 1
  pinMode(pinSemafor1Rosu, OUTPUT);
  pinMode(pinSemafor1Galben, OUTPUT);
  pinMode(pinSemafor1Verde, OUTPUT);

  // SEMAFOR 2
  pinMode(pinSemafor2Rosu, OUTPUT);
  pinMode(pinSemafor2Galben, OUTPUT);
  pinMode(pinSemafor2Verde, OUTPUT);

  // SEMAFOR 3
  pinMode(pinSemafor3Rosu, OUTPUT);
  pinMode(pinSemafor3Galben, OUTPUT);
  pinMode(pinSemafor3Verde, OUTPUT);

  // SEMAFOR 4
  pinMode(pinSemafor4Rosu, OUTPUT);
  pinMode(pinSemafor4Galben, OUTPUT);
  pinMode(pinSemafor4Verde, OUTPUT);

  // LED-uri suplimentare
  pinMode(pinLed1Verde, OUTPUT);
  pinMode(pinLed1Rosu, OUTPUT);

   // LED-uri suplimentare
  pinMode(pinLed2Verde, OUTPUT);
  pinMode(pinLed2Rosu, OUTPUT);

   // LED-uri suplimentare
  pinMode(pinLed3Verde, OUTPUT);
  pinMode(pinLed3Rosu, OUTPUT);

   // LED-uri suplimentare
  pinMode(pinLed4Verde, OUTPUT);
  pinMode(pinLed4Rosu, OUTPUT);

   // LED-uri suplimentare
  pinMode(pinBuzzer, OUTPUT);

  // Inițializare: doar semaforul 1 pe verde, restul pe roșu
  stareSemafor1 = 0;
  stareSemafor2 = 2;
  stareSemafor3 = 2;
  stareSemafor4 = 0;

  digitalWrite(pinSemafor1Verde, HIGH);
  digitalWrite(pinSemafor1Galben, LOW);
  digitalWrite(pinSemafor1Rosu, LOW);

  digitalWrite(pinSemafor2Verde, LOW);
  digitalWrite(pinSemafor2Galben, LOW);
  digitalWrite(pinSemafor2Rosu, HIGH);

  digitalWrite(pinSemafor3Verde, LOW);
  digitalWrite(pinSemafor3Galben, LOW);
  digitalWrite(pinSemafor3Rosu, HIGH);

  digitalWrite(pinSemafor4Verde, HIGH);
  digitalWrite(pinSemafor4Galben, LOW);
  digitalWrite(pinSemafor4Rosu, LOW);

  // LED-uri suplimentare - pornim LED verde, stingem LED roșu
  digitalWrite(pinLed1Verde, HIGH);
  digitalWrite(pinLed1Rosu, LOW);

  digitalWrite(pinLed2Verde, HIGH);
  digitalWrite(pinLed2Rosu, LOW);

  digitalWrite(pinLed3Verde, HIGH);
  digitalWrite(pinLed3Rosu, LOW);

  digitalWrite(pinLed4Verde, HIGH);
  digitalWrite(pinLed4Rosu, LOW);

  contor2Timp = 0;
  contorTimp = 0;
  previous = millis();

  Serial.begin(9600);
}

void loop() {
  current = millis();
  if (current - previous >= interval) {
    contorTimp = contorTimp + 1;
    contor2Timp = contor2Timp + 1;
    Serial.println(contorTimp);

    // SEMAFOR 1
    switch (stareSemafor1) {
      case 0: // verde
        if (contorTimp >= contorSemaforVerde) {

          
          digitalWrite(pinSemafor1Verde, LOW);
          digitalWrite(pinSemafor1Galben, HIGH);

          digitalWrite(pinSemafor4Verde, LOW);
          digitalWrite(pinSemafor4Galben, HIGH);



          stareSemafor1 = 1;
          contorTimp = 0;
          Serial.println("Semafor 1: Rosu");
        }
        break;
      case 1: // galben
        if (contorTimp >= contorSemaforGalben) {
          digitalWrite(pinSemafor1Galben, LOW);
          digitalWrite(pinSemafor1Rosu, HIGH);

          digitalWrite(pinSemafor4Galben, LOW);
          digitalWrite(pinSemafor4Rosu, HIGH);
          
          stareSemafor1 = 2;
          contorTimp = 0;
          Serial.println("Semafor 1: Verde");
        }
        break;
      case 2: // rosu
        if (contorTimp >= contorSemaforRosu) {
          digitalWrite(pinSemafor1Rosu, LOW);
          digitalWrite(pinSemafor1Verde, HIGH);

          digitalWrite(pinSemafor4Rosu, LOW);
          digitalWrite(pinSemafor4Verde, HIGH);


          stareSemafor1 = 0;
          contorTimp = 0;
          Serial.println("Semafor 1: Galben");
        }
        break;
    }

    switch (stareSemafor3) {
      case 0: // verde
        if (contor2Timp >= contorSemaforVerde) {

          
          digitalWrite(pinSemafor3Verde, LOW);
          digitalWrite(pinSemafor3Galben, HIGH);

          digitalWrite(pinSemafor2Verde, LOW);
          digitalWrite(pinSemafor2Galben, HIGH);

          stareSemafor3 = 1;
          contor2Timp = 0;
          Serial.println("Semafor 1: Rosu");
        }
        break;
      case 1: // galben
        if (contor2Timp >= contorSemaforGalben) {
          digitalWrite(pinSemafor3Galben, LOW);
          digitalWrite(pinSemafor3Rosu, HIGH);

          digitalWrite(pinSemafor2Galben, LOW);
          digitalWrite(pinSemafor2Rosu, HIGH);
          stareSemafor3 = 2;
          contor2Timp = 0;
          Serial.println("Semafor 1: Verde");
        }
        break;
      case 2: // rosu
        if (contor2Timp >= contorSemaforRosu) {
          digitalWrite(pinSemafor3Rosu, LOW);
          digitalWrite(pinSemafor3Verde, HIGH);

          digitalWrite(pinSemafor2Rosu, LOW);
          digitalWrite(pinSemafor2Verde, HIGH);

          stareSemafor3 = 0;
          contor2Timp = 0;
          Serial.println("Semafor 1: Galben");
        }
        break;
    }

 if (stareSemafor1 == 2) { // Semafor 1 pe ROȘU
      digitalWrite(pinLed3Verde, HIGH);
      digitalWrite(pinLed3Rosu, LOW);
      digitalWrite(pinLed4Verde, HIGH);
      digitalWrite(pinLed4Rosu, LOW);
    } 
    else { // Semafor 1 pe VERDE sau GALBEN
      digitalWrite(pinLed3Verde, LOW);
      digitalWrite(pinLed3Rosu, HIGH);
      digitalWrite(pinLed4Verde, LOW);
      digitalWrite(pinLed4Rosu, HIGH);
    }
    
    
    
    if (stareSemafor3 == 2) { // Semafor 3 pe ROȘU
      digitalWrite(pinLed1Verde, HIGH);
      digitalWrite(pinLed1Rosu, LOW);
      digitalWrite(pinLed2Verde, HIGH);
      digitalWrite(pinLed2Rosu, LOW);
    } 
    else { // Semafor 1 pe VERDE sau GALBEN
      digitalWrite(pinLed1Verde, LOW);
      digitalWrite(pinLed1Rosu, HIGH);
      digitalWrite(pinLed2Verde, LOW);
      digitalWrite(pinLed2Rosu, HIGH);
    }

     if (stareSemafor3 == 0) { // semafoare 3 și 4 pe verde
      tone(pinBuzzer, 1000);  // buzzer la 1000 Hz
    } else if (stareSemafor1 == 2) { // semafoare 1 și 2 pe roșu (LED-uri 1 și 2 verzi)
      tone(pinBuzzer, 500);   // buzzer la 500 Hz
    } 


    previous = current;
  }
}