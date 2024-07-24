/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 02:18:17 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 01:07:09 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MLX_H
# define SO_LONG_MLX_H

typedef struct s_sl_mlx
{
	void	*mlx;
	void	*win;
	void	*img_sample;
	int		height;
	int		width;
}	t_sl_mlx;

typedef struct s_sl_img
{
	void	*tl_img;
	char	*tl_addr;
	int		tl_bpp;
	int		tl_len;
	int		tl_endian;
}	t_sl_img;

typedef struct s_sl_imgt
{
	void	*lr_img;
	char	*lr_addr;
	int		lr_bpp;
	int		lr_len;
	int		lr_endian;
	int		lr_y;
	int		lr_x;
}	t_sl_imgt;


typedef struct s_sl_tiles
{
	void *img_g;
	void *img_s;
	void *img_wu;
	void *img_wur;
	void *img_wul;
	void *img_wd;
	void *img_wdl;
	void *img_wdr;
	void *img_wl;
	void *img_wr;
	void *img_el;
	void *img_elrm;
	void *img_c;
	void *img_xc;
	void *img_xo;
	void *img_ps_bs;
	void *img_p_bs;
	void *img_p_br;
	void *img_p_bl;
	void *img_ps_fs;
	void *img_p_fs;
	void *img_p_fr;
	void *img_p_fl;
	void *img_ps_ls;
	void *img_p_ls;
	void *img_p_lr;
	void *img_p_ll;
	void *img_ps_rs;
	void *img_p_rs;
	void *img_p_rr;
	void *img_p_rl;
}	t_sl_tiles;

typedef struct s_sl_layers
{
	void	*background;
	void	*elements;
	void	*player;
	int		width;
	int		height;
}	t_sl_layers;

void	path_init_ext(char **path_array);
void	path_init(char **path_array);
int		image_init(t_sl_hub *data, char **path_array);
int		setup_image(t_sl_hub *data);
int		setup_window(t_sl_hub *data);
void	tile_to_wall(t_sl_hub *data);
void	punch_ebc(t_sl_hub *data, int y, int x, char c);
void	tile_to_elem(t_sl_hub *data);
void	tile_to_player(t_sl_hub *data);
int 	render_layers(t_sl_hub *data);
void	elem_punch(t_sl_hub *data, int y, int x);
void	bground_punch(t_sl_hub *data, int y, int x);
void	collect_punch(t_sl_hub *data, int y, int x);
void	exit_punch(t_sl_hub *data, int y, int x);
void	player_punch(t_sl_hub *data, int y, int x);
void	wall_up_punch(t_sl_hub *data, int y, int x);
void	wall_dn_punch(t_sl_hub *data, int y, int x);
void	wall_lr_punch(t_sl_hub *data, int y, int x);

# define PATH_G "images/img_g.xpm"
# define PATH_S "images/img_s.xpm"
# define PATH_WU "images/img_wu.xpm"
# define PATH_WUR "images/img_wur.xpm"
# define PATH_WUL "images/img_wul.xpm"
# define PATH_WD "images/img_wd.xpm"
# define PATH_WDR "images/img_wdr.xpm"
# define PATH_WDL "images/img_wdl.xpm"
# define PATH_WL "images/img_wl.xpm"
# define PATH_WR "images/img_wr.xpm"
# define PATH_EL "images/img_el.xpm"
# define PATH_ELR "images/img_elrm.xpm"
# define PATH_C "images/img_c.xpm"
# define PATH_XC "images/img_xc.xpm"
# define PATH_XO "images/img_xo.xpm"
# define PATH_PS_BS "images/img_ps_bs.xpm"
# define PATH_P_BS "images/img_p_bs.xpm"
# define PATH_P_BR "images/img_p_br.xpm"
# define PATH_P_BL "images/img_p_bl.xpm"
# define PATH_PS_FS "images/img_ps_fs.xpm"
# define PATH_P_FS "images/img_p_fs.xpm"
# define PATH_P_FR "images/img_p_fr.xpm"
# define PATH_P_FL "images/img_p_fl.xpm"
# define PATH_PS_LS "images/img_ps_ls.xpm"
# define PATH_P_LS "images/img_p_ls.xpm"
# define PATH_P_LR "images/img_p_lr.xpm"
# define PATH_P_LL "images/img_p_ll.xpm"
# define PATH_PS_RS "images/img_ps_rs.xpm"
# define PATH_P_RS "images/img_p_rs.xpm"
# define PATH_P_RR "images/img_p_rr.xpm"
# define PATH_P_RL "images/img_p_rl.xpm"
# define PATH_COUNT 31

# define CTLFUNC_COUNT 3



#endif