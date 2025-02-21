/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:07:03 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 17:41:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

/*MAIN*/

int		correct_extension(char *file_name);
int		ft_initialize(t_data *data);
int		ft_open_file(char *filename);

/*CLEAN FREE EXIT*/

int		ft_clean_layout(t_data *data);
int		free_char_tab(char **texture_file);
int		ft_free_exit(char *line, char **rgb_tab, t_data *data, int i);
int		ft_clean_data_and_exit(t_data *data);

/*PARSING METADATA*/

int		check_texture(t_data *data);
int		check_config_data(t_data *data);
int		format_ceilling_color(char *line, t_data *data);
int		format_floor_color(char *line, t_data *data);
int		ft_trim_tab(char **rgb_tab);
int		ft_end_file(t_data *data);

/*PARSING METADATE UTILS*/

int		ft_is_number(char *str);
int		ft_set_texture(t_data *data, char *line);
void	ft_print_tab(char **rgb_tab);
int		parse_map(t_data *data);
int		ft_store_metadata(t_data *data);
int		ft_set_north_texture(char *line, t_data *data);
int		ft_check_north_doublon(char *line, t_data *data);
int		ft_set_south_texture(char *line, t_data *data);
int		ft_check_south_doublon(char *line, t_data *data);
int		ft_set_west_texture(char *line, t_data *data);
int		ft_check_west_doublon(char *line, t_data *data);
int		ft_set_east_texture(char *line, t_data *data);
int		ft_check_east_doublon(char *line, t_data *data);
int		ft_check_floor_doublon(char *line, t_data *data);
int		ft_check_ceilling_doublon(char *line, t_data *data);
int		ft_check_for_doublon(t_data *data);

/*PARSING MAP*/

int		parse(t_data *data);
int		parse_map(t_data *data);
int		ft_store_map(t_data *data);

/*PARSING MAP UTILS*/
/*Move in the map(index)*/
int		skip_metadata(t_data *data);
int		get_map_index(t_data *data);
int		*ft_go_to_map(t_data *data);
/*manipulate map's data*/
int		ft_calculate_map_height_and_width(t_data *data);
int		ft_store(t_data *data);
int		replace_spaces(t_data *data);
char	*ft_trim_line(char *line);
int		ft_initialize_layout(t_data *data);
int		set_player_position(int i, int j, t_data *data);
int		restore_map(t_data *data);
int		ft_fill_layout(t_data *data);
int		is_walkable(char c);
/*check map reauirements*/
int		check_allowed_character(t_data *data);
int		check_first_last_row(t_data *data);
int		check_first_last_column(t_data *data);
int		ft_check_flag(int flag, t_data *data);
int		check_player(t_data *data);
int		check_boundaries(t_data *data);
int		check_every_neighbore(t_data *data);
int		hole_in_the_map(t_data *data, int i, int j);
/*floodfill algorithm*/
int		floodfill_algo(t_data *data, int i, int j);
int		check_algo_floodfill(t_data *data);

/*TEST & DEBUG*/

int		print_map(t_data *data);
int		test_parsing_metadata(t_data *data);

//libft add
char	*ft_strjoin_array(char **strs, int nb);

#endif /* FUNCTIONS_H */
