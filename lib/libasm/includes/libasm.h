/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/14 00:09:17 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include "op.h"
# include "libft.h"

# define READ_BUF_SIZE 5
# define STR_MALOC_SIZE 1
# define ERR_INPUT_PARAMS_FIRST "Error: the program accepts only one "
# define ERR_INPUT_PARAMS_SEC "parameter as input (the full path to the file)"
# define ERR_INPUT_PARAMS ERR_INPUT_PARAMS_FIRST ERR_INPUT_PARAMS_SEC
# define ERR_FILE_EXT "Error: the file must have the extension .c"

void		asm_prog_error(char *msg);
void		asm_sys_error(void);
t_string	*asm_file_to_str(char *file_path);

#endif
