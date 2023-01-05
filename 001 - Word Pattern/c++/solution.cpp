class Solution
{
public:
        bool wordPattern(std::string pattern, std::string s)
        {
                size_t pattern_keys_count = pattern.size();
                std::string current_word;
                std::istringstream ss(s);

                std::unordered_map<char, std::string> pattern_word_map;
                std::unordered_map<std::string, char> word_pattern_map;

                // iterate on all pattern chars (keys)
                for (size_t index = 0; index < pattern_keys_count; ++index)
                {
                        // if there is no next word (i.e., the pattern characters are more than the words), return false
                        if (!(ss >> current_word))
                                return false;

                        char current_pattern_key = pattern[index];
                        auto pattern_it = pattern_word_map.find(current_pattern_key);
                        if (pattern_it == pattern_word_map.end())
                        {
                                // the current pattern key hasn't been associated with a word yet

                                // first, check if the current word itself has been assoicated with another pattern key
                                auto word_it = word_pattern_map.find(current_word);
                                if (word_it != word_pattern_map.end())
                                {
                                        // the current word is already associated with a key (which is different)
                                        // so return false
                                        return false;
                                }

                                // else, the word hasn't been associated with a different key.
                                // So, assoicate this word to that key and mark the word as visited
                                pattern_word_map[current_pattern_key] = current_word;
                                word_pattern_map[current_word] = current_pattern_key;
                        }
                        else
                        {
                                // the current key has a word associated with it, we need to check if that word is the same as the current word
                                if (pattern_it->second.compare(current_word) != 0)
                                {
                                        // both word are different
                                        return false;
                                }
                        }
                }
                if (ss >> current_word)
                        return false;
                return true;
        }
};