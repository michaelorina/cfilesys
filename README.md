# cfilesys - A Simple In-Memory File System in C

For this week's Thursday build, I created **cfilesys**—a lightweight, in-memory file system written in **C**. This project explores **directory structures, memory management, and file system operations** while maintaining a **minimal yet functional CLI interface**.

## 🚀 Features
- ✅ In-memory directory tree structure  
- ✅ Basic file system commands (`mkdir`, `ls`, `cd`, `exit`)  
- ✅ Dynamic memory management for directory operations  
- ✅ CLI for interacting with the virtual file system  
- ✅ Modular structure with `Makefile` for easy compilation and testing  

## 🛠 Installation & Usage
Clone the repository:
```sh
git clone https://github.com/michaelorina/cfilesys.git
cd cfilesys
```
## Build and Run:
```sh
make run
```
This will compile the project and start the CLI.

## Running Tests:
```sh
make test
```
Runs unit tests to verify functionality.

## 📂 Project Structure
```makefile
cfilesys/
│── src/          # Source code files
│── include/      # Header files
│── tests/        # Unit tests
│── build/        # Compiled binaries and object files
│── Makefile      # Build automation
│── README.md     # Project documentation
```
## 🤝 Contributing
Pull requests and suggestions are welcome! Let's build better C projects together.

