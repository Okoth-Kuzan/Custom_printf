#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @pmeters: the parameters struct
 * @arglst: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *pmeters, va_list arglst)
{
	pmeters->unsign = 0;

	pmeters->plus_flag = 0;
	pmeters->space_flag = 0;
	pmeters->hashtag_flag = 0;
	pmeters->zero_flag = 0;
	pmeters->minus_flag = 0;

	pmeters->width = 0;
	pmeters->precision = UINT_MAX;

	pmeters->h_modifier = 0;
	pmeters->l_modifier = 0;
	(void)arglst;
}
