/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wall_detect.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 22:11:09 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 23:20:11 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_point	closest_grid_h(t_point *p, t_map *m, double angle)
{
	t_point closest;
	
	if (angle > PI && angle <= 2 * PI)
		closest.y = (int)(p->y / m->bloc_size) * m->bloc_size - 1;
	else
		closest.y = (int)(p->y / m->bloc_size) * m->bloc_size  + m->bloc_size;
	closest.x = p->x + (p->y - closest.y) / tan(angle);
	return (closest);
}

t_point	 closest_grid_v(t_point *p, t_map *m, double angle)
{
	t_point closest;
	
	if (angle > PI && angle <= 2 * PI)
		closest.x = (int)(p->x / m->bloc_size) * m->bloc_size  + m->bloc_size;
	else
		closest.x = (int)(p->x / m->bloc_size) * m->bloc_size - 1;
	closest.y = p->y + (p->x - closest.x) * tan(angle);
	return (closest);
}

t_point closest_wall_h(t_point *p, t_map *m, double angle)
{
	t_point closest;
	t_point offset;

	if (angle > 2 * PI * 0.75 && angle < PI / 2)
		offset.y = m->bloc_size;
	else
		offset.y = -m->bloc_size;
	offset.x = m->bloc_size / tan(angle);
}

t_point closest_wall_h(t_point *p, t_map *m, double angle)
{
	t_point closest;
	t_point offset;

	if (angle < 2 * PI * 0.75 && angle > PI / 2)
		offset.x = m->bloc_size;
	else
		offset.x = -m->bloc_size;
	offset.y = m->bloc_size / tan(angle);
}

void draw_ray(t_player *p, t_map *m, double angle)
{
	t_point cur_h;
	t_point cur_v;
	double ray_dist;

	cur_h = closest_grid_h(p->pos, m, angle);
	cur_v = closest_grid_v(p->pos, m, angle);
	
	
	

}