/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:35 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/20 16:13:10 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/librt.h"

int main(int ac, char **av)
{
    t_scene *_scene;
    int fd;

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
    printf( CYAN"          ___                       ___                       ___                 \n"RESET);
    printf( CYAN"         /__/\\        ___          /__/\\        ___          /  /\\          ___   \n"RESET);
    printf( CYAN"        |  |::\\      /  /\\         \\  \\:\\      /  /\\        /  /::\\        /  /\\  \n"RESET);
    printf( CYAN"        |  |:|:\\    /  /:/          \\  \\:\\    /  /:/       /  /:/\\:\\      /  /:/  \n"RESET);
    printf( CYAN"      __|__|:|\\:\\  /__/::\\      _____\\__\\:\\  /__/::\\      /  /:/~/:/     /  /:/   \n"RESET);
    printf( CYAN"     /__/::::| \\:\\ \\__\\/\\:\\__  /__/::::::::\\ \\__\\/\\:\\__  /__/:/ /:/___  /  /::\\   \n"RESET);
    printf( CYAN"     \\  \\:\\~~\\__\\/    \\  \\:\\/\\ \\  \\:\\~~\\~~\\/    \\  \\:\\/\\ \\  \\:\\/:::::/ /__/:/\\:\\  \n"RESET);
    printf( CYAN"      \\  \\:\\           \\__\\::/  \\  \\:\\  ~~~      \\__\\::/  \\  \\::/~~~~  \\__\\/  \\:\\ \n"RESET);
    printf( CYAN"       \\  \\:\\          /__/:/    \\  \\:\\          /__/:/    \\  \\:\\           \\  \\:\\\n"RESET);
    printf( CYAN"        \\  \\:\\         \\__\\/      \\  \\:\\         \\__\\/      \\  \\:\\           \\__\\/ \n"RESET);
    printf( CYAN"         \\__\\/                     \\__\\/                     \\__\\/                \n" RESET);
    _scene->canvas = render(_scene->camera, _scene->world);
    set_events_and_display(_scene->canvas);
    return 0;
}