# gitpkg

Every OS need a package manager. For a project of Hell-like OS, I decided to write my own. \
It is supposed to be a wrapper for `git` from the TTY.

---

## Summary

- [Syntax](#Command Syntax)
- [Features](#Features)
- [Usage](#Usage)
- [Compilation](#Compilation)
    - [Depedencies](#Depedencies)
    - [Process](#Process)
- [TOOD](#TODO)

## Command Syntax

```bash
gitpkg search <keyword> # Look for repo using keywords
gitpkg read <repo>      # Display the README of a repo
gitpkg see <repo>       # Open the repo in lynx
gitpkg get <repo>       # Clone the repo using `git`
gitpkg help             # Display an help message
```

## Features

| Feature                  | Detail                                                     |
| ------------------------ | ---------------------------------------------------------- |
| Fetch                    | Use Github API to get repo details                         |
| README Visualization     | Display the README of a repo, if it exists                 |
| View in lynx             | Open the repo in Lynx Browser                              |
| Download                 | `git clone`                                                |
| GUI                      | No.                                                        |

## Usage

**Input:**
```bash
gitpkg search cargo
```

**Output:** 

```
rust-lang/cargo
mattt/CargoBay
cargo-generate/cargo-generate
javaee/cargotracker
killercup/cargo-edit
```

**Then:**

```bash
gitpkg read rust-lang/cargo   # Display the README
gitpkg get mattt/CargoBay     # Clone the repo
cd CargoBay                   # Congrats, you are in CargoBay 
```

## Compilation

### Depdencies:

- curl ( And I mean curl, not libcurl )
- grep
- cut
- git
- lynx 
- gcc
- make

### Process: 

To compile it, just use `make` and the executable will be found at `build/bin`

## TODO

- [ ] Display repo metadata in an `info` command
- [ ] Add a support to search for repo in github, gitlab or codeberg
- [ ] Add support for "pages"
- [ ] Add a support to choose the browser to view the repo in 
- [ ] Write a real JSON parser

---

![image](https://brainmade.org/white-logo.png)
