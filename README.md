# gitpkg

Every OS need a package manager. For a project of Hell-like OS, I decided to write my own. \
It is supposed to be a wrapper for `git` from the TTY.

---

## Command Syntax

```bash
gitpkg search <keyword> # Look for repo using keywords
gitpkg read <repo>      # Display the README of a repo
gitpkg see <repo>       # Open the repo in lynx
gitpkg get <repo>       # Clone the repo using `git`
gitpkg help             # Display an help message
```

## Fonctionnalités 

| Feature                  | Détail                                                     |
| ------------------------ | ---------------------------------------------------------- |
| Fetch                    | Accéder à l'API de Github et trouver des repos             |
| README Visualization     | Afficher le README d'un repo, s'il existe                  |
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

## Screenshots 

*Later, later*

## TODO

- [ ] Display repo metadata in an `info` command
- [ ] Add a support to search for repo in github, gitlab or codeberg
- [ ] Add support for "pages"
- [ ] Add a support to choose the browser to view the repo in 
- [ ] Write a real JSON parser

---

![image](https://brainmade.org/white-logo.png)
