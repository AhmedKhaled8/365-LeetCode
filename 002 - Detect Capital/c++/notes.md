# [2 - Detect Capital]()

We define the usage of capitals in a word to be right when one of the following cases holds:

* All letters in this word are capitals, like "USA".
* All letters in this word are not capitals, like "leetcode".
* Only the first letter in this word is capital, like "Google".

Given a string `word`, return `true` if the usage of capitals in it is right.

Example 1:

```
Input: word = "USA"
Output: true
```

Example 2:

```
Input: word = "FlaG"
Output: false
```

Constraints:

* `1 <= word.length <= 100`
* `word` consists of lowercase and uppercase English letters.

### 1. Trivial Solution
Since the validity of the word state mainly depend on the first letter and maybe the second letter we can make some if conditions based on the first 2 letters.


Pseudo Code:
```
if (word[0].isUpper())
{
        if (word[1].isUpper)
        {
                check from 2 until end is upper
        }
        else
        {
                check from 2 until end is lower
        }
}
else
{
        check from 1 until end is lower
}
```

#### Alternative Solution

To simplify the if conditions, we can translate the validity of `word` of lenght `n` mathematically with counting the uppercase letters in `word` in `upper_count` as following:

* All letters in this word are capitals ==> `upper_count = n`.
* All letters in this word are not capitals ==> `upper_count == 0`.
* Only the first letter in this word is capital ==> `upper_count == 1 && word[0].isUpper()`.

that's it.

### Solution

```cpp
class Solution
{
public:
        bool detectCapitalUse(string word)
        {
                uint8_t upper_count = 0;
                for (uint8_t index = 0; index < word.size(); ++index)
                {
                        if (int(word[index]) >= 65 && int(word[index]) <= 90)
                                upper_count += 1;
                }
                if (upper_count == 0 || upper_count == word.size()) // either XXXX or xxxx
                        return true;
                else if (upper_count == 1 && int(word[0]) >= 65 && int(word[0]) <= 90) // Xxxx
                        return true;
                else
                        return false;
        }
};
```