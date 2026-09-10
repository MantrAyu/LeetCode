class Solution {
    public int countWords(String[] words1, String[] words2) {
        HashMap<String,Integer> n1 = new HashMap<>();
        HashMap<String,Integer> n2 = new HashMap<>();
        for(String c : words1){
            n1.put(c, n1.getOrDefault(c,0)+1);
        }
        for(String c : words2){
            n2.put(c, n2.getOrDefault(c,0)+1);
        }
        int c=0;
        for(Map.Entry<String,Integer> entry : n1.entrySet()){
            if(entry.getValue()==1){
                int i = n2.getOrDefault(entry.getKey(), 0);
                if(i==1)
                  c++;  
            }
        }
        return c;       
    }
}