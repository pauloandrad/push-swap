/* =============================================================================
 * bench.c
 *
 * O QUE FAZER AQUI:
 * - void print_bench(t_ps *ps): só é chamada se a flag --bench foi
 *   passada. TUDO aqui vai para STDERR (nunca stdout, para não misturar
 *   com a lista de operações).
 * - Formato esperado (ver exemplos do subject VI.5.1):
 *     [bench] disorder: XX.XX%
 *     [bench] strategy: <nome> / O(...)
 *     [bench] total_ops: N
 *     [bench] sa: n sb: n ss: n pa: n pb: n
 *     [bench] ra: n rb: n rr: n rra: n rrb: n rrr: n
 * - Os valores vêm dos contadores incrementados em operations/ops_single.c
 *   e ops_combo.c, e do ps->disorder calculado em disorder/disorder.c.
 * - O disorder deve ser impresso com 2 casas decimais, em porcentagem
 *   (multiplicar por 100).
 * ========================================================================== */
