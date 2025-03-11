# Cub3D


[Raycasting Docs](https://lodev.org/cgtutor/raycasting.html)

[Raycasting Video](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Raycasting Video Github](https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c)



TODO:
[]	game() - Optimize Rendering
		Currently, fill_canvas(data) is always called before game(), even if only a small change happened.
		Instead, clear only the player's old position before redrawing.
		If a full refresh is needed, consider double buffering to prevent flickering.


youtube video summary:

program your very own ray caster 
the first game to really make a ray caster engine popular was called Wolfenstein 3d back in 1992 
which at the time looked unbelievable that you could do this much on such slow computers at that time. 
there are several limitations to a ray caster engine you'll get to see how easy 
it is to create the actual code to write the game and how quickly it is to update an actual level. 
it is actually a top-down 2-dimensional game but we are gonna convert that into what looks like a 3d game 

what we're about to create, you can imagine as a world made from perfectly square cubes and we have 
a player in this world but he is unable to see anything. But he can cast a ray 
from his eyes forward until it hits one of these walls and then we can convert 
that Ray distance into a vertical line, and when you do this enough times you 
were able to now see the world you're in.

and what makes this technique so optimized is how few checks you actually 
have to do per Ray to detect the wall. 
- we will first use triangles on the horizontal grid lines.
- we'll save that distance and do the same on the vertical lines.
- we'll compare both and whichever hit closest we'll use as the vertical line strip.
and that's how we're going to convert to this 2d world into a "3d world" 

> I'm going to set the background to a dark grey  
> I'm going to set the new window dimension to 1024 by 512 pixels  
> I'm going to call this function in the main function and we'll 
add the standard C header files and I'm going to save this as a normal C file.

```
	void	fill_canvas(t_map_data *map)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < map->image->height)
	{
		x = 0;
		while (x < map->image->width)
		{
			if (x < map->image->width && y < map->image->height)
				mlx_put_pixel(map->image, x, y, 0x333333FF);
			x++;
		}
		y++;
	}
}


void	create_window(t_map_data *map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, false);
	if (map->window == NULL)
		ft_exit("Malloc allocation failed\n");
	map->image = mlx_new_image(map->window, WIDTH - MENU_WIDTH, HEIGHT);
	if (map->image == NULL)
	{
		mlx_terminate(map->window);
		ft_exit("Malloc allocation failed\n");
	}
	mlx_image_to_window(map->window, map->image, MENU_WIDTH, 0);
	fill_canvas(map);
	mlx_loop_hook(map->window, key_is_pressed, map);
	mlx_loop(map->window);
	mlx_delete_image(map->window, map->menu_image);
	mlx_delete_texture(map->menu_texture);
	mlx_terminate(map->window);
}

int	main(int argc, char **argv)
{
	t_map_data	*map;

	if (argc != 2)
		ft_exit("Incorrect number of arguments\n");
	map = (t_map_data *)ft_calloc(sizeof(t_map_data), 1);
	if (map == NULL)
		ft_exit("Malloc allocation failed\n");
	// parsing
	create_window(map);
	clear_everything(map);
}

```


- now let's add a player will give X and y position variables and a 
function to draw that player with the red and green values both set to 1.

that'll give us a yellow color let's call this function in our display 
function and we can initialize a player's position in here and there is 
but we're going to want to make him move we'll create a function with these 
opengl parameters to check if a key has been pressed well check if W a DRS has 
been pressed and we'll move the X or Y position in the positive or negative 
direction and we'll need to reference this function in the keyboard function 
in the main loop and there he goes we can now finally move our player it looks 
pretty lonely so let's give them a world to move around in let's create our own 
world that world's going to be a grid of 8x8 units and each of these cubes is 
going to be 64 units in size the level itself is going to be stored in a single 
array but I'll add some spaces so you can clearly see it zeros gonna represent 
empty spaces and a 1 that's gonna be where the wall is we don't want this 
player just walking off anywhere so let's lock this place down add a few 
walls here and here and maybe one here and the function to draw this map will 
be two for loops going through the X's and the Y values and offset by 60 for 
our cube size these walls will have a color of white and empty spaces will be 
black we need to call this function before we 
draw a player and let's compile and run this is correct but it could look a 
little better I'm going to add or subtract one pixel so it'll outline each 
of the cubes yeah our player finally has his own 
place to live you can go here or maybe here you can explore over here or maybe 
go over here and this is good but just a warned you our next step is gonna 
involve some math but but don't go don't go stay here I'll walk you through it 
so we want to rotate the player which means we'll have to use sine and cosine 
and the value of pi let's add the math dot H header file and we'll save the 
value of pi we now need to store the Delta X and Delta Y and angle of the 
player so now when we look left we'll have to subtract a small amount from 
that player's angle a small amount because in C the sine and cosine will 
use Radian values so instead of 0 to 360 degrees it's 0 to 2 pi which is around a 
6.28 value if we go less than 0 let's reset back to 2 pi the values returned 
from sine and cosine are very small so 
let's multiply that by 5 and looking right we add that small value and if we 
go above 2 pi let's reset back to zero moving forward and backwards is very 
simple since we just add that Delta X and Delta Y it would be pretty cool if 
we could see this direction so let's go ahead and draw that and let's calculate 
X and Delta Y when the program first runs and look at that I can now look at 
stuff look at him looking around looks like we made progress now I probably cut 
that joke it's not really a joke everything up to this point has been set 
up so now we can actually start casting rays here are the variables we will need 
for this function first we have to hold and set the raise angle to the players 
angle and let's just take things slow and cast one ray for now we will need 
the negative inverse of tangent so that'll be negative one divided by 
tangent so first up we're gonna check the horizontal gridlines let's find the 
x and y value where the Ray will first hit the closest horizontal line we first 
need to know if the Ray is looking up or down and we know this by looking at the 
Rays angle if it's less than pi aka 180 degrees then our Ray is facing upwards 
we want to round the Rays Y position to the nearest 64th value and a cool way to 
do that and impress your friends is to simply divide the value by 64 a bit 
shifting at 6 down and multiplying it by 64 or bit shifting at 6 up and subtract 
the small amount for accuracy the Rays X value is the distance between the player 
and the Rays Y position times the inverse of tangent plus we got to add
that players X position and once we find out the Rays first hit position we need 
the next X&Y offset so the y offset we will subtract 64 units and the X offset 
is the y offset value times the inverse of tangent now if the Ray is looking 
down and the values are exactly the same but but a little different so yeah it's 
not exactly the same just change here where we add 64 and here is a positive Y 
offset if the Ray is looking straight left or right it's impossible for the 
raid ever hit a horizontal line and we don't want to check forever and get 
caught in a loop so I'll added up the field to check to 8 
max so we know the large coordinates 
where the Ray will hit the wall but we need to know where that is in the map 
array let's take the Ray hip position and divide it by 64 and set that to find 
the position in the maps array if the map position is less than the 
array size then we can check it inside the map and if the value is 1 then there 
is a wall there so if we hit a wall we're done you can shut this loop down 
go to the beach take a few selfies run around in the sand have some fun you 
deserve it and when you come back let me know because this is my favorite part if 
we didn't hit a wall all we have to do to check the next horizontal line is add 
the X&Y offset that's it just a simple addition this is what makes a rake a 
stir so optimized and super fast and then finally let's draw this race 
starting from where the player is toward the Ray ended when we compile it'll look 
like this the green ray is actually doing exactly what we told it to do check the first 
horizontal grid line for any walls if none then add the X and y offset and 
check the next horizontal grid line if there is a wall there then end the loop 
and draw the Ray now don't let me lose you yet I know this looks intimidating 
let me just show you what we're fighting for your very own game that is easy to 
make and fun to play so just hang in there next up is the vertical line check 
we can put this drawing function on one line and copy and paste the horizontal 
chunk of code for this check we only need the negative tangent of the value 
of the raeangel we should update that new variable in these places and since 
we are checking vertical lines we need to know now if the Ray is facing left or 
right or up or down if we look at the unit circle we can see that the right 
side would be less than 90 degrees pi divided by 2 are greater than 270 
degrees 3 pi divided by 2 let's define those values so we can use them later and be 
to use the or symbol here and no I did not spend like 40 minutes trying to 
figure out why it wasn't working with the ant symbol it just it needs to be or 
which makes sense if you look at the unit circle anyways since this is now 
the vertical line check its flipped so all X's now become wise and all wise now 
become X's it's like opposite world and that's the only change we really need to 
make but we can draw this ray with a different color let's make it red and 
compile and run and is working correctly the Ray is casted out forward and stops 
when it hits a vertical line with the solid wall and this is the heart of the 
code let me show you both rays at once you can see where the green ray stops on 
the horizontal walls and the red stops on the vertical all I need to do now is 
only use and draw the shortest line that hits first before we continue I noticed 
that we're currently checking if the map value is less than the array size but we 
should also make sure that it's above zero - okay that's better we need a 
function that will return the distance between the player and the Rays endpoint 
that's the hypotenuse so we can use the Pythagorean theorem remember that we 
were looking for the shortest distance so let's make the default value really 
high and we will be saving the horizontal rays x and y position and the 
vertical is the same but with the V in the variable name and we don't need to 
draw this anymore and now if we hit a wall and after we go to the beach knife 
on and come back we should save the Rays X&Y position and calculate the Rays 
distance from the player same for the vertical but with the correct variable name 
with the shortest distance so if the vertical or horizontal is shorter then 
we set the raid to that variable and check that out isn't that cool the Ray 
now stops when it hits any side of the wall and this kind of looks like its own 
game to me reminds me of a spider-man's web next we'll draw a few more of these 
rays but want to move the next ray back one degree but since sine and cosine 
uses radians let's define that value if we initialize a ray angle back one 
degree from our player angle which should add our limits to the next angle 
and let's move back 30 degrees you can see the Ray is back 30 degrees 
from the players angle now let's increase the for-loop to draw 10 rays 
and after each ray is done we should increased array by one degree and set 
the limit again so far so good and no errors so let's cast 60 Ray's which will 
be 30 degrees to the left and right of the player we've done it and the Rays 
are working correctly and hey just for fun let me show you something cool you 
don't have to do this part but let me show you what all 360 Ray's looks like 
at once now that's pretty cool it looks like a light source shining 
light and casting shadows but this is not necessary for this so let's go back 
to 60 rays that's better [Music] 
we forgot to create a variable to hold the final distance and by we I mean Leo 
so let's set the new variable to the distance right here now we were ready to 
draw the 3d scene my window will be 320 by 160 pixels so the formula for each 
line height will be our cube size times our new screen height divided by that 
ray distance so the further away the larger the distance the shorter the 
final line height will be and let's cap the line at 320 no taller I'm going to 
use OpenGL to draw the line every eighth pixel and shift the window over to the 
right side you can see the line Heights are correct but we need each line to be 
offset to the center of the screen so the offset is just the full window 
height minus half the line height you would think it would be correct but do 
you see the warping this problem happens in all ray casters the fisheye effect 
actually makes sense because the further rays are a longer distance than the 
center rays but they need to be equal this is easy to fix with math cosine 
we need to find the distance between the player angle and the Ray angle make 
limits of course and multiply the rate distance by cosine of that new angle and 
now we have it a 2d top-down level that we can reformat into a quote-unquote 3d 
level but wait there's more in a normal 3d engine lighting can be a 
very difficult and complicated task for programmers but not for a ray caster 
remember that we know if the Ray hit a vertical or horizontal side so we can 
set each two different colors and that will be a simple form of lighting and 
shading it's amazing how simple lighting in a ray caster can be but wait there's more 
it's easy to change the level layout of the walls by simply updating the array 
[Music] 
but wait there's even more we can hold on to that array number and change the 
wall properties like have different colors or even wall Heights there is so 
much we can do with so little lines of code and that's why I find a ray caster 
so interesting and I really wanted to share it with you I can even optimize this even more and 
port it to my game boy advance this is running on the real hardware and I want 
to make a video tutorial to show you how you can program your own games on the 
game boy bands you can check out my other videos where a program minecraft 
or Zelda for the Gameboy Advance and leave your thoughts in the comments on 
this video or if you have any suggestions on future videos and if you 
like this we can do a part two where we add actual textures to the walls 
maybe floors and ceilings sprites collision enemies so much more we can 
add thank you for watching it this far I hope you learned something or at least 
enjoyed the video and as always thank you for watching 