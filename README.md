# 🔗 URL Shortener in C++ (CLI-based Project)

This is a simple, beginner-friendly *URL Shortener* built using *C++*. It generates a short URL from a long one (like YouTube links), stores the mapping temporarily in memory, and allows you to decode it back to the original.

> ✅ No server, no website — everything works in the terminal itself.

---

## 📌 Features

- Shortens long URLs with random 6-character codes
- Simulates a real service using a local domain (http://short.ly/)
- Remembers shortened URLs during the session
- Allows decoding of short URLs back to original
- Opens the original URL in your *default browser* (optional redirect)
- Beginner-friendly and entirely written in *standard C++*

---

## 🚀 How It Works

1. You input a long URL (e.g., a YouTube link)
2. It generates a fake short URL like: http://short.ly/aB9Xz2
3. You paste that short URL into the program
4. The program decodes it and opens the original link in your browser

---

## 🛠️ Requirements

- A C++ compiler (e.g., g++, MSVC, clang)
- Works on:
  - Windows
  - macOS
  - Linux

---

## ▶️ How to Run

1. *Clone or download* this project
2. *Compile the file* using:

   ```bash
   g++ -o urlshortener url_shortener.cpp
