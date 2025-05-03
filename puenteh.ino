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
#define DERECHA1   13
#define IZQUIERDA2 12
#define IZQUIERDA1 11
#define DERECHA2   10

bool acciona =0; // variable para cuando se pulsa el boton de funcionamiento
bool paro1=0;// variable para cuando se acciona el final de carrera abajo
bool paro2=0;// variable para cuando se acciona el final de carrera arriba
int estado =1 ;// variable de estado funcionamiento



void setup() {
  pinMode(PULS, INPUT);
  pinMode(PULSP1, INPUT);
  pinMode(PULSP2,INPUT);
  pinMode(DERECHA1, OUTPUT);
  pinMode(DERECHA2, OUTPUT);
  pinMode(IZQUIERDA1, OUTPUT);
  pinMode(IZQUIERDA2, OUTPUT);
 
 }

void loop() {
 
  acciona = digitalRead(PULS);
  paro1 =digitalRead (PULSP1);
  paro2 = digitalRead(PULSP2);
  delay(20);
 
  if(acciona){
   
    estado=(estado+1)%4; //unha vez que se acciona o pulsador de funcionamento cambiase o estado no que estaba
   
   
       while(digitalRead(PULS)){
      delay(10);
         
       }
  }
  if (paro1 && estado == 2 ){// cando se acciona o final de carrera inferior e o estado no que estaba era baixar parase
  estado=3;
  }
   if (paro2 && estado == 0){ // cando se acciona o final de carrera superior e o estado no que estaba era subir parase
  estado=1;
  }
      if (estado==0){// pasa a subir
        digitalWrite(DERECHA1, HIGH);
        digitalWrite(DERECHA2, HIGH);
    digitalWrite(IZQUIERDA1, LOW);
    digitalWrite(IZQUIERDA2, LOW);
      }

      if (estado==1||estado==3){// para
         digitalWrite(DERECHA1, LOW);
         digitalWrite(DERECHA2, LOW);
    digitalWrite(IZQUIERDA1, LOW);
    digitalWrite(IZQUIERDA2, LOW);
      }
  if (estado==2){// pasa a subida
     digitalWrite(DERECHA1, LOW);
     digitalWrite(DERECHA2, LOW);
    digitalWrite(IZQUIERDA1, HIGH);
    digitalWrite(IZQUIERDA2, HIGH);
    }
}
