/* =============================================================================
 * adaptive.c — estratégia adaptativa (design da dupla)
 *
 * O QUE FAZER AQUI:
 * - void run_adaptive(t_ps *ps): usa o disorder já calculado (ps->disorder)
 *   para decidir internamente qual técnica aplicar, respeitando os
 *   limiares do subject (VI.3.3):
 *     - disorder < 0.2        -> técnica que roda em O(n²)
 *     - 0.2 <= disorder < 0.5 -> técnica que roda em O(n√n)
 *     - disorder >= 0.5       -> técnica que roda em O(n log n)
 * - Pode (e provavelmente deve) reaproveitar as funções de simple.c,
 *   medium.c e complex.c internamente, OU implementar lógica própria —
 *   o subject não exige um algoritmo "nomeado" aqui.
 * - Essa é a estratégia DEFAULT quando nenhuma flag é passada.
 * - Documentar no README: por que esses limiares (ou outros escolhidos
 *   pela dupla), qual técnica interna roda em cada regime, e uma breve
 *   prova/argumento do limite superior de tempo e espaço.
 * ========================================================================== */
