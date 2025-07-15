# AddressBook - Interactive Console Contact Manager

## Overview

This is a practice C++ project designed to demonstrate foundational programming skills including data structures, object-oriented programming, and user interaction through the console.

**AddressBook** is an interactive console application that manages contact information such as full name, email, and phone number. It stores contacts efficiently in a **binary search tree (BST)** data structure to allow fast search, insertion, and removal operations.

---

## Features

- Add new contacts with full name, email, and phone number.
- Search for contacts by full name (case-insensitive).
- Remove contacts from the address book.
- Display contact information in a neatly formatted console box.
- Efficient internal storage using a binary search tree for quick operations.

---

## Purpose

This project serves as a hands-on demonstration of:

- Implementing custom data structures (binary search tree) in C++.
- Working with pointers, dynamic memory allocation, and object lifetime management.
- Designing a modular program with classes and namespaces.
- Building an interactive console UI for user input and output.
- Handling string manipulation and case-insensitive comparison.

---

## Getting Started

### Prerequisites

- C++ compiler with C++11 (or later) support.
- CMake (optional, if using a CMake build system).

### Build Instructions

```bash
git clone https://github.com/yourusername/AddressBook.git
cd AddressBook
mkdir build
cd build
cmake ..
make
./AddressBook
