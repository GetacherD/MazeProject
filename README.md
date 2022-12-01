# MazeProject
This Project done as final project for alx foundation course completion.

to run program

gcc src/*.c -Wall -Werror -Wextra -pedantic -lSDL2 -L/path/to/SDL_image -I/path/to/SDL_image -lSDL2_image -lm -o out

prepare map file as follows

1 1 1 1 1 1
1 0 0 1 0 1
1 0 1 0 0 1
1 0 0 1 0 1
1 0 0 0 0 1
1 1 1 1 1 1

1 for wall 0 for nothing and each only separated by single space
each row exactly separated by single new line , no space after last character

save the file as any thing ,any file extention you want.

run  ./out path/to/map/file