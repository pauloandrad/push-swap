/* =============================================================================
 * stack_push_pop.c
 *
 * O QUE FAZER AQUI:
 * - Funções de baixo nível para manipular a lista duplamente ligada que
 *   representa cada stack (independente das operações sa/pa/ra do subject,
 *   que ficam em operations/):
 *     - node_push_front(t_node **top, t_node *node)
 *     - t_node *node_pop_front(t_node **top)
 * - Essas funções são os "tijolos" usados por operations/ops_single.c para
 *   implementar sa, sb, pa, pb, ra, rb, rra, rrb.
 * - Cuidado com os ponteiros prev/next se a lista for circular ou dupla,
 *   para as rotações (ra/rra) ficarem O(1).
 * ========================================================================== */
