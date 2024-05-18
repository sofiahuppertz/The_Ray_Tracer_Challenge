#include "libs/librt.h"

int main(int ac, char **av)
{
	t_scene *_scene;
	int   fd;

	_scene = scene();

   if (check_cmd_line(ac, av) == 1)
       return (1);
   fd = open(av[ac - 1], O_RDONLY);
   if (fd == -1)
    {
        perror("fd");
        close(fd);
        return (1);
    }
   if (check_file_rt(fd) == 1)
    {
        close(fd);
        return (1);
    }
    close(fd);
   	_scene->canvas = render(_scene->camera, _scene->world);
   	set_events_and_display(_scene->canvas);
    return 0;
}