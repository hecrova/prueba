#include <Arduino.h>
#include <DIYables_IRcontroller.h>

// Pines de LEDs
#define LED_1 2
#define LED_2 5
#define LED_3 4
#define LED_4 25
#define LED_5 21
#define LED_6 23
#define LED_7 16

// Pin del buzzer
#define BUZZER 15

// Sensor infrarrojo
#define IR_RECEIVER_PIN 13
DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200);

// Notas musicales
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0

// Melodías
int starWarsMelody[] = { // Primera canción
    NOTE_AS4, 500, NOTE_AS4, 500, NOTE_AS4, 500, NOTE_F5, 350, NOTE_C6, 150,
    NOTE_AS5, 500, NOTE_A5, 500, NOTE_G5, 500, NOTE_F6, 350, NOTE_C6, 150,
    NOTE_AS5, 500, NOTE_A5, 500, NOTE_AS5, 500, NOTE_G5, 1000
};

int imperialMarchMelody[] = { // Segunda canción
    NOTE_A4, 500, NOTE_A4, 500, NOTE_A4, 500, NOTE_F4, 350, NOTE_C5, 150,
    NOTE_A4, 500, NOTE_F4, 350, NOTE_C5, 150, NOTE_A4, 1000,
    NOTE_E5, 500, NOTE_E5, 500, NOTE_E5, 500, NOTE_F5, 350, NOTE_C5, 150,
    NOTE_A4, 500, NOTE_F4, 350, NOTE_C5, 150, NOTE_A4, 1000
};

// Función para reproducir una melodía y sincronizar LEDs
void playMelodyWithLEDs(int *melody, int length, int ledPins[], int ledCount) {
    for (int i = 0; i < length; i += 2) {
        // Encender LEDs
        for (int j = 0; j < ledCount; j++) {
            digitalWrite(ledPins[j], HIGH);
        }

        // Reproducir nota
        tone(BUZZER, melody[i], melody[i + 1] * 0.9);
        delay(melody[i + 1] / 2);

        // Apagar LEDs
        for (int j = 0; j < ledCount; j++) {
            digitalWrite(ledPins[j], LOW);
        }
        delay(melody[i + 1] / 2);
        noTone(BUZZER);
    }
}

// Apagar todos los LEDs
void turnOffAllLEDs() {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
}

// Configuración inicial
void setup() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_5, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    irController.begin();
    Serial.begin(115200);
}

// Secuencia al presionar Botón 1
void performSequence() {
    // Encender pin 21 al inicio
    digitalWrite(LED_5, HIGH);

    // Reproducir Star Wars con LEDs 2, 5, 4 y 25
    int ledsStarWars[] = {LED_1, LED_2, LED_3, LED_4};
    playMelodyWithLEDs(starWarsMelody, sizeof(starWarsMelody) / sizeof(starWarsMelody[0]), ledsStarWars, 4);




    // Retraso de 2 segundos antes de la segunda canción
    delay(2000);

    // Reproducir Marcha Imperial con LEDs 23 y 16
    int ledsImperial[] = {LED_6, LED_7};
    playMelodyWithLEDs(imperialMarchMelody, sizeof(imperialMarchMelody) / sizeof(imperialMarchMelody[0]), ledsImperial, 2);

    // Apagar pin 21 al final
    digitalWrite(LED_5, LOW);

    turnOffAllLEDs();
}

// Bucle principal
void loop() {
    Key17 command = irController.getKey();
    if (command == Key17::KEY_1) {
        performSequence();

    }
}
