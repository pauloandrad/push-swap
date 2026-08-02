/* =============================================================================
 * main.c
 *
 * O QUE FAZER AQUI (fluxo geral do programa):
 * 1. Se argc == 1 (nenhum parâmetro) -> não imprimir nada, return 0.
 * 2. Parsear argv (parsing/parse_args.c) -> validar inteiros, duplicados,
 *    overflow (parsing/error_handling.c). Em erro: "Error\n" em stderr.
 * 3. Construir as stacks a e b a partir dos valores parseados (stack/).
 * 4. Calcular o disorder da stack a ANTES de qualquer operação
 *    (disorder/disorder.c).
 * 5. Detectar se foi passada uma flag de estratégia (--simple, --medium,
 *    --complex, --adaptive) e/ou a flag --bench (selector/strategy_selector.c).
 * 6. Rodar a estratégia escolhida, que deve gerar e IMPRIMIR (stdout) a
 *    sequência de operações necessárias, e ao mesmo tempo ir contando
 *    cada operação executada na struct de estado.
 * 7. Se --bench foi passado, imprimir em stderr: disorder (%),
 *    nome da estratégia + complexidade, total de operações e contagem
 *    por tipo (bench/bench.c).
 * 8. Liberar toda a memória alocada (stacks, structs) antes de sair.
 * ========================================================================== */

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
