#include "filler.h"

int is_placable_piece(t_filler *f, int mx, int my)
{
	int x;
	int y;
	int my2;
	int tot;

	x = 0;
	y = 0;
	tot = 0;
	f->count = 0;
	while (x < f->piece_x)
	{
		my2 = my;
		y = 0;
		while (y < f->piece_y && my2 < f->map_y)
		{
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 1)
				f->count += 1;
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 2)
				return(0);
			if(f->count >= 2)
				return(0);
			y++;
			my2++;
			tot++;
		}
		x++;
		mx++;
	}
	if(f->count == 1 && tot == f->piece_tot) // je peux changer et mettre la limte dans le while de x
		return(1);
	return(0);
}

int play(t_filler *f)
{
	//p1 start north
	if ((f->map_first_p <= (f->map_x + 1) / 2) && f->switch_algo == 0)
			return(algo_nw_se(f));
	if ((f->map_first_p <= (f->map_x + 1) / 2) && f->switch_algo == 1)
		return(algo_se_nw(f));
	if ((f->map_first_p <= (f->map_x + 1) / 2) && f->switch_algo == 2)
			return(algo_bottom_right(f));





//p1 start south
	if ((f->map_first_p > (f->map_x + 1) / 2) && f->switch_algo == 0)
		return(algo_se_nw(f));
	if ((f->map_first_p > (f->map_x + 1) / 2) && f->switch_algo == 3)
		return(algo_nw_se(f));
	if ((f->map_first_p > (f->map_x + 1) / 2) && f->switch_algo == 4)
			return(algo_top_left(f));
	return(error_handle(f));
}
