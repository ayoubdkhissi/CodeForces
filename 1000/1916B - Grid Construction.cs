const bool MULTIPLE_TEST_CASES = true;

/*
 * Notes: 
 * the answer is to simply construct the following grid:
 * 2n-1  2     n+2 ........2n-2 n
 *  1   n+1    3   ........n-1  2n
*/

static void Solve()
{
    int n = int.Parse(Console.ReadLine());

    // grid of 2.n
    int[,] grid = new int[2, n];

    grid[0,0] = 2 * n - 1;
    grid[1, n - 1] = 2 * n;

    int z = 1;
    for(int i=0; i<n; i++)
    {
        grid[z, i] = i + 1;
        z = 1 - z;
    }

    z = 1;
    for (int i = 1; i<n-1; i++)
    {
        grid[z, i] = n+i;
        
        z = 1 - z;
    }
    
    // print grid
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < n; k++)
            Console.Write(grid[j, k] + " ");
        Console.WriteLine();
    }
}

int t = 1;
if (MULTIPLE_TEST_CASES)
    t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
    Solve();
}
