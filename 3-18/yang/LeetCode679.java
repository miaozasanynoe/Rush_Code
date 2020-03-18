package com.ibuyi.interview.leetcode;

import java.util.ArrayList;

public class LeetCode679 {
    //4个数字，取出两个做运算，最后剩3个数字
    //3个数字，取出两个做运算，最后剩2个数字
    //2个数字，取出两个做孕栓，最后得出结果

    public  boolean judgePoint24(int[] nums) {
        ArrayList<Double> list1 = new ArrayList<>();
        for(int i=0;i<nums.length;i++) {
            list1.add((double)nums[i]);
        }
        return slove(list1);


    }

    private boolean slove(ArrayList<Double> list) {
        //随机取出两个数字
        if (list.size() == 0) {
            return false;
        }
        if (list.size() == 1) {
            return Math.abs(list.get(0) - 24) < 1e-6;
        }
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                ArrayList<Double> list2 = new ArrayList<Double>();
                if(i!=j){
                    for(int k=0;k<list.size();k++){
                        if(k!=j&&k!=i){
                            //如果没有用到的数字，全部放在列表中，进入下一次递归
                            list2.add(list.get(k));
                        }
                    }
                    //计算这两个数字产生的结果是多少，四种情况
                    for(int k=0;k<4;k++){
                        if(k<2&&i<j){
                            //乘法和加法具有对称性
                            continue;
                        }
                        if(k==0){
                            list2.add(list.get(i)+list.get(j));
                        }else if(k==1){
                            list2.add(list.get(i)*list.get(j));
                        }else if(k==2){
                            list2.add(list.get(i)-list.get(j));
                        }else if(k==3&&list.get(j)!=0){
                            list2.add(list.get(i)/list.get(j));
                        }else{
                            continue;
                        }
                        if(slove(list2)){
                            return true;
                        }
                        //把该结果去除，进行下一次结果计算
                        list2.remove(list2.size()-1);

                    }
                }
            }
        }
        return false;
    }
}
