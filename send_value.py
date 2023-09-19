import serial
import time

class ArduinoController:
    def __init__(self, port, baud_rate):
        self.port = port
        self.baud_rate = baud_rate
        self.serial_connection = None

    def connect(self):
        try:
            self.serial_connection = serial.Serial(self.port, self.baud_rate)
            time.sleep(2)  # Aspetta un momento per stabilire la connessione
            print("Connessione seriale stabilita con successo.")
        except serial.SerialException as e:
            print(f"Errore nella connessione seriale: {e}")

    def send_value(self, value):
        if self.serial_connection:
            try:
                self.serial_connection.write(str(value).encode())  # Invia il valore seriale all'Arduino
                print(f"Valore {value} inviato con successo.")
                time.sleep(1)
            except Exception as e:
                print(f"Errore nell'invio del valore seriale: {e}")
        else:
            print("Connessione seriale non stabilita. Esegui il metodo connect() prima di inviare valori.")

    def disconnect(self):
        if self.serial_connection:
            self.serial_connection.close()
            print("Connessione seriale chiusa.")
        else:
            print("Nessuna connessione seriale da chiudere.")

"""
# Esempio di utilizzo:
if __name__ == "__main__":
    arduino = ArduinoController('COM3', 9600)  # Sostituisci 'COM3' con la porta seriale corretta
    arduino.connect()
    
    # Esempio di invio del valore seriale
    valore_da_inviare = 75
    arduino.send_value(valore_da_inviare)
    
    arduino.disconnect()
"""
