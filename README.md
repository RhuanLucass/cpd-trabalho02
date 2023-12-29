# Trabalho Prático II - Classificação e Pesquisa de Dados

**Grupo:** Davi Santos Ferrarez, Rhuan Lucas Barbosa Fernandes  
**Curso:** Engenharia de Computação  

## Experimento 1 - Comparação de Algoritmos de Transformação de Chave (Hashing)

### Introdução
O Experimento 1 visa comparar o tempo de execução para inserção e busca em diferentes tipos de algoritmos de transformação de chave (hashing). A tabela hash é a generalização de um vetor com associação entre chaves e valores, visando buscar de forma rápida através de uma chave simples e encontrar o valor desejado.

### Tabela (tempo em segundos) e Discussão dos Resultados
#### Teste 1
- Tamanho do vetor: 100 mil
- Tamanho vetor endereçamento aberto: 200 mil
- Tamanho vetor lista encadeada: 5 mil

| Algoritmo    | Sondagem Linear | Sondagem Quadrática | Lista Encadeada |
|--------------|-----------------|---------------------|-----------------|
| Inserção     | 0.004           | 0.002               | 0.012           |
| Busca        | 0.005           | 0.002               | 0.019           |

#### Teste 2
- Tamanho do vetor: 100 mil elementos
- Tamanho vetor endereçamento aberto: 100001
- Tamanho vetor lista encadeada: 99999

| Algoritmo    | Sondagem Linear | Sondagem Quadrática | Lista Encadeada |
|--------------|-----------------|---------------------|-----------------|
| Inserção     | 0.005           | 0.003               | 0.012           |
| Busca        | 0.005           | 0.002               | 0.020           |

#### Teste 3
- Tamanho do vetor: 100 mil elementos
- Tamanho vetor endereçamento aberto: 150 mil
- Tamanho vetor lista encadeada: 50 mil

| Algoritmo    | Sondagem Linear | Sondagem Quadrática | Lista Encadeada |
|--------------|-----------------|---------------------|-----------------|
| Inserção     | 0.004           | 0.002               | 0.011           |
| Busca        | 0.004           | 0.001               | 0.020           |

### Conclusão
Através dos testes realizados, observamos que o hashing de endereçamento aberto com sondagem quadrática obteve o melhor tempo em todas as tentativas. Isso se deve ao fato de que a sondagem quadrática encontra uma posição livre no vetor mais rapidamente do que a linear. Além disso, a tabela hash com lista encadeada percorre toda a lista referente à chave, resultando em um tempo maior.

## Experimento 2 - Árvore Binária de Busca (ABB) e Árvore AVL

### Introdução
O Experimento 2 compara dois algoritmos: Árvore Binária de Busca (ABB) e Árvore AVL. A ABB possui cada nó como um objeto contendo atributos left, right e p, enquanto a AVL é balanceada, garantindo que a diferença de altura entre subárvores direita e esquerda seja 1, 0 ou -1.

### Tabela (tempo em segundos) e Discussão dos Resultados
- Tempo de inserção
- Tempo de busca
- Tempo de remoção

| Algoritmo | Inserção | Busca | Remoção |
|-----------|----------|-------|---------|
| ABB       | 0.002    | 0.001 | 0.227   |
| AVL       | 0.002    | 0.001 | 0.259   |

### Conclusão
Observou-se que o tempo de inserção e busca em ambos os algoritmos é aproximadamente igual. No entanto, a AVL apresenta um tempo de remoção menor em comparação com a ABB. O tempo de busca em ambos os algoritmos é mais rápido que o tempo de inserção. O tempo de remoção em ambas as árvores é consideravelmente mais longo em comparação com os outros casos.

Para acessar o trabalho completo, utilize os seguintes links:
- [Experimento 1 no GitHub](https://github.com/RhuanLucass/cpd-trabalho02/tree/master/Experimento1)
- [Experimento 2 no GitHub](https://github.com/RhuanLucass/cpd-trabalho02/blob/master/Experimento2/main.c)
