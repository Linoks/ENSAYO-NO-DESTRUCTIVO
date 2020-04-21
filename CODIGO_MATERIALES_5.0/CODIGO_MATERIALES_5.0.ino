
//El valor de la resistencia del amplificador de instrumentacion para temperatura puede variar segun los parametros relacionados con el sensor
//Para un correto fucnionamiento del circuito es necesario configurar los potenciometros de corriente con un amermetro ,el potenciometro de frecuencia del equipo tambien debe ser configurado con un osciloscopio
//el proceso es realizar una rela de tres y verificar los valores mediante la prediccionde datos
//Los valores de amplificacion de los modulos de barkhausen,grietas y ultraosnido dependeran del  ususrio
//para el modulo de ultrasonido se requerira un transductor especial
#include <LiquidCrystal.h> // Librería para el control del LCD
#include <Keypad.h>        // Librería para el control del keypad

//resisitividad
float area;
float contactos;
float F1 = 4.3669;
float F2 = 2.3707;

//sensor de temperatura CONFIGURACION RESISTENCIAS Y VARIABLES DE VOLTAJE
float tempR1 = 6800;
float tempR2 = 100;
float tempR3 = 6800;
float tempVS;
float voltajetemp;
float vwheastonetemp;
float Resistenciatemp;
float temperatura;
///////////////////corriente/////////////
float vcurrent;
float i;
//////////////////frecuencia/////////////
float vfrecuencia;
float f;
/////////////////barkhausen//////////////
float vBARKHAUSEN;
float vBARKHAUSENREAL;
/////////////////GRIETA/////////////////
float vGRIETA;
float vGRIETAREAL;
/////////////////ULTRASONIDO/////////////////
float vULTRA;
float vULTRAREAL;

//sensor de voltaje de fuente de alimentacion
int R1 = 10;
float R2 = 0.235;
int R3 = 10;
float Vg;
float Vs;

// Declaracion de variables globales
float voltajeampli;
float vbarra;
float Resistencia;
float Resistividad;

///////////////////////////////////////COLOCAR LONGITUD /////////////////////////////////////
int PRI = 0;            //Variable a mostrar por LCD digitos
int SEG = 0;            
int TER = 0;
int CUA = 0;
int QUI = 0;
int SEX = 0;
char key ;

/////////////////////////////////////////////////////////////////////////////////

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // varible LCD y pines
char pulsacion;                      // almacena la tecla pulsada
int  contador = 1;                   // cuenta el nivel del menu en el que se esta
const byte ROWS = 4;                 //Cuatro Filas
const byte COLS = 4;                 //Cuatro Columnas
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8};      //Puntos de conexion del teclado al arduino FILAS
byte colPins[COLS] = {121, 111, 13, 12};  //Puntos de conexion del teclado al arduino COLUMNAS
Keypad Teclado1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Configura el teclado

void setup () {

  pinMode(1, OUTPUT);  
  pinMode(0, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  
  intro_0();  //llama a la funcion que  muestra el intro de  bienvenida
}
void loop() {
  pulsacion = Teclado1.getKey() ;  // Lee la tecla pulsada
  if (pulsacion != 0) {
    delay(100);
  }
  // CON CONTADOR ME MUEVO A TRAVES DE MENUS,CADA MENU TIENE SU CONTADOR
  if (contador == 19) {
    menu_19();  //MENU
    accion_19();
  }
 
  if (contador == 18) {
    menu_18();  //MENU
    accion_18();
  }
  if (contador == 17) {
    menu_17();  //MENU
    accion_17();
  }
  if (contador == 16) {
    menu_16();  //MENU
    accion_16();
  }
  if (contador == 15) {
    menu_15();  //MENU 
    accion_15();
  }
  if (contador == 14) {
    menu_14();  //MENU 
    accion_14();
  }
  if (contador == 13) {
    menu_13();  //MENU 
    accion_13();
  }
  if (contador == 12) {
    menu_12();  //MENU 
    accion_12();
  }
  if (contador == 11) {
    menu_11();  //MENU 
    accion_11();
  } if (contador == 10) {
    menu_10();  //MENU 
    accion_10();
  }
  if (contador == 9) {
    menu_9();  //MENU
    accion_9();
  }
  
  if (contador == 8) {
    menu_8();  //MENU
    accion_8();
  }
  if (contador == 7) {
    menu_7();  //MENU
    accion_7();
  }
  if (contador == 6) {
    menu_6();  //MENU
    accion_6();
  }
  if (contador == 5) {
    menu_5();  //MENU 
    accion_5();
  }
  if (contador == 4) {
    menu_4();  //MENU 
    accion_4();
  }
  if (contador == 3) {
    menu_3();  //MENU 
    accion_3();
  }
  if (contador == 2) {
    menu_2();  //MENU 
    accion_2();
  }
  if (contador == 1) {
    menu_1();  //MENU 
    accion_1();
  } if (contador == 21) {
    menu_21();  //MENU 
    accion_21();
  }


}  

/////////////////////Intro_0 ///////////////////////////////////////////////////
void intro_0() {
  lcd.clear();                 // Borra el  LCD
  lcd.setCursor(1, 0);         // Se posiciona en la Columna 3, Fila 0
  lcd.print(" CONFIGURACION");
  lcd.setCursor(0, 1);
  lcd.print("BIENVENIDO E-N-D");
  delay(1000);                // espera 1 segundos mostrando el intro
  lcd.clear();
}
/////////////////////Menu_0 ESTE MENU CONTIENE LA SELECCION DEL ENSAYO //////////////////////////////////
void menu_1() {
  lcd.setCursor(0, 0);
  lcd.print("RDM->A");
  lcd.setCursor(10, 0);
  lcd.print("RMB->B");
  lcd.setCursor(0, 1);
  lcd.print("SPG->C");
  lcd.setCursor(10, 1);
  lcd.print("UTS->D");
}

void accion_1() {
  if (pulsacion == 'A') { //SI SE PRESIONA A VAMOS A MEDIR RESISTIVDIAD
    contador = 21;
    lcd.clear();
  }
  if (pulsacion == 'B') { //SI SE PRESIONA B VAMOS A MEDIR BARKHAUSEN
    contador = 7;
    lcd.clear();
  }
  if (pulsacion == 'C') { //SI SE PRESIONA C VAMOS A VER GRIETAS
    contador = 13;
    lcd.clear();
  }
  if (pulsacion == 'D') { //SI SE PRESIONA D VAMOS A MEDIR POR ULTRASONIDO
    contador = 16;
    lcd.clear();
  }
}
void menu_21() {
  lcd.setCursor(1, 0);
  lcd.print("INTRODUCE AREA");
  lcd.setCursor(7, 1);
  lcd.print("mm^2");
  lcd.setCursor(12, 1);
  lcd.print("NEXT");
}
/////////////////////Accion 21 //////////////////////////////
void accion_21() {

  if (pulsacion == 'A')             //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a A
  {
    PRI = PRI + 1 ;
    if (PRI == 10) PRI = 0;
    delay(250);
  }

  if (pulsacion == 'B')            //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a B
  {
    SEG = SEG + 1;
    if (SEG == 10) SEG = 0;
    delay(25);
  }

  if (pulsacion == 'C')            //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a C
  {
    TER = TER + 1;
    if (TER == 10) TER = 0;
    delay(25);
  }

  if (pulsacion == 'D')            //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a D
  {
    CUA = CUA + 1;
    if (CUA == 10) CUA = 0;
    delay(25);
  }
  if (pulsacion == '6')           //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a 6
  {
    QUI = QUI + 1;
    if (QUI == 10) QUI = 0;
    delay(25);
  }
  if (pulsacion == '9')           //Si el boton ha sido pulsado, aumentamos lOS digitos que corresponden a 9
  {
    SEX = SEX + 1;
    if (SEX == 10) SEX = 0;
    delay(25);
  }
  //si llega a 9 y se presiona el boton automaticamente baja a cero
  lcd.setCursor(0, 1);

  if (PRI > 9) PRI = 0;
  lcd.print(PRI);

  if (SEG > 9) SEG = 0;
  lcd.print(SEG);

  if (TER > 9) TER = 0;
  lcd.print(TER);

  if (CUA > 9) CUA = 0;
  lcd.print(CUA);

  if (QUI > 9) QUI = 0;
  lcd.print(QUI);

  if (SEX > 9) SEX = 0;
  lcd.print(SEX);


  area = 0.0001 * PRI + 0.00001 * SEG + 0.000001 * TER + 0.0000001 * CUA + 0.00000001 * QUI + 0.000000001 * SEX ;


  if (pulsacion == '#') {
    contador = 2;
    PRI = 0;
    SEG = 0;
    TER = 0;
    CUA = 0;
    QUI = 0;
    SEX = 0;
    lcd.clear();
  }

}

/////////////////////Menu_2 ANCHO MUESTRA //////////////////////////////////
void menu_2() {

  lcd.setCursor(0, 0);
  lcd.print("INTRODUCE DISTANC");
  lcd.setCursor(9, 1);
  lcd.print("mm");
  lcd.setCursor(12, 1);
  lcd.print("NEXT");
}
/////////////////////Accion 2 //////////////////////////////
void accion_2() {

  if (pulsacion == 'A')
  {
    PRI = PRI + 1 ;
    if (PRI == 10) PRI = 0;
    delay(250);
  }

  if (pulsacion == 'B')
  {
    SEG = SEG + 1;
    if (SEG == 10) SEG = 0;
    delay(25);
  }

  if (pulsacion == 'C')
  {
    TER = TER + 1;
    if (TER == 10) TER = 0;
    delay(25);
  }

  if (pulsacion == 'D')
  {
    CUA = CUA + 1;
    if (CUA == 10) CUA = 0;
    delay(25);
  }
  if (pulsacion == '6')
  {
    QUI = QUI + 1;
    if (QUI == 10) QUI = 0;
    delay(25);
  }
  if (pulsacion == '9')
  {
    SEX = SEX + 1;
    if (SEX == 10) SEX = 0;
    delay(25);
  }

  lcd.setCursor(0, 1);

  if (PRI > 9) PRI = 0;
  lcd.print(PRI);

  if (SEG > 9) SEG = 0;
  lcd.print(SEG);

  if (TER > 9) TER = 0;
  lcd.print(TER);

  if (CUA > 9) CUA = 0;
  lcd.print(CUA);

  if (QUI > 9) QUI = 0;
  lcd.print(QUI);

  if (SEX > 9) SEX = 0;
  lcd.print(SEX);


  contactos = 0.0001 * PRI + 0.00001 * SEG + 0.000001 * TER + 0.0000001 * CUA + 0.00000001 * QUI + 0.000000001 * SEX ;


  if (pulsacion == '#') {
    contador = 3;
    PRI = 0;
    SEG = 0;
    TER = 0;
    CUA = 0;
    QUI = 0;
    SEX = 0;
    lcd.clear();
  }
}
/////////////////////Menu_3 configurar valor de corriente //////////////////////////////////
void menu_3() {
  //variar la corrinte a partir del voltaje sensado del potenciometros ya que existe una relacion lineal
  vcurrent = analogRead(A4);
  vcurrent = vcurrent * 5 / 1024;
  i = 1.5 * vcurrent / 2.5;
  lcd.setCursor(0, 0);
  lcd.print("  CORRIENTE(I)");
  lcd.setCursor(5, 1);
  lcd.print(i);
  lcd.setCursor(11, 1);
  lcd.print("A");//
}
/////////////////////accion_3  //////////////////////////////////
void accion_3() {
  if (pulsacion == '#') {
    contador = 4;
    lcd.clear();
  }
}
/////////////////////Menu_4 //////////////////////////////////
void menu_4() {
  lcd.setCursor(0, 0);
  lcd.print("VER CON LCD  ->A");
  lcd.setCursor(0, 1);
  lcd.print("VER CON PC   ->B");
}
/////////////////////accion_4  //////////////////////////////////
void accion_4() {
  if (pulsacion == 'A') {
    contador = 5;
    lcd.clear();
  }
  if (pulsacion == 'B') {
    contador = 6;
    lcd.clear();
  }
}
/////////////////////Menu_5 ver en lcd//////////////////////////////////
void menu_5() {

  voltajeampli = analogRead(A5);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLIFICADOR
  //---------------------CALCULO DE RESISTIVIDAD----------------------
  // Calculamos el voltaje de Salida del amplificador
  voltajeampli = 5 * voltajeampli / 1024;
  //Calculamos voltaje en la barra
  vbarra = (voltajeampli / 5000);
  //Calculamos la resistencia
  Resistencia = vbarra / i ;
  // Calculamos la resistividad
  Resistividad = Resistencia * area * contactos;

  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("RDM");
  lcd.setCursor(0, 1);
  lcd.print("RES:");//
  lcd.setCursor(4, 1);
  //imprime el valor de resisitividad en LCD
  lcd.print(Resistividad);
  lcd.setCursor(11, 1);
  lcd.print("Ohm*m");
}
/////////////////////accion_5  //////////////////////////////////
void accion_5() {
  if (pulsacion == '#') {
    contador = 6;
    lcd.clear();
  }
}
/////////////////////Menu_6 //////////////////////////////////
void menu_6() {
  Serial.begin(9600);
  voltajeampli = analogRead(A5);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLIFICADOR
  //---------------------CALCULO DE RESISTIVIDAD----------------------
  // Calculamos el voltaje de Salida del amplificador
  voltajeampli = 5 * voltajeampli / 1024;
  //Calculamos voltaje en la barra
  vbarra = (voltajeampli / 5000);
  //Calculamos la resistencia
  Resistencia = vbarra / i ;
  // Calculamos la resistividad
  Resistividad = Resistencia * area * contactos;
  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);         //VOLTAJE DE PUENTE DE WHEASTONE
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = 2 * tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("RDM");
  lcd.setCursor(0, 1);
  lcd.print("  COMPARTIENDO");
  Serial.println(Resistividad  , 5);
  delay(100);
}
/////////////////////accion_6  //////////////////////////////////
void accion_6() {

}

/////////////////////Menu_7 rango de frecuencia, se tendra que obtener la regla de tres para la selecion de frecuencias con osciloscopio,comparando valores y prediciondo valores(regresion lineal) //
void menu_7() {

  lcd.setCursor(0, 0);
  lcd.print("RANGO FRECUENCIA");
  lcd.setCursor(0, 1);
  lcd.print("50");
  lcd.setCursor(4, 1);
  lcd.print("10K");
  lcd.setCursor(9, 1);
  lcd.print("1M");
  lcd.setCursor(12, 1);
  lcd.print("10M");
}
/////////////////////accion_7  //////////////////////////////////
void accion_7() {

  if (pulsacion == '#') {
    contador = 8;
  }
}
/////////////////////Menu_8  //////////////////////////////////
void menu_8() {

  vfrecuencia = analogRead(A2);
  vfrecuencia = vfrecuencia * 5 / 1024;
  f = 1.5 * vcurrent / 2.5; //un valor que te permitira establecer una relacion entre frecuncia y voltaje del ptenciometro
  lcd.setCursor(0, 0);
  lcd.print("SELECT FRECUENCIA");
  lcd.setCursor(11, 1);
  lcd.print("Ohm*m");
}

/////////////////////accion_8  //////////////////////////////////
void accion_8() {
  if (pulsacion == '#') {
    contador = 9;
  }
}
//se realiza de manera manual//
void menu_9() {
  lcd.setCursor(0, 0);
  lcd.print("SELECT SIN-SQR-TRI");

  lcd.setCursor(0, 1);
  lcd.print("SIN>A");
  lcd.setCursor(6, 1);
  lcd.print("TRI >B");
  lcd.setCursor(12, 1);
  lcd.print("TRI>A");
}
void accion_9() {
  if (pulsacion == '#') {
    contador = 10;
  }
}
void menu_10() {
  lcd.setCursor(0, 0);
  lcd.print("ESCUCHAR     ->A");
  lcd.setCursor(0, 1);
  lcd.print("VER CON PC   ->B");
}
void accion_10() {
  if (pulsacion == 'A') {
    contador = 11;
    lcd.clear();
  }
  if (pulsacion == 'B') {
    contador = 12;
    lcd.clear();
  }
}
// ver con lcd//
void menu_11() {
  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);         //PUERTO ANALOGICO PARA VOLTAJE DE PUENTE DE WHEASTONE
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = 2*tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  // BARKHAUSEN
  vBARKHAUSEN = analogRead(A3);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLIFICADOR
  // Calculamos el voltaje de Salida del amplificador
  vBARKHAUSEN = 5 * vBARKHAUSEN / 1024;
  //Calculamos voltaje en la barra
  vBARKHAUSENREAL = (vBARKHAUSEN / 5000);
 // el valor se envia haci el parlante
  digitalWrite(1, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("RMB");
  lcd.setCursor(0, 1);
  lcd.print("ESCUCHANDO");
  Serial.println(voltajeampli , 20);
  delay(100);

}
void accion_11() {
}
//barkhausen compartiendo//
void menu_12() {
  Serial.begin(9600);
  vBARKHAUSEN = analogRead(A3);   //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLI
  // Calculamos el voltaje de Salida del amplificador
  vBARKHAUSEN = 5 * vBARKHAUSEN / 1024;
  //Calculamos voltaje en la barra
  vBARKHAUSENREAL = (vBARKHAUSEN / 5000);

  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS =2* tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("RMB");
  lcd.setCursor(0, 1);
  lcd.print("COMPARTIENDO");
  Serial.println(vBARKHAUSEN , 20);
  delay(100);
}
void accion_12() {
// equipo destinado a las grietas//
}
void menu_13() {
  lcd.setCursor(0, 0);
  lcd.print("VER CON LCD  ->A");
  lcd.setCursor(0, 1);
  lcd.print("VER CON PC   ->B");
}
void accion_13() {

  if (pulsacion == 'A') {
    contador = 14;
    lcd.clear();
  }
  if (pulsacion == 'B') {
    contador = 15;
    lcd.clear();
  }
}
///El efecto se observara a traves del led verde , cuando haya grieta el led verde se encendera
void menu_14() {
  vGRIETA = analogRead(A1);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLI
  //---------------------CALCULO DE GRIETA----------------------
  // Calculamos el voltaje de Salida del amplificador
  vGRIETA = 5 * vGRIETA / 1024;
  //Calculamos voltaje en la barra
  vGRIETAREAL = (vGRIETA / 5000); //CAMBIAR EL VALOR DEL AMPLIFICADOR OPERACONAL
  if (vGRIETAREAL > 1 ) {
   digitalWrite(0,HIGH);
  }
  //temperatura
  tempVS = 2*tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("SPG");
  lcd.setCursor(0, 1);
  lcd.print("PUT FREQ:60Hz ");
}
void accion_14() {
}
//COMPARTIR CON PANTALLA 
void menu_15() {
  Serial.begin(9600);
  vGRIETA = analogRead(A1);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLI
  //---------------------CALCULO DE GRIETA----------------------
  // Calculamos el voltaje de Salida del amplificador
  vGRIETA = 5 * vGRIETA / 1024;
  //Calculamos voltaje en la barra
  vGRIETAREAL = (vGRIETA / 5000); //CAMBIAR EL VALOR DEL AMPLIFICADOR OPERACONAL
  
  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("SPG");
  lcd.setCursor(0, 1);
  lcd.print("COMPARTIENDO");
  Serial.println(vGRIETAREAL * 1000 , 20); // LO MULTIPLICAMOS POR 1000 PARA VER EL EFECTO EN EL MONITOR SERIAL
  delay(100);
}
void accion_15() {

}
void menu_16() {

  lcd.setCursor(0, 0);
  lcd.print("VER EN LCD   ->A");
  lcd.setCursor(0, 1);
  lcd.print("VER CON PC   ->B");
}
void accion_16() {
  if (pulsacion == 'A') {
    contador = 17;
    lcd.clear();
  }
  if (pulsacion == 'B') {
    contador = 18;
    lcd.clear();
  }
}

void menu_17() {
  vULTRA = analogRead(A0);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLI
  // Calculamos el voltaje de Salida del amplificador
  vULTRA = 5 * vULTRA / 1024;
  //Calculamos voltaje en la barra
  vULTRAREAL = (vULTRA / 5000); //CAMBIAR EL VALOR DEL AMPLIFICADOR OPERACONAL

  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("SPG");
  if (vULTRA  > 2.5) {
    lcd.setCursor(0, 1);
    lcd.print(vULTRA);
    lcd.setCursor(6, 1);
    lcd.print("GRIETA");
  }
  if (vULTRA < 2.5) {
    lcd.setCursor(0, 1);
    lcd.print(vULTRA);
    lcd.setCursor(6, 1);
    lcd.print("NO GRIETA");
  }

}
void accion_17() {

}
void menu_18() {
  Serial.begin(9600);
    //---------------------CALCULO DE ULTRASONIDO----------------------
  vULTRA = analogRead(A0);  //PUERTO ANALOGICO PARA EL VOLTAJE DEL AMPLI
  // Calculamos el voltaje de Salida del amplificador
  vULTRA = 5 * vULTRA / 1024;
  //Calculamos voltaje en la barra
  vULTRAREAL = (vULTRA / 5000); //CAMBIAR EL VALOR DEL AMPLIFICADOR OPERACONAL

  //TEMPERATURA
  voltajetemp = analogRead(A7);    //PUERTO ANALOGICO PARA LA TEMPERATURA
  tempVS = analogRead(A6);
  //-------------------CALCULO DE TEMPERATURA-------------------------
  tempVS = tempVS * 5 / 1024;
  // Calculamos el voltaje de Salida del amplificador
  voltajetemp = 5 * voltajetemp / 1024;
  //Calculamos voltaje diferencial puente de wheastone
  vwheastonetemp = -voltajetemp / 134.3;
  //Calculamos la resistencia
  Resistenciatemp = ((tempR3 * tempR2 * tempVS) - (tempR3 * vwheastonetemp * (tempR1 + tempR2))) / ((vwheastonetemp * (tempR1 + tempR2)) + (tempVS * tempR1));
  temperatura = (Resistenciatemp - 100) / (100 * 0.003243);
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.setCursor(5, 0);
  lcd.print(temperatura);
  lcd.setCursor(13, 0);
  lcd.print("SPG");
  Serial.println(vULTRAREAL * 1000 , 7); // LO MULTIPLICAMOS POR 1000 PARA VER EL EFECTO EN EL MONITOR SERIAL
  delay(100);
}
void accion_18() {

}

void menu_19() {

}
void accion_19() {

}
