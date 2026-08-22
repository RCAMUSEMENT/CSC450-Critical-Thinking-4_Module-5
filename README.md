# CSC450: Programming III — Critical Thinking 4

**Student Name:** Ryley Carlson
**Course:** CSC450 - Programming III (Module 5)
**Development Environment:** Visual Studio Code (C/C++ Extension Pack)
**Compiler Toolchain:** GCC / G++ Cross-Platform Environment

---

## Project Overview

This repository contains the complete deliverables for the Module 5 Critical Thinking assignment. The project focuses on persistent file-stream manipulation, sequential character buffer mapping, and dual-pointer string array inversion:

1. **Sacred Runic Grimoire OS (`Grimoire.cpp` / `Grimoire.exe`):** An interactive console application stylized as a fantasy Isekai anime summoning circle interface. The application is engineered to safely ingest arbitrary text data from the keyboard stream, append the payload to a persistent ledger while preserving historical text lines, extract and reverse the full character array via an in-place inversion engine, and compile the raw reflected results into an independent secondary output file.
2. **System Design Pseudocode:** A high-level algorithmic blueprint detailing robust stream availability validation checkpoints, file append configurations, input array tracking boundaries, and character sequence transformations to prevent data corruption.

---

## Hardware Optimization Note

While Eclipse IDE was originally recommended for this course, it utilizes a heavy GUI runtime framework that creates an overwhelming processing overhead on integrated graphics processing units. To mitigate UI thread blocking, asset delay bottlenecks, and local development system lag, this entire project environment was migrated to a highly optimized Visual Studio Code workspace configuration. This lean environment ensures that delayed cosmetic scrolling animations run smoothly without stalling background data-handling buffers.

---

## Compilation and Execution Instructions

To compile and run the source file manually via your local native terminal framework, execute the following compiler commands:

### 1. Sacred Runic Grimoire Binary Compilation
```bash
g++ -std=c++17 -Wall Grimoire.cpp -o Grimoire.exe
./Grimoire.exe
```

---

## Identified Bug Fixes & Security Enhancements

### Grimoire.cpp Features:
* **Eliminated Executable Path Injection Bugs:** Patched a critical input routing bug by swapping out raw command-line arguments for an explicit `std::getline(cin, userInput)` loop, completely preventing the program from accidentally writing the system folder path into your text files.
* **Mitigated Text File Truncation Data Loss:** Enforced the strict `std::ios::app` standard flag during the primary file stream instantiation, locking the output pointer securely to the end of the file and ensuring pre-existing lines 1 through 3 are never wiped out or corrupted.
* **Preserved Structural Boundary Alignment:** Engineered an active look back condition that programmatically fires a `.pop_back()` mutation on the ingested string vector, clearing away artificial trailing line breaks to ensure the reversed file structure mirrors the original exactly.
* **Isolated Fresh Compilation Buffers:** Configured the target output stream with the strict `std::ios::trunc` file mode, forcing the system to securely wipe old historical reversed attempts and generate a fresh, uncorrupted data matrix on every deployment run.