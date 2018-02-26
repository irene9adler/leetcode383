/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*int res;
        res = strstr(ransomNote,magazine);
        if(res != NULL) return true;
        else return false;
        */
        //是判断第一个串能不能从第二个串中抽取组合成 不是找子串 并且c++不能用strstr找子串 string类有find函数
        //前面的题用过这个思路 用数组统计字符串中字母出现的次数
        vector <int> count(26,0);
        //bool res = true;
        int i;
        for(i = 0;i < magazine.size();i++)
        {
            count[magazine[i] - 'a']++;
        }

        for(i = 0;i < ransomNote.size();i++)
        {
            count[ransomNote[i] - 'a']--;
        }

        for(i = 0;i < 26;i++)
        {
            if(count[i] < 0)
            {
                //res = false;
                //break;
                return false;
            }
        }
        return true;
    }

};
