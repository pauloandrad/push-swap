/* =============================================================================
 * medium.c — estratégia O(n√n)
 *
 * O QUE FAZER AQUI:
 * - Escolher UMA abordagem em O(n√n) (ex: dividir os valores em √n chunks
 *   por faixa de valor, empurrar cada chunk para b, e reinserir em a na
 *   posição correta usando rotações — é a técnica clássica de push_swap
 *   para ~500 elementos).
 * - void run_medium(t_ps *ps): função de entrada chamada pelo selector.
 * - Cuidado para minimizar o número de rotações/rr ao escolher entre
 *   rotacionar "para cima" (ra) ou "para baixo" (rra) — normalmente parte
 *   do que diferencia uma implementação "boa" de uma "excelente" nos
 *   benchmarks do subject (VI.6).
 * - Documentar a lógica de particionamento (quantos chunks, como cada um
 *   é escolhido) para justificar no README.
 * ========================================================================== */
