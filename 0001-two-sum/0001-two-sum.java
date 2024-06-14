import java.util.HashMap;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mymap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int comp = target - nums[i];
            if (mymap.containsKey(comp)) {
                return new int[]{mymap.get(comp), i};
            }
            mymap.put(nums[i], i);
        }
        return null;
    }
}