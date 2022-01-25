
//** EXPLOSIÓN DE ENERGÍA A LAS 3 AM **//

//** Definiciones **//
int rojo=2;      //definimos el valor del pin para el led rojo
int amarillo=4;  //definimos el valor del pin para el led amarillo
int verde=7;     //definimos el valor del pin para el led verde

void setup() {
  pinMode(rojo,OUTPUT);    //declaramos el pin rojo como salida
  pinMode(amarillo,OUTPUT);//declaramos el pin amarillo como salida
  pinMode(verde,OUTPUT);   //declaramos el pin verde como salida  
}

void loop() {
 
 digitalWrite(verde,HIGH); //encendemos el led verde
 delay(1000);              //esperamos 2 segundos
 digitalWrite(verde,LOW);  //apagamos el led verde
 delay(10);               //esperamos medio segundo

 digitalWrite(amarillo,HIGH); //encendemos el led amarillo
 delay(1000);                 //esperamos 2 segundos
 digitalWrite(amarillo,LOW);  //apagamos el led amarillo
 delay(10);                  //esperamos medio segundo
 
 digitalWrite(rojo,HIGH); //encendemos el led rojo
 delay(1000);             //esperamos 2 segundos
 digitalWrite(rojo,LOW);  //apagamos el led rojo
 delay(10);              //esperamos medio segundo

}
