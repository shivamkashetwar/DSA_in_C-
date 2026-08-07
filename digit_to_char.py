class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
            
        res = []
        digittochar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        
        def backtrag(i, currstr):
            if len(currstr) == len(digits):
                res.append(currstr)
                return 
            
            for char in digittochar[digits[i]]:
                backtrag(i + 1, currstr + char)
                
        backtrag(0, "")
        return res