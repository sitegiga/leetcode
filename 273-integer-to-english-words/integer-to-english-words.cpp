class Solution {
public:
    vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                              "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return below20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return below20[num / 100] + " Hundred " + helper(num % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0)
                res = helper(num % 1000) + thousands[i] + " " + res;
            num /= 1000;
            i++;
        }
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};
