// Variables para los estados de A y B
int estadoA = 0;
int estadoB = 0;

// Variables para los pines de entrada
int w = 0;
int x = 0;
int y = 0;
int z = 0;

// Función para encender los segmentos del display
void encender(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(2, a);  // Segmento 'a'
  digitalWrite(3, b);  // Segmento 'b'
  digitalWrite(4, c);  // Segmento 'c'
  digitalWrite(5, d);  // Segmento 'd'
  digitalWrite(6, e);  // Segmento 'e'
  digitalWrite(7, f);  // Segmento 'f'
  digitalWrite(8, g);  // Segmento 'g'
}

// Inicializar pines
void setup() {
  pinMode(A1, INPUT); // A
  pinMode(A2, INPUT); // B
  pinMode(9, INPUT);  // w
  pinMode(10, INPUT); // x
  pinMode(11, INPUT); // y
  pinMode(12, INPUT); // z

  // Configurar pines de salida para el display
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
  }
}

// Función para mostrar el número en el display
void mostrarNumero(int numero) {
  switch (numero) {
    case 0: encender(1, 1, 1, 0, 1, 1, 1); break; // Muestra 0
    case 1: encender(0, 0, 1, 0, 0, 0, 1); break; // Muestra 1
    case 10: encender(1, 0, 1, 1, 1, 1, 1); break; // Muestra 10 (A)
    case 11: encender(1, 1, 1, 1, 1, 0, 0); break; // Muestra 11 (B)
    case 12: encender(1, 1, 0, 0, 1, 1, 0); break; // Muestra 12 (C)
    case 13: encender(1, 1, 1, 1, 0, 0, 1); break; // Muestra 13 (D)
    default: encender(1, 1, 1, 0, 1, 1, 1); break; // Muestra 0 por defecto
  }
}

// Loop principal
void loop() {
  // Leer los estados de los pines
  estadoA = digitalRead(A1);
  estadoB = digitalRead(A2);
  w = digitalRead(9);
  x = digitalRead(10);
  y = digitalRead(11);
  z = digitalRead(12);

  // Comprobar combinaciones y mostrar resultados
  if ((!estadoA && !estadoB) && (!z && !y && !x && !w)) {
    mostrarNumero(0);
  } else if ((!estadoA && !estadoB) && (!z && !y && !x && w)) {
    mostrarNumero(0);
  } else if ((estadoA ^ estadoB) && (!z && !y && !x && w)) {
    mostrarNumero(1);
  } else if ((estadoA && estadoB) && (!z && !y && !x && w)) {
    mostrarNumero(10);
  } else if ((!estadoA && !estadoB) && (!z && !y && x && !w)) {
    mostrarNumero(0);
  } else if ((estadoA && estadoB) && (!z && !y && x && !w)) {
    mostrarNumero(0);
  } else if ((estadoA && !estadoB) && (!z && !y && x && !w)) {
    mostrarNumero(1);
  } else if ((!estadoA && estadoB) && (!z && !y && x && !w)) {
    mostrarNumero(11);
  } else if ((estadoA && estadoB) && (!z && !y && x && w)) {
    mostrarNumero(1);
  } else if ((!estadoA && !estadoB) && (w && x && !y && !z)) {
    mostrarNumero(0);
  } else if ((estadoA && estadoB) && (!z && y && !x && !w)) {
    mostrarNumero(1);
  } else if ((!estadoA && !estadoB) && (!z && y && !x && !w)) {
    mostrarNumero(12);
  } else if ((estadoA && !estadoB) && (!z && y && !x && !w)) {
    mostrarNumero(13);
  } else if ((!estadoA && !estadoB) && (w && !x && y && !z)) {
    mostrarNumero(0);
  } else if ((estadoA && estadoB) && (!z && y && !x && w)) {
    mostrarNumero(1);
  } else if ((!estadoA && !estadoB) && (!w && x && y && !z)) {
    mostrarNumero(0);
  } else if ((estadoA || estadoB) && (!z && y && x && !w)) {
    mostrarNumero(1);
  } else if ((!z && y && x && w)) {
    mostrarNumero(estadoA ? 0 : 1);
  } else if ((!estadoA && !estadoB) && (!w && !x && !y && z)) {
    mostrarNumero(0);
  } else if ((estadoA ^ estadoB) && (z && !y && !x && !w)) {
    mostrarNumero(1);
  } else if ((!estadoA && !estadoB) && (w && !x && !y && z)) {
    mostrarNumero(0);
  } else if (!(estadoA ^ estadoB) && (z && !y && !x && w)) {
    mostrarNumero(1);
  } else if (!(estadoA && estadoB) && (z && !y && x && !w)) {
    mostrarNumero(1);
  } else if ((estadoA && estadoB) && (z && !y && x && !w)) {
    mostrarNumero(0);
  } else if (!(estadoA || estadoB) && (z && !y && x && w)) {
    mostrarNumero(1);
  } else if ((estadoA || estadoB) && (z && !y && x && w)) {
    mostrarNumero(0);
  }
}