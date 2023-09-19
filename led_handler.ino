const int ledPin1 = 5; // Primo LED
const int ledPin2 = 4; // Secondo LED
const int ledPin3 = 3; // Terzo LED
const int ledPin4 = 2; // Quarto LED
int luci_da_accendere = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
      
  if (Serial.available() > 0) {
    luci_da_accendere = Serial.parseInt();  // Legge il valore seriale inviato

    if (luci_da_accendere == 0) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }
    
    else if (luci_da_accendere == 1) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }

    else if (luci_da_accendere == 2) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }

    else if (luci_da_accendere == 3) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
    }

    else if (luci_da_accendere == 4) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
    }

    // Stampa quante luci sono accese sulla console seriale
    Serial.print("Luci accese: ");
    Serial.println(luci_da_accendere);
    delay(1000);
  }
  
}
