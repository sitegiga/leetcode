class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n/2; i++) {
            for (int j = 1; max(i, j) <= n - i - j; j++) {
                string a = num.substr(0, i);
                string b = num.substr(i, j);
                if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) continue;
                if (isValid(a, b, i + j, num)) return true;
            }
        }
        return false;
    }

    bool isValid(string a, string b, int start, string& num) {
        while (start < num.size()) {
            string sum = addStrings(a, b);
            if (num.substr(start, sum.size()) != sum) return false;
            start += sum.size();
            a = b;
            b = sum;
        }
        return true;
    }

    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
