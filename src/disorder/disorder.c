/* =============================================================================
 * disorder.c
 *
 * O QUE FAZER AQUI:
 * - Implementar compute_disorder(t_node *top) seguindo o pseudocódigo do
 *   subject (VI.3.2):
 *     - percorrer todos os pares (i, j) com i < j
 *     - contar quantas vezes a[i] > a[j] (inversões / "mistakes")
 *     - disorder = mistakes / total_pairs (double, entre 0.0 e 1.0)
 * - Deve ser chamada ANTES de qualquer operação ser executada sobre a
 *   stack (senão o valor fica errado / o subject marca isso como
 *   obrigatório).
 * - Cuidado com n <= 1 (total_pairs = 0 -> evitar divisão por zero,
 *   retornar disorder 0.0 nesse caso).
 * - Esse valor é usado tanto pelo --bench (print em %) quanto pelo
 *   algorithms/adaptive.c para decidir qual técnica interna usar.
 * ========================================================================== */
