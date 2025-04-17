#include <Stepper.h>

const int pasosPorVuelta = 200;         // Pasos por revolución del motor
const int pasosPorPosicion = 50;        // 1/4 de vuelta = 90 grados

Stepper motor(pasosPorVuelta, 8, 10, 9, 11);  // Pines conectados a IN1-IN4 del L298N
int posicionActual = 0; // 0, 1, 2, 3 → 0°, 90°, 180°, 270°

void setup() {
  Serial.begin(9600);
  motor.setSpeed(60);  // Velocidad inicial
  Serial.println("Comandos disponibles:");
  Serial.println("F: siguiente posición | D: anterior | S: reset (0°)");
  Serial.println("0-3: ir a posición específica (0°–270°)");
  Serial.println("R: rotación completa | V###: velocidad (ej: V120)");
  Serial.println("P: mostrar posición actual");
  Serial.println("A: secuencia automática | B: secuencia automática antihoraria");
}

void loop() {
  if (Serial.available() > 0) {
    String entrada = Serial.readStringUntil('\n');
    entrada.trim();  // Elimina espacios y saltos de línea

    if (entrada.length() == 0) return;

    char comando = entrada.charAt(0); 
    char comandoMayus = toupper(comando);

    switch (comandoMayus) {
      case 'F':
        posicionActual = (posicionActual + 1) % 4;
        motor.step(pasosPorPosicion);
        Serial.print("Girando a ");
        Serial.print(posicionActual * 90);
        Serial.println("°");
        break;

      case 'D':
        posicionActual = (posicionActual - 1 + 4) % 4;
        motor.step(-pasosPorPosicion);
        Serial.print("Girando a ");
        Serial.print(posicionActual * 90);
        Serial.println("°");
        break;

      case 'S':
        motor.step(-posicionActual * pasosPorPosicion);
        posicionActual = 0;
        Serial.println("Volviendo a 0°");
        break;

      case '0':
      case '1':
      case '2':
      case '3': {
        int destino = comando - '0';
        int pasos = (destino - posicionActual) * pasosPorPosicion;
        motor.step(pasos);
        posicionActual = destino;
        Serial.print("Movido a ");
        Serial.print(posicionActual * 90);
        Serial.println("°");
        break;
      }

      case 'R':
        motor.step(pasosPorVuelta);
        Serial.println("Rotación completa 360°");
        break;

      case 'V': {
        int nuevaVelocidad = entrada.substring(1).toInt();
        if (nuevaVelocidad > 0) {
          motor.setSpeed(nuevaVelocidad);
          Serial.print("Velocidad cambiada a ");
          Serial.print(nuevaVelocidad);
          Serial.println(" RPM");
        } else {
          Serial.println("Velocidad inválida");
        }
        break;
      }

      case 'P':
        Serial.print("Posición actual: ");
        Serial.print(posicionActual * 90);
        Serial.println("°");
        break;

      case 'A':
        Serial.println("Secuencia automática:");
        for (int i = 0; i < 4; i++) {
          motor.step(pasosPorPosicion);
          posicionActual = (posicionActual + 1) % 4;
          Serial.print(" → ");
          Serial.print(posicionActual * 90);
          Serial.println("°");
          delay(1000);
        }
        break;

      case 'B':
        Serial.println("Secuencia automática antihoraria:");
        for (int i = 0; i < 4; i++) {
          motor.step(-pasosPorPosicion);
          posicionActual = (posicionActual - 1 + 4) % 4;
          Serial.print(" ← ");
          Serial.print(posicionActual * 90);
          Serial.println("°");
          delay(1000);
        }
        break;

      default:
        Serial.println("Comando inválido. Usa F, D, S, 0-3, R, V###, P, A o B.");
        break;
    }
  }
}
