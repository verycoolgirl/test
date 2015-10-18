  class Solution {
public:
    bool isDecChar(char c) {
        if ((c >= '0') && (c <= '9')) {
            return true;
        } 

        return false;
    }
    bool parsenum(string &s, int *start, int end, bool decimal) {
        bool has_num=false;
        bool is_decimal = false;
        if (*start <= end) {
             if (s[*start] == '+' || s[*start] == '-') {
                (*start)++;
             }
        } 
        
        if (*start > end) {
            return false;
        }
        for (; *start <= end; (*start)++) {
            if (s[*start] == '.') {
                if (!decimal || is_decimal) {
                    return false;
                }
                is_decimal = true;
                continue;
            }
            if (!isDecChar(s[*start])) {
                return has_num;
            }           
            has_num = true;
        }
        if (has_num == false) {
            return false;
        }
        return true;
    }
    bool isNumber(string s) {
        int i, ri, begin;
        bool result;
        
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
        begin = i;
        result = parsenum(s, &i, ri, true);
        if (i > ri) {
            return result;
        }
        
        if ((s[i] == 'e') && result) {
            i++;
            result = parsenum(s, &i, ri, false);
            if (i > ri) {
                return result;
            }
        }
        return false;
    }
};
