# Push_swap

Sorted data is the best thing about computer science. But what if you have to sort it using only two stacks and a limited set of operations? This is the challenge of **push_swap**.

## 📋 The Project

The goal of this project is to write a program in C which calculates and displays on the standard output the smallest program, using Push_swap instruction language, that sorts the integers received as arguments.

### Rules
- You have 2 stacks, named **a** and **b**.
- At the start:
  - The stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack **b** is empty.
- The objective is to sort numbers into stack **a** in ascending order.

### Instructions

| Operation | Description |
| :--- | :--- |
| `sa` (swap a) | Swap the first 2 elements at the top of stack a. |
| `sb` (swap b) | Swap the first 2 elements at the top of stack b. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` (push a) | Take the first element at the top of b and put it at the top of a. |
| `pb` (push b) | Take the first element at the top of a and put it at the top of b. |
| `ra` (rotate a) | Shift up all elements of stack a by 1. The first element becomes the last one. |
| `rb` (rotate b) | Shift up all elements of stack b by 1. The first element becomes the last one. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one. |
| `rrb` (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one. |
| `rrr` | `rra` and `rrb` at the same time. |

## 🚀 Usage

### Compilation
To compile the project, run:
```bash
make
```

### Running the program
```bash
./push_swap 2 1 3 6 5 8
```

### Checking results
You can use the provided `checker_linux` to verify if the output sorts the stack correctly:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## 🧪 Testing

The project includes a comprehensive tester `push_swap_test_linux.sh`.

### How to use the tester:
1. Ensure the script has execution permissions:
   ```bash
   chmod +x push_swap_test_linux.sh
   ```
2. Run the script:
   ```bash
   ./push_swap_test_linux.sh
   ```

### Performance expectations
- **3 numbers**: <= 3 instructions.
- **5 numbers**: <= 12 instructions.
- **100 numbers**:
  - 5 points: < 700
  - 4 points: < 900
  - 3 points: < 1100
  - 2 points: < 1300
  - 1 point: < 1500
- **500 numbers**:
  - 5 points: < 5500
  - 4 points: < 7000
  - 3 points: < 8500
  - 2 points: < 10000
  - 1 point: < 11500

## 🛠️ Algorithm
This implementation uses:
- **Small Sort**: Specialized logic for 2, 3, and 5 elements.
- **Chunk Sort**: Divide numbers into chunks, push to stack B in a rough order, and then pull back to stack A using the most efficient rotations.

---
*Developed as part of the 42 School curriculum.*
# Push-_swap_
