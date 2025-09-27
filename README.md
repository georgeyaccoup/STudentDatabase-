
# StudentDatabase

A simple C / CLI-based student database management application.  
This project allows users to add, edit, delete, view, and persist student records via file I/O.

---

## Table of Contents

1. [Features](#features)  
2. [Getting Started](#getting-started)  
3. [Usage](#usage)  
4. [Project Structure](#project-structure)  
5. [Build Instructions](#build-instructions)  
6. [Contributing](#contributing)  
7. [License](#license)  
8. [Author](#author)  

---

## Features

- Add new student records  
- Edit existing student information  
- Delete student entries  
- View all students or search by ID  
- Save records to a file (persistent storage)  
- Load records from file on startup  

---

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine for development and testing.

### Prerequisites

- A C compiler (e.g. `gcc`)  
- Make (optional, if a Makefile is provided)  
- Basic familiarity with command line / terminal usage  

---

## Usage

1. Clone the repository:  
   ```bash
   git clone https://github.com/georgeyaccoup/STudentDatabase-.git
   cd STudentDatabase-
````

2. Build the project (see **Build Instructions** below).

3. Run the executable. The program will prompt you with a menu to manage student records (add, edit, delete, view, etc.).

4. Changes will be saved to a file, and loaded automatically the next time you run the program.

---

## Project Structure

```
STudentDatabase-/
├── SDBAPP.c
├── SDB.c
├── SDB.h
├── STD.h
├── main.c
├── MainPage.cbp
├── MainPage.depend
├── MainPage.layout
└── (other build / object files)
```

* `main.c` — Entry point and menu handling
* `SDB.c` / `SDB.h` — Core student database operations (add, delete, edit, load, save)
* `SDBAPP.c` — Application-level logic bridging the UI/menu and data operations
* `STD.h` — Standard definitions, utility functions, macros
* `.cbp`, `.depend`, `.layout` — Project / build configuration files

---

## Build Instructions

From the project root:

```bash
gcc -o StudentDB main.c SDB.c SDBAPP.c
```

Optionally, if using an IDE or project file (`.cbp`, `.layout`), open them accordingly and build via your IDE.

---

## Contributing

Contributions, bug reports, and improvements are welcome! To contribute:

1. Fork the project
2. Create a new branch (`git checkout -b feature/YourFeature`)
3. Make changes
4. Submit a pull request with a clear description

Please follow consistent coding style, include comments, and update the README if you add features.

---

## License

This project is open source. You may use, modify, and distribute it freely. (You can insert here a specific license such as MIT, GPL, etc., if desired.)

---

## Author

**George Read**
LinkedIn: [https://www.linkedin.com/in/george-yaccoup/](https://www.linkedin.com/in/george-yaccoup/)

```

::contentReference[oaicite:0]{index=0}
```
