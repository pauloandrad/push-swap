/* =============================================================================
 * parse_args.c
 *
 * O QUE FAZER AQUI:
 * - Percorrer argv (a partir do índice 1) e separar:
 *     - os tokens que são a lista de inteiros da stack a
 *     - os tokens que são flags (--simple, --medium, --complex, --adaptive,
 *       --bench)
 * - Suportar tanto "./push_swap 2 1 3" quanto argumentos vindos como uma
 *   única string com espaços "./push_swap '2 1 3'" (checar se o subject/
 *   testes da dupla exigem isso; se não, simplificar).
 * - Converter cada token numérico para int usando uma função própria tipo
 *   ft_atoi_strict, validando:
 *     - só dígitos (e sinal opcional no início)
 *     - dentro do range de INT_MIN..INT_MAX (usar long para checar overflow
 *       antes de castar para int)
 * - Retornar os valores já convertidos (ex: array de long ou int) para quem
 *   chamou (main.c), junto com o total de elementos.
 * ========================================================================== */
