/* =============================================================================
 * ops_combo.c
 *
 * O QUE FAZER AQUI:
 * - void op_ss(t_ps *ps): chama op_sa + op_sb, mas imprime "ss\n" UMA vez
 *   só (não "sa\nsb\n"), e incrementa o contador de ss (não os de sa/sb).
 * - void op_rr(t_ps *ps): equivalente combinando ra + rb, imprime "rr\n".
 * - void op_rrr(t_ps *ps): equivalente combinando rra + rrb, imprime "rrr\n".
 * - Dica: reaproveitar a lógica interna de rotação/swap de ops_single.c
 *   (extrair helpers privados sem print/contador) para não duplicar
 *   código e não imprimir "sa" + "sb" quando o certo é "ss".
 * ========================================================================== */
