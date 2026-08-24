*This project has been created as part of the 42 curriculum by pahenriq, hegoncal.*

# push_swap

## Description

**push_swap** is a sorting algorithm project developed as part of the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, with the smallest number of moves possible.

The program receives a list of integers as arguments and outputs to the standard output the sequence of operations needed to sort them in ascending order. Two stacks are available — **Stack A** (which initially holds all the numbers) and **Stack B** (which starts empty) — and only the following operations may be used:

| Operation | Description |
| --------- | ----------- |
| `sa`      | Swap the first two elements of Stack A. |
| `sb`      | Swap the first two elements of Stack B. |
| `ss`      | `sa` and `sb` simultaneously. |
| `pa`      | Push the top element of Stack B onto Stack A. |
| `pb`      | Push the top element of Stack A onto Stack B. |
| `ra`      | Rotate Stack A upward (first element becomes last). |
| `rb`      | Rotate Stack B upward. |
| `rr`      | `ra` and `rb` simultaneously. |
| `rra`     | Reverse rotate Stack A (last element becomes first). |
| `rrb`     | Reverse rotate Stack B. |
| `rrr`     | `rra` and `rrb` simultaneously. |

The project uses the **Strategy Pattern** to dynamically select the most efficient sorting algorithm based on the input size and degree of disorder of the data.

## Instructions

### Compilation

Clone the repository and build the program with `make`:

```sh
git clone https://github.com/pauloandrad/push-swap.git push_swap
cd push_swap
make
```

This produces the executable `push_swap` in the project root.

Available Makefile rules:

| Rule          | Description                                              |
| ------------- | -------------------------------------------------------- |
| `make`        | Build the `push_swap` executable (default `all` rule).   |
| `make clean`  | Remove the object (`.o`) files.                          |
| `make fclean` | Remove the object files **and** the `push_swap` binary.  |
| `make re`     | Rebuild everything from scratch.                         |

The project is compiled with `cc -Wall -Wextra -Werror`.

### Execution

Pass the integers as arguments:

```sh
./push_swap 4 67 3 87 23
```

The program outputs the list of operations to sort the stack, one per line. You can pipe the output to the provided `checker_linux` to verify correctness:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

To count the number of operations:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

## Algorithm and Technical Choices

### Architecture: Strategy Pattern

The project implements the **Strategy Pattern** to select the sorting algorithm at runtime. A `select_strategy` factory function calculates the **disorder percentage** of the input stack and picks the best algorithm accordingly:

| Strategy   | Condition                       | Algorithm             |
| ---------- | ------------------------------- | --------------------- |
| `SIMPLE`   | 5 or fewer elements            | Hard-coded base cases |
| `MEDIUM`   | Disorder < 50%                 | Chunk Sort            |
| `COMPLEX`  | Disorder ≥ 50%                 | Quick Sort            |

This adaptive approach guarantees optimal (or near-optimal) operation counts across all input sizes and disorder levels.

### Simple (≤ 5 elements)

For stacks with **3 or fewer** elements, a hard-coded `base_three` function handles all possible permutations in at most 2 operations.

For stacks with **4 or 5** elements, a `base_five` function pushes the smallest elements to Stack B, sorts the remaining 3 with `base_three`, and pushes back — completing in at most 12 operations.

### Chunk Sort (`MEDIUM` strategy)

The Chunk Sort algorithm transfers elements from Stack A to Stack B in fixed-size **chunks**, ordered by rank:

1. A dynamic chunk size is calculated: `(size * 11 / 100) + 15`.
2. For each chunk window, the algorithm scans Stack A. If the top element's rank falls within the current chunk range, it is pushed to Stack B. Otherwise, Stack A is rotated.
3. After all elements are in Stack B, the algorithm finds the maximum element in Stack B and brings it back to Stack A in sorted order by rotating or reverse-rotating Stack B as needed.

This strategy performs well on partially sorted data and achieves approximately **~5 500 – 5 800** operations on 500 random elements.

### Quick Sort (`COMPLEX` strategy)

The Quick Sort operates recursively using a **pivot-based partition**:

1. A **pivot** is calculated as the midpoint between the minimum and maximum ranks in the current segment.
2. Elements with a rank below the pivot are pushed from Stack A to Stack B (`pb`); elements above the pivot stay in Stack A (`ra`).
3. The algorithm recursively partitions both halves until segments are reduced to 2 or 3 elements, which are resolved with direct swaps.
4. Once all sub-segments are sorted, elements are pushed back from Stack B to Stack A in order.

Quick Sort excels on heavily disordered inputs because it always isolates the smaller half regardless of the initial arrangement.

### Justification

- **Strategy Pattern** enables the program to adapt to any input profile, avoiding a one-size-fits-all approach that would be suboptimal for specific cases.
- **Chunk Sort** minimizes operations on low-disorder data by transferring elements in predictable batches, reducing unnecessary rotations.
- **Quick Sort** handles high-disorder data efficiently through recursive halving, which is more adaptable than fixed-chunk approaches when the data has no discernible order.
- **Hard-coded base cases** (3 and 5 elements) eliminate recursion overhead for trivial inputs, ensuring the minimum possible number of operations.

## Contributions

### pahenriq (Paulo Andrade)

- Initial project structure, boilerplate, and Makefile setup
- Architecture diagrams and contract header definitions
- Argument parsing and error handling (`parse_args`, input validation)
- Main orchestration function (`main.c`)
- Disorder calculation algorithm (`calculate_disorder`)
- Strategy selection factory (`select_strategy`, `dispatch_strategy`)
- Quick Sort algorithm implementation (`complex.c`)
- Integration of `libft` into the project
- Merge management and branch coordination

### hegoncal (Henry Gonçalves)

- Stack data structure implementation (`stack_new`, `stack_push_pop_swap`, `stack_rotate`, `stack_utils`)
- All push_swap operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, and combo variants)
- Simple algorithm for ≤ 5 elements (`base_three`, `base_five`, `simple.c`)
- Chunk Sort (Medium algorithm) implementation (`medium.c`, `get_index`)
- Dynamic chunk size tuning for optimal operation count
- Bench output reporting system (`bench.c`, `bench_utils.c`)
- Bug fixes: `stack_swap_top` rank swap, Quick Sort base-case guard (`base_utils.c`)
- Code refactoring and Norminette compliance across the codebase

## Resources

### Documentation and references

- [push_swap tutorial — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — popular walkthrough of the push_swap problem and the Chunk Sort approach.
- [Quick Sort — Wikipedia](https://en.wikipedia.org/wiki/Quicksort) — reference on the pivot-based partition algorithm.
- [Visualgo — Sorting Algorithms](https://visualgo.net/en/sorting) — interactive visualization of sorting algorithms.
- 42's own `push_swap` subject and Norm documentation.

### Use of AI

AI assistance was used in two scoped ways during this project:

- **Understanding concepts and algorithms** — clarifying how Quick Sort partitioning maps to a two-stack model, reviewing edge cases in the chunk size formula, and understanding the disorder calculation.
- **Tests, review, and debugging** — generating test inputs, reviewing implementations for correctness and Norminette compliance, and diagnosing bugs such as the `stack_swap_top` rank issue and the Quick Sort base-case rotation bug.

All function implementations were written and understood by the authors; AI was used as a study and verification aid, not as a code generator.
