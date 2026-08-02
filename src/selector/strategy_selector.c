/* =============================================================================
 * strategy_selector.c
 *
 * O QUE FAZER AQUI:
 * - Função que recebe os argv já filtrados (flags) e retorna qual
 *   estratégia usar (enum: SIMPLE, MEDIUM, COMPLEX, ADAPTIVE).
 * - Reconhecer --simple, --medium, --complex, --adaptive.
 * - Se nenhuma flag for passada -> default é ADAPTIVE.
 * - Reconhecer também a flag --bench (independente da estratégia, pode
 *   ser combinada com qualquer uma delas, ex: --bench --complex).
 * - void dispatch_strategy(t_ps *ps): chama run_simple / run_medium /
 *   run_complex / run_adaptive de acordo com o resultado do selector, e
 *   guarda o nome da estratégia + complexidade teórica na struct de
 *   estado para uso posterior pelo bench/bench.c.
 * - Deve funcionar para QUALQUER tamanho/disorder de input (o subject é
 *   explícito sobre isso em VI.5).
 * ========================================================================== */
