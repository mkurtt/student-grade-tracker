# Student Grade Tracker

A student record manager written in C, using a singly linked list to store and manage student records.

## What it does

- Add a student (name, ID, grade)
- Delete a student by ID
- List all students
- Calculate the grade average
- Find the highest and lowest grade

## Why a singly linked list

Records are added and removed one at a time without needing a fixed capacity, so the list grows as far as memory allows. Since every operation walks the list from the start, a single `next` pointer per node is enough — no backward traversal is needed here.

## Build & run

```bash
gcc main.c -o main
./main
```
