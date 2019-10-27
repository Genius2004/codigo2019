//#VERSION: 1.0
/*######################################################################################################################
  ###  PROYECTO:              Encuentrame                                                                            ###
  ###                                                                                                                ###
  ###  DESARROLLADORES:       Gudelia Hernández Molina         GHM                                                   ###
  ###  FECHA DE INICIO:       Viernes 26, octubre del 2019                                                           ###
  ###                                                                                                                ###
  ######################################################################################################################
   VERSION:
    V.1.00      (20191025 -         ) GHM: Primera Versión

   CAMBIOS:
    V.1.0.X    (1910XX)  GHM:

    Requerimientos:
    1. Programar el sensor ultrasonico

    Apoyo: https://programarfacil.com/tutoriales/fragmentos/sensor-de-ultrasonidos-con-arduino/
   
######################################################################################################################*/

// Configuramos los pines del sensor Trigger y Echo
const int PinTrig = 2;
const int PinEcho = 3;
 
// Constante velocidad sonido en cm/s
const float VelSon = 34000.0;
 
float distancia;
 
void setup()
{
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  // Ponemos el pin Trig en modo salida
  pinMode(PinTrig, OUTPUT);
  // Ponemos el pin Echo en modo entrada
  pinMode(PinEcho, INPUT);
}

void loop()
{
  iniciarTrigger();
  
  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(PinEcho, HIGH);
  
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  distancia = tiempo * 0.000001 * VelSon / 2.0;
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
 
// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger()
{
  // Ponemos el Trigger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);
  
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);
  
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}
