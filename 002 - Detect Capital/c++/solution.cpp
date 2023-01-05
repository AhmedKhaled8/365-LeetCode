class Solution
{
public:
        bool detectCapitalUse(string word)
        {
                uint8_t upper_count = 0;
                uint8_t lower_count = 0;
                for (uint8_t index = 0; index < word.size(); ++index)
                {
                        if (int(word[index]) >= 65 && int(word[index]) <= 90)
                                upper_count += 1;
                        else
                                lower_count += 1;
                }
                if (upper_count == 0 || lower_count == 0) // either XXXX or xxxx
                        return true;
                else if (upper_count == 1 && int(word[0]) >= 65 && int(word[0]) <= 90) // Xxxx
                        return true;
                else
                        return false;
        }
};