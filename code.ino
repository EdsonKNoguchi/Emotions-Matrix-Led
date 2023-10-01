//------------- Edson Noguchi -------------//


#include <LedControl.h> // Inclui biblioteca

// Define os pinos de conexão com a matriz MAX7219
const int DIN_PIN = 12;   // Pino de dados
const int CS_PIN = 11;    // Pino de seleção de chip
const int CLK_PIN = 10;   // Pino de clock

LedControl lc=LedControl(DIN_PIN,CLK_PIN,CS_PIN,1);  // Inicializa a biblioteca (OBS: 1 representa uma matriz)

void setup() {
  lc.shutdown(0,false);  // Ativa o controlador
  lc.setIntensity(0,8);  // Define a intensidade do brilho (0-15)
  lc.clearDisplay(0);    // Limpa a tela
} 

// Padrões possíveis para a matriz

byte feliz[8] = {
    B00000000,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00111100
  };
  byte normal[8] = {
    B00000000,
    B00000000,
    B00000000,
    B10000001,
    B11111111,
    B10000001,
    B00000000,
    B00000000
  };
  byte triste[8] = {
    B00111100,
    B01000010,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B00000000
  };
  byte susto[8] = {
    B00000000,
    B00000000,
    B00000000,
    B00111100,
    B00100100,
    B00111100,
    B00000000,
    B00000000
  };

void loop() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,feliz[i]);      // feliz será representado na matriz
  }
  delay(1000);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,normal[i]);      // normal será representado na matriz
  }
  delay(1000);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,susto[i]);      // susto será representado na matriz
  }
  delay(1000);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,triste[i]);      // triste será representado na matriz
  }
  delay(1000);
}
