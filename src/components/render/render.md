### key steps:

1. **Initialize mlx and window**
2. **Create an image buffer to draw on**
3. **Cast rays for each vertical stripe on the screen**
4. **Calculate wall distances and texture mapping**
5. **Draw vertical strips (walls) with correct height and texture**
6. **Draw floor and ceiling**
7. **Render additional elements like minimap, player, doors, weapons**
8. **Display the image on the window**
9. **Handle input and update the scene each frame**

---

### A minimal example outline based on your structs and functions:

```c
int game_loop(t_cub *cub)
{
    int x;
    float ray_angle;
    float ray_step = (PI * 2) / WIDTH; // total FOV divided by screen width

    clear_image(cub);  // clear previous frame

    draw_split_background(cub); // floor + ceiling

    for (x = 0; x < WIDTH; x++)
    {
        ray_angle = cub->player.angle - (PI / 6) + ray_step * x; // assume 60 degree FOV (PI/3)

        t_ray_params params;
        init_ray_params(&params, cub, ray_angle);

        // Raycast: perform DDA or similar to find wall hit
        while (1)
        {
            // Move ray in map grid based on params.step_x/y and side_dist_x/y
            // Check map for wall hit, set params.hit_tile when found
            // Set params.side = 0 or 1 (vertical/horizontal wall)
            // break when hit
        }

        // Calculate perpendicular distance to avoid fish-eye distortion
        float perp_dist = ...; // use params and cub->player.x/y

        // Calculate wall height on screen
        int line_height = (int)(HEIGHT / perp_dist);

        int draw_start = HEIGHT / 2 - line_height / 2;
        int draw_end = HEIGHT / 2 + line_height / 2;

        // Choose texture based on wall hit side and direction

        // Calculate texture coordinate (tex_x)

        // Draw vertical line of pixels from draw_start to draw_end with texture colors
        draw_wall(cub, x, &ray_data, perp_dist);
    }

    draw_minimap(cub); // optional minimap

    draw_weapon(cub); // optional weapon overlay

    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);

    return (0);
}
```

---

### Key mlx functions you will use:

* `mlx_init()` — initialize mlx connection
* `mlx_new_window()` — create the window
* `mlx_new_image()` — create an image buffer to draw pixels on
* `mlx_get_data_addr()` — get raw pixel buffer to write to
* `mlx_put_image_to_window()` — display your rendered image to the window
* `mlx_loop()` — main loop of mlx to keep window alive
* Input hooks: `mlx_hook()`, `mlx_key_hook()`, etc.

---

### How to draw pixels on your image (example function):

```c
void my_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    if (x < 0 || y < 0 || x >= img->width || y >= img->height)
        return;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
```

---

### Typical initialization flow:

```c
void init_cub(t_cub *cub)
{
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3D");
    cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
    cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
                                      &cub->img.line_length, &cub->img.endian);
    cub->img.width = WIDTH;
    cub->img.height = HEIGHT;

    // Initialize player pos, angle, textures, map, etc.
}
```

---

### Next steps for your code:

* Implement **raycasting logic** in your `init_ray_params` and the ray step loop to detect wall collisions
* Compute **correct wall height** based on perpendicular distance
* Map the **correct texture slice** to the vertical wall column
* Draw **floor and ceiling** colors/pixels outside wall height
* Add **input handling** for player movement and rotation
* Put the **render loop** inside mlx loop with hooks (like `mlx_loop_hook`)

---

### Example minimal main loop setup:

```c
int main(int argc, char **argv)
{
    t_cub cub;

    // Parse map and initialize cub here...

    init_cub(&cub);

    mlx_loop_hook(cub.mlx, game_loop, &cub);
    mlx_hook(cub.win, 2, 1L<<0, key_press, &cub);
    mlx_hook(cub.win, 3, 1L<<1, key_release, &cub);
    mlx_hook(cub.win, 17, 0, close_window, &cub);

    mlx_loop(cub.mlx);

    return (0);
}
```