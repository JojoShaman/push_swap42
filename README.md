_This project has been created as part of the 42 curriculum by srosu, mbuchet._

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (a and b) and a limited set of operations, while minimizing the number of moves.

What makes this implementation distinctive is its **adaptive strategy**: rather than applying a single algorithm blindly, the program computes a _disorder score_ of the input before sorting, and selects the most efficient algorithm for the situation.

The project is implemented in C and relies on a **doubly linked list** as the underlying data structure, which makes stack operations (push, rotate, reverse rotate) natural and efficient. A custom `ft_printf` — adapted from a prior 42 project — is embedded directly and extended to support a file descriptor parameter, enabling clean output routing: operations to `stdout`, errors and bench stats to `stderr`.

## Contributors

### srosu
srosu established the foundations of the project. He designed and implemented the core architecture: the doubly linked list data structure, the full set of stack operations (push, rotate, reverse rotate and their variants), and two of the three sorting algorithms — simple sort and medium sort (Turkish/chunk sort). He also designed the disorder metric and the adaptive strategy that selects the most appropriate algorithm based on the input. In short, srosu built the engine that makes push_swap work.

### mbuchet
mbuchet joined the project approximately one and a half weeks in and took ownership of several key areas. He implemented the radix sort algorithm, contributed to the argument parsing and input validation logic, collaborated with srosu on identifying and fixing bugs throughout the codebase, and led the effort to restructure and reorganise the project for better readability and maintainability. He also refactored portions of the code to comply with the 42 Norm (norminette), ensuring the entire codebase passes style validation. His work made the project cleaner, more robust and improved the readability of the code.

Both contributors are able to explain and defend any part of the code.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` binary. The embedded `ft_printf` is compiled as a static library (`printf/libftprintf.a`) and linked automatically.

Other Makefile rules:

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full recompile
```

### Usage

```bash
./push_swap [FLAGS] <numbers>
```

Numbers can be passed as separate arguments or as a single quoted string:

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

The program outputs the sequence of operations to `stdout`, one per line.

### Flags

| Flag         | Description                                                                                              |
| ------------ | -------------------------------------------------------------------------------------------------------- |
| `--bench`    | Print sorting statistics to `stderr` (disorder score, strategy used, total ops, breakdown per operation) |
| `--adaptive` | Force adaptive mode (default behavior, included for completeness)                                        |
| `--simple`   | Force the simple sort algorithm — O(n²)                                                                  |
| `--medium`   | Force the medium sort (Turkish sort by chunks) — O(n√n)                                                  |
| `--complex`  | Force the radix sort — O(n log n)                                                                        |

Flags can be combined with the number list in any order:

```bash
./push_swap --bench --complex 42 17 3 99 56
```

### Verifying the output

To verify that the output actually sorts the stack correctly, use the checker (bonus):

```bash
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
```

Or use the checker provided on the 42 intranet:

```bash
./push_swap 5 3 1 4 2 | ./checker_linux 5 3 1 4 2
```

### Error handling

The program prints `Error` to `stderr` and exits with code 1 in the following cases: non-integer input, values outside the `INT` range, duplicate values, or invalid arguments.

```bash
./push_swap --adaptive 0 one 2 3   # Error
./push_swap --simple 3 2 3         # Error (duplicate)
```

## Algorithms

### Disorder Metric

Before any sorting takes place, the program computes a **disorder score** between `0.0` and `1.0`. This score is the ratio of _inversions_ (pairs where a larger number appears before a smaller one) over the total number of pairs:

```
disorder = inversions / total_pairs
```

- `0.0` means the stack is already sorted.
- `1.0` means every pair is inverted (worst case, fully reversed stack).

This metric is computed in O(n²) time as a one-time pre-sort step and is never re-evaluated mid-sort.

### Adaptive Strategy — Threshold Rationale

The adaptive mode maps disorder ranges to algorithms as follows:

| Disorder range  | Algorithm                    | Complexity |
| --------------- | ---------------------------- | ---------- |
| `< 0.2`         | Simple sort                  | O(n²)      |
| `0.2 ≤ d < 0.5` | Medium sort (Turkish chunks) | O(n√n)     |
| `≥ 0.5`         | Radix sort                   | O(n log n) |

**Why 0.2 as the low threshold?**
Below 20% inversion ratio, the stack is nearly sorted. A quadratic strategy pays off here because the constant factor is tiny — almost no elements actually need moving, and the overhead of chunk setup or bit-level passes would be wasteful. In practice, this covers already-sorted, reversed-prefix, and single-swap cases efficiently.

**Why 0.5 as the high threshold?**
Above 50% inversion ratio, the disorder is close to maximal. Chunk-based approaches lose their edge because no element range is naturally grouped. Radix sort, which is blind to order and depends only on bit representation, becomes consistently efficient and its O(n log n) advantage over O(n√n) becomes significant at larger n.

---

### Simple Sort — O(n²)

**Used when:** disorder < 0.2

**Approach:** Handles sizes ≤ 5 with hardcoded optimal routines (dedicated sequences for 2, 3, 4, and 5 elements). For larger nearly-sorted inputs, elements are extracted one by one using median-aware `ra`/`rra` selection to minimise rotations before each push.

**Complexity argument:** Each of the n elements requires at most O(n) rotations to position, giving O(n²) operations total. For nearly-sorted inputs the constant is very small — most elements are already close to their target position, so the actual operation count is far below worst case.

**Space:** O(1) auxiliary (the two stacks are the working memory).

---

### Medium Sort — O(n√n)

**Used when:** 0.2 ≤ disorder < 0.5

**Approach:** A Turkish sort by value chunks. Elements are pushed to stack b in chunks of increasing value ranges, with chunk size adapted to input size (10 for ≤ 50 elements, 50 for ≤ 100, 100 beyond). A cost function determines the cheapest element to move at each step, exploiting simultaneous rotations (`rr`, `rrr`) when both stacks need to move in the same direction.

**Complexity argument:** With √n chunks of size √n, each chunk requires O(n) rotations to locate and push all its members, giving O(n · √n) = O(n√n) total operations. The simultaneous rotation optimisation reduces the constant factor significantly.

**Space:** O(1) auxiliary.

---

### Radix Sort — O(n log n)

**Used when:** disorder ≥ 0.5

**Approach:** Applied on the _normalised_ representation of the stack (values replaced by their sorted rank: 0, 1, 2…). Iterates bit by bit (LSD), pushing elements whose current bit is `0` to stack b and rotating those whose bit is `1` in stack a, then pulling everything back. Requires ⌈log₂ n⌉ passes.

**Complexity argument:** Each pass costs O(n) operations (one push or rotate per element). With ⌈log₂ n⌉ bits needed to represent ranks up to n−1, the total is O(n log n). No cost function or comparison is needed — the algorithm is order-agnostic, which makes it robust for highly disordered inputs.

**Space:** O(1) auxiliary (normalisation reuses the stack nodes in-place).

---

### Benchmark Results

| Input size  | Strategy    | Operations |
| ----------- | ----------- | ---------- |
| 100 numbers | Medium sort | ~600 ops   |
| 500 numbers | Medium sort | ~6 400 ops |
| 500 numbers | Radix sort  | ~6 400 ops |

Performance targets from the subject:

| Input       | Pass     | Good    | Excellent |
| ----------- | -------- | ------- | --------- |
| 100 numbers | < 2 000  | < 1 500 | < 700     |
| 500 numbers | < 12 000 | < 8 000 | < 5 500   |

## Technical Choices

**Doubly linked list:** chosen for its natural fit with stack operations — push, rotate and reverse rotate all reduce to pointer rewiring at the head or tail, with no shifting of elements.

**Value normalisation:** before sorting, all values are replaced by their sorted rank (0 to n−1). This is essential for the radix sort (which operates on bit representations) and simplifies comparisons throughout.

**Custom ft_printf with fd support:** the `ft_printf` from a prior 42 project was extended to accept a file descriptor as its first argument, allowing operations to be printed to `stdout` (fd 1), errors to `stderr` (fd 2), and bench output to `stderr` as well — without mixing concerns.

**Global variables:** none used, in compliance with the 42 Norm.

## Resources

**Sorting theory & algorithms**

- [Pancake sorting — Wikipedia](https://en.wikipedia.org/wiki/Pancake_sorting) — theoretical basis for rotation-based sorting
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — bit-indexed partitioning approach
- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Amortized analysis — Wikipedia](https://en.wikipedia.org/wiki/Amortized_analysis) — for reasoning about rotate costs across sequences of operations
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — time & space complexity reference
- [Introduction to Algorithms (CLRS), Chapter 8 — Sorting in Linear Time](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) — authoritative reference on non-comparison sorts

---

**AI usage disclosure**

Claude (claude.ai) was used in the following scoped ways:

- **README drafting** — structure and wording were generated from our own descriptions of implementation choices and algorithm rationale; all technical claims were verified by both authors.

All code was written, understood, and submitted by the authors. AI was not used to generate or debug C code directly.
