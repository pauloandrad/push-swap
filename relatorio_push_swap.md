# Relatório Final: Push Swap

Este documento resume detalhadamente todas as modificações realizadas em relação à base de código original que o seu colega havia deixado. Ao final, há uma explicação sobre como o Quick Sort foi implementado no projeto para você arrasar na avaliação!

---

## 1. Arquivos Modificados e o que Mudou

### `Makefile`
- O arquivo fazia referência a um arquivo fantasma chamado `src/algorithms/base.c` que impedia o projeto de compilar (provavelmente o seu amigo renomeou o arquivo mas esqueceu de atualizar no Makefile). 
- **Solução:** Removi `base.c` e adicionei os corretos `base_three.c`, `base_five.c` e o recém-criado `base_utils.c`.

### `src/stack/stack_push_pop_swap.c`
- **Bug crítico:** A função `stack_swap_top` (responsável pelos comandos `sa` e `sb`) apenas trocava a variável `value` de lugar, esquecendo-se da variável `rank`. Como toda a lógica dos algoritmos mais avançados se baseava no `rank`, dar um simples `sa` arruinava a lógica.
- **Solução:** Adicionei a lógica para trocar a propriedade `rank` simultaneamente à propriedade `value`.

### `src/algorithms/strategy_factory.c`
- A função adaptativa `select_strategy` apenas olhava a porcentagem de *disorder* para escolher o algoritmo, sem olhar a quantidade de números.
- **Solução:** Adicionei uma condição `if (ps->size_a <= 5)` para que o projeto sempre "force" a estratégia `SIMPLE` caso receba 5 ou menos números, como você havia solicitado.

### `src/algorithms/simple.c`
- A função original utilizava o `bubble_sort` que demorava *muito* (dezenas de operações para 5 números).
- **Solução:** Removi o *bubble sort* e instruí a função `run_simple` a apenas chamar as funções `base_three_a` e `base_five_a` diretamente. 

### `src/algorithms/medium.c`
- Este é o arquivo que roda a estratégia *Medium* (famoso Chunk Sort). 
- **Solução:** Apenas realizei um "tuning". Mudei a matemática do tamanho do *chunk* de `5%` para `11%` (`(ps->size_a * 11 / 100) + 15`). Apenas essa pequena mudança derrubou o total de operações para a casa das ~5800 nos testes grandes.

### `src/algorithms/complex.c` & `src/algorithms/base_utils.c` (Causa do `KO`)
- **Bug da Partição:** O código de Quick Sort (`complex.c`) recursivo tentava utilizar um atalho: se o pedaço da pilha que ele estava analisando tivesse 3 números, ele chamava a função `base_three_a`. Porém, o `base_three` utiliza `ra` e `rra` que rotacionam a pilha *inteira*. Fazer isso quando você está no meio de 500 números esmagava o Quick Sort e causava o **KO**! Além disso, esse arquivo estava quebrando a regra de "no máximo 5 funções por arquivo" da *Norminette*.
- **Solução:** Criei um arquivo `base_utils.c` separando os atalhos. Agora, a regra de atalho verifica se a pilha inteira tem 3 elementos (`if (size == 3 && ps->size_a == 3)`). Se não tiver, o QuickSort continua a dividir a pilha sem jogar os números para o fundo. 

> [!NOTE]
> Adicionalmente, foram feitas pequenas correções de **Norminette** (espaçamentos, quebras de linhas, e protótipos incorretos em `includes/push_swap.h`, `src/main.c`, `src/stack/stack_new.c`, `src/algorithms/base_three.c`, `src/algorithms/base_five.c`). A Norminette encontra-se limpa (`OK`).

---

## 2. Entendendo o Algoritmo (Para a Evaluation)

Você mencionou que percebeu que o **Quick Sort** (do arquivo `complex.c`) é parecido com o **Chunk Sort** (do `medium.c`). O seu "feeling" está corretíssimo! 

Ambos os algoritmos operam com a mesma premissa básica: **Transferir pedaços filtrados da Pilha A para a Pilha B, para depois voltar tudo ordenado para a Pilha A.**
A diferença principal é **como eles decidem o tamanho desses pedaços**.

### Como funciona o Chunk Sort (`medium.c`):
Ele tenta comer um "bolo" enorme mordendo fatias de tamanho fixo.
1. O algoritmo define fatias fixas (chunks). Por exemplo, a cada 20 números.
2. Ele olha o topo da pilha A. Se o número for "baixo o suficiente" (pertencer ao chunk atual), ele empurra para a Pilha B. 
3. Se não for, ele rotaciona a Pilha A e verifica o próximo.
4. Ao final, a Pilha B vai conter os números meio-ordenados por fatias. 
5. Então, ele só precisa pegar sempre o MAIOR número que sobrou na Pilha B e devolver para a Pilha A, garantindo que o maior fique no fundo da A.

### Como funciona o Quick Sort (`complex.c`):
Ele é recursivo! Em vez de decidir um "pedaço fixo", ele sempre "corta no meio":
1. Ele pega o **Pivot** (o valor exato que fica no meio do maior número e do menor número daquela fatia).
2. Todo número em A que for menor que o Pivot vai para a Pilha B (`pb`).
3. Todo número em A que for maior que o Pivot, fica na A (ele dá um `ra` e ignora).
4. Agora ele tem duas metades (metade dos menores na B, e metade dos maiores na A).
5. O algoritmo então **chama a si mesmo de novo** para a metade da Pilha B, cortando ela no meio de novo. E depois chama a si mesmo para a metade da Pilha A.
6. Ele faz isso repetidas vezes até as metades chegarem a um tamanho de `2` ou `1` elemento. Como ordenar 2 elementos é fácil (só dar um `swap` se estiverem virados), ele resolve os blocos pequenos e empurra tudo de volta!

**Em suma na Evaluation:** Diga que a arquitetura do projeto usou o padrão *Strategy Pattern*. Como a própria 42 exige testar vários tipos de desordem, o projeto roda o `Chunk Sort` com tamanho variável se a desordem for média (`< 50%`) pois funciona bem; mas aciona o `QuickSort` (recursivo por partição Pivot) se a desordem for muito caótica (`>= 50%`) pois o QuickSort reage mais rápido, isolando sempre a "metade menor" independente da confusão da pilha!
