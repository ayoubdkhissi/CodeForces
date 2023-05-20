const bool MULTIPLE_TEST_CASES = true;

/*
 * Notes: 
 * the answer is to simply construct the following grid:
 * 2n-1  2     2n-2 ........ n
 *  1   2n-3    3  ........ 2n
*/

static void Solve()
{
    long n = long.Parse(Console.ReadLine());

    // grid of 2.n
    long[,] grid = new long[2, n];

    grid[0,0] = 2 * n - 1;
    grid[1, n - 1] = 2 * n;

    long z = 1;
    for(long i=0; i<n; i++)
    {
        grid[z, i] = i + 1;
        z = 1 - z;
    }

    z = 0;
    for (long i = 2; i<n-1; i+=2)
    {
        grid[0, i] = 2*n - 2 - z;
        grid[1, i - 1] = 2*n - 2 - z - 1;

        z += 2;
    }

    // print grid
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < n; k++)
            Console.Write(grid[j, k] + " ");
        Console.WriteLine();
    }
}

long t = 1;
if (MULTIPLE_TEST_CASES)
    t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
    Solve();
}
