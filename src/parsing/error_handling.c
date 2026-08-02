/* =============================================================================
 * error_handling.c
 *
 * O QUE FAZER AQUI:
 * - Função central de erro, ex: void ps_error(void), que:
 *     - escreve "Error\n" em stderr (usar write, não printf)
 *     - libera qualquer memória já alocada até aquele ponto (se a struct de
 *       estado já existir, ela deve ser passada e limpa aqui)
 *     - dá exit(1) (ou EXIT_FAILURE)
 * - Função de checagem de duplicados: comparar cada valor parseado com
 *   todos os outros (O(n²) aqui é aceitável, é só validação, não faz parte
 *   da complexidade do algoritmo de ordenação).
 * - Chamar ps_error() em todos os pontos de parsing/construção da stack
 *   onde algo for inválido: não-inteiro, fora do range de int, duplicado,
 *   malloc falhando.
 * ========================================================================== */
