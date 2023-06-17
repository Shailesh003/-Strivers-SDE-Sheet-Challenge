
int minCharsforPalindrome(string str) {
 int n = str.size();

    int low = 0;

    int high = n - 1;

    int e2 = high;

    int cnt = 0;

    while (low < high)

    {

        if (str[low] == str[high])

        {

            low++;

            high--;

        }

        else

        {

            cnt++;

            low = 0;

            e2--;

            high = e2;

        }

    }

    return cnt;
	
}
