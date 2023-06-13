const bool MULTIPLE_TEST_CASES = true;
long t = 1;
if (MULTIPLE_TEST_CASES)
    t = int.Parse(Console.ReadLine());

for (int _ = 0; _ < t; _++)
{
    Solve();
}

/*
 * Notes: 
 * we need to find all segments where the rule is verified (at least k consecutive days where a[i]<=q)
 * then for each segment we calculate the number of possible visits which is:
 * - 1 + 2 + .... +(n-k+1) = (n-k+1)(n-k+2)/2     straight famous sum formula!
 * it is also equivalent to lCk (Combination) where l is the lenght of the segment.
 * 
 * then answer is simply the sum of the number of possibilities of all segments in the input.
 */

static void Solve()
{
    var nums = ReadLongArray();
    var (n, k, q) = (nums[0], nums[1], nums[2]);
    var a = ReadLongArray();

    if(n == 1 && a[0]<=q)
    {
        Console.WriteLine(1);
        return;
    }
    if(n == 1 && a[0]>q) 
    {
        Console.WriteLine(0);
        return;
    }


    int i = 0;
    long consecutive_count = 0;
    long ans = 0;
    while (i<n)
    {
        if (a[i]<=q)
        {
            consecutive_count++;
            i++;
            continue;
        }
        if(consecutive_count>=k)
        {
            ans += ((consecutive_count - k+1)*(consecutive_count - k+2))/2;
        }
        consecutive_count = 0;
        i++;
    }

    if (consecutive_count >= k)
    {
        ans += ((consecutive_count - k+1)*(consecutive_count - k+2))/2;
        consecutive_count = 0;
    }

    Console.WriteLine(ans);

}

static int[] ReadIntArray() => 
    Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
static long[] ReadLongArray() =>
    Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
