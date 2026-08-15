/* =============================================================================
 * ops_single.c
 *
 * O QUE FAZER AQUI (uma função por operação, seguindo exatamente as regras
 * do subject VI.2):
 * - void op_sa(t_ps *ps): swap dos 2 primeiros elementos do topo de a.
 *   Não faz nada se a tiver 0 ou 1 elemento.
 * - void op_sb(t_ps *ps): idem para b.
 * - void op_pa(t_ps *ps): tira o topo de b e põe no topo de a. Não faz
 *   nada se b estiver vazia.
 * - void op_pb(t_ps *ps): tira o topo de a e põe no topo de b. Não faz
 *   nada se a estiver vazia.
 * - void op_ra(t_ps *ps): rotaciona a para cima (primeiro vira último).
 * - void op_rb(t_ps *ps): idem para b.
 * - void op_rra(t_ps *ps): rotaciona a para baixo (último vira primeiro).
 * - void op_rrb(t_ps *ps): idem para b.
 *
 * IMPORTANTE:
 * - Cada função deve, além de mexer na stack, (1) imprimir o nome da
 *   operação em stdout seguido de \n, e (2) incrementar o contador
 *   correspondente na struct de estado (usado pelo --bench).
 * - Centralizar essa dupla responsabilidade evita esquecer de contar ou
 *   de imprimir em algum lugar do código dos algoritmos.
 * ========================================================================== */
