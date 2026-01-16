class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = []
        shorter_len = min(len(word1), len(word2))
        
        for i in range(shorter_len):
            ans.append(word1[i])
            ans.append(word2[i])
        
        ans += word1[shorter_len:]
        ans += word2[shorter_len:]

        return "".join(ans)
