typedef struct {
  char cidade[20];
  float *temperatura;
} TMedidas;

typedef struct {
  int qtde_dias;
  int qtde_medidas;
  TMedidas *medidas;
} TTemperaturas;
