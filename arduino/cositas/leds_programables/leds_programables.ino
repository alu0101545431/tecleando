//** Definiciones **//
int rojo=2;      //definimos el valor del pin para el led rojo
int amarillo=4;  //definimos el valor del pin para el led amarillo
int verde=7;     //definimos el valor del pin para el led verde
int tiempo=900;  //variable de pausa entre cada encendido
int v=9;         //multiplicador para conseguir los milisegundos de pausa a partir del monitor serie


void setup() {
  Serial.begin(9600);
  pinMode(rojo,OUTPUT);    //declaramos el pin rojo como salida
  pinMode(amarillo,OUTPUT);//declaramos el pin amarillo como salida
  pinMode(verde,OUTPUT);   //declaramos el pin verde como salida
  Serial.println("Introduzca un valor entre 1 y 9");  
}

void loop() {
if (Serial.available()>0){               // Comprueba si el serial está disponible
    v =  Serial.read()-48;      // leemos el valor del monitor serial y se transforma    
    if (v >= 1 && v <= 9)  // Si el valor introducido está entre 1 y 9
    {
      tiempo = v*100;
      
      Serial.print("El intervalo de tiempo es : ");
      Serial.print(tiempo);
      Serial.println(" milisegundos");      
      Serial.println("Introduzca un valor entre 1 y 9");
      
    }
    else {                                 // Si introducimos un valor erroneo
      Serial.println("El dato introducido es incorrecto");
      Serial.println("Introduzca un valor entre 1 y 9");
      delay (200);
    }
  }
else {
  digitalWrite(verde,HIGH); //encendemos el led verde
  delay(tiempo);              //esperamos 2 segundos
  digitalWrite(verde,LOW);  //apagamos el led verde
  delay(tiempo);               //esperamos medio segundo

  digitalWrite(amarillo,HIGH); //encendemos el led amarillo
  delay(tiempo);                 //esperamos 2 segundos
  digitalWrite(amarillo,LOW);  //apagamos el led amarillo
  delay(tiempo);                  //esperamos medio segundo
 
  digitalWrite(rojo,HIGH); //encendemos el led rojo
  delay(tiempo);             //esperamos 2 segundos
  digitalWrite(rojo,LOW);  //apagamos el led rojo
  delay(tiempo);              //esperamos medio segundo
  }
}