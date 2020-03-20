class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Queue q=new PriorityQueue<Integer>((a,b)->{return b-a;});
        for(int i=0;i<arr.length;i++){
            q.offer(arr[i]);
            while(q.size()>k)q.poll();
        }
        int []res=new int[k];
        for(int i=0;i<k;i++){
            res[i]=(int)q.peek();
            q.poll();
        }
        return res;
    }
}