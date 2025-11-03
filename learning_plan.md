# C++ File I/O Learning Plan

This plan is designed to build your skills progressively, starting from basic file operations and culminating in parsing the complex MNIST dataset.

---

### Part 1: C++ File I/O Fundamentals (Text Files)

These tasks will familiarize you with the basics of reading and writing human-readable text files.

*   **Task 1.1: Hello, File!**
    *   **Goal:** Write a program that creates a new file named `hello.txt` and writes the string "Hello, C++ File I/O!" into it.
    *   **Concepts:** `std::ofstream`, opening a file, writing to a file, closing a file.

*   **Task 1.2: Read It Back**
    *   **Goal:** Write a program that reads the content from `hello.txt` and prints it to the console.
    *   **Concepts:** `std::ifstream`, checking if a file is open, reading from a file line by line.

*   **Task 1.3: Appending, Not Overwriting**
    *   **Goal:** Modify your program to open `hello.txt` and add a new line, "Learning is fun!", without erasing the original content.
    *   **Concepts:** `std::ios::app` (append mode).

*   **Task 1.4: Working with Numbers**
    *   **Goal:** Create a `std::vector<int>` with a few numbers. Write a program to save this vector to a file named `numbers.txt`, with each number on a new line. Then, write another program to read `numbers.txt` back into a new `std::vector<int>` and print it to verify.
    *   **Concepts:** Looping, string-to-integer conversion (`std::stoi`), integer-to-string conversion.

---

### Part 2: Diving into Binary Files

Binary files store raw bytes of data. This is essential for performance and for handling non-textual data like the MNIST dataset.

*   **Task 2.1: Writing Raw Bytes**
    *   **Goal:** Write a program that saves a single `int` (e.g., the number `12345`) to a file named `data.bin` in its raw binary format.
    *   **Concepts:** `std::ios::binary`, `ostream::write()`.

*   **Task 2.2: Reading Raw Bytes**
    *   **Goal:** Write a program to read the binary `int` back from `data.bin` and print its value to confirm it's correct.
    *   **Concepts:** `istream::read()`, `reinterpret_cast`.

*   **Task 2.3: The Endian Question**
    *   **Goal:** Understand your system's byte order. Write a small program that determines if your machine is big-endian or little-endian. Then, write a function `uint32_t swap_endian(uint32_t val)` that can flip the byte order of a 32-bit integer. This is the **most critical** skill for the MNIST task.
    *   **Concepts:** Bitwise operators (`<<`, `>>`, `&`, `|`), pointers/unions for byte inspection.

---

### Part 3: The MNIST Challenge

Now we apply all the learned skills to the real dataset.

*   **Task 3.1: Get the Data**
    *   **Goal:** Download the MNIST dataset and decompress it.
    *   **Action:** Download the four `.gz` files from [Yann LeCun's website](http://yann.lecun.com/exdb/mnist/) and use a command-line tool like `gzip -d <filename>` to decompress them into `...-ubyte` files.

*   **Task 3.2: Parse the Header**
    *   **Goal:** Write a C++ program to open the `train-images-idx3-ubyte` file in binary mode. Read the first 16 bytes (the header) and use your `swap_endian` function to correctly interpret and print the "magic number," the total number of images, and the dimensions (rows and columns).
    *   **Concepts:** Applying all previous binary reading and data manipulation skills.

*   **Task 3.3: Read One Image**
    *   **Goal:** After successfully reading the header, read the next 784 bytes (28 * 28) into a `std::vector<unsigned char>`.
    *   **Concepts:** Reading a fixed block of binary data.

*   **Task 3.4 (Recommended): Visualize the Image**
    *   **Goal:** To verify your success, write a function that prints your `std::vector<unsigned char>` to the console, mapping pixel intensity to characters (e.g., `.` for low values, `#` for high values). You should see a digit!
    *   **Concepts:** Simple data visualization, mapping values.

*   **Task 3.5: Build the Data Loader**
    *   **Goal:** Create a robust function or class that encapsulates the entire loading process. It should take a file path as input and return a complete dataset (e.g., `std::vector<std::vector<unsigned char>>` for images). Do the same for the label files.
    *   **Concepts:** Code organization, creating reusable components.

---
### Resources
*   [MNIST Database](http://yann.lecun.com/exdb/mnist/)
*   [C++ fstream documentation](https://en.cppreference.com/w/cpp/header/fstream)
*   [Endianness Explained](https://www.geeksforgeeks.org/little-and-big-endian-mystery/)
