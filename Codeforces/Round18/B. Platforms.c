#include <stdio.h>

int main()
{
	__int64 res;
	__int64 pos;
	__int64 iPlat;
	__int64 n, d, m, l;
	__int64 step;

	scanf("%I64d %I64d %I64d %I64d", &n, &d, &m, &l);
	{
		pos = 0;
		iPlat = 1;

		while(iPlat <= n)
		{
			step = ((iPlat - 1) * m + l - pos) / d;
			pos += d * step;
			while(pos <= (iPlat - 1) * m + l)
				pos += d;
			iPlat++;
			if (pos < (iPlat - 1) * m)
			{
				res = pos;
				break;
			}
		}
		if (iPlat > n)
			res = pos;
		printf("%I64d\n", res);
	}
	return 0;
}
