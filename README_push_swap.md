# 📚 Push Swap — Explicação Completa do Código

## 📌 O que é o Push Swap?

O Push Swap é um projeto da 42 onde você recebe uma lista de números inteiros desordenados na **stack A** e precisa ordená-los usando **apenas operações específicas**, com o menor número de operações possível. A **stack B** é usada como espaço auxiliar.

---

## 🏗️ Estrutura do Projeto

```
push_swap/
├── includes/
│   └── push_swap.h          ← Header principal (structs, protótipos)
├── src/
│   ├── main.c                ← Ponto de entrada do programa
│   ├── parsing/
│   │   └── parse_args.c      ← Validação e leitura dos argumentos
│   ├── stack/
│   │   ├── stack_new.c       ← Criação de nós e stack
│   │   ├── stack_push_pop_swap.c  ← Push/pop/swap na stack
│   │   ├── stack_rotate.c    ← Rotate e reverse rotate
│   │   └── stack_utils.c     ← is_sorted, normalize, get_index
│   ├── operations/
│   │   ├── ops_push_swap.c   ← sa, sb, pa, pb
│   │   ├── ops_rotate.c      ← ra, rb, rra, rrb
│   │   └── ops_combo.c       ← ss, rr, rrr
│   ├── algorithms/
│   │   ├── strategy_factory.c← Seleção e dispatch de estratégia
│   │   ├── simple.c          ← Algoritmo para ≤5 elementos
│   │   ├── medium.c          ← Algoritmo chunk-based
│   │   ├── complex.c         ← QuickSort adaptado para stacks
│   │   ├── base_three.c      ← Caso base: ordenar 3 elementos
│   │   ├── base_five.c       ← Caso base: ordenar 5 elementos
│   │   └── base_utils.c      ← Dispatcher dos casos base
│   └── bench/
│       ├── bench.c           ← Impressão do benchmark
│       └── bench_utils.c     ← Utilitários do benchmark
├── libs/libft/               ← Biblioteca libft
└── Makefile
```

---

## 🧠 Estruturas de Dados (push_swap.h)

### `t_node` — Um elemento da stack

```c
typedef struct s_node
{
    int             value;   // valor original do número
    int             rank;    // posição relativa (1 = menor, N = maior)
    struct s_node   *next;   // próximo nó (abaixo na stack)
    struct s_node   *prev;   // nó anterior (acima na stack)
}                   t_node;
```

**Explicação simples:** Cada número na stack é um "nó". Imagine uma pilha de cartas — cada carta sabe qual carta está em cima dela (`prev`) e qual está embaixo (`next`). O `rank` é a "posição correta" que o número deveria ter (ex: se os números são `42 7 99`, o rank do 7 é 1, do 42 é 2, do 99 é 3).

---

### `t_strategy` — Qual algoritmo usar

```c
typedef enum e_strategy
{
    SIMPLE,          // 0 → para ≤5 elementos ou desordem baixa
    MEDIUM,          // 1 → chunk-based, bom para médios
    COMPLEX,         // 2 → quicksort adaptado, bom para grandes
    ADAPTIVE,        // 3 → decide automaticamente baseado na desordem
    STRATEGY_COUNT   // 4 → total de estratégias (usado como tamanho do array)
}                   t_strategy;
```

**Explicação simples:** É como escolher uma ferramenta. Se tem poucos parafusos (poucos números), usa chave manual (SIMPLE). Se tem muitos, usa furadeira (COMPLEX). O ADAPTIVE olha a bagunça e decide qual ferramenta usar.

---

### `t_op_count` — Contador de operações

```c
typedef struct s_op_count
{
    int    sa, sb, ss;       // swaps
    int    pa, pb;           // pushes
    int    ra, rb, rr;       // rotates
    int    rra, rrb, rrr;    // reverse rotates
}                   t_op_count;
```

**Explicação simples:** Cada vez que uma operação é executada (ex: `sa`), o contador correspondente incrementa em 1. Serve para o benchmark saber quantas operações foram usadas.

---

### `t_ps` — O "cérebro" do programa

```c
typedef struct s_ps
{
    t_node      *a;              // topo da stack A
    t_node      *b;              // topo da stack B
    int         size_a;          // tamanho atual da stack A
    int         size_b;          // tamanho atual da stack B
    float       disorder;        // % de desordem (0.0 = ordenado, 1.0 = totalmente invertido)
    t_strategy  strategy;        // estratégia escolhida pelo usuário (ou ADAPTIVE)
    t_strategy  adap_strategy;   // estratégia escolhida pelo ADAPTIVE
    int         bench_mode;      // 1 se --bench foi passado, 0 se não
    t_op_count  operations;      // contadores de cada operação
}                   t_ps;
```

**Explicação simples:** Essa struct guarda TUDO. As duas stacks, os tamanhos, a estratégia, o modo benchmark, e os contadores. Toda função do programa recebe um ponteiro para essa struct.

---

## 🚀 Fluxo de Execução (Como Tudo Se Conecta)

```
./push_swap 3 1 4 1 5 --bench
         │
         ▼
┌─────────────────────────────┐
│        main()               │
│  1. Inicializa t_ps com {0} │
│  2. strategy = ADAPTIVE     │
│  3. Chama parse_args()      │
│  4. Chama dispatch_strategy()│
│  5. Se bench_mode, print_bench()│
│  6. free_ps()               │
└─────────────────────────────┘
         │
         ▼
┌─────────────────────────────┐
│      parse_args()           │
│  Para cada argumento:       │
│  ├─ É "--bench"? → bench=1  │
│  ├─ É "--simple"? → strategy│
│  ├─ É número válido?        │
│  │   ├─ Dentro de INT range?│
│  │   ├─ É único (sem dup)?  │
│  │   └─ Cria nó e push_bottom│
│  └─ Retorna 0 se erro       │
└─────────────────────────────┘
         │
         ▼
┌─────────────────────────────┐
│   dispatch_strategy()       │
│  1. Calcula disorder        │
│  2. Monta array de handlers │
│     handlers[SIMPLE] = run_simple│
│     handlers[MEDIUM] = run_medium│
│     handlers[COMPLEX]= run_complex│
│     handlers[ADAPTIVE]=select_strategy()│
│  3. Executa handlers[strategy]()│
└─────────────────────────────┘
         │
    ┌────┴─────────┬──────────────┐
    ▼              ▼              ▼
 run_simple    run_medium    run_complex
 (≤5 elem)     (chunks)     (quicksort)
```

---

## 📂 Explicação Arquivo por Arquivo

---

### 1. [main.c](file:///home/hegoncal/Documents/push_swap/src/main.c)

```c
int main(int argc, char **argv)
{
    t_ps ps;

    ps = (t_ps){0};          // ① Zera TUDO (stacks, contadores, etc.)
    ps.strategy = ADAPTIVE;  // ② Default: deixa o programa decidir
    if (!parse_args(argc, argv, &ps))  // ③ Lê e valida argumentos
    {
        free_ps(&ps);
        write(STDERR_FILENO, "Error\n", 6);  // Se erro, imprime "Error"
        return (1);
    }
    dispatch_strategy(&ps);  // ④ Executa o algoritmo de ordenação
    if (ps.bench_mode)
        print_bench(&ps);    // ⑤ Se --bench, imprime estatísticas
    free_ps(&ps);
    return (0);
}
```

**O que faz:** É o ponto de entrada. Inicializa tudo, parseia argumentos, ordena, e opcionalmente mostra benchmark.

**Detalhe importante:** `ps = (t_ps){0}` é um truque em C para zerar toda a struct de uma vez. Sem isso, os contadores teriam lixo de memória.

---

### 2. [parse_args.c](file:///home/hegoncal/Documents/push_swap/src/parsing/parse_args.c)

#### `parse_args()` — Função principal do parsing

```c
int parse_args(int argc, char **argv, t_ps *ps)
{
    // Para cada argumento do argv:
    //   1. Faz ft_split por espaço (para suportar "1 2 3" como um argumento)
    //   2. Para cada pedaço, chama parse_and_set_arg()
    //   3. Se qualquer um falhar, retorna 0 (erro)
}
```

**Explicação:** Aceita números tanto como `./push_swap 3 1 4` quanto como `./push_swap "3 1 4"`. O `ft_split` quebra strings com espaço.

#### `parse_and_set_arg()` — Processa um argumento individual

```c
int parse_and_set_arg(char *arg, t_ps *ps)
{
    // Se NÃO é um número válido:
    //   - É "--bench"? → ativa bench_mode
    //   - É uma flag de estratégia? → seta ps->strategy
    //   - Se nenhum dos dois → retorna erro
    //
    // Se É um número válido:
    //   - Converte para long (para checar overflow)
    //   - Verifica se está entre INT_MIN e INT_MAX
    //   - Verifica se é único (sem duplicatas)
    //   - Cria um nó e adiciona ao FINAL da stack A
}
```

**Detalhe crucial:** Usa `node_push_bottom` (e não `push_top`) para manter a ordem dos argumentos. Se fizesse push_top, a stack ficaria invertida.

#### `parse_strategy()` — Converte flag para enum

```c
t_strategy parse_strategy(char *argv)
{
    // "--simple"  → SIMPLE
    // "--medium"  → MEDIUM
    // "--complex" → COMPLEX
    // "--adaptive"→ ADAPTIVE
    // Qualquer outro → STRATEGY_COUNT (erro)
}
```

---

### 3. [strategy_factory.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/strategy_factory.c) — O Cérebro da Decisão

#### `calculate_disorder()` — Mede quão bagunçada a stack está

```c
float calculate_disorder(t_node *top)
{
    // Conta TODOS os pares (i, j) onde i vem antes de j na stack
    // Para cada par, se i > j, é uma "inversão" (par fora de ordem)
    // Retorna: inversões / total_de_pares
    //
    // Exemplo: [3, 1, 2]
    //   Pares: (3,1) (3,2) (1,2)
    //   Inversões: (3,1)✗ (3,2)✗ (1,2)✓
    //   Desordem = 2/3 = 0.666 = 66.6%
}
```

**Explicação simples:** Imagine que você pega cada par de cartas e verifica se estão na ordem certa. A % de pares errados é a desordem. 0% = já ordenado, 100% = totalmente invertido.

#### `select_strategy()` — O "Modo Adaptativo"

```c
t_fn select_strategy(t_ps *ps)
{
    // Se ≤5 elementos OU desordem < 20%  → SIMPLE
    // Se desordem entre 20% e 50%         → MEDIUM
    // Se desordem ≥ 50%                   → COMPLEX
}
```

**Por que isso existe:** Cada algoritmo tem um ponto forte. O SIMPLE é ótimo para poucos elementos, o MEDIUM é bom para desordem moderada, e o COMPLEX é melhor para muita bagunça.

#### `dispatch_strategy()` — Executa a estratégia

```c
void dispatch_strategy(t_ps *ps)
{
    // 1. Calcula desordem
    // 2. Cria um array de ponteiros de função:
    //    handlers[SIMPLE]   = run_simple
    //    handlers[MEDIUM]   = run_medium
    //    handlers[COMPLEX]  = run_complex
    //    handlers[ADAPTIVE] = resultado do select_strategy()
    // 3. Chama: handlers[ps->strategy](ps)
}
```

**Detalhe inteligente:** Usa um array de ponteiros de função (`t_fn`). Em vez de ter um `if/else` gigante, simplesmente indexa o array com o enum. É um **Factory Pattern** — o enum decide qual função chamar.

**Como `handlers[ADAPTIVE]` funciona:** Quando a estratégia é ADAPTIVE, `select_strategy()` já retorna o ponteiro da função correta (run_simple, run_medium, ou run_complex). Então `handlers[ADAPTIVE]` aponta para a mesma função que seria chamada diretamente.

---

### 4. [simple.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/simple.c) — Algoritmo para Poucos Elementos

```c
void run_simple(t_ps *ps)
{
    // ① Se <2 elementos ou já ordenado → nada a fazer
    // ② Normaliza a stack (atribui ranks)
    // ③ Se 2 elementos → compara e faz sa se necessário
    // ④ Se 3 elementos → base_three_a()
    // ⑤ Se 4-5 elementos → base_five_a()
}
```

**Explicação:** Para poucos elementos, não precisa de algoritmo complexo. Usa casos base hardcoded que são extremamente eficientes.

---

### 5. [medium.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/medium.c) — Algoritmo Chunk-Based

#### Ideia Geral

O Medium divide os números em "chunks" (pedaços) e os envia para B em ordem parcial, depois retorna para A.

#### `sort_to_b()` — Fase 1: Enviar para B por chunks

```c
static void sort_to_b(t_ps *ps)
{
    // chunk_size = (tamanho * 11 / 100) + 15
    //   → Fórmula mágica: para 100 números, chunk ≈ 26
    //   → Para 500 números, chunk ≈ 70
    //
    // limit = chunk_size (limite atual do chunk)
    //
    // Enquanto stack A não estiver vazia:
    //   index = posição relativa do topo de A entre TODOS os números
    //   Se index < limit (pertence ao chunk atual):
    //     pb → manda para B
    //     Se index < limit - chunk/2 → rb (manda para baixo de B)
    //     Se B encheu o chunk → limit += chunk_size
    //   Senão:
    //     ra → roda A para encontrar um que pertença ao chunk
}
```

**Explicação visual:**
```
Chunk 1: números de rank 0-25   → vão primeiro para B
Chunk 2: números de rank 26-51  → vão depois
...
Último chunk: os maiores         → vão por último

Dentro de cada chunk: os menores ficam embaixo de B (rb),
os maiores ficam em cima. Assim B fica semi-ordenado.
```

**O truque do `rb`:** Quando um número pertence à metade inferior do chunk, ele é rotacionado para baixo de B. Isso cria uma divisão "maiores em cima, menores embaixo" dentro de B.

#### `return_to_a()` — Fase 2: Retornar em ordem

```c
static void return_to_a(t_ps *ps)
{
    // Enquanto B não estiver vazia:
    //   Encontra a posição do MAIOR elemento em B
    //   Se está no topo → pa (manda para A)
    //   Se está na metade superior → rb (rotaciona para chegar ao topo)
    //   Se está na metade inferior → rrb (rotaciona invertido)
}
```

**Explicação:** Sempre pega o maior de B e manda para A. Como precisa que o maior esteja no topo, decide se é mais rápido ir por cima (rb) ou por baixo (rrb) baseado na posição.

---

### 6. [complex.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/complex.c) — QuickSort para Stacks

#### Ideia Geral

É um **QuickSort recursivo** adaptado para funcionar com apenas duas stacks. Em vez de particionar um array in-place, ele particiona movendo elementos entre A e B.

#### `quick_sort_a()` — Ordena elementos na stack A

```c
void quick_sort_a(t_ps *ps, int min, int max, int size)
{
    // ① Se é caso base (≤5) → handle_base_a() e retorna
    // ② Calcula pivot = (min + max + 1) / 2 (mediana)
    // ③ sort_a(): empurra para B tudo que tem rank < pivot
    //    Resultado: A tem a metade maior, B tem a metade menor
    // ④ Recursão: ordena a metade MAIOR que ficou em A
    // ⑤ Recursão: ordena a metade MENOR que foi para B
    // ⑥ Puxa de volta para A os elementos que foram para B
}
```

#### `sort_a()` — Partição em A

```c
int sort_a(t_ps *ps, int size, int pivot)
{
    // Percorre 'size' elementos do topo de A:
    //   Se rank < pivot → pb (manda para B) e conta pushed++
    //   Se rank >= pivot → ra (rotaciona, vai pro final)
    //
    // Depois desfaz as rotações:
    //   rra × (size - pushed) vezes, para restaurar a posição
    //
    // Retorna: quantos foram para B (pushed)
}
```

#### `quick_sort_b()` — Ordena elementos na stack B

```c
void quick_sort_b(t_ps *ps, int min, int max, int size)
{
    // Mesma lógica que quick_sort_a, mas invertida:
    // ① Se é caso base → handle_base_b()
    // ② pivot = (min + max + 1) / 2
    // ③ sort_b(): empurra para A tudo que tem rank >= pivot
    // ④ Recursão: ordena a metade MENOR que ficou em B
    // ⑤ Recursão: ordena a metade MAIOR que foi para A
    // ⑥ Empurra de volta para B
}
```

**Visualização do QuickSort:**
```
Stack A: [5, 3, 8, 1, 7, 2, 6, 4]    pivot = 4

Após sort_a (rank < 4 vão para B):
   Stack A: [5, 8, 7, 6]    ← maiores (ficaram)
   Stack B: [3, 1, 2, 4]    ← menores (foram)

Recursão: quick_sort_a nos maiores de A
Recursão: quick_sort_b nos menores de B
Depois: pa para trazer de volta
```

---

### 7. [base_three.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/base_three.c) — Caso Base: 3 Elementos

#### `base_three_a()` — Ordena 3 em A (crescente)

```c
void base_three_a(t_ps *ps)
{
    // 1. Encontra o MAIOR rank entre os 3 do topo
    // 2. Se o maior está no topo → ra (joga pro final)
    //    Se o maior está no meio → rra (traz o último pro topo)
    // 3. Se os dois do topo estão fora de ordem → sa
}
```

**Todas as permutações de [1, 2, 3]:**
```
[1,2,3] → já ordenado, nenhuma operação
[1,3,2] → rra, sa         (2 ops)
[2,1,3] → sa              (1 op)
[2,3,1] → rra             (1 op)
[3,1,2] → ra              (1 op)
[3,2,1] → ra, sa          (2 ops)
```

#### `base_three_b()` — Ordena 3 em B (decrescente)

Mesma lógica, mas invertida: procura o MENOR e ordena de forma decrescente (para que quando voltar para A, fique crescente).

---

### 8. [base_five.c](file:///home/hegoncal/Documents/push_swap/src/algorithms/base_five.c) — Caso Base: 5 Elementos

#### `base_five_a()` — Ordena 5 em A

```c
void base_five_a(t_ps *ps)
{
    // 1. Encontra a posição do MENOR entre os 5
    // 2. Rotaciona (ra ou rra) para trazer o menor ao topo
    //    → Escolhe a direção mais curta (pos vs 5-pos)
    // 3. pb → manda o menor para B
    // 4. Repete: encontra o segundo menor entre os 4 restantes
    // 5. pb → manda para B
    // 6. base_three_a() → ordena os 3 restantes em A
    // 7. pa, pa → traz os dois de B de volta
}
```

**Visualização:**
```
A: [3,5,1,4,2]    B: []
→ Encontra 1 (pos 2), ra ra, pb
A: [4,2,3,5]      B: [1]
→ Encontra 2 (pos 1), ra, pb
A: [3,5,4]         B: [2,1]
→ base_three_a: ordena [3,5,4] → [3,4,5]
→ pa, pa
A: [1,2,3,4,5]    B: []     ✓ Ordenado!
```

---

### 9. Operações — [ops_push_swap.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_push_swap.c), [ops_rotate.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_rotate.c), [ops_combo.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_combo.c)

Todas as operações seguem o mesmo padrão:

```c
void op_XX(t_ps *ps)
{
    // 1. Verifica se a operação é válida (stack existe, tem elementos suficientes)
    // 2. Executa a operação na stack
    // 3. Incrementa o contador: ps->operations.XX++
    // 4. Imprime o nome da operação em stdout: ft_putstr_fd("XX\n", 1)
}
```

| Operação | O que faz |
|----------|-----------|
| `sa` | Troca os 2 primeiros de A |
| `sb` | Troca os 2 primeiros de B |
| `ss` | `sa` + `sb` ao mesmo tempo |
| `pa` | Tira o topo de B e coloca no topo de A |
| `pb` | Tira o topo de A e coloca no topo de B |
| `ra` | Rotaciona A: primeiro vai pro final |
| `rb` | Rotaciona B: primeiro vai pro final |
| `rr` | `ra` + `rb` ao mesmo tempo |
| `rra` | Rotação inversa de A: último vai pro início |
| `rrb` | Rotação inversa de B: último vai pro início |
| `rrr` | `rra` + `rrb` ao mesmo tempo |

**Detalhe importante:** Cada operação imprime seu nome em **stdout** (fd 1). O benchmark imprime em **stderr** (fd 2). Isso permite redirecionar separadamente: `./push_swap 3 1 2 | ./checker_linux` só vê as operações.

---

### 10. [bench.c](file:///home/hegoncal/Documents/push_swap/src/bench/bench.c) — Benchmark

```c
void print_bench(t_ps *ps)
{
    // Calcula total = soma de TODOS os contadores
    // Imprime em STDERR:
    //   [bench] disorder: XX.XX%
    //   [bench] strategy: Simple / O(n²)
    //   [bench] total_ops: 42
    //   [bench] sa: 3 sb: 0 ss: 0 pa: 5 pb: 5
    //   [bench] ra: 12 rb: 7 rr: 0 rra: 4 rrb: 6 rrr: 0
}
```

---

## 🔗 Como Tudo Se Conecta — Mapa Completo

```
┌──────────────────────────────────────────────────────────┐
│                        main()                            │
│                          │                               │
│         ┌────────────────┼────────────────┐              │
│         ▼                ▼                ▼              │
│    parse_args()   dispatch_strategy()  print_bench()     │
│         │                │                │              │
│         ▼                ▼                ▼              │
│  parse_and_set_arg()  calculate_disorder()  get_total_ops()│
│    │        │         select_strategy()                   │
│    │        │              │                              │
│    ▼        ▼         ┌────┴────┬──────────┐             │
│ node_new  parse_     ▼         ▼          ▼             │
│ push_bottom strategy run_simple run_medium run_complex   │
│                        │         │          │            │
│                        ▼         ▼          ▼            │
│                    normalize  sort_to_b  quick_sort_a    │
│                    base_3/5  return_to_a quick_sort_b    │
│                        │         │          │            │
│                        └────┬────┴──────────┘            │
│                             ▼                            │
│                    Operações (op_sa, op_pb, etc.)         │
│                        │         │                       │
│                        ▼         ▼                       │
│               stack_swap_top  node_pop_top               │
│               stack_rotate    node_push_top               │
│                  ft_putstr_fd("sa\n", 1)                 │
│                  ps->operations.sa++                     │
└──────────────────────────────────────────────────────────┘
```

**Resumo da conexão:**
1. `main()` chama `parse_args()` para ler os números e flags
2. `main()` chama `dispatch_strategy()` que calcula a desordem e escolhe o algoritmo
3. O algoritmo escolhido (simple/medium/complex) chama operações (`op_sa`, `op_pb`, etc.)
4. Cada operação manipula as stacks E imprime o nome em stdout E incrementa o contador
5. Se `--bench` foi passado, `print_bench()` mostra as estatísticas no stderr

---

## 🆕 Como Adicionar a Flag `--count-only`

A flag `--count-only` deve mostrar **apenas o número total de operações** (sem imprimir as operações em si e sem o relatório completo do bench). Isso é perfeito para o livecoding, onde o avaliador quer ver rapidamente quantas operações foram usadas.

**Resultado esperado:**
```bash
$ ./push_swap 3 1 4 2 5 --count-only
5
```

(Em vez de imprimir `sa`, `pb`, `ra`, etc., imprime apenas o número `5`)

### Passo a passo das alterações:

---

### Passo 1: Adicionar campo `count_only` na struct `t_ps`

**Arquivo:** [push_swap.h](file:///home/hegoncal/Documents/push_swap/includes/push_swap.h)

```diff
 typedef struct s_ps
 {
     t_node          *a;
     t_node          *b;
     int             size_a;
     int             size_b;
     float           disorder;
     t_strategy      strategy;
     t_strategy      adap_strategy;
     int             bench_mode;
+    int             count_only;
     t_op_count      operations;
 }                   t_ps;
```

---

### Passo 2: Reconhecer `--count-only` no parser

**Arquivo:** [parse_args.c](file:///home/hegoncal/Documents/push_swap/src/parsing/parse_args.c)

Na função `parse_and_set_arg()`, adicionar o reconhecimento da nova flag:

```diff
     if (!is_valid_number(arg))
     {
         if (ft_strcmp(arg, "--bench") == 0)
         {
             ps->bench_mode = 1;
             return (1);
         }
+        if (ft_strcmp(arg, "--count-only") == 0)
+        {
+            ps->count_only = 1;
+            return (1);
+        }
         ps->strategy = parse_strategy(arg);
         return (ps->strategy != STRATEGY_COUNT);
     }
```

---

### Passo 3: Suprimir a impressão das operações quando `count_only` está ativo

**Arquivo:** Em TODAS as funções de operação, o `ft_putstr_fd` precisa ser condicional.

A forma mais limpa é **modificar cada operação** para verificar `count_only`. Nas operações em [ops_push_swap.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_push_swap.c), [ops_rotate.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_rotate.c) e [ops_combo.c](file:///home/hegoncal/Documents/push_swap/src/operations/ops_combo.c):

**Exemplo para `op_sa`:**
```diff
 void    op_sa(t_ps *ps)
 {
     if (!ps || !ps->a || !ps->a->next)
         return ;
     stack_swap_top(&ps->a);
     ps->operations.sa++;
-    ft_putstr_fd("sa\n", 1);
+    if (!ps->count_only)
+        ft_putstr_fd("sa\n", 1);
 }
```

> [!IMPORTANT]
> Fazer essa mesma mudança em **TODAS as 11 operações**: `op_sa`, `op_sb`, `op_ss`, `op_pa`, `op_pb`, `op_ra`, `op_rb`, `op_rr`, `op_rra`, `op_rrb`, `op_rrr`.

---

### Passo 4: Imprimir o número total de operações no `main()`

**Arquivo:** [main.c](file:///home/hegoncal/Documents/push_swap/src/main.c)

```diff
     dispatch_strategy(&ps);
     if (ps.bench_mode)
         print_bench(&ps);
+    if (ps.count_only)
+    {
+        ft_putnbr_fd(ps.operations.sa + ps.operations.sb + ps.operations.ss
+            + ps.operations.pa + ps.operations.pb + ps.operations.ra
+            + ps.operations.rb + ps.operations.rr + ps.operations.rra
+            + ps.operations.rrb + ps.operations.rrr, 1);
+        ft_putstr_fd("\n", 1);
+    }
     free_ps(&ps);
```

> [!TIP]
> **Alternativa mais limpa:** Você pode expor a função `get_total_ops()` de [bench.c](file:///home/hegoncal/Documents/push_swap/src/bench/bench.c) removendo o `static` e adicionando o protótipo no header. Daí no main seria apenas:
> ```c
> if (ps.count_only)
> {
>     ft_putnbr_fd(get_total_ops(&ps.operations), 1);
>     ft_putstr_fd("\n", 1);
> }
> ```

---

### Resumo Visual da Alteração

```
Antes:
  ./push_swap 3 1 2
  → sa        (stdout)

Com --bench:
  ./push_swap 3 1 2 --bench
  → sa        (stdout)
  → [bench] disorder: 66.67%   (stderr)
  → [bench] strategy: ...       (stderr)
  → [bench] total_ops: 1        (stderr)
  → [bench] sa: 1 sb: 0 ...    (stderr)

Com --count-only:
  ./push_swap 3 1 2 --count-only
  → 1         (stdout, apenas o número)
```

---

## 📊 Complexidade dos Algoritmos

| Estratégia | Quando é usada | Complexidade | Operações esperadas (100 nums) | Operações esperadas (500 nums) |
|-----------|----------------|-------------|-------------------------------|-------------------------------|
| SIMPLE | ≤5 elementos ou disorder < 20% | O(n²) | N/A (só para ≤5) | N/A |
| MEDIUM | disorder 20-50% | O(n√n) | ~700 | ~5500 |
| COMPLEX | disorder ≥ 50% | O(n log n) | ~600 | ~4500 |
| ADAPTIVE | Default | Escolhe o melhor | Varia | Varia |
