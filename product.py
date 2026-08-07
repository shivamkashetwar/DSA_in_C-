class Solution:

  def product(self, nums):
    total_product = 1
    ans = []

    # Calculate the product of all elements
    for i in range(len(nums)):
      total_product *= nums[i]

    # Divide the total product by each element to form the new array
    for i in range(len(nums)):
      ans.append(total_product // nums[i])

    return ans


sol = Solution()
prod = sol.product([1, 2, 3, 4])
print(prod)