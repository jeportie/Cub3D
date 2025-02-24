/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:22:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 12:13:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"

/* --- Alphabet (lowercase, using ASCII codes) --- */
# define KEY_A           97      /* 'a' */
# define KEY_B           98      /* 'b' */
# define KEY_C           99      /* 'c' */
# define KEY_D           100     /* 'd' */
# define KEY_E           101     /* 'e' */
# define KEY_F           102     /* 'f' */
# define KEY_G           103     /* 'g' */
# define KEY_H           104     /* 'h' */
# define KEY_I           105     /* 'i' */
# define KEY_J           106     /* 'j' */
# define KEY_K           107     /* 'k' */
# define KEY_L           108     /* 'l' */
# define KEY_M           109     /* 'm' */
# define KEY_N           110     /* 'n' */
# define KEY_O           111     /* 'o' */
# define KEY_P           112     /* 'p' */
# define KEY_Q           113     /* 'q' */
# define KEY_R           114     /* 'r' */
# define KEY_S           115     /* 's' */
# define KEY_T           116     /* 't' */
# define KEY_U           117     /* 'u' */
# define KEY_V           118     /* 'v' */
# define KEY_W           119     /* 'w' */
# define KEY_X           120     /* 'x' */
# define KEY_Y           121     /* 'y' */
# define KEY_Z           122     /* 'z' */

/* --- Numerals (ASCII codes) --- */
# define KEY_0           48      /* '0' */
# define KEY_1           49      /* '1' */
# define KEY_2           50      /* '2' */
# define KEY_3           51      /* '3' */
# define KEY_4           52      /* '4' */
# define KEY_5           53      /* '5' */
# define KEY_6           54      /* '6' */
# define KEY_7           55      /* '7' */
# define KEY_8           56      /* '8' */
# define KEY_9           57      /* '9' */

/* --- Arrow keys (X11 KeySym values) --- */
# define KEY_LEFT_ARROW  65361   /* Left arrow */
# define KEY_UP_ARROW    65362   /* Up arrow */
# define KEY_RIGHT_ARROW 65363   /* Right arrow */
# define KEY_DOWN_ARROW  65364   /* Down arrow */

/* --- Function keys (X11 KeySym values) --- */
# define KEY_F1          65470   /* F1 */
# define KEY_F2          65471   /* F2 */
# define KEY_F3          65472   /* F3 */
# define KEY_F4          65473   /* F4 */
# define KEY_F5          65474   /* F5 */
# define KEY_F6          65475   /* F6 */
# define KEY_F7          65476   /* F7 */
# define KEY_F8          65477   /* F8 */
# define KEY_F9          65478   /* F9 */
# define KEY_F10         65479   /* F10 */
# define KEY_F11         65480   /* F11 */
# define KEY_F12         65481   /* F12 */

/* --- Special keys --- */
# define KEY_ESC         65307   /* Escape key */
# define KEY_TAB         65289   /* Tab key */
# define KEY_CAPSLOCK    65509   /* Caps Lock key */
# define KEY_SHIFT       65505   /* Shift key (either left or right) */
# define KEY_CONTROL     65507   /* Control key (either left or right) */
# define KEY_ALT         65513   /* Alt key (often left Alt) */
# define KEY_SPACE       32      /* Space bar */
# define KEY_BACKSPACE   65288   /* Backspace */
# define KEY_ENTER       65293   /* Enter */

/* --- Punctuation and others --- */
# define KEY_MINUS       45      /* '-' key */
# define KEY_EQUAL       61      /* '=' key */
# define KEY_LEFT_BRACE  91      /* '[' key */
# define KEY_RIGHT_BRACE 93      /* ']' key */
# define KEY_BACKSLASH   92      /* '\' key */
# define KEY_SEMICOLON   59      /* ';' key */
# define KEY_APOSTROPHE  39      /* ''' key */
# define KEY_GRAVE       96      /* '`' key */
# define KEY_COMMA       44      /* ',' key */
# define KEY_PERIOD      46      /* '.' key */
# define KEY_SLASH       47      /* '/' key */

int	key_press(int keycode, t_data *data);
int	key_release(int keycode, t_data *data);
int	close_window(t_data *data);

#endif
