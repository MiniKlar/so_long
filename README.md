# so_long

> A small top-down 2D game built from scratch with the **MLX42** graphics library.
> Walk across a `.ber` map, collect every item, reach the exit — and watch your move count climb.
>
> *Un petit jeu 2D en vue de dessus codé à la main avec **MLX42**. Traverse une carte `.ber`, ramasse tous les objets, atteins la sortie — et regarde ton compteur de mouvements grimper.*

---

## 🇬🇧 English

### Principle

`so_long` is a tile-based 2D game (42 school project). You control a player on a grid loaded from a `.ber` map file. The goal is simple: **collect every item, then reach the exit**. Each step is counted, and the number of moves is displayed on screen.

Before the window even opens, the map is fully parsed and validated: correct file extension, rectangular shape, walls all around the border, valid characters only, exactly one player, at least one collectible, at least one exit, and a guaranteed path to every item and to the exit (verified with a flood fill). If anything is wrong, the program prints a clear `Error\n...` message and exits.

The project also includes bonus features: animated sprites, a player that faces left or right depending on its direction, enemies/traps (`T`), and the live move counter rendered inside the window.

### Map format

Maps are plain text files with the `.ber` extension, made of the following characters:

| Char | Meaning           |
|:----:|-------------------|
| `1`  | Wall              |
| `0`  | Floor (walkable)  |
| `P`  | Player start      |
| `C`  | Collectible       |
| `E`  | Exit              |
| `T`  | Enemy / trap (bonus) |

A map must be rectangular and entirely surrounded by walls. Example:

```
1111111111111
100100P0000C1
1000011111001
100011E000001
1111111111111
```

### Controls

| Key                | Action      |
|--------------------|-------------|
| `W` / `↑`          | Move up     |
| `S` / `↓`          | Move down   |
| `A` / `←`          | Move left   |
| `D` / `→`          | Move right  |
| `Esc`              | Quit        |

Closing the window also quits the game.

### Build & Run

This project depends on **MLX42** (which itself requires `glfw`, `cmake`, plus the system libraries `libdl`, `pthread` and `libm`). The `Makefile` clones and builds MLX42 and the personal C library automatically.

```bash
# Build
make

# Run with a map of your choice
./so_long maps/map_sujet.ber
```

Other useful targets:

```bash
make clean    # remove object files and the cloned dependencies
make fclean   # clean + remove the so_long binary
make re       # full rebuild
```

> Note: a graphical environment is required. On a headless machine the window cannot open.

### What I learned

- **Graphics programming with MLX42**: initializing a window, loading PNG textures, creating image instances and drawing tiles to compose a scene.
- **Event loop & input handling**: reacting to key events through a key hook and updating game state on each frame through the loop hook.
- **Map parsing & validation**: reading a `.ber` file, building a 2D grid, and enforcing every rule (extension, charset, rectangular shape, enclosing walls, element counts) before launching.
- **Pathfinding via flood fill**: proving that every collectible and the exit are reachable from the player's start position.
- **Memory management**: carefully allocating and freeing the map, the collectible list, the textures and image buffers — no leaks, validated with Valgrind.

---

## 🇫🇷 Français

### Principe

`so_long` est un jeu 2D en tuiles (projet de l'école 42). Tu contrôles un joueur sur une grille chargée depuis un fichier de carte `.ber`. Le but est simple : **ramasser tous les objets, puis atteindre la sortie**. Chaque déplacement est compté et le nombre de mouvements s'affiche à l'écran.

Avant même l'ouverture de la fenêtre, la carte est entièrement analysée et validée : bonne extension de fichier, forme rectangulaire, murs tout autour du bord, caractères valides uniquement, exactement un joueur, au moins un objet, au moins une sortie, et un chemin garanti vers chaque objet et vers la sortie (vérifié par un flood fill). En cas d'erreur, le programme affiche un message clair `Error\n...` et s'arrête.

Le projet comprend aussi des bonus : sprites animés, un joueur qui regarde à gauche ou à droite selon sa direction, des ennemis/pièges (`T`) et le compteur de mouvements affiché en temps réel dans la fenêtre.

### Format de carte

Les cartes sont des fichiers texte d'extension `.ber`, composés des caractères suivants :

| Caractère | Signification        |
|:---------:|----------------------|
| `1`       | Mur                  |
| `0`       | Sol (praticable)     |
| `P`       | Position du joueur   |
| `C`       | Objet à collecter    |
| `E`       | Sortie               |
| `T`       | Ennemi / piège (bonus) |

Une carte doit être rectangulaire et entièrement entourée de murs. Exemple :

```
1111111111111
100100P0000C1
1000011111001
100011E000001
1111111111111
```

### Commandes

| Touche             | Action            |
|--------------------|-------------------|
| `W` / `↑`          | Aller en haut     |
| `S` / `↓`          | Aller en bas      |
| `A` / `←`          | Aller à gauche    |
| `D` / `→`          | Aller à droite    |
| `Échap`            | Quitter           |

Fermer la fenêtre quitte également le jeu.

### Compilation & Lancement

Ce projet dépend de **MLX42** (qui nécessite lui-même `glfw`, `cmake`, ainsi que les bibliothèques système `libdl`, `pthread` et `libm`). Le `Makefile` clone et compile automatiquement MLX42 et la bibliothèque C personnelle.

```bash
# Compilation
make

# Lancement avec la carte de ton choix
./so_long maps/map_sujet.ber
```

Autres cibles utiles :

```bash
make clean    # supprime les .o et les dépendances clonées
make fclean   # clean + supprime le binaire so_long
make re       # recompilation complète
```

> Remarque : un environnement graphique est nécessaire. Sur une machine sans affichage, la fenêtre ne peut pas s'ouvrir.

### Ce que ça m'a apporté

- **Programmation graphique avec MLX42** : initialiser une fenêtre, charger des textures PNG, créer des instances d'images et dessiner les tuiles pour composer la scène.
- **Boucle d'événements & gestion des entrées** : réagir aux touches via un key hook et mettre à jour l'état du jeu à chaque frame via le loop hook.
- **Parsing & validation de carte** : lire un fichier `.ber`, construire une grille 2D et appliquer toutes les règles (extension, charset, forme rectangulaire, murs englobants, comptage des éléments) avant de lancer.
- **Recherche de chemin par flood fill** : prouver que chaque objet et la sortie sont atteignables depuis la position de départ du joueur.
- **Gestion mémoire** : allouer et libérer soigneusement la carte, la liste des objets, les textures et les buffers d'images — sans fuite, vérifié avec Valgrind.
