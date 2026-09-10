class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        HashSet <Integer> set = new HashSet<>();
        for(int i=0; i<nums1.length; i++){
            set.add(nums1[i]);
        }
        int a = Integer.MAX_VALUE;
        for(int i=0; i<nums2.length; i++){
            if(set.contains(nums2[i])){
                if(nums2[i]<a)
                   a=nums2[i];
            }
        }
        if(a == Integer.MAX_VALUE)
            return -1;
        return a;
    }
}