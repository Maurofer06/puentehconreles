/*
Esta practica consiste na simulación de unha xanela de carro.
En diferenza ca primeira practica aqui ao volver a pulsar o pulsador,
pasara por paro os motores antes de encenderse o outro, teñendo que vovler
a pulsar o boton para arrancarlo. 
Tamen se añade dous finales de carrera para os sentidos.
*/

#define PULS 9
#define PULSP1 8
#define PULSP2 7
#define DERECHA1 13
#define IZQUIERDA2 12
#define IZQUIERDA1 11
#define DERECHA2 10

bool acciona = 0; // variable para cuando se pulsa el botón de funcionamiento
bool paro1 = 0;   // variable para cuando se acciona el final de carrera abajo
bool paro2 = 0;   // variable para cuando se acciona el final de carrera arriba
int estado = 1;   // variable de estado de funcionamiento
unsigned long tiempoCambio = 0;  // variable para almacenar el tiempo en que cambió el estado

void setup() {
  pinMode(PULS, INPUT);
  pinMode(PULSP1, INPUT);
  pinMode(PULSP2, INPUT);
  pinMode(DERECHA1, OUTPUT);
  pinMode(DERECHA2, OUTPUT);
  pinMode(IZQUIERDA1, OUTPUT);
  pinMode(IZQUIERDA2, OUTPUT);
}

void loop() {
  acciona = digitalRead(PULS);
  paro1 = digitalRead(PULSP1);
  paro2 = digitalRead(PULSP2);
  delay(20);

  // Cambio de estado con el botón
  if (acciona) {
    estado = (estado + 1) % 4;  // Se cambia al siguiente estado
    tiempoCambio = millis();    // Guardamos el tiempo cuando se cambia el estado
    while (digitalRead(PULS)) {
      delay(10);
    }
  }

  // Detener el movimiento cuando se activa un final de carrera
  if (paro1 && estado == 2) { // Final de carrera inferior
    estado = 3;
  }
  if (paro2 && estado == 0) { // Final de carrera superior
    estado = 1;
  }

  // Comprobamos si han pasado 10 segundos desde el último cambio de estado
  if ((millis() - tiempoCambio) >= 10000) { // 10 segundos en milisegundos
    if (estado == 0) { // Estado de subida
      estado = 1; // Cambiar a detenido
      tiempoCambio = millis();  // Reiniciamos el temporizador
    }
    else if (estado == 2) { // Estado de bajada
      estado = 3; // Cambiar a detenido
      tiempoCambio = millis();  // Reiniciamos el temporizador
    }
  }

  // Control de motores según el estado
  if (estado == 0) { // Subir
    digitalWrite(DERECHA1, HIGH);
    digitalWrite(DERECHA2, HIGH);
    digitalWrite(IZQUIERDA1, LOW);
    digitalWrite(IZQUIERDA2, LOW);
  }

  if (estado == 1 || estado == 3) { // Detener
    digitalWrite(DERECHA1, LOW);
    digitalWrite(DERECHA2, LOW);
    digitalWrite(IZQUIERDA1, LOW);
    digitalWrite(IZQUIERDA2, LOW);
  }

  if (estado == 2) { // Bajar
    digitalWrite(DERECHA1, LOW);
    digitalWrite(DERECHA2, LOW);
    digitalWrite(IZQUIERDA1, HIGH);
    digitalWrite(IZQUIERDA2, HIGH);
  }
}
