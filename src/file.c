#include "../headers/main.h"

/**
 * _memset - set allocated memory initial value to 0
 * @map: 2D array (allocated memory)
 * @size: size of row or number of columns
 */
void _memset(int **map, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			map[i][j] = 0;
		}
	}
}
/**
 * free_map - free allocated memory for map
 * @map: - map to be freed
 * @rows: number of rows of map allocated
 */
void free_map(int **map, int rows)
{
	int i;

	for (i = 0; i < rows; i++)
	{
		free(map[i]);
	}
	free(map);
}
/**
 * print_map - print all data of map
 * @map: 2D map array to be printed
 * @size: size of rows / columns
 */
void print_map(int **map, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d\t", map[i][j]);
		}
		printf("\n");
	}
}
/**
 * readToMap - read all chars except space and newline to map
 * @fo: file to be read from
 * @map: map to recieve character data as int
 */
void readToMap(FILE *fo, int **map)
{
	int i, j, c;

	i = j = 0;
	while (true)
	{
		c = fgetc(fo);
		if (c == EOF)
			break;
		if (c == ' ')
			continue;
		else if (c == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			map[i][j] = c - '0';
			j++;
		}
	}
}
/**
 * loadMap - load map from file
 * @filename: file name of file for map
 * Return: Map struct containing size and map
 */
Map loadMap(char *filename)
{
	FILE *fo;
	int len, col, row, i;
	Map map;

	map.map = NULL;
	map.size = 0;
	fo = fopen(filename, "r");
	if (fo == NULL)
		return (map);
	fseek(fo, 0, SEEK_END);
	len = ftell(fo);
	fseek(fo, 0, SEEK_SET);
	row = col = sqrt(len / 2);
	map.map = (int **)malloc(sizeof(int *) * row);
	if (map.map == NULL)
		return (map);
	for (i = 0; i < row; i++)
	{
		map.map[i] = (int *) malloc(sizeof(int) * col);
		if (map.map[i] == NULL)
		{
			free_map(map.map, i);
			return (map);
		}
	}
	_memset(map.map, row);
	readToMap(fo, map.map);
	for (i = 0; i < row; i++)
	{
		map.map[0][i] = 1;
		map.map[i][0] = 1;
		map.map[row - 1][i] = 1;
		map.map[i][row - 1] = 1;
	}
	fclose(fo);
	map.size = row;
	return (map);
}
