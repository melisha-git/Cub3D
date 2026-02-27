# 🎮 Cub3D

A 3D maze game engine inspired by [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D), built using **raycasting** technology. Developed as part of the [School 21](https://21-school.ru/) (42 Network) curriculum.

![C](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-macOS%20%7C%20Linux-lightgrey)
![42](https://img.shields.io/badge/School-21%2F42-darkgreen)

---

## About

Cub3D is a graphics project that renders a realistic 3D perspective inside a maze from a 2D map using the **raycasting** technique — the same approach used in early '90s games like Wolfenstein 3D. The engine is written entirely in C using the **MiniLibX** graphics library.

### Features

- **Raycasting engine** — real-time 3D rendering from a 2D grid map
- **Textured walls** — different textures for North, South, East, and West walls
- **Sprite rendering** — objects placed within the map with proper depth sorting
- **Shadow / fog effect** — distance-based shading for added depth
- **HUD / life bar** — on-screen health indicator
- **Sound support** — audio integration for immersive gameplay
- **Screenshot mode** — save a BMP screenshot of the first rendered frame
- **Cross-platform** — runs on both **macOS** and **Linux** (platform detection via preprocessor macros)

---

## Getting Started

### Prerequisites

**macOS:**
- Xcode Command Line Tools (`xcode-select --install`)
- MiniLibX (included: `minilibx_mms/`)

**Linux:**
- `gcc`, `make`
- X11 development libraries:
  ```bash
  sudo apt-get install libx11-dev libxext-dev libbsd-dev
  ```
- MiniLibX for Linux (included: `minilibx-linux/`)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/melisha-git/Cub3D.git
cd Cub3D

# Build and launch
make && ./cub3D all_map/map.cub
```

### Screenshot Mode

Render the first frame and save it as a BMP image:

```bash
make && ./cub3D all_map/map.cub --save
```

---

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` `→` | Rotate camera |
| `ESC` | Quit |

---

## Map Format (`.cub`)

The game reads `.cub` configuration files that define textures, colors, and the map layout.

```
R  1920 1080          # Resolution
NO ./textures/n.xpm   # North wall texture
SO ./textures/s.xpm   # South wall texture
WE ./textures/w.xpm   # West wall texture
EA ./textures/e.xpm   # East wall texture
S  ./textures/sp.xpm  # Sprite texture
F  220,100,0          # Floor color (R,G,B)
C  225,30,0           # Ceiling color (R,G,B)

111111
100101
101001
1100N1
111111
```

**Map legend:**

| Symbol | Meaning |
|--------|---------|
| `1` | Wall |
| `0` | Empty space |
| `2` | Sprite |
| `N` `S` `E` `W` | Player start position & direction |

> The map must be enclosed by walls (`1`) on all sides.

---

## Project Structure

```
Cub3D/
├── all_map/             # Map files (.cub)
├── textures/            # Wall and sprite textures (.xpm)
├── sound/               # Sound files
├── parser/              # Map and config file parser
├── get_next_line/       # Line-by-line file reader (42 utility)
├── minilibx_mms/        # MiniLibX for macOS
├── minilibx-linux/      # MiniLibX for Linux
├── raycasting.c         # Core raycasting algorithm
├── sprites.c            # Sprite rendering and sorting
├── paint_sprite.c       # Sprite drawing
├── paint_background.c   # Floor and ceiling rendering
├── shadow.c             # Distance-based fog/shadow effect
├── move.c               # Player movement
├── turn.c               # Camera rotation
├── fn_paint_life.c      # HUD / health bar rendering
├── fn_save.c            # BMP screenshot export
├── fn_init_raycast.c    # Raycasting initialization
├── init_param.c         # Parameter initialization
├── init_press_key.c     # Key event handlers
├── init_pos_sprite.c    # Sprite position setup
├── init_texture_card_p.c# Texture loading
├── work_of_color.c      # Color utilities
├── error.c              # Error handling
├── main.c               # Entry point
├── cub.h                # Main header
├── cub_struct.h         # Data structures
├── Makefile             # Build system (macOS & Linux)
└── README.md
```

---

## How Raycasting Works

The engine casts one ray per vertical screen column from the player's position. Each ray travels through the 2D grid until it hits a wall. The distance to the wall determines the height of the vertical stripe drawn on screen — closer walls appear taller, creating a 3D perspective illusion.

For sprites, the engine calculates the distance from the player to each sprite, sorts them back-to-front, and renders them with proper scaling and depth occlusion.

---

## Cross-Platform Support

The project uses preprocessor macros to detect the operating system at compile time and link the appropriate MiniLibX library:

- **macOS** → `minilibx_mms/` (uses OpenGL/AppKit)
- **Linux** → `minilibx-linux/` (uses X11)

No code changes are needed to switch platforms — just run `make`.

---

## License

This project was created for educational purposes as part of the School 21 / 42 curriculum.
