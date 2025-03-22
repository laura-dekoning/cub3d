# Cub3D


[Raycasting Docs](https://lodev.org/cgtutor/raycasting.html)

[Raycasting Video](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Raycasting Video -> Github](https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c)



TODO:
[]	add framerate

TODO BONUS:
[]	add mouse-rotation
[]  add compass


maps:

 =================================
	data->map->rows = 5;   // y
	data->map->cols = 6;   // x
	char temp_map[5][6] = {
		"111111",
		"100101",
		"101001",
		"1000N1",
		"111111"
	};
 =================================
	data->map->rows = 8;   // y
	data->map->cols = 8;   // x
	char temp_map[8][8] =
	{
		"11111111",
		"10100001",
		"10100001",
		"10110001",
		"100S0001",
		"10000101",
		"10000001",
		"11111111"
	};
 =================================
	data->map->rows = 20;   // y
	data->map->cols = 20;   // x
		char temp_map[20][20] =
	{
		"11111111111111111111",
		"10000001000000000001",
		"10000001000000000001",
		"10000001000000000001",
		"11111001111111110001",
		"10000000000000000001",
		"10000000000000000001",
		"10000000000000000001",
		"10011111111100000001",
		"10010000000000000001",
		"10010000000000000001",
		"10010000000100000001",
		"10010000000100000001",
		"100100000001000N0001",
		"10010000000100000001",
		"10010000000111111111",
		"10010000000000000001",
		"10010000000000000001",
		"10000000000000000001",
		"11111111111111111111"
	};





TEXTURES:

Step 1: Understand the Texture Data Structure

Your texture is represented by this struct:

typedef struct mlx_texture
{
    uint32_t width;
    uint32_t height;
    uint8_t  bytes_per_pixel;
    uint8_t* pixels;
} mlx_texture_t;

What does this mean?

    width: The texture’s width in pixels.
    height: The texture’s height in pixels.
    bytes_per_pixel: Always 4 (RGBA), meaning every pixel uses 4 bytes.
    pixels: An array where every 4 consecutive values represent the Red, Green, Blue, and Alpha (transparency) of a pixel.

Example:
A 2x2 texture with red, green, blue, and white pixels could look like this:

pixels = [255, 0, 0, 255,    // Red pixel
          0, 255, 0, 255,    // Green pixel
          0, 0, 255, 255,    // Blue pixel
          255, 255, 255, 255]// White pixel

If you want to access the top-right pixel (Green), you calculate its index like this:

row = 0, col = 1
index = (row * width + col) * 4 = (0 * 2 + 1) * 4 = 4

🎯 Step 2: Figure Out Which Part of the Texture to Use

When the ray hits a wall, we want to map each vertical slice of the wall to a slice of the texture. But how do we figure out which part of the texture corresponds to each ray?
🔍 Horizontal vs Vertical Walls

    Horizontal walls: You’re crossing grid lines along the X-axis, so you use the Y-coordinate to pick the texture slice.
    Vertical walls: You’re crossing grid lines along the Y-axis, so you use the X-coordinate to pick the texture slice.

🏆 Example:

Imagine you're casting a ray at a wall that's 32 pixels wide and your texture is also 32 pixels wide.

    If the ray hits at X = 15 of the grid cell, you pick the 15th pixel from the texture.
    Formula:

texture_x = (hit_position_on_wall % GRIDSIZE) * (texture_width / GRIDSIZE)

If GRIDSIZE = 64 and texture_width = 64:

texture_x = (15 % 64) * (64 / 64) = 15

📐 Step 3: Draw the Vertical Slice

Now that you know the texture_x, you want to "stretch" the texture vertically so it matches the wall height. Imagine the texture is 64 pixels high and the wall slice is 200 pixels high.

    Loop through every pixel from wall_top to wall_bottom on the screen.
    For each screen pixel y, calculate its corresponding texture pixel:

texture_y = (y - wall_top) * texture_height / wall_height

🏆 Example:

If wall_top = 100, wall_height = 200, and texture_height = 64:

y = 150
texture_y = (150 - 100) * 64 / 200 = 50 * 64 / 200 ≈ 16

Now you have (texture_x, texture_y), and you can grab the color from the texture:

pixel_index = (texture_y * texture_width + texture_x) * 4
r = texture->pixels[pixel_index]
g = texture->pixels[pixel_index + 1]
b = texture->pixels[pixel_index + 2]

Draw that pixel on the screen at (ray_i, y).
🏁 Summary:

    Find where the ray hits the wall → Gives you the horizontal or vertical slice (texture_x).
    Calculate wall height → Decide how much the texture needs to "stretch."
    Loop through each vertical screen pixel → Map it to a texture pixel (texture_y).
    Draw each pixel → Grab the color from the texture and draw it!

Would you like me to add more examples, diagrams, or even animations to help visualize what’s happening? I can also walk you through the code line by line if you’d like. Let me know what you’d prefer! 🌟
You said:
yes please, walk me through the code line by line
ChatGPT said:

Alright! Let’s carefully walk through the code step by step, line by line. I’ll break it down into small pieces and explain what each part does, with simple examples along the way. Let’s go! 🚀
🏗️ Step 1: Picking the Right Texture

This part of the code decides which texture to use based on the wall's direction:

mlx_texture_t *get_wall_texture(t_data *data, t_ray *ray)
{
    if (ray->wall_side == NORTH)
        return (data->north_texture);
    else if (ray->wall_side == EAST)
        return (data->east_texture);
    else if (ray->wall_side == SOUTH)
        return (data->south_texture);
    else
        return (data->west_texture);
}

✅ What’s happening?

    ray->wall_side tells you which direction the wall is facing.
    Depending on the direction (NORTH, EAST, SOUTH, WEST), the function returns the corresponding texture.

🧠 Example:
If the ray hits a North wall, you’ll use data->north_texture.
📏 Step 2: Finding the Correct Column in the Texture

This code figures out which part of the texture corresponds to the ray's hit position on the wall:

int get_texture_x(t_ray *ray, mlx_texture_t *texture)
{
    float hit_pos;

    if (ray->wall_side == NORTH || ray->wall_side == SOUTH)
        hit_pos = ray->hit.x;
    else
        hit_pos = ray->hit.y;

    int texture_x = (int)(hit_pos) % GRIDSIZE;
    texture_x = (texture_x * texture->width) / GRIDSIZE;
    return (texture_x);
}

✅ What’s happening?

    When the ray hits the wall, ray->hit gives the exact point where the ray made contact.
    Depending on the wall direction:
        North/South walls: Use the X-coordinate of the hit.
        East/West walls: Use the Y-coordinate of the hit.
    Then, convert the hit position to the correct column in the texture:

    texture_x = (hit_pos % GRIDSIZE) * (texture->width / GRIDSIZE);

    This makes sure the texture stretches correctly across the wall.

🧠 Example:

    Suppose GRIDSIZE = 64 and texture->width = 64.
    The ray hits at hit_pos = 30.
    texture_x = (30 % 64) * (64 / 64) = 30.

Now you know that column 30 of the texture corresponds to this ray.
🖼️ Step 3: Drawing the Wall Slice

This is the most important part! It maps each vertical pixel on the screen to a pixel in the texture.

void render_3d_scene(t_data *data, t_ray *ray, int ray_i, int wall_top, int wall_bottom)
{
    mlx_texture_t *texture = get_wall_texture(data, ray);
    int texture_x = get_texture_x(ray, texture);
    float wall_height = wall_bottom - wall_top;

    int i = 0;
    while (wall_top + i < wall_bottom)
    {
        int y = wall_top + i;
        int texture_y = (i * texture->height) / wall_height;

        int pixel_index = (texture_y * texture->width + texture_x) * 4;
        uint8_t r = texture->pixels[pixel_index];
        uint8_t g = texture->pixels[pixel_index + 1];
        uint8_t b = texture->pixels[pixel_index + 2];

        uint64_t colour = (r << 24) | (g << 16) | (b << 8) | 255;

        put_pixel(data->window_image, ray_i, y, colour);
        i++;
    }
}

✅ What’s happening?

    Get the texture → Call get_wall_texture() to pick the right texture.
    Find the correct column → Call get_texture_x() to pick the right slice of the texture (texture_x).
    Loop through each screen pixel vertically:
        i is the vertical position in the wall slice.
        texture_y maps each vertical screen pixel to the texture:

    texture_y = (i * texture->height) / wall_height;

Get the color from the texture:

    pixel_index calculates the exact location of the pixel in the texture’s pixels array:

pixel_index = (texture_y * texture->width + texture_x) * 4;

Extract the Red, Green, and Blue components:

        r = texture->pixels[pixel_index];
        g = texture->pixels[pixel_index + 1];
        b = texture->pixels[pixel_index + 2];

    Draw the pixel:
        Combine the r, g, b values into a uint64_t colour and draw it with put_pixel().

🧠 Example:
Imagine:

    Texture size = 64x64.
    Wall slice = 200 pixels tall.
    On the 100th screen pixel from wall_top, the code calculates:

texture_y = (100 * 64) / 200 = 32

This means the 32nd row of the texture is used for that screen pixel.
📡 Step 4: Putting It All Together

Finally, cast_ray() and raycasting() handle the ray casting itself. You’ve already got this working, so the key takeaway is:

    cast_ray() figures out how tall each wall slice is and calls render_3d_scene() to draw it.
    raycasting() casts rays from left to right, rendering each vertical slice in the scene.

Every ray gets its own vertical slice, and the textures stretch to fit the walls, making it look like a 3D game!
🏅 Final Summary:

    Pick the Texture → Based on the wall's direction.
    Find the Right Column → Use the hit position to get texture_x.
    Stretch the Texture Vertically → Map each screen pixel to texture_y.
    Draw Each Pixel → Fetch the color from the texture and draw it.


The mirroring issue on the south and west walls is due to how the texture offset is calculated. Let’s carefully revisit the logic.

Currently, the texture offset is calculated as:

texture_x = fmod(ray->end_pos.x, GRIDSIZE) / GRIDSIZE;

However, this calculation works correctly only for certain wall orientations. Specifically:

    North and East walls: The texture coordinates align naturally.
    South and West walls: The coordinates need to be flipped because the rays hit the walls from the opposite side.

Fixing it:

    Identify the wall side:
    You already have ray->wall_side — we can use that!

    Flip the texture offset for South and West:
    When hitting these walls, subtract the offset from 1.0 to mirror it correctly.

Here’s the improved calculation:

if (ray->wall_side == SOUTH || ray->wall_side == WEST)
    texture_x = 1.0 - texture_x;