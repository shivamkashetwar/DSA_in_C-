class solution:
    def closest(self,nums,targets):
        cs=float('inf')
        nums.sort()

        for i in range(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue

        l=i+1
        r=len(nums)-1
        while l<r:
            sum=nums[i]+nums[l]+nums[r]
            if (abs(cs-targets))>abs(sum-targets):
                cs=sum
                if sum<targets:
                    l+=1
                elif sum>targets:
                    r-=1
                else:
                    return sum
        return cs
sol=solution()
nums=[-1,2,1,-4]
targets=1
print(sol.closest(nums,targets))
