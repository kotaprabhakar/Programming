#include <iostream>
using namespace std;

#define SIZE 1000000000
#define TRUE false
#define FALSE true
#define INIT_VALUE 100003

typedef size_t longest;

bool *primeSieve;

void createSieve()
{
    primeSieve = (bool *) calloc(SIZE, sizeof(bool));
    primeSieve[0] = FALSE, primeSieve[1] = FALSE,
            primeSieve[2] = TRUE, primeSieve[3] = TRUE;
    longest i = 0, j = 0;
    for(i = 2; i < SIZE; (i == 2 || i == 3 || i == 4) ? i++
            : ((i % 6 == 1) ? i += 4 : i += 2))
    {
        if(primeSieve[i] == TRUE)
        {
            for (j = i * i; j < SIZE; j += i)
            {
                primeSieve[j] = FALSE;
            }
        }
    }
}

void deleteSieve()
{
    free(primeSieve);
}

longest intLength(longest x)
{
    longest c = 0;
    while(x /= 10)
        c++;
    return c + 1;
}

longest findCount(longest num, longest *res, longest n, longest r)
{
    longest i, cnt = 0, j = 0, temp;
    const longest N = n;
    char str[N + 1];
    sprintf(str, "%lu", num);

    for(i = 1; i < r; i++)
    {
        if(str[res[i]] != str[res[i - 1]])
            return 0;
    }

    for(i = 0; i < 10; i++)
    {
        if(res[0] == 0 && i == 0)
            continue;
        for(j = 0; j < r; j++)
        {
            str[res[j]] = static_cast<char>(48 + i);
        }
        temp = static_cast<longest>(atoi(str));
        if(primeSieve[temp] == TRUE)
            cnt++;
    }
    return cnt;
}

bool combinations(longest num, longest n, longest r)
{
    const longest N = n, R = r;
    longest res[N], i, j;
    for(i = 0; i < R; i++)
    {
        res[i] = i;
    }
    while(true)
    {
        // TODO: Write code to use each combination here
        if(findCount(num, res, n, r) == 8)
            return true;

        i = R - 1, j = N - 1;
        while(res[i] == j)
            i--, j--;
        if(i >= 0 && i < R)
        {
            res[i] = res[i] + 1;
            for (i = i + 1; i < R; i++)
                res[i] = res[i - 1] + 1;
        }
        else
            break;
    }
    return false;
}

int main()
{
    createSieve();

    longest i = 0, j = 0;
    bool fin = false;
    for(i = INIT_VALUE; i < SIZE; (i % 6 == 1) ? i += 4 : i += 2)
    {
        if(primeSieve[i] == TRUE)
        {
            longest l = intLength(i);
            for(j = 1; j < l; j++)
            {
                if(combinations(i, l, j))
                {
                    printf("%lu\n", i);
                    fin = true;
                    break;
                }
            }
        }
        if(fin)
            break;
    }

    deleteSieve();
    return 0;
}