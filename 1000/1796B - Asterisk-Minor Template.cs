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
 *  - if the 2 strings have the first or the last character c in common, then the answer is c* or *c
 *  - if the 2 strings have at least 2 neighbour characters cc in common then the answer is *cc*
 *  - elese there is no answer.
 *  
 *  the first case is trivial.
 *  int the second case I have used the sliding window technique, 
 *  I made a sliding window of 2 characters and looped throuhg the 2 strings checking if they have a common window
 */

static void Solve()
{

    string a = Console.ReadLine();
    string b = Console.ReadLine();

    if (a[0] == b[0])
    {
        Console.WriteLine("YES");
        Console.WriteLine($"{a[0]}*");
        return;
    }

    if (a.Last() == b.Last())
    {
        Console.WriteLine("YES");
        Console.WriteLine($"*{a.Last()}");
        return;
    }

    for(int i=0; i<a.Length-1; i++)
    {
        var window = a.Substring(i,2);
        for(int j=0; j<b.Length-1; j++)
        {
            if(window.Equals(b.Substring(j,2)))
            {
                Console.WriteLine("YES");
                Console.WriteLine($"*{window}*");
                return;
            }
        }
    }

    Console.WriteLine("NO");

}
