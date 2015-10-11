class Solution {
public:
    bool isDecChar(char c) {
        if ((c >= '0') && (c <= '9')) {
            return true;
        } 

        return false;
    }
    bool isHexChar(char c) {
        if ((c >= 'a') && (c <= 'f')) {
            return true;
        }
        if ((c >= 'A') && (c <= 'F')) {
            return true;
        }
        return false;
    }
    bool isNumber(string s) {
        int i, ri;
        bool is_decimal = false;
        bool has_dec = false;
        bool has_hex = false;
        
        // process leading empty space
        for (i = 0; i != s.length(); i++) {
            if (s[i] != ' ') {
                break;
            }   
        }
        // process trailing empty space
        for (ri = s.length() - 1; ri >= i; ri--) {
            if (s[ri] != ' ') {
                break;
            }
        }
        
        for (; i<= ri; i++) {
            if (s[i] == '.') {
                if (is_decimal) {
                    return false;
                }
                is_decimal = true;
                continue;
            }
            if (isDecChar(s[i])) {
                has_dec = true;
            } else if (isHexChar(s[i]) && !is_decimal) {
                has_hex = true;
            } else {
                return false;
            }
        }
        if (!(is_decimal && has_hex)  && (has_hex || has_dec)) {
            return true;
        }
    }
};
