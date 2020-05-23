#include "ft_printf.h"

void	chk_mod(t_pfdata *pfdata)
{
	if (ft_strchr("hl", pfdata->format[pfdata->i]))
	{
		pfdata->mod[0] = pfdata->format[pfdata->i];
		pfdata->i++;
		if (pfdata->format[pfdata->i] == pfdata->mod[0])
		{
			pfdata->mod[1] = pfdata->mod[0];
			pfdata->i++;
		}
	}
}