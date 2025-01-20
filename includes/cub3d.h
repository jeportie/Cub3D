#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>  // for close, etc.
# include <math.h>     // for cos, sin, etc. (may need -lm)
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"

# define WINDOW_WIDTH   800
# define WINDOW_HEIGHT  600

# define MAP_WIDTH      8
# define MAP_HEIGHT     8
# define TILE_SIZE      64

# define SPEED          200.0  // Movement speed in pixels per second
# define ROT_SPEED      1.0    // Radians per second (will multiply by 5)

typedef struct s_player
{
    double  x;          // Player x-position (pixels)
    double  y;          // Player y-position (pixels)
    double  angle;      // Player viewing angle in radians
    double  dx;         // cos(angle)
    double  dy;         // sin(angle)

    bool    move_up;
    bool    move_down;
    bool    move_left;
    bool    move_right;

    bool    rot_left;   // Pressing left arrow
    bool    rot_right;  // Pressing right arrow
}   t_player;

typedef struct s_image
{
    void    *img_ptr;
    char    *addr;
    int     bpp;            // bits per pixel
    int     line_len;
    int     endian;
}   t_image;

typedef struct s_data
{
    void            *mlx;
    void            *win;
    t_image         img;
    t_player        player;
    struct timespec last_time;
    double          delta_accumulator;
    int             map_offset_x;
    int             map_offset_y;
}   t_data;

/**
 * Global 8x8 map
 */
static char g_map[MAP_HEIGHT][MAP_WIDTH + 1] =
{
    "11111111",
    "10000001",
    "10000001",
    "10000001",
    "10000001",
    "10000001",
    "1P000001",
    "11111111"
};

#endif
