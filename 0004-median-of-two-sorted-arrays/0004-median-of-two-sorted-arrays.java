class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
         int num[]= new int[nums1.length+nums2.length];
         int i = 0;
         int j = 0;
         int k = 0;
            while(i<nums1.length && j<nums2.length){
             if(nums1[i]<nums2[j]){
                 num[k]=nums1[i];
                 i++;
             }
             else{
                 num[k]=nums2[j];
                 j++;
             }   
             k++;
            }
            while(i<nums1.length){
                num[k]=nums1[i];
                i++;
                k++;
            }
            while(j<nums2.length){
                num[k]=nums2[j];
                j++;
                k++;
            }
            if(num.length%2==0){
              int a = num.length/2;
              return (num[a-1]+num[a])/2.0;
            }
            else {
              int a = num.length/2;
              return num[a]+0.0;
            } 
    }
}