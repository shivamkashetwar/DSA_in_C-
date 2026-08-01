class Solution:
    def sum(self, num):
        num.sort()
        result = []

        for i in range(len(num) - 2):
        
            if i > 0 and num[i] == num[i - 1]:
                continue

            j = i + 1
            k = len(num) - 1

            while j < k:
                total = num[i] + num[j] + num[k]

                if total < 0:
                    j += 1

                elif total > 0:
                    k -= 1

                else:
                    result.append((num[i], num[j], num[k]))

                    # Move both pointers
                    j += 1
                    k -= 1

                    # Skip duplicate values
                    while j < k and num[j] == num[j - 1]:
                        j += 1

                    while j < k and num[k] == num[k + 1]:
                        k -= 1

        return result


sol = Solution()
nums = [-1, 0, 1, 2, -1, -4]

result = sol.sum(nums)
print(result)