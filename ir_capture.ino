#include <Arduino.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 4;

void setup() {
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN);
    Serial.println("Ready to receive RAW pulses on Pin 4");
}

void loop() {
    if (IrReceiver.decode()) {
        // This prints the exact timings ESPHome needs for 'transmit_raw'
        IrReceiver.printIRResultRawFormatted(&Serial, true);
        Serial.println();
        IrReceiver.resume(); 
    }
}
