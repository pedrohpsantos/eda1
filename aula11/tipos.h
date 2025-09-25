typedef struct {
  int id;         // codigo do produto
  int quantidade; // quantitativo do produto em estoque
  float preco;    // preco unitario do produto
} TProduto;

typedef struct {
  int qtdeProdutos;   // quantidade maxima de diferentes produtos (QMP)
  TProduto *produtos; // vetor contendo os detalhes de cada produto
} TEstoque;
