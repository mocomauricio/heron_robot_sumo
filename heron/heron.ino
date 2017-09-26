#define ULTRASONICO_DELANTERO_TRIGGER 1
#define ULTRASONICO_DELANTERO_ECHO 2

#define ULTRASONICO_TRASERO_TRIGGER 3
#define ULTRASONICO_TRASERO_ECHO 4

#define ULTRASONICO_IZQUIERDO_TRIGGER 5
#define ULTRASONICO_IZQUIERDO_ECHO 6

#define ULTRASONICO_DERECHO_TRIGGER 7
#define ULTRASONICO_DERECHO_ECHO 8

#define MOTOR_IZQUIERDO_PIN1 9
#define MOTOR_IZQUIERDO_PIN2 10

#define MOTOR_DERECHO_PIN1 11
#define MOTOR_DERECHO_PIN2 12

#define RADIO_DE_DETECCION 10

bool detectar_adelante(){
    long duracion, distancia;

    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(ULTRASONICO_DELANTERO_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONICO_DELANTERO_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONICO_DELANTERO_TRIGGER, LOW);
    duracion = pulseIn(ULTRASONICO_DELANTERO_ECHO, HIGH);

    // convertir el tiempo a distancia en centimetros
    distancia = duracion / 29.1 / 2 ;

    if (distancia <= RADIO_DE_DETECCION && distancia > 0)
        return true;

    return false;
}


bool detectar_atras(){
    long duracion, distancia;

    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(ULTRASONICO_TRASERO_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONICO_TRASERO_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONICO_TRASERO_TRIGGER, LOW);
    duracion = pulseIn(ULTRASONICO_TRASERO_ECHO, HIGH);

    // convertir el tiempo a distancia en centimetros
    distancia = duracion / 29.1 / 2 ;

    if (distancia <= RADIO_DE_DETECCION && distancia > 0)
        return true;

    return false;
}


bool detectar_izquierda(){
    long duracion, distancia;

    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(ULTRASONICO_IZQUIERDO_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONICO_IZQUIERDO_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONICO_IZQUIERDO_TRIGGER, LOW);
    duracion = pulseIn(ULTRASONICO_IZQUIERDO_ECHO, HIGH);

    // convertir el tiempo a distancia en centimetros
    distancia = duracion / 29.1 / 2 ;

    if (distancia <= RADIO_DE_DETECCION && distancia > 0)
        return true;

    return false;
}


bool detectar_derecha(){
    long duracion, distancia;

    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(ULTRASONICO_DERECHO_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONICO_DERECHO_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONICO_DERECHO_TRIGGER, LOW);
    duracion = pulseIn(ULTRASONICO_DERECHO_ECHO, HIGH);

    // convertir el tiempo a distancia en centimetros
    distancia = duracion / 29.1 / 2 ;

    if (distancia <= RADIO_DE_DETECCION && distancia > 0)
        return true;

    return false;
}


void girar_derecha(){
    digitalWrite(MOTOR_IZQUIERDO_PIN1, HIGH);
    digitalWrite(MOTOR_IZQUIERDO_PIN2, LOW);
    digitalWrite(MOTOR_DERECHO_PIN1, LOW);
    digitalWrite(MOTOR_DERECHO_PIN2, HIGH);
}


void girar_izquierda(){
    digitalWrite(MOTOR_IZQUIERDO_PIN1, LOW);
    digitalWrite(MOTOR_IZQUIERDO_PIN2, HIGH);
    digitalWrite(MOTOR_DERECHO_PIN1, HIGH);
    digitalWrite(MOTOR_DERECHO_PIN2, LOW);
}

void retroceder(){
    digitalWrite(MOTOR_IZQUIERDO_PIN1, LOW);
    digitalWrite(MOTOR_IZQUIERDO_PIN2, HIGH);
    digitalWrite(MOTOR_DERECHO_PIN1, LOW);
    digitalWrite(MOTOR_DERECHO_PIN2, HIGH);
}

void avanzar(){
    digitalWrite(MOTOR_IZQUIERDO_PIN1, HIGH);
    digitalWrite(MOTOR_IZQUIERDO_PIN2, LOW);
    digitalWrite(MOTOR_DERECHO_PIN1, HIGH);
    digitalWrite(MOTOR_DERECHO_PIN2, LOW);
}

void parar(){
    digitalWrite(MOTOR_IZQUIERDO_PIN1, LOW);
    digitalWrite(MOTOR_IZQUIERDO_PIN2, LOW);
    digitalWrite(MOTOR_DERECHO_PIN1, LOW);
    digitalWrite(MOTOR_DERECHO_PIN2, LOW);  
  
}

bool inicio;

void setup(){
    //pines de motores
    pinMode(MOTOR_IZQUIERDO_PIN1, OUTPUT);
    pinMode(MOTOR_IZQUIERDO_PIN2, OUTPUT);
    pinMode(MOTOR_DERECHO_PIN1, OUTPUT);
    pinMode(MOTOR_DERECHO_PIN2, OUTPUT);

    //pines de ultrasonicos
    pinMode(ULTRASONICO_DELANTERO_TRIGGER, OUTPUT);   
    pinMode(ULTRASONICO_DELANTERO_ECHO, INPUT);
    pinMode(ULTRASONICO_TRASERO_TRIGGER, OUTPUT);   
    pinMode(ULTRASONICO_TRASERO_ECHO, INPUT);
    pinMode(ULTRASONICO_IZQUIERDO_TRIGGER, OUTPUT);   
    pinMode(ULTRASONICO_IZQUIERDO_ECHO, INPUT);
    pinMode(ULTRASONICO_DERECHO_TRIGGER, OUTPUT);   
    pinMode(ULTRASONICO_DERECHO_ECHO, INPUT);

   inicio = true;

}

void loop() {
  // put your main code here, to run repeatedly:

  if (inicio){
    delay(5000);
    inicio = false;  
  }

  if (detectar_adelante())
    avanzar();

  else if (detectar_atras())
    retroceder();

  else if (detectar_izquierda())
    girar_izquierda();

  else if (detectar_derecha())
    girar_derecha();

  else 
    parar();
   
  delay(500);

}
