/*
 * Notes: 
    - it is optimal to let the first patient to wait as long as possible, 
        so first pack will be oppended at t[0] + w and it will expire at T[0] + w + d.
    - so we take k users each time and check if I vaccinate the maximum of those users.

    - I keep repeating the same algorithm stating from the last unvaccinated user. until everyone is vaccinated (i >= n)
 */

int t = int.Parse(Console.ReadLine());

while (t > 0)
{
    t--;

    var nums = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    var (n, k, d, w) = (nums[0], nums[1], nums[2], nums[3]);
    var T = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);


    int i = 0;
    int ans = 0;
    while (i < n)
    {
        int l = i;
        var expiration = T[l] + w + d;
        for (var j = l; j < k + l && i < n; j++)
        {
            if (T[j] > expiration)
            {
                break;
            }
            i++;
        }
        ans++;
    }

    Console.WriteLine(ans);
}
