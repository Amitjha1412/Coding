#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char c[20001] = {'\0'};
        int n, k, i;
        int flag, last, count;
        scanf("%d%d\n", &n, &k);
        scanf("%s", c);

        flag = 0;
        last = 0;
        count = 0;
        for (i = 1; c[i] != '\0'; ++i)
        {
            if (c[last] != c[i])
            {
                int len = i - last;
                int cc = len / k;
                if (cc * k != len)
                    cc++;
                count += cc;
                if (len >= k)
                    flag = 1;
                last = i;
            }
        }
        {
            int len = i - last;
            int cc = len / k;
            if (cc * k != len)
                cc++;
            count += cc;
            if (len >= k)
                flag = 1;
            last = i;
        }
        if (flag == 0)
            printf("-1\n");
        else
            printf("%d\n", count);
    }
    return 0;
}
