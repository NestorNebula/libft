<a id="top"></a>

<div align="center">
    <h3>Libft</h3>
</div>

---

### Table of Contents

- [Description](#description)
  - [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Tests](#tests)
- [Usage](#usage)
  - [Disclaimer](#disclaimer)
- [License](#license)
- [Contact](#contact)
- [Acknowledgments](#acknowledgments)

---

## Description

This project is my implementation of the first 42 project, "Libft".

It is a library that contains reimplementations of libc functions, behaving like the originals.

These functions are completed by a set of new functions that are not included in the libc or exist in a different form. For each new function, a short description is available in their file.

Bonus functions, working on Linked List structures are also provided in `_bonus.c` files.

### Built With

[![C](https://skillicons.dev/icons?i=c&theme=light)](https://www.c-language.org/)

## Getting Started

### Prerequisites

- Criterion (For testing only)

### Installation

1. Fork the repository (https://github.com/NestorNebula/libft)

2. Clone the forked repository to your local machine
   ```
   git clone git@github.com:<your username>/<repo name>.git
   ```
3. Update the remote URL

   ```
   # SSH:
   git remote add upstream git@github.com:NestorNebula/libft.git

   # HTTPS:
   git remote add upstream https://github.com/NestorNebula/libft.git
   ```

4. Build the repository's library, including the bonus if necessary
   ```
   make (bonus)
   ```

### Tests

Tests are provided for each function in the `tests` directory.

To execute them, you will need the [Criterion Testing Framework](https://github.com/Snaipe/Criterion) installed on your computer.

1. Go to the tests directory
   ```
   cd tests
   ```
2. Update the `CRITERION` variable in the tests Makefile. This should correspond to the path to the criterion library on your computer.
3. Build the tests
   ```
   make
   ```
4. Run the tests
   ```
   ./do_tests
   ```

## Usage

Once built, the library can be linked to any C project during build. The functions can then be used in the program.

### Disclaimer

Please note that this project has been made public only to display my work and for learning purpose.

If you decide to use my project as your own personal work, you will be fully responsible for any repercussion that could occur.

Particularly, if you decide to use my work in any 42 project, this is considered as cheating by the 42 rules and can lead to sanctions.

## License

[![MIT License](https://img.shields.io/badge/License-MIT-darkcyan.svg?style=for-the-badge)](https://github.com/NestorNebula/libft/blob/main/LICENSE)

## Contact

Noa Houssier: [Github](https://github.com/NestorNebula) - [LinkedIn](www.linkedin.com/in/noahoussier)

## Acknowledgments

This project was done as a student of the [42](https://42.fr) Paris school.

To learn more about it, you can read the [subject](https://cdn.intra.42.fr/pdf/pdf/184866/en.subject.pdf).

<p align='right'>(<a href='#top'>go back to the top</a>)</p>
