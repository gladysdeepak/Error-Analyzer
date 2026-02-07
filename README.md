
# C Static Code Analyzer using Lex & Yacc

A comprehensive **static analysis tool for C programs**, built using **Lex (Flex)** and **Yacc (Bison)**, that detects a wide range of **logical, semantic, syntactic, memory, and runtime errors at compile time**.  
This project simulates a simplified **compiler front-end**, focusing on deep semantic analysis rather than code generation.

---

## 📌 Overview

This analyzer processes a C source file and reports **potential bugs and unsafe coding practices** before execution.  
It performs:

- Lexical Analysis (tokenization)
- Syntax Analysis (grammar validation)
- Semantic & Logical Analysis (stateful error detection)

The output consists of **clear, color-coded warnings and errors** with **exact line numbers**, helping developers debug early and efficiently.

---

## 🎯 Motivation

Many real-world C bugs—such as memory leaks, null pointer dereferences, infinite loops, and logical contradictions—can be detected **before runtime**.

This project was built to:
- Gain hands-on understanding of **compiler design concepts**
- Learn **Lex–Yacc integration**
- Implement **stateful static analysis**
- Bridge the gap between **theory and real compiler behavior**

---

## 🧠 System Architecture

The analyzer follows a classic compiler front-end pipeline:

```

C Source Code
↓
Lex (Flex) – Tokenization
↓
Yacc (Bison) – Parsing + Semantic Actions
↓
Symbol Tables & State Trackers
↓
Static Error & Warning Reports

```

### Core Components
- **Lexer (`.l`)**: Identifies tokens, keywords, operators, and tracks line numbers
- **Parser (`.y`)**: Validates grammar and triggers semantic checks
- **Symbol Table**: Tracks variables, types, scopes, initialization, and pointer states
- **Check Modules**: Independent semantic and logical error detectors
- **Master Program**: Runs all analyzers in parallel using process isolation

---

## 🚨 Error Detection Coverage

The analyzer detects **30+ error patterns**, including:

### 🔴 Memory & Pointer Errors
- Memory leaks
- Double free
- Invalid free (stack address)
- Use-after-free
- Null pointer dereference
- Missing NULL check after `malloc`
- Returning address of local variable
- Writing to read-only memory

### 🟡 Runtime & Semantic Errors
- Division or modulo by zero
- Segmentation faults (invalid dereference)
- Undeclared variables
- Variable redeclaration
- Uninitialized variable use
- Unreachable code
- Printf format mismatch

### 🟠 Logical & Control-Flow Errors
- Infinite loops (loop variable not modified)
- Assignment instead of comparison in conditions
- Missing `break` in `switch`
- Logical contradictions (`x < 5 && x > 10`)
- Misplaced semicolon after `if`
- Missing braces in conditional blocks
- Confusing operator precedence
- Bitwise operators in logical conditions

### ⚠️ Unsafe & Bad Practices
- Unsafe functions (`gets`, `strcpy`, `strcat`, `sprintf`)
- Buffer overflow risks in `scanf`
- Misuse of `sizeof`
- Invalid `void` casts

---

## 🧪 Sample Output

- Errors and warnings are **color-coded**
- Each message includes:
  - Error type
  - Description
  - Exact line number

Example:
```

Runtime Error: Division by zero at line 12
Semantic Error: Undeclared variable 'c' used at line 6
Style Warning: Missing braces in if statement at line 28

````

---

## 🛠️ Tech Stack

- **Language:** C
- **Tools:** Lex (Flex), Yacc (Bison)
- **Concepts Used:**
  - Compiler Design
  - Grammar Rules
  - Symbol Tables
  - Semantic Analysis
  - Process Management (`fork`, `exec`)




