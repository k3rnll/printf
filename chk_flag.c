#include "ft_printf.h"

void	chk_flag(t_pfdata *pfdata)
{
	if (ft_strchr("hl", pfdata->format[pfdata->i]))
	{
		pfdata->flag[0] = pfdata->format[pfdata->i];
		pfdata->i++;
		if (pfdata->format[pfdata->i] == pfdata->flag[0])
		{
			pfdata->flag[1] = pfdata->flag[0];
			pfdata->i++;
		}
	}
}